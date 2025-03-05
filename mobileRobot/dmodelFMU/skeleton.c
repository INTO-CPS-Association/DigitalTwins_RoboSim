/*! \file skeleton.c
 * In this file there are the implementations
 * of the fuctions declared in fmu.h
 * along with the data needed.
 */
#include "fmu.h"
#include <stdio.h>

/**
 * Function for the initialization of the model.
 * It calls the init function of the model and sets the output.
 * It initializes the semaphore and creates the websocket thread.
 * @param location is the directory where the fmu has been unzipped. Might be used in future version
 *
 */
 void initialize(ModelInstance* comp, const char* location) {
    init(&comp->modelData);
    comp->fmiBuffer.booleanBuffer[0] = comp->modelData.closestDistance;
    comp->fmiBuffer.realBuffer[1] = comp->modelData.closest_distance;
    comp->fmiBuffer.booleanBuffer[2] = comp->modelData.closestAngle;
    comp->fmiBuffer.realBuffer[3] = comp->modelData.closest_angle;
    comp->fmiBuffer.booleanBuffer[4] = comp->modelData.move;
    comp->fmiBuffer.realBuffer[5] = comp->modelData.lv;
    comp->fmiBuffer.realBuffer[6] = comp->modelData.av;
    comp->fmiBuffer.stringBuffer[7] = comp->modelData.state;
    comp->fmiBuffer.stringBuffer[8] = comp->modelData.target_state;
    comp->fmiBuffer.stringBuffer[9] = comp->modelData.status;
    comp->fmiBuffer.booleanBuffer[10] = comp->modelData.done;
    comp->first = 0;
    }
void doStep(ModelInstance* comp, const char* action) {
    if(comp->first == 0) {
    comp->modelData.closestDistance = comp->fmiBuffer.booleanBuffer[0];
    comp->modelData.closest_distance = comp->fmiBuffer.realBuffer[1];
    comp->modelData.closestAngle = comp->fmiBuffer.booleanBuffer[2];
    comp->modelData.closest_angle = comp->fmiBuffer.realBuffer[3];
    }
    // Inputs and arguments
    comp->modelData.closestDistance = comp->fmiBuffer.booleanBuffer[0];
    comp->modelData.closest_distance = comp->fmiBuffer.realBuffer[1];
    comp->modelData.closestAngle = comp->fmiBuffer.booleanBuffer[2];
    comp->modelData.closest_angle = comp->fmiBuffer.realBuffer[3];
    // step in the module
    tick(&comp->modelData);
    // Outputs
    comp->fmiBuffer.booleanBuffer[4] = comp->modelData.move;
    comp->fmiBuffer.realBuffer[5] = comp->modelData.lv;
    comp->fmiBuffer.realBuffer[6] = comp->modelData.av;
    comp->fmiBuffer.stringBuffer[7] = comp->modelData.state;
    comp->fmiBuffer.stringBuffer[8] = comp->modelData.target_state;
    comp->fmiBuffer.stringBuffer[9] = comp->modelData.status;
    comp->fmiBuffer.booleanBuffer[10] = comp->modelData.done;
}


void terminate(ModelInstance* comp) {
    comp->terminateSimulation = true;
    comp->modelData.terminateSimulation = true;
    release();
}
