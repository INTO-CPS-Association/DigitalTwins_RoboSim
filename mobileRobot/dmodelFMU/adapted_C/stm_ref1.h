/*
	This file contains function definitions derived from the state machine ref1.
*/

#ifndef STM_REF1__H
#define STM_REF1__H
#define _POSIX_C_SOURCE 200112L

#include "defs.h"
#include "aux.h"
#include <threads.h>
#include <stdio.h>

/* Representation of record stm_ref1_Wander_state */
typedef struct
{
	bool done;
	STATES_stm_ref1_Wander_Enum state;
	STATES_stm_ref1_Wander_Enum target_state;
	STATUS_Enum status;
	bool en_Wander_Turn_1_done;
	int en_Wander_Turn_1_counter;
	bool en_Wander_Move_Forward_1_done;
	int en_Wander_Move_Forward_1_counter;
	bool tr_ObstacleAvoidance_Wander_t3_done;
	int tr_ObstacleAvoidance_Wander_t3_counter;
	bool tr_ObstacleAvoidance_Wander_t4_done;
	int tr_ObstacleAvoidance_Wander_t4_counter;
	bool tr_ObstacleAvoidance_Wander_t1_done;
	int tr_ObstacleAvoidance_Wander_t1_counter;
	bool tr_ObstacleAvoidance_Wander_t2_done;
	int tr_ObstacleAvoidance_Wander_t2_counter;
} stm_ref1_Wander_state;
/* Representation of record stm_ref1_OA_state */
typedef struct
{
	bool done;
	STATES_stm_ref1_OA_Enum state;
	STATES_stm_ref1_OA_Enum target_state;
	STATUS_Enum status;
	bool tr_ObstacleAvoidance_OA_t12_done;
	int tr_ObstacleAvoidance_OA_t12_counter;
	bool tr_ObstacleAvoidance_OA_t0_done;
	int tr_ObstacleAvoidance_OA_t0_counter;
	bool tr_ObstacleAvoidance_OA_t3_done;
	int tr_ObstacleAvoidance_OA_t3_counter;
	bool tr_ObstacleAvoidance_OA_t13_done;
	int tr_ObstacleAvoidance_OA_t13_counter;
	bool tr_ObstacleAvoidance_OA_t6_done;
	int tr_ObstacleAvoidance_OA_t6_counter;
	bool tr_ObstacleAvoidance_OA_t4_done;
	int tr_ObstacleAvoidance_OA_t4_counter;
	bool tr_ObstacleAvoidance_OA_t11_done;
	int tr_ObstacleAvoidance_OA_t11_counter;
	bool tr_ObstacleAvoidance_OA_t10_done;
	int tr_ObstacleAvoidance_OA_t10_counter;
	bool tr_ObstacleAvoidance_OA_t2_done;
	int tr_ObstacleAvoidance_OA_t2_counter;
} stm_ref1_OA_state;
/* Representation of record stm_ref1_memory */
typedef struct
{
	float min_range;
	float av;
	int sign;
	float lv;
	float lv_wander;
	bool OA_done;
	float current_speed;
	float pi;
	float av_wander;
	float vel[2];
	float randcoef;
	float closest_distance;
	float max_range;
	bool wander_done;
	float closest_angle;
	bool turn;
	float NOA_Move[2];
} stm_ref1_memory;
/* Representation of record stm_ref1_inputstate */
typedef struct
{
	bool closestAngle;
	float closestAngle_value;
	bool closestDistance;
	float closestDistance_value;
	int _clock_T;
	TRANSITIONS_stm_ref1_Enum _transition_;
} stm_ref1_inputstate;
/* Representation of record stm_ref1_state */
typedef struct
{
	bool done;
	STATES_stm_ref1_Enum state;
	STATES_stm_ref1_Enum target_state;
	STATUS_Enum status;
	stm_ref1_Wander_state s_Wander;
	stm_ref1_OA_state s_OA;
	bool tr_ObstacleAvoidance_t1_done;
	int tr_ObstacleAvoidance_t1_counter;
	bool tr_ObstacleAvoidance_t0_done;
	int tr_ObstacleAvoidance_t0_counter;
	bool tr_ObstacleAvoidance_t3_done;
	int tr_ObstacleAvoidance_t3_counter;
} stm_ref1_state;

typedef struct
{
	pthread_barrier_t can_write, can_read;
	stm_ref1_input_Enum value;
} stm_ref1_input_Enum_Channel;

typedef struct
{
	pthread_barrier_t can_write, can_read;
	stm_ref1_output_Enum value;
} stm_ref1_output_Enum_Channel;

typedef struct
{
	stm_ref1_input_Enum_Channel *start_stm_ref1;
	stm_ref1_output_Enum_Channel *end_stm_ref1;
} stm_stm_ref1_Channels;

/* Declaration of function signatures */
RESULT_Enum tr_ObstacleAvoidance_OA_t10(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_OA_t11(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_Wander_t3(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t0(stm_ref1_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_Wander_t1(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_OA_t3(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_OA_t4(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_OA_t0(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_OA_t6(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t1(stm_ref1_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_OA_t12(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_Wander_t2(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_OA_t2(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_OA_t13(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_Wander_t4(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t3(stm_ref1_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);

RESULT_Enum ObstacleAvoidance_OA_j0(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output);
RESULT_Enum ObstacleAvoidance_OA_j4(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output);
RESULT_Enum ObstacleAvoidance_OA_j1(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output);
RESULT_Enum ObstacleAvoidance_OA_j3(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output);
RESULT_Enum ObstacleAvoidance_OA_j2(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output);

RESULT_Enum en_Wander_Move_Forward_1(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);
RESULT_Enum en_Wander_Turn_1(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output);

char *print_STATES_stm_ref1(STATES_stm_ref1_Enum *value)
{
	if (value->type == STATES_stm_ref1_NONE)
	{
		return "NONE";
	}
	else if (value->type == STATES_stm_ref1_Wander)
	{
		return "Wander";
	}
	else if (value->type == STATES_stm_ref1_OA)
	{
		return "OA";
	}
}

char *print_STATES_stm_ref1_Wander(STATES_stm_ref1_Wander_Enum *value)
{
	if (value->type == STATES_stm_ref1_Wander_NONE)
	{
		return "NONE";
	}
	else if (value->type == STATES_stm_ref1_Wander_Turn)
	{
		return "Turn";
	}
	else if (value->type == STATES_stm_ref1_Wander_Move_Forward)
	{
		return "Move_Forward";
	}
	else if (value->type == STATES_stm_ref1_Wander_s0)
	{
		return "s0";
	}
}

RESULT_Enum ObstacleAvoidance_OA_j4(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output)
{
	if (abs((memorystate)->closest_angle) >= 30)
	{
		if (!(state)->tr_ObstacleAvoidance_OA_t2_done)
		{
			RESULT_Enum _ret_;
			_ret_ = tr_ObstacleAvoidance_OA_t2(state, inputstate, memorystate, output);
			return _ret_;
		}
		else
		{
			(state)->tr_ObstacleAvoidance_OA_t0_done = false;
			(state)->tr_ObstacleAvoidance_OA_t12_done = false;
			(state)->tr_ObstacleAvoidance_OA_t13_done = false;
			(state)->tr_ObstacleAvoidance_OA_t3_done = false;
			(state)->tr_ObstacleAvoidance_OA_t4_done = false;

			(*state).state = create_STATES_stm_ref1_OA_VHFEnabled();
			(*state).status = create_STATUS_ENTER_STATE();
			(*state).tr_ObstacleAvoidance_OA_t2_done = false;
			(*state).tr_ObstacleAvoidance_OA_t2_counter = 0;
			return create_RESULT_CONT();
		}
	}
	else if (abs((memorystate)->closest_angle) < 30)
	{
		RESULT_Enum _ret_;
		_ret_ = ObstacleAvoidance_OA_j2(state, inputstate, memorystate, output);
		return _ret_;
	}
	else
	{
		return create_RESULT_CONT();
	}
}
char *print_STATES_stm_ref1_OA(STATES_stm_ref1_OA_Enum *value)
{
	if (value->type == STATES_stm_ref1_OA_NONE)
	{
		return "NONE";
	}
	else if (value->type == STATES_stm_ref1_OA_VHFEnabled)
	{
		return "VHFEnabled";
	}
}
RESULT_Enum tr_ObstacleAvoidance_OA_t10(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_OA_t10.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_OA_t10_counter == 0)
	{
		(*memory).lv = -0.4;
		(*state).tr_ObstacleAvoidance_OA_t10_counter = 1;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_OA_t10_counter == 1)
	{
		(*memory).OA_done = true;
		(*state).tr_ObstacleAvoidance_OA_t10_counter = 2;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_OA_t10_counter = 0;
		(state)->tr_ObstacleAvoidance_OA_t10_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_OA_t11(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_OA_t11.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_OA_t11_counter == 0)
	{
		(*memory).OA_done = true;
		(*state).tr_ObstacleAvoidance_OA_t11_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_OA_t11_counter = 0;
		(state)->tr_ObstacleAvoidance_OA_t11_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum ObstacleAvoidance_OA_j1(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output)
{
	if (((memorystate)->closest_distance >= (memorystate)->min_range) && ((memorystate)->closest_distance < (memorystate)->max_range) && (abs((memorystate)->closest_angle) <= 90))
	{
		if (!(state)->tr_ObstacleAvoidance_OA_t0_done)
		{
			RESULT_Enum _ret_;
			_ret_ = tr_ObstacleAvoidance_OA_t0(state, inputstate, memorystate, output);
			return _ret_;
		}
		else
		{
			
			RESULT_Enum _ret_;
			_ret_ = ObstacleAvoidance_OA_j0(state, inputstate, memorystate, output);
			return _ret_;
		}
	}
	else if (!(((memorystate)->closest_distance >= (memorystate)->min_range) && ((memorystate)->closest_distance < (memorystate)->max_range) && abs((memorystate)->closest_angle) <= 90))
	{
		if (!(state)->tr_ObstacleAvoidance_OA_t6_done)
		{
			RESULT_Enum _ret_;
			_ret_ = tr_ObstacleAvoidance_OA_t6(state, inputstate, memorystate, output);
			return _ret_;
		}
		else
		{
			(state)->tr_ObstacleAvoidance_OA_t0_done = false;
			(state)->tr_ObstacleAvoidance_OA_t12_done = false;
			(state)->tr_ObstacleAvoidance_OA_t13_done = false;
			(state)->tr_ObstacleAvoidance_OA_t3_done = false;
			(state)->tr_ObstacleAvoidance_OA_t4_done = false;

			(*state).state = create_STATES_stm_ref1_OA_VHFEnabled();
			(*state).status = create_STATUS_ENTER_STATE();
			(*state).tr_ObstacleAvoidance_OA_t6_done = false;
			(*state).tr_ObstacleAvoidance_OA_t6_counter = 0;
			return create_RESULT_CONT();
		}
	}
	else
	{
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_Wander_t3(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_Wander_t3.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_Wander_t3_counter == 0)
	{
		(*memory).wander_done = true;
		(*state).tr_ObstacleAvoidance_Wander_t3_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_Wander_t3_counter = 0;
		(state)->tr_ObstacleAvoidance_Wander_t3_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_t0(stm_ref1_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t0.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_t0_counter == 0)
	{
		(*memory).wander_done = false;
		(*state).tr_ObstacleAvoidance_t0_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_t0_counter = 0;
		(state)->tr_ObstacleAvoidance_t0_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum stm_stm_ref1_OA_step(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "		Running step of state machine OA");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((*state).state.type == create_STATES_stm_ref1_OA_NONE().type)
	{
		{
			char _s0[256];
			sprintf(_s0, "%s", "		Executing initial junction of OA");
			fprintf(log_file, "DEBUG: %s\n", _s0);
		}
		{
			(*state).state = create_STATES_stm_ref1_OA_VHFEnabled();
		}
		return create_RESULT_CONT();
	}
	else if ((*state).state.type == create_STATES_stm_ref1_OA_VHFEnabled().type)
	{
		if ((*state).status.type == create_STATUS_ENTER_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering state VHFEnabled");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				(*state).status = create_STATUS_ENTER_CHILDREN();
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_ENTER_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering children of state VHFEnabled");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			(*state).status = create_STATUS_EXECUTE_STATE();
			{
				(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_NONE();
			}
			return create_RESULT_CONT();
		}
		else if ((*state).status.type == create_STATUS_EXECUTE_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Executing state VHFEnabled");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_NONE().type)
			{
				if ((inputstate)->closestAngle && (inputstate)->closestDistance)
				{
					(*memorystate).closest_angle = (inputstate)->closestAngle_value;
					(*memorystate).closest_distance = (inputstate)->closestDistance_value;
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_OA_t5();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else
				{
					return create_RESULT_CONT();
				}
			}
			else
			{
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_EXIT_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting children of state VHFEnabled");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			(*state).status = create_STATUS_EXIT_STATE();
			return create_RESULT_CONT();
		}
		else if ((*state).status.type == create_STATUS_EXIT_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting state VHFEnabled");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_OA_t5().type)
				{
					RESULT_Enum _ret_;
					_ret_ = ObstacleAvoidance_OA_j1(state, inputstate, memorystate, output);
					return _ret_;
				}
				else
				{
					(*state).status = create_STATUS_INACTIVE();
					(*state).state = create_STATES_stm_ref1_OA_NONE();
					return create_RESULT_CONT();
				}
			}
		}
		else if ((*state).status.type == create_STATUS_INACTIVE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		State VHFEnabled is inactive");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			return create_RESULT_CONT();
		}
	}
}
RESULT_Enum tr_ObstacleAvoidance_Wander_t1(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_Wander_t1.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_Wander_t1_counter == 0)
	{
		// TODO: check correction
		// (*memory).NOA_Move = (memory)->vel;
		memcpy((*memory).NOA_Move, (memory)->vel, sizeof((memory)->vel));
		(*state).tr_ObstacleAvoidance_Wander_t1_counter = 1;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_Wander_t1_counter == 1)
	{
		(*inputstate)._clock_T = 0;
		(*state).tr_ObstacleAvoidance_Wander_t1_counter = 2;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_Wander_t1_counter == 2)
	{
		(*memory).randcoef = rand() % 5;
		(*state).tr_ObstacleAvoidance_Wander_t1_counter = 3;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_Wander_t1_counter == 3)
	{
		(*memory).sign = random_sign();
		;
		(*state).tr_ObstacleAvoidance_Wander_t1_counter = 4;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_Wander_t1_counter == 4)
	{
		(*memory).turn = false;
		(*state).tr_ObstacleAvoidance_Wander_t1_counter = 5;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_Wander_t1_counter == 5)
	{
		(*memory).wander_done = true;
		(*state).tr_ObstacleAvoidance_Wander_t1_counter = 6;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_Wander_t1_counter = 0;
		(state)->tr_ObstacleAvoidance_Wander_t1_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_OA_t3(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_OA_t3.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_OA_t3_counter == 0)
	{
		(*memory).av = (((((memory)->closest_angle - 100)) * (memory)->pi) / 180);
		(*state).tr_ObstacleAvoidance_OA_t3_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_OA_t3_counter = 0;
		(state)->tr_ObstacleAvoidance_OA_t3_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_OA_t4(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_OA_t4.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_OA_t4_counter == 0)
	{
		(*memory).av = (((((memory)->closest_angle + 100)) * (memory)->pi) / 180);
		(*state).tr_ObstacleAvoidance_OA_t4_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_OA_t4_counter = 0;
		(state)->tr_ObstacleAvoidance_OA_t4_done = true;
		return create_RESULT_CONT();
	}
}

RESULT_Enum en_Wander_Move_Forward_1(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running entry action 1 of state Wander_Move_Forward.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->en_Wander_Move_Forward_1_counter == 0)
	{
		// TODO: check correction
		// ERROR = 0.0;
		(*memory).vel[0] = 0.0;
		(*state).en_Wander_Move_Forward_1_counter = 1;
		return create_RESULT_CONT();
	}
	else if ((state)->en_Wander_Move_Forward_1_counter == 1)
	{
		// TODO: check correction
		//ERROR = (memory)->lv_wander;
		(*memory).vel[1] = (memory)->lv_wander;
		(*state).en_Wander_Move_Forward_1_counter = 2;
		return create_RESULT_CONT();
	}
	else if ((state)->en_Wander_Move_Forward_1_counter == 2)
	{
		// TODO: check correction
		// (*memory).NOA_Move = (memory)->vel;
		memcpy((*memory).NOA_Move, (memory)->vel, sizeof((memory)->vel));
		(*state).en_Wander_Move_Forward_1_counter = 3;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).en_Wander_Move_Forward_1_counter = 0;
		(state)->en_Wander_Move_Forward_1_done = true;
		return create_RESULT_CONT();
	}
}
char *print_stm_ref1_OA_state(stm_ref1_OA_state *state)
{
	char *temp1_;
	temp1_ = print_STATES_stm_ref1_OA(&(state)->state);
	char *temp2_;
	temp2_ = print_STATUS(&(state)->status);
	return concat(concat(concat(temp1_, " ("), temp2_), ")");
}
RESULT_Enum ObstacleAvoidance_OA_j3(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output)
{
	if (((memorystate)->closest_distance > 0.4))
	{
		if (!(state)->tr_ObstacleAvoidance_OA_t12_done)
		{
			RESULT_Enum _ret_;
			_ret_ = tr_ObstacleAvoidance_OA_t12(state, inputstate, memorystate, output);
			return _ret_;
		}
		else
		{
			RESULT_Enum _ret_;
			_ret_ = ObstacleAvoidance_OA_j4(state, inputstate, memorystate, output);
			return _ret_;
		}
	}
	else if (((memorystate)->closest_distance <= 0.4))
	{
		if (!(state)->tr_ObstacleAvoidance_OA_t13_done)
		{
			RESULT_Enum _ret_;
			_ret_ = tr_ObstacleAvoidance_OA_t13(state, inputstate, memorystate, output);
			return _ret_;
		}
		else
		{
			
			RESULT_Enum _ret_;
			_ret_ = ObstacleAvoidance_OA_j4(state, inputstate, memorystate, output);
			return _ret_;
		}
	}
	else
	{
		return create_RESULT_CONT();
	}
}

RESULT_Enum stm_stm_ref1_Wander_step(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "		Running step of state machine Wander");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((*state).state.type == create_STATES_stm_ref1_Wander_NONE().type)
	{
		{
			char _s0[256];
			sprintf(_s0, "%s", "		Executing initial junction of Wander");
			fprintf(log_file, "DEBUG: %s\n", _s0);
		}
		{
			(*state).state = create_STATES_stm_ref1_Wander_s0();
		}
		return create_RESULT_CONT();
	}
	else if ((*state).state.type == create_STATES_stm_ref1_Wander_Turn().type)
	{
		if ((*state).status.type == create_STATUS_ENTER_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering state Turn");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if (!(state)->en_Wander_Turn_1_done)
			{
				RESULT_Enum _ret_;
				_ret_ = en_Wander_Turn_1(state, inputstate, memorystate, output);
				return _ret_;
			}
			else
			{
				(*state).status = create_STATUS_ENTER_CHILDREN();
				(*state).en_Wander_Turn_1_done = false;
				(*state).en_Wander_Turn_1_counter = 0;
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_ENTER_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering children of state Turn");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			(*state).status = create_STATUS_EXECUTE_STATE();
			{
				(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_NONE();
			}
			return create_RESULT_CONT();
		}
		else if ((*state).status.type == create_STATUS_EXECUTE_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Executing state Turn");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_NONE().type)
			{
				if ((inputstate)->_clock_T < (memorystate)->randcoef)
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t4();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else if ((inputstate)->_clock_T >= (memorystate)->randcoef)
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t1();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else
				{
					return create_RESULT_CONT();
				}
			}
			else
			{
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_EXIT_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting children of state Turn");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			(*state).status = create_STATUS_EXIT_STATE();
			return create_RESULT_CONT();
		}
		else if ((*state).status.type == create_STATUS_EXIT_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting state Turn");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t4().type)
				{
					if (!(state)->tr_ObstacleAvoidance_Wander_t4_done)
					{
						RESULT_Enum _ret_;
						_ret_ = tr_ObstacleAvoidance_Wander_t4(state, inputstate, memorystate, output);
						return _ret_;
					}
					else
					{
						(*state).state = create_STATES_stm_ref1_Wander_Turn();
						(*state).status = create_STATUS_ENTER_STATE();
						(*state).tr_ObstacleAvoidance_Wander_t4_done = false;
						(*state).tr_ObstacleAvoidance_Wander_t4_counter = 0;
						return create_RESULT_CONT();
					}
				}
				else if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t1().type)
				{
					if (!(state)->tr_ObstacleAvoidance_Wander_t1_done)
					{
						RESULT_Enum _ret_;
						_ret_ = tr_ObstacleAvoidance_Wander_t1(state, inputstate, memorystate, output);
						return _ret_;
					}
					else
					{
						(*state).state = create_STATES_stm_ref1_Wander_Move_Forward();
						(*state).status = create_STATUS_ENTER_STATE();
						(*state).tr_ObstacleAvoidance_Wander_t1_done = false;
						(*state).tr_ObstacleAvoidance_Wander_t1_counter = 0;
						return create_RESULT_CONT();
					}
				}
				else
				{
					(*state).status = create_STATUS_INACTIVE();
					(*state).state = create_STATES_stm_ref1_Wander_NONE();
					return create_RESULT_CONT();
				}
			}
		}
		else if ((*state).status.type == create_STATUS_INACTIVE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		State Turn is inactive");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			return create_RESULT_CONT();
		}
	}
	else if ((*state).state.type == create_STATES_stm_ref1_Wander_Move_Forward().type)
	{
		if ((*state).status.type == create_STATUS_ENTER_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering state Move_Forward");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if (!(state)->en_Wander_Move_Forward_1_done)
			{
				RESULT_Enum _ret_;
				_ret_ = en_Wander_Move_Forward_1(state, inputstate, memorystate, output);
				return _ret_;
			}
			else
			{
				(*state).status = create_STATUS_ENTER_CHILDREN();
				(*state).en_Wander_Move_Forward_1_done = false;
				(*state).en_Wander_Move_Forward_1_counter = 0;
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_ENTER_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering children of state Move_Forward");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			(*state).status = create_STATUS_EXECUTE_STATE();
			{
				(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_NONE();
			}
			return create_RESULT_CONT();
		}
		else if ((*state).status.type == create_STATUS_EXECUTE_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Executing state Move_Forward");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_NONE().type)
			{
				if ((inputstate)->_clock_T < (memorystate)->randcoef)
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t3();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else if ((inputstate)->_clock_T >= (memorystate)->randcoef)
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t2();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else
				{
					return create_RESULT_CONT();
				}
			}
			else
			{
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_EXIT_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting children of state Move_Forward");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			(*state).status = create_STATUS_EXIT_STATE();
			return create_RESULT_CONT();
		}
		else if ((*state).status.type == create_STATUS_EXIT_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting state Move_Forward");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t3().type)
				{
					if (!(state)->tr_ObstacleAvoidance_Wander_t3_done)
					{
						RESULT_Enum _ret_;
						_ret_ = tr_ObstacleAvoidance_Wander_t3(state, inputstate, memorystate, output);
						return _ret_;
					}
					else
					{
						(*state).state = create_STATES_stm_ref1_Wander_Move_Forward();
						(*state).status = create_STATUS_ENTER_STATE();
						(*state).tr_ObstacleAvoidance_Wander_t3_done = false;
						(*state).tr_ObstacleAvoidance_Wander_t3_counter = 0;
						return create_RESULT_CONT();
					}
				}
				else if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t2().type)
				{
					if (!(state)->tr_ObstacleAvoidance_Wander_t2_done)
					{
						RESULT_Enum _ret_;
						_ret_ = tr_ObstacleAvoidance_Wander_t2(state, inputstate, memorystate, output);
						return _ret_;
					}
					else
					{
						(*state).state = create_STATES_stm_ref1_Wander_Turn();
						(*state).status = create_STATUS_ENTER_STATE();
						(*state).tr_ObstacleAvoidance_Wander_t2_done = false;
						(*state).tr_ObstacleAvoidance_Wander_t2_counter = 0;
						return create_RESULT_CONT();
					}
				}
				else
				{
					(*state).status = create_STATUS_INACTIVE();
					(*state).state = create_STATES_stm_ref1_Wander_NONE();
					return create_RESULT_CONT();
				}
			}
		}
		else if ((*state).status.type == create_STATUS_INACTIVE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		State Move_Forward is inactive");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			return create_RESULT_CONT();
		}
	}
	else if ((*state).state.type == create_STATES_stm_ref1_Wander_s0().type)
	{
		if ((*state).status.type == create_STATUS_ENTER_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering state s0");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				(*state).status = create_STATUS_ENTER_CHILDREN();
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_ENTER_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering children of state s0");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			(*state).status = create_STATUS_EXECUTE_STATE();
			{
				(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_NONE();
			}
			return create_RESULT_CONT();
		}
		else if ((*state).status.type == create_STATUS_EXECUTE_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Executing state s0");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_NONE().type)
			{
				if ((memorystate)->turn)
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t5();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else if (!(memorystate)->turn)
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t6();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else
				{
					return create_RESULT_CONT();
				}
			}
			else
			{
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_EXIT_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting children of state s0");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			(*state).status = create_STATUS_EXIT_STATE();
			return create_RESULT_CONT();
		}
		else if ((*state).status.type == create_STATUS_EXIT_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting state s0");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t5().type)
				{
					(*state).state = create_STATES_stm_ref1_Wander_Turn();
					(*state).status = create_STATUS_ENTER_STATE();
					return create_RESULT_CONT();
				}
				else if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t6().type)
				{
					(*state).state = create_STATES_stm_ref1_Wander_Move_Forward();
					(*state).status = create_STATUS_ENTER_STATE();
					return create_RESULT_CONT();
				}
				else
				{
					(*state).status = create_STATUS_INACTIVE();
					(*state).state = create_STATES_stm_ref1_Wander_NONE();
					return create_RESULT_CONT();
				}
			}
		}
		else if ((*state).status.type == create_STATUS_INACTIVE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		State s0 is inactive");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			return create_RESULT_CONT();
		}
	}
}

RESULT_Enum stm_stm_ref1_step(stm_ref1_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "		Running step of state machine ObstacleAvoidance");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((*state).state.type == create_STATES_stm_ref1_NONE().type)
	{
		{
			char _s0[256];
			sprintf(_s0, "%s", "		Executing initial junction of ObstacleAvoidance");
			fprintf(log_file, "DEBUG: %s\n", _s0);
		}
		{
			(*state).state = create_STATES_stm_ref1_Wander();
		}
		return create_RESULT_CONT();
	}
	else if ((*state).state.type == create_STATES_stm_ref1_Wander().type)
	{
		if ((*state).status.type == create_STATUS_ENTER_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering state Wander");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				(*state).status = create_STATUS_ENTER_CHILDREN();
				((*state).s_Wander).status = create_STATUS_ENTER_STATE();
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_ENTER_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering children of state Wander");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			RESULT_Enum _ret_;
			_ret_ = stm_stm_ref1_Wander_step(&(state)->s_Wander, inputstate, memorystate, output);
			if (((state)->s_Wander).status.type == create_STATUS_EXECUTE_STATE().type)
			{
				(*state).status = create_STATUS_EXECUTE_STATE();
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_NONE();
				}
			}
			return _ret_;
		}
		else if ((*state).status.type == create_STATUS_EXECUTE_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Executing state Wander");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_NONE().type)
			{
				if ((memorystate)->wander_done == true)
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_t0();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else
				{
					RESULT_Enum _ret_;
					_ret_ = stm_stm_ref1_Wander_step(&(state)->s_Wander, inputstate, memorystate, output);
					return _ret_;
				}
			}
			else
			{
				RESULT_Enum _ret_;
				_ret_ = stm_stm_ref1_Wander_step(&(state)->s_Wander, inputstate, memorystate, output);
				return _ret_;
			}
		}
		else if ((*state).status.type == create_STATUS_EXIT_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting children of state Wander");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if (((*state).s_Wander).status.type == create_STATUS_EXECUTE_STATE().type)
			{
				((*state).s_Wander).status = create_STATUS_EXIT_CHILDREN();
				return create_RESULT_CONT();
			}
			else if (((*state).s_Wander).status.type == create_STATUS_INACTIVE().type)
			{
				(*state).status = create_STATUS_EXIT_STATE();
				return create_RESULT_CONT();
			}
			else
			{
				RESULT_Enum _ret_;
				_ret_ = stm_stm_ref1_Wander_step(&(state)->s_Wander, inputstate, memorystate, output);
				return _ret_;
			}
		}
		else if ((*state).status.type == create_STATUS_EXIT_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting state Wander");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_t0().type)
				{
					if (!(state)->tr_ObstacleAvoidance_t0_done)
					{
						RESULT_Enum _ret_;
						_ret_ = tr_ObstacleAvoidance_t0(state, inputstate, memorystate, output);
						return _ret_;
					}
					else
					{
						(*state).state = create_STATES_stm_ref1_OA();
						(*state).status = create_STATUS_ENTER_STATE();
						(*state).tr_ObstacleAvoidance_t0_done = false;
						(*state).tr_ObstacleAvoidance_t0_counter = 0;
						return create_RESULT_CONT();
					}
				}
				else
				{
					(*state).status = create_STATUS_INACTIVE();
					(*state).state = create_STATES_stm_ref1_NONE();
					return create_RESULT_CONT();
				}
			}
		}
		else if ((*state).status.type == create_STATUS_INACTIVE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		State Wander is inactive");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			return create_RESULT_CONT();
		}
	}
	else if ((*state).state.type == create_STATES_stm_ref1_OA().type)
	{
		if ((*state).status.type == create_STATUS_ENTER_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering state OA");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				(*state).status = create_STATUS_ENTER_CHILDREN();
				((*state).s_OA).status = create_STATUS_ENTER_STATE();
				return create_RESULT_CONT();
			}
		}
		else if ((*state).status.type == create_STATUS_ENTER_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Entering children of state OA");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			RESULT_Enum _ret_;
			_ret_ = stm_stm_ref1_OA_step(&(state)->s_OA, inputstate, memorystate, output);
			if (((state)->s_OA).status.type == create_STATUS_EXECUTE_STATE().type)
			{
				(*state).status = create_STATUS_EXECUTE_STATE();
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_NONE();
				}
			}
			return _ret_;
		}
		else if ((*state).status.type == create_STATUS_EXECUTE_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Executing state OA");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_NONE().type)
			{
				if ((memorystate)->OA_done == true)
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_t1();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else if (!(inputstate)->closestDistance || !(inputstate)->closestAngle)
				{
					(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_t3();
					(*state).status = create_STATUS_EXIT_CHILDREN();
					return create_RESULT_CONT();
				}
				else
				{
					RESULT_Enum _ret_;
					_ret_ = stm_stm_ref1_OA_step(&(state)->s_OA, inputstate, memorystate, output);
					return _ret_;
				}
			}
			else
			{
				RESULT_Enum _ret_;
				_ret_ = stm_stm_ref1_OA_step(&(state)->s_OA, inputstate, memorystate, output);
				return _ret_;
			}
		}
		else if ((*state).status.type == create_STATUS_EXIT_CHILDREN().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting children of state OA");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			if (((*state).s_OA).status.type == create_STATUS_EXECUTE_STATE().type)
			{
				((*state).s_OA).status = create_STATUS_EXIT_CHILDREN();
				return create_RESULT_CONT();
			}
			else if (((*state).s_OA).status.type == create_STATUS_INACTIVE().type)
			{
				// TODO: This resets the done attribute when the parent state is exited
				(*state).s_OA.tr_ObstacleAvoidance_OA_t0_done = false;
				(*state).s_OA.tr_ObstacleAvoidance_OA_t12_done = false;
				(*state).s_OA.tr_ObstacleAvoidance_OA_t13_done = false;
				(*state).s_OA.tr_ObstacleAvoidance_OA_t3_done = false;
				(*state).s_OA.tr_ObstacleAvoidance_OA_t4_done = false;
				(*state).status = create_STATUS_EXIT_STATE();
				return create_RESULT_CONT();
			}
			else
			{
				RESULT_Enum _ret_;
				_ret_ = stm_stm_ref1_OA_step(&(state)->s_OA, inputstate, memorystate, output);
				return _ret_;
			}
		}
		else if ((*state).status.type == create_STATUS_EXIT_STATE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Exiting state OA");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_t1().type)
				{
					if (!(state)->tr_ObstacleAvoidance_t1_done)
					{
						RESULT_Enum _ret_;
						_ret_ = tr_ObstacleAvoidance_t1(state, inputstate, memorystate, output);
						return _ret_;
					}
					else
					{
						(*state).state = create_STATES_stm_ref1_Wander();
						(*state).status = create_STATUS_ENTER_STATE();
						(*state).tr_ObstacleAvoidance_t1_done = false;
						(*state).tr_ObstacleAvoidance_t1_counter = 0;
						return create_RESULT_CONT();
					}
				}
				else if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_t3().type)
				{
					if (!(state)->tr_ObstacleAvoidance_t3_done)
					{
						RESULT_Enum _ret_;
						_ret_ = tr_ObstacleAvoidance_t3(state, inputstate, memorystate, output);
						return _ret_;
					}
					else
					{
						(*state).state = create_STATES_stm_ref1_Wander();
						(*state).status = create_STATUS_ENTER_STATE();
						(*state).tr_ObstacleAvoidance_t3_done = false;
						(*state).tr_ObstacleAvoidance_t3_counter = 0;
						return create_RESULT_CONT();
					}
				}
				else
				{
					(*state).status = create_STATUS_INACTIVE();
					(*state).state = create_STATES_stm_ref1_NONE();
					return create_RESULT_CONT();
				}
			}
		}
		else if ((*state).status.type == create_STATUS_INACTIVE().type)
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "		State OA is inactive");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			return create_RESULT_CONT();
		}
	}
}
RESULT_Enum ObstacleAvoidance_OA_j0(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output)
{
	if (((memorystate)->closest_angle > 0))
	{
		if (!(state)->tr_ObstacleAvoidance_OA_t3_done)
		{
			RESULT_Enum _ret_;
			_ret_ = tr_ObstacleAvoidance_OA_t3(state, inputstate, memorystate, output);
			return _ret_;
		}
		else
		{
			
			RESULT_Enum _ret_;
			_ret_ = ObstacleAvoidance_OA_j3(state, inputstate, memorystate, output);
			return _ret_;
		}
	}
	else if (((memorystate)->closest_angle <= 0))
	{
		if (!(state)->tr_ObstacleAvoidance_OA_t4_done)
		{
			RESULT_Enum _ret_;
			_ret_ = tr_ObstacleAvoidance_OA_t4(state, inputstate, memorystate, output);
			return _ret_;
		}
		else
		{
			
			RESULT_Enum _ret_;
			_ret_ = ObstacleAvoidance_OA_j3(state, inputstate, memorystate, output);
			return _ret_;
		}
	}
	else
	{
		return create_RESULT_CONT();
	}
}

char *print_stm_ref1_Wander_state(stm_ref1_Wander_state *state)
{
	char *temp1_;
	temp1_ = print_STATES_stm_ref1_Wander(&(state)->state);
	char *temp2_;
	temp2_ = print_STATUS(&(state)->status);
	return concat(concat(concat(temp1_, " ("), temp2_), ")");
}

RESULT_Enum en_Wander_Turn_1(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running entry action 1 of state Wander_Turn.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->en_Wander_Turn_1_counter == 0)
	{
		// TODO: check correction
		// ERROR = ((memory)->av_wander * (memory)->sign);
		(*memory).vel[0] = ((memory)->av_wander * (memory)->sign);
		(*state).en_Wander_Turn_1_counter = 1;
		return create_RESULT_CONT();
	}
	else if ((state)->en_Wander_Turn_1_counter == 1)
	{
		// TODO: check correction
		// ERROR = 0.0;
		(*memory).vel[1] = 0.0;
		(*state).en_Wander_Turn_1_counter = 2;
		return create_RESULT_CONT();
	}
	else if ((state)->en_Wander_Turn_1_counter == 2)
	{
		// TODO: check correction
		// (*memory).NOA_Move = (memory)->vel;
		memcpy((*memory).NOA_Move, (memory)->vel, sizeof((memory)->vel));
		(*state).en_Wander_Turn_1_counter = 3;
		return create_RESULT_CONT();
	}
	else
	{
		(state)->en_Wander_Turn_1_counter = 0;
		(state)->en_Wander_Turn_1_done = true;
		return create_RESULT_CONT();
	}
}

RESULT_Enum tr_ObstacleAvoidance_OA_t0(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_OA_t0.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_OA_t0_counter == 0)
	{
		// TODO: check correction
		(*memory).current_speed = memory->NOA_Move[1];
		(*state).tr_ObstacleAvoidance_OA_t0_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(state)->tr_ObstacleAvoidance_OA_t0_counter = 0;
		(state)->tr_ObstacleAvoidance_OA_t0_done = true;
		return create_RESULT_CONT();
	}
}
char *print_stm_ref1_state(stm_ref1_state *state)
{
	char *temp1_;
	temp1_ = print_STATES_stm_ref1(&(state)->state);
	char *temp2_;
	temp2_ = print_STATUS(&(state)->status);
	if ((state)->state.type == STATES_stm_ref1_OA)
	{
		char *temp_;
		temp_ = print_stm_ref1_OA_state(&(state)->s_OA);
		return concat(concat(concat(concat(concat(temp1_, " ("), temp2_), ")"), " > "), temp_);
	}
	else if ((state)->state.type == STATES_stm_ref1_Wander)
	{
		char *temp_;
		temp_ = print_stm_ref1_Wander_state(&(state)->s_Wander);
		return concat(concat(concat(concat(concat(temp1_, " ("), temp2_), ")"), " > "), temp_);
	}
	else
	{
		return concat(concat(concat(temp1_, " ("), temp2_), ")");
	}
}

RESULT_Enum tr_ObstacleAvoidance_OA_t6(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_OA_t6.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_OA_t6_counter == 0)
	{
		// TODO: check correction
		(*memory).lv = memory->NOA_Move[1];
		(*state).tr_ObstacleAvoidance_OA_t6_counter = 1;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_OA_t6_counter == 1)
	{
		// TODO: check correction
		(*memory).av = memory->NOA_Move[0];
		(*state).tr_ObstacleAvoidance_OA_t6_counter = 2;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_OA_t6_counter == 2)
	{
		(*memory).OA_done = true;
		(*state).tr_ObstacleAvoidance_OA_t6_counter = 3;
		return create_RESULT_CONT();
	}
	else
	{
		(state)->tr_ObstacleAvoidance_OA_t6_counter = 0;
		(state)->tr_ObstacleAvoidance_OA_t6_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_t1(stm_ref1_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t1.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_t1_counter == 0)
	{
		(*memory).OA_done = false;
		(*state).tr_ObstacleAvoidance_t1_counter = 1;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_t1_counter == 1)
	{
		{
			pthread_barrier_wait(&output->can_write);
			output->value = create_stm_ref1_output__move((memory)->av, (memory)->lv);
			printf("Move: av = %f, lv = %f\n", (memory)->av, (memory)->lv);
			pthread_barrier_wait(&output->can_read);
		}
		(*state).tr_ObstacleAvoidance_t1_counter = 2;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_t1_counter == 2)
	{
		(*state).tr_ObstacleAvoidance_t1_counter = 3;
		return create_RESULT_WAIT();
	}
	else
	{
		(state)->tr_ObstacleAvoidance_t1_counter = 0;
		(state)->tr_ObstacleAvoidance_t1_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_OA_t12(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_OA_t12.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_OA_t12_counter == 0)
	{
		(*memory).lv = ((memory)->current_speed / 2);
		(*state).tr_ObstacleAvoidance_OA_t12_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_OA_t12_counter = 0;
		(state)->tr_ObstacleAvoidance_OA_t12_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum ObstacleAvoidance_OA_j2(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memorystate, stm_ref1_output_Enum_Channel *output)
{
	if (((memorystate)->closest_distance >= 0.4))
	{
		if (!(state)->tr_ObstacleAvoidance_OA_t11_done)
		{
			RESULT_Enum _ret_;
			_ret_ = tr_ObstacleAvoidance_OA_t11(state, inputstate, memorystate, output);
			return _ret_;
		}
		else
		{
			// reset dones when reaching back into state; this does not work if there are junction loops; need alternative solution
			(state)->tr_ObstacleAvoidance_OA_t0_done = false;
			(state)->tr_ObstacleAvoidance_OA_t12_done = false;
			(state)->tr_ObstacleAvoidance_OA_t13_done = false;
			(state)->tr_ObstacleAvoidance_OA_t3_done = false;
			(state)->tr_ObstacleAvoidance_OA_t4_done = false;

			(*state).state = create_STATES_stm_ref1_OA_VHFEnabled();
			(*state).status = create_STATUS_ENTER_STATE();
			(*state).tr_ObstacleAvoidance_OA_t11_done = false;
			(*state).tr_ObstacleAvoidance_OA_t11_counter = 0;
			return create_RESULT_CONT();
		}
	}
	else if (((memorystate)->closest_distance < 0.4))
	{
		if (!(state)->tr_ObstacleAvoidance_OA_t10_done)
		{
			RESULT_Enum _ret_;
			_ret_ = tr_ObstacleAvoidance_OA_t10(state, inputstate, memorystate, output);
			return _ret_;
		}
		else
		{
			// reset dones when going back into the state; 
			(state)->tr_ObstacleAvoidance_OA_t0_done = false;
			(state)->tr_ObstacleAvoidance_OA_t12_done = false;
			(state)->tr_ObstacleAvoidance_OA_t13_done = false;
			(state)->tr_ObstacleAvoidance_OA_t3_done = false;
			(state)->tr_ObstacleAvoidance_OA_t4_done = false;

			(*state).state = create_STATES_stm_ref1_OA_VHFEnabled();
			(*state).status = create_STATUS_ENTER_STATE();
			(*state).tr_ObstacleAvoidance_OA_t10_done = false;
			(*state).tr_ObstacleAvoidance_OA_t10_counter = 0;
			return create_RESULT_CONT();
		}
	}
	else
	{
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_Wander_t2(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_Wander_t2.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_Wander_t2_counter == 0)
	{
		// TODO: check correction
		//(*memory).NOA_Move = (memory)->vel;
		memcpy((*memory).NOA_Move, (memory)->vel, sizeof((memory)->vel));
		(*state).tr_ObstacleAvoidance_Wander_t2_counter = 1;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_Wander_t2_counter == 1)
	{
		(*inputstate)._clock_T = 0;
		(*state).tr_ObstacleAvoidance_Wander_t2_counter = 2;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_Wander_t2_counter == 2)
	{
		(*memory).randcoef = rand() % 5;
		(*state).tr_ObstacleAvoidance_Wander_t2_counter = 3;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_Wander_t2_counter == 3)
	{
		(*memory).turn = true;
		(*state).tr_ObstacleAvoidance_Wander_t2_counter = 4;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_Wander_t2_counter == 4)
	{
		(*memory).wander_done = true;
		(*state).tr_ObstacleAvoidance_Wander_t2_counter = 5;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_Wander_t2_counter = 0;
		(state)->tr_ObstacleAvoidance_Wander_t2_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_OA_t2(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_OA_t2.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_OA_t2_counter == 0)
	{
		(*memory).OA_done = true;
		(*state).tr_ObstacleAvoidance_OA_t2_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_OA_t2_counter = 0;
		(state)->tr_ObstacleAvoidance_OA_t2_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_OA_t13(stm_ref1_OA_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_OA_t13.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_OA_t13_counter == 0)
	{
		(*memory).lv = 0.0;
		(*state).tr_ObstacleAvoidance_OA_t13_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_OA_t13_counter = 0;
		(state)->tr_ObstacleAvoidance_OA_t13_done = true;
		return create_RESULT_CONT();
	}
}
RESULT_Enum tr_ObstacleAvoidance_Wander_t4(stm_ref1_Wander_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_Wander_t4.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_Wander_t4_counter == 0)
	{
		(*memory).wander_done = true;
		(*state).tr_ObstacleAvoidance_Wander_t4_counter = 1;
		return create_RESULT_CONT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_Wander_t4_counter = 0;
		(state)->tr_ObstacleAvoidance_Wander_t4_done = true;
		return create_RESULT_CONT();
	}
}

RESULT_Enum tr_ObstacleAvoidance_t3(stm_ref1_state *state, stm_ref1_inputstate *inputstate, stm_ref1_memory *memory, stm_ref1_output_Enum_Channel *output)
{
	{
		char _s0[256];
		sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t3.");
		fprintf(log_file, "DEBUG: %s\n", _s0);
	}
	if ((state)->tr_ObstacleAvoidance_t3_counter == 0)
	{
		{
			pthread_barrier_wait(&output->can_write);
			// TODO: check if my correction is okay
			// output->value = create_stm_ref1_output__move(ERROR, ERROR);
			output->value = create_stm_ref1_output__move((memory)->av, (memory)->lv);
			printf("Move: av = %f, lv = %f\n", (memory)->av, (memory)->lv);
			pthread_barrier_wait(&output->can_read);
		}
		(*state).tr_ObstacleAvoidance_t3_counter = 1;
		return create_RESULT_CONT();
	}
	else if ((state)->tr_ObstacleAvoidance_t3_counter == 1)
	{
		(*state).tr_ObstacleAvoidance_t3_counter = 2;
		return create_RESULT_WAIT();
	}
	else
	{
		(*state).tr_ObstacleAvoidance_t3_counter = 0;
		(state)->tr_ObstacleAvoidance_t3_done = true;
		return create_RESULT_CONT();
	}
}

void *stm_stm_ref1(void *arg)
{
	stm_stm_ref1_Channels *channels = (stm_stm_ref1_Channels *)arg;
	stm_ref1_input_Enum_Channel *start_stm_ref1 = channels->start_stm_ref1;
	stm_ref1_output_Enum_Channel *end_stm_ref1 = channels->end_stm_ref1;
	{
		// state machine variable declarations;
		stm_ref1_inputstate inputstate = (stm_ref1_inputstate){
			.closestAngle = false,
			.closestAngle_value = 0.0,
			.closestDistance = false,
			.closestDistance_value = 0.0,
			._clock_T = 0,
			._transition_ = create_TRANSITIONS_stm_ref1_NONE()};
		stm_ref1_state state = (stm_ref1_state){
			.done = false,
			.state = create_STATES_stm_ref1_NONE(),
			.target_state = create_STATES_stm_ref1_NONE(),
			.status = create_STATUS_ENTER_STATE(),
			.s_Wander = (stm_ref1_Wander_state){
				.done = false,
				.state = create_STATES_stm_ref1_Wander_NONE(),
				.target_state = create_STATES_stm_ref1_Wander_NONE(),
				.status = create_STATUS_ENTER_STATE(),
				.en_Wander_Turn_1_done = false,
				.en_Wander_Turn_1_counter = 0,
				.en_Wander_Move_Forward_1_done = false,
				.en_Wander_Move_Forward_1_counter = 0,
				.tr_ObstacleAvoidance_Wander_t3_done = false,
				.tr_ObstacleAvoidance_Wander_t3_counter = 0,
				.tr_ObstacleAvoidance_Wander_t4_done = false,
				.tr_ObstacleAvoidance_Wander_t4_counter = 0,
				.tr_ObstacleAvoidance_Wander_t1_done = false,
				.tr_ObstacleAvoidance_Wander_t1_counter = 0,
				.tr_ObstacleAvoidance_Wander_t2_done = false,
				.tr_ObstacleAvoidance_Wander_t2_counter = 0},
			.s_OA = (stm_ref1_OA_state){.done = false, .state = create_STATES_stm_ref1_OA_NONE(), .target_state = create_STATES_stm_ref1_OA_NONE(), .status = create_STATUS_ENTER_STATE(), .tr_ObstacleAvoidance_OA_t12_done = false, .tr_ObstacleAvoidance_OA_t12_counter = 0, .tr_ObstacleAvoidance_OA_t0_done = false, .tr_ObstacleAvoidance_OA_t0_counter = 0, .tr_ObstacleAvoidance_OA_t3_done = false, .tr_ObstacleAvoidance_OA_t3_counter = 0, .tr_ObstacleAvoidance_OA_t13_done = false, .tr_ObstacleAvoidance_OA_t13_counter = 0, .tr_ObstacleAvoidance_OA_t6_done = false, .tr_ObstacleAvoidance_OA_t6_counter = 0, .tr_ObstacleAvoidance_OA_t4_done = false, .tr_ObstacleAvoidance_OA_t4_counter = 0, .tr_ObstacleAvoidance_OA_t11_done = false, .tr_ObstacleAvoidance_OA_t11_counter = 0, .tr_ObstacleAvoidance_OA_t10_done = false, .tr_ObstacleAvoidance_OA_t10_counter = 0, .tr_ObstacleAvoidance_OA_t2_done = false, .tr_ObstacleAvoidance_OA_t2_counter = 0},
			.tr_ObstacleAvoidance_t1_done = false,
			.tr_ObstacleAvoidance_t1_counter = 0,
			.tr_ObstacleAvoidance_t0_done = false,
			.tr_ObstacleAvoidance_t0_counter = 0,
			.tr_ObstacleAvoidance_t3_done = false,
			.tr_ObstacleAvoidance_t3_counter = 0};
		stm_ref1_memory memorystate = (stm_ref1_memory){
			.min_range = 0.2,
			.av = 0.0,
			.sign = 1,
			.lv = 0.0,
			.lv_wander = 0.6,
			.OA_done = false,
			.current_speed = 0.0,
			.pi = 3.14159,
			.av_wander = 0.7,
			.vel = {0.0, 0.0},
			.randcoef = 0.2,
			.closest_distance = 0,
			.max_range = 1.0,
			.wander_done = false,
			.closest_angle = 0,
			.turn = true,
			.NOA_Move = {0.0, 0.0}};
		// state machine loop;
		while (!(state).done)
		{
			{
				{
					char _s0[256];
					sprintf(_s0, "%s", "- Waiting for input on channel start_stm_ref1");
					fprintf(log_file, "DEBUG: %s\n", _s0);
				}
				bool inputDone = false;
				while (!inputDone)
				{
					stm_ref1_input_Enum _input_;
					{
						pthread_barrier_wait(&start_stm_ref1->can_write);
						pthread_barrier_wait(&start_stm_ref1->can_read);
						_input_ = start_stm_ref1->value;
					}
					{
						char _s0[256];
						sprintf(_s0, "%s", "- Read input on channel start_stm_ref1");
						fprintf(log_file, "DEBUG: %s\n", _s0);
					}
					if (_input_.type == stm_ref1_input_closestAngle)
					{
						float _aux_ = _input_.data.closestAngle.v1;
						(inputstate).closestAngle = true;
						(inputstate).closestAngle_value = _aux_;
					}
					else if (_input_.type == stm_ref1_input_closestDistance)
					{
						float _aux_ = _input_.data.closestDistance.v1;
						(inputstate).closestDistance = true;
						(inputstate).closestDistance_value = _aux_;
					}
					else if (_input_.type == stm_ref1_input__done_)
					{
						inputDone = true;
					}
					else if (_input_.type == stm_ref1_input__terminate_)
					{
						inputDone = true;
					}
				}
			}
			RESULT_Enum ret = create_RESULT_CONT();
			while (ret.type == create_RESULT_CONT().type)
			{
				char *temp_;
				temp_ = print_stm_ref1_state(&state);
				{
					char _s0[256];
					sprintf(_s0, "%s", temp_);
					fprintf(log_file, "DEBUG: %s\n", _s0);
				}
				ret = stm_stm_ref1_step(&state, &inputstate, &memorystate, end_stm_ref1);
			}
			{
				pthread_barrier_wait(&end_stm_ref1->can_write);
				end_stm_ref1->value = create_stm_ref1_output__done_();
				pthread_barrier_wait(&end_stm_ref1->can_read);
			}
			// update clocks;
			(inputstate)._clock_T = ((inputstate)._clock_T + 1);
			// reset input events;
			(inputstate).closestAngle = false;
			(inputstate).closestDistance = false;
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Sent output _done_ on channel end_stm_ref1");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
		}
	}
}

#endif