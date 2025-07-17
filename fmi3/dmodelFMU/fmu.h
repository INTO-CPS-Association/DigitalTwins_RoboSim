#ifndef DEFSFMI
#define DEFSFMI
#include "fmi3/fmi3Functions.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

/**** Update ****/
typedef struct {
	bool feasibleMoveDiscreteCommand;
	bool robotStopped;
	bool gripperOpened;
	bool collision;
	bool closeGripperCommand;
	bool gripperClosed;
	bool nonfeasibleMoveDiscreteCommand;
	bool moveCompleted;
	bool openGripperCommand;
	bool moveDiscreteCommand;
	int MovementArgs_target_X;
	int MovementArgs_target_Y;
	int MovementArgs_target_Z;
	bool movediscrete;
	bool pick;
	bool place;
	int target_X;
	int target_Y;
	int target_Z;
	double closing_diameter;
	double closing_speed;
	double closing_force;
	double opening_diameter;
	double opening_speed;
	double opening_force;
	bool stop;
	bool movejoint;
	double target_q0;
	double target_q1;
	double target_q2;
	double target_q3;
	double target_q4;
	double target_q5;
	bool movecartesian;
	double target_x;
	double target_y;
	double target_z;
	double target_rx;
	double target_ry;
	double target_rz;
	bool setvelocity;
	double target_v;
	char *state;
	char *target_state;
	char *status;
	bool done;
	bool terminateSimulation;
} ModelData;

typedef enum {
    FMIStartAndEndState         = 1 << 0,
    FMIInstantiatedState        = 1 << 1,
    FMIInitializationModeState  = 1 << 2,
    FMITerminatedState          = 1 << 3,
    FMIConfigurationModeState   = 1 << 4,
    FMIReconfigurationModeState = 1 << 5,
    FMIEventModeState           = 1 << 6,
    FMIContinuousTimeModeState  = 1 << 7,
    FMIStepModeState            = 1 << 8,
    FMIClockActivationMode      = 1 << 9
} FMIState;

#define BOOL_COUNT 50
#define INT32_COUNT 50
#define FLOAT64_COUNT 50
#define STRING_COUNT 50
#define CLOCK_COUNT 50
#define FMI_COSIMULATION

typedef struct {
     fmi3Boolean booleanBuffer[BOOL_COUNT];
     fmi3Int32 int32Buffer[INT32_COUNT];
     fmi3Float64 float64Buffer[FLOAT64_COUNT];
     fmi3String stringBuffer[STRING_COUNT];
	 fmi3Clock clockBuffer[CLOCK_COUNT];
} FmiBuffer;

typedef struct {
	
	const char* instanceName;
	fmi3LogMessageCallback logMessage;
	bool eventModeUsed;    
	void* componentEnvironment;
	// add other config attributes if needed

	/* Specific to the framework */
	FMIState fmiState;
	FmiBuffer fmiBuffer;
	bool terminateSimulation;
    ModelData modelData;	
} ModelInstance;


void setStartValues(ModelData* comp);

#define M(v) (comp->v)

/**
 * init function
 */
void init(ModelData* comp);

/**
 * triggers
 */
 ModelData* tick(ModelData* comp);

 ModelData* step(ModelData* comp);

/**
 * leave/enter functions (Unused)
 */
void enter(ModelData* comp);
void leave(ModelData* comp);


/*
* Function to free memory when terminating
*/
void release();
/**** ****/

/*
* Functions for skeleton.c
*/
void initialize(ModelInstance*);
void doStep(ModelInstance*);
void updateDiscreteStates(ModelInstance*);
void terminate(ModelInstance*);


#endif
