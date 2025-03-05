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

/* Representation of record stm_ref1_memory */
struct stm_ref1_memory {
	float cmd[2];
	float NOAcmd[2];
};


/* Representation of record stm_ref1_inputstate */
struct stm_ref1_inputstate {
	bool CCMove;
	float CCMove_value[2];
	bool OAMove;
	float OAMove_value[2];
	bool RWMove;
	float RWMove_value[2];
	bool Avoiding;
	bool Avoiding_value;
	TRANSITIONS_stm_ref1_Enum _transition_;
};
/* Representation of record stm_ref1_state */
struct stm_ref1_state {
	bool done;
	STATES_stm_ref1_Enum state;
	STATES_stm_ref1_Enum target_state;
	STATUS_Enum status;
	bool en_MoveManager_MoveHandler_1_done;
	int en_MoveManager_MoveHandler_1_counter;
};

typedef struct
{
    pthread_barrier_t can_write, can_read;
    stm_ref1_input_Enum value;
} stm_ref1_input_Enum_Channel;

typedef struct {
	pthread_barrier_t can_write, can_read;
	stm_ref1_output_Enum value;
} stm_ref1_output_Enum_Channel;

typedef struct {
	stm_ref1_input_Enum_Channel* start_stm_ref1;
	stm_ref1_output_Enum_Channel* end_stm_ref1;
} stm_stm_ref1_Channels;

	char* print_STATES_stm_ref1(STATES_stm_ref1_Enum* value) {
		if (value->type == STATES_stm_ref1_NONE) {
			return "NONE";
		}
		else if (value->type == STATES_stm_ref1_MoveHandler) {
		     	return "MoveHandler";
		     }
	}

	char* print_stm_ref1_state(struct stm_ref1_state* state) {
		char* temp1_;
		temp1_ = print_STATES_stm_ref1(&(state)->state);
		char* temp2_;
		temp2_ = print_STATUS(&(state)->status);
		// return concat(concat(concat(temp1_, " ("), temp2_), ")");
		return "";
	}






RESULT_Enum en_MoveManager_MoveHandler_1(struct stm_ref1_state* state, struct stm_ref1_inputstate* inputstate, struct stm_ref1_memory* memory, stm_ref1_output_Enum_Channel* output) {
		{
			char _s0[256];
			sprintf(_s0, "%s", "Running entry action 1 of state MoveManager_MoveHandler.");
			fprintf(log_file, "DEBUG: %s\n", _s0);
		}
		if (	(state)->en_MoveManager_MoveHandler_1_counter == 0 ) {
			{
				pthread_barrier_wait(&output->can_write);
				output->value = create_stm_ref1_output__move((memory)->cmd);
				pthread_barrier_wait(&output->can_read);
			}
			(*state).en_MoveManager_MoveHandler_1_counter = 1;
			return create_RESULT_CONT();
		} else if (	(state)->en_MoveManager_MoveHandler_1_counter == 1 ) {
			{
				pthread_barrier_wait(&output->can_write);
				output->value = create_stm_ref1_output_NOAMove((memory)->NOAcmd);
				pthread_barrier_wait(&output->can_read);
			}
			(*state).en_MoveManager_MoveHandler_1_counter = 2;
			return create_RESULT_CONT();
		} else {
			(state)->en_MoveManager_MoveHandler_1_done = true;
			return create_RESULT_CONT();
		}
	}
	





RESULT_Enum stm_stm_ref1_step(struct stm_ref1_state* state, struct stm_ref1_inputstate* inputstate, struct stm_ref1_memory* memorystate, stm_ref1_output_Enum_Channel* output) {
		{
			char _s0[256];
			sprintf(_s0, "%s", "		Running step of state machine MoveManager");
			fprintf(log_file, "DEBUG: %s\n", _s0);
		}
		if ((*state).state.type == create_STATES_stm_ref1_NONE().type) {
			{
				char _s0[256];
				sprintf(_s0, "%s", "		Executing initial junction of MoveManager");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			{
				(*state).state = create_STATES_stm_ref1_MoveHandler();
			}
			return create_RESULT_CONT();
		}
		else if ((*state).state.type == create_STATES_stm_ref1_MoveHandler().type) {
		     	if ((*state).status.type == create_STATUS_ENTER_STATE().type) {
		     		{
		     			char _s0[256];
		     			sprintf(_s0, "%s", "		Entering state MoveHandler");
		     			fprintf(log_file, "DEBUG: %s\n", _s0);
		     		}
		     		if (!(state)->en_MoveManager_MoveHandler_1_done) {
		     			RESULT_Enum _ret_;
		     			_ret_ = en_MoveManager_MoveHandler_1(state
		     			                                     , inputstate
		     			                                     , memorystate
		     			                                     , output);
		     			return _ret_;
		     		} else {
		     			(*state).status = create_STATUS_ENTER_CHILDREN();
		     			(*state).en_MoveManager_MoveHandler_1_done = false;
		     			(*state).en_MoveManager_MoveHandler_1_counter = 0;
		     			return create_RESULT_CONT();
		     		}
		     	}
		     	else if ((*state).status.type == create_STATUS_ENTER_CHILDREN().type) {
		     	     	{
		     	     		char _s0[256];
		     	     		sprintf(_s0, "%s", "		Entering children of state MoveHandler");
		     	     		fprintf(log_file, "DEBUG: %s\n", _s0);
		     	     	}
		     	     	(*state).status = create_STATUS_EXECUTE_STATE();
		     	     	{
		     	     		(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_NONE();
		     	     	}
		     	     	return create_RESULT_CONT();
		     	     }
		     	else if ((*state).status.type == create_STATUS_EXECUTE_STATE().type) {
		     	     	{
		     	     		char _s0[256];
		     	     		sprintf(_s0, "%s", "		Executing state MoveHandler");
		     	     		fprintf(log_file, "DEBUG: %s\n", _s0);
		     	     	}
		     	     	if (	(*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_NONE().type
		     	     	     ) {
		     	     		if ((inputstate)->RWMove && (inputstate)->RWMove && !(inputstate)->OAMove && !(inputstate)->CCMove) {
		     	     			(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_t0();
		     	     			(*state).status = create_STATUS_EXIT_CHILDREN();
		     	     			return create_RESULT_WAIT();
		     	     		} else if ((inputstate)->OAMove && (inputstate)->CCMove && !(inputstate)->RWMove) {
		     	     			(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_t4();
		     	     			(*state).status = create_STATUS_EXIT_CHILDREN();
		     	     			return create_RESULT_WAIT();
		     	     		} else if ((inputstate)->CCMove && (inputstate)->CCMove && !(inputstate)->OAMove) {
		     	     			(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_t2();
		     	     			(*state).status = create_STATUS_EXIT_CHILDREN();
		     	     			return create_RESULT_WAIT();
		     	     		} else if ((inputstate)->OAMove && (inputstate)->RWMove && !(inputstate)->CCMove) {
		     	     			(*inputstate)._transition_ = create_TRANSITIONS_stm_ref1_stm_ref1_t3();
		     	     			(*state).status = create_STATUS_EXIT_CHILDREN();
		     	     			return create_RESULT_WAIT();
		     	     		} else {
		     	     			return create_RESULT_WAIT();
		     	     		}
		     	     	} else {
		     	     		return create_RESULT_CONT();
		     	     	}
		     	     }
		     	else if ((*state).status.type == create_STATUS_EXIT_CHILDREN().type) {
		     	     	{
		     	     		char _s0[256];
		     	     		sprintf(_s0, "%s", "		Exiting children of state MoveHandler");
		     	     		fprintf(log_file, "DEBUG: %s\n", _s0);
		     	     	}
		     	     	(*state).status = create_STATUS_EXIT_STATE();
		     	     	return create_RESULT_CONT();
		     	     }
		     	else if ((*state).status.type == create_STATUS_EXIT_STATE().type) {
		     	     	{
		     	     		char _s0[256];
		     	     		sprintf(_s0, "%s", "		Exiting state MoveHandler");
		     	     		fprintf(log_file, "DEBUG: %s\n", _s0);
		     	     	}
		     	     	{
		     	     		if (	(*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_t0().type
		     	     		     ) {
		     	     			(*state).state = create_STATES_stm_ref1_MoveHandler();
		     	     			(*state).status = create_STATUS_ENTER_STATE();
		     	     			return create_RESULT_CONT();
		     	     		} else if (	(*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_t4().type
		     	     		            ) {
		     	     			(*state).state = create_STATES_stm_ref1_MoveHandler();
		     	     			(*state).status = create_STATUS_ENTER_STATE();
		     	     			return create_RESULT_CONT();
		     	     		} else if (	(*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_t2().type
		     	     		            ) {
		     	     			(*state).state = create_STATES_stm_ref1_MoveHandler();
		     	     			(*state).status = create_STATUS_ENTER_STATE();
		     	     			return create_RESULT_CONT();
		     	     		} else if (	(*inputstate)._transition_.type == create_TRANSITIONS_stm_ref1_stm_ref1_t3().type
		     	     		            ) {
		     	     			(*state).state = create_STATES_stm_ref1_MoveHandler();
		     	     			(*state).status = create_STATUS_ENTER_STATE();
		     	     			return create_RESULT_CONT();
		     	     		} else {
		     	     			(*state).status = create_STATUS_INACTIVE();
		     	     			(*state).state = create_STATES_stm_ref1_NONE();
		     	     			return create_RESULT_CONT();
		     	     		}
		     	     	}
		     	     }
		     	else if ((*state).status.type == create_STATUS_INACTIVE().type) {
		     	     	{
		     	     		char _s0[256];
		     	     		sprintf(_s0, "%s", "		State MoveHandler is inactive");
		     	     		fprintf(log_file, "DEBUG: %s\n", _s0);
		     	     	}
		     	     	return create_RESULT_CONT();
		     	     }
		     }
	}
	
void *stm_stm_ref1(void *arg) {
	stm_stm_ref1_Channels* channels = (stm_stm_ref1_Channels*) arg;
	stm_ref1_input_Enum_Channel* start_stm_ref1 = channels->start_stm_ref1;
	stm_ref1_output_Enum_Channel* end_stm_ref1 = channels->end_stm_ref1;
{
	// state machine variable declarations;
	struct stm_ref1_inputstate inputstate = (struct stm_ref1_inputstate) {
	                                        	.CCMove = false,
	                                        	.CCMove_value = {0.0,0.0},
	                                        	.OAMove = false,
	                                        	.OAMove_value = {0.0,0.0},
	                                        	.RWMove = false,
	                                        	.RWMove_value = {0.0,0.0},
	                                        	.Avoiding = false,
	                                        	.Avoiding_value = false,
	                                        	._transition_ = create_TRANSITIONS_stm_ref1_NONE()
	                                        };
	struct stm_ref1_state state = (struct stm_ref1_state) {
	                              	.done = false,
	                              	.state = create_STATES_stm_ref1_NONE(),
	                              	.target_state = create_STATES_stm_ref1_NONE(),
	                              	.status = create_STATUS_ENTER_STATE(),
	                              	.en_MoveManager_MoveHandler_1_done = false,
	                              	.en_MoveManager_MoveHandler_1_counter = 0
	                              };
	struct stm_ref1_memory memorystate = (struct stm_ref1_memory) {
	                                     	.cmd = {0.0,0.0},
	                                     	.NOAcmd = {0.0,0.0}
	                                     };
	// state machine loop;
	while (!(state).done) {
		{
			{
				char _s0[256];
				sprintf(_s0, "%s", "- Waiting for input on channel start_stm_ref1");
				fprintf(log_file, "DEBUG: %s\n", _s0);
			}
			bool inputDone = false;
			while (!inputDone) {
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
				if (_input_.type == stm_ref1_input_CCMove) {
					float _aux_[2];
                    _aux_[0] = _input_.data.CCMove.v1[0];
                    _aux_[1] = _input_.data.CCMove.v1[1];
					(inputstate).CCMove = true;
					(inputstate).CCMove_value[0] = _aux_[0];
                    (inputstate).CCMove_value[1] = _aux_[1];
				}
				else if (_input_.type == stm_ref1_input_OAMove) {
				     	float _aux_[2];
                        _aux_[0] = _input_.data.OAMove.v1[0];
                        _aux_[1] = _input_.data.OAMove.v1[1];
				     	(inputstate).OAMove = true;
				     	(inputstate).OAMove_value[0] = _aux_[0];
                        (inputstate).OAMove_value[1] = _aux_[1];
				     }
				else if (_input_.type == stm_ref1_input_RWMove) {
				     	float _aux_[2];
                        _aux_[0] = _input_.data.RWMove.v1[0];
                        _aux_[1] = _input_.data.RWMove.v1[1];
				     	(inputstate).RWMove = true;
				     	(inputstate).RWMove_value[0] = _aux_[0];
                        (inputstate).RWMove_value[1] = _aux_[1];
				     }
				else if (_input_.type == stm_ref1_input_Avoiding) {
				     	bool _aux_ = _input_.data.Avoiding.v1;
				     	(inputstate).Avoiding = true;
				     	(inputstate).Avoiding_value = _aux_;
				     }
				else if (_input_.type == stm_ref1_input__done_) {
				     	inputDone = true;
				     }
				else if (_input_.type == stm_ref1_input__terminate_) {
				     	inputDone = true;
				     }
			}
		}
		RESULT_Enum ret = create_RESULT_CONT();
		while (	ret.type == create_RESULT_CONT().type
		        ) {
			char* temp_;
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
		// reset input events;
		(inputstate).CCMove = false;
		(inputstate).OAMove = false;
		(inputstate).Avoiding = false;
		(inputstate).RWMove = false;
		{
			char _s0[256];
			sprintf(_s0, "%s", "		Sent output _done_ on channel end_stm_ref1");
			fprintf(log_file, "DEBUG: %s\n", _s0);
		}
		
	}
}
}


#endif