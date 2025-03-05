#ifndef INTERFACE
#define INTERFACE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "defs.h"
#include "aux.h"
#include "defs_fmi.h"

ModelData* fmi_data_interface;
void update_fmi_data(ModelData* comp){
  fmi_data_interface = comp;
}


M_CacheConsM_input_Enum read_input()
{
    if (fmi_data_interface->closestDistance) {
        {
            char _s0[256];
            sprintf(_s0, "%%s", "Found event closestDistance");
            printf("%%s", _s0);}
        {
            fmi_data_interface->closestDistance = false; // reset memory
            return create_M_CacheConsM_input_closestDistance(fmi_data_interface->closest_distance);
        }
    }
else if (fmi_data_interface->closestAngle) {
        {
            char _s0[256];
            sprintf(_s0, "%%s", "Found event closestAngle");
            printf("%%s", _s0);}
        {
            fmi_data_interface->closestAngle = false; // reset memory
            return create_M_CacheConsM_input_closestAngle(fmi_data_interface->closest_angle);
        }
    }
    else {
            return create_M_CacheConsM_input__done_();
    }
}

void write_output(M_CacheConsM_output_Enum _output_)
{
    if (_output_.type == M_CacheConsM_output__move) {
        {
            fmi_data_interface->move = true;
            fmi_data_interface->av= _output_.data._move.v1; // update accordingly;
            fmi_data_interface->lv = _output_.data._move.v2; // update accordingly;
        }
    }

    else if (_output_.type == M_CacheConsM_output__done_) {
    }
}

#endif