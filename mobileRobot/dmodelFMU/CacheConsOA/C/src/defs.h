/*
	This file contains type definitions derived from the RoboSim model.
	These include both recurrent definitions such as STATUS_Enum and application specific definition such as TRANSITIONS_sm_Type.
*/

#ifndef DEFS
#define DEFS

/* Representation of enum TRANSITIONS_stm_ref5 */

typedef enum
{
	TRANSITIONS_stm_ref5_NONE,
	TRANSITIONS_stm_ref5_stm_ref5_Wander_t2,
	TRANSITIONS_stm_ref5_stm_ref5_Wander_t0,
	TRANSITIONS_stm_ref5_stm_ref5_Wander_t1,
	TRANSITIONS_stm_ref5_stm_ref5_t2,
	TRANSITIONS_stm_ref5_stm_ref5_t3,
	TRANSITIONS_stm_ref5_stm_ref5_t0,
	TRANSITIONS_stm_ref5_stm_ref5_t1,
	TRANSITIONS_stm_ref5_stm_ref5_Wander_t4,
	TRANSITIONS_stm_ref5_stm_ref5_Wander_t3,
} TRANSITIONS_stm_ref5_Type;

typedef union
{
} TRANSITIONS_stm_ref5_Data;

typedef struct
{
	TRANSITIONS_stm_ref5_Type type;
	TRANSITIONS_stm_ref5_Data data;
} TRANSITIONS_stm_ref5_Enum;

TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_NONE()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_NONE;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t2()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_stm_ref5_Wander_t2;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t0()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_stm_ref5_Wander_t0;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t1()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_stm_ref5_Wander_t1;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_stm_ref5_t2()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_stm_ref5_t2;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_stm_ref5_t3()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_stm_ref5_t3;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_stm_ref5_t0()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_stm_ref5_t0;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_stm_ref5_t1()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_stm_ref5_t1;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t4()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_stm_ref5_Wander_t4;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref5_Enum create_TRANSITIONS_stm_ref5_stm_ref5_Wander_t3()
{
	TRANSITIONS_stm_ref5_Data data;

	TRANSITIONS_stm_ref5_Type type = TRANSITIONS_stm_ref5_stm_ref5_Wander_t3;

	TRANSITIONS_stm_ref5_Enum aux = (TRANSITIONS_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum STATES_stm_ref1 */

typedef enum
{
	STATES_stm_ref1_NONE,
	STATES_stm_ref1_MoveHandler,
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
STATES_stm_ref1_Enum create_STATES_stm_ref1_MoveHandler()
{
	STATES_stm_ref1_Data data;

	STATES_stm_ref1_Type type = STATES_stm_ref1_MoveHandler;

	STATES_stm_ref1_Enum aux = (STATES_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}

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
/* Representation of enum STATES_stm_ref5 */

typedef enum
{
	STATES_stm_ref5_NONE,
	STATES_stm_ref5_Wander,
	STATES_stm_ref5_Wait,
} STATES_stm_ref5_Type;

typedef union
{
} STATES_stm_ref5_Data;

typedef struct
{
	STATES_stm_ref5_Type type;
	STATES_stm_ref5_Data data;
} STATES_stm_ref5_Enum;

STATES_stm_ref5_Enum create_STATES_stm_ref5_NONE()
{
	STATES_stm_ref5_Data data;

	STATES_stm_ref5_Type type = STATES_stm_ref5_NONE;

	STATES_stm_ref5_Enum aux = (STATES_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref5_Enum create_STATES_stm_ref5_Wander()
{
	STATES_stm_ref5_Data data;

	STATES_stm_ref5_Type type = STATES_stm_ref5_Wander;

	STATES_stm_ref5_Enum aux = (STATES_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref5_Enum create_STATES_stm_ref5_Wait()
{
	STATES_stm_ref5_Data data;

	STATES_stm_ref5_Type type = STATES_stm_ref5_Wait;

	STATES_stm_ref5_Enum aux = (STATES_stm_ref5_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum TRANSITIONS_stm_ref1 */

typedef enum
{
	TRANSITIONS_stm_ref1_NONE,
	TRANSITIONS_stm_ref1_stm_ref1_t0,
	TRANSITIONS_stm_ref1_stm_ref1_t4,
	TRANSITIONS_stm_ref1_stm_ref1_t2,
	TRANSITIONS_stm_ref1_stm_ref1_t3,
	TRANSITIONS_stm_ref1_stm_ref1_t1,
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
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_t0()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_t0;

	TRANSITIONS_stm_ref1_Enum aux = (TRANSITIONS_stm_ref1_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_t4()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_t4;

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
TRANSITIONS_stm_ref1_Enum create_TRANSITIONS_stm_ref1_stm_ref1_t3()
{
	TRANSITIONS_stm_ref1_Data data;

	TRANSITIONS_stm_ref1_Type type = TRANSITIONS_stm_ref1_stm_ref1_t3;

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
/* Representation of enum stm_ref5_input */

typedef enum
{
	stm_ref5_input_EnableClusterWatch,
	stm_ref5_input_DisableClusterWatch,
	stm_ref5_input__done_,
	stm_ref5_input__terminate_,
} stm_ref5_input_Type;

typedef union
{
} stm_ref5_input_Data;

typedef struct
{
	stm_ref5_input_Type type;
	stm_ref5_input_Data data;
} stm_ref5_input_Enum;

stm_ref5_input_Enum create_stm_ref5_input_EnableClusterWatch()
{
	stm_ref5_input_Data data;

	stm_ref5_input_Type type = stm_ref5_input_EnableClusterWatch;

	stm_ref5_input_Enum aux = (stm_ref5_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref5_input_Enum create_stm_ref5_input_DisableClusterWatch()
{
	stm_ref5_input_Data data;

	stm_ref5_input_Type type = stm_ref5_input_DisableClusterWatch;

	stm_ref5_input_Enum aux = (stm_ref5_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref5_input_Enum create_stm_ref5_input__done_()
{
	stm_ref5_input_Data data;

	stm_ref5_input_Type type = stm_ref5_input__done_;

	stm_ref5_input_Enum aux = (stm_ref5_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref5_input_Enum create_stm_ref5_input__terminate_()
{
	stm_ref5_input_Data data;

	stm_ref5_input_Type type = stm_ref5_input__terminate_;

	stm_ref5_input_Enum aux = (stm_ref5_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum STATES_stm_ref2 */

typedef enum
{
	STATES_stm_ref2_NONE,
	STATES_stm_ref2_VHFEnabled,
	STATES_stm_ref2_VHFDisabled,
} STATES_stm_ref2_Type;

typedef union
{
} STATES_stm_ref2_Data;

typedef struct
{
	STATES_stm_ref2_Type type;
	STATES_stm_ref2_Data data;
} STATES_stm_ref2_Enum;

STATES_stm_ref2_Enum create_STATES_stm_ref2_NONE()
{
	STATES_stm_ref2_Data data;

	STATES_stm_ref2_Type type = STATES_stm_ref2_NONE;

	STATES_stm_ref2_Enum aux = (STATES_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref2_Enum create_STATES_stm_ref2_VHFEnabled()
{
	STATES_stm_ref2_Data data;

	STATES_stm_ref2_Type type = STATES_stm_ref2_VHFEnabled;

	STATES_stm_ref2_Enum aux = (STATES_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref2_Enum create_STATES_stm_ref2_VHFDisabled()
{
	STATES_stm_ref2_Data data;

	STATES_stm_ref2_Type type = STATES_stm_ref2_VHFDisabled;

	STATES_stm_ref2_Enum aux = (STATES_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum STATES_stm_ref5_Wander */

typedef enum
{
	STATES_stm_ref5_Wander_NONE,
	STATES_stm_ref5_Wander_Turn,
	STATES_stm_ref5_Wander_Move_Forward,
} STATES_stm_ref5_Wander_Type;

typedef union
{
} STATES_stm_ref5_Wander_Data;

typedef struct
{
	STATES_stm_ref5_Wander_Type type;
	STATES_stm_ref5_Wander_Data data;
} STATES_stm_ref5_Wander_Enum;

STATES_stm_ref5_Wander_Enum create_STATES_stm_ref5_Wander_NONE()
{
	STATES_stm_ref5_Wander_Data data;

	STATES_stm_ref5_Wander_Type type = STATES_stm_ref5_Wander_NONE;

	STATES_stm_ref5_Wander_Enum aux = (STATES_stm_ref5_Wander_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref5_Wander_Enum create_STATES_stm_ref5_Wander_Turn()
{
	STATES_stm_ref5_Wander_Data data;

	STATES_stm_ref5_Wander_Type type = STATES_stm_ref5_Wander_Turn;

	STATES_stm_ref5_Wander_Enum aux = (STATES_stm_ref5_Wander_Enum){
		.type = type,
		.data = data};

	return aux;
}
STATES_stm_ref5_Wander_Enum create_STATES_stm_ref5_Wander_Move_Forward()
{
	STATES_stm_ref5_Wander_Data data;

	STATES_stm_ref5_Wander_Type type = STATES_stm_ref5_Wander_Move_Forward;

	STATES_stm_ref5_Wander_Enum aux = (STATES_stm_ref5_Wander_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum TRANSITIONS_stm_ref2 */

typedef enum
{
	TRANSITIONS_stm_ref2_NONE,
	TRANSITIONS_stm_ref2_stm_ref2_t9,
	TRANSITIONS_stm_ref2_stm_ref2_t7,
	TRANSITIONS_stm_ref2_stm_ref2_t5,
	TRANSITIONS_stm_ref2_stm_ref2_t13,
	TRANSITIONS_stm_ref2_stm_ref2_t0,
	TRANSITIONS_stm_ref2_stm_ref2_t8,
	TRANSITIONS_stm_ref2_stm_ref2_t4,
	TRANSITIONS_stm_ref2_stm_ref2_t10,
	TRANSITIONS_stm_ref2_stm_ref2_t12,
	TRANSITIONS_stm_ref2_stm_ref2_t1,
	TRANSITIONS_stm_ref2_stm_ref2_t6,
	TRANSITIONS_stm_ref2_stm_ref2_t2,
	TRANSITIONS_stm_ref2_stm_ref2_t11,
	TRANSITIONS_stm_ref2_stm_ref2_t3,
} TRANSITIONS_stm_ref2_Type;

typedef union
{
} TRANSITIONS_stm_ref2_Data;

typedef struct
{
	TRANSITIONS_stm_ref2_Type type;
	TRANSITIONS_stm_ref2_Data data;
} TRANSITIONS_stm_ref2_Enum;

TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_NONE()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_NONE;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t9()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t9;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t7()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t7;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t5()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t5;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t13()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t13;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t0()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t0;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t8()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t8;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t4()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t4;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t10()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t10;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t12()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t12;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t1()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t1;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t6()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t6;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t2()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t2;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t11()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t11;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}
TRANSITIONS_stm_ref2_Enum create_TRANSITIONS_stm_ref2_stm_ref2_t3()
{
	TRANSITIONS_stm_ref2_Data data;

	TRANSITIONS_stm_ref2_Type type = TRANSITIONS_stm_ref2_stm_ref2_t3;

	TRANSITIONS_stm_ref2_Enum aux = (TRANSITIONS_stm_ref2_Enum){
		.type = type,
		.data = data};

	return aux;
}

/* Representation of enum M_CacheCons_input */

typedef enum
{
	M_CacheCons_input_EnableClusterWatch,
	M_CacheCons_input_closestAngle,
	M_CacheCons_input_CCMove,
	M_CacheCons_input_EnableVHF,
	M_CacheCons_input_closestDistance,
	M_CacheCons_input_DisableVHF,
	M_CacheCons_input_DisableClusterWatch,
	M_CacheCons_input__done_,
	M_CacheCons_input__terminate_,
	M_CacheCons_input__unknown_,
} M_CacheCons_input_Type;

typedef struct
{
	float v1;
} M_CacheCons_input_closestAngle_Data;

typedef struct
{
	float v1[2];
} M_CacheCons_input_CCMove_Data;

typedef struct
{
	float v1;
} M_CacheCons_input_closestDistance_Data;

typedef union
{
	M_CacheCons_input_closestAngle_Data closestAngle;
	M_CacheCons_input_CCMove_Data CCMove;
	M_CacheCons_input_closestDistance_Data closestDistance;
} M_CacheCons_input_Data;

typedef struct
{
	M_CacheCons_input_Type type;
	M_CacheCons_input_Data data;
} M_CacheCons_input_Enum;

M_CacheCons_input_Enum create_M_CacheCons_input_EnableClusterWatch()
{
	M_CacheCons_input_Data data;

	M_CacheCons_input_Type type = M_CacheCons_input_EnableClusterWatch;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheCons_input_Enum create_M_CacheCons_input_closestAngle(float v1)
{
	M_CacheCons_input_Data data;
	data.closestAngle.v1 = v1;

	M_CacheCons_input_Type type = M_CacheCons_input_closestAngle;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheCons_input_Enum create_M_CacheCons_input_CCMove(float v1[2])
{
	M_CacheCons_input_Data data;
	data.CCMove.v1[0] = v1[0];
	data.CCMove.v1[1] = v1[1];

	M_CacheCons_input_Type type = M_CacheCons_input_CCMove;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheCons_input_Enum create_M_CacheCons_input_EnableVHF()
{
	M_CacheCons_input_Data data;

	M_CacheCons_input_Type type = M_CacheCons_input_EnableVHF;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheCons_input_Enum create_M_CacheCons_input_closestDistance(float v1)
{
	M_CacheCons_input_Data data;
	data.closestDistance.v1 = v1;

	M_CacheCons_input_Type type = M_CacheCons_input_closestDistance;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheCons_input_Enum create_M_CacheCons_input_DisableVHF()
{
	M_CacheCons_input_Data data;

	M_CacheCons_input_Type type = M_CacheCons_input_DisableVHF;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheCons_input_Enum create_M_CacheCons_input_DisableClusterWatch()
{
	M_CacheCons_input_Data data;

	M_CacheCons_input_Type type = M_CacheCons_input_DisableClusterWatch;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheCons_input_Enum create_M_CacheCons_input__done_()
{
	M_CacheCons_input_Data data;

	M_CacheCons_input_Type type = M_CacheCons_input__done_;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheCons_input_Enum create_M_CacheCons_input__terminate_()
{
	M_CacheCons_input_Data data;

	M_CacheCons_input_Type type = M_CacheCons_input__terminate_;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}

M_CacheCons_input_Enum create_M_CacheCons_input__unknown_()
{
	M_CacheCons_input_Data data;

	M_CacheCons_input_Type type = M_CacheCons_input__unknown_;

	M_CacheCons_input_Enum aux = (M_CacheCons_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum M_CacheCons_output */

typedef enum
{
	M_CacheCons_output__move,
	M_CacheCons_output__done_,
} M_CacheCons_output_Type;

typedef struct
{
	float v1[2];
} M_CacheCons_output__move_Data;

typedef union
{
	M_CacheCons_output__move_Data _move;
} M_CacheCons_output_Data;

typedef struct
{
	M_CacheCons_output_Type type;
	M_CacheCons_output_Data data;
} M_CacheCons_output_Enum;

M_CacheCons_output_Enum create_M_CacheCons_output__move(float v1[2])
{
	M_CacheCons_output_Data data;
	data._move.v1[0] = v1[0];
	data._move.v1[1] = v1[1];

	M_CacheCons_output_Type type = M_CacheCons_output__move;

	M_CacheCons_output_Enum aux = (M_CacheCons_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
M_CacheCons_output_Enum create_M_CacheCons_output__done_()
{
	M_CacheCons_output_Data data;

	M_CacheCons_output_Type type = M_CacheCons_output__done_;

	M_CacheCons_output_Enum aux = (M_CacheCons_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum stm_ref1_output */

typedef enum
{
	stm_ref1_output_NOAMove,
	stm_ref1_output__move,
	stm_ref1_output__done_,
} stm_ref1_output_Type;

typedef struct
{
	float v1[2];
} stm_ref1_output_NOAMove_Data;

typedef struct
{
	float v1[2];
} stm_ref1_output__move_Data;

typedef union
{
	stm_ref1_output_NOAMove_Data NOAMove;
	stm_ref1_output__move_Data _move;
} stm_ref1_output_Data;

typedef struct
{
	stm_ref1_output_Type type;
	stm_ref1_output_Data data;
} stm_ref1_output_Enum;

stm_ref1_output_Enum create_stm_ref1_output_NOAMove(float v1[2])
{
	stm_ref1_output_Data data;
	data.NOAMove.v1[0] = v1[0];
	data.NOAMove.v1[1] = v1[1];

	stm_ref1_output_Type type = stm_ref1_output_NOAMove;

	stm_ref1_output_Enum aux = (stm_ref1_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref1_output_Enum create_stm_ref1_output__move(float v1[2])
{
	stm_ref1_output_Data data;
	data._move.v1[0] = v1[0];
	data._move.v1[1] = v1[1];

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
/* Representation of enum stm_ref2_output */

typedef enum
{
	stm_ref2_output_OAMove,
	stm_ref2_output_Avoiding,
	stm_ref2_output__done_,
} stm_ref2_output_Type;

typedef struct
{
	float v1[2];
} stm_ref2_output_OAMove_Data;

typedef struct
{
	bool v1;
} stm_ref2_output_Avoiding_Data;

typedef union
{
	stm_ref2_output_OAMove_Data OAMove;
	stm_ref2_output_Avoiding_Data Avoiding;
} stm_ref2_output_Data;

typedef struct
{
	stm_ref2_output_Type type;
	stm_ref2_output_Data data;
} stm_ref2_output_Enum;

stm_ref2_output_Enum create_stm_ref2_output_OAMove(float v1[2])
{
	stm_ref2_output_Data data;
	data.OAMove.v1[0] = v1[0];
	data.OAMove.v1[1] = v1[1];

	stm_ref2_output_Type type = stm_ref2_output_OAMove;

	stm_ref2_output_Enum aux = (stm_ref2_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref2_output_Enum create_stm_ref2_output_Avoiding(bool v1)
{
	stm_ref2_output_Data data;
	data.Avoiding.v1 = v1;

	stm_ref2_output_Type type = stm_ref2_output_Avoiding;

	stm_ref2_output_Enum aux = (stm_ref2_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref2_output_Enum create_stm_ref2_output__done_()
{
	stm_ref2_output_Data data;

	stm_ref2_output_Type type = stm_ref2_output__done_;

	stm_ref2_output_Enum aux = (stm_ref2_output_Enum){
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
	float v1[2];
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

C_ctrl_ref0_output_Enum create_C_ctrl_ref0_output__move(float v1[2])
{
	C_ctrl_ref0_output_Data data;
	data._move.v1[0] = v1[0];
	data._move.v1[1] = v1[1];

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
/* Representation of enum stm_ref1_input */

typedef enum
{
	stm_ref1_input_CCMove,
	stm_ref1_input_OAMove,
	stm_ref1_input_RWMove,
	stm_ref1_input_Avoiding,
	stm_ref1_input__done_,
	stm_ref1_input__terminate_,
} stm_ref1_input_Type;

typedef struct
{
	float v1[2];
} stm_ref1_input_CCMove_Data;

typedef struct
{
	float v1[2];
} stm_ref1_input_OAMove_Data;

typedef struct
{
	float v1[2];
} stm_ref1_input_RWMove_Data;

typedef struct
{
	bool v1;
} stm_ref1_input_Avoiding_Data;

typedef union
{
	stm_ref1_input_CCMove_Data CCMove;
	stm_ref1_input_OAMove_Data OAMove;
	stm_ref1_input_RWMove_Data RWMove;
	stm_ref1_input_Avoiding_Data Avoiding;
} stm_ref1_input_Data;

typedef struct
{
	stm_ref1_input_Type type;
	stm_ref1_input_Data data;
} stm_ref1_input_Enum;

stm_ref1_input_Enum create_stm_ref1_input_CCMove(float v1[2])
{
	stm_ref1_input_Data data;
	data.CCMove.v1[0] = v1[0];
	data.CCMove.v1[1] = v1[1];

	stm_ref1_input_Type type = stm_ref1_input_CCMove;

	stm_ref1_input_Enum aux = (stm_ref1_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref1_input_Enum create_stm_ref1_input_OAMove(float v1[2])
{
	stm_ref1_input_Data data;
	data.OAMove.v1[0] = v1[0];
	data.OAMove.v1[1] = v1[1];

	stm_ref1_input_Type type = stm_ref1_input_OAMove;

	stm_ref1_input_Enum aux = (stm_ref1_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref1_input_Enum create_stm_ref1_input_RWMove(float v1[2])
{
	stm_ref1_input_Data data;
	data.RWMove.v1[0] = v1[0];
	data.RWMove.v1[1] = v1[1];

	stm_ref1_input_Type type = stm_ref1_input_RWMove;

	stm_ref1_input_Enum aux = (stm_ref1_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref1_input_Enum create_stm_ref1_input_Avoiding(bool v1)
{
	stm_ref1_input_Data data;
	data.Avoiding.v1 = v1;

	stm_ref1_input_Type type = stm_ref1_input_Avoiding;

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
/* Representation of enum stm_ref5_output */

typedef enum
{
	stm_ref5_output_RWMove,
	stm_ref5_output__done_,
} stm_ref5_output_Type;

typedef struct
{
	float v1[2];
} stm_ref5_output_RWMove_Data;

typedef union
{
	stm_ref5_output_RWMove_Data RWMove;
} stm_ref5_output_Data;

typedef struct
{
	stm_ref5_output_Type type;
	stm_ref5_output_Data data;
} stm_ref5_output_Enum;

stm_ref5_output_Enum create_stm_ref5_output_RWMove(float v1[2])
{
	stm_ref5_output_Data data;
	data.RWMove.v1[0] = v1[0];
	data.RWMove.v1[1] = v1[1];

	stm_ref5_output_Type type = stm_ref5_output_RWMove;

	stm_ref5_output_Enum aux = (stm_ref5_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref5_output_Enum create_stm_ref5_output__done_()
{
	stm_ref5_output_Data data;

	stm_ref5_output_Type type = stm_ref5_output__done_;

	stm_ref5_output_Enum aux = (stm_ref5_output_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum stm_ref2_input */

typedef enum
{
	stm_ref2_input_DisableVHF,
	stm_ref2_input_EnableVHF,
	stm_ref2_input_NOAMove,
	stm_ref2_input_closestDistance,
	stm_ref2_input_closestAngle,
	stm_ref2_input__done_,
	stm_ref2_input__terminate_,
} stm_ref2_input_Type;

typedef struct
{
	float v1[2];
} stm_ref2_input_NOAMove_Data;

typedef struct
{
	float v1;
} stm_ref2_input_closestDistance_Data;

typedef struct
{
	float v1;
} stm_ref2_input_closestAngle_Data;

typedef union
{
	stm_ref2_input_NOAMove_Data NOAMove;
	stm_ref2_input_closestDistance_Data closestDistance;
	stm_ref2_input_closestAngle_Data closestAngle;
} stm_ref2_input_Data;

typedef struct
{
	stm_ref2_input_Type type;
	stm_ref2_input_Data data;
} stm_ref2_input_Enum;

stm_ref2_input_Enum create_stm_ref2_input_DisableVHF()
{
	stm_ref2_input_Data data;

	stm_ref2_input_Type type = stm_ref2_input_DisableVHF;

	stm_ref2_input_Enum aux = (stm_ref2_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref2_input_Enum create_stm_ref2_input_EnableVHF()
{
	stm_ref2_input_Data data;

	stm_ref2_input_Type type = stm_ref2_input_EnableVHF;

	stm_ref2_input_Enum aux = (stm_ref2_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref2_input_Enum create_stm_ref2_input_NOAMove(float v1[2])
{
	stm_ref2_input_Data data;
	data.NOAMove.v1[0] = v1[0];
	data.NOAMove.v1[1] = v1[1];

	stm_ref2_input_Type type = stm_ref2_input_NOAMove;

	stm_ref2_input_Enum aux = (stm_ref2_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref2_input_Enum create_stm_ref2_input_closestDistance(float v1)
{
	stm_ref2_input_Data data;
	data.closestDistance.v1 = v1;

	stm_ref2_input_Type type = stm_ref2_input_closestDistance;

	stm_ref2_input_Enum aux = (stm_ref2_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref2_input_Enum create_stm_ref2_input_closestAngle(float v1)
{
	stm_ref2_input_Data data;
	data.closestAngle.v1 = v1;

	stm_ref2_input_Type type = stm_ref2_input_closestAngle;

	stm_ref2_input_Enum aux = (stm_ref2_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref2_input_Enum create_stm_ref2_input__done_()
{
	stm_ref2_input_Data data;

	stm_ref2_input_Type type = stm_ref2_input__done_;

	stm_ref2_input_Enum aux = (stm_ref2_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
stm_ref2_input_Enum create_stm_ref2_input__terminate_()
{
	stm_ref2_input_Data data;

	stm_ref2_input_Type type = stm_ref2_input__terminate_;

	stm_ref2_input_Enum aux = (stm_ref2_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
/* Representation of enum C_ctrl_ref0_input */

typedef enum
{
	C_ctrl_ref0_input_DisableClusterWatch,
	C_ctrl_ref0_input_closestAngle,
	C_ctrl_ref0_input_EnableVHF,
	C_ctrl_ref0_input_CCMove,
	C_ctrl_ref0_input_EnableClusterWatch,
	C_ctrl_ref0_input_closestDistance,
	C_ctrl_ref0_input_DisableVHF,
	C_ctrl_ref0_input__done_,
	C_ctrl_ref0_input__terminate_,
} C_ctrl_ref0_input_Type;

typedef struct
{
	float v1;
} C_ctrl_ref0_input_closestAngle_Data;

typedef struct
{
	float v1[2];
} C_ctrl_ref0_input_CCMove_Data;

typedef struct
{
	float v1;
} C_ctrl_ref0_input_closestDistance_Data;

typedef union
{
	C_ctrl_ref0_input_closestAngle_Data closestAngle;
	C_ctrl_ref0_input_CCMove_Data CCMove;
	C_ctrl_ref0_input_closestDistance_Data closestDistance;
} C_ctrl_ref0_input_Data;

typedef struct
{
	C_ctrl_ref0_input_Type type;
	C_ctrl_ref0_input_Data data;
} C_ctrl_ref0_input_Enum;

C_ctrl_ref0_input_Enum create_C_ctrl_ref0_input_DisableClusterWatch()
{
	C_ctrl_ref0_input_Data data;

	C_ctrl_ref0_input_Type type = C_ctrl_ref0_input_DisableClusterWatch;

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
C_ctrl_ref0_input_Enum create_C_ctrl_ref0_input_EnableVHF()
{
	C_ctrl_ref0_input_Data data;

	C_ctrl_ref0_input_Type type = C_ctrl_ref0_input_EnableVHF;

	C_ctrl_ref0_input_Enum aux = (C_ctrl_ref0_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
C_ctrl_ref0_input_Enum create_C_ctrl_ref0_input_CCMove(float v1[2])
{
	C_ctrl_ref0_input_Data data;
	data.CCMove.v1[0] = v1[0];
	data.CCMove.v1[1] = v1[1];

	C_ctrl_ref0_input_Type type = C_ctrl_ref0_input_CCMove;

	C_ctrl_ref0_input_Enum aux = (C_ctrl_ref0_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
C_ctrl_ref0_input_Enum create_C_ctrl_ref0_input_EnableClusterWatch()
{
	C_ctrl_ref0_input_Data data;

	C_ctrl_ref0_input_Type type = C_ctrl_ref0_input_EnableClusterWatch;

	C_ctrl_ref0_input_Enum aux = (C_ctrl_ref0_input_Enum){
		.type = type,
		.data = data};

	return aux;
}
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
C_ctrl_ref0_input_Enum create_C_ctrl_ref0_input_DisableVHF()
{
	C_ctrl_ref0_input_Data data;

	C_ctrl_ref0_input_Type type = C_ctrl_ref0_input_DisableVHF;

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

#endif