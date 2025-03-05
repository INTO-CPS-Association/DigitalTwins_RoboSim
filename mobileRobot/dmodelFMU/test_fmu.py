# Santiago
from fmpy import read_model_description, extract
from fmpy.fmi2 import FMU2Slave
from fmpy.util import plot_result, download_test_file
import numpy as np
import shutil
import signal
import sys
import time

def signal_handler(sig, frame):
    print('Ctrl+C pressed')
    fmu.terminate()
    fmu.freeInstance()
    print("Forcing the termination of the FMI Simulation")
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

fmu_filename = 'dmodelFMU.fmu'
start_simulation_time = 0.0
threshold = 2.0
stop_simulation_time = 10.0
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
    if idx == 0:
        fmu.setBoolean([vrs["closestAngle"]],[True]) # EnableVHF event
        fmu.setBoolean([vrs["closestDistance"]],[True]) # EnableClusterWatch event
        fmu.setReal([vrs["closest_angle"]],[0.3]) # closest_angle value
        fmu.setReal([vrs["closest_distance"]],[0.4]) # closest_distance value
        #pass

    # if idx == 1:
    #     #fmu.setBoolean([vrs["closestDistance"]],[False]) # EnableVHF event
    #     #fmu.setBoolean([vrs["closestAngle"]],[False]) # EnableClusterWatch event
    # #     #pass



    if idx == 8:
        fmu.setBoolean([vrs["closestAngle"]],[True]) # closestAngle event
        fmu.setBoolean([vrs["closestDistance"]],[True]) # closestDistance event
        fmu.setReal([vrs["closest_angle"]],[0.5]) # closest_angle value
        fmu.setReal([vrs["closest_distance"]],[0.6]) # closest_distance value

    # if idx == 10:
    #     #fmu.setBoolean([vrs["closestAngle"]],[False]) # closestAngle event
    #     #fmu.setBoolean([vrs["closestDistance"]],[False]) # closestDistance event


    if idx == 16:
        fmu.setBoolean([vrs["closestAngle"]],[True]) # closestAngle event
        fmu.setBoolean([vrs["closestDistance"]],[True]) # closestDistance event
        fmu.setReal([vrs["closest_angle"]],[0.7]) # closest_angle value
        fmu.setReal([vrs["closest_distance"]],[0.8]) # closest_distance value

    # if idx == 18:
    #     fmu.setBoolean([vrs["closestAngle"]],[False]) # closestAngle event
    #     fmu.setBoolean([vrs["closestDistance"]],[False]) # closestDistance event


    fmu.doStep(currentCommunicationPoint=simulation_time, communicationStepSize=step_size)


    # advance the simulation_time
    simulation_time += step_size
    idx = idx + 1
    #time.wait(step_size)

fmu.terminate()
fmu.freeInstance()
print("Terminating FMI Simulation")
# clean up
shutil.rmtree(unzipdir, ignore_errors=True)
