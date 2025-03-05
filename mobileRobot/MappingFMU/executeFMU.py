from fmpy import read_model_description, extract
from fmpy.fmi2 import FMU2Slave
import numpy as np
import shutil
import signal
import sys
import logging
import time

logging.disable()

def signal_handler(sig, frame):
    print('Ctrl+C pressed')
    fmu.terminate()
    fmu.freeInstance()
    print("Forcing the termination of the FMI Simulation")
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

fmu_filename = 'mappingFMU.fmu' ## Update according to the specific MappingFMU instance in use
start_simulation_time = 0.0
threshold = 2.0
stop_simulation_time = 20.0
step_size = 0.5
# read the model description
model_description = read_model_description(fmu_filename)

# collect the value references
vrs = {}
for variable in model_description.modelVariables:
    vrs[variable.name] = variable.valueReference

# extract the FMU
unzipdir = extract(fmu_filename)

fmu = FMU2Slave(guid=model_description.guid,
                unzipDirectory=unzipdir,
                modelIdentifier=model_description.coSimulation.modelIdentifier,
                instanceName='instance1')

# initialize
print("Initializing FMI Simulation")
fmu.instantiate()
fmu.setupExperiment(startTime=start_simulation_time)
fmu.enterInitializationMode()
fmu.exitInitializationMode()


simulation_time = start_simulation_time

# simulation loop
idx = 0
while simulation_time < stop_simulation_time:
    # NOTE: the FMU.get*() and FMU.set*() functions take lists of
    # value references as arguments and return lists of values
    print("Before FMI DoStep idx " + str(idx))
    if idx == 2:
        fmu.setReal([vrs["lv"],vrs["av"]],[0.8,0.7])
        fmu.setBoolean([vrs["move"]],[True])



    if idx == 11:
        fmu.setReal([vrs["lv"],vrs["av"]],[0.6,0.1])
        fmu.setBoolean([vrs["move"]],[True])

    if idx == 26:
        fmu.setReal([vrs["lv"],vrs["av"]],[0.0,0.0])
        fmu.setBoolean([vrs["move"]],[True])


    fmu.doStep(currentCommunicationPoint=simulation_time, communicationStepSize=step_size)
    print("closest_distance (mappingFMU): "+ str(fmu.getReal([vrs["closest_distance"]])))
    print("closest_angle (mappingFMU): " + str(fmu.getReal([vrs["closest_angle"]])))


    # advance the simulation_time
    simulation_time += step_size
    idx = idx + 1
    time.sleep(0.5)


fmu.terminate()
fmu.freeInstance()
print("Terminating FMI Simulation")
# clean up
shutil.rmtree(unzipdir, ignore_errors=True)
