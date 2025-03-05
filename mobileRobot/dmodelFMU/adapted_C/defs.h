/*
	This file contains type definitions derived from the RoboSim model.
	These include both recurrent definitions such as STATUS_Enum and application specific definition such as TRANSITIONS_sm_Type.
*/

#ifndef DEFS
#define DEFS

// NEW

/* Representation of enum STATUS */

typedef enum
{
	STATUS_ENTER_STATE,
	STATUS_ENTER_CHILDREN,
	STATUS_EXECUTE_STATE,
	STATUS_EXIT_CHILDREN,
	STATUS_EXIT_STATE,
	STATUS_INACTIVE,
} STATUS_Type;

typedef union
{
} STATUS_Data;

typedef struct
{
	STATUS_Type type;
	STATUS_Data data;
} STATUS_Enum;

STATUS_Enum create_STATUS_ENTER_STATE()
{
	STATUS_Data data;

	STATUS_Type type = STATUS_ENTER_STATE;

	STATUS_Enum aux = (STATUS_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATUS_Enum create_STATUS_ENTER_CHILDREN()
{
	STATUS_Data data;

	STATUS_Type type = STATUS_ENTER_CHILDREN;

	STATUS_Enum aux = (STATUS_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATUS_Enum create_STATUS_EXECUTE_STATE()
{
	STATUS_Data data;

	STATUS_Type type = STATUS_EXECUTE_STATE;

	STATUS_Enum aux = (STATUS_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATUS_Enum create_STATUS_EXIT_CHILDREN()
{
	STATUS_Data data;

	STATUS_Type type = STATUS_EXIT_CHILDREN;

	STATUS_Enum aux = (STATUS_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATUS_Enum create_STATUS_EXIT_STATE()
{
	STATUS_Data data;

	STATUS_Type type = STATUS_EXIT_STATE;

	STATUS_Enum aux = (STATUS_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATUS_Enum create_STATUS_INACTIVE()
{
	STATUS_Data data;

	STATUS_Type type = STATUS_INACTIVE;

	STATUS_Enum aux = (STATUS_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum RESULT */

typedef enum
{
	RESULT_WAIT,
	RESULT_CONT,
} RESULT_Type;

typedef union
{
} RESULT_Data;

typedef struct
{
	RESULT_Type type;
	RESULT_Data data;
} RESULT_Enum;

RESULT_Enum create_RESULT_WAIT()
{
	RESULT_Data data;

	RESULT_Type type = RESULT_WAIT;

	RESULT_Enum aux = (RESULT_Enum){
		.type = type,
		.data = data};

	return aux;
}
RESULT_Enum create_RESULT_CONT()
{
	RESULT_Data data;

	RESULT_Type type = RESULT_CONT;

	RESULT_Enum aux = (RESULT_Enum){
		.type = type,
		.data = data};

	return aux;
}

/* Representation of enum M_CacheConsM_input */

typedef enum
{
	M_CacheConsM_input_closestDistance,
	M_CacheConsM_input_closestAngle,
	M_CacheConsM_input__done_,
	M_CacheConsM_input__terminate_,
	M_CacheConsM_input__unknown_
} M_CacheConsM_input_Type;

typedef struct
{
	float v1;
} M_CacheConsM_input_closestDistance_Data;

typedef struct
{
	float v1;
} M_CacheConsM_input_closestAngle_Data;

typedef union
{
	M_CacheConsM_input_closestDistance_Data closestDistance;
	M_CacheConsM_input_closestAngle_Data closestAngle;
} M_CacheConsM_input_Data;

typedef struct
{
	M_CacheConsM_input_Type type;
	M_CacheConsM_input_Data data;
} M_CacheConsM_input_Enum;

M_CacheConsM_input_Enum create_M_CacheConsM_input_closestDistance(float v1)
{
	M_CacheConsM_input_Data data;
	data.closestDistance.v1 = v1;

	M_CacheConsM_input_Type type = M_CacheConsM_input_closestDistance;

	M_CacheConsM_input_Enum aux = (M_CacheConsM_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheConsM_input_Enum create_M_CacheConsM_input_closestAngle(float v1)
{
	M_CacheConsM_input_Data data;
	data.closestAngle.v1 = v1;

	M_CacheConsM_input_Type type = M_CacheConsM_input_closestAngle;

	M_CacheConsM_input_Enum aux = (M_CacheConsM_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheConsM_input_Enum create_M_CacheConsM_input__unknown_()
{
	M_CacheConsM_input_Data data;

	M_CacheConsM_input_Type type = M_CacheConsM_input__unknown_;

	M_CacheConsM_input_Enum aux = (M_CacheConsM_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheConsM_input_Enum create_M_CacheConsM_input__done_()
{
	M_CacheConsM_input_Data data;

	M_CacheConsM_input_Type type = M_CacheConsM_input__done_;

	M_CacheConsM_input_Enum aux = (M_CacheConsM_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheConsM_input_Enum create_M_CacheConsM_input__terminate_()
{
	M_CacheConsM_input_Data data;

	M_CacheConsM_input_Type type = M_CacheConsM_input__terminate_;

	M_CacheConsM_input_Enum aux = (M_CacheConsM_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum M_CacheConsM_output */

typedef enum
{
	M_CacheConsM_output__move,
	M_CacheConsM_output__done_,
} M_CacheConsM_output_Type;

typedef struct
{
	float v1;
	float v2;
} M_CacheConsM_output__move_Data;

typedef union
{
	M_CacheConsM_output__move_Data _move;
} M_CacheConsM_output_Data;

typedef struct
{
	M_CacheConsM_output_Type type;
	M_CacheConsM_output_Data data;
} M_CacheConsM_output_Enum;

M_CacheConsM_output_Enum create_M_CacheConsM_output__move(float v1, float v2)
{
	M_CacheConsM_output_Data data;
	data._move.v1 = v1;
	data._move.v2 = v2;

	M_CacheConsM_output_Type type = M_CacheConsM_output__move;

	M_CacheConsM_output_Enum aux = (M_CacheConsM_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheConsM_output_Enum create_M_CacheConsM_output__done_()
{
	M_CacheConsM_output_Data data;

	M_CacheConsM_output_Type type = M_CacheConsM_output__done_;

	M_CacheConsM_output_Enum aux = (M_CacheConsM_output_Enum){
		.type = type,
		.data = data};

	return aux;
}

/* Representation of enum C_ctrl_ref0_output */

typedef enum
{
	C_ctrl_ref0_output__move,
	C_ctrl_ref0_output__done_,
} C_ctrl_ref0_output_Type;

typedef struct
{
	float v1;
	float v2;
} C_ctrl_ref0_output__move_Data;

typedef union
{
	C_ctrl_ref0_output__move_Data _move;
} C_ctrl_ref0_output_Data;

typedef struct
{
	C_ctrl_ref0_output_Type type;
	C_ctrl_ref0_output_Data data;
} C_ctrl_ref0_output_Enum;

C_ctrl_ref0_output_Enum create_C_ctrl_ref0_output__move(float v1, float v2)
{
	C_ctrl_ref0_output_Data data;
	data._move.v1 = v1;
	data._move.v2 = v2;

	C_ctrl_ref0_output_Type type = C_ctrl_ref0_output__move;

	C_ctrl_ref0_output_Enum aux = (C_ctrl_ref0_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
C_ctrl_ref0_output_Enum create_C_ctrl_ref0_output__done_()
{
	C_ctrl_ref0_output_Data data;

	C_ctrl_ref0_output_Type type = C_ctrl_ref0_output__done_;

	C_ctrl_ref0_output_Enum aux = (C_ctrl_ref0_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum C_ctrl_ref0_input */

typedef enum
{
	C_ctrl_ref0_input_closestDistance,
	C_ctrl_ref0_input_closestAngle,
	C_ctrl_ref0_input__done_,
	C_ctrl_ref0_input__terminate_,
} C_ctrl_ref0_input_Type;

typedef struct
{
	float v1;
} C_ctrl_ref0_input_closestDistance_Data;

typedef struct
{
	float v1;
} C_ctrl_ref0_input_closestAngle_Data;

typedef union
{
	C_ctrl_ref0_input_closestDistance_Data closestDistance;
	C_ctrl_ref0_input_closestAngle_Data closestAngle;
} C_ctrl_ref0_input_Data;

typedef struct
{
	C_ctrl_ref0_input_Type type;
	C_ctrl_ref0_input_Data data;
} C_ctrl_ref0_input_Enum;

C_ctrl_ref0_input_Enum create_C_ctrl_ref0_input_closestDistance(float v1)
{
	C_ctrl_ref0_input_Data data;
	data.closestDistance.v1 = v1;

	C_ctrl_ref0_input_Type type = C_ctrl_ref0_input_closestDistance;

	C_ctrl_ref0_input_Enum aux = (C_ctrl_ref0_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
C_ctrl_ref0_input_Enum create_C_ctrl_ref0_input_closestAngle(float v1)
{
	C_ctrl_ref0_input_Data data;
	data.closestAngle.v1 = v1;

	C_ctrl_ref0_input_Type type = C_ctrl_ref0_input_closestAngle;

	C_ctrl_ref0_input_Enum aux = (C_ctrl_ref0_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
C_ctrl_ref0_input_Enum create_C_ctrl_ref0_input__done_()
{
	C_ctrl_ref0_input_Data data;

	C_ctrl_ref0_input_Type type = C_ctrl_ref0_input__done_;

	C_ctrl_ref0_input_Enum aux = (C_ctrl_ref0_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
C_ctrl_ref0_input_Enum create_C_ctrl_ref0_input__terminate_()
{
	C_ctrl_ref0_input_Data data;

	C_ctrl_ref0_input_Type type = C_ctrl_ref0_input__terminate_;

	C_ctrl_ref0_input_Enum aux = (C_ctrl_ref0_input_Enum){
		.type = type,
		.data = data};

	return aux;
}

char *print_STATUS(STATUS_Enum *value)
{
	if (value->type == STATUS_ENTER_STATE)
	{
		return "ENTER_STATE";
	}
	else if (value->type == STATUS_ENTER_CHILDREN)
	{
		return "ENTER_CHILDREN";
	}
	else if (value->type == STATUS_EXECUTE_STATE)
	{
		return "EXECUTE_STATE";
	}
	else if (value->type == STATUS_EXIT_CHILDREN)
	{
		return "EXIT_CHILDREN";
	}
	else if (value->type == STATUS_EXIT_STATE)
	{
		return "EXIT_STATE";
	}
	else if (value->type == STATUS_INACTIVE)
	{
		return "INACTIVE";
	}
}

/* Representation of enum STATES_stm_ref1_Wander */

typedef enum
{
	STATES_stm_ref1_Wander_NONE,
	STATES_stm_ref1_Wander_Turn,
	STATES_stm_ref1_Wander_Move_Forward,
	STATES_stm_ref1_Wander_s0,
} STATES_stm_ref1_Wander_Type;

typedef union
{
} STATES_stm_ref1_Wander_Data;

typedef struct
{
	STATES_stm_ref1_Wander_Type type;
	STATES_stm_ref1_Wander_Data data;
} STATES_stm_ref1_Wander_Enum;

STATES_stm_ref1_Wander_Enum create_STATES_stm_ref1_Wander_NONE()
{
	STATES_stm_ref1_Wander_Data data;

	STATES_stm_ref1_Wander_Type type = STATES_stm_ref1_Wander_NONE;

	STATES_stm_ref1_Wander_Enum aux = (STATES_stm_ref1_Wander_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref1_Wander_Enum create_STATES_stm_ref1_Wander_Turn()
{
	STATES_stm_ref1_Wander_Data data;

	STATES_stm_ref1_Wander_Type type = STATES_stm_ref1_Wander_Turn;

	STATES_stm_ref1_Wander_Enum aux = (STATES_stm_ref1_Wander_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref1_Wander_Enum create_STATES_stm_ref1_Wander_Move_Forward()
{
	STATES_stm_ref1_Wander_Data data;

	STATES_stm_ref1_Wander_Type type = STATES_stm_ref1_Wander_Move_Forward;

	STATES_stm_ref1_Wander_Enum aux = (STATES_stm_ref1_Wander_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref1_Wander_Enum create_STATES_stm_ref1_Wander_s0()
{
	STATES_stm_ref1_Wander_Data data;

	STATES_stm_ref1_Wander_Type type = STATES_stm_ref1_Wander_s0;

	STATES_stm_ref1_Wander_Enum aux = (STATES_stm_ref1_Wander_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum TRANSITIONS_stm_ref1 */

typedef enum
{
	TRANSITIONS_stm_ref1_NONE,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t12,
	TRANSITIONS_stm_ref1_stm_ref1_Wander_t5,
	TRANSITIONS_stm_ref1_stm_ref1_Wander_t4,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t13,
	TRANSITIONS_stm_ref1_stm_ref1_Wander_t6,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t6,
	TRANSITIONS_stm_ref1_stm_ref1_Wander_t1,
	TRANSITIONS_stm_ref1_stm_ref1_Wander_t2,
	TRANSITIONS_stm_ref1_stm_ref1_t2,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t1,
	TRANSITIONS_stm_ref1_stm_ref1_t1,
	TRANSITIONS_stm_ref1_stm_ref1_Wander_t3,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t0,
	TRANSITIONS_stm_ref1_stm_ref1_t0,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t3,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t5,
	TRANSITIONS_stm_ref1_stm_ref1_Wander_t0,
	TRANSITIONS_stm_ref1_stm_ref1_t3,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t4,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t11,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t10,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t2,
	TRANSITIONS_stm_ref1_stm_ref1_OA_t9,
} TRANSITIONS_stm_ref1_Type;

typedef union
{
} TRANSITIONS_stm_ref1_Data;

typedef struct
{
	TRANSITIONS_stm_ref1_Type type;
	TRANSITIONS_stm_ref1_Data data;
} TRANSITIONS_stm_ref1_Enum;

TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_NONE()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_NONE;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t12()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t12;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t5()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_Wander_t5;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t4()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_Wander_t4;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t13()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t13;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t6()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_Wander_t6;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t6()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t6;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t1()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_Wander_t1;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t2()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_Wander_t2;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_t2()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_t2;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t1()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t1;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_t1()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_t1;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t3()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_Wander_t3;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t0()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t0;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_t0()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_t0;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t3()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t3;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t5()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t5;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_Wander_t0()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_Wander_t0;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_t3()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_t3;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t4()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t4;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t11()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t11;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t10()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t10;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t2()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t2;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_OA_t9()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_OA_t9;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum STATES_stm_ref1_OA */

typedef enum
{
	STATES_stm_ref1_OA_NONE,
	STATES_stm_ref1_OA_VHFEnabled,
} STATES_stm_ref1_OA_Type;

typedef union
{
} STATES_stm_ref1_OA_Data;

typedef struct
{
	STATES_stm_ref1_OA_Type type;
	STATES_stm_ref1_OA_Data data;
} STATES_stm_ref1_OA_Enum;

STATES_stm_ref1_OA_Enum create_STATES_stm_ref1_OA_NONE()
{
	STATES_stm_ref1_OA_Data data;

	STATES_stm_ref1_OA_Type type = STATES_stm_ref1_OA_NONE;

	STATES_stm_ref1_OA_Enum aux = (STATES_stm_ref1_OA_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref1_OA_Enum create_STATES_stm_ref1_OA_VHFEnabled()
{
	STATES_stm_ref1_OA_Data data;

	STATES_stm_ref1_OA_Type type = STATES_stm_ref1_OA_VHFEnabled;

	STATES_stm_ref1_OA_Enum aux = (STATES_stm_ref1_OA_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum STATES_stm_ref1 */

typedef enum
{
	STATES_stm_ref1_NONE,
	STATES_stm_ref1_Wander,
	STATES_stm_ref1_OA,
} STATES_stm_ref1_Type;

typedef union
{
} STATES_stm_ref1_Data;

typedef struct
{
	STATES_stm_ref1_Type type;
	STATES_stm_ref1_Data data;
} STATES_stm_ref1_Enum;

STATES_stm_ref1_Enum create_STATES_stm_ref1_NONE()
{
	STATES_stm_ref1_Data data;

	STATES_stm_ref1_Type type = STATES_stm_ref1_NONE;

	STATES_stm_ref1_Enum aux = (STATES_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref1_Enum create_STATES_stm_ref1_Wander()
{
	STATES_stm_ref1_Data data;

	STATES_stm_ref1_Type type = STATES_stm_ref1_Wander;

	STATES_stm_ref1_Enum aux = (STATES_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref1_Enum create_STATES_stm_ref1_OA()
{
	STATES_stm_ref1_Data data;

	STATES_stm_ref1_Type type = STATES_stm_ref1_OA;

	STATES_stm_ref1_Enum aux = (STATES_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}

/* Representation of enum stm_ref1_input */

typedef enum
{
	stm_ref1_input_closestAngle,
	stm_ref1_input_closestDistance,
	stm_ref1_input__done_,
	stm_ref1_input__terminate_,
} stm_ref1_input_Type;

typedef struct
{
	float v1;
} stm_ref1_input_closestAngle_Data;

typedef struct
{
	float v1;
} stm_ref1_input_closestDistance_Data;

typedef union
{
	stm_ref1_input_closestAngle_Data closestAngle;
	stm_ref1_input_closestDistance_Data closestDistance;
} stm_ref1_input_Data;

typedef struct
{
	stm_ref1_input_Type type;
	stm_ref1_input_Data data;
} stm_ref1_input_Enum;

stm_ref1_input_Enum create_stm_ref1_input_closestAngle(float v1)
{
	stm_ref1_input_Data data;
	data.closestAngle.v1 = v1;

	stm_ref1_input_Type type = stm_ref1_input_closestAngle;

	stm_ref1_input_Enum aux = (stm_ref1_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref1_input_Enum create_stm_ref1_input_closestDistance(float v1)
{
	stm_ref1_input_Data data;
	data.closestDistance.v1 = v1;

	stm_ref1_input_Type type = stm_ref1_input_closestDistance;

	stm_ref1_input_Enum aux = (stm_ref1_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref1_input_Enum create_stm_ref1_input__done_()
{
	stm_ref1_input_Data data;

	stm_ref1_input_Type type = stm_ref1_input__done_;

	stm_ref1_input_Enum aux = (stm_ref1_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref1_input_Enum create_stm_ref1_input__terminate_()
{
	stm_ref1_input_Data data;

	stm_ref1_input_Type type = stm_ref1_input__terminate_;

	stm_ref1_input_Enum aux = (stm_ref1_input_Enum){
		.type = type,
		.data = data};

	return aux;
}

/* Representation of enum stm_ref1_output */

typedef enum
{
	stm_ref1_output__move,
	stm_ref1_output__done_,
} stm_ref1_output_Type;

typedef struct
{
	float v1;
	float v2;
} stm_ref1_output__move_Data;

typedef union
{
	stm_ref1_output__move_Data _move;
} stm_ref1_output_Data;

typedef struct
{
	stm_ref1_output_Type type;
	stm_ref1_output_Data data;
} stm_ref1_output_Enum;

stm_ref1_output_Enum create_stm_ref1_output__move(float v1, float v2)
{
	stm_ref1_output_Data data;
	data._move.v1 = v1;
	data._move.v2 = v2;

	stm_ref1_output_Type type = stm_ref1_output__move;

	stm_ref1_output_Enum aux = (stm_ref1_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref1_output_Enum create_stm_ref1_output__done_()
{
	stm_ref1_output_Data data;

	stm_ref1_output_Type type = stm_ref1_output__done_;

	stm_ref1_output_Enum aux = (stm_ref1_output_Enum){
		.type = type,
		.data = data};

	return aux;
}

int random_sign()
{
	// Returns either 1 or -1 randomly
	return (rand() % 2 == 0) ? 1 : -1;
}
// TODO: check this; I commented because it conflicts with stdlib function;
// we may need to use a naming convention in the code generationr (__abs__())
// Also, check for the parameters of abs. Here it does not have parameters, but
// its calls have arguments.
// float abs()
// {
// 	// TODO: complete implementation
// 	return 0;
// }

#endif