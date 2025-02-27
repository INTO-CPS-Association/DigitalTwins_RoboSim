## Implementation for the UR3e
### Model artefacts
The RoboSim models are available in the folders ```URxe/robosim_models```. More precisely, the ```p-model``` is contained in the file ```urxe_gripper.pm```, the ```d-model``` in the file ```urxe_gripper.rst```, and the ```platform mapping model``` in the file ```mapping.pm```. **Note:** Both UR5e and UR3e use the same platform mapping and d-model (stored in the `UR5e` folder). [RoboTool](https://robostar.cs.york.ac.uk/robotool/) is required to access the models using the Eclipse Modeling Framework.

### Implementation and co-simulation artifacts

#### d-model C and d-model FMU
The implementation for the d-model C code is in the folder ```dmodelFMU```, which is adapted with the headers and interfaces of the [FMI Standard](https://github.com/modelica/fmi-standard) in folder ```dmodelFMU/adapted_C``` (the original source code generated with RoboSim is in `dmodelFMU/UR5e_code_v6`).  
The generation of the FMU for a different robot (or different data scope) needs to modify the data pointer between the FMI interface and the C application. The data structure is defined in the ```adapted_C/defs_fmi.h``` file under the struct ```ModelData```.
The ```skeleton.c``` file provides the interaction between the FMI data and the C application data using the data pointer, and taking over the ```adapted_C/DiscreteGrippingArm.c``` main C file through the ```init``` and ```tick``` methods, where the data pointer is passed and updated between the two data scopes. Be aware that the array indexes to access the data pointer in the FMI side are dependent on the indexes in the ```modelDescription.xml``` file.  
To generate the d-model FMU, use the ```makefile``` script through ```make all```. This will generate the ```dmodelFMU.fmu``` file, which is then used for the co-simulation.
The script ```dmodelFMU/test_fmu.py``` can be used to test the d-model FMU at the unit level.

#### Simulation based on the p-model
The implementation for the p-model SDF file is in the folder ```URxe/Scenes_CoppeliaSim```, which includes the ```urxe_gripper_pmodel.sdf``` generated from the p-models and the ```ur3e-DTLab.ttt``` and ```flex-cell-simple.ttt``` CoppeliaSim scenes accordingly, which are reduced versions of the original setup.
**Note:** Be sure your CoppeliaSim installation has the plugin that enables the Remote API via ZeroMQ.

#### Platform Mapping Interface and Platform Mapping FMU
The instantiation of the platform mapping is particular for each robotic platform. In the folder ```URxe/mapping```, we provide the prototypical implementation of the Platform Mapping Interface enabled with the interfaces for CoppeliaSim and for the URInterface.
This implementation is then used in the platform mapping FMU in the folder ```URxe/mappingFMU``` as part of the resources of the FMU, which has been created with [UniFMU](https://github.com/INTO-CPS-Association/unifmu).
Changes in the logic of the platform mapping FMU are to be made in the ```model.py``` file in the resources folder of the FMU, which are to be consistent with the ```ModelDescription.xml```.
The script ```URxe/mappingFMU/wrap_fmu.sh``` copies and pastes the previously created mapping interface into the FMU resources folder, and wraps the files with ```.fmu``` extension.
The script ```URxe/mappingFMU/test_fmu.py``` can be used to test the platform mapping FMU at the unit level.
**Note:** In case stand-alone libraries are to be used within the FMU, these should be copied and pasted in the FMU resources folder (if not installed system-wide).

#### Controller FMU
The controllerFMU or is alternative [RabbitMQFMU](https://github.com/INTO-CPS-Association/fmu-rabbitmq) are stored in the folder ```URxe/controller/```. The controllerFMU follows the [UniFMU](https://github.com/INTO-CPS-Association/unifmu) structure, and therefore, changes in the logic of the controller FMU are to be made in the ```model.py``` file in the resources folder of the FMU, which are to be consistent with the ```ModelDescription.xml```.
For RabbitMQFMU, the logic is to be updated in the publisher file ```URxe/controller/publisher_rmq.py```, which needs to be consistent with the ```ModelDescription.xml``` provided with RabbitMQFMU in the folders ```URxe/controller/rmqfmu``` and ```URxe/controller/rmqfmu/resources```.
The script ```URxe/controller/wrap_fmu.sh``` wraps the controllerFMU and RabbitMQFMU recently updated with ```.fmu``` extension.
The script ```URxe/controller/test_fmu.py``` can be used to test the controllerFMU at the unit level.


#### Co-simulation
The implementation for the co-simulation is in folder ```URxe/co-simulation```. Here, the FMUs previously created FMUs are orchestrated by the co-simulation engine [Maestro](https://github.com/INTO-CPS-Association/maestro) through the definition of the co-simulation configuration file ```multimodel_"".json```. There are 4 co-simulation files per robot, including combinations with RabbitMQFMU/ControllerFMU and CoppeliaSim/URInterface (**Note:** using RabbitMQFMU requires an active RabbitMQ broker to connect to, using CoppeliaSim requires that CoppeliaSim is up and running with the respective scene, and using the actual UR5e/UR3e robot requires that the robot is connected to the same network as the computer where you are running the co-simulation, with the right IP address provided in the platform mapping interface, and with remote control enabled on the teach pendant).

To execute the co-simulation, the JAR file for Maestro is required ([download it here](https://github.com/INTO-CPS-Association/maestro/releases/latest)), and execute the script ```URxe/co-simulation/cosimulation_execution.sh``` to run the co-simulation.
In this script, you can update the value of the variables ```using_rmqfmu=false``` and ```using_simulation=false``` to `true` or `false` depending on the scenario you want to run.
To stop the co-simulation and background services, use the script ```terminate.sh```.

The output of experiments is generated to the folder ```URxe/co-simulation/results``` by default (this path can be updated in the ```URxe/co-simulation/cosimulation_execution.sh``` file).


