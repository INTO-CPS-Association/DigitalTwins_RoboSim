#!/bin/bash
#Author: Santiago Gil
# Controller FMU
rm controllerFMU.fmu
(cd controllerFMU && zip -r controllerFMU.fmu .)
cp controllerFMU/controllerFMU.fmu .
rm controllerFMU/controllerFMU.fmu

# RMQ FMU
rm rmqfmu.fmu
(cd rmqfmu && zip -r rmqfmu.fmu .)
cp rmqfmu/rmqfmu.fmu .
rm rmqfmu/rmqfmu.fmu

# RMQ FMU (DT)
rm rmqfmu_dt.fmu
(cd rmqfmu_dt && zip -r rmqfmu_dt.fmu .)
cp rmqfmu_dt/rmqfmu_dt.fmu .
rm rmqfmu_dt/rmqfmu_dt.fmu

# RMQ FMU (PT)
rm rmqfmu_pt.fmu
(cd rmqfmu_pt && zip -r rmqfmu_pt.fmu .)
cp rmqfmu_pt/rmqfmu_pt.fmu .
rm rmqfmu_pt/rmqfmu_pt.fmu
