/* scc : C CODE OF EQUATIONS cruiseState - SIMULATION MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define __BASIC_ACT(i) (__CheckVariables(__cruiseState_PCheckArray[i]),(*__cruiseState_PActionArray[i])())
#define __BASIC_TEST_ACT(i)(*((__cruiseState_TAPF)(__cruiseState_PActionArray[i])))()
#ifdef TRACE_ACTION
#define __ACT(i) (fprintf(stderr, "__cruiseState_A%d\n", i),__BASIC_ACT(i))
#define __TEST_ACT(i) (fprintf(stderr, "__cruiseState_A%d\n", i),__BASIC_TEST_ACT(i))
#else
#define __ACT(i) __BASIC_ACT(i)
#define __TEST_ACT(i) __BASIC_TEST_ACT(i)
#endif
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define CSIMUL_H_LOADED
typedef struct {char text[STRLEN];} symbolic;
extern void _boolean(boolean*, boolean);
extern boolean _eq_boolean(boolean, boolean);
extern boolean _ne_boolean(boolean, boolean);
extern boolean _cond_boolean(boolean ,boolean ,boolean);
extern char* _boolean_to_text(boolean);
extern int _check_boolean(char*);
extern void _text_to_boolean(boolean*, char*);
extern void _integer(integer*, integer);
extern boolean _eq_integer(integer, integer);
extern boolean _ne_integer(integer, integer);
extern integer _cond_integer(boolean ,integer ,integer);
extern char* _integer_to_text(integer);
extern int _check_integer(char*);
extern void _text_to_integer(integer*, char*);
extern void _string(string, string);
extern boolean _eq_string(string, string);
extern boolean _ne_string(string, string);
extern string _cond_string(boolean ,string ,string);
extern char* _string_to_text(string);
extern int _check_string(char*);
extern void _text_to_string(string, char*);
extern void _float(float*, float);
extern boolean _eq_float(float, float);
extern boolean _ne_float(float, float);
extern float _cond_float(boolean ,float ,float);
extern char* _float_to_text(float);
extern int _check_float(char*);
extern void _text_to_float(float*, char*);
extern void _double(double*, double);
extern boolean _eq_double(double, double);
extern boolean _ne_double(double, double);
extern double _cond_double(boolean ,double ,double);
extern char* _double_to_text(double);
extern int _check_double(char*);
extern void _text_to_double(double*, char*);
extern void _symbolic(symbolic*, symbolic);
extern boolean _eq_symbolic(symbolic, symbolic);
extern boolean _ne_symbolic(symbolic, symbolic);
extern symbolic _cond_symbolic(boolean ,symbolic ,symbolic);
extern char* _symbolic_to_text(symbolic);
extern int _check_symbolic(char*);
extern void _text_to_symbolic(symbolic*, char*);
extern char* __PredefinedTypeToText(int, char*);
#define _true 1
#define _false 0
#define __cruiseState_GENERIC_TEST(TEST) return TEST;
typedef void (*__cruiseState_APF)();
typedef int (*__cruiseState_TAPF)();
static __cruiseState_APF *__cruiseState_PActionArray;
static int **__cruiseState_PCheckArray;
struct __SourcePoint {
int linkback;
int line;
int column;
int instance_index;
};
struct __InstanceEntry {
char *module_name;
int father_index;
char *dir_name;
char *file_name;
struct __SourcePoint source_point;
struct __SourcePoint end_point;
struct __SourcePoint instance_point;
};
struct __TaskEntry {
char *name;
int   nb_args_ref;
int   nb_args_val;
int  *type_codes_array;
struct __SourcePoint source_point;
};
struct __SignalEntry {
char *name;
int code;
int variable_index;
int present;
struct __SourcePoint source_point;
int number_of_emit_source_points;
struct __SourcePoint* emit_source_point_array;
int number_of_present_source_points;
struct __SourcePoint* present_source_point_array;
int number_of_access_source_points;
struct __SourcePoint* access_source_point_array;
};
struct __InputEntry {
char *name;
int hash;
char *type_name;
int is_a_sensor;
int type_code;
int multiple;
int signal_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ReturnEntry {
char *name;
int hash;
char *type_name;
int type_code;
int signal_index;
int exec_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ImplicationEntry {
int master;
int slave;
struct __SourcePoint source_point;
};
struct __ExclusionEntry {
int *exclusion_list;
struct __SourcePoint source_point;
};
struct __VariableEntry {
char *full_name;
char *short_name;
char *type_name;
int type_code;
int comment_kind;
int is_initialized;
char *p_variable;
char *source_name;
int written;
unsigned char written_in_transition;
unsigned char read_in_transition;
struct __SourcePoint source_point;
};
struct __ExecEntry {
int task_index;
int *var_indexes_array;
char **p_values_array;
struct __SourcePoint source_point;
};
struct __HaltEntry {
struct __SourcePoint source_point;
};
struct __NetEntry {
int known;
int value;
int number_of_source_points;
struct __SourcePoint* source_point_array;
};
struct __ModuleEntry {
char *version_id;
char *name;
int number_of_instances;
int number_of_tasks;
int number_of_signals;
int number_of_inputs;
int number_of_returns;
int number_of_sensors;
int number_of_outputs;
int number_of_locals;
int number_of_exceptions;
int number_of_implications;
int number_of_exclusions;
int number_of_variables;
int number_of_execs;
int number_of_halts;
int number_of_nets;
int number_of_states;
int state;
unsigned short *halt_list;
unsigned short *awaited_list;
unsigned short *emitted_list;
unsigned short *started_list;
unsigned short *killed_list;
unsigned short *suspended_list;
unsigned short *active_list;
int run_time_error_code;
int error_info;
void (*init)();
int (*run)();
int (*reset)();
char *(*show_variable)(int);
void (*set_variable)(int, char*, char*);
int (*check_value)(int, char*);
int (*execute_action)();
struct __InstanceEntry* instance_table;
struct __TaskEntry* task_table;
struct __SignalEntry* signal_table;
struct __InputEntry* input_table;
struct __ReturnEntry* return_table;
struct __ImplicationEntry* implication_table;
struct __ExclusionEntry* exclusion_table;
struct __VariableEntry* variable_table;
struct __ExecEntry* exec_table;
struct __HaltEntry* halt_table;
struct __NetEntry* net_table;
};

#include "cruiseControl.h"

/* EXTERN DECLARATIONS */

extern int __CheckVariables(int*);
extern void __ResetInput();
extern void __ResetExecs();
extern void __ResetVariables();
extern void __ResetVariableStatus();
extern void __AppendToList(unsigned short*, unsigned short);
extern void __ListCopy(unsigned short*, unsigned short**);
extern void __WriteVariable(int);
extern void __ResetVariable(int);
extern void __ResetModuleEntry();
extern void __ResetModuleEntryBeforeReaction();
extern void __ResetModuleEntryAfterReaction();
#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_CONSTANT_DEFINITIONS
#endif
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef _regulateThrottle_DEFINED
#ifndef regulateThrottle
extern void regulateThrottle(float* ,boolean ,float ,float);
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */
static float SpeedMin = (float)30.0;
static float SpeedMax = (float)150.0;
static float SetSpeed = (float)0.0;

/* MEMORY ALLOCATION */

static boolean __cruiseState_V0;
static boolean __cruiseState_V1;
static boolean __cruiseState_V2;
static boolean __cruiseState_V3;
static boolean __cruiseState_V4;
static boolean __cruiseState_V5;
static float __cruiseState_V6;
static boolean __cruiseState_V7;
static float __cruiseState_V8;
static boolean __cruiseState_V9;
static float __cruiseState_V10;
static boolean __cruiseState_V11;
static float __cruiseState_V12;
static float __cruiseState_V13;
static integer __cruiseState_V14;
static integer __cruiseState_V15;
static float __cruiseState_V16;
static float __cruiseState_V17;
static boolean __cruiseState_V18;

static unsigned short __cruiseState_HaltList[3];
static unsigned short __cruiseState_AwaitedList[13];
static unsigned short __cruiseState_EmittedList[13];
static unsigned short __cruiseState_StartedList[1];
static unsigned short __cruiseState_KilledList[1];
static unsigned short __cruiseState_SuspendedList[1];
static unsigned short __cruiseState_ActiveList[1];
static unsigned short __cruiseState_AllAwaitedList[13]={6,0,1,2,3,4,5};


/* INPUT FUNCTIONS */

void cruiseState_I_On () {
__cruiseState_V0 = _true;
}
void cruiseState_IS_On () {
__cruiseState_V0 = _true;
}
void cruiseState_I_Off () {
__cruiseState_V1 = _true;
}
void cruiseState_IS_Off () {
__cruiseState_V1 = _true;
}
void cruiseState_I_Resume () {
__cruiseState_V2 = _true;
}
void cruiseState_IS_Resume () {
__cruiseState_V2 = _true;
}
void cruiseState_I_Set () {
__cruiseState_V3 = _true;
}
void cruiseState_IS_Set () {
__cruiseState_V3 = _true;
}
void cruiseState_I_QuickAccel () {
__cruiseState_V4 = _true;
}
void cruiseState_IS_QuickAccel () {
__cruiseState_V4 = _true;
}
void cruiseState_I_QuickDecel () {
__cruiseState_V5 = _true;
}
void cruiseState_IS_QuickDecel () {
__cruiseState_V5 = _true;
}
static void cruiseState_I_Accel (float __V) {
__WriteVariable(6);
__cruiseState_V6 = __V;
}
static void cruiseState_IS_Accel (string __V) {
__WriteVariable(6);
_text_to_float(&__cruiseState_V6,__V);
;
}
static void cruiseState_I_Brake (float __V) {
__WriteVariable(8);
__cruiseState_V8 = __V;
}
static void cruiseState_IS_Brake (string __V) {
__WriteVariable(8);
_text_to_float(&__cruiseState_V8,__V);
;
}
static void cruiseState_I_Speed (float __V) {
__WriteVariable(10);
__cruiseState_V10 = __V;
}
static void cruiseState_IS_Speed (string __V) {
__WriteVariable(10);
_text_to_float(&__cruiseState_V10,__V);
;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int cruiseState_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __cruiseState_A1 () {
__cruiseState_GENERIC_TEST(__cruiseState_V0);
}
static int __cruiseState_Check1 [] = {1,0,0};
static int __cruiseState_A2 () {
__cruiseState_GENERIC_TEST(__cruiseState_V1);
}
static int __cruiseState_Check2 [] = {1,0,0};
static int __cruiseState_A3 () {
__cruiseState_GENERIC_TEST(__cruiseState_V2);
}
static int __cruiseState_Check3 [] = {1,0,0};
static int __cruiseState_A4 () {
__cruiseState_GENERIC_TEST(__cruiseState_V3);
}
static int __cruiseState_Check4 [] = {1,0,0};
static int __cruiseState_A5 () {
__cruiseState_GENERIC_TEST(__cruiseState_V4);
}
static int __cruiseState_Check5 [] = {1,0,0};
static int __cruiseState_A6 () {
__cruiseState_GENERIC_TEST(__cruiseState_V5);
}
static int __cruiseState_Check6 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __cruiseState_A7 () {
#ifdef __OUTPUT
cruiseState_O_CruiseSpeed(__cruiseState_V12);
#endif
__AppendToList(__cruiseState_EmittedList,9);
}
static int __cruiseState_Check7 [] = {1,0,0};
static void __cruiseState_A8 () {
#ifdef __OUTPUT
cruiseState_O_ThrottleCmd(__cruiseState_V13);
#endif
__AppendToList(__cruiseState_EmittedList,10);
}
static int __cruiseState_Check8 [] = {1,0,0};
static void __cruiseState_A9 () {
#ifdef __OUTPUT
cruiseState_O_CruiseState(__cruiseState_V14);
#endif
__AppendToList(__cruiseState_EmittedList,11);
}
static int __cruiseState_Check9 [] = {1,0,0};

/* ASSIGNMENTS */

static void __cruiseState_A10 () {
__cruiseState_V0 = _false;
}
static int __cruiseState_Check10 [] = {1,0,1,0};
static void __cruiseState_A11 () {
__cruiseState_V1 = _false;
}
static int __cruiseState_Check11 [] = {1,0,1,1};
static void __cruiseState_A12 () {
__cruiseState_V2 = _false;
}
static int __cruiseState_Check12 [] = {1,0,1,2};
static void __cruiseState_A13 () {
__cruiseState_V3 = _false;
}
static int __cruiseState_Check13 [] = {1,0,1,3};
static void __cruiseState_A14 () {
__cruiseState_V4 = _false;
}
static int __cruiseState_Check14 [] = {1,0,1,4};
static void __cruiseState_A15 () {
__cruiseState_V5 = _false;
}
static int __cruiseState_Check15 [] = {1,0,1,5};
static void __cruiseState_A16 () {
__cruiseState_V7 = _false;
}
static int __cruiseState_Check16 [] = {1,0,1,7};
static void __cruiseState_A17 () {
__cruiseState_V9 = _false;
}
static int __cruiseState_Check17 [] = {1,0,1,9};
static void __cruiseState_A18 () {
__cruiseState_V11 = _false;
}
static int __cruiseState_Check18 [] = {1,0,1,11};
static void __cruiseState_A19 () {
__cruiseState_V15 = 0;
}
static int __cruiseState_Check19 [] = {1,0,1,15};
static void __cruiseState_A20 () {
__cruiseState_V16 = (float)0.0;
}
static int __cruiseState_Check20 [] = {1,0,1,16};
static void __cruiseState_A21 () {
__cruiseState_V17 = (float)0.0;
}
static int __cruiseState_Check21 [] = {1,0,1,17};
static void __cruiseState_A22 () {
__cruiseState_V18 = _false;
}
static int __cruiseState_Check22 [] = {1,0,1,18};
static void __cruiseState_A23 () {
__cruiseState_V16 = __cruiseState_V10;
}
static int __cruiseState_Check23 [] = {1,1,10,1,16};
static void __cruiseState_A24 () {
__cruiseState_V15 = 1;
}
static int __cruiseState_Check24 [] = {1,0,1,15};
static void __cruiseState_A25 () {
__cruiseState_V14 = 1;
}
static int __cruiseState_Check25 [] = {1,0,1,14};
static void __cruiseState_A26 () {
__cruiseState_V17 = __cruiseState_V6;
}
static int __cruiseState_Check26 [] = {1,1,6,1,17};
static void __cruiseState_A27 () {
__cruiseState_V15 = 0;
}
static int __cruiseState_Check27 [] = {1,0,1,15};
static void __cruiseState_A28 () {
__cruiseState_V14 = 0;
}
static int __cruiseState_Check28 [] = {1,0,1,14};
static void __cruiseState_A29 () {
__cruiseState_V15 = 2;
}
static int __cruiseState_Check29 [] = {1,0,1,15};
static void __cruiseState_A30 () {
__cruiseState_V14 = 2;
}
static int __cruiseState_Check30 [] = {1,0,1,14};
static void __cruiseState_A31 () {
__cruiseState_V15 = 3;
}
static int __cruiseState_Check31 [] = {1,0,1,15};
static void __cruiseState_A32 () {
__cruiseState_V14 = 3;
}
static int __cruiseState_Check32 [] = {1,0,1,14};
static void __cruiseState_A33 () {
__cruiseState_V18 = _true;
}
static int __cruiseState_Check33 [] = {1,0,1,18};
static void __cruiseState_A34 () {
__cruiseState_V13 = __cruiseState_V17;
}
static int __cruiseState_Check34 [] = {1,1,17,1,13};
static void __cruiseState_A35 () {
__cruiseState_V16 = __cruiseState_V16+(float)1.0;
}
static int __cruiseState_Check35 [] = {1,1,16,1,16};
static void __cruiseState_A36 () {
__cruiseState_V18 = _true;
}
static int __cruiseState_Check36 [] = {1,0,1,18};
static void __cruiseState_A37 () {
__cruiseState_V13 = __cruiseState_V17;
}
static int __cruiseState_Check37 [] = {1,1,17,1,13};
static void __cruiseState_A38 () {
__cruiseState_V16 = __cruiseState_V16-(float)1.0;
}
static int __cruiseState_Check38 [] = {1,1,16,1,16};
static void __cruiseState_A39 () {
__cruiseState_V15 = 0;
}
static int __cruiseState_Check39 [] = {1,0,1,15};
static void __cruiseState_A40 () {
__cruiseState_V14 = 0;
}
static int __cruiseState_Check40 [] = {1,0,1,14};
static void __cruiseState_A41 () {
__cruiseState_V15 = 1;
}
static int __cruiseState_Check41 [] = {1,0,1,15};
static void __cruiseState_A42 () {
__cruiseState_V14 = 1;
}
static int __cruiseState_Check42 [] = {1,0,1,14};
static void __cruiseState_A43 () {
__cruiseState_V15 = 1;
}
static int __cruiseState_Check43 [] = {1,0,1,15};
static void __cruiseState_A44 () {
__cruiseState_V16 = __cruiseState_V10;
}
static int __cruiseState_Check44 [] = {1,1,10,1,16};
static void __cruiseState_A45 () {
__cruiseState_V14 = 1;
}
static int __cruiseState_Check45 [] = {1,0,1,14};
static void __cruiseState_A46 () {
__cruiseState_V15 = 1;
}
static int __cruiseState_Check46 [] = {1,0,1,15};
static void __cruiseState_A47 () {
__cruiseState_V14 = 1;
}
static int __cruiseState_Check47 [] = {1,0,1,14};
static void __cruiseState_A48 () {
__cruiseState_V17 = __cruiseState_V6;
}
static int __cruiseState_Check48 [] = {1,1,6,1,17};
static void __cruiseState_A49 () {
__cruiseState_V15 = 3;
}
static int __cruiseState_Check49 [] = {1,0,1,15};
static void __cruiseState_A50 () {
__cruiseState_V14 = 3;
}
static int __cruiseState_Check50 [] = {1,0,1,14};
static void __cruiseState_A51 () {
__cruiseState_V15 = 1;
}
static int __cruiseState_Check51 [] = {1,0,1,15};
static void __cruiseState_A52 () {
__cruiseState_V14 = 1;
}
static int __cruiseState_Check52 [] = {1,0,1,14};
static void __cruiseState_A53 () {
__cruiseState_V17 = __cruiseState_V6;
}
static int __cruiseState_Check53 [] = {1,1,6,1,17};
static void __cruiseState_A54 () {
__cruiseState_V13 = __cruiseState_V17;
}
static int __cruiseState_Check54 [] = {1,1,17,1,13};
static void __cruiseState_A55 () {
__cruiseState_V12 = __cruiseState_V16;
}
static int __cruiseState_Check55 [] = {1,1,16,1,12};

/* PROCEDURE CALLS */

static void __cruiseState_A56 () {
regulateThrottle(&__cruiseState_V17,__cruiseState_V18,__cruiseState_V16+(float)1.0,__cruiseState_V10);
}
static int __cruiseState_Check56 [] = {1,3,18,16,10,1,17};
static void __cruiseState_A57 () {
regulateThrottle(&__cruiseState_V17,__cruiseState_V18,__cruiseState_V16-(float)1.0,__cruiseState_V10);
}
static int __cruiseState_Check57 [] = {1,3,18,16,10,1,17};

/* CONDITIONS */

static int __cruiseState_A58 () {
__cruiseState_GENERIC_TEST(__cruiseState_V15==0);
}
static int __cruiseState_Check58 [] = {1,1,15,0};
static int __cruiseState_A59 () {
__cruiseState_GENERIC_TEST((__cruiseState_V6<(float)3.0)&&(__cruiseState_V10>=SpeedMin)&&(__cruiseState_V10<=SpeedMax));
}
static int __cruiseState_Check59 [] = {1,3,6,10,10,0};
static int __cruiseState_A60 () {
__cruiseState_GENERIC_TEST(__cruiseState_V15==1);
}
static int __cruiseState_Check60 [] = {1,1,15,0};
static int __cruiseState_A61 () {
__cruiseState_GENERIC_TEST(__cruiseState_V8>=(float)3.0);
}
static int __cruiseState_Check61 [] = {1,1,8,0};
static int __cruiseState_A62 () {
__cruiseState_GENERIC_TEST(__cruiseState_V6>=(float)3.0);
}
static int __cruiseState_Check62 [] = {1,1,6,0};
static int __cruiseState_A63 () {
__cruiseState_GENERIC_TEST(__cruiseState_V15==1);
}
static int __cruiseState_Check63 [] = {1,1,15,0};
static int __cruiseState_A64 () {
__cruiseState_GENERIC_TEST(__cruiseState_V15==1);
}
static int __cruiseState_Check64 [] = {1,1,15,0};
static int __cruiseState_A65 () {
__cruiseState_GENERIC_TEST(__cruiseState_V15==3);
}
static int __cruiseState_Check65 [] = {1,1,15,0};
static int __cruiseState_A66 () {
__cruiseState_GENERIC_TEST((__cruiseState_V6<(float)3.0)&&(__cruiseState_V10>=SpeedMin)&&(__cruiseState_V10<=SpeedMax));
}
static int __cruiseState_Check66 [] = {1,3,6,10,10,0};
static int __cruiseState_A67 () {
__cruiseState_GENERIC_TEST(__cruiseState_V15==2);
}
static int __cruiseState_Check67 [] = {1,1,15,0};
static int __cruiseState_A68 () {
__cruiseState_GENERIC_TEST((__cruiseState_V6>=(float)3.0)||(__cruiseState_V10<=SpeedMin)||(__cruiseState_V10>=SpeedMax));
}
static int __cruiseState_Check68 [] = {1,3,6,10,10,0};
static int __cruiseState_A69 () {
__cruiseState_GENERIC_TEST((__cruiseState_V6<(float)3.0)&&(__cruiseState_V10>=SpeedMin)&&(__cruiseState_V10<=SpeedMax));
}
static int __cruiseState_Check69 [] = {1,3,6,10,10,0};

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __cruiseState_A70 () {
;
__ResetVariable(12);
}
static int __cruiseState_Check70 [] = {1,0,0};
static void __cruiseState_A71 () {
;
__ResetVariable(13);
}
static int __cruiseState_Check71 [] = {1,0,0};
static void __cruiseState_A72 () {
;
__ResetVariable(14);
}
static int __cruiseState_Check72 [] = {1,0,0};
static void __cruiseState_A73 () {
;
__ResetVariable(15);
}
static int __cruiseState_Check73 [] = {1,0,0};
static void __cruiseState_A74 () {
;
__ResetVariable(16);
}
static int __cruiseState_Check74 [] = {1,0,0};
static void __cruiseState_A75 () {
;
__ResetVariable(17);
}
static int __cruiseState_Check75 [] = {1,0,0};
static void __cruiseState_A76 () {
;
__ResetVariable(18);
}
static int __cruiseState_Check76 [] = {1,0,0};

/* ACTION SEQUENCES */

/* THE ACTION ARRAY */

static __cruiseState_APF __cruiseState_ActionArray[] = {
0,
(__cruiseState_APF)__cruiseState_A1,
(__cruiseState_APF)__cruiseState_A2,
(__cruiseState_APF)__cruiseState_A3,
(__cruiseState_APF)__cruiseState_A4,
(__cruiseState_APF)__cruiseState_A5,
(__cruiseState_APF)__cruiseState_A6,
(__cruiseState_APF)__cruiseState_A7,
(__cruiseState_APF)__cruiseState_A8,
(__cruiseState_APF)__cruiseState_A9,
(__cruiseState_APF)__cruiseState_A10,
(__cruiseState_APF)__cruiseState_A11,
(__cruiseState_APF)__cruiseState_A12,
(__cruiseState_APF)__cruiseState_A13,
(__cruiseState_APF)__cruiseState_A14,
(__cruiseState_APF)__cruiseState_A15,
(__cruiseState_APF)__cruiseState_A16,
(__cruiseState_APF)__cruiseState_A17,
(__cruiseState_APF)__cruiseState_A18,
(__cruiseState_APF)__cruiseState_A19,
(__cruiseState_APF)__cruiseState_A20,
(__cruiseState_APF)__cruiseState_A21,
(__cruiseState_APF)__cruiseState_A22,
(__cruiseState_APF)__cruiseState_A23,
(__cruiseState_APF)__cruiseState_A24,
(__cruiseState_APF)__cruiseState_A25,
(__cruiseState_APF)__cruiseState_A26,
(__cruiseState_APF)__cruiseState_A27,
(__cruiseState_APF)__cruiseState_A28,
(__cruiseState_APF)__cruiseState_A29,
(__cruiseState_APF)__cruiseState_A30,
(__cruiseState_APF)__cruiseState_A31,
(__cruiseState_APF)__cruiseState_A32,
(__cruiseState_APF)__cruiseState_A33,
(__cruiseState_APF)__cruiseState_A34,
(__cruiseState_APF)__cruiseState_A35,
(__cruiseState_APF)__cruiseState_A36,
(__cruiseState_APF)__cruiseState_A37,
(__cruiseState_APF)__cruiseState_A38,
(__cruiseState_APF)__cruiseState_A39,
(__cruiseState_APF)__cruiseState_A40,
(__cruiseState_APF)__cruiseState_A41,
(__cruiseState_APF)__cruiseState_A42,
(__cruiseState_APF)__cruiseState_A43,
(__cruiseState_APF)__cruiseState_A44,
(__cruiseState_APF)__cruiseState_A45,
(__cruiseState_APF)__cruiseState_A46,
(__cruiseState_APF)__cruiseState_A47,
(__cruiseState_APF)__cruiseState_A48,
(__cruiseState_APF)__cruiseState_A49,
(__cruiseState_APF)__cruiseState_A50,
(__cruiseState_APF)__cruiseState_A51,
(__cruiseState_APF)__cruiseState_A52,
(__cruiseState_APF)__cruiseState_A53,
(__cruiseState_APF)__cruiseState_A54,
(__cruiseState_APF)__cruiseState_A55,
(__cruiseState_APF)__cruiseState_A56,
(__cruiseState_APF)__cruiseState_A57,
(__cruiseState_APF)__cruiseState_A58,
(__cruiseState_APF)__cruiseState_A59,
(__cruiseState_APF)__cruiseState_A60,
(__cruiseState_APF)__cruiseState_A61,
(__cruiseState_APF)__cruiseState_A62,
(__cruiseState_APF)__cruiseState_A63,
(__cruiseState_APF)__cruiseState_A64,
(__cruiseState_APF)__cruiseState_A65,
(__cruiseState_APF)__cruiseState_A66,
(__cruiseState_APF)__cruiseState_A67,
(__cruiseState_APF)__cruiseState_A68,
(__cruiseState_APF)__cruiseState_A69,
(__cruiseState_APF)__cruiseState_A70,
(__cruiseState_APF)__cruiseState_A71,
(__cruiseState_APF)__cruiseState_A72,
(__cruiseState_APF)__cruiseState_A73,
(__cruiseState_APF)__cruiseState_A74,
(__cruiseState_APF)__cruiseState_A75,
(__cruiseState_APF)__cruiseState_A76
};
static __cruiseState_APF *__cruiseState_PActionArray  = __cruiseState_ActionArray;

static int *__cruiseState_CheckArray[] = {
0,
__cruiseState_Check1,
__cruiseState_Check2,
__cruiseState_Check3,
__cruiseState_Check4,
__cruiseState_Check5,
__cruiseState_Check6,
__cruiseState_Check7,
__cruiseState_Check8,
__cruiseState_Check9,
__cruiseState_Check10,
__cruiseState_Check11,
__cruiseState_Check12,
__cruiseState_Check13,
__cruiseState_Check14,
__cruiseState_Check15,
__cruiseState_Check16,
__cruiseState_Check17,
__cruiseState_Check18,
__cruiseState_Check19,
__cruiseState_Check20,
__cruiseState_Check21,
__cruiseState_Check22,
__cruiseState_Check23,
__cruiseState_Check24,
__cruiseState_Check25,
__cruiseState_Check26,
__cruiseState_Check27,
__cruiseState_Check28,
__cruiseState_Check29,
__cruiseState_Check30,
__cruiseState_Check31,
__cruiseState_Check32,
__cruiseState_Check33,
__cruiseState_Check34,
__cruiseState_Check35,
__cruiseState_Check36,
__cruiseState_Check37,
__cruiseState_Check38,
__cruiseState_Check39,
__cruiseState_Check40,
__cruiseState_Check41,
__cruiseState_Check42,
__cruiseState_Check43,
__cruiseState_Check44,
__cruiseState_Check45,
__cruiseState_Check46,
__cruiseState_Check47,
__cruiseState_Check48,
__cruiseState_Check49,
__cruiseState_Check50,
__cruiseState_Check51,
__cruiseState_Check52,
__cruiseState_Check53,
__cruiseState_Check54,
__cruiseState_Check55,
__cruiseState_Check56,
__cruiseState_Check57,
__cruiseState_Check58,
__cruiseState_Check59,
__cruiseState_Check60,
__cruiseState_Check61,
__cruiseState_Check62,
__cruiseState_Check63,
__cruiseState_Check64,
__cruiseState_Check65,
__cruiseState_Check66,
__cruiseState_Check67,
__cruiseState_Check68,
__cruiseState_Check69,
__cruiseState_Check70,
__cruiseState_Check71,
__cruiseState_Check72,
__cruiseState_Check73,
__cruiseState_Check74,
__cruiseState_Check75,
__cruiseState_Check76
};
static int **__cruiseState_PCheckArray =  __cruiseState_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void cruiseState_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __cruiseState_show_variable (int __V) {
extern struct __VariableEntry __cruiseState_VariableTable[];
struct __VariableEntry* p_var = &__cruiseState_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __cruiseState_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __cruiseState_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __cruiseState_InstanceTable [] = {
{"cruiseState",0,"","cruiseControl.strl",{1,1,1,0},{1,121,1,0},{0,0,0,0}},
};

static struct __SourcePoint __cruiseState_SPSPA_0[] = {
{1,35,3,0},
{1,35,3,0}};
static struct __SourcePoint __cruiseState_SPSPA_1[] = {
{1,46,3,0},
{1,46,3,0},
{1,79,3,0},
{1,79,3,0}};
static struct __SourcePoint __cruiseState_SPSPA_2[] = {
{1,83,3,0},
{1,83,3,0}};
static struct __SourcePoint __cruiseState_SPSPA_3[] = {
{1,87,3,0},
{1,87,3,0}};
static struct __SourcePoint __cruiseState_SPSPA_4[] = {
{1,58,3,0},
{1,58,3,0}};
static struct __SourcePoint __cruiseState_SPSPA_5[] = {
{1,67,3,0},
{1,67,3,0}};
static struct __SourcePoint __cruiseState_SASPA_6[] = {
{1,36,7,0},
{1,42,18,0},
{1,53,9,0},
{1,93,6,0},
{1,98,18,0},
{1,103,6,0},
{1,106,9,0},
{1,110,18,0}};
static struct __SourcePoint __cruiseState_SASPA_7[] = {
{1,50,6,0}};
static struct __SourcePoint __cruiseState_SASPA_8[] = {
{1,36,25,0},
{1,37,20,0},
{1,61,66,0},
{1,70,66,0},
{1,89,19,0},
{1,93,24,0},
{1,103,24,0},
{1,106,27,0}};
static struct __SourcePoint __cruiseState_SESPA_9[] = {
{1,115,2,0}};
static struct __SourcePoint __cruiseState_SESPA_10[] = {
{1,62,5,0},
{1,71,5,0},
{1,114,2,0}};
static struct __SourcePoint __cruiseState_SESPA_11[] = {
{1,39,5,0},
{1,48,4,0},
{1,52,4,0},
{1,55,4,0},
{1,81,4,0},
{1,85,4,0},
{1,90,4,0},
{1,95,4,0},
{1,105,4,0},
{1,108,4,0}};
struct __SignalEntry __cruiseState_SignalTable [] = {
{"On",33,0,0,{1,3,7,0},0,(void*) NULL,2,__cruiseState_SPSPA_0,0,(void*) NULL},
{"Off",33,0,0,{1,3,11,0},0,(void*) NULL,4,__cruiseState_SPSPA_1,0,(void*) NULL},
{"Resume",33,0,0,{1,3,16,0},0,(void*) NULL,2,__cruiseState_SPSPA_2,0,(void*) NULL},
{"Set",33,0,0,{1,3,24,0},0,(void*) NULL,2,__cruiseState_SPSPA_3,0,(void*) NULL},
{"QuickAccel",33,0,0,{1,4,7,0},0,(void*) NULL,2,__cruiseState_SPSPA_4,0,(void*) NULL},
{"QuickDecel",33,0,0,{1,4,19,0},0,(void*) NULL,2,__cruiseState_SPSPA_5,0,(void*) NULL},
{"Accel",4,6,0,{1,8,8,0},0,(void*) NULL,0,(void*) NULL,8,__cruiseState_SASPA_6},
{"Brake",4,8,0,{1,9,8,0},0,(void*) NULL,0,(void*) NULL,1,__cruiseState_SASPA_7},
{"Speed",4,10,0,{1,10,8,0},0,(void*) NULL,0,(void*) NULL,8,__cruiseState_SASPA_8},
{"CruiseSpeed",2,12,0,{1,12,8,0},1,__cruiseState_SESPA_9,0,(void*) NULL,0,(void*) NULL},
{"ThrottleCmd",2,13,0,{1,13,8,0},3,__cruiseState_SESPA_10,0,(void*) NULL,0,(void*) NULL},
{"CruiseState",2,14,0,{1,14,8,0},10,__cruiseState_SESPA_11,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __cruiseState_InputTable [] = {
{"On",88,0,0,-1,0,0,0,cruiseState_IS_On,0,{1,3,7,0}},
{"Off",81,0,0,-1,0,1,0,cruiseState_IS_Off,0,{1,3,11,0}},
{"Resume",19,0,0,-1,0,2,0,cruiseState_IS_Resume,0,{1,3,16,0}},
{"Set",98,0,0,-1,0,3,0,cruiseState_IS_Set,0,{1,3,24,0}},
{"QuickAccel",72,0,0,-1,0,4,0,cruiseState_IS_QuickAccel,0,{1,4,7,0}},
{"QuickDecel",77,0,0,-1,0,5,0,cruiseState_IS_QuickDecel,0,{1,4,19,0}},
{"Accel",68,"float",1,-5,0,6,_check_float,cruiseState_IS_Accel,0,{1,8,8,0}},
{"Brake",81,"float",1,-5,0,7,_check_float,cruiseState_IS_Brake,0,{1,9,8,0}},
{"Speed",93,"float",1,-5,0,8,_check_float,cruiseState_IS_Speed,0,{1,10,8,0}}};

struct __VariableEntry __cruiseState_VariableTable [] = {
{"__cruiseState_V0","V0","boolean",-2,2,0,(char*)&__cruiseState_V0,"On",0,0,0,{1,3,7,0}},
{"__cruiseState_V1","V1","boolean",-2,2,0,(char*)&__cruiseState_V1,"Off",0,0,0,{1,3,11,0}},
{"__cruiseState_V2","V2","boolean",-2,2,0,(char*)&__cruiseState_V2,"Resume",0,0,0,{1,3,16,0}},
{"__cruiseState_V3","V3","boolean",-2,2,0,(char*)&__cruiseState_V3,"Set",0,0,0,{1,3,24,0}},
{"__cruiseState_V4","V4","boolean",-2,2,0,(char*)&__cruiseState_V4,"QuickAccel",0,0,0,{1,4,7,0}},
{"__cruiseState_V5","V5","boolean",-2,2,0,(char*)&__cruiseState_V5,"QuickDecel",0,0,0,{1,4,19,0}},
{"__cruiseState_V6","V6","float",-5,4,0,(char*)&__cruiseState_V6,"Accel",0,0,0,{1,8,8,0}},
{"__cruiseState_V7","V7","boolean",-2,5,0,(char*)&__cruiseState_V7,"Accel",0,0,0,{1,8,8,0}},
{"__cruiseState_V8","V8","float",-5,4,0,(char*)&__cruiseState_V8,"Brake",0,0,0,{1,9,8,0}},
{"__cruiseState_V9","V9","boolean",-2,5,0,(char*)&__cruiseState_V9,"Brake",0,0,0,{1,9,8,0}},
{"__cruiseState_V10","V10","float",-5,4,0,(char*)&__cruiseState_V10,"Speed",0,0,0,{1,10,8,0}},
{"__cruiseState_V11","V11","boolean",-2,5,0,(char*)&__cruiseState_V11,"Speed",0,0,0,{1,10,8,0}},
{"__cruiseState_V12","V12","float",-5,1,0,(char*)&__cruiseState_V12,"CruiseSpeed",0,0,0,{1,12,8,0}},
{"__cruiseState_V13","V13","float",-5,1,0,(char*)&__cruiseState_V13,"ThrottleCmd",0,0,0,{1,13,8,0}},
{"__cruiseState_V14","V14","integer",-3,1,0,(char*)&__cruiseState_V14,"CruiseState",0,0,0,{1,14,8,0}},
{"__cruiseState_V15","V15","integer",-3,0,0,(char*)&__cruiseState_V15,"state",0,0,0,{1,23,6,0}},
{"__cruiseState_V16","V16","float",-5,0,0,(char*)&__cruiseState_V16,"cruiseSpeed",0,0,0,{1,24,2,0}},
{"__cruiseState_V17","V17","float",-5,0,0,(char*)&__cruiseState_V17,"throttleOut",0,0,0,{1,25,2,0}},
{"__cruiseState_V18","V18","boolean",-2,0,0,(char*)&__cruiseState_V18,"temp",0,0,0,{1,26,2,0}}
};

struct __HaltEntry __cruiseState_HaltTable [] = {
{{1,121,1,0}},
{{1,116,2,0}}
};

static struct __SourcePoint __cruiseState_SPA[] = {
/* Net 2*/
{1,3,7,0},
/* Net 5*/
{1,3,11,0},
/* Net 8*/
{1,3,16,0},
/* Net 11*/
{1,3,24,0},
/* Net 14*/
{1,4,7,0},
/* Net 17*/
{1,4,19,0},
/* Net 21*/
{1,12,8,0},
/* Net 25*/
{1,13,8,0},
/* Net 29*/
{1,14,8,0},
/* Net 37*/
{1,121,1,0},
/* Net 42*/
{1,23,6,0},
/* Net 44*/
{1,24,2,0},
/* Net 46*/
{1,25,2,0},
/* Net 48*/
{1,26,2,0},
/* Net 50*/
{1,28,8,0},
/* Net 52*/
{1,29,14,0},
/* Net 54*/
{1,30,14,0},
/* Net 56*/
{1,31,7,0},
{1,33,2,0},
/* Net 57*/
{1,33,15,0},
{1,35,3,0},
/* Net 60*/
{1,35,14,0},
/* Net 62*/
{1,36,4,0},
/* Net 63*/
{1,36,67,0},
/* Net 68*/
{1,37,17,0},
/* Net 70*/
{1,38,11,0},
{1,39,5,0},
/* Net 72*/
{1,39,5,0},
/* Net 76*/
{1,42,15,0},
/* Net 77*/
{1,44,2,0},
/* Net 78*/
{1,44,15,0},
{1,46,3,0},
/* Net 81*/
{1,46,15,0},
/* Net 84*/
{1,47,10,0},
{1,48,4,0},
/* Net 86*/
{1,48,4,0},
/* Net 88*/
{1,50,3,0},
/* Net 89*/
{1,50,21,0},
/* Net 90*/
{1,53,3,0},
/* Net 93*/
{1,51,10,0},
{1,52,4,0},
/* Net 95*/
{1,52,4,0},
/* Net 96*/
{1,53,3,0},
/* Net 97*/
{1,53,24,0},
/* Net 101*/
{1,54,10,0},
{1,55,4,0},
/* Net 103*/
{1,55,4,0},
/* Net 104*/
{1,58,3,0},
/* Net 105*/
{1,58,22,0},
{1,59,4,0},
/* Net 107*/
{1,59,17,0},
/* Net 111*/
{1,60,10,0},
/* Net 114*/
{1,61,5,0},
{1,62,5,0},
/* Net 116*/
{1,62,5,0},
/* Net 118*/
{1,63,17,0},
/* Net 119*/
{1,67,3,0},
/* Net 120*/
{1,67,22,0},
{1,68,4,0},
/* Net 122*/
{1,68,17,0},
/* Net 126*/
{1,69,10,0},
/* Net 129*/
{1,70,5,0},
{1,71,5,0},
/* Net 131*/
{1,71,5,0},
/* Net 133*/
{1,72,17,0},
/* Net 134*/
{1,77,2,0},
/* Net 135*/
{1,77,15,0},
{1,79,3,0},
/* Net 138*/
{1,79,15,0},
/* Net 141*/
{1,80,10,0},
{1,81,4,0},
/* Net 143*/
{1,81,4,0},
/* Net 144*/
{1,83,3,0},
/* Net 145*/
{1,83,18,0},
/* Net 148*/
{1,84,10,0},
{1,85,4,0},
/* Net 150*/
{1,85,4,0},
/* Net 151*/
{1,87,3,0},
/* Net 152*/
{1,87,15,0},
/* Net 155*/
{1,88,10,0},
/* Net 158*/
{1,89,16,0},
{1,90,4,0},
/* Net 160*/
{1,90,4,0},
/* Net 162*/
{1,93,3,0},
/* Net 163*/
{1,93,66,0},
/* Net 167*/
{1,94,10,0},
{1,95,4,0},
/* Net 169*/
{1,95,4,0},
/* Net 173*/
{1,98,15,0},
/* Net 174*/
{1,101,2,0},
/* Net 175*/
{1,101,15,0},
/* Net 178*/
{1,103,3,0},
/* Net 179*/
{1,103,65,0},
/* Net 180*/
{1,106,3,0},
/* Net 183*/
{1,104,9,0},
{1,105,4,0},
/* Net 185*/
{1,105,4,0},
/* Net 186*/
{1,106,3,0},
/* Net 187*/
{1,106,69,0},
/* Net 191*/
{1,107,10,0},
{1,108,4,0},
/* Net 193*/
{1,108,4,0},
/* Net 197*/
{1,110,15,0},
/* Net 198*/
{1,114,2,0},
/* Net 200*/
{1,114,2,0},
{1,115,2,0},
/* Net 202*/
{1,115,2,0},
/* Net 203*/
{1,22,1,0},
/* Net 207*/
{1,116,2,0}};
struct __NetEntry __cruiseState_NetTable [] = {
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+0},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+1},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+2},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+3},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+4},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+5},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+6},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+7},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+8},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+9},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+10},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+11},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+12},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+13},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+14},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+15},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+16},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+17},
{0,0,2,__cruiseState_SPA+19},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+21},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+22},
{0,0,1,__cruiseState_SPA+23},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+24},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+25},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+27},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+28},
{0,0,1,__cruiseState_SPA+29},
{0,0,2,__cruiseState_SPA+30},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+32},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+33},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+35},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+36},
{0,0,1,__cruiseState_SPA+37},
{0,0,1,__cruiseState_SPA+38},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+39},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+41},
{0,0,1,__cruiseState_SPA+42},
{0,0,1,__cruiseState_SPA+43},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+44},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+46},
{0,0,1,__cruiseState_SPA+47},
{0,0,2,__cruiseState_SPA+48},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+50},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+51},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+52},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+54},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+55},
{0,0,1,__cruiseState_SPA+56},
{0,0,2,__cruiseState_SPA+57},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+59},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+60},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+61},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+63},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+64},
{0,0,1,__cruiseState_SPA+65},
{0,0,2,__cruiseState_SPA+66},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+68},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+69},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+71},
{0,0,1,__cruiseState_SPA+72},
{0,0,1,__cruiseState_SPA+73},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+74},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+76},
{0,0,1,__cruiseState_SPA+77},
{0,0,1,__cruiseState_SPA+78},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+79},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+80},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+82},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+83},
{0,0,1,__cruiseState_SPA+84},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+85},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+87},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+88},
{0,0,1,__cruiseState_SPA+89},
{0,0,1,__cruiseState_SPA+90},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+91},
{0,0,1,__cruiseState_SPA+92},
{0,0,1,__cruiseState_SPA+93},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+94},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+96},
{0,0,1,__cruiseState_SPA+97},
{0,0,1,__cruiseState_SPA+98},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+99},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+101},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+102},
{0,0,1,__cruiseState_SPA+103},
{0,0,0,(void*) NULL},
{0,0,2,__cruiseState_SPA+104},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+106},
{0,0,1,__cruiseState_SPA+107},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL},
{0,0,1,__cruiseState_SPA+108},
{0,0,0,(void*) NULL},
{0,0,0,(void*) NULL}
};


static void __cruiseState__reset_input () {
__cruiseState_V0 = _false;
__cruiseState_V1 = _false;
__cruiseState_V2 = _false;
__cruiseState_V3 = _false;
__cruiseState_V4 = _false;
__cruiseState_V5 = _false;
__cruiseState_V7 = _false;
__cruiseState_V9 = _false;
__cruiseState_V11 = _false;
}


/* MODULE DATA FOR SIMULATION */

int cruiseState();
int cruiseState_reset();

static struct __ModuleEntry __cruiseState_ModuleData = {
"Simulation interface release 5","cruiseState",
1,0,12,9,0,3,3,0,0,0,0,19,0,2,208,0,0,
__cruiseState_HaltList,
__cruiseState_AwaitedList,
__cruiseState_EmittedList,
__cruiseState_StartedList,
__cruiseState_KilledList,
__cruiseState_SuspendedList,
__cruiseState_ActiveList,
0,0,
cruiseState_initialize,cruiseState,cruiseState_reset,
__cruiseState_show_variable,__cruiseState_set_variable,__cruiseState_check_value,0,
__cruiseState_InstanceTable,
0,
__cruiseState_SignalTable,__cruiseState_InputTable,0,
0,0,
__cruiseState_VariableTable,
0,
__cruiseState_HaltTable,
__cruiseState_NetTable};

static int  __SCRUN__();
static void __SCRESET__();

#define __KIND 0
#define __AUX 1
#define __KNOWN 2
#define __DEFAULT_VALUE 3
#define __VALUE 4
#define __ARITY 5
#define __PREDECESSOR_COUNT 6
#define __ACCESS_ARITY  7
#define __ACCESS_COUNT 8
#define __LISTS 9
#define __SIMUL_SCRUN

#define __SIMUL_NET_TABLE__ __cruiseState_NetTable

#define __NET_TYPE__ int
enum {__STANDARD, __SELECTINC, __RETURN, __SINGLE, __SIGTRACE, __ACTION, __TEST, __REG, __HALT} __NET_KIND__;

#define __SINGLE_SIGNAL_EMITTED_TWICE_ERROR_CODE 2
#define __CAUSALITY_ERROR_CODE 3
#define  __MODULE_NAME__ "cruiseState"

/* THE TABLE OF NETS */

static __NET_TYPE__ __cruiseState_nets [] = {
/* On__I_0_0*/
__TEST,1,0,1,1,0,0,0,0,0,1,1,0,
/* PRESENT_S0_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,1,60,2,2,61,0,
/* TRACE_S0_0_*/
__SIGTRACE,0,0,1,1,1,1,0,0,0,0,0,
/* Off__I_0_0*/
__TEST,2,0,1,1,0,0,0,0,0,1,4,0,
/* PRESENT_S1_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,2,81,138,3,5,82,139,0,
/* TRACE_S1_0_*/
__SIGTRACE,1,0,1,1,1,1,0,0,0,0,0,
/* Resume__I_0_0*/
__TEST,3,0,1,1,0,0,0,0,0,1,7,0,
/* PRESENT_S2_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,1,145,2,8,146,0,
/* TRACE_S2_0_*/
__SIGTRACE,2,0,1,1,1,1,0,0,0,0,0,
/* Set__I_0_0*/
__TEST,4,0,1,1,0,0,0,0,0,1,10,0,
/* PRESENT_S3_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,1,152,2,11,153,0,
/* TRACE_S3_0_*/
__SIGTRACE,3,0,1,1,1,1,0,0,0,0,0,
/* QuickAccel__I_0_0*/
__TEST,5,0,1,1,0,0,0,0,0,1,13,0,
/* PRESENT_S4_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,1,105,2,14,106,0,
/* TRACE_S4_0_*/
__SIGTRACE,4,0,1,1,1,1,0,0,0,0,0,
/* QuickDecel__I_0_0*/
__TEST,6,0,1,1,0,0,0,0,0,1,16,0,
/* PRESENT_S5_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,1,120,2,17,121,0,
/* TRACE_S5_0_*/
__SIGTRACE,5,0,1,1,1,1,0,0,0,0,0,
/* CruiseSpeed__O_0_0*/
__ACTION,7,0,1,1,1,1,1,1,0,0,0,
/* PRESENT_S9_0_0*/
__SINGLE,9,0,1,1,1,1,0,0,0,2,18,21,0,
/* UPDATED_S9_0_0*/
__STANDARD,0,0,1,1,1,1,2,2,0,0,1,18,
/* TRACE_S9_0_*/
__SIGTRACE,9,0,1,1,1,1,0,0,0,0,0,
/* ThrottleCmd__O_0_0*/
__ACTION,8,0,1,1,1,1,1,1,0,0,0,
/* PRESENT_S10_0_0*/
__SINGLE,10,0,1,1,3,3,0,0,0,2,22,25,0,
/* UPDATED_S10_0_0*/
__STANDARD,0,0,1,1,1,1,4,4,0,0,1,22,
/* TRACE_S10_0_*/
__SIGTRACE,10,0,1,1,1,1,0,0,0,0,0,
/* CruiseState__O_0_0*/
__ACTION,9,0,1,1,1,1,1,1,0,0,0,
/* PRESENT_S11_0_0*/
__SINGLE,11,0,1,1,10,10,0,0,0,2,26,29,0,
/* UPDATED_S11_0_0*/
__STANDARD,0,0,1,1,1,1,11,11,0,0,1,26,
/* TRACE_S11_0_*/
__SIGTRACE,11,0,1,1,1,1,0,0,0,0,0,
/* BOOT_REGISTER_0_0*/
__REG,0,0,1,1,1,1,0,0,1,31,4,32,33,34,41,0,
/* ROOT_RES_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,1,203,0,0,
/* ACT_16_0_0_0*/
__ACTION,70,0,1,1,1,1,0,0,0,0,1,20,
/* ACT_18_0_0_0*/
__ACTION,71,0,1,1,1,1,0,0,0,0,1,24,
/* ACT_20_0_0_0*/
__ACTION,72,0,1,1,1,1,0,0,0,0,1,28,
/* ROOT_KILL_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,0,1,207,0,
/* ROOT_STAY_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,1,204,0,0,
/* ROOT_K0_0_0*/
__RETURN,0,0,1,1,1,1,0,0,0,0,0,
/* ROOT_K1_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* SELECT_0_0_0*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* TRACE_ACT_21_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* GO_1_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,0,1,42,0,
/* ACT_21_0_0_0*/
__ACTION,73,0,1,1,1,1,0,0,0,2,40,44,0,
/* TRACE_ACT_22_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_22_0_0_0*/
__ACTION,74,0,1,1,1,1,0,0,0,2,43,46,0,
/* TRACE_ACT_23_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_23_0_0_0*/
__ACTION,75,0,1,1,1,1,0,0,0,2,45,48,0,
/* TRACE_ACT_24_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_24_0_0_0*/
__ACTION,76,0,1,1,1,1,0,0,0,2,47,50,0,
/* TRACE_ACT_25_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_25_0_0_0*/
__ACTION,19,0,1,1,1,1,0,0,0,2,49,52,0,
/* TRACE_ACT_26_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_26_0_0_0*/
__ACTION,20,0,1,1,1,1,0,0,0,2,51,54,0,
/* TRACE_ACT_27_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_27_0_0_0*/
__ACTION,21,0,1,1,1,1,0,0,0,2,53,56,0,
/* TRACE_ACT_28_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_28_0_0_0*/
__ACTION,22,0,1,1,1,1,0,0,1,58,2,55,57,0,
/* TEST_29_0_0_0*/
__TEST,58,0,1,1,1,1,0,0,2,60,61,2,58,59,0,
/* ELSE_9_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,77,0,
/* TRACE_TEST_29_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* THEN_10_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,1,62,0,0,
/* ELSE_10_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,73,0,
/* CONT_11_0_0*/
__STANDARD,0,0,0,0,3,3,0,0,1,64,1,63,0,
/* TEST_30_0_0_0*/
__TEST,59,0,1,1,1,1,0,0,1,66,2,64,65,0,
/* ELSE_12_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,73,0,
/* TRACE_TEST_30_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* CONT_13_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,68,0,
/* TRACE_ACT_31_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_31_0_0_0*/
__ACTION,23,0,1,1,1,1,0,0,0,2,67,70,0,
/* TRACE_ACT_32_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_32_0_0_0*/
__ACTION,24,0,1,1,1,1,0,0,0,3,27,69,72,0,
/* TRACE_ACT_33_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_33_0_0_0*/
__ACTION,25,0,1,1,1,1,0,0,0,2,71,73,1,28,
/* GO_19_0_0*/
__STANDARD,0,0,1,1,3,3,0,0,1,74,0,0,
/* CONT_19_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,76,0,
/* TRACE_ACT_34_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_34_0_0_0*/
__ACTION,26,0,1,1,1,1,0,0,0,2,75,77,0,
/* GO_21_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,1,79,1,78,0,
/* TEST_35_0_0_0*/
__TEST,60,0,1,1,1,1,0,0,2,81,82,2,79,80,0,
/* ELSE_21_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,134,0,
/* TRACE_TEST_35_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* THEN_22_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,84,0,
/* ELSE_22_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,87,0,
/* TRACE_ACT_36_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_36_0_0_0*/
__ACTION,27,0,1,1,1,1,0,0,0,3,27,83,86,0,
/* TRACE_ACT_37_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_37_0_0_0*/
__ACTION,28,0,1,1,1,1,0,0,0,2,85,87,1,28,
/* GO_27_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,1,88,0,0,
/* CONT_27_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,1,90,1,89,0,
/* TEST_38_0_0_0*/
__TEST,61,0,1,1,1,1,0,0,0,3,90,91,93,0,
/* ELSE_28_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,1,96,0,0,
/* TRACE_TEST_38_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* TRACE_ACT_39_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_39_0_0_0*/
__ACTION,29,0,1,1,1,1,0,0,0,3,27,92,95,0,
/* TRACE_ACT_40_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_40_0_0_0*/
__ACTION,30,0,1,1,1,1,0,0,0,2,94,104,1,28,
/* CONT_33_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,1,98,1,97,0,
/* TEST_41_0_0_0*/
__TEST,62,0,1,1,1,1,0,0,0,3,98,99,101,0,
/* ELSE_34_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,104,0,
/* TRACE_TEST_41_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* TRACE_ACT_42_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_42_0_0_0*/
__ACTION,31,0,1,1,1,1,0,0,0,3,27,100,103,0,
/* TRACE_ACT_43_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_43_0_0_0*/
__ACTION,32,0,1,1,1,1,0,0,0,2,102,104,1,28,
/* GO_39_0_0*/
__STANDARD,0,0,1,1,3,3,0,0,2,105,106,0,0,
/* THEN_39_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,1,108,1,107,0,
/* ELSE_39_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,119,0,
/* TEST_44_0_0_0*/
__TEST,63,0,1,1,1,1,0,0,0,3,108,109,111,0,
/* ELSE_40_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,119,0,
/* TRACE_TEST_44_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* TRACE_ACT_45_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_45_0_0_0*/
__ACTION,33,0,1,1,1,1,0,0,1,112,1,110,0,
/* CONT_42_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,114,0,
/* TRACE_ACT_46_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_46_0_0_0*/
__ACTION,56,0,1,1,1,1,0,0,0,3,23,113,116,0,
/* TRACE_ACT_47_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_47_0_0_0*/
__ACTION,34,0,1,1,1,1,0,0,0,2,115,118,1,24,
/* TRACE_ACT_48_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_48_0_0_0*/
__ACTION,35,0,1,1,1,1,0,0,0,2,117,119,0,
/* GO_48_0_0*/
__STANDARD,0,0,1,1,3,3,0,0,2,120,121,0,0,
/* THEN_48_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,1,123,1,122,0,
/* ELSE_48_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,134,0,
/* TEST_49_0_0_0*/
__TEST,64,0,1,1,1,1,0,0,0,3,123,124,126,0,
/* ELSE_49_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,134,0,
/* TRACE_TEST_49_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* TRACE_ACT_50_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_50_0_0_0*/
__ACTION,36,0,1,1,1,1,0,0,1,127,1,125,0,
/* CONT_51_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,129,0,
/* TRACE_ACT_51_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_51_0_0_0*/
__ACTION,57,0,1,1,1,1,0,0,0,3,23,128,131,0,
/* TRACE_ACT_52_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_52_0_0_0*/
__ACTION,37,0,1,1,1,1,0,0,0,2,130,133,1,24,
/* TRACE_ACT_53_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_53_0_0_0*/
__ACTION,38,0,1,1,1,1,0,0,0,2,132,134,0,
/* GO_57_0_0*/
__STANDARD,0,0,1,1,4,4,0,0,1,136,1,135,0,
/* TEST_54_0_0_0*/
__TEST,65,0,1,1,1,1,0,0,2,138,139,2,136,137,0,
/* ELSE_57_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,174,0,
/* TRACE_TEST_54_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* THEN_58_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,141,0,
/* ELSE_58_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,144,0,
/* TRACE_ACT_55_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_55_0_0_0*/
__ACTION,39,0,1,1,1,1,0,0,0,3,27,140,143,0,
/* TRACE_ACT_56_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_56_0_0_0*/
__ACTION,40,0,1,1,1,1,0,0,0,2,142,144,1,28,
/* GO_63_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,2,145,146,0,0,
/* THEN_63_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,148,0,
/* ELSE_63_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,151,0,
/* TRACE_ACT_57_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_57_0_0_0*/
__ACTION,41,0,1,1,1,1,0,0,0,3,27,147,150,0,
/* TRACE_ACT_58_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_58_0_0_0*/
__ACTION,42,0,1,1,1,1,0,0,0,2,149,151,1,28,
/* GO_68_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,2,152,153,0,0,
/* THEN_68_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,155,0,
/* ELSE_68_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,161,0,
/* TRACE_ACT_59_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_59_0_0_0*/
__ACTION,43,0,1,1,1,1,0,0,1,156,1,154,0,
/* CONT_70_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,158,0,
/* TRACE_ACT_60_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_60_0_0_0*/
__ACTION,44,0,1,1,1,1,0,0,0,3,27,157,160,0,
/* TRACE_ACT_61_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_61_0_0_0*/
__ACTION,45,0,1,1,1,1,0,0,0,2,159,161,1,28,
/* GO_75_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,1,162,0,0,
/* CONT_75_0_0*/
__STANDARD,0,0,0,0,3,3,0,0,1,164,1,163,0,
/* TEST_62_0_0_0*/
__TEST,66,0,1,1,1,1,0,0,0,3,164,165,167,0,
/* ELSE_76_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,170,0,
/* TRACE_TEST_62_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* TRACE_ACT_63_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_63_0_0_0*/
__ACTION,46,0,1,1,1,1,0,0,0,3,27,166,169,0,
/* TRACE_ACT_64_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_64_0_0_0*/
__ACTION,47,0,1,1,1,1,0,0,0,2,168,170,1,28,
/* GO_81_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,1,171,0,0,
/* CONT_81_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,173,0,
/* TRACE_ACT_65_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_65_0_0_0*/
__ACTION,48,0,1,1,1,1,0,0,0,2,172,174,0,
/* GO_83_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,1,176,1,175,0,
/* TEST_66_0_0_0*/
__TEST,67,0,1,1,1,1,0,0,1,178,2,176,177,0,
/* ELSE_83_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,198,0,
/* TRACE_TEST_66_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* CONT_84_0_0*/
__STANDARD,0,0,0,0,3,3,0,0,1,180,1,179,0,
/* TEST_67_0_0_0*/
__TEST,68,0,1,1,1,1,0,0,0,3,180,181,183,0,
/* ELSE_85_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,1,186,0,0,
/* TRACE_TEST_67_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* TRACE_ACT_68_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_68_0_0_0*/
__ACTION,49,0,1,1,1,1,0,0,0,3,27,182,185,0,
/* TRACE_ACT_69_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_69_0_0_0*/
__ACTION,50,0,1,1,1,1,0,0,0,2,184,194,1,28,
/* CONT_90_0_0*/
__STANDARD,0,0,0,0,3,3,0,0,1,188,1,187,0,
/* TEST_70_0_0_0*/
__TEST,69,0,1,1,1,1,0,0,0,3,188,189,191,0,
/* ELSE_91_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,194,0,
/* TRACE_TEST_70_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* TRACE_ACT_71_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_71_0_0_0*/
__ACTION,51,0,1,1,1,1,0,0,0,3,27,190,193,0,
/* TRACE_ACT_72_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_72_0_0_0*/
__ACTION,52,0,1,1,1,1,0,0,0,2,192,194,1,28,
/* GO_96_0_0*/
__STANDARD,0,0,1,1,3,3,0,0,1,195,0,0,
/* CONT_96_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,197,0,
/* TRACE_ACT_73_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_73_0_0_0*/
__ACTION,53,0,1,1,1,1,0,0,0,2,196,198,0,
/* GO_98_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,0,2,23,200,0,
/* TRACE_ACT_74_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_74_0_0_0*/
__ACTION,54,0,1,1,1,1,0,0,0,3,19,199,202,1,24,
/* TRACE_ACT_75_0_0_*/
__STANDARD,0,0,1,1,1,1,0,0,0,0,0,
/* ACT_75_0_0_0*/
__ACTION,55,0,1,1,1,1,0,0,0,2,201,206,1,20,
/* CONT_104_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,41,0,
/* STAY_104_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,206,0,
/* PAUSE_REG_104_0_0*/
__HALT,1,0,1,0,1,1,0,0,2,203,204,1,39,0,
/* GO_104_0_0*/
__STANDARD,0,0,1,1,2,2,0,0,1,207,1,38,0,
/* TO_REG_104_0_0*/
__STANDARD,0,0,0,0,2,2,0,0,0,1,205,0,
/* __FALSE__*/
__STANDARD,0,0,0,0,0,0,0,0,0,4,30,35,36,37,0,
/* __TRUE__*/
__STANDARD,0,0,1,1,0,0,0,0,17,62,62,66,74,88,96,112,127,156,162,162,171,178,178,186,186,195,3,20,24,28,0};

/* THE NET ARRAY */

static __NET_TYPE__* __cruiseState_net_array[] = {
__cruiseState_nets+0,
__cruiseState_nets+13,
__cruiseState_nets+28,
__cruiseState_nets+40,
__cruiseState_nets+53,
__cruiseState_nets+70,
__cruiseState_nets+82,
__cruiseState_nets+95,
__cruiseState_nets+110,
__cruiseState_nets+122,
__cruiseState_nets+135,
__cruiseState_nets+150,
__cruiseState_nets+162,
__cruiseState_nets+175,
__cruiseState_nets+190,
__cruiseState_nets+202,
__cruiseState_nets+215,
__cruiseState_nets+230,
__cruiseState_nets+242,
__cruiseState_nets+254,
__cruiseState_nets+268,
__cruiseState_nets+281,
__cruiseState_nets+293,
__cruiseState_nets+305,
__cruiseState_nets+319,
__cruiseState_nets+332,
__cruiseState_nets+344,
__cruiseState_nets+356,
__cruiseState_nets+370,
__cruiseState_nets+383,
__cruiseState_nets+395,
__cruiseState_nets+412,
__cruiseState_nets+425,
__cruiseState_nets+438,
__cruiseState_nets+451,
__cruiseState_nets+464,
__cruiseState_nets+477,
__cruiseState_nets+490,
__cruiseState_nets+502,
__cruiseState_nets+514,
__cruiseState_nets+526,
__cruiseState_nets+538,
__cruiseState_nets+551,
__cruiseState_nets+565,
__cruiseState_nets+577,
__cruiseState_nets+591,
__cruiseState_nets+603,
__cruiseState_nets+617,
__cruiseState_nets+629,
__cruiseState_nets+643,
__cruiseState_nets+655,
__cruiseState_nets+669,
__cruiseState_nets+681,
__cruiseState_nets+695,
__cruiseState_nets+707,
__cruiseState_nets+721,
__cruiseState_nets+733,
__cruiseState_nets+748,
__cruiseState_nets+764,
__cruiseState_nets+777,
__cruiseState_nets+789,
__cruiseState_nets+802,
__cruiseState_nets+815,
__cruiseState_nets+829,
__cruiseState_nets+844,
__cruiseState_nets+857,
__cruiseState_nets+869,
__cruiseState_nets+882,
__cruiseState_nets+894,
__cruiseState_nets+908,
__cruiseState_nets+920,
__cruiseState_nets+935,
__cruiseState_nets+947,
__cruiseState_nets+962,
__cruiseState_nets+975,
__cruiseState_nets+988,
__cruiseState_nets+1000,
__cruiseState_nets+1014,
__cruiseState_nets+1028,
__cruiseState_nets+1044,
__cruiseState_nets+1057,
__cruiseState_nets+1069,
__cruiseState_nets+1082,
__cruiseState_nets+1095,
__cruiseState_nets+1107,
__cruiseState_nets+1122,
__cruiseState_nets+1134,
__cruiseState_nets+1149,
__cruiseState_nets+1162,
__cruiseState_nets+1176,
__cruiseState_nets+1191,
__cruiseState_nets+1204,
__cruiseState_nets+1216,
__cruiseState_nets+1228,
__cruiseState_nets+1243,
__cruiseState_nets+1255,
__cruiseState_nets+1270,
__cruiseState_nets+1284,
__cruiseState_nets+1299,
__cruiseState_nets+1312,
__cruiseState_nets+1324,
__cruiseState_nets+1336,
__cruiseState_nets+1351,
__cruiseState_nets+1363,
__cruiseState_nets+1378,
__cruiseState_nets+1392,
__cruiseState_nets+1406,
__cruiseState_nets+1419,
__cruiseState_nets+1434,
__cruiseState_nets+1447,
__cruiseState_nets+1459,
__cruiseState_nets+1471,
__cruiseState_nets+1485,
__cruiseState_nets+1498,
__cruiseState_nets+1510,
__cruiseState_nets+1525,
__cruiseState_nets+1537,
__cruiseState_nets+1552,
__cruiseState_nets+1564,
__cruiseState_nets+1578,
__cruiseState_nets+1592,
__cruiseState_nets+1606,
__cruiseState_nets+1619,
__cruiseState_nets+1634,
__cruiseState_nets+1647,
__cruiseState_nets+1659,
__cruiseState_nets+1671,
__cruiseState_nets+1685,
__cruiseState_nets+1698,
__cruiseState_nets+1710,
__cruiseState_nets+1725,
__cruiseState_nets+1737,
__cruiseState_nets+1752,
__cruiseState_nets+1764,
__cruiseState_nets+1778,
__cruiseState_nets+1792,
__cruiseState_nets+1808,
__cruiseState_nets+1821,
__cruiseState_nets+1833,
__cruiseState_nets+1846,
__cruiseState_nets+1859,
__cruiseState_nets+1871,
__cruiseState_nets+1886,
__cruiseState_nets+1898,
__cruiseState_nets+1913,
__cruiseState_nets+1927,
__cruiseState_nets+1940,
__cruiseState_nets+1953,
__cruiseState_nets+1965,
__cruiseState_nets+1980,
__cruiseState_nets+1992,
__cruiseState_nets+2007,
__cruiseState_nets+2021,
__cruiseState_nets+2034,
__cruiseState_nets+2047,
__cruiseState_nets+2059,
__cruiseState_nets+2073,
__cruiseState_nets+2086,
__cruiseState_nets+2098,
__cruiseState_nets+2113,
__cruiseState_nets+2125,
__cruiseState_nets+2140,
__cruiseState_nets+2153,
__cruiseState_nets+2167,
__cruiseState_nets+2182,
__cruiseState_nets+2195,
__cruiseState_nets+2207,
__cruiseState_nets+2219,
__cruiseState_nets+2234,
__cruiseState_nets+2246,
__cruiseState_nets+2261,
__cruiseState_nets+2274,
__cruiseState_nets+2287,
__cruiseState_nets+2299,
__cruiseState_nets+2313,
__cruiseState_nets+2327,
__cruiseState_nets+2342,
__cruiseState_nets+2355,
__cruiseState_nets+2367,
__cruiseState_nets+2381,
__cruiseState_nets+2396,
__cruiseState_nets+2409,
__cruiseState_nets+2421,
__cruiseState_nets+2433,
__cruiseState_nets+2448,
__cruiseState_nets+2460,
__cruiseState_nets+2475,
__cruiseState_nets+2489,
__cruiseState_nets+2504,
__cruiseState_nets+2517,
__cruiseState_nets+2529,
__cruiseState_nets+2541,
__cruiseState_nets+2556,
__cruiseState_nets+2568,
__cruiseState_nets+2583,
__cruiseState_nets+2596,
__cruiseState_nets+2609,
__cruiseState_nets+2621,
__cruiseState_nets+2635,
__cruiseState_nets+2649,
__cruiseState_nets+2661,
__cruiseState_nets+2677,
__cruiseState_nets+2689,
__cruiseState_nets+2704,
__cruiseState_nets+2717,
__cruiseState_nets+2730,
__cruiseState_nets+2745,
__cruiseState_nets+2759,
__cruiseState_nets+2772,
__cruiseState_nets+2788,

};
#define __NET_ARRAY__ __cruiseState_net_array

 /* THE QUEUE */

static __NET_TYPE__ __cruiseState_queue[210] = {
0,
 3,
 6,
 9,
 12,
 15,
 30,
 205,
 208,
 209
};
#define __QUEUE__ __cruiseState_queue
#define __NUMBER_OF_NETS__ 210
#define __NUMBER_OF_INITIAL_NETS__ 10
#define __NUMBER_OF_REGISTERS__ 2
#define __NUMBER_OF_HALTS__ 2

#define __HALT_LIST__ __cruiseState_HaltList
#define __EMITTED_LIST__ __cruiseState_EmittedList
#define __SINGLE_SIGNAL_EMITTED_TWICE_ERROR__(i) __cruiseState_ModuleData.run_time_error_code = __SINGLE_SIGNAL_EMITTED_TWICE_ERROR_CODE; __cruiseState_ModuleData.error_info = i;
#define __CAUSALITY_ERROR__ __cruiseState_ModuleData.run_time_error_code = __CAUSALITY_ERROR_CODE;

int cruiseState () {

__cruiseState_ModuleData.awaited_list = __cruiseState_AwaitedList;
__ResetModuleEntryBeforeReaction();
__SCRUN__();
__ResetModuleEntryAfterReaction();
__cruiseState_ModuleData.awaited_list = __cruiseState_AllAwaitedList;
__cruiseState__reset_input();
return __cruiseState_net_array[38][__VALUE];
}

/* AUTOMATON RESET */

int cruiseState_reset () {
__SCRESET__();
__cruiseState_ModuleData.awaited_list = __cruiseState_AwaitedList;
__ResetModuleEntry();
__cruiseState_ModuleData.awaited_list = __cruiseState_AllAwaitedList;
__cruiseState_ModuleData.state = 0;
__cruiseState_net_array[30][__VALUE] = 1;
__cruiseState_net_array[205][__VALUE] = 0;
__cruiseState__reset_input();
return 0;
}
#ifdef __SIMUL_SCRUN
#include <assert.h>
#ifndef TRACE_ACTION
#include <stdio.h>
#endif
#endif
 

#define __KIND 0
#define __AUX 1
#define __KNOWN 2
#define __DEFAULT_VALUE 3
#define __VALUE 4
#define __ARITY 5
#define __PREDECESSOR_COUNT 6
#define __ACCESS_ARITY  7
#define __ACCESS_COUNT 8
#define __LISTS 9

#define __SIMUL_VALUE 0
#define __SIMUL_KNOWN 1

static int __free_queue_position;
#ifdef __SIMUL_SCRUN
static int __TESTRES__[__NUMBER_OF_NETS__];
#endif
static int __REGVAL[__NUMBER_OF_NETS__];
static int __NUMBER_OF_REGS_KNOWN;


static void __SET_VALUE (netNum, value) 
int netNum; 
int value; {
   int* net = __NET_ARRAY__[netNum];
#ifdef __SIMUL_SCRUN
   if (net[__KNOWN] && net[__KIND] == __SINGLE && net[__VALUE] && value) {
       __SINGLE_SIGNAL_EMITTED_TWICE_ERROR__(net[__AUX]);
   }
#endif
   if (net[__KNOWN]) return;
   net[__KNOWN] =  1;
   switch (net[__KIND]) {
      case __REG:
      case __HALT:
         __REGVAL[netNum] = value;
         __NUMBER_OF_REGS_KNOWN++;
#ifdef TRACE_SCRUN
            fprintf(stderr, "Save register %d with value %d\n", netNum, value);
#endif
         break;
      default:
         net[__VALUE] =  value;
         if (! net[__ACCESS_COUNT]) {
            __QUEUE__[__free_queue_position++] = netNum;
#ifdef TRACE_SCRUN
            fprintf(stderr, "Enqueue net %d with value %d\n", netNum, value);
#endif
         }
   }
}

static void __DECR_ARITY (netNum)
int netNum; {
   int* net = __NET_ARRAY__[netNum];
   if (! (--(net[__PREDECESSOR_COUNT]))) {
      __SET_VALUE(netNum, !net[__DEFAULT_VALUE]);
   }
}

static void __DECR_ACCESS_ARITY (netNum) 
int netNum; {
   int* net = __NET_ARRAY__[netNum];
   if (   ! (--(net[__ACCESS_COUNT])) 
       && net[__KNOWN]) {
      __QUEUE__[__free_queue_position++] = netNum;
#ifdef TRACE_SCRUN
      fprintf(stderr, "Enqueue %d by freeing last access\n", netNum);
#endif
   }
}

static void __SCFOLLOW (netNum, value)
int netNum;
int value; {
   int* net = __NET_ARRAY__[netNum];
   int* lists = net + __LISTS;
   int count;
   int i;  /* list index */
   int followerNum;

#ifdef __SIMUL_SCRUN
   __SIMUL_NET_TABLE__[netNum].known = 1;
   __SIMUL_NET_TABLE__[netNum].value = value;
#endif
#ifdef __SIMUL_SCRUN
   if (net[__KIND] == __TEST) {
       /* set __KNOWN for inputs (one has already __KNOWN==1 for other tests
          when reaching this point. This is only useful to print correctly 
          the causality error message.
       */
       net[__KNOWN] = 1;
   }
#endif
   count = lists[0];
   lists++;
   if (value) {
      for (i=0; i<count; i++) {
         followerNum = lists[0];
         lists++;
         if (! __NET_ARRAY__[followerNum][__KNOWN]) {
            __DECR_ARITY(followerNum);
         }
      }
      count = lists[0];
      lists++;
      for (i=0; i<count; i++) {
         followerNum =lists[0];
         lists++;
         __SET_VALUE(followerNum, 
                     __NET_ARRAY__[followerNum][__DEFAULT_VALUE]);
      }
  } else {
      for (i=0; i<count; i++) {
         followerNum = lists[0];
         lists++;
         __SET_VALUE(followerNum,
                     __NET_ARRAY__[followerNum][__DEFAULT_VALUE]);
      }
      count = lists[0];
      lists++;
      for (i=0; i<count; i++) {
         followerNum = lists[0];
         lists++;
         if (! __NET_ARRAY__[followerNum][__KNOWN]) {
            __DECR_ARITY(followerNum);
         }
      }
   }
   count = lists[0];
   lists++;
   for (i=0; i<count; i++) {
      followerNum = lists[0];
      lists++;
      __DECR_ACCESS_ARITY(followerNum);
   }
}

static int __SCRUN__ () {
   int queuePosition;
   int netNum;
   int* net;
   int value;    /* current net value */
   int testres;  /* result of test action */
   __free_queue_position = __NUMBER_OF_INITIAL_NETS__;

#ifdef TRACE_SCRUN
            fprintf(stderr, "\n***************************\n");
#endif

   /* Reset predecessor counts, access counts, and known flags */
   for (netNum=0; netNum< __NUMBER_OF_NETS__; netNum++) {
      net = __NET_ARRAY__[netNum];
      net[__PREDECESSOR_COUNT] = net[__ARITY];
      net[__ACCESS_COUNT] = net[__ACCESS_ARITY];
      net[__KNOWN] = 0;
#ifdef __SIMUL_SCRUN
      __SIMUL_NET_TABLE__[netNum].known = 0;
      __TESTRES__[netNum] = 0;
#endif
   }
   __NUMBER_OF_REGS_KNOWN = 0;

   /* Run main algorithm */
   for (queuePosition=0; 
        queuePosition < __free_queue_position; 
        queuePosition++) {
      netNum = __QUEUE__[queuePosition];
      net = __NET_ARRAY__[netNum];
      value = net[__VALUE];
#ifdef TRACE_SCRUN
      fprintf(stderr,
              "Step %d : processing net %d value %d\n",
              queuePosition, netNum, value);
#endif

      /* Decode kind and perform action if necessary */
      switch (net[__KIND]) {
         case __STANDARD :
         case __SELECTINC :
         case __SINGLE :   /* TO BE CHANGED FOR SINGLE SIGNAL TEST! */
         case __REG :
         case __HALT :
#ifdef __SIMUL_SCRUN
   __SIMUL_NET_TABLE__[netNum].value = value;
#endif
            __SCFOLLOW(netNum, value);
            break;
         case __RETURN :
#ifdef __SIMUL_SCRUN
            if (value) {
               __AppendToList(__HALT_LIST__, (unsigned short)net[__AUX]);
            }
#endif
            __SCFOLLOW(netNum, value);
            break;
         case __SIGTRACE :
#ifdef __SIMUL_SCRUN
            if (value) {
               __AppendToList(__EMITTED_LIST__, (unsigned short)net[__AUX]);
           }
#endif
            __SCFOLLOW(netNum, value);
            break;
         case __ACTION :
            if (value) {
               __ACT(net[__AUX]);
            }
            __SCFOLLOW(netNum, value);
            break;
         case __TEST :
            if (value) {
               testres = __TEST_ACT(net[__AUX]);
#ifdef __SIMUL_SCRUN
               __TESTRES__[netNum] = testres;
#endif
            }
            __SCFOLLOW(netNum, value && testres);
            break;
      }
   }                     
         
   /* check that all nets have been explored */ 
   {
      int seen = queuePosition + __NUMBER_OF_REGS_KNOWN;
      int tosee = __NUMBER_OF_NETS__ + __NUMBER_OF_REGISTERS__;
      if (seen != tosee) {
#ifdef __SIMUL_SCRUN
      __CAUSALITY_ERROR__;
#endif
         return -1;
     }
   }
  
   /* Set registers. The computed values were temporarily stored in
                     the auxiliary __REGVAL  array.
                     All the register nums are initially in the queue */

   for (queuePosition=0; 
        queuePosition < __NUMBER_OF_INITIAL_NETS__;
        queuePosition++) {
      netNum = __QUEUE__[queuePosition];
      net = __NET_ARRAY__[netNum];
      switch (net[__KIND]) {
         case __REG :
         case __HALT :
            net[__VALUE] = __REGVAL[netNum];
#ifdef TRACE_SCRUN
            fprintf(stderr, "Register %d set to %d\n", 
                            netNum, 
                            __REGVAL[netNum]);
#endif
#ifdef __SIMUL_SCRUN
            if (net[__KIND] == __HALT &&net[__VALUE]) {
               __AppendToList(__HALT_LIST__, (unsigned short)net[__AUX]);
           }
#endif
            break;
        default:
            break;
        }
   }
   return 0;
}


static void __SCRESET__ () {
#ifdef __SIMUL_SCRUN
   int netNum;
   for (netNum=0; netNum < __NUMBER_OF_NETS__; netNum++) {
      __SIMUL_NET_TABLE__[netNum].known = 1;
      __SIMUL_NET_TABLE__[netNum].value = 0;
   }
#endif
}



char* CompilationType = "Interpreted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__cruiseState_ModuleData
};
