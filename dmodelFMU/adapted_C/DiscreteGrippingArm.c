#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <ctype.h>
#include "defs.h"
#include "defs_fmi.h"
#include "mod_DiscreteGrippingArm.h"
#include "ctrl_cm.h"
#include "stm_sm.h"
#include "aux.h"
#include "interface.h"

#define DEBUG

typedef struct {
	control_Channels* control_channels;
	pthread_t mod_DiscreteGrippingArm_thread_id;
	mod_DiscreteGrippingArm_thread_Channels* mod_DiscreteGrippingArm_thread_channels;
	pthread_t ctrl_cm_thread_id;
	ctrl_cm_thread_Channels* ctrl_cm_thread_channels;
	pthread_t stm_sm_id;
	stm_sm_Channels* stm_sm_channels;
} __Infrastructure__;

/***** Specific to FMI *****/
__Infrastructure__* state;

void __initialiseProgrammingEnvironment__() {
}

void __initialiseConcurrencyInfrastructure__(__Infrastructure__* state) {
	log_file = fopen("test.log", "w");

	// Module channel declarations;;
	M_DiscreteGrippingArm_input_Enum_Channel* start_DiscreteGrippingArm = (M_DiscreteGrippingArm_input_Enum_Channel*)malloc(sizeof(M_DiscreteGrippingArm_input_Enum_Channel));
	pthread_barrier_init(&start_DiscreteGrippingArm->can_read, NULL, 2);
	pthread_barrier_init(&start_DiscreteGrippingArm->can_write, NULL, 2);
	M_DiscreteGrippingArm_output_Enum_Channel* end_DiscreteGrippingArm = (M_DiscreteGrippingArm_output_Enum_Channel*)malloc(sizeof(M_DiscreteGrippingArm_output_Enum_Channel));
	pthread_barrier_init(&end_DiscreteGrippingArm->can_read, NULL, 2);
	pthread_barrier_init(&end_DiscreteGrippingArm->can_write, NULL, 2);
	C_cm_input_Enum_Channel* start_cm = (C_cm_input_Enum_Channel*)malloc(sizeof(C_cm_input_Enum_Channel));
	pthread_barrier_init(&start_cm->can_read, NULL, 2);
	pthread_barrier_init(&start_cm->can_write, NULL, 2);
	C_cm_output_Enum_Channel* end_cm = (C_cm_output_Enum_Channel*)malloc(sizeof(C_cm_output_Enum_Channel));
	pthread_barrier_init(&end_cm->can_read, NULL, 2);
	pthread_barrier_init(&end_cm->can_write, NULL, 2);
	sm_input_Enum_Channel* start_sm = (sm_input_Enum_Channel*)malloc(sizeof(sm_input_Enum_Channel));
	pthread_barrier_init(&start_sm->can_read, NULL, 2);
	pthread_barrier_init(&start_sm->can_write, NULL, 2);
	sm_output_Enum_Channel* end_sm = (sm_output_Enum_Channel*)malloc(sizeof(sm_output_Enum_Channel));
	pthread_barrier_init(&end_sm->can_read, NULL, 2);
	pthread_barrier_init(&end_sm->can_write, NULL, 2);
	// Instantiate threads;;
	int status;

	state->control_channels = (control_Channels*)malloc(sizeof(control_Channels));

	state->control_channels->end_DiscreteGrippingArm = end_DiscreteGrippingArm;
	state->control_channels->start_DiscreteGrippingArm = start_DiscreteGrippingArm;

	state->mod_DiscreteGrippingArm_thread_channels = (mod_DiscreteGrippingArm_thread_Channels*)malloc(sizeof(mod_DiscreteGrippingArm_thread_Channels));

	state->mod_DiscreteGrippingArm_thread_channels->start_DiscreteGrippingArm = start_DiscreteGrippingArm;
	state->mod_DiscreteGrippingArm_thread_channels->end_cm = end_cm;
	state->mod_DiscreteGrippingArm_thread_channels->end_DiscreteGrippingArm = end_DiscreteGrippingArm;
	state->mod_DiscreteGrippingArm_thread_channels->start_cm = start_cm;

	status = pthread_create(&state->mod_DiscreteGrippingArm_thread_id, NULL, mod_DiscreteGrippingArm_thread, state->mod_DiscreteGrippingArm_thread_channels);
	if (status != 0)
			err_abort(status, "Create mod_DiscreteGrippingArm_thread thread");

	state->ctrl_cm_thread_channels = (ctrl_cm_thread_Channels*)malloc(sizeof(ctrl_cm_thread_Channels));

	state->ctrl_cm_thread_channels->start_cm = start_cm;
	state->ctrl_cm_thread_channels->end_sm = end_sm;
	state->ctrl_cm_thread_channels->end_cm = end_cm;
	state->ctrl_cm_thread_channels->start_sm = start_sm;

	status = pthread_create(&state->ctrl_cm_thread_id, NULL, ctrl_cm_thread, state->ctrl_cm_thread_channels);
	if (status != 0)
			err_abort(status, "Create ctrl_cm_thread thread");

	state->stm_sm_channels = (stm_sm_Channels*)malloc(sizeof(stm_sm_Channels));

	state->stm_sm_channels->start_sm = start_sm;
	state->stm_sm_channels->end_sm = end_sm;

	status = pthread_create(&state->stm_sm_id, NULL, stm_sm, state->stm_sm_channels);
	if (status != 0)
			err_abort(status, "Create stm_sm thread");
	return;
}

void __clean__(__Infrastructure__* state) {
	int status = 0;
	status = pthread_join(state->mod_DiscreteGrippingArm_thread_id, NULL);
	if (status != 0)
			err_abort(status, "Join mod_DiscreteGrippingArm_thread thread");
	status = pthread_join(state->ctrl_cm_thread_id, NULL);
	if (status != 0)
			err_abort(status, "Join ctrl_cm_thread thread");
	status = pthread_join(state->stm_sm_id, NULL);
	if (status != 0)
			err_abort(status, "Join stm_sm thread");

	fclose(log_file);

	return;
}

bool __step__(__Infrastructure__* state) {
	bool terminate__ = false;
	{
		bool inputdone = false;
		while (!inputdone) {
			M_DiscreteGrippingArm_input_Enum aux = read_input();
			if (aux.type == M_DiscreteGrippingArm_input__done_) {
				inputdone = true;
			}
			else if (aux.type == M_DiscreteGrippingArm_input__terminate_) {
				inputdone = true;
				terminate__ = true;
			}
			{
				pthread_barrier_wait(&state->control_channels->start_DiscreteGrippingArm->can_write);
				state->control_channels->start_DiscreteGrippingArm->value = aux;
				pthread_barrier_wait(&state->control_channels->start_DiscreteGrippingArm->can_read);
			}
		}
	}
	{
		bool outputdone = false;
		while (!outputdone) {
			M_DiscreteGrippingArm_output_Enum _output_;
			{
				pthread_barrier_wait(&state->control_channels->end_DiscreteGrippingArm->can_write);
				pthread_barrier_wait(&state->control_channels->end_DiscreteGrippingArm->can_read);
				_output_ = state->control_channels->end_DiscreteGrippingArm->value;
			}
			write_output(_output_);
			if (_output_.type == M_DiscreteGrippingArm_output__done_) {
				outputdone = true;
			}
			
		}
	}
	return terminate__;
}



int main(int argc, char* argv[]) {
    if (argc  <= 0) {
        fprintf(stderr, "error: Not enough arguments.");
        exit(1);
    }
	return 0;
}

// Additional Functions

/***** Specific to FMI *****/
void setStartValues(ModelData *comp) {
	comp->terminateSimulation = false;
	M(feasibleMoveDiscreteCommand) = false;
	M(robotStopped) = false;
	M(gripperOpened) = false;
	M(collision) = false;
	M(closeGripperCommand) = false;
	M(gripperClosed) = false;
	M(nonfeasibleMoveDiscreteCommand) = false;
	M(moveCompleted) = false;
	M(openGripperCommand) = false;
	M(moveDiscreteCommand) = false;
	M(MovementArgs_target_X) = 0;
	M(MovementArgs_target_Y) = 0;
	M(MovementArgs_target_Z) = 0;
	M(movediscrete) = false;
	M(pick) = false;
	M(place) = false;
	M(target_X) = 0;
	M(target_Y) = 0;
	M(target_Z) = 0;
	M(closing_diameter) = 0.0;
	M(closing_speed) = 0.0;
	M(closing_force) = 0.0;
	M(opening_diameter) = 0.0;
	M(opening_speed) = 0.0;
	M(opening_force) = 0.0;
	M(stop) = false;
	M(movejoint) = false;
	M(target_q0) = 0.0;
	M(target_q1) = 0.0;
	M(target_q2) = 0.0;
	M(target_q3) = 0.0;
	M(target_q4) = 0.0;
	M(target_q5) = 0.0;
	M(movecartesian) = false;
	M(target_x) = 0.0;
	M(target_y) = 0.0;
	M(target_z) = 0.0;
	M(target_rx) = 0.0;
	M(target_ry) = 0.0;
	M(target_rz) = 0.0;
	M(setvelocity) = false;
	M(target_v) = 0.0;
	M(state) = "";
	M(target_state) = "";
	M(status) = "";
	M(done) = false;
}


/***** *****/

void init(ModelData* comp) { //Replace for the main function
		setStartValues(comp);
		update_fmi_data(comp);
		state = (__Infrastructure__*)malloc(sizeof(__Infrastructure__));

		__initialiseProgrammingEnvironment__();
		__initialiseConcurrencyInfrastructure__(state);

}

ModelData* tick(ModelData* comp){
	update_fmi_data(comp);
	{
		bool terminate__ = false;
		if ((!comp->terminateSimulation) || (!terminate__)) {
			terminate__ = __step__(state);
		}
	}
	return comp;
}

void release(){
	//__clean__(state);
	exit(0);
}