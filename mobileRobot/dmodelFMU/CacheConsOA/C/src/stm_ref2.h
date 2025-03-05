/*
    This file contains function definitions derived from the state machine ref1.
*/

#ifndef STM_REF2__H
#define STM_REF2__H
#define _POSIX_C_SOURCE 200112L

#include "defs.h"
#include "aux.h"
#include <threads.h>
#include <stdio.h>

/* Representation of record stm_ref2_inputstate */
struct stm_ref2_inputstate
{
    bool DisableVHF;
    bool EnableVHF;
    bool NOAMove;
    float NOAMove_value[2];
    bool closestDistance;
    float closestDistance_value;
    bool closestAngle;
    float closestAngle_value;
    int _clock_T;
    TRANSITIONS_stm_ref2_Enum _transition_;
};

/* Representation of record stm_ref2_memory */
struct stm_ref2_memory
{
    float current_speed;
    float closest_distance;
    float max_range;
    float closest_angle;
    float av;
    float NOA_Move[2];
    float pi;
    float min_range;
    float lv;
};

/* Representation of record stm_ref2_state */
struct stm_ref2_state
{
    bool done;
    STATES_stm_ref2_Enum state;
    STATES_stm_ref2_Enum target_state;
    STATUS_Enum status;
    bool en_ObstacleAvoidance_VHFEnabled_1_done;
    int en_ObstacleAvoidance_VHFEnabled_1_counter;
    bool tr_ObstacleAvoidance_t4_done;
    int tr_ObstacleAvoidance_t4_counter;
    bool tr_ObstacleAvoidance_t10_done;
    int tr_ObstacleAvoidance_t10_counter;
    bool tr_ObstacleAvoidance_t12_done;
    int tr_ObstacleAvoidance_t12_counter;
    bool tr_ObstacleAvoidance_t1_done;
    int tr_ObstacleAvoidance_t1_counter;
    bool tr_ObstacleAvoidance_t13_done;
    int tr_ObstacleAvoidance_t13_counter;
    bool tr_ObstacleAvoidance_t6_done;
    int tr_ObstacleAvoidance_t6_counter;
    bool tr_ObstacleAvoidance_t11_done;
    int tr_ObstacleAvoidance_t11_counter;
    bool tr_ObstacleAvoidance_t0_done;
    int tr_ObstacleAvoidance_t0_counter;
    bool tr_ObstacleAvoidance_t3_done;
    int tr_ObstacleAvoidance_t3_counter;
};

typedef struct
{
    pthread_barrier_t can_write, can_read;
    stm_ref2_input_Enum value;
} stm_ref2_input_Enum_Channel;
typedef struct
{
    pthread_barrier_t can_write, can_read;
    stm_ref2_output_Enum value;
} stm_ref2_output_Enum_Channel;

typedef struct
{
    stm_ref2_input_Enum_Channel *start_stm_ref2;
    stm_ref2_output_Enum_Channel *end_stm_ref2;
} stm_stm_ref2_Channels;

RESULT_Enum ObstacleAvoidance_j0(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t13(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
RESULT_Enum en_ObstacleAvoidance_VHFEnabled_1(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t12(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t4(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t6(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
RESULT_Enum ObstacleAvoidance_j3(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t1(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
RESULT_Enum ObstacleAvoidance_j1(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t3(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
RESULT_Enum ObstacleAvoidance_j2(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t11(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t0(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
RESULT_Enum tr_ObstacleAvoidance_t10(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output);
char *print_STATES_stm_ref2(STATES_stm_ref2_Enum *value);
char *print_stm_ref2_state(struct stm_ref2_state *state);
RESULT_Enum stm_stm_ref2_step(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output);

char *print_STATES_stm_ref2(STATES_stm_ref2_Enum *value)
{
    if (value->type == STATES_stm_ref2_NONE)
    {
        return "NONE";
    }
    else if (value->type == STATES_stm_ref2_VHFEnabled)
    {
        return "VHFEnabled";
    }
    else if (value->type == STATES_stm_ref2_VHFDisabled)
    {
        return "VHFDisabled";
    }
}

char *print_stm_ref2_state(struct stm_ref2_state *state)
{
    char *temp1_;
    temp1_ = print_STATES_stm_ref2(&(state)->state);
    char *temp2_;
    temp2_ = print_STATUS(&(state)->status);
    // char* temp3_ = concat(temp1_, " (");
    // char* temp4_ = concat(temp3_, temp2_);
    // char* temp5_ = concat(temp4_, ")");

    // return temp5_;
    return "";
}

RESULT_Enum tr_ObstacleAvoidance_t10(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t10.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_ObstacleAvoidance_t10_counter == 0)
    {
        (*memory).lv = -0.4;
        (*state).tr_ObstacleAvoidance_t10_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_ObstacleAvoidance_t10_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum ObstacleAvoidance_j0(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output)
{
    if (((memorystate)->closest_angle < 30))
    {
        RESULT_Enum _ret_;
        _ret_ = ObstacleAvoidance_j2(state, inputstate, memorystate, output);
        return _ret_;
    }
    else if (((memorystate)->closest_angle <= 0))
    {
        if (!(state)->tr_ObstacleAvoidance_t4_done)
        {
            RESULT_Enum _ret_;
            _ret_ = tr_ObstacleAvoidance_t4(state, inputstate, memorystate, output);
            return _ret_;
        }
        else
        {
            (*state).state = create_STATES_stm_ref2_VHFEnabled();
            (*state).status = create_STATUS_ENTER_STATE();
            (*state).tr_ObstacleAvoidance_t4_done = false;
            (*state).tr_ObstacleAvoidance_t4_counter = 0;
            return create_RESULT_CONT();
        }
    }
    else if (((memorystate)->closest_angle > 0))
    {
        if (!(state)->tr_ObstacleAvoidance_t3_done)
        {
            RESULT_Enum _ret_;
            _ret_ = tr_ObstacleAvoidance_t3(state, inputstate, memorystate, output);
            return _ret_;
        }
        else
        {
            (*state).state = create_STATES_stm_ref2_VHFEnabled();
            (*state).status = create_STATUS_ENTER_STATE();
            (*state).tr_ObstacleAvoidance_t3_done = false;
            (*state).tr_ObstacleAvoidance_t3_counter = 0;
            return create_RESULT_CONT();
        }
    }
    else
    {
        return create_RESULT_CONT();
    }
}

RESULT_Enum tr_ObstacleAvoidance_t13(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t13.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_ObstacleAvoidance_t13_counter == 0)
    {
        (*memory).lv = 0.0;
        (*state).tr_ObstacleAvoidance_t13_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_ObstacleAvoidance_t13_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum en_ObstacleAvoidance_VHFEnabled_1(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running entry action 1 of state ObstacleAvoidance_VHFEnabled.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->en_ObstacleAvoidance_VHFEnabled_1_counter == 0)
    {
        {
            pthread_barrier_wait(&output->can_write);
            output->value = create_stm_ref2_output_OAMove((float[2]){(memory)->av, (memory)->lv});
            pthread_barrier_wait(&output->can_read);
        }
        (*state).en_ObstacleAvoidance_VHFEnabled_1_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->en_ObstacleAvoidance_VHFEnabled_1_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum tr_ObstacleAvoidance_t12(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t12.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_ObstacleAvoidance_t12_counter == 0)
    {
        (*memory).lv = ((memory)->current_speed / 2);
        (*state).tr_ObstacleAvoidance_t12_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_ObstacleAvoidance_t12_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum tr_ObstacleAvoidance_t4(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t4.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_ObstacleAvoidance_t4_counter == 0)
    {
        (*memory).av = (((((memory)->closest_angle + 100)) * (memory)->pi) / 180);
        (*state).tr_ObstacleAvoidance_t4_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_ObstacleAvoidance_t4_done = true;
        return create_RESULT_CONT();
    }
}
RESULT_Enum tr_ObstacleAvoidance_t6(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t6.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_ObstacleAvoidance_t6_counter == 0)
    {
        (*memory).lv = ((memory)->NOA_Move)[2];
        (*state).tr_ObstacleAvoidance_t6_counter = 1;
        return create_RESULT_CONT();
    }
    else if ((state)->tr_ObstacleAvoidance_t6_counter == 1)
    {
        (*memory).av = ((memory)->NOA_Move)[1];
        (*state).tr_ObstacleAvoidance_t6_counter = 2;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_ObstacleAvoidance_t6_done = true;
        return create_RESULT_CONT();
    }
}
RESULT_Enum ObstacleAvoidance_j3(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output)
{
    if (((memorystate)->closest_distance > 0.4))
    {
        if (!(state)->tr_ObstacleAvoidance_t12_done)
        {
            RESULT_Enum _ret_;
            _ret_ = tr_ObstacleAvoidance_t12(state, inputstate, memorystate, output);
            return _ret_;
        }
        else
        {
            RESULT_Enum _ret_;
            _ret_ = ObstacleAvoidance_j0(state, inputstate, memorystate, output);
            return _ret_;
        }
    }
    else if (((memorystate)->closest_distance <= 0.4))
    {
        if (!(state)->tr_ObstacleAvoidance_t13_done)
        {
            RESULT_Enum _ret_;
            _ret_ = tr_ObstacleAvoidance_t13(state, inputstate, memorystate, output);
            return _ret_;
        }
        else
        {
            RESULT_Enum _ret_;
            _ret_ = ObstacleAvoidance_j0(state, inputstate, memorystate, output);
            return _ret_;
        }
    }
    else
    {
        return create_RESULT_CONT();
    }
}
RESULT_Enum tr_ObstacleAvoidance_t1(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t1.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_ObstacleAvoidance_t1_counter == 0)
    {
        (*state).tr_ObstacleAvoidance_t1_counter = 1;
        return create_RESULT_WAIT();
    }
    else
    {
        (state)->tr_ObstacleAvoidance_t1_done = true;
        return create_RESULT_CONT();
    }
}
RESULT_Enum ObstacleAvoidance_j1(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output)
{
    if (!(((memorystate)->closest_distance >= (memorystate)->min_range) && ((memorystate)->closest_distance < (memorystate)->max_range) && (abs((memorystate)->closest_angle) <= 90)))
    {
        if (!(state)->tr_ObstacleAvoidance_t6_done)
        {
            RESULT_Enum _ret_;
            _ret_ = tr_ObstacleAvoidance_t6(state, inputstate, memorystate, output);
            return _ret_;
        }
        else
        {
            (*state).state = create_STATES_stm_ref2_VHFEnabled();
            (*state).status = create_STATUS_ENTER_STATE();
            (*state).tr_ObstacleAvoidance_t6_done = false;
            (*state).tr_ObstacleAvoidance_t6_counter = 0;
            return create_RESULT_CONT();
        }
    }
    else if (((memorystate)->closest_distance >= (memorystate)->min_range) && ((memorystate)->closest_distance < (memorystate)->max_range) && (abs((memorystate)->closest_angle) <= 90))
    {
        if (!(state)->tr_ObstacleAvoidance_t0_done)
        {
            RESULT_Enum _ret_;
            _ret_ = tr_ObstacleAvoidance_t0(state, inputstate, memorystate, output);
            return _ret_;
        }
        else
        {
            RESULT_Enum _ret_;
            _ret_ = ObstacleAvoidance_j3(state, inputstate, memorystate, output);
            return _ret_;
        }
    }
    else
    {
        return create_RESULT_CONT();
    }
}
RESULT_Enum tr_ObstacleAvoidance_t3(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t3.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_ObstacleAvoidance_t3_counter == 0)
    {
        (*memory).av = (((((memory)->closest_angle - 100)) * (memory)->pi) / 180);
        (*state).tr_ObstacleAvoidance_t3_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_ObstacleAvoidance_t3_done = true;
        return create_RESULT_CONT();
    }
}
RESULT_Enum ObstacleAvoidance_j2(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output)
{
    if (((memorystate)->closest_distance < 0.4))
    {
        if (!(state)->tr_ObstacleAvoidance_t10_done)
        {
            RESULT_Enum _ret_;
            _ret_ = tr_ObstacleAvoidance_t10(state, inputstate, memorystate, output);
            return _ret_;
        }
        else
        {
            (*state).state = create_STATES_stm_ref2_VHFEnabled();
            (*state).status = create_STATUS_ENTER_STATE();
            (*state).tr_ObstacleAvoidance_t10_done = false;
            (*state).tr_ObstacleAvoidance_t10_counter = 0;
            return create_RESULT_CONT();
        }
    }
    else if (((memorystate)->closest_distance >= 0.4))
    {
        if (!(state)->tr_ObstacleAvoidance_t11_done)
        {
            RESULT_Enum _ret_;
            _ret_ = tr_ObstacleAvoidance_t11(state, inputstate, memorystate, output);
            return _ret_;
        }
        else
        {
            (*state).state = create_STATES_stm_ref2_VHFEnabled();
            (*state).status = create_STATUS_ENTER_STATE();
            (*state).tr_ObstacleAvoidance_t11_done = false;
            (*state).tr_ObstacleAvoidance_t11_counter = 0;
            return create_RESULT_CONT();
        }
    }
    else
    {
        return create_RESULT_CONT();
    }
}
RESULT_Enum tr_ObstacleAvoidance_t11(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t11.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_ObstacleAvoidance_t11_counter == 0)
    {
        (*memory).lv = 0.0;
        (*state).tr_ObstacleAvoidance_t11_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_ObstacleAvoidance_t11_done = true;
        return create_RESULT_CONT();
    }
}
RESULT_Enum tr_ObstacleAvoidance_t0(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memory, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Running transition action of transition ObstacleAvoidance_t0.");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((state)->tr_ObstacleAvoidance_t0_counter == 0)
    {
        (*memory).current_speed = ((memory)->NOA_Move)[2];
        (*state).tr_ObstacleAvoidance_t0_counter = 1;
        return create_RESULT_CONT();
    }
    else
    {
        (state)->tr_ObstacleAvoidance_t0_done = true;
        return create_RESULT_CONT();
    }
}

RESULT_Enum stm_stm_ref2_step(struct stm_ref2_state *state, struct stm_ref2_inputstate *inputstate, struct stm_ref2_memory *memorystate, stm_ref2_output_Enum_Channel *output)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "		Running step of state machine ObstacleAvoidance");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    if ((*state).state.type == create_STATES_stm_ref2_NONE().type)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "		Executing initial junction of ObstacleAvoidance");
            fprintf(log_file, "DEBUG: %s\n", _s0);
        }
        {
            (*state).state = create_STATES_stm_ref2_VHFEnabled();
        }
        return create_RESULT_CONT();
    }
    else if ((*state).state.type == create_STATES_stm_ref2_VHFEnabled().type)
    {
        if ((*state).status.type == create_STATUS_ENTER_STATE().type)
        {
            {
                char _s0[256];
                sprintf(_s0, "%s", "		Entering state VHFEnabled");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            if (!(state)->en_ObstacleAvoidance_VHFEnabled_1_done)
            {
                RESULT_Enum _ret_;
                _ret_ = en_ObstacleAvoidance_VHFEnabled_1(state, inputstate, memorystate, output);
                return _ret_;
            }
            else
            {
                (*state).status = create_STATUS_ENTER_CHILDREN();
                (*state).en_ObstacleAvoidance_VHFEnabled_1_done = false;
                (*state).en_ObstacleAvoidance_VHFEnabled_1_counter = 0;
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
                (*inputstate)._transition_ = create_TRANSITIONS_stm_ref2_NONE();
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
            if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref2_NONE().type)
            {
                if ((inputstate)->DisableVHF)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref2_stm_ref2_t7();
                    (*state).status = create_STATUS_EXIT_CHILDREN();
                    return create_RESULT_WAIT();
                }
                else if ((inputstate)->closestAngle && (inputstate)->closestDistance && (inputstate)->NOAMove)
                {
                    (*memorystate).NOA_Move[0] = (inputstate)->NOAMove_value[0];
                    (*memorystate).NOA_Move[1] = (inputstate)->NOAMove_value[1];
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref2_stm_ref2_t5();
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
                if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref2_stm_ref2_t7().type)
                {
                    (*state).state = create_STATES_stm_ref2_VHFDisabled();
                    (*state).status = create_STATUS_ENTER_STATE();
                    return create_RESULT_CONT();
                }
                else if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref2_stm_ref2_t5().type)
                {
                    RESULT_Enum _ret_;
                    _ret_ = ObstacleAvoidance_j1(state, inputstate, memorystate, output);
                    return _ret_;
                }
                else
                {
                    (*state).status = create_STATUS_INACTIVE();
                    (*state).state = create_STATES_stm_ref2_NONE();
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
    else if ((*state).state.type == create_STATES_stm_ref2_VHFDisabled().type)
    {
        if ((*state).status.type == create_STATUS_ENTER_STATE().type)
        {
            {
                char _s0[256];
                sprintf(_s0, "%s", "		Entering state VHFDisabled");
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
                sprintf(_s0, "%s", "		Entering children of state VHFDisabled");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            (*state).status = create_STATUS_EXECUTE_STATE();
            {
                (*inputstate)._transition_ = create_TRANSITIONS_stm_ref2_NONE();
            }
            return create_RESULT_CONT();
        }
        else if ((*state).status.type == create_STATUS_EXECUTE_STATE().type)
        {
            {
                char _s0[256];
                sprintf(_s0, "%s", "		Executing state VHFDisabled");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref2_NONE().type)
            {
                if ((inputstate)->EnableVHF)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref2_stm_ref2_t8();
                    (*state).status = create_STATUS_EXIT_CHILDREN();
                    return create_RESULT_WAIT();
                }
                else if (!(inputstate)->EnableVHF)
                {
                    (*inputstate)._transition_ = create_TRANSITIONS_stm_ref2_stm_ref2_t1();
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
                sprintf(_s0, "%s", "		Exiting children of state VHFDisabled");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            (*state).status = create_STATUS_EXIT_STATE();
            return create_RESULT_CONT();
        }
        else if ((*state).status.type == create_STATUS_EXIT_STATE().type)
        {
            {
                char _s0[256];
                sprintf(_s0, "%s", "		Exiting state VHFDisabled");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            {
                if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref2_stm_ref2_t8().type)
                {
                    (*state).state = create_STATES_stm_ref2_VHFEnabled();
                    (*state).status = create_STATUS_ENTER_STATE();
                    return create_RESULT_CONT();
                }
                else if ((*inputstate)._transition_.type == create_TRANSITIONS_stm_ref2_stm_ref2_t1().type)
                {
                    if (!(state)->tr_ObstacleAvoidance_t1_done)
                    {
                        RESULT_Enum _ret_;
                        _ret_ = tr_ObstacleAvoidance_t1(state, inputstate, memorystate, output);
                        return _ret_;
                    }
                    else
                    {
                        (*state).state = create_STATES_stm_ref2_VHFDisabled();
                        (*state).status = create_STATUS_ENTER_STATE();
                        (*state).tr_ObstacleAvoidance_t1_done = false;
                        (*state).tr_ObstacleAvoidance_t1_counter = 0;
                        return create_RESULT_CONT();
                    }
                }
                else
                {
                    (*state).status = create_STATUS_INACTIVE();
                    (*state).state = create_STATES_stm_ref2_NONE();
                    return create_RESULT_CONT();
                }
            }
        }
        else if ((*state).status.type == create_STATUS_INACTIVE().type)
        {
            {
                char _s0[256];
                sprintf(_s0, "%s", "		State VHFDisabled is inactive");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            return create_RESULT_CONT();
        }
    }
}

void *stm_stm_ref2(void *arg)
{
    stm_stm_ref2_Channels *channels = (stm_stm_ref2_Channels *)arg;
    stm_ref2_input_Enum_Channel *start_stm_ref2 = channels->start_stm_ref2;
    stm_ref2_output_Enum_Channel *end_stm_ref2 = channels->end_stm_ref2;
    {
        // state machine variable declarations;
        struct stm_ref2_inputstate inputstate = (struct stm_ref2_inputstate){
            .DisableVHF = false,
            .EnableVHF = false,
            .NOAMove = false,
            .NOAMove_value = {0.0, 0.0},
            .closestDistance = false,
            .closestDistance_value = 0.0,
            .closestAngle = false,
            .closestAngle_value = 0.0,
            ._clock_T = 0,
            ._transition_ = create_TRANSITIONS_stm_ref2_NONE()};
        struct stm_ref2_state state = (struct stm_ref2_state){
            .done = false,
            .state = create_STATES_stm_ref2_NONE(),
            .target_state = create_STATES_stm_ref2_NONE(),
            .status = create_STATUS_ENTER_STATE(),
            .en_ObstacleAvoidance_VHFEnabled_1_done = false,
            .en_ObstacleAvoidance_VHFEnabled_1_counter = 0,
            .tr_ObstacleAvoidance_t4_done = false,
            .tr_ObstacleAvoidance_t4_counter = 0,
            .tr_ObstacleAvoidance_t10_done = false,
            .tr_ObstacleAvoidance_t10_counter = 0,
            .tr_ObstacleAvoidance_t12_done = false,
            .tr_ObstacleAvoidance_t12_counter = 0,
            .tr_ObstacleAvoidance_t1_done = false,
            .tr_ObstacleAvoidance_t1_counter = 0,
            .tr_ObstacleAvoidance_t13_done = false,
            .tr_ObstacleAvoidance_t13_counter = 0,
            .tr_ObstacleAvoidance_t6_done = false,
            .tr_ObstacleAvoidance_t6_counter = 0,
            .tr_ObstacleAvoidance_t11_done = false,
            .tr_ObstacleAvoidance_t11_counter = 0,
            .tr_ObstacleAvoidance_t0_done = false,
            .tr_ObstacleAvoidance_t0_counter = 0,
            .tr_ObstacleAvoidance_t3_done = false,
            .tr_ObstacleAvoidance_t3_counter = 0};
        struct stm_ref2_memory memorystate = (struct stm_ref2_memory){
            .current_speed = 0.0,
            .closest_distance = 0,
            .max_range = 0.4,
            .closest_angle = 0,
            .av = 0.7,
            .NOA_Move = {0.0, 0.0},
            .pi = 3.14159,
            .min_range = 0.1,
            .lv = 0.07};
        // state machine loop;
        while (!(state).done)
        {
            {
                {
                    char _s0[256];
                    sprintf(_s0, "%s", "- Waiting for input on channel start_stm_ref2");
                    fprintf(log_file, "DEBUG: %s\n", _s0);
                }
                bool inputDone = false;
                while (!inputDone)
                {
                    stm_ref2_input_Enum _input_;
                    {
                        pthread_barrier_wait(&start_stm_ref2->can_write);
                        pthread_barrier_wait(&start_stm_ref2->can_read);
                        _input_ = start_stm_ref2->value;
                    }
                    {
                        char _s0[256];
                        sprintf(_s0, "%s", "- Read input on channel start_stm_ref2");
                        fprintf(log_file, "DEBUG: %s\n", _s0);
                    }
                    if (_input_.type == stm_ref2_input_DisableVHF)
                    {
                        (inputstate).DisableVHF = true;
                    }
                    else if (_input_.type == stm_ref2_input_EnableVHF)
                    {
                        (inputstate).EnableVHF = true;
                    }
                    else if (_input_.type == stm_ref2_input_NOAMove)
                    {
                        float _aux_[2];
                        _aux_[0] = _input_.data.NOAMove.v1[0];
                        _aux_[1] = _input_.data.NOAMove.v1[1];
                        (inputstate).NOAMove = true;
                        (inputstate).NOAMove_value[0] = _aux_[0];
                        (inputstate).NOAMove_value[1] = _aux_[1];
                    }
                    else if (_input_.type == stm_ref2_input_closestDistance)
                    {
                        float _aux_ = _input_.data.closestDistance.v1;
                        (inputstate).closestDistance = true;
                        (inputstate).closestDistance_value = _aux_;
                    }
                    else if (_input_.type == stm_ref2_input_closestAngle)
                    {
                        float _aux_ = _input_.data.closestAngle.v1;
                        (inputstate).closestAngle = true;
                        (inputstate).closestAngle_value = _aux_;
                    }
                    else if (_input_.type == stm_ref2_input__done_)
                    {
                        inputDone = true;
                    }
                    else if (_input_.type == stm_ref2_input__terminate_)
                    {
                        inputDone = true;
                    }
                }
            }
            RESULT_Enum ret = create_RESULT_CONT();
            while (ret.type == create_RESULT_CONT().type)
            {
                char *temp_;
                temp_ = print_stm_ref2_state(&state);
                {
                    char _s0[256];
                    sprintf(_s0, "%s", temp_);
                    fprintf(log_file, "DEBUG: %s\n", _s0);
                }
                ret = stm_stm_ref2_step(&state, &inputstate, &memorystate, end_stm_ref2);
            }
            {
                pthread_barrier_wait(&end_stm_ref2->can_write);
                end_stm_ref2->value = create_stm_ref2_output__done_();
                pthread_barrier_wait(&end_stm_ref2->can_read);
            }
            // update clocks;
            (inputstate)._clock_T = ((inputstate)._clock_T + 1);
            // reset input events;
            (inputstate).EnableVHF = false;
            (inputstate).DisableVHF = false;
            (inputstate).closestDistance = false;
            (inputstate).closestAngle = false;
            (inputstate).NOAMove = false;
            {
                char _s0[256];
                sprintf(_s0, "%s", "		Sent output _done_ on channel end_stm_ref2");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
        }
    }
}

#endif