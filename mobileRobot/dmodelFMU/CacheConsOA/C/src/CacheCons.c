
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
#include "aux.h"
#include "mod_CacheCons.h"
#include "ctrl_ref0.h"
#include "stm_ref1.h"
#include "stm_ref2.h"
#include "stm_ref5.h"
#include "interface.h"

typedef struct
{
	M_CacheCons_output_Enum_Channel *end_CacheCons;
	M_CacheCons_input_Enum_Channel *start_CacheCons;
} control_Channels;

typedef struct
{
	control_Channels *control_channels;
	pthread_t mod_CacheCons_thread_id;
	mod_CacheCons_thread_Channels *mod_CacheCons_thread_channels;
	pthread_t ctrl_ctrl_ref0_thread_id;
	ctrl_ctrl_ref0_thread_Channels *ctrl_ctrl_ref0_thread_channels;
	pthread_t stm_stm_ref1_id;
	pthread_t stm_stm_ref2_id;
	pthread_t stm_stm_ref5_id;
	stm_stm_ref1_Channels *stm_stm_ref1_channels;
	stm_stm_ref2_Channels *stm_stm_ref2_channels;
	stm_stm_ref5_Channels *stm_stm_ref5_channels;
} __Infrastructure__;

void __initialiseProgrammingEnvironment__()
{
}

void __initialiseConcurrencyInfrastructure__(__Infrastructure__ *state)
{
	log_file = fopen("test.log", "w");

	// Module channel declarations;;
	M_CacheCons_input_Enum_Channel *start_CacheCons = (M_CacheCons_input_Enum_Channel *)malloc(sizeof(M_CacheCons_input_Enum_Channel));
	pthread_barrier_init(&start_CacheCons->can_read, NULL, 2);
	pthread_barrier_init(&start_CacheCons->can_write, NULL, 2);
	M_CacheCons_output_Enum_Channel *end_CacheCons = (M_CacheCons_output_Enum_Channel *)malloc(sizeof(M_CacheCons_output_Enum_Channel));
	pthread_barrier_init(&end_CacheCons->can_read, NULL, 2);
	pthread_barrier_init(&end_CacheCons->can_write, NULL, 2);
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
	stm_ref5_input_Enum_Channel *start_stm_ref5 = (stm_ref5_input_Enum_Channel *)malloc(sizeof(stm_ref5_input_Enum_Channel));
	pthread_barrier_init(&start_stm_ref5->can_read, NULL, 2);
	pthread_barrier_init(&start_stm_ref5->can_write, NULL, 2);
	stm_ref5_output_Enum_Channel *end_stm_ref5 = (stm_ref5_output_Enum_Channel *)malloc(sizeof(stm_ref5_output_Enum_Channel));
	pthread_barrier_init(&end_stm_ref5->can_read, NULL, 2);
	pthread_barrier_init(&end_stm_ref5->can_write, NULL, 2);
	stm_ref2_input_Enum_Channel *start_stm_ref2 = (stm_ref2_input_Enum_Channel *)malloc(sizeof(stm_ref2_input_Enum_Channel));
	pthread_barrier_init(&start_stm_ref2->can_read, NULL, 2);
	pthread_barrier_init(&start_stm_ref2->can_write, NULL, 2);
	stm_ref2_output_Enum_Channel *end_stm_ref2 = (stm_ref2_output_Enum_Channel *)malloc(sizeof(stm_ref2_output_Enum_Channel));
	pthread_barrier_init(&end_stm_ref2->can_read, NULL, 2);
	pthread_barrier_init(&end_stm_ref2->can_write, NULL, 2);

	int status;

	state->control_channels = (control_Channels *)malloc(sizeof(control_Channels));

	state->control_channels->end_CacheCons = end_CacheCons;
	state->control_channels->start_CacheCons = start_CacheCons;

	state->mod_CacheCons_thread_channels = (mod_CacheCons_thread_Channels *)malloc(sizeof(mod_CacheCons_thread_Channels));

	state->mod_CacheCons_thread_channels->start_CacheCons = start_CacheCons;
	state->mod_CacheCons_thread_channels->end_ctrl_ref0 = end_ctrl_ref0;
	state->mod_CacheCons_thread_channels->end_CacheCons = end_CacheCons;
	state->mod_CacheCons_thread_channels->start_ctrl_ref0 = start_ctrl_ref0;

	status = pthread_create(&state->mod_CacheCons_thread_id, NULL, mod_CacheCons_thread, state->mod_CacheCons_thread_channels);
	if (status != 0)
		err_abort(status, "Create mod_CacheCons_thread thread");

	state->ctrl_ctrl_ref0_thread_channels = (ctrl_ctrl_ref0_thread_Channels *)malloc(sizeof(ctrl_ctrl_ref0_thread_Channels));

	state->ctrl_ctrl_ref0_thread_channels->start_ctrl_ref0 = start_ctrl_ref0;
	state->ctrl_ctrl_ref0_thread_channels->end_stm_ref5 = end_stm_ref5;
	state->ctrl_ctrl_ref0_thread_channels->end_stm_ref2 = end_stm_ref2;
	state->ctrl_ctrl_ref0_thread_channels->end_stm_ref1 = end_stm_ref1;
	state->ctrl_ctrl_ref0_thread_channels->end_ctrl_ref0 = end_ctrl_ref0;
	state->ctrl_ctrl_ref0_thread_channels->start_stm_ref5 = start_stm_ref5;
	state->ctrl_ctrl_ref0_thread_channels->start_stm_ref2 = start_stm_ref2;
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

	state->stm_stm_ref2_channels = (stm_stm_ref2_Channels *)malloc(sizeof(stm_stm_ref2_Channels));

	state->stm_stm_ref2_channels->start_stm_ref2 = start_stm_ref2;
	state->stm_stm_ref2_channels->end_stm_ref2 = end_stm_ref2;

	status = pthread_create(&state->stm_stm_ref2_id, NULL, stm_stm_ref2, state->stm_stm_ref2_channels);
	if (status != 0)
		err_abort(status, "Create stm_stm_ref2 thread");

	state->stm_stm_ref5_channels = (stm_stm_ref5_Channels *)malloc(sizeof(stm_stm_ref5_Channels));

	state->stm_stm_ref5_channels->start_stm_ref5 = start_stm_ref5;
	state->stm_stm_ref5_channels->end_stm_ref5 = end_stm_ref5;

	status = pthread_create(&state->stm_stm_ref5_id, NULL, stm_stm_ref5, state->stm_stm_ref5_channels);
	if (status != 0)
		err_abort(status, "Create stm_stm_ref5 thread");
	return;
}

void __clean__(__Infrastructure__ *state)
{
	int status = 0;

	status = pthread_join(state->mod_CacheCons_thread_id, NULL);
	if (status != 0)
		err_abort(status, "Join mod_CacheCons_thread thread");
	status = pthread_join(state->ctrl_ctrl_ref0_thread_id, NULL);
	if (status != 0)
		err_abort(status, "Join ctrl_ctrl_ref0_thread thread");
	status = pthread_join(state->stm_stm_ref1_id, NULL);
	if (status != 0)
		err_abort(status, "Join stm_stm_ref1 thread");
	status = pthread_join(state->stm_stm_ref2_id, NULL);
	if (status != 0)
		err_abort(status, "Join stm_stm_ref2 thread");
	status = pthread_join(state->stm_stm_ref5_id, NULL);
	if (status != 0)
		err_abort(status, "Join stm_stm_ref5 thread");

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
			M_CacheCons_input_Enum aux = read_input();
			if (aux.type == M_CacheCons_input__done_)
			{
				inputdone = true;
			}
			else if (aux.type == M_CacheCons_input__terminate_)
			{
				inputdone = true;
				terminate__ = true;
			}
			{
				pthread_barrier_wait(&state->control_channels->start_CacheCons->can_write);
				state->control_channels->start_CacheCons->value = aux;
				pthread_barrier_wait(&state->control_channels->start_CacheCons->can_read);
			}
		}
	}
	{
		bool outputdone = false;
		while (!outputdone)
		{
			// printf("Writing output\n");
			M_CacheCons_output_Enum _output_;
			{
				// printf("Waiting for output: can_write\n");
				pthread_barrier_wait(&state->control_channels->end_CacheCons->can_write);
				// printf("Waiting for output: can_read\n");
				pthread_barrier_wait(&state->control_channels->end_CacheCons->can_read);
				_output_ = state->control_channels->end_CacheCons->value;
				// printf("Output has been read\n");
			}
			write_output(_output_);
			if (_output_.type == M_CacheCons_output__done_)
			{
				outputdone = true;
				// printf("Done writing outputs\n");
			}
		}
	}
	return terminate__;
}

int main(int argc, char *argv[])
{
	if (argc <= 0)
	{
		fprintf(stderr, "error: Not enough arguments.");
		exit(1);
	}

	__Infrastructure__ *state = (__Infrastructure__ *)malloc(sizeof(__Infrastructure__));

	__initialiseProgrammingEnvironment__();
	__initialiseConcurrencyInfrastructure__(state);

	{
		bool terminate__ = false;
		int n = 1;
		while (!terminate__)
		{
			// printf("Start of cycle %d\n", n); n++;
			terminate__ = __step__(state);
			// printf("----------------------------\n");
		}
	}

	__clean__(state);

	return 0;
}