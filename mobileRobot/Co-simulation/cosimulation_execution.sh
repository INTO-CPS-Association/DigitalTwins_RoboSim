#!/bin/bash
echo "Executing Co-simulation experiment"
echo "-----------------------------"
echo "Specification"
echo "-----------------------------"
maestro_path=/home/arjun/installs # Change path accordingly
maestro_jar=maestro-3.0.2-jar-with-dependencies.jar
output_path=results # Change accordingly

java -jar $maestro_path/$maestro_jar import sg1 coe.json multimodel_normq.json -output generate ## Update the json specification according to the experiment to run

echo "-----------------------------"
echo "Interpretation"
echo "-----------------------------"
java -jar $maestro_path/$maestro_jar interpret generate/spec.mabl -output $output_path

echo "Co-simulation experiment finished. See output results in folder '$output_path'"

