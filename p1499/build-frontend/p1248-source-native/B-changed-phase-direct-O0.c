#define main p1248_case_1_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1248/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1248/native_observer.h"
#define NEWLANG_CURRENT_LOOP_OBSERVER "/workspace/NewLang_Compiler/tests/p1248/native_observer.h"
#define P296_PREHEAP 1
#define P296_INDEX 0
#define P296_LIMIT 3
#define P296_TERMINAL 83
#define P296_OLD 211
#define P296_OLD_TRACE {29,83,83,211}
#define P296_NEW_TRACE {83,83,211,83}
#define P296_ROLES {4,6,7,8,9}
#define P296_CALLER_ROLES {2,3,4,5}
#include "/workspace/NewLang_Compiler/build-frontend/p1248-source-native/B-changed-phase-direct.c"
#undef main
void p1248_case_1(size_t quota){p_reset(quota);int result=p1248_case_1_main();assert(result==0 && p296.finished);}
