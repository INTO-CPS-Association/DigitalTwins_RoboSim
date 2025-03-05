#!/bin/bash
echo "Executing Co-simulation experiment"
echo "-----------------------------"
echo "Specification"
echo "-----------------------------"
maestro_path=/home/arjun/installs # Change path accordingly
maestro_jar=maestro-2.4.1-jar-with-dependencies.jar
output_path=results # Change accordingly

java -jar $maestro_path/$maestro_jar import sg1 coe.json multimodel_rmq.json -output generate ## Update the json specification according to the experiment to run

echo "-----------------------------"
echo "Interpretation"
echo "-----------------------------"
python3 ../ControllerFMU/publisher_rmqfmu.py &
java -jar $maestro_path/$maestro_jar interpret generate/spec.mabl -output $output_path

echo "Co-simulation experiment finished. See output results in folder '$output_path'"
pkill -9 -f ../ControllerFMU/publisher_rmqfmu.py 

