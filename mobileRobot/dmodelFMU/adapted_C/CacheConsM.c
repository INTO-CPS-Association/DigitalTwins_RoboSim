
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
#include <stdbool.h>
#include "defs.h"
#include "defs_fmi.h"
#include "aux.h"
#include "mod_CacheCons.h"
#include "ctrl_ref0.h"
#include "stm_ref1.h"
#include "interface.h"

// NEW

typedef struct
{
	M_CacheConsM_output_Enum_Channel *end_CacheConsM;
	M_CacheConsM_input_Enum_Channel *start_CacheConsM;
} control_Channels;

typedef struct
{
	control_Channels *control_channels;
	pthread_t mod_CacheConsM_thread_id;
	mod_CacheConsM_thread_Channels *mod_CacheConsM_thread_channels;
	pthread_t ctrl_ctrl_ref0_thread_id;
	ctrl_ctrl_ref0_thread_Channels *ctrl_ctrl_ref0_thread_channels;
	pthread_t stm_stm_ref1_id;
	stm_stm_ref1_Channels *stm_stm_ref1_channels;
} __Infrastructure__;

__Infrastructure__* state;

void __initialiseProgrammingEnvironment__()
{
}

void __initialiseConcurrencyInfrastructure__(__Infrastructure__ *state)
{
	log_file = fopen("test.log", "w");

	// Module channel declarations;;
	M_CacheConsM_input_Enum_Channel *start_CacheConsM = (M_CacheConsM_input_Enum_Channel *)malloc(sizeof(M_CacheConsM_input_Enum_Channel));
	pthread_barrier_init(&start_CacheConsM->can_read, NULL, 2);
	pthread_barrier_init(&start_CacheConsM->can_write, NULL, 2);
	M_CacheConsM_output_Enum_Channel *end_CacheConsM = (M_CacheConsM_output_Enum_Channel *)malloc(sizeof(M_CacheConsM_output_Enum_Channel));
	pthread_barrier_init(&end_CacheConsM->can_read, NULL, 2);
	pthread_barrier_init(&end_CacheConsM->can_write, NULL, 2);
	C_ctrl_ref0_input_Enum_Channel *start_ctrl_ref0 = (C_ctrl_ref0_input_Enum_Channel *)malloc(sizeof(C_ctrl_ref0_input_Enum_Channel));
	pthread_barrier_init(&start_ctrl_ref0->can_read, NULL, 2);
	pthread_barrier_init(&start_ctrl_ref0->can_write, NULL, 2);
	C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0 = (C_ctrl_ref0_output_Enum_Channel *)malloc(sizeof(C_ctrl_ref0_output_Enum_Channel));
	pthread_barrier_init(&end_ctrl_ref0->can_read, NULL, 2);
	pthread_barrier_init(&end_ctrl_ref0->can_write, NULL, 2);
	stm_ref1_input_Enum_Channel *start_stm_ref1 = (stm_ref1_input_Enum_Channel *)malloc(sizeof(stm_ref1_input_Enum_Channel));
	pthread_barrier_init(&start_stm_ref1->can_read, NULL, 2);
	pthread_barrier_init(&start_stm_ref1->can_write, NULL, 2);
	stm_ref1_output_Enum_Channel *end_stm_ref1 = (stm_ref1_output_Enum_Channel *)malloc(sizeof(stm_ref1_output_Enum_Channel));
	pthread_barrier_init(&end_stm_ref1->can_read, NULL, 2);
	pthread_barrier_init(&end_stm_ref1->can_write, NULL, 2);

	// Instantiate threads;;
	int status;

	state->control_channels = (control_Channels *)malloc(sizeof(control_Channels));

	state->control_channels->end_CacheConsM = end_CacheConsM;
	state->control_channels->start_CacheConsM = start_CacheConsM;

	state->mod_CacheConsM_thread_channels = (mod_CacheConsM_thread_Channels *)malloc(sizeof(mod_CacheConsM_thread_Channels));

	state->mod_CacheConsM_thread_channels->start_CacheConsM = start_CacheConsM;
	state->mod_CacheConsM_thread_channels->end_ctrl_ref0 = end_ctrl_ref0;
	state->mod_CacheConsM_thread_channels->end_CacheConsM = end_CacheConsM;
	state->mod_CacheConsM_thread_channels->start_ctrl_ref0 = start_ctrl_ref0;

	status = pthread_create(&state->mod_CacheConsM_thread_id, NULL, mod_CacheConsM_thread, state->mod_CacheConsM_thread_channels);
	if (status != 0)
		err_abort(status, "Create mod_CacheConsM_thread thread");

	state->ctrl_ctrl_ref0_thread_channels = (ctrl_ctrl_ref0_thread_Channels *)malloc(sizeof(ctrl_ctrl_ref0_thread_Channels));

	state->ctrl_ctrl_ref0_thread_channels->start_ctrl_ref0 = start_ctrl_ref0;
	state->ctrl_ctrl_ref0_thread_channels->end_stm_ref1 = end_stm_ref1;
	state->ctrl_ctrl_ref0_thread_channels->end_ctrl_ref0 = end_ctrl_ref0;
	state->ctrl_ctrl_ref0_thread_channels->start_stm_ref1 = start_stm_ref1;

	status = pthread_create(&state->ctrl_ctrl_ref0_thread_id, NULL, ctrl_ctrl_ref0_thread, state->ctrl_ctrl_ref0_thread_channels);
	if (status != 0)
		err_abort(status, "Create ctrl_ctrl_ref0_thread thread");

	state->stm_stm_ref1_channels = (stm_stm_ref1_Channels *)malloc(sizeof(stm_stm_ref1_Channels));

	state->stm_stm_ref1_channels->start_stm_ref1 = start_stm_ref1;
	state->stm_stm_ref1_channels->end_stm_ref1 = end_stm_ref1;

	status = pthread_create(&state->stm_stm_ref1_id, NULL, stm_stm_ref1, state->stm_stm_ref1_channels);
	if (status != 0)
		err_abort(status, "Create stm_stm_ref1 thread");
	return;
}

void __clean__(__Infrastructure__ *state)
{
	int status = 0;

	status = pthread_join(state->mod_CacheConsM_thread_id, NULL);
	if (status != 0)
		err_abort(status, "Join mod_CacheConsM_thread thread");
	status = pthread_join(state->ctrl_ctrl_ref0_thread_id, NULL);
	if (status != 0)
		err_abort(status, "Join ctrl_ctrl_ref0_thread thread");
	status = pthread_join(state->stm_stm_ref1_id, NULL);
	if (status != 0)
		err_abort(status, "Join stm_stm_ref1 thread");

	fclose(log_file);

	return;
}

bool __step__(__Infrastructure__ *state)
{
	bool terminate__ = false;
	{
		bool inputdone = false;
		while (!inputdone)
		{
			M_CacheConsM_input_Enum aux = read_input();
			if (aux.type == M_CacheConsM_input__done_)
			{
				inputdone = true;
			}
			else if (aux.type == M_CacheConsM_input__terminate_)
			{
				inputdone = true;
				terminate__ = true;
			}
			{
				pthread_barrier_wait(&state->control_channels->start_CacheConsM->can_write);
				state->control_channels->start_CacheConsM->value = aux;
				pthread_barrier_wait(&state->control_channels->start_CacheConsM->can_read);
			}
		}
	}
	{
		bool outputdone = false;
		while (!outputdone)
		{
			// printf("Writing output\n");
			M_CacheConsM_output_Enum _output_;
			{
				// printf("Waiting for output: can_write\n");
				pthread_barrier_wait(&state->control_channels->end_CacheConsM->can_write);
				// printf("Waiting for output: can_read\n");
				pthread_barrier_wait(&state->control_channels->end_CacheConsM->can_read);
				_output_ = state->control_channels->end_CacheConsM->value;
				// printf("Output has been read\n");
			}
			write_output(_output_);
			if (_output_.type == M_CacheConsM_output__done_)
			{
				outputdone = true;
				// printf("Done writing outputs\n");
			}
		}
	}
	return terminate__;
}

// int main(int argc, char *argv[])
// {
// 	if (argc <= 0)
// 	{
// 		fprintf(stderr, "error: Not enough arguments.");
// 		exit(1);
// 	}

// 	__Infrastructure__ *state = (__Infrastructure__ *)malloc(sizeof(__Infrastructure__));

// 	__initialiseProgrammingEnvironment__();
// 	__initialiseConcurrencyInfrastructure__(state);

// 	{
// 		bool terminate__ = false;
// 		int n = 1;
// 		while (!terminate__)
// 		{
// 			// printf("Start of cycle %d\n", n); n++;
// 			terminate__ = __step__(state);
// 			// printf("----------------------------\n");
// 		}
// 	}

// 	__clean__(state);

// 	return 0;
// }

void setStartValues(ModelData *comp) {
	comp->terminateSimulation = false;
	M(closestDistance) = true;
	M(closest_distance) = 0.0;
	M(closestAngle) = true;
	M(closest_angle) = 0.0;
	M(move) = false;
	M(lv) = 0.0;
	M(av) = 0.0;
	M(state) = "";
	M(target_state) = "";
	M(status) = "";
	M(done) = false;
}

/***** Init and tick functions (no need for changes) *****/
void init(ModelData* comp) { //Replace for the main function
	setStartValues(comp); // Optional
	printf("Initializing the RoboSim ... module\n");
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
printf("Terminating modules\n");
__clean__(state);
exit(0);
}