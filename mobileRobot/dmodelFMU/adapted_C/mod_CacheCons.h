#ifndef MOD_CACHECONS__H
#define MOD_CACHECONS__H
#define _POSIX_C_SOURCE 200112L

#include "defs.h"
#include "aux.h"
#include <threads.h>
#include <stdio.h>
#include "conf.h"
#include "ctrl_ref0.h"

typedef struct
{
    pthread_barrier_t can_write, can_read;
    M_CacheConsM_input_Enum value;
} M_CacheConsM_input_Enum_Channel;
typedef struct
{
    pthread_barrier_t can_write, can_read;
    M_CacheConsM_output_Enum value;
} M_CacheConsM_output_Enum_Channel;

typedef struct
{
    M_CacheConsM_input_Enum_Channel *start_CacheConsM;
    C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0;
    M_CacheConsM_output_Enum_Channel *end_CacheConsM;
    C_ctrl_ref0_input_Enum_Channel *start_ctrl_ref0;
} mod_CacheConsM_thread_Channels;

void mod_CacheConsM_step(C_ctrl_ref0_input_Enum_Channel *start_ctrl_ref0, C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Started step of module CacheConsM");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    {
        char _s0[256];
        sprintf(_s0, "%s", "Finished step of module CacheConsM");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
}

void *mod_CacheConsM_thread(void *arg)
{
    mod_CacheConsM_thread_Channels *channels = (mod_CacheConsM_thread_Channels *)arg;
    M_CacheConsM_input_Enum_Channel *start_CacheConsM = channels->start_CacheConsM;
    C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0 = channels->end_ctrl_ref0;
    M_CacheConsM_output_Enum_Channel *end_CacheConsM = channels->end_CacheConsM;
    C_ctrl_ref0_input_Enum_Channel *start_ctrl_ref0 = channels->start_ctrl_ref0;
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
                        sprintf(_s0, "%s", "- Waiting for input on channel start_CacheConsM");
                        fprintf(log_file, "DEBUG: %s\n", _s0);
                    }
                    M_CacheConsM_input_Enum _input_;
                    {
                        pthread_barrier_wait(&start_CacheConsM->can_write);
                        pthread_barrier_wait(&start_CacheConsM->can_read);
                        _input_ = start_CacheConsM->value;
                    }
                    {
                        char _s0[256];
                        sprintf(_s0, "%s", "- Read input on channel start_CacheConsM");
                        fprintf(log_file, "DEBUG: %s\n", _s0);
                    }
                    if (_input_.type == M_CacheConsM_input_closestDistance)
                    {
                        float _aux1_ = _input_.data.closestDistance.v1;
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input_closestDistance(_aux1_);
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                    }
                    else if (_input_.type == M_CacheConsM_input_closestAngle)
                    {
                        float _aux1_ = _input_.data.closestAngle.v1;
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input_closestAngle(_aux1_);
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                    }
                    else if (_input_.type == M_CacheConsM_input__done_)
                    {
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input__done_();
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                        inputDone = true;
                    }
                    else if (_input_.type == M_CacheConsM_input__terminate_)
                    {
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input__terminate_();
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                        terminate__ = true;
                    }
                }
            }
            {
                char _s0[256];
                sprintf(_s0, "%s", "Finished reading inputs of module CacheConsM");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            mod_CacheConsM_step(start_ctrl_ref0, end_ctrl_ref0);
            {
                bool outputDone = false;
                while (!outputDone)
                {
                    C_ctrl_ref0_output_Enum _output_;
                    {
                        pthread_barrier_wait(&end_ctrl_ref0->can_write);
                        pthread_barrier_wait(&end_ctrl_ref0->can_read);
                        _output_ = end_ctrl_ref0->value;
                    }
                    if (_output_.type == C_ctrl_ref0_output__move)
                    {
                        float _aux1_ = _output_.data._move.v1;
                        float _aux2_ = _output_.data._move.v2;
                        {
                            pthread_barrier_wait(&end_CacheConsM->can_write);
                            end_CacheConsM->value = create_M_CacheConsM_output__move(_aux1_, _aux2_);
                            pthread_barrier_wait(&end_CacheConsM->can_read);
                        }
                    }
                    else if (_output_.type == C_ctrl_ref0_output__done_)
                    {
                        outputDone = true;
                    }
                }
            }
            {
                pthread_barrier_wait(&end_CacheConsM->can_write);
                end_CacheConsM->value = create_M_CacheConsM_output__done_();
                pthread_barrier_wait(&end_CacheConsM->can_read);
            }
        }
    }
}

#endif