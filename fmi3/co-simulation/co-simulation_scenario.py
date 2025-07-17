# Author: Santiago Gil
from fmpy import read_model_description, extract
from fmpy.fmi3 import FMU3Slave,fmi3OK, fmi3ValueReference, fmi3Binary, fmi3Error
import shutil
import logging
import time
import threading
import pandas as pd

logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__file__)

## For identifying datatypes:
vars = {}
# inputs
vars["feasibleMoveDiscreteCommand"]="Clock"
vars["robotStopped"]="Clock"
vars["gripperOpened"]="Clock"
vars["collision"]="Clock"
vars["closeGripperCommand"]="Clock"
vars["gripperClosed"]="Clock"
vars["nonfeasibleMoveDiscreteCommand"]="Clock"
vars["moveCompleted"]="Clock"
vars["openGripperCommand"]="Clock"
vars["moveDiscreteCommand"]="Clock"
vars["feasibleMoveDiscreteCommand"]="Clock"
vars["MovementArgs_target_X"]="Int32"
vars["MovementArgs_target_Y"]="Int32"
vars["MovementArgs_target_Z"]="Int32"
# Outputs
vars["movediscrete"]="Clock"
vars["pick"]="Clock"
vars["place"]="Clock"
vars["target_X"]="Int32"
vars["target_Y"]="Int32"
vars["target_Z"]="Int32"
vars["closing_diameter"]="Float64"
vars["closing_speed"]="Float64"
vars["closing_force"]="Float64"
vars["opening_diameter"]="Float64"
vars["opening_speed"]="Float64"
vars["opening_force"]="Float64"
vars["stop"]="Clock"
vars["movejoint"]="Clock"
vars["target_q0"]="Float64"
vars["target_q1"]="Float64"
vars["target_q2"]="Float64"
vars["target_q3"]="Float64"
vars["target_q4"]="Float64"
vars["target_q5"]="Float64"
vars["movecartesian"]="Clock"
vars["target_x"]="Float64"
vars["target_y"]="Float64"
vars["target_z"]="Float64"
vars["target_rx"]="Float64"
vars["target_ry"]="Float64"
vars["target_rz"]="Float64"
vars["setvelocity"]="Clock"
vars["target_v"]="Float64"
# Logging
vars["q0"] = "Float64"
vars["q1"] = "Float64"
vars["q2"] = "Float64"
vars["q3"] = "Float64"
vars["q4"] = "Float64"
vars["q5"] = "Float64"
vars["qd0"] = "Float64"
vars["qd1"] = "Float64"
vars["qd2"] = "Float64"
vars["qd3"] = "Float64"
vars["qd4"] = "Float64"
vars["qd5"] = "Float64"
vars["qdd0"] = "Float64"
vars["qdd1"] = "Float64"
vars["qdd2"] = "Float64"
vars["qdd3"] = "Float64"
vars["qdd4"] = "Float64"
vars["qdd5"] = "Float64"
vars["t0"] = "Float64"
vars["t1"] = "Float64"
vars["t2"] = "Float64"
vars["t3"] = "Float64"
vars["t4"] = "Float64"
vars["t5"] = "Float64"
vars["x"] = "Float64"
vars["y"] = "Float64"
vars["z"] = "Float64"
vars["rx"] = "Float64"
vars["ry"] = "Float64"
vars["rz"] = "Float64"

# Co-simulation parameters
end_simulation_time = 100.0
start_simulation_time = 0.0
sim_time = start_simulation_time # Holds the current time of the simulation
step_size = 0.5
simulation_program_delay = True # Set to True for real-time simulation

# For periodic clocks
class ThreadedTimer:
    def __init__(self, interval, function, *args, **kwargs):
        self.interval = interval
        self.function = function
        self.args = args
        self.kwargs = kwargs
        self.stop_event = threading.Event()
        self.thread = threading.Thread(target=self._run)
        
    def _run(self):
        while not self.stop_event.is_set():
            self.function(*self.args, **self.kwargs)
            if simulation_program_delay:
                time.sleep(self.interval)
        
    def start(self):
        self.thread.start()
        
    def stop(self):
        self.stop_event.set()
        self.thread.join()

columns = [
    "sim_time", 
    "super_dense_time",
    "controller.moveDiscreteCommand", 
    "controller.MovementArgs_target_X", 
    "controller.MovementArgs_target_Y", 
    "controller.MovementArgs_target_Z", 
    "dmodel.movediscrete",
    "mapping.q0",
    "mapping.q1",
    "mapping.q2",
    "mapping.q3",
    "mapping.q4",
    "mapping.q5",
    "mapping.robotStopped",
    "mapping.moveCompleted"
]

df = pd.DataFrame(columns=columns) # Empty dataframe to store data

mapping_fmu_filename = "../mappingFMU/mappingFMU.fmu"
dmodel_fmu_filename = "../dmodelFMU/dmodelFMU.fmu"
controller_fmu_filename = "../controllerFMU/controllerFMU.fmu"
unzipdir_mapping = extract(mapping_fmu_filename)
unzipdir_dmodel = extract(dmodel_fmu_filename)
unzipdir_controller = extract(controller_fmu_filename)
# read the model description
model_description_mapping = read_model_description(unzipdir_mapping)
model_description_dmodel = read_model_description(unzipdir_dmodel)
model_description_controller = read_model_description(unzipdir_controller)

# collect the value references
vrs_mapping = {}
vrs_dmodel = {}
vrs_controller = {}
for variable in model_description_mapping.modelVariables:
    vrs_mapping[variable.name] = variable.valueReference
for variable in model_description_dmodel.modelVariables:
    vrs_dmodel[variable.name] = variable.valueReference
for variable in model_description_controller.modelVariables:
    vrs_controller[variable.name] = variable.valueReference

mapping_fmu = FMU3Slave(guid=model_description_mapping.guid,
                unzipDirectory=unzipdir_mapping,
                modelIdentifier=model_description_mapping.coSimulation.modelIdentifier,
                instanceName='mapping')
controller_fmu = FMU3Slave(guid=model_description_controller.guid,
                unzipDirectory=unzipdir_controller,
                modelIdentifier=model_description_controller.coSimulation.modelIdentifier,
                instanceName='controller')
dmodel_fmu = FMU3Slave(guid=model_description_dmodel.guid,
                unzipDirectory=unzipdir_dmodel,
                modelIdentifier=model_description_dmodel.coSimulation.modelIdentifier,
                instanceName='dmodel')

# Connections for input/output ports
timed_connections = {
		"mapping.q0" : ["controller.q0"],
        "mapping.q1" : ["controller.q1"],
        "mapping.q2" : ["controller.q2"],
        "mapping.q3" : ["controller.q3"],
        "mapping.q4" : ["controller.q4"],
        "mapping.q5" : ["controller.q5"],
        "mapping.qd0" : ["controller.qd0"],
        "mapping.qd1" : ["controller.qd1"],
        "mapping.qd2" : ["controller.qd2"],
        "mapping.qd3" : ["controller.qd3"],
        "mapping.qd4" : ["controller.qd4"],
        "mapping.qd5" : ["controller.qd5"],
        "mapping.qdd0" : ["controller.qdd0"],
        "mapping.qdd1" : ["controller.qdd1"],
        "mapping.qdd2" : ["controller.qdd2"],
        "mapping.qdd3" : ["controller.qdd3"],
        "mapping.qdd4" : ["controller.qdd4"],
        "mapping.qdd5" : ["controller.qdd5"],
        "mapping.t0" : ["controller.t0"],
        "mapping.t1" : ["controller.t1"],
        "mapping.t2" : ["controller.t2"],
        "mapping.t3" : ["controller.t3"],
        "mapping.t4" : ["controller.t4"],
        "mapping.t5" : ["controller.t5"],
        "mapping.x" : ["controller.x"],
        "mapping.y" : ["controller.y"],
        "mapping.z" : ["controller.z"],
        "mapping.rx" : ["controller.rx"],
        "mapping.ry" : ["controller.ry"],
        "mapping.rz" : ["controller.rz"]
	}

clocked_connections = {
		"controller.closeGripperCommand" : ["dmodel.closeGripperCommand"],
        "controller.openGripperCommand" : ["dmodel.openGripperCommand"],
        "controller.moveDiscreteCommand" : ["dmodel.moveDiscreteCommand"],
        "controller.MovementArgs_target_X" : ["dmodel.MovementArgs_target_X"],
        "controller.MovementArgs_target_Y" : ["dmodel.MovementArgs_target_Y"],
        "controller.MovementArgs_target_Z" : ["dmodel.MovementArgs_target_Z"],
        "mapping.feasibleMoveDiscreteCommand" : ["dmodel.feasibleMoveDiscreteCommand"],
        "mapping.robotStopped" : ["dmodel.robotStopped"],
        "mapping.gripperOpened" : ["dmodel.gripperOpened"],
        "mapping.collision" : ["dmodel.collision"],
        "mapping.gripperClosed" : ["dmodel.gripperClosed"],
        "mapping.nonfeasibleMoveDiscreteCommand" : ["dmodel.nonfeasibleMoveDiscreteCommand"],
        "mapping.moveCompleted" : ["dmodel.moveCompleted"],
        "dmodel.movediscrete" : ["mapping.movediscrete"],
        "dmodel.pick" : ["mapping.pick"],
        "dmodel.place" : ["mapping.place"],
        "dmodel.target_X" : ["mapping.target_X"],
        "dmodel.target_Y" : ["mapping.target_Y"],
        "dmodel.target_Z" : ["mapping.target_Z"],
        "dmodel.closing_diameter" : ["mapping.closing_diameter"],
        "dmodel.closing_speed" : ["mapping.closing_speed"],
        "dmodel.closing_force" : ["mapping.closing_force"],
        "dmodel.opening_diameter" : ["mapping.opening_diameter"],
        "dmodel.opening_speed" : ["mapping.opening_speed"],
        "dmodel.opening_force" : ["mapping.opening_force"],
        "dmodel.stop" : ["mapping.stop"],
        "dmodel.movejoint" : ["mapping.movejoint"],
        "dmodel.target_q0" : ["mapping.target_q0"],
        "dmodel.target_q1" : ["mapping.target_q1"],
        "dmodel.target_q2" : ["mapping.target_q2"],
        "dmodel.target_q3" : ["mapping.target_q3"],
        "dmodel.target_q4" : ["mapping.target_q4"],
        "dmodel.target_q5" : ["mapping.target_q5"],
        "dmodel.movecartesian" : ["mapping.movecartesian"],
        "dmodel.target_x" : ["mapping.target_x"],
        "dmodel.target_y" : ["mapping.target_y"],
        "dmodel.target_z" : ["mapping.target_z"],
        "dmodel.target_rx" : ["mapping.target_rx"],
        "dmodel.target_ry" : ["mapping.target_ry"],
        "dmodel.target_rz" : ["mapping.target_rz"],
        "dmodel.setvelocity" : ["mapping.setvelocity"],
        "dmodel.target_v" : ["mapping.target_v"],
	}

all_connections = {**timed_connections,**clocked_connections}

# Outputs for logging
q0 = 0.0
q1 = 0.0
q2 = 0.0
q3 = 0.0
q4 = 0.0
q5 = 0.0
movediscrete = False
dmodel_state = "Idle"
moveDiscreteCommand = False
MovementArgs_target_X = 0
MovementArgs_target_Y = 0
MovementArgs_target_Z = 0
robotStopped = False
moveCompleted = False

# Instantiate
mapping_fmu.instantiate(visible=False,
                    loggingOn=False,
                    eventModeUsed=False,
                    earlyReturnAllowed=False,
                    logMessage=None,
                    intermediateUpdate=None)
dmodel_fmu.instantiate(visible=False,
                    loggingOn=False,
                    eventModeUsed=False,
                    earlyReturnAllowed=True,
                    logMessage=None,
                    intermediateUpdate=None)
controller_fmu.instantiate(visible=False,
                    loggingOn=False,
                    eventModeUsed=False,
                    earlyReturnAllowed=True,
                    logMessage=None,
                    intermediateUpdate=None)

# Initialization mode
mapping_fmu.enterInitializationMode()
dmodel_fmu.enterInitializationMode()
controller_fmu.enterInitializationMode()

# Set parameters if needed
controller_fmu.setBoolean([vrs_controller["repeat_cycles"]],[True])

## For different initial conditions (robot arm)
# mapping_fmu.setFloat64([vrs_mapping["q0"]],[0.0])
# mapping_fmu.setFloat64([vrs_mapping["q1"]],[0.0])
# mapping_fmu.setFloat64([vrs_mapping["q2"]],[0.0])
# mapping_fmu.setFloat64([vrs_mapping["q3"]],[0.0])
# mapping_fmu.setFloat64([vrs_mapping["q4"]],[0.0])
# mapping_fmu.setFloat64([vrs_mapping["q5"]],[0.0])

q0 = 0.0
q1 = 0.0
q2 = 0.0
q3 = 0.0
q4 = 0.0
q5 = 0.0
movediscrete = False
moveDiscreteCommand = False
MovementArgs_target_X = 0
MovementArgs_target_Y = 0
MovementArgs_target_Z = 0
robotStopped = False
moveCompleted = False

# Updating outputs to initial values
## Timed variables
q0 = mapping_fmu.getFloat64([vrs_mapping["q0"]])[0]
q1 = mapping_fmu.getFloat64([vrs_mapping["q1"]])[0]
q2 = mapping_fmu.getFloat64([vrs_mapping["q2"]])[0]
q3 = mapping_fmu.getFloat64([vrs_mapping["q3"]])[0]
q4 = mapping_fmu.getFloat64([vrs_mapping["q4"]])[0]
q5 = mapping_fmu.getFloat64([vrs_mapping["q5"]])[0]

## Clocked variables
movediscrete = dmodel_fmu.getClock([vrs_dmodel["movediscrete"]])[0]
moveDiscreteCommand = controller_fmu.getClock([vrs_controller["moveDiscreteCommand"]])[0]
robotStopped = mapping_fmu.getClock([vrs_mapping["robotStopped"]])[0]
moveCompleted = mapping_fmu.getClock([vrs_mapping["moveCompleted"]])[0]
MovementArgs_target_X = controller_fmu.getFloat32([vrs_controller["MovementArgs_target_X"]])[0]
MovementArgs_target_Y = controller_fmu.getFloat32([vrs_controller["MovementArgs_target_Y"]])[0]
MovementArgs_target_Z = controller_fmu.getFloat32([vrs_controller["MovementArgs_target_Z"]])[0]

# Get and set initial values
for connection_src,connection_sink in all_connections.items():
        connection_src_array = connection_src.split(".")
        # Get the current output
        if connection_src_array[0] == "mapping":
            for k,v in vars.items():
                if connection_src_array[1] == k:
                    match v:
                        case "Float64":
                            o = mapping_fmu.getFloat64([vrs_mapping[connection_src_array[1]]])[0]
                        case "Int32":
                            o = mapping_fmu.getInt32([vrs_mapping[connection_src_array[1]]])[0]
                        case "Clock":
                            o = mapping_fmu.getClock([vrs_mapping[connection_src_array[1]]])[0]
        elif connection_src_array[0] == "controller":
            for k,v in vars.items():
                if connection_src_array[1] == k:
                    match v:
                        case "Float64":
                            o = controller_fmu.getFloat64([vrs_controller[connection_src_array[1]]])[0]
                        case "Int32":
                            o = controller_fmu.getInt32([vrs_controller[connection_src_array[1]]])[0]
                        case "Clock":
                            o = controller_fmu.getClock([vrs_controller[connection_src_array[1]]])[0]
        elif connection_src_array[0] == "dmodel":
            for k,v in vars.items():
                if connection_src_array[1] == k:
                    match v:
                        case "Float64":
                            o = dmodel_fmu.getFloat64([vrs_dmodel[connection_src_array[1]]])[0]
                        case "Int32":
                            o = dmodel_fmu.getInt32([vrs_dmodel[connection_src_array[1]]])[0]
                        case "Clock":
                            o = dmodel_fmu.getClock([vrs_dmodel[connection_src_array[1]]])[0]
               
        # Set the inputs
        for sink in connection_sink:
            sink_array = sink.split(".")
            if sink_array[0] == "mapping":
                for k,v in vars.items():
                    if sink_array[1] == k:
                        match v:
                            case "Float64":
                                mapping_fmu.setFloat64([vrs_mapping[sink_array[1]]],[o])
                            case "Int32":
                                mapping_fmu.setInt32([vrs_mapping[sink_array[1]]],[o])
                            case "Clock":
                                mapping_fmu.setClock([vrs_mapping[sink_array[1]]],[o])
            elif sink_array[0] == "controller":
                for k,v in vars.items():
                    if sink_array[1] == k:
                        match v:
                            case "Float64":
                                controller_fmu.setFloat64([vrs_controller[sink_array[1]]],[o])
                            case "Int32":
                                controller_fmu.setInt32([vrs_controller[sink_array[1]]],[o])
                            case "Clock":
                                controller_fmu.setClock([vrs_controller[sink_array[1]]],[o])
            elif sink_array[0] == "dmodel":
                for k,v in vars.items():
                    if sink_array[1] == k:
                        match v:
                            case "Float64":
                                dmodel_fmu.setFloat64([vrs_dmodel[sink_array[1]]],[o])
                            case "Int32":
                                dmodel_fmu.setInt32([vrs_dmodel[sink_array[1]]],[o])
                            case "Clock":
                                dmodel_fmu.setClock([vrs_dmodel[sink_array[1]]],[o])


# Exit initialization mode
mapping_fmu.exitInitializationMode()
dmodel_fmu.exitInitializationMode()
controller_fmu.exitInitializationMode()

# Co-simulation loop (loose coupling)
logger.info(f"Initializing co-simulation for {end_simulation_time} seconds, with step size {step_size}, and real-time {simulation_program_delay}")
while (sim_time < end_simulation_time):
    start_computation_time = time.perf_counter()

    # Get current state from timed connections
    for connection_src,connection_sink in timed_connections.items():
        connection_src_array = connection_src.split(".")
        # Get the current output
        if connection_src_array[0] == "mapping":
            for k,v in vars.items():
                if connection_src_array[1] == k:
                    match v:
                        case "Float64":
                            o = mapping_fmu.getFloat64([vrs_mapping[connection_src_array[1]]])[0]
                        case "Int32":
                            o = mapping_fmu.getInt32([vrs_mapping[connection_src_array[1]]])[0]
        elif connection_src_array[0] == "controller":
            for k,v in vars.items():
                if connection_src_array[1] == k:
                    match v:
                        case "Float64":
                            o = controller_fmu.getFloat64([vrs_controller[connection_src_array[1]]])[0]
                        case "Int32":
                            o = controller_fmu.getInt32([vrs_controller[connection_src_array[1]]])[0]
        elif connection_src_array[0] == "dmodel":
            for k,v in vars.items():
                if connection_src_array[1] == k:
                    match v:
                        case "Float64":
                            o = dmodel_fmu.getFloat64([vrs_dmodel[connection_src_array[1]]])[0]
                        case "Int32":
                            o = dmodel_fmu.getInt32([vrs_dmodel[connection_src_array[1]]])[0]
        
        # Set the inputs
        for sink in connection_sink:
            sink_array = sink.split(".")
            if sink_array[0] == "mapping":
                for k,v in vars.items():
                    if sink_array[1] == k:
                        match v:
                            case "Float64":
                                mapping_fmu.setFloat64([vrs_mapping[sink_array[1]]],[o])
                            case "Int32":
                                mapping_fmu.setInt32([vrs_mapping[sink_array[1]]],[o])
            elif sink_array[0] == "controller":
                for k,v in vars.items():
                    if sink_array[1] == k:
                        match v:
                            case "Float64":
                                controller_fmu.setFloat64([vrs_controller[sink_array[1]]],[o])
                            case "Int32":
                                controller_fmu.setInt32([vrs_controller[sink_array[1]]],[o])
            elif sink_array[0] == "dmodel":
                for k,v in vars.items():
                    if sink_array[1] == k:
                        match v:
                            case "Float64":
                                dmodel_fmu.setFloat64([vrs_dmodel[sink_array[1]]],[o])
                            case "Int32":
                                dmodel_fmu.setInt32([vrs_dmodel[sink_array[1]]],[o])

    # Step all FMUs
    logger.info(f"Doing a step of size {step_size} at time {sim_time}")
    mapping_event_needed,mapping_terminate_sim,mapping_early_return,mapping_last_successful_time = mapping_fmu.doStep(sim_time, step_size)
    dmodel_event_needed,dmodel_terminate_sim,dmodel_early_return,dmodel_last_successful_time = dmodel_fmu.doStep(sim_time, step_size)
    controller_event_needed,controller_terminate_sim,controller_early_return,controller_last_successful_time = controller_fmu.doStep(sim_time, step_size)

    super_dense_time = 0
    while (mapping_event_needed or dmodel_event_needed or controller_event_needed):
        # logger.info(f"Event handling needed - Super-dense time: {super_dense_time}")
        # logger.info(f"mapping_event_needed: {mapping_event_needed}")
        # logger.info(f"dmodel_event_needed: {dmodel_event_needed}")
        # logger.info(f"controller_event_needed: {controller_event_needed}")

        # Set FMUs into event mode
        controller_fmu_in_event_mode = False
        dmodel_fmu_in_event_mode = False
        mapping_fmu_in_event_mode = False

        # If all FMUs go into event mode
        controller_fmu.enterEventMode()
        dmodel_fmu.enterEventMode()
        mapping_fmu.enterEventMode()

        controller_fmu_in_event_mode = True
        dmodel_fmu_in_event_mode = True
        mapping_fmu_in_event_mode = True

        # In case some FMUs don't need to go into event mode
        # if controller_event_needed and not mapping_event_needed: # controller FMU always activates clocks in dmodel FMU
        #     controller_fmu.enterEventMode()
        #     controller_fmu_in_event_mode = True
        #     dmodel_fmu.enterEventMode()
        #     dmodel_fmu_in_event_mode = True
        # elif controller_event_needed and mapping_event_needed:
        #     controller_fmu.enterEventMode()
        #     controller_fmu_in_event_mode = True
        #     dmodel_fmu.enterEventMode()
        #     dmodel_fmu_in_event_mode = True
        #     mapping_fmu.enterEventMode()
        #     mapping_fmu_in_event_mode = True
        # elif not controller_event_needed and (dmodel_event_needed or mapping_event_needed): # These two fmus must go in event mode together
        #     dmodel_fmu.enterEventMode()
        #     dmodel_fmu_in_event_mode = True
        #     mapping_fmu.enterEventMode()
        #     mapping_fmu_in_event_mode = True   
    
        # Get and set clocked variables
        for connection_src,connection_sink in clocked_connections.items():
            o = None
            connection_src_array = connection_src.split(".")
            # Get the current output
            if (connection_src_array[0] == "mapping") and mapping_fmu_in_event_mode:
                for k,v in vars.items():
                    if connection_src_array[1] == k:
                        match v:
                            case "Float64":
                                o = mapping_fmu.getFloat64([vrs_mapping[connection_src_array[1]]])[0]
                            case "Int32":
                                o = mapping_fmu.getInt32([vrs_mapping[connection_src_array[1]]])[0]
                            case "Clock":
                                o = mapping_fmu.getClock([vrs_mapping[connection_src_array[1]]])[0]
            elif (connection_src_array[0] == "controller") and controller_fmu_in_event_mode:
                for k,v in vars.items():
                    if connection_src_array[1] == k:
                        match v:
                            case "Float64":
                                o = controller_fmu.getFloat64([vrs_controller[connection_src_array[1]]])[0]
                            case "Int32":
                                o = controller_fmu.getInt32([vrs_controller[connection_src_array[1]]])[0]
                            case "Clock":
                                o = controller_fmu.getClock([vrs_controller[connection_src_array[1]]])[0]
            elif (connection_src_array[0] == "dmodel") and dmodel_fmu_in_event_mode:
                for k,v in vars.items():
                    if connection_src_array[1] == k:
                        match v:
                            case "Float64":
                                o = dmodel_fmu.getFloat64([vrs_dmodel[connection_src_array[1]]])[0]
                            case "Int32":
                                o = dmodel_fmu.getInt32([vrs_dmodel[connection_src_array[1]]])[0]
                            case "Clock":
                                o = dmodel_fmu.getClock([vrs_dmodel[connection_src_array[1]]])[0]
                
            # Set the inputs
            if o == None:
                continue
            for sink in connection_sink:
                sink_array = sink.split(".")
                if (sink_array[0] == "mapping") and mapping_fmu_in_event_mode:
                    for k,v in vars.items():
                        if sink_array[1] == k:
                            match v:
                                case "Float64":
                                    mapping_fmu.setFloat64([vrs_mapping[sink_array[1]]],[o])
                                case "Int32":
                                    mapping_fmu.setInt32([vrs_mapping[sink_array[1]]],[o])
                                case "Clock":
                                    mapping_fmu.setClock([vrs_mapping[sink_array[1]]],[o])
                elif (sink_array[0] == "controller") and controller_fmu_in_event_mode:
                    for k,v in vars.items():
                        if sink_array[1] == k:
                            match v:
                                case "Float64":
                                    controller_fmu.setFloat64([vrs_controller[sink_array[1]]],[o])
                                case "Int32":
                                    controller_fmu.setInt32([vrs_controller[sink_array[1]]],[o])
                                case "Clock":
                                    controller_fmu.setClock([vrs_controller[sink_array[1]]],[o])
                elif (sink_array[0] == "dmodel") and dmodel_fmu_in_event_mode:
                    for k,v in vars.items():
                        if sink_array[1] == k:
                            match v:
                                case "Float64":
                                    dmodel_fmu.setFloat64([vrs_dmodel[sink_array[1]]],[o])
                                case "Int32":
                                    dmodel_fmu.setInt32([vrs_dmodel[sink_array[1]]],[o])
                                case "Clock":
                                    dmodel_fmu.setClock([vrs_dmodel[sink_array[1]]],[o])

        # Update discrete states, read clocked outputs for logging, and check if event handling is still needed
        if dmodel_fmu_in_event_mode:
            (mapping_discrete_states_need_update,terminate_simulation,
            mapping_nominals_of_continuous_states_changed,
            mapping_values_of_continuous_states_changed,
            mapping_next_event_time_defined,
            mapping_next_event_time) = mapping_fmu.updateDiscreteStates()
            robotStopped = mapping_fmu.getClock([vrs_mapping["robotStopped"]])[0]
            moveCompleted = mapping_fmu.getClock([vrs_mapping["moveCompleted"]])[0]
            mapping_event_needed = mapping_discrete_states_need_update

        if dmodel_fmu_in_event_mode:
            (dmodel_discrete_states_need_update,terminate_simulation,
            dmodel_nominals_of_continuous_states_changed,
            dmodel_values_of_continuous_states_changed,
            dmodel_next_event_time_defined,
            dmodel_next_event_time) = dmodel_fmu.updateDiscreteStates()
            movediscrete = dmodel_fmu.getClock([vrs_dmodel["movediscrete"]])[0]
            dmodel_event_needed = dmodel_discrete_states_need_update
        
        if controller_fmu_in_event_mode:
            (controller_discrete_states_need_update,terminate_simulation,
            controller_nominals_of_continuous_states_changed,
            controller_values_of_continuous_states_changed,
            controller_next_event_time_defined,
            controller_next_event_time) = controller_fmu.updateDiscreteStates()            
            moveDiscreteCommand = controller_fmu.getClock([vrs_controller["moveDiscreteCommand"]])[0]        
            MovementArgs_target_X = controller_fmu.getFloat32([vrs_controller["MovementArgs_target_X"]])[0]
            MovementArgs_target_Y = controller_fmu.getFloat32([vrs_controller["MovementArgs_target_Y"]])[0]
            MovementArgs_target_Z = controller_fmu.getFloat32([vrs_controller["MovementArgs_target_Z"]])[0]
            controller_event_needed = controller_discrete_states_need_update

        super_dense_time += 1

        # Store the data in the dataframe
        df.loc[len(df)] = [
            sim_time,
            super_dense_time,
            moveDiscreteCommand,
            MovementArgs_target_X,
            MovementArgs_target_Y,
            MovementArgs_target_Z,
            movediscrete,
            q0,
            q1,
            q2,
            q3,
            q4,
            q5,
            robotStopped,
            moveCompleted
        ]

        # Get back to step mode
        if (mapping_fmu_in_event_mode) and (not mapping_event_needed):            
            mapping_fmu.enterStepMode()
        
        if (dmodel_fmu_in_event_mode) and (not dmodel_event_needed):
            dmodel_fmu.enterStepMode()
        
        if (controller_fmu_in_event_mode) and (not controller_event_needed):
            controller_fmu.enterStepMode()

    # Read timed outputs for logging
    q0 = mapping_fmu.getFloat64([vrs_mapping["q0"]])[0]
    q1 = mapping_fmu.getFloat64([vrs_mapping["q1"]])[0]
    q2 = mapping_fmu.getFloat64([vrs_mapping["q2"]])[0]
    q3 = mapping_fmu.getFloat64([vrs_mapping["q3"]])[0]
    q4 = mapping_fmu.getFloat64([vrs_mapping["q4"]])[0]
    q5 = mapping_fmu.getFloat64([vrs_mapping["q5"]])[0]

    # logger.info(f"mapping.q0 :  {q0}")
    # logger.info(f"mapping.q1 :  {q1}")
    # logger.info(f"mapping.q2 :  {q2}")
    # logger.info(f"mapping.q3 :  {q3}")
    # logger.info(f"mapping.q4 :  {q4}")
    # logger.info(f"mapping.q5 :  {q5}")
    # logger.info(f"mapping.robotStopped :  {robotStopped}")
    # logger.info(f"mapping.moveCompleted :  {moveCompleted}")
    # logger.info(f"controller.moveDiscreteCommand :  {moveDiscreteCommand}")
    # logger.info(f"controller.MovementArgs_target_X :  {MovementArgs_target_X}")
    # logger.info(f"controller.MovementArgs_target_Y :  {MovementArgs_target_Y}")
    # logger.info(f"controller.MovementArgs_target_Z :  {MovementArgs_target_Z}")
    # logger.info(f"dmodel.movediscrete :  {movediscrete}")   

    # # Store the data in the dataframe
    # df.loc[len(df)] = [
    #     sim_time,
    #     super_dense_time,
    #     moveDiscreteCommand,
    #     MovementArgs_target_X,
    #     MovementArgs_target_Y,
    #     MovementArgs_target_Z,
    #     movediscrete,
    #     q0,
    #     q1,
    #     q2,
    #     q3,
    #     q4,
    #     q5,
    #     robotStopped,
    #     moveCompleted
    # ]

    sim_time += step_size
    end_computation_time = time.perf_counter()
    computation_time = end_computation_time - start_computation_time
    if (simulation_program_delay):
        # logger.info(f'Computation time {computation_time}')
        sleeping_time = step_size-computation_time
        if sleeping_time<0:
            sleeping_time = 0.0
        # logger.info(f'Sleeping for {sleeping_time} to follow real time')
        time.sleep(sleeping_time)

# save the data
df.to_csv("data/simulation_data.csv", index=False)

# Terminate instances
mapping_fmu.terminate()
mapping_fmu.freeInstance()
dmodel_fmu.terminate()
dmodel_fmu.freeInstance()
controller_fmu.terminate()
controller_fmu.freeInstance()

# clean up
shutil.rmtree(unzipdir_mapping, ignore_errors=True)
shutil.rmtree(unzipdir_dmodel, ignore_errors=True)
shutil.rmtree(unzipdir_controller, ignore_errors=True)