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
 *
 */
void initialize(ModelInstance* comp) {
    init(&comp->modelData);
    comp->fmiBuffer.clockBuffer[0] = comp->modelData.feasibleMoveDiscreteCommand;
    comp->fmiBuffer.clockBuffer[1] = comp->modelData.robotStopped;
    comp->fmiBuffer.clockBuffer[2] = comp->modelData.gripperOpened;
    comp->fmiBuffer.clockBuffer[3] = comp->modelData.collision;
    comp->fmiBuffer.clockBuffer[4] = comp->modelData.closeGripperCommand;
    comp->fmiBuffer.clockBuffer[5] = comp->modelData.gripperClosed;
    comp->fmiBuffer.clockBuffer[6] = comp->modelData.nonfeasibleMoveDiscreteCommand;
    comp->fmiBuffer.clockBuffer[7] = comp->modelData.moveCompleted;
    comp->fmiBuffer.clockBuffer[8] = comp->modelData.openGripperCommand;
    comp->fmiBuffer.clockBuffer[9] = comp->modelData.moveDiscreteCommand;
    comp->fmiBuffer.int32Buffer[10] = comp->modelData.MovementArgs_target_X;
    comp->fmiBuffer.int32Buffer[11] = comp->modelData.MovementArgs_target_Y;
    comp->fmiBuffer.int32Buffer[12] = comp->modelData.MovementArgs_target_Z;
    comp->fmiBuffer.clockBuffer[13] = comp->modelData.movediscrete;
    comp->fmiBuffer.clockBuffer[14] = comp->modelData.pick;
    comp->fmiBuffer.clockBuffer[15] = comp->modelData.place;
    comp->fmiBuffer.int32Buffer[16] = comp->modelData.target_X;
    comp->fmiBuffer.int32Buffer[17] = comp->modelData.target_Y;
    comp->fmiBuffer.int32Buffer[18] = comp->modelData.target_Z;
    comp->fmiBuffer.float64Buffer[19] = comp->modelData.closing_diameter;
    comp->fmiBuffer.float64Buffer[20] = comp->modelData.closing_speed;
    comp->fmiBuffer.float64Buffer[21] = comp->modelData.closing_force;
    comp->fmiBuffer.float64Buffer[22] = comp->modelData.opening_diameter;
    comp->fmiBuffer.float64Buffer[23] = comp->modelData.opening_speed;
    comp->fmiBuffer.float64Buffer[24] = comp->modelData.opening_force;
    comp->fmiBuffer.clockBuffer[25] = comp->modelData.stop;
    comp->fmiBuffer.clockBuffer[26] = comp->modelData.movejoint;
    comp->fmiBuffer.float64Buffer[27] = comp->modelData.target_q0;
    comp->fmiBuffer.float64Buffer[28] = comp->modelData.target_q1;
    comp->fmiBuffer.float64Buffer[29] = comp->modelData.target_q2;
    comp->fmiBuffer.float64Buffer[30] = comp->modelData.target_q3;
    comp->fmiBuffer.float64Buffer[31] = comp->modelData.target_q4;
    comp->fmiBuffer.float64Buffer[32] = comp->modelData.target_q5;
    comp->fmiBuffer.clockBuffer[33] = comp->modelData.movecartesian;
    comp->fmiBuffer.float64Buffer[34] = comp->modelData.target_x;
    comp->fmiBuffer.float64Buffer[35] = comp->modelData.target_y;
    comp->fmiBuffer.float64Buffer[36] = comp->modelData.target_z;
    comp->fmiBuffer.float64Buffer[37] = comp->modelData.target_rx;
    comp->fmiBuffer.float64Buffer[38] = comp->modelData.target_ry;
    comp->fmiBuffer.float64Buffer[39] = comp->modelData.target_rz;
    comp->fmiBuffer.clockBuffer[40] = comp->modelData.setvelocity;
    comp->fmiBuffer.float64Buffer[41] = comp->modelData.target_v;
    comp->fmiBuffer.stringBuffer[42] = comp->modelData.state;
    comp->fmiBuffer.stringBuffer[43] = comp->modelData.target_state;
    comp->fmiBuffer.stringBuffer[44] = comp->modelData.status;
    comp->fmiBuffer.booleanBuffer[45] = comp->modelData.done;
}



/**
 * Function that performs a step of the simulation model.
 * At first the inputs of the are updated with the values fom the master algorithm.
 * Then the tick function is called inside the mutex, in order to guarantee mutual exlusion.
 * Finally the outputs of the model are forwarded to the master algorithm
 */
void doStep(ModelInstance* comp) {
    // Nothing happens in step mode in the dmodelFMU so far    
}

/**
 * Function that performs the execution of the updateDiscreteStates function of the simulation model.
 */
void updateDiscreteStates(ModelInstance* comp) {
    // Inputs and arguments
    comp->modelData.feasibleMoveDiscreteCommand = comp->fmiBuffer.clockBuffer[0];
    comp->modelData.robotStopped = comp->fmiBuffer.clockBuffer[1];
    comp->modelData.gripperOpened = comp->fmiBuffer.clockBuffer[2];
    comp->modelData.collision = comp->fmiBuffer.clockBuffer[3];
    comp->modelData.closeGripperCommand = comp->fmiBuffer.clockBuffer[4];
    comp->modelData.gripperClosed = comp->fmiBuffer.clockBuffer[5];
    comp->modelData.nonfeasibleMoveDiscreteCommand = comp->fmiBuffer.clockBuffer[6];
    comp->modelData.moveCompleted = comp->fmiBuffer.clockBuffer[7];
    comp->modelData.openGripperCommand = comp->fmiBuffer.clockBuffer[8];
    comp->modelData.moveDiscreteCommand = comp->fmiBuffer.clockBuffer[9];
    comp->modelData.MovementArgs_target_X = comp->fmiBuffer.int32Buffer[10];
    comp->modelData.MovementArgs_target_Y = comp->fmiBuffer.int32Buffer[11];
    comp->modelData.MovementArgs_target_Z = comp->fmiBuffer.int32Buffer[12];
    // updateDiscreteStates in the module
    tick(&comp->modelData);
    // Outputs
    comp->fmiBuffer.clockBuffer[13] = comp->modelData.movediscrete;
    comp->fmiBuffer.clockBuffer[14] = comp->modelData.pick;
    comp->fmiBuffer.clockBuffer[15] = comp->modelData.place;
    comp->fmiBuffer.int32Buffer[16] = comp->modelData.target_X;
    comp->fmiBuffer.int32Buffer[17] = comp->modelData.target_Y;
    comp->fmiBuffer.int32Buffer[18] = comp->modelData.target_Z;
    comp->fmiBuffer.float64Buffer[19] = comp->modelData.closing_diameter;
    comp->fmiBuffer.float64Buffer[20] = comp->modelData.closing_speed;
    comp->fmiBuffer.float64Buffer[21] = comp->modelData.closing_force;
    comp->fmiBuffer.float64Buffer[22] = comp->modelData.opening_diameter;
    comp->fmiBuffer.float64Buffer[23] = comp->modelData.opening_speed;
    comp->fmiBuffer.float64Buffer[24] = comp->modelData.opening_force;
    comp->fmiBuffer.clockBuffer[25] = comp->modelData.stop;
    comp->fmiBuffer.clockBuffer[26] = comp->modelData.movejoint;
    comp->fmiBuffer.float64Buffer[27] = comp->modelData.target_q0;
    comp->fmiBuffer.float64Buffer[28] = comp->modelData.target_q1;
    comp->fmiBuffer.float64Buffer[29] = comp->modelData.target_q2;
    comp->fmiBuffer.float64Buffer[30] = comp->modelData.target_q3;
    comp->fmiBuffer.float64Buffer[31] = comp->modelData.target_q4;
    comp->fmiBuffer.float64Buffer[32] = comp->modelData.target_q5;
    comp->fmiBuffer.clockBuffer[33] = comp->modelData.movecartesian;
    comp->fmiBuffer.float64Buffer[34] = comp->modelData.target_x;
    comp->fmiBuffer.float64Buffer[35] = comp->modelData.target_y;
    comp->fmiBuffer.float64Buffer[36] = comp->modelData.target_z;
    comp->fmiBuffer.float64Buffer[37] = comp->modelData.target_rx;
    comp->fmiBuffer.float64Buffer[38] = comp->modelData.target_ry;
    comp->fmiBuffer.float64Buffer[39] = comp->modelData.target_rz;
    comp->fmiBuffer.clockBuffer[40] = comp->modelData.setvelocity;
    comp->fmiBuffer.float64Buffer[41] = comp->modelData.target_v;
    comp->fmiBuffer.stringBuffer[42] = comp->modelData.state;
    comp->fmiBuffer.stringBuffer[43] = comp->modelData.target_state;
    comp->fmiBuffer.stringBuffer[44] = comp->modelData.status;
    comp->fmiBuffer.booleanBuffer[45] = comp->modelData.done;
}

/**
 * Function that terminates the simulation model.
 */
void terminate(ModelInstance* comp) {
    comp->terminateSimulation = true;
    comp->modelData.terminateSimulation = true;
    release();
}
