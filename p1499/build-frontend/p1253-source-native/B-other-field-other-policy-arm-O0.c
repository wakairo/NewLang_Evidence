#define main p1253_case_1_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1253/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1253/native_observer.h"
#define NEWLANG_CURRENT_LOOP_OBSERVER "/workspace/NewLang_Compiler/tests/p1253/native_observer.h"
#define P299_PREHEAP 1
#define P299_INDEX 1
#define P299_LIMIT 2
#define P299_TERMINAL 229
#define P299_OLD 167
#define P299_INITIAL 0
#define P299_STORES 3
#define P299_HAS_PREFIX 1
#define P299_POLICY 229
#define P299_OLD_TRACE {181,103,167}
#define P299_NEW_TRACE {103,167,229}
#define P299_ROLES {7,9,10,11,12}
#define P299_CALLER_ROLES {5,6,7,8}
#define P299_PREFIX_ROLES {3,4}
#include "/workspace/NewLang_Compiler/build-frontend/p1253-source-native/B-other-field-other-policy-arm.c"
#undef main
void p1253_case_1(size_t quota){p_reset(quota);int result=p1253_case_1_main();assert(result==0 && p299.finished);}
