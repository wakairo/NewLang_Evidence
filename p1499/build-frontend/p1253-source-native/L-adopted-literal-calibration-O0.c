#define main p1253_case_3_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1253/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1253/native_observer.h"
#define NEWLANG_CURRENT_LOOP_OBSERVER "/workspace/NewLang_Compiler/tests/p1253/native_observer.h"
#define P299_PREHEAP 1
#define P299_INDEX 0
#define P299_LIMIT 2
#define P299_TERMINAL 43
#define P299_OLD 167
#define P299_INITIAL 0
#define P299_STORES 3
#define P299_HAS_PREFIX 0
#define P299_POLICY 43
#define P299_OLD_TRACE {67,103,167}
#define P299_NEW_TRACE {103,167,43}
#define P299_ROLES {4,6,7,8,9}
#define P299_CALLER_ROLES {2,3,4,5}
#define P299_PREFIX_ROLES {0,0}
#include "/workspace/NewLang_Compiler/build-frontend/p1253-source-native/L-adopted-literal-calibration.c"
#undef main
void p1253_case_3(size_t quota){p_reset(quota);int result=p1253_case_3_main();assert(result==0 && p299.finished);}
