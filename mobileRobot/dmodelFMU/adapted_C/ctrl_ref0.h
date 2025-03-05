/*
	This file contains function definitions derived from the state machine ref1.
*/

#ifndef CTRL_REF0__H
#define CTRL_REF0__H
#define _POSIX_C_SOURCE 200112L

#include "defs.h"
#include "aux.h"
#include <threads.h>
#include <stdio.h>
#include "conf.h"
#include "stm_ref1.h"

// NEW

typedef struct
{
	pthread_barrier_t can_write, can_read;
	C_ctrl_ref0_input_Enum value;
} C_ctrl_ref0_input_Enum_Channel;

typedef struct
{
	pthread_barrier_t can_write, can_read;
	C_ctrl_ref0_output_Enum value;
} C_ctrl_ref0_output_Enum_Channel;

typedef struct
{
	C_ctrl_ref0_input_Enum_Channel *start_ctrl_ref0;
	stm_ref1_output_Enum_Channel *end_stm_ref1;
	C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0;
	stm_ref1_input_Enum_Channel *start_stm_ref1;
} ctrl_ctrl_ref0_thread_Channels;

void ctrl_ctrl_ref0_step(stm_ref1_input_Enum_Channel *start_stm_ref1, stm_ref1_output_Enum_Channel *end_stm_ref1)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "	Started step of controller ctrl_ref0");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
}

void *ctrl_ctrl_ref0_thread(void *arg)
{
	ctrl_ctrl_ref0_thread_Channels *channels = (ctrl_ctrl_ref0_thread_Channels *)arg;
	C_ctrl_ref0_input_Enum_Channel *start_ctrl_ref0 = channels->start_ctrl_ref0;
	stm_ref1_output_Enum_Channel *end_stm_ref1 = channels->end_stm_ref1;
	C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0 = channels->end_ctrl_ref0;
	stm_ref1_input_Enum_Channel *start_stm_ref1 = channels->start_stm_ref1;
	{
		bool terminate__ = false;
		while (!terminate__)
		{
			{
				bool inputDone = false;
				while (!inputDone)
				{
					{
						char _s0[256];
						sprintf(_s0, "%s", "- Waiting for input on channel start_ctrl_ref0");
						fprintf(log_file, "DEBUG: %s\n", _s0);
					}
					C_ctrl_ref0_input_Enum _input_;
					{
						pthread_barrier_wait(&start_ctrl_ref0->can_write);
						pthread_barrier_wait(&start_ctrl_ref0->can_read);
						_input_ = start_ctrl_ref0->value;
					}
					{
						char _s0[256];
						sprintf(_s0, "%s", "- Read input on channel start_ctrl_ref0");
						fprintf(log_file, "DEBUG: %s\n", _s0);
					}
					if (_input_.type == C_ctrl_ref0_input_closestDistance)
					{
						float _aux1_ = _input_.data.closestDistance.v1;
						{
							pthread_barrier_wait(&start_stm_ref1->can_write);
							start_stm_ref1->value = create_stm_ref1_input_closestDistance(_aux1_);
							pthread_barrier_wait(&start_stm_ref1->can_read);
						}
					}
					else if (_input_.type == C_ctrl_ref0_input_closestAngle)
					{
						float _aux1_ = _input_.data.closestAngle.v1;
						{
							pthread_barrier_wait(&start_stm_ref1->can_write);
							start_stm_ref1->value = create_stm_ref1_input_closestAngle(_aux1_);
							pthread_barrier_wait(&start_stm_ref1->can_read);
						}
					}
					else if (_input_.type == C_ctrl_ref0_input__done_)
					{
						{
							pthread_barrier_wait(&start_stm_ref1->can_write);
							start_stm_ref1->value = create_stm_ref1_input__done_();
							pthread_barrier_wait(&start_stm_ref1->can_read);
						}
						inputDone = true;
					}
					else if (_input_.type == C_ctrl_ref0_input__terminate_)
					{
						{
							pthread_barrier_wait(&start_stm_ref1->can_write);
							start_stm_ref1->value = create_stm_ref1_input__terminate_();
							pthread_barrier_wait(&start_stm_ref1->can_read);
						}
						terminate__ = true;
					}
				}
			}
			{
				char _s0[256];
				sprintf(_s0, "%s", "	Finished reading inputs of controller ctrl_ref0");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			ctrl_ctrl_ref0_step(start_stm_ref1, end_stm_ref1);
			{
				bool outputDone = false;
				while (!outputDone)
				{
					stm_ref1_output_Enum _output_;
					{
						pthread_barrier_wait(&end_stm_ref1->can_write);
						pthread_barrier_wait(&end_stm_ref1->can_read);
						_output_ = end_stm_ref1->value;
					}
					if (_output_.type == stm_ref1_output__move)
					{
						float _aux1_ = _output_.data._move.v1;
						float _aux2_ = _output_.data._move.v2;
						{
							pthread_barrier_wait(&end_ctrl_ref0->can_write);
							end_ctrl_ref0->value = create_C_ctrl_ref0_output__move(_aux1_, _aux2_);
							pthread_barrier_wait(&end_ctrl_ref0->can_read);
						}
					}
					else if (_output_.type == stm_ref1_output__done_)
					{
						outputDone = true;
					}
				}
			}
			{
				pthread_barrier_wait(&end_ctrl_ref0->can_write);
				end_ctrl_ref0->value = create_C_ctrl_ref0_output__done_();
				pthread_barrier_wait(&end_ctrl_ref0->can_read);
			}
		}
	}
}

#endif