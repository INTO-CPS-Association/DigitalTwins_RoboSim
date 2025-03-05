/*
    This file contains function definitions derived from the state machine ref5.
*/

#ifndef STM_REF5__H
#define STM_REF5__H
#define _POSIX_C_SOURCE 200112L

#include "defs.h"
#include "aux.h"
#include <threads.h>
#include <stdio.h>

/* Representation of record stm_ref5_Wander_state */
struct stm_ref5_Wander_state
{
    bool done;
    STATES_stm_ref5_Wander_Enum state;
    STATES_stm_ref5_Wander_Enum target_state;
    STATUS_Enum status;
    bool en_Wander_Move_Forward_1_done;
    int en_Wander_Move_Forward_1_counter;
    bool en_Wander_Turn_1_done;
    int en_Wander_Turn_1_counter;
    bool tr_RandomWalk_Wander_t2_done;
    int tr_RandomWalk_Wander_t2_counter;
    bool tr_RandomWalk_Wander_t1_done;
    int tr_RandomWalk_Wander_t1_counter;
};

/* Representation of record stm_ref5_memory */
struct stm_ref5_memory
{
    float lv;
    float av;
    float pi;
    float randcoef;
    int sign;
};

/* Representation of record stm_ref5_inputstate */
struct stm_ref5_inputstate
{
    bool EnableClusterWatch;
    bool DisableClusterWatch;
    int _clock_T;
    TRANSITIONS_stm_ref5_Enum _transition_;
};
/* Representation of record stm_ref5_state */
struct stm_ref5_state
{
    bool done;
    STATES_stm_ref5_Enum state;
    STATES_stm_ref5_Enum target_state;
    STATUS_Enum status;
    struct stm_ref5_Wander_state s_Wander;
    bool tr_RandomWalk_t2_done;
    int tr_RandomWalk_t2_counter;
    bool tr_RandomWalk_t3_done;
    int tr_RandomWalk_t3_counter;
};

typedef struct
{
    pthread_barrier_t can_write, can_read;
    stm_ref5_input_Enum value;
} stm_ref5_input_Enum_Channel;

typedef struct
{
    pthread_barrier_t can_write, can_read;
    stm_ref5_output_Enum value;
} stm_ref5_output_Enum_Channel;

typedef struct
{
    stm_ref5_input_Enum_Channel *start_stm_ref5;
    stm_ref5_output_Enum_Channel *end_stm_ref5;
} stm_stm_ref5_Channels;

char *print_STATES_stm_ref5(STATES_stm_ref5_Enum *value)
{
    if (value->type == STATES_stm_ref5_NONE)
    {
        return "NONE";
    }
    else if (value->type == STATES_stm_ref5_Wander)
    {
        return "Wander";
    }
    else if (value->type == STATES_stm_ref5_Wait)
    {
        return "Wait";
    }
}

char *print_STATES_stm_ref5_Wander(STATES_stm_ref5_Wander_Enum *value)
{
    if (value->type == STATES_stm_ref5_Wander_NONE)
    {
        return "NONE";
    }
    else if (value->type == STATES_stm_ref5_Wander_Turn)
    {
        return "Turn";
    }
    else if (value->type == STATES_stm_ref5_Wander_Move_Forward)
    {
        return "Move_Forward";
    }
}


char *print_stm_ref5_Wander_state(struct stm_ref5_Wander_state *state)
{
    char *temp1_;
    temp1_ = print_STATES_stm_ref5_Wander(&(state)->state);
    char *temp2_;
    temp2_ = print_STATUS(&(state)->status);
    // return concat(concat(concat(temp1_, " ("), temp2_), ")");
    return "";
}

char *print_stm_ref5_state(struct stm_ref5_state *state)
{
    char *temp1_;
    temp1_ = print_STATES_stm_ref5(&(state)->state);
    char *temp2_;
    temp2_ = print_STATUS(&(state)->status);
    if ((state)->state.type == STATES_stm_ref5_Wander)
    {
        char *temp_;
        temp_ = print_stm_ref5_Wander_state(&(state)->s_Wander);
        // return concat(concat(concat(concat(concat(temp1_, " ("), temp2_), ")"), " > "), temp_);
        return "";
    }
    else
    {
        // return concat(concat(concat(temp1_, " ("), temp2_), ")");
        return "";
    }
}

RESULT_Enum en_Wander_Turn_1(struct stm_ref5_Wander_state *state, struct stm_ref5_inputstate *inputstate, struct stm_ref5_memory *memory, stm_ref5_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running entry action 1 of state Wander_Turn.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->en_Wander_Turn_1_counter == 0)
    {
        (*memory).randcoef = (((float)rand()) / ((float)rand()));
        (*state).en_Wander_Turn_1_counter = 1;
        return create_RESULT_CONT();
    }
    else if ((state)->en_Wander_Turn_1_counter == 1)
    {
        {
            pthread_barrier_wait(&output->can_write);
            output->value = create_stm_ref5_output_RWMove((float[2]){((memory)->av * (memory)->sign), 0.0});
            pthread_barrier_wait(&output->can_read);
        }
        (*state).en_Wander_Turn_1_counter = 2;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->en_Wander_Turn_1_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum en_Wander_Move_Forward_1(struct stm_ref5_Wander_state *state, struct stm_ref5_inputstate *inputstate, struct stm_ref5_memory *memory, stm_ref5_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running entry action 1 of state Wander_Move_Forward.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->en_Wander_Move_Forward_1_counter == 0)
    {
        {
            pthread_barrier_wait(&output->can_write);
            output->value = create_stm_ref5_output_RWMove((float[2]){0.0, (memory)->lv});
            pthread_barrier_wait(&output->can_read);
        }
        (*state).en_Wander_Move_Forward_1_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->en_Wander_Move_Forward_1_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum tr_RandomWalk_t3(struct stm_ref5_state *state, struct stm_ref5_inputstate *inputstate, struct stm_ref5_memory *memory, stm_ref5_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition RandomWalk_t3.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_RandomWalk_t3_counter == 0)
    {
        {
            pthread_barrier_wait(&output->can_write);
            output->value = create_stm_ref5_output_RWMove((float[2]){0.0, 0.0});
            pthread_barrier_wait(&output->can_read);
        }
        (*state).tr_RandomWalk_t3_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_RandomWalk_t3_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum tr_RandomWalk_Wander_t1(struct stm_ref5_Wander_state *state, struct stm_ref5_inputstate *inputstate, struct stm_ref5_memory *memory, stm_ref5_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition RandomWalk_Wander_t1.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_RandomWalk_Wander_t1_counter == 0)
    {
        {
            pthread_barrier_wait(&output->can_write);
            output->value = create_stm_ref5_output_RWMove((float[2]){0.0, 0.0});
            pthread_barrier_wait(&output->can_read);
        }
        (*state).tr_RandomWalk_Wander_t1_counter = 1;
        return create_RESULT_CONT();
    }
    else if ((state)->tr_RandomWalk_Wander_t1_counter == 1)
    {
        (*inputstate)._clock_T = 0;
        (*state).tr_RandomWalk_Wander_t1_counter = 2;
        return create_RESULT_CONT();
    }
    else if ((state)->tr_RandomWalk_Wander_t1_counter == 2)
    {
        (*memory).randcoef = (((float)rand()) / ((float)rand()));
        (*state).tr_RandomWalk_Wander_t1_counter = 3;
        return create_RESULT_CONT();
    }
    else if ((state)->tr_RandomWalk_Wander_t1_counter == 3)
    {
        (*memory).sign = random_sign();
        ;
        (*state).tr_RandomWalk_Wander_t1_counter = 4;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_RandomWalk_Wander_t1_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum tr_RandomWalk_Wander_t2(struct stm_ref5_Wander_state *state, struct stm_ref5_inputstate *inputstate, struct stm_ref5_memory *memory, stm_ref5_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition RandomWalk_Wander_t2.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_RandomWalk_Wander_t2_counter == 0)
    {
        {
            pthread_barrier_wait(&output->can_write);
            output->value = create_stm_ref5_output_RWMove((float[2]){0.0, 0.0});
            pthread_barrier_wait(&output->can_read);
        }
        (*state).tr_RandomWalk_Wander_t2_counter = 1;
        return create_RESULT_CONT();
    }
    else if ((state)->tr_RandomWalk_Wander_t2_counter == 1)
    {
        (*inputstate)._clock_T = 0;
        (*state).tr_RandomWalk_Wander_t2_counter = 2;
        return create_RESULT_CONT();
    }
    else if ((state)->tr_RandomWalk_Wander_t2_counter == 2)
    {
        (*memory).randcoef = (((float)rand()) / ((float)rand()));
        (*state).tr_RandomWalk_Wander_t2_counter = 3;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_RandomWalk_Wander_t2_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum tr_RandomWalk_t2(struct stm_ref5_state *state, struct stm_ref5_inputstate *inputstate, struct stm_ref5_memory *memory, stm_ref5_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition RandomWalk_t2.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_RandomWalk_t2_counter == 0)
    {
        (*state).tr_RandomWalk_t2_counter = 1;
        return create_RESULT_WAIT();
    }
    else
    {
        (state)->tr_RandomWalk_t2_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum stm_stm_ref5_Wander_step(struct stm_ref5_Wander_state *state, struct stm_ref5_inputstate *inputstate, struct stm_ref5_memory *memorystate, stm_ref5_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "		Running step of state machine Wander");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((*state).state.type == create_STATES_stm_ref5_Wander_NONE().type)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "		Executing initial junction of Wander");
            fprintf(log_file, "DEBUG: %s\n", _s0);
        }
        {
            (*state).state = create_STATES_stm_ref5_Wander_Turn();
        }
        return create_RESULT_CONT();
    }
    else if ((*state).state.type == create_STATES_stm_ref5_Wander_Turn().type)
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
                (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_NONE();
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
            if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_NONE().type)
            {
                if ((inputstate)->_clock_T >= (memorystate)->randcoef)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t1();
                    (*state).status = create_STATUS_EXIT_CHILDREN();
                    return create_RESULT_WAIT();
                }
                else if ((inputstate)->_clock_T < (memorystate)->randcoef)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t4();
                    (*state).status = create_STATUS_EXIT_CHILDREN();
                    return create_RESULT_WAIT();
                }
                else
                {
                    return create_RESULT_WAIT();
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
                if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t1().type)
                {
                    if (!(state)->tr_RandomWalk_Wander_t1_done)
                    {
                        RESULT_Enum _ret_;
                        _ret_ = tr_RandomWalk_Wander_t1(state, inputstate, memorystate, output);
                        return _ret_;
                    }
                    else
                    {
                        (*state).state = create_STATES_stm_ref5_Wander_Move_Forward();
                        (*state).status = create_STATUS_ENTER_STATE();
                        (*state).tr_RandomWalk_Wander_t1_done = false;
                        (*state).tr_RandomWalk_Wander_t1_counter = 0;
                        return create_RESULT_CONT();
                    }
                }
                else if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t4().type)
                {
                    (*state).state = create_STATES_stm_ref5_Wander_Turn();
                    (*state).status = create_STATUS_ENTER_STATE();
                    return create_RESULT_CONT();
                }
                else
                {
                    (*state).status = create_STATUS_INACTIVE();
                    (*state).state = create_STATES_stm_ref5_Wander_NONE();
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
    else if ((*state).state.type == create_STATES_stm_ref5_Wander_Move_Forward().type)
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
                (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_NONE();
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
            if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_NONE().type)
            {
                if ((inputstate)->_clock_T >= (memorystate)->randcoef)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t2();
                    (*state).status = create_STATUS_EXIT_CHILDREN();
                    return create_RESULT_WAIT();
                }
                else if ((inputstate)->_clock_T < (memorystate)->randcoef)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t3();
                    (*state).status = create_STATUS_EXIT_CHILDREN();
                    return create_RESULT_WAIT();
                }
                else
                {
                    return create_RESULT_WAIT();
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
                if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t2().type)
                {
                    if (!(state)->tr_RandomWalk_Wander_t2_done)
                    {
                        RESULT_Enum _ret_;
                        _ret_ = tr_RandomWalk_Wander_t2(state, inputstate, memorystate, output);
                        return _ret_;
                    }
                    else
                    {
                        (*state).state = create_STATES_stm_ref5_Wander_Turn();
                        (*state).status = create_STATUS_ENTER_STATE();
                        (*state).tr_RandomWalk_Wander_t2_done = false;
                        (*state).tr_RandomWalk_Wander_t2_counter = 0;
                        return create_RESULT_CONT();
                    }
                }
                else if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t3().type)
                {
                    (*state).state = create_STATES_stm_ref5_Wander_Move_Forward();
                    (*state).status = create_STATUS_ENTER_STATE();
                    return create_RESULT_CONT();
                }
                else
                {
                    (*state).status = create_STATUS_INACTIVE();
                    (*state).state = create_STATES_stm_ref5_Wander_NONE();
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
}

RESULT_Enum stm_stm_ref5_step(struct stm_ref5_state *state, struct stm_ref5_inputstate *inputstate, struct stm_ref5_memory *memorystate, stm_ref5_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "		Running step of state machine RandomWalk");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((*state).state.type == create_STATES_stm_ref5_NONE().type)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "		Executing initial junction of RandomWalk");
            fprintf(log_file, "DEBUG: %s\n", _s0);
        }
        {
            (*state).state = create_STATES_stm_ref5_Wait();
        }
        return create_RESULT_CONT();
    }
    else if ((*state).state.type == create_STATES_stm_ref5_Wander().type)
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
            _ret_ = stm_stm_ref5_Wander_step(&(state)->s_Wander, inputstate, memorystate, output);
            if (((state)->s_Wander).status.type == create_STATUS_EXECUTE_STATE().type)
            {
                (*state).status = create_STATUS_EXECUTE_STATE();
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_NONE();
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
            if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_NONE().type)
            {
                if ((inputstate)->DisableClusterWatch)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_stm_ref5_t3();
                    (*state).status = create_STATUS_EXIT_CHILDREN();
                    return create_RESULT_WAIT();
                }
                else
                {
                    RESULT_Enum _ret_;
                    _ret_ = stm_stm_ref5_Wander_step(&(state)->s_Wander, inputstate, memorystate, output);
                    return _ret_;
                }
            }
            else
            {
                RESULT_Enum _ret_;
                _ret_ = stm_stm_ref5_Wander_step(&(state)->s_Wander, inputstate, memorystate, output);
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
                _ret_ = stm_stm_ref5_Wander_step(&(state)->s_Wander, inputstate, memorystate, output);
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
                if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_stm_ref5_t3().type)
                {
                    if (!(state)->tr_RandomWalk_t3_done)
                    {
                        RESULT_Enum _ret_;
                        _ret_ = tr_RandomWalk_t3(state, inputstate, memorystate, output);
                        return _ret_;
                    }
                    else
                    {
                        (*state).state = create_STATES_stm_ref5_Wait();
                        (*state).status = create_STATUS_ENTER_STATE();
                        (*state).tr_RandomWalk_t3_done = false;
                        (*state).tr_RandomWalk_t3_counter = 0;
                        return create_RESULT_CONT();
                    }
                }
                else
                {
                    (*state).status = create_STATUS_INACTIVE();
                    (*state).state = create_STATES_stm_ref5_NONE();
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
    else if ((*state).state.type == create_STATES_stm_ref5_Wait().type)
    {
        if ((*state).status.type == create_STATUS_ENTER_STATE().type)
        {
            {
                char _s0[256];
                sprintf(_s0, "%s", "		Entering state Wait");
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
                sprintf(_s0, "%s", "		Entering children of state Wait");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            (*state).status = create_STATUS_EXECUTE_STATE();
            {
                (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_NONE();
            }
            return create_RESULT_CONT();
        }
        else if ((*state).status.type == create_STATUS_EXECUTE_STATE().type)
        {
            {
                char _s0[256];
                sprintf(_s0, "%s", "		Executing state Wait");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_NONE().type)
            {
                if (!(inputstate)->EnableClusterWatch)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_stm_ref5_t1();
                    (*state).status = create_STATUS_EXIT_CHILDREN();
                    return create_RESULT_WAIT();
                }
                else if ((inputstate)->EnableClusterWatch)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref5_stm_ref5_t2();
                    (*state).status = create_STATUS_EXIT_CHILDREN();
                    return create_RESULT_CONT();
                }
                else
                {
                    return create_RESULT_WAIT();
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
                sprintf(_s0, "%s", "		Exiting children of state Wait");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            (*state).status = create_STATUS_EXIT_STATE();
            return create_RESULT_CONT();
        }
        else if ((*state).status.type == create_STATUS_EXIT_STATE().type)
        {
            {
                char _s0[256];
                sprintf(_s0, "%s", "		Exiting state Wait");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            {
                if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_stm_ref5_t1().type)
                {
                    (*state).state = create_STATES_stm_ref5_Wait();
                    (*state).status = create_STATUS_ENTER_STATE();
                    return create_RESULT_CONT();
                }
                else if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref5_stm_ref5_t2().type)
                {
                    if (!(state)->tr_RandomWalk_t2_done)
                    {
                        RESULT_Enum _ret_;
                        _ret_ = tr_RandomWalk_t2(state, inputstate, memorystate, output);
                        return _ret_;
                    }
                    else
                    {
                        (*state).state = create_STATES_stm_ref5_Wander();
                        (*state).status = create_STATUS_ENTER_STATE();
                        (*state).tr_RandomWalk_t2_done = false;
                        (*state).tr_RandomWalk_t2_counter = 0;
                        return create_RESULT_CONT();
                    }
                }
                else
                {
                    (*state).status = create_STATUS_INACTIVE();
                    (*state).state = create_STATES_stm_ref5_NONE();
                    return create_RESULT_CONT();
                }
            }
        }
        else if ((*state).status.type == create_STATUS_INACTIVE().type)
        {
            {
                char _s0[256];
                sprintf(_s0, "%s", "		State Wait is inactive");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            return create_RESULT_CONT();
        }
    }
}

void *stm_stm_ref5(void *arg)
{
    stm_stm_ref5_Channels *channels = (stm_stm_ref5_Channels *)arg;
    stm_ref5_input_Enum_Channel *start_stm_ref5 = channels->start_stm_ref5;
    stm_ref5_output_Enum_Channel *end_stm_ref5 = channels->end_stm_ref5;
    {
        // state machine variable declarations;
        struct stm_ref5_inputstate inputstate = (struct stm_ref5_inputstate){
            .EnableClusterWatch = false,
            .DisableClusterWatch = false,
            ._clock_T = 0,
            ._transition_ = create_TRANSITIONS_stm_ref5_NONE()};
        struct stm_ref5_state state = (struct stm_ref5_state){
            .done = false,
            .state = create_STATES_stm_ref5_NONE(),
            .target_state = create_STATES_stm_ref5_NONE(),
            .status = create_STATUS_ENTER_STATE(),
            .s_Wander = (struct stm_ref5_Wander_state){
                .done = false,
                .state = create_STATES_stm_ref5_Wander_NONE(),
                .target_state = create_STATES_stm_ref5_Wander_NONE(),
                .status = create_STATUS_ENTER_STATE(),
                .en_Wander_Move_Forward_1_done = false,
                .en_Wander_Move_Forward_1_counter = 0,
                .en_Wander_Turn_1_done = false,
                .en_Wander_Turn_1_counter = 0,
                .tr_RandomWalk_Wander_t2_done = false,
                .tr_RandomWalk_Wander_t2_counter = 0,
                .tr_RandomWalk_Wander_t1_done = false,
                .tr_RandomWalk_Wander_t1_counter = 0},
            .tr_RandomWalk_t2_done = false,
            .tr_RandomWalk_t2_counter = 0,
            .tr_RandomWalk_t3_done = false,
            .tr_RandomWalk_t3_counter = 0};
        struct stm_ref5_memory memorystate = (struct stm_ref5_memory){
            .lv = 0.07,
            .av = 0.6,
            .pi = 3.14159,
            .randcoef = 0.2,
            .sign = 1};
        // state machine loop;
        while (!(state).done)
        {
            {
                {
                    char _s0[256];
                    sprintf(_s0, "%s", "- Waiting for input on channel start_stm_ref5");
                    fprintf(log_file, "DEBUG: %s\n", _s0);
                }
                bool inputDone = false;
                while (!inputDone)
                {
                    stm_ref5_input_Enum _input_;
                    {
                        pthread_barrier_wait(&start_stm_ref5->can_write);
                        pthread_barrier_wait(&start_stm_ref5->can_read);
                        _input_ = start_stm_ref5->value;
                    }
                    {
                        char _s0[256];
                        sprintf(_s0, "%s", "- Read input on channel start_stm_ref5");
                        fprintf(log_file, "DEBUG: %s\n", _s0);
                    }
                    if (_input_.type == stm_ref5_input_EnableClusterWatch)
                    {
                        (inputstate).EnableClusterWatch = true;
                    }
                    else if (_input_.type == stm_ref5_input_DisableClusterWatch)
                    {
                        (inputstate).DisableClusterWatch = true;
                    }
                    else if (_input_.type == stm_ref5_input__done_)
                    {
                        inputDone = true;
                    }
                    else if (_input_.type == stm_ref5_input__terminate_)
                    {
                        inputDone = true;
                    }
                }
            }
            RESULT_Enum ret = create_RESULT_CONT();
            while (ret.type == create_RESULT_CONT().type)
            {
                char *temp_;
                temp_ = print_stm_ref5_state(&state);
                {
                    char _s0[256];
                    sprintf(_s0, "%s", temp_);
                    fprintf(log_file, "DEBUG: %s\n", _s0);
                }
                ret = stm_stm_ref5_step(&state, &inputstate, &memorystate, end_stm_ref5);
            }
            {
                pthread_barrier_wait(&end_stm_ref5->can_write);
                end_stm_ref5->value = create_stm_ref5_output__done_();
                pthread_barrier_wait(&end_stm_ref5->can_read);
            }
            // update clocks;
            (inputstate)._clock_T = ((inputstate)._clock_T + 1);
            // reset input events;
            (inputstate).EnableClusterWatch = false;
            (inputstate).DisableClusterWatch = false;
            {
                char _s0[256];
                sprintf(_s0, "%s", "		Sent output _done_ on channel end_stm_ref5");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
        }
    }
}

#endif