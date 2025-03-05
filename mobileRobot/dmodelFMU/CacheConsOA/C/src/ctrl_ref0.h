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
#include "stm_ref2.h"
#include "stm_ref5.h"

typedef struct
{
	pthread_barrier_t can_write, can_read;
	C_ctrl_ref0_output_Enum value;
} C_ctrl_ref0_output_Enum_Channel;
typedef struct
{
	pthread_barrier_t can_write, can_read;
	C_ctrl_ref0_input_Enum value;
} C_ctrl_ref0_input_Enum_Channel;

typedef struct
{
	C_ctrl_ref0_input_Enum_Channel *start_ctrl_ref0;
	stm_ref5_output_Enum_Channel *end_stm_ref5;
	stm_ref2_output_Enum_Channel *end_stm_ref2;
	stm_ref1_output_Enum_Channel *end_stm_ref1;
	C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0;
	stm_ref5_input_Enum_Channel *start_stm_ref5;
	stm_ref2_input_Enum_Channel *start_stm_ref2;
	stm_ref1_input_Enum_Channel *start_stm_ref1;
} ctrl_ctrl_ref0_thread_Channels;

void ctrl_ctrl_ref0_step(stm_ref5_input_Enum_Channel *start_stm_ref5, stm_ref5_output_Enum_Channel *end_stm_ref5, stm_ref2_input_Enum_Channel *start_stm_ref2, stm_ref2_output_Enum_Channel *end_stm_ref2, stm_ref1_input_Enum_Channel *start_stm_ref1, stm_ref1_output_Enum_Channel *end_stm_ref1)
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
	stm_ref5_output_Enum_Channel *end_stm_ref5 = channels->end_stm_ref5;
	stm_ref2_output_Enum_Channel *end_stm_ref2 = channels->end_stm_ref2;
	stm_ref1_output_Enum_Channel *end_stm_ref1 = channels->end_stm_ref1;
	C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0 = channels->end_ctrl_ref0;
	stm_ref5_input_Enum_Channel *start_stm_ref5 = channels->start_stm_ref5;
	stm_ref2_input_Enum_Channel *start_stm_ref2 = channels->start_stm_ref2;
	stm_ref1_input_Enum_Channel *start_stm_ref1 = channels->start_stm_ref1;
	{
		bool terminate__ = false;
		struct
		{
			stm_ref5_input_Enum items[MAX_SEQ_SIZE];
			int start;
			int end;
		} stm_stm_ref5_queue;
		stm_stm_ref5_queue.start = -1;
		stm_stm_ref5_queue.end = -1;

		stm_ref5_input_Enum stm_stm_ref5_queue_Dequeue()
		{
			if (stm_stm_ref5_queue.start == -1)
			{
				printf("ERROR: trying to dequeue value from an empty queue.\n");
				return create_stm_ref5_input__terminate_();
			}
			else
			{
				stm_ref5_input_Enum value = stm_stm_ref5_queue.items[stm_stm_ref5_queue.start];
				if (stm_stm_ref5_queue.start == stm_stm_ref5_queue.end)
				{
					stm_stm_ref5_queue.start = stm_stm_ref5_queue.end = -1;
				}
				else
				{
					stm_stm_ref5_queue.start = (stm_stm_ref5_queue.start + 1) % MAX_SEQ_SIZE;
				}
				return value;
			}
		}

		void stm_stm_ref5_queue_Enqueue(stm_ref5_input_Enum value)
		{
			if (stm_stm_ref5_queue.start == (stm_stm_ref5_queue.end + 1) % MAXQUEUE)
			{
				printf("ERROR: trying to enqueue a value on a full queue.\n");
				return;
			}

			if (stm_stm_ref5_queue.start == -1)
			{
				stm_stm_ref5_queue.start = 0;
			}
			stm_stm_ref5_queue.end = (stm_stm_ref5_queue.end + 1) % MAXQUEUE;
			stm_stm_ref5_queue.items[stm_stm_ref5_queue.end] = value;
		}

		bool stm_stm_ref5_queue_isEmpty()
		{
			return stm_stm_ref5_queue.start == -1;
		}

		void stm_stm_ref5_queue_Clear()
		{
			stm_stm_ref5_queue.start = -1;
			stm_stm_ref5_queue.end = -1;
		}
		struct
		{
			stm_ref2_input_Enum items[MAX_SEQ_SIZE];
			int start;
			int end;
		} stm_stm_ref2_queue;
		stm_stm_ref2_queue.start = -1;
		stm_stm_ref2_queue.end = -1;

		stm_ref2_input_Enum stm_stm_ref2_queue_Dequeue()
		{
			if (stm_stm_ref2_queue.start == -1)
			{
				printf("ERROR: trying to dequeue value from an empty queue.\n");
				return create_stm_ref2_input__terminate_();
			}
			else
			{
				stm_ref2_input_Enum value = stm_stm_ref2_queue.items[stm_stm_ref2_queue.start];
				if (stm_stm_ref2_queue.start == stm_stm_ref2_queue.end)
				{
					stm_stm_ref2_queue.start = stm_stm_ref2_queue.end = -1;
				}
				else
				{
					stm_stm_ref2_queue.start = (stm_stm_ref2_queue.start + 1) % MAX_SEQ_SIZE;
				}
				return value;
			}
		}

		void stm_stm_ref2_queue_Enqueue(stm_ref2_input_Enum value)
		{
			if (stm_stm_ref2_queue.start == (stm_stm_ref2_queue.end + 1) % MAXQUEUE)
			{
				printf("ERROR: trying to enqueue a value on a full queue.\n");
				return;
			}

			if (stm_stm_ref2_queue.start == -1)
			{
				stm_stm_ref2_queue.start = 0;
			}
			stm_stm_ref2_queue.end = (stm_stm_ref2_queue.end + 1) % MAXQUEUE;
			stm_stm_ref2_queue.items[stm_stm_ref2_queue.end] = value;
		}

		bool stm_stm_ref2_queue_isEmpty()
		{
			return stm_stm_ref2_queue.start == -1;
		}

		void stm_stm_ref2_queue_Clear()
		{
			stm_stm_ref2_queue.start = -1;
			stm_stm_ref2_queue.end = -1;
		}
		struct
		{
			stm_ref1_input_Enum items[MAX_SEQ_SIZE];
			int start;
			int end;
		} stm_stm_ref1_queue;
		stm_stm_ref1_queue.start = -1;
		stm_stm_ref1_queue.end = -1;

		stm_ref1_input_Enum stm_stm_ref1_queue_Dequeue()
		{
			if (stm_stm_ref1_queue.start == -1)
			{
				printf("ERROR: trying to dequeue value from an empty queue.\n");
				return create_stm_ref1_input__terminate_();
			}
			else
			{
				stm_ref1_input_Enum value = stm_stm_ref1_queue.items[stm_stm_ref1_queue.start];
				if (stm_stm_ref1_queue.start == stm_stm_ref1_queue.end)
				{
					stm_stm_ref1_queue.start = stm_stm_ref1_queue.end = -1;
				}
				else
				{
					stm_stm_ref1_queue.start = (stm_stm_ref1_queue.start + 1) % MAX_SEQ_SIZE;
				}
				return value;
			}
		}

		void stm_stm_ref1_queue_Enqueue(stm_ref1_input_Enum value)
		{
			if (stm_stm_ref1_queue.start == (stm_stm_ref1_queue.end + 1) % MAXQUEUE)
			{
				printf("ERROR: trying to enqueue a value on a full queue.\n");
				return;
			}

			if (stm_stm_ref1_queue.start == -1)
			{
				stm_stm_ref1_queue.start = 0;
			}
			stm_stm_ref1_queue.end = (stm_stm_ref1_queue.end + 1) % MAXQUEUE;
			stm_stm_ref1_queue.items[stm_stm_ref1_queue.end] = value;
		}

		bool stm_stm_ref1_queue_isEmpty()
		{
			return stm_stm_ref1_queue.start == -1;
		}

		void stm_stm_ref1_queue_Clear()
		{
			stm_stm_ref1_queue.start = -1;
			stm_stm_ref1_queue.end = -1;
		}
		while (!terminate__)
		{
			while (!stm_stm_ref5_queue_isEmpty())
			{
				stm_ref5_input_Enum ev = stm_stm_ref5_queue_Dequeue();
				{
					pthread_barrier_wait(&start_stm_ref5->can_write);
					start_stm_ref5->value = ev;
					pthread_barrier_wait(&start_stm_ref5->can_read);
				}
			}
			while (!stm_stm_ref2_queue_isEmpty())
			{
				stm_ref2_input_Enum ev = stm_stm_ref2_queue_Dequeue();
				{
					pthread_barrier_wait(&start_stm_ref2->can_write);
					start_stm_ref2->value = ev;
					pthread_barrier_wait(&start_stm_ref2->can_read);
				}
			}
			while (!stm_stm_ref1_queue_isEmpty())
			{
				stm_ref1_input_Enum ev = stm_stm_ref1_queue_Dequeue();
				{
					pthread_barrier_wait(&start_stm_ref1->can_write);
					start_stm_ref1->value = ev;
					pthread_barrier_wait(&start_stm_ref1->can_read);
				}
			}
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
					if (_input_.type == C_ctrl_ref0_input_DisableClusterWatch)
					{
						{
							pthread_barrier_wait(&start_stm_ref5->can_write);
							start_stm_ref5->value = create_stm_ref5_input_DisableClusterWatch();
							pthread_barrier_wait(&start_stm_ref5->can_read);
						}
					}
					else if (_input_.type == C_ctrl_ref0_input_closestAngle)
					{
						float _aux1_ = _input_.data.closestAngle.v1;
						{
							pthread_barrier_wait(&start_stm_ref2->can_write);
							start_stm_ref2->value = create_stm_ref2_input_closestAngle(_aux1_);
							pthread_barrier_wait(&start_stm_ref2->can_read);
						}
					}
					else if (_input_.type == C_ctrl_ref0_input_EnableVHF)
					{
						{
							pthread_barrier_wait(&start_stm_ref2->can_write);
							start_stm_ref2->value = create_stm_ref2_input_EnableVHF();
							pthread_barrier_wait(&start_stm_ref2->can_read);
						}
					}
					else if (_input_.type == C_ctrl_ref0_input_CCMove)
					{
						float _aux1_[2];
						_aux1_[0] = _input_.data.CCMove.v1[0];
						_aux1_[1] = _input_.data.CCMove.v1[1];
						{
							pthread_barrier_wait(&start_stm_ref1->can_write);
							start_stm_ref1->value = create_stm_ref1_input_CCMove(_aux1_);
							pthread_barrier_wait(&start_stm_ref1->can_read);
						}
					}
					else if (_input_.type == C_ctrl_ref0_input_EnableClusterWatch)
					{
						{
							pthread_barrier_wait(&start_stm_ref5->can_write);
							start_stm_ref5->value = create_stm_ref5_input_EnableClusterWatch();
							pthread_barrier_wait(&start_stm_ref5->can_read);
						}
					}
					else if (_input_.type == C_ctrl_ref0_input_closestDistance)
					{
						float _aux1_ = _input_.data.closestDistance.v1;
						{
							pthread_barrier_wait(&start_stm_ref2->can_write);
							start_stm_ref2->value = create_stm_ref2_input_closestDistance(_aux1_);
							pthread_barrier_wait(&start_stm_ref2->can_read);
						}
					}
					else if (_input_.type == C_ctrl_ref0_input_DisableVHF)
					{
						{
							pthread_barrier_wait(&start_stm_ref2->can_write);
							start_stm_ref2->value = create_stm_ref2_input_DisableVHF();
							pthread_barrier_wait(&start_stm_ref2->can_read);
						}
					}
					else if (_input_.type == C_ctrl_ref0_input__done_)
					{
						{
							pthread_barrier_wait(&start_stm_ref1->can_write);
							start_stm_ref1->value = create_stm_ref1_input__done_();
							pthread_barrier_wait(&start_stm_ref1->can_read);
						}
						{
							pthread_barrier_wait(&start_stm_ref5->can_write);
							start_stm_ref5->value = create_stm_ref5_input__done_();
							pthread_barrier_wait(&start_stm_ref5->can_read);
						}
						{
							pthread_barrier_wait(&start_stm_ref2->can_write);
							start_stm_ref2->value = create_stm_ref2_input__done_();
							pthread_barrier_wait(&start_stm_ref2->can_read);
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
						{
							pthread_barrier_wait(&start_stm_ref5->can_write);
							start_stm_ref5->value = create_stm_ref5_input__terminate_();
							pthread_barrier_wait(&start_stm_ref5->can_read);
						}
						{
							pthread_barrier_wait(&start_stm_ref2->can_write);
							start_stm_ref2->value = create_stm_ref2_input__terminate_();
							pthread_barrier_wait(&start_stm_ref2->can_read);
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
			ctrl_ctrl_ref0_step(start_stm_ref5, end_stm_ref5, start_stm_ref2, end_stm_ref2, start_stm_ref1, end_stm_ref1);
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
						float _aux1_[2];
						_aux1_[0] = _output_.data._move.v1[0];
						_aux1_[1] = _output_.data._move.v1[1];
						{
							pthread_barrier_wait(&end_ctrl_ref0->can_write);
							end_ctrl_ref0->value = create_C_ctrl_ref0_output__move(_aux1_);
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
				bool outputDone = false;
				while (!outputDone)
				{
					stm_ref5_output_Enum _output_;
					{
						pthread_barrier_wait(&end_stm_ref5->can_write);
						pthread_barrier_wait(&end_stm_ref5->can_read);
						_output_ = end_stm_ref5->value;
					}
					if (_output_.type == stm_ref5_output_RWMove)
					{
						float _aux1_[2];
						_aux1_[0] = _output_.data.RWMove.v1[0];
						_aux1_[1] = _output_.data.RWMove.v1[1];
						stm_stm_ref1_queue_Enqueue(create_stm_ref1_input_RWMove(_aux1_));
					}
					else if (_output_.type == stm_ref5_output__done_)
					{
						outputDone = true;
					}
				}
			}
			{
				bool outputDone = false;
				while (!outputDone)
				{
					stm_ref2_output_Enum _output_;
					{
						pthread_barrier_wait(&end_stm_ref2->can_write);
						pthread_barrier_wait(&end_stm_ref2->can_read);
						_output_ = end_stm_ref2->value;
					}
					if (_output_.type == stm_ref2_output_Avoiding)
					{
						bool _aux1_ = _output_.data.Avoiding.v1;
						stm_stm_ref1_queue_Enqueue(create_stm_ref1_input_Avoiding(_aux1_));
					}
					else if (_output_.type == stm_ref2_output_OAMove)
					{
						float _aux1_[2];
						_aux1_[0] = _output_.data.OAMove.v1[0];
						_aux1_[1] = _output_.data.OAMove.v1[1];
						stm_stm_ref1_queue_Enqueue(create_stm_ref1_input_OAMove(_aux1_));
					}
					else if (_output_.type == stm_ref2_output__done_)
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