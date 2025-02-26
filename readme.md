# Digital Twin implementations of robotic platforms with Co-simulation and RoboStar

This repository contains the [templates](#templates) for the technique to create Digital Twin implementations of robotic platforms using co-simulation and [RoboStar](https://github.com/UoY-RoboStar) technologies associated to [this publication](#cite-this-work).

We also provide [examples](#implementation-for-the-ur5eur3e) for the instantiation of the [templates](#templates) for the Universal Robots UR5e (see [here](UR5e/)) and the UR3e (see [here](UR3e/)). The UR5e belongs to a manufacturing cell, the [Flex-cell](https://github.com/INTO-CPS-Association/DTaaS-examples/tree/main/digital_twins/flex-cell), which has been used as a case study for Digital Twins in robotics. For these examples, we provide the implementations for simulation using [CoppeliaSim](https://github.com/CoppeliaRobotics) and for real robots using the [URInterface](https://gitlab.au.dk/clagms/urinterface), which is based on the [Universal Robots RTDE](https://github.com/UniversalRobots/RTDE_Python_Client_Library).



## Installation
0. Java and Python must be installed.
1. Clone this repository.
<pre>
git clone https://github.com/INTO-CPS-Association/DigitalTwins_RoboSim.git
</pre>
2. Install CoppeliaSim:
  https://www.coppeliarobotics.com/
3. Install ZeroMQ to communicate remotely with CoppeliaSim and the URInterface to communicate with the UR5e/UR3e:
<pre>
  python3 -m pip install coppeliasim-zmqremoteapi-client zmq urinterface
</pre>
4. Install the additional dependencies for running and testing the examples and components - [Robotics Toolbox Python](https://github.com/petercorke/robotics-toolbox-python), pickle, [FMPy](https://github.com/CATIA-Systems/FMPy), mqtt, and pika (AMQP):
<pre>
  python3 -m pip install roboticstoolbox-python pickle fmpy paho-mqtt pika
</pre>

## External resources
Some of the tools this approach relies on include:
1. [UniFMU](https://github.com/INTO-CPS-Association/unifmu).
2. [RoboTool](https://robostar.cs.york.ac.uk/robotool/).
3. [RabbitMQFMU](https://github.com/INTO-CPS-Association/fmu-rabbitmq).
4. [Maestro](https://github.com/INTO-CPS-Association/maestro).
5. [FMI Standard and headers](https://github.com/modelica/fmi-standard).
6. [TwinManager](https://github.com/sagilar/TwinManager).

## Implementation of Examples
We provide the implementation of three examples below, with the general methodology outlined in the following **Templates** section of this readme.
1. [UR3e](https://github.com/INTO-CPS-Association/DigitalTwins_RoboSim/tree/main/UR3e)
2. [UR5e](https://github.com/INTO-CPS-Association/DigitalTwins_RoboSim/tree/main/UR5e)
3. [Mobile Robot](https://github.com/INTO-CPS-Association/DigitalTwins_RoboSim/tree/main/mobileRobot)

## Templates
We provide templates based on the provided methodology in our paper (see [Cite this work](#cite-this-work)) in the [templates folder](templates/).

The script ```templates/helper.py``` provides a set of miscellaneous functions that help with automatically printing some portions of code to set up the templates based on the particular RoboSim models and variables names. These portions of code are printed to the terminal and must be copied and pasted to the corresponding files.

To use this script, update the RoboSim module name in `robosim_module_name = "name"`; update the dictionary `vars` with your Input Events, Operations, and Arguments for Input Events and Operations accordingly; define which of the Input Events are to be provided by the controller FMU in `vars_controller`; and define which variables of the robotic platform you want to log in `vars_log_pmFMU` (these are not necessarily part of the RoboSim module but observations you can get from the robotic platform - either real or simulated).

The script provides 11 functions that provide some portions of code for the following files or sections in the templates:
1. `connections` field in the `step5_co-simulation/multimodel.json` file used by Maestro to set up the co-simulation given the FMUs and connections (see [here](templates/step5_co-simulation/multimodel.json)). (**Step 5 in the methodology**)
2. `ModelDescription.xml` of the platform mapping FMU (see [here](templates/steps6-7_MappingFMU/mappingFMU/modelDescription.xml)). (**Step 6 in the methodology**)
3. `model.py` of the platform mapping FMU (see [here](templates/steps6-7_MappingFMU/mappingFMU/resources/model.py)). (**Steps 6 and 7 in the methodology**)
4. `ModelDescription.xml` of the d-model FMU (see [here](templates/steps8-11_dmodelFMU/modelDescription.xml)). (**Step 8 in the methodology**)
5. `ModelData struct` in `steps8-11_dmodelFMU/adapted_C/defs_fmi.h` of the d-model FMU (see [here](templates/steps8-11_dmodelFMU/adapted_C/defs_fmi.h)). (**Step 9 in the methodology**)
6. `read_input` function in the `steps8-11_dmodelFMU/adapted_C/interface.h` file of the d-model FMU (see [here](templates/steps8-11_dmodelFMU/adapted_C/interface.h)). (**Step 10 in the methodology**)
7. `write_output` function in the `steps8-11_dmodelFMU/adapted_C/interface.h` file of the d-model FMU (see [here](templates/steps8-11_dmodelFMU/adapted_C/interface.h)). (**Step 10 in the methodology**)
8. `skeleton.c` of the d-model FMU (see [here](templates/steps8-11_dmodelFMU/skeleton.c)). (**Step 11 in the methodology**)
9. `setStartValues` function in the `steps8-11_dmodelFMU/adapted_C/main.c` file of the d-model FMU (see [here](templates/steps8-11_dmodelFMU/adapted_C/main.c)). (**Step 11 in the methodology**)
10. `model.py` of the controller FMU (see [here](templates/steps12-13_controller/controllerFMU/resources/model.py)). (**Steps 12 and 13 in the methodology**)
11. `ModelDescription.xml` of the controller FMU (also works for the outputs of the RabbitMQ FMU) (see [here](templates/steps12-13_controller/controllerFMU/modelDescription.xml) for the controllerFMU; RabbitMQ FMU requires the same `ModelDescription.xml` in two places, [here](templates/steps12-13_controller/rmqfmu/modelDescription.xml) and [here](templates/steps12-13_controller/rmqfmu/resources/modelDescription.xml)). (**Step 13 in the methodology**)



### Steps
- **Steps 1 and 2** are case-specific. Refer to the examples provided in [UR5e/UR3e Models](#models) for further guidance.
- **Step 3** refers to the platform mapping interface, whose template is provided in [mapping template](templates/step3_mapping/). Here, the user is expected create the mapping given the robotic platform and the communication interface and libraries required. For exemplification, refer to [mapping UR5e](UR5e/mapping/) to see the instantiation of the mapping template for the UR5e with two different interfaces, the CoppeliaSim Remote API and the URInterface.
- **Step 4** is case-specific; be sure the simulation or real robotic platform is running and enabled for remote connection based on the communication interface provided in Step 3. Refer to the examples provided in [UR5e/UR3e Models](#p-model) for further guidance.
- **Step 5** is defined in the `co-simulation/multimodel.json` file ([co-simulation template](templates/step5_co-simulation/)) for the co-simulation and the distinct `ModelDescription.xml` files for each FMU. Use the feature **1** of `templates/helper.py` to get the connections between FMUs. The features **2, 4, and 11** also help to set up the `ModelDescription.xml` files that are used for the FMUs used in the co-simulation. For exemplification, refer to [co-simulation UR5e](UR5e/co-simulation/) to see the implementation of the co-simulation for the UR5e.
- **Steps 6 and 7** are provided in the [mapping FMU template](templates/steps6-7_mappingFMU/). Use the features **2 and 3** of the `templates/helper.py` to set up the platform mapping FMU. When everything is done, use the provided script `templates/steps6-7_mappingFMU/wrap_fmu.sh` to wrap the platform mapping FMU with extension `.fmu`, including the worked-out **Step 3**. For exemplification, refer to [mapping FMU UR5e](UR5e/mapping/) to see the instantiation of the mapping FMU template for the UR5e.
- **Step 8** is provided in the [d-model FMU template](templates/steps8-11_dmodelFMU/). Adapt the automatically generated C code in the `templates/steps8-11_dmodelFMU/adapted_C` folder using the guidance provided to adapt the `main.c` file. Update the `ModelDescription.xml` file using the feature **4** of the `templates/helper.py`.
For exemplification, refer to [d-model FMU](d-model/) to see the instantiation of the d-model FMU template for the UR5e.
- **Step 9** is provided in the [defs_fmi.h template](templates/steps8-11_dmodelFMU/adapted_C/defs_fmi.h). Use the feature **5** of the `templates/helper.py` to update the data struct.
- **Step 10** is provided in the [interface.h template](templates/steps8-11_dmodelFMU/adapted_C/interface.h). Use the features **6 and 7** of the `templates/helper.py` to update the behavior of the `interface.h` based on your data.
- **Step 11** is provided in the [d-model FMU template](templates/steps8-11_dmodelFMU/). Adapt the `skeleton.c` using the feature **8** of the `templates/helper.py` and the `main.c` using the feature **9** of the `templates/helper.py`. Be sure to have the modified structure in your `main.c` so the program is started using the `init` and called using the `tick` function.
- **Steps 12 and 13** are provided in the [templates for the controller and RabbitMQ FMU](templates/steps12-13_controller). The logic is to be stored in the `templates/steps12-13_controller/controllerFMU/resources/model.py` (see [here](templates/steps12-13_controller/controllerFMU/resources/model.py)) for the controller FMU (use the feature **10** of the `templates/helper.py` to set up the `model.py` of the controller FMU) and in the `templates/steps12-13_controller/publisher_rmq.py` (see [here](templates/steps12-13_controller/publisher_rmq.py)) for the RabbitMQ FMU. Use the feature **11** of the `templates/helper.py` to set up the `ModelDescription.xml` files of the controller FMU and the RabbitMQ FMU (**Note:** RabbitMQ FMU requires that the `ModelDescription.xml` file is also stored in its resources folder `rmqfmu/resources/`). For exemplification, refer to [controller UR5e](UR5e/controller) to see the instantiation of the controller FMU and RabbitMQ FMU templates for the UR5e.

### Execution

After these steps have been worked out, the co-simulation can be executed using the script `templates/step5_co-simulation/cosimulation_execution.sh`. For exemplification, refer to [co-simulation UR5e](UR5e/co-simulation/) to see the implementation of the co-simulation for the UR5e.

## Cite this work
TBD
