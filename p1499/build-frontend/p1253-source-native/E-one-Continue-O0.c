#define main p1253_case_5_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1253/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1253/native_observer.h"
#define NEWLANG_CURRENT_LOOP_OBSERVER "/workspace/NewLang_Compiler/tests/p1253/native_observer.h"
#define P299_PREHEAP 1
#define P299_INDEX 0
#define P299_LIMIT 1
#define P299_TERMINAL 229
#define P299_OLD 103
#define P299_INITIAL 0
#define P299_STORES 2
#define P299_HAS_PREFIX 1
#define P299_POLICY 229
#define P299_OLD_TRACE {67,103}
#define P299_NEW_TRACE {103,229}
#define P299_ROLES {7,9,10,11,12}
#define P299_CALLER_ROLES {5,6,7,8}
#define P299_PREFIX_ROLES {3,4}
#include "/workspace/NewLang_Compiler/build-frontend/p1253-source-native/E-one-Continue.c"
#undef main
void p1253_case_5(size_t quota){p_reset(quota);int result=p1253_case_5_main();assert(result==0 && p299.finished);}
