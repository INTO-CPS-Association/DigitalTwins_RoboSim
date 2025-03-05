/*
    This file contains function definitions derived from the state machine ref1.
*/

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
    M_CacheCons_input_Enum value;
} M_CacheCons_input_Enum_Channel;
typedef struct
{
    pthread_barrier_t can_write, can_read;
    M_CacheCons_output_Enum value;
} M_CacheCons_output_Enum_Channel;

typedef struct
{
    M_CacheCons_input_Enum_Channel *start_CacheCons;
    C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0;
    M_CacheCons_output_Enum_Channel *end_CacheCons;
    C_ctrl_ref0_input_Enum_Channel *start_ctrl_ref0;
} mod_CacheCons_thread_Channels;

void mod_CacheCons_step(C_ctrl_ref0_input_Enum_Channel *start_ctrl_ref0, C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0)
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Started step of module CacheCons");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
    {
        char _s0[256];
        sprintf(_s0, "%s", "Finished step of module CacheCons");
        fprintf(log_file, "DEBUG: %s\n", _s0);
    }
}

void *mod_CacheCons_thread(void *arg)
{
    mod_CacheCons_thread_Channels *channels = (mod_CacheCons_thread_Channels *)arg;
    M_CacheCons_input_Enum_Channel *start_CacheCons = channels->start_CacheCons;
    C_ctrl_ref0_output_Enum_Channel *end_ctrl_ref0 = channels->end_ctrl_ref0;
    M_CacheCons_output_Enum_Channel *end_CacheCons = channels->end_CacheCons;
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
                        sprintf(_s0, "%s", "- Waiting for input on channel start_CacheCons");
                        fprintf(log_file, "DEBUG: %s\n", _s0);
                    }
                    M_CacheCons_input_Enum _input_;
                    {
                        pthread_barrier_wait(&start_CacheCons->can_write);
                        pthread_barrier_wait(&start_CacheCons->can_read);
                        _input_ = start_CacheCons->value;
                    }
                    {
                        char _s0[256];
                        sprintf(_s0, "%s", "- Read input on channel start_CacheCons");
                        fprintf(log_file, "DEBUG: %s\n", _s0);
                    }
                    if (_input_.type == M_CacheCons_input_EnableClusterWatch)
                    {
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input_EnableClusterWatch();
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                    }
                    else if (_input_.type == M_CacheCons_input_closestAngle)
                    {
                        float _aux1_ = _input_.data.closestAngle.v1;
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input_closestAngle(_aux1_);
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                    }
                    else if (_input_.type == M_CacheCons_input_CCMove)
                    {
                        float _aux1_[2];
                        _aux1_[0] = _input_.data.CCMove.v1[0];
                        _aux1_[1] = _input_.data.CCMove.v1[1];
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input_CCMove(_aux1_);
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                    }
                    else if (_input_.type == M_CacheCons_input_EnableVHF)
                    {
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input_EnableVHF();
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                    }
                    else if (_input_.type == M_CacheCons_input_closestDistance)
                    {
                        float _aux1_ = _input_.data.closestDistance.v1;
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input_closestDistance(_aux1_);
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                    }
                    else if (_input_.type == M_CacheCons_input_DisableVHF)
                    {
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input_DisableVHF();
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                    }
                    else if (_input_.type == M_CacheCons_input_DisableClusterWatch)
                    {
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input_DisableClusterWatch();
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                    }
                    else if (_input_.type == M_CacheCons_input__done_)
                    {
                        {
                            pthread_barrier_wait(&start_ctrl_ref0->can_write);
                            start_ctrl_ref0->value = create_C_ctrl_ref0_input__done_();
                            pthread_barrier_wait(&start_ctrl_ref0->can_read);
                        }
                        inputDone = true;
                    }
                    else if (_input_.type == M_CacheCons_input__terminate_)
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
                sprintf(_s0, "%s", "Finished reading inputs of module CacheCons");
                fprintf(log_file, "DEBUG: %s\n", _s0);
            }
            mod_CacheCons_step(start_ctrl_ref0, end_ctrl_ref0);
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
                        float _aux1_[2];
                        _aux1_[0] = _output_.data._move.v1[0];
                        _aux1_[1] = _output_.data._move.v1[1];
                        {
                            pthread_barrier_wait(&end_CacheCons->can_write);
                            end_CacheCons->value = create_M_CacheCons_output__move(_aux1_);
                            pthread_barrier_wait(&end_CacheCons->can_read);
                        }
                    }
                    else if (_output_.type == C_ctrl_ref0_output__done_)
                    {
                        outputDone = true;
                    }
                }
            }
            {
                pthread_barrier_wait(&end_CacheCons->can_write);
                end_CacheCons->value = create_M_CacheCons_output__done_();
                pthread_barrier_wait(&end_CacheCons->can_read);
            }
        }
    }
}

#endif