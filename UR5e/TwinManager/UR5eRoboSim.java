import java.util.ArrayList;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;
import java.lang.Thread;

import config.AsyncConfig;
import config.TwinSystemConfiguration;
import config.TwinConfiguration;
import management.TwinManager;
import model.Clock;
import model.TwinSchema;
import services.DeviationChecker;
import services.Planner;

public class UR5eRoboSim {
	static TwinManager twinManager;
	static Clock simulationClock;
	static String modelFolderPrefix = "models/";
	static String dtFolderPrefix = "digital_twins/";
	static String dataFolderPrefix = "data/";
	static boolean usingDT = true;
	static boolean usingPT = true;
	static double stepSize = 0.5;
	static double monitoringFreq = 0.5;
	static double plannerFreq = 0.5;
	static double maxTime = 20.0;
	static int numberOfCycles = 2000;

	public static void main(String[] args) {
		System.out.println("Executing UR5e RoboSim application with DT and PT (hardware-in-the-loop)");
		System.out.println("---- Configuration settings ----\nDigital Twin: " + String.valueOf(usingDT) + "\nPhysical Twin: " + String.valueOf(usingPT) + "\n---- End configuration settings ----");
		TwinSchema ur5eSchema = TwinSchema.initializeFromAASX(modelFolderPrefix+"ur5e.aasx","UR5e");
		
		TwinConfiguration configPMFMU_PT = new TwinConfiguration(dtFolderPrefix+"ur5e_URInterface.conf");
		TwinConfiguration configPMFMU_DT = new TwinConfiguration(dtFolderPrefix+"ur5e_CoppeliaSim.conf");
		TwinSystemConfiguration ur5eSimulationSystemConfig = new TwinSystemConfiguration("../co-simulation/multimodel_CoppeliaSim.json");
        TwinSystemConfiguration ur5eHiLSystemConfig = new TwinSystemConfiguration("../co-simulation/multimodel_robot.json");
		String coe = dtFolderPrefix + "../co-simulation/coe.json"; // both work with the same co-simulation parameters
		String outputPathSimulation = dataFolderPrefix + "output_simulation/";
        String outputPathHiL = dataFolderPrefix + "output_HiL/";		
		
		twinManager = new TwinManager("UR5eRoboSimManager");
		AsyncConfig asyncConf = new AsyncConfig(dtFolderPrefix+"async_config.conf");
		twinManager.setAsync(asyncConf);
		twinManager.addSchema("UR5e", ur5eSchema);

		if (usingPT) {
			twinManager.createTwin("PMFMU_UR5ePT",configPMFMU_PT,"UR5e"); // twinName, config (fmu), schemaName
		}
        if (usingDT) {
			twinManager.createTwin("PMFMU_UR5eDT",configPMFMU_DT,"UR5e"); // twinName, config (fmu), schemaName
		}

		/***** Physical Twin System *****/
		List<String> ptsUR5eSystem = new ArrayList<String>();
		ptsUR5eSystem.add("PMFMU_UR5ePT");
		if (usingPT) {			
			twinManager.createTwinSystem("ur5ePTSystem",ptsUR5eSystem,ur5eHiLSystemConfig,coe,outputPathHiL);
		}
		
		/***** Digital Twin System *****/
        List<String> dtsUR5eSystem = new ArrayList<String>();
		dtsUR5eSystem.add("PMFMU_UR5eDT");
		if (usingDT) {
			twinManager.createTwinSystem("ur5eDTSystem",dtsUR5eSystem,ur5eSimulationSystemConfig,coe,outputPathSimulation);
		}
		
		List<Object> arguments = new ArrayList<Object>();
		arguments.add(0.0);
		if (usingPT) {
			twinManager.executeOperationOnSystem("initializeSimulation", arguments, "ur5ePTSystem");
			new Thread(() -> {
				twinManager.executeOperationOnSystem("simulate", null, "ur5ePTSystem");
			}).start();
		}
		if (usingDT) {
        	twinManager.executeOperationOnSystem("initializeSimulation", arguments, "ur5eDTSystem");
			new Thread(() -> {
				twinManager.executeOperationOnSystem("simulate", null, "ur5eDTSystem");
			}).start();
		}

		Planner dtPlanner = new Planner("DTSystem");
		dtPlanner.systemSet(twinManager,dtFolderPrefix+"plan.csv",(int)(stepSize*1000));
		if (usingPT) {
			dtPlanner.bindSystem("ur5ePTSystem");
		}
		if (usingDT) {
			dtPlanner.bindSystem("ur5eDTSystem");
		}
		System.out.println("------------Starting plan execution---------------");
		//dtPlanner.systemExecute((int)(plannerFreq*1000)); // If synchronization between the execution and the planner is strictly needed
		dtPlanner.systemExecuteAsync((int)(plannerFreq*1000), (int)(maxTime*1000));
				
		Thread monitoringThread = new Thread(() -> {
			new Timer().scheduleAtFixedRate(new TimerTask() {
				public void run() {
					try{
						if (twinManager.async){
							int simstepMillis = Double.valueOf(twinManager.getAsyncAttribute("simstep").toString()).intValue();// Syncing clock -> simstep in millis
							int clockInt = (int)(simstepMillis/(stepSize*1000));
							Clock extClock = new Clock();
							int previousStepMillis = (int)(dtPlanner.getClock().getNow() * 1000/stepSize);
							extClock.setClock(clockInt);
							twinManager.setClock(extClock);
							dtPlanner.setClock(clockInt);
						}
					}catch(Exception e1){
						//e1.printStackTrace();
					}
						
					try {						
						for (int k=0;k<6;k++){
							if (usingPT){
								System.out.println("(PT) Joint q" + String.valueOf(k) + ": " + twinManager.getSystemAttributeValue("q" + String.valueOf(k),"ur5ePTSystem").getValue().toString());
							}
							if (usingDT){
								System.out.println("(DT) Joint q" + String.valueOf(k) + ": " + twinManager.getSystemAttributeValue("q" + String.valueOf(k),"ur5eDTSystem").getValue().toString());
							}
						}
						if (usingDT && usingPT){
							Object deviationResult = DeviationChecker.deviationCheckingOnSystem(twinManager, "q1", "q1", "ur5eDTSystem", "ur5ePTSystem", 0.1); // Returns the result of the deviation checking
						}
						if (!twinManager.async){
							twinManager.getClock().increaseTime(1); // Updating clock by 1 iteration == 1 time step
						}
						if (twinManager.getClock().getNow() == numberOfCycles){ // Execute for n steps and exit application afterwards
							System.out.println("------------Finishing the monitoring thread---------------");
							System.exit(0);
						}
					} catch (Exception e) {
						//e.printStackTrace();
					}
				}
			}, 0, (int)(monitoringFreq*1000));
		});
		

		System.out.println("------------Starting the monitoring thread---------------");
		monitoringThread.start();
		try{
			monitoringThread.join();
		}catch(Exception ex)
		{
		}		
	}
}