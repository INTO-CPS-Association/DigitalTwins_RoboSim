# FMI3 Support

This folder provides an FMI3 implementation of the UR5e case study using [UniFMU](https://github.com/INTO-CPS-Association/unifmu) on its v0.12.0-beta, [FMI3 headers](https://github.com/modelica/fmi-standard), and a stand-alone co-simulation master algorithm.


https://github.com/user-attachments/assets/c7a964cb-be9d-4be4-b14e-15d6e57f15c9


## Table of Contents
- [Templates](#templates).
- [Controller FMU and Platform Mapping FMU](#controller-fmu-and-platform-mapping-fmu).
- [d-model FMU](#d-model-fmu).
- [Co-simulation and Execution](#co-simulation-and-execution).

## Templates
Similar to the FMI2 version, the script ```templates/helper.py``` provides a set of miscellaneous functions that help with automatically printing some portions of code to set up the templates based on the particular RoboSim models and variables names, now using the FMI3 notations and datatypes. These portions of code are printed to the terminal and must be copied and pasted to the corresponding files.
Take a look at the existing example to understand how to use the chunks of code.

## Controller FMU and Platform Mapping FMU
The Controller FMU and the Platform Mapping FMU follow the same principles as in the original approach for FMI2 (see the [root repository](../)).
For the FMI3 support, both FMUs extend from the templates of UniFMU v0.12.0-beta as Python FMI3 FMU and perform the execution of the time-based steps (`doStep`) and the event-based steps (`updateDiscreteStates`) accordingly.

## d-model FMU
The d-model FMU uses the headers from FMI3 and a similar structure for that in the approach with FMI2 (see the [d-model FMI2 FMU](../UR5e/dmodelFMU/)).
The functions required for the d-model FMI3 FMU have been implemented; however, those not required are left empty.
The integration between the FMI interface and the d-model state machines still happens in the `tick` function, as it is for the FMI2 version.

## Co-simulation and Execution
We created a stand-alone master algorithm for the execution of this particular example with the UR5e.
This master algorithm uses a non-official version of FMPy that supports some FMI3 functions not available in the original [FMPy library](https://github.com/CATIA-Systems/FMPy).

The co-simulation and execution script is `co-simulation/co-simulation_scenario.py`.
In this file, one can change the co-simulation parameters `end_simulation_time`, `start_simulation_time`, `step_size`, and `simulation_program_delay` (to follow real time) to those required.
In initialization mode, one can also change the initial values in the FMUs if required.

To run the co-simulation, there are some steps to follow:
1. Move the working directory to `co-simulation`:
    ```
    cd co-simulation
    ```
2. Create and activate a Python virtual environment:

    **Linux:**
    ```
    python3 -m venv venv
    . venv/bin/activate
    ```
    **Windows:**
    ```
    python -m venv venv
    source venv/Scripts/activate
    ```
3. Install the basic requirements:
    ```
    pip install -r requirements.txt
    ```

4. Copy the non-official FMPy `co-simulation/fmpy/fmi3.py` script provided into the virtual environment within the FMPy package. Check and replace the Python version installed in your virtual environment within the tag `<version>`:
    **Linux:**
    ```
    cp fmpy/fmi3.py venv/lib/python<version>/site-packages/fmpy/
    ```
    **Windows:**
    ```
    Copy-Item fmpy\fmi3.py venv\lib\python<version>\site-packages\fmpy
    ```
5. Start CoppeliaSim and open the scene for the UR5e (provided [here](../UR5e/Scenes_CoppeliaSim/)).
6. With the virtual environment activated, execute the co-simulation scenario with the `co-simulation/co-simulation_scenario.py` script:
    ```
    python co-simulation_scenario.py
    ```

After the co-simulation is executed, some data are collected into the `data/simulation_data.csv`. From the `fmi3` root folder, use the script `plots/plot.py` to plot the data with a given layout with:

```
python plots/plot.py data/simulation_data.csv --save
```


