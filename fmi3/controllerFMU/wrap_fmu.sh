#!/bin/bash
#Author: Santiago Gil
# Controller FMU
rm controllerFMU.fmu
(cd controllerFMU && zip -r controllerFMU.fmu .)
cp controllerFMU/controllerFMU.fmu .
rm controllerFMU/controllerFMU.fmu
