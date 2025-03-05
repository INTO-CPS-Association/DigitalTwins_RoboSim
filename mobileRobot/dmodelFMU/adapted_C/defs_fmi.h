#ifndef DEFSFMI
#define DEFSFMI
#include <stdio.h>
#include <stdbool.h>
/**** Update ****/
typedef struct {
	bool closestDistance;
	float closest_distance;
	bool closestAngle;
	float closest_angle;
	bool move;
	float lv;
	float av;
	char *state;
	char *target_state;
	char *status;
	bool done;
	bool terminateSimulation;
} ModelData;

void setStartValues(ModelData* comp);

//#define M(v) (comp->v)
#define M(v) (comp->v)

/**
 * init function
 */
void init(ModelData* comp);

/**
 * triggers
 */
/*bool per_tick(ModelData* comp);*/
ModelData* tick(ModelData* comp);

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



#endif
