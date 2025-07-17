#!/bin/bash
#Author: Santiago Gil

rm mappingFMU.fmu
# Creating the fmu for CoppeliaSim
(cd mappingFMU && zip -r mappingFMU.fmu .)
cp mappingFMU/mappingFMU.fmu .
rm mappingFMU/mappingFMU.fmu


