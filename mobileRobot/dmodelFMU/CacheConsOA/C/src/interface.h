#ifndef INTERFACE
#define INTERFACE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "defs.h"
#include "aux.h"

M_CacheCons_input_Enum read_input()
{
    {
        char _s0[256];
        sprintf(_s0, "%s", "Enter an event:");
        printf("%s", _s0);
    }
    char *_event_;
    char _temp_0[256];
    if (fgets(_temp_0, sizeof(_temp_0), stdin) == NULL)
        exit(0);
    _event_ = trim(_temp_0, NULL);
    if (strcmp(_event_, "") == 0)
    {
        {
            return create_M_CacheCons_input__done_();
        }
    }
    else if (strcmp(_event_, "DisableVHF") == 0)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "Found event DisableVHF");
            printf("%s\n", _s0);
        }
        {
            return create_M_CacheCons_input_DisableVHF();
        }
    }
    else if (strcmp(_event_, "CCMove") == 0)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "Found event CCMove");
            printf("%s\n", _s0);
        }
        {
            char _s0[256];
            sprintf(_s0, "%s", "Enter value for event CCMove of type vector(real, 2): ");
            printf("%s", _s0);
        }
        {
            float _value_[2] = {0.0, 0.0};
            {
                char _s0[256];
                sprintf(_s0, "%s", "Enter value for repeated vector value  of type real: ");
                printf("%s", _s0);
            }
            {
                char *_svalue_;
                char _temp_0[256];
                if (fgets(_temp_0, sizeof(_temp_0), stdin) == NULL)
                    exit(0);
                _svalue_ = trim(_temp_0, NULL);
                float _base_value_ = 0.0;
                _base_value_ = atof(_svalue_);
                _value_[0] = _base_value_;
                _value_[1] = _base_value_;
            }
            {
                return create_M_CacheCons_input_CCMove(_value_);
            }
        }
    }
    else if (strcmp(_event_, "closestDistance") == 0)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "Found event closestDistance");
            printf("%s\n", _s0);
        }
        {
            char _s0[256];
            sprintf(_s0, "%s", "Enter value for event closestDistance of type real: ");
            printf("%s", _s0);
        }
        {
            char *_svalue_;
            char _temp_0[256];
            if (fgets(_temp_0, sizeof(_temp_0), stdin) == NULL)
                exit(0);
            _svalue_ = trim(_temp_0, NULL);
            float _value_ = 0.0;
            _value_ = atof(_svalue_);
            {
                return create_M_CacheCons_input_closestDistance(_value_);
            }
        }
    }
    else if (strcmp(_event_, "EnableVHF") == 0)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "Found event EnableVHF");
            printf("%s\n", _s0);
        }
        {
            return create_M_CacheCons_input_EnableVHF();
        }
    }
    else if (strcmp(_event_, "closestAngle") == 0)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "Found event closestAngle");
            printf("%s\n", _s0);
        }
        {
            char _s0[256];
            sprintf(_s0, "%s", "Enter value for event closestAngle of type real: ");
            printf("%s", _s0);
        }
        {
            char *_svalue_;
            char _temp_0[256];
            if (fgets(_temp_0, sizeof(_temp_0), stdin) == NULL)
                exit(0);
            _svalue_ = trim(_temp_0, NULL);
            float _value_ = 0.0;
            _value_ = atof(_svalue_);
            {
                return create_M_CacheCons_input_closestAngle(_value_);
            }
        }
    }
    else if (strcmp(_event_, "EnableClusterWatch") == 0)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "Found event EnableClusterWatch");
            printf("%s\n", _s0);
        }
        {
            return create_M_CacheCons_input_EnableClusterWatch();
        }
    }
    else if (strcmp(_event_, "DisableClusterWatch") == 0)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "Found event DisableClusterWatch");
            printf("%s\n", _s0);
        }
        {
            return create_M_CacheCons_input_DisableClusterWatch();
        }
    }
    else if (strcmp(_event_, "$end") == 0)
    {
        {
            return create_M_CacheCons_input__terminate_();
        }
        {
            char _s0[256];
            sprintf(_s0, "%s", "Terminating system. One more cycle will run before this program ends.");
            printf("%s\n", _s0);
        }
    }
    else
    {
        {
            char _s0[256];
            sprintf(_s0, "%s%s", "Unknown event: ", _event_);
            printf("%s\n", _s0);
        }
        {
            return create_M_CacheCons_input__unknown_();
        }
    }
}

void write_output(M_CacheCons_output_Enum _output_)
{
    if (_output_.type == M_CacheCons_output__move)
    {
        float _aux1_[2];
        _aux1_[0] = _output_.data._move.v1[0];
        _aux1_[1] = _output_.data._move.v1[1];
        {
            char _s0[256];
            sprintf(_s0, "%s", "output move");
            printf("%s", _s0);
        }
        {
            char _s0[256];
            sprintf(_s0, "%s", "(");
            printf("%s", _s0);
        }
        {
            // compileString not yet implemented for variables of type vector;
            // printf("%s", _s0);
        }
        {
            char _s0[256];
            sprintf(_s0, "%s", ")");
            printf("%s\n", _s0);
        }
    }
    else if (_output_.type == M_CacheCons_output__done_)
    {
        {
            char _s0[256];
            sprintf(_s0, "%s", "---------------------");
            printf("%s\n", _s0);
        }
    }
}

#endif