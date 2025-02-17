#!/bin/bash

### Build the TwinManager Jar ###
# mvn -f pom.xml package -Dmaven.test.skip=true -Dmaven.javadoc.skip=true # To build the TwinManager jar

### Create and activate a Python virtual environment ###
# python3 -m venv venv # Create a virtual Python environment
. venv/bin/activate # Activate the virtual environment

### Run on an external RabbitMQ publisher ###
# python ../controller/routine_prosumer.py & # To start the RMQ consumer/publisher externally

### Execute the Digital Twin application ###
java -cp /home/au698550/Aarhus/DT/TwinManager/Java/target/TwinManagerFramework-0.0.4.jar UR5eRoboSim.java # Execute the Digital Twin application with the TwinManager jar recently created. Update the TwinManager jar path accordingly

### Kill background processes
# pkill -9 -f ../controller/routine_prosumer.py # Kill background process for RMQ
pkill -f java # Kill background process for existing co-simulations
