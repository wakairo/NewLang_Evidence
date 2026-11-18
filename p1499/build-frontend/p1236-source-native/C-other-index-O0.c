#define main p1236_case_2_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1236/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1236/native_observer.h"
#define NEWLANG_CURRENT_LOOP_OBSERVER "/workspace/NewLang_Compiler/tests/p1236/native_observer.h"
#define P288_PREHEAP 1
#define P288_INDEX 1
#define P288_TERMINAL 239
#define P288_ROLES {4,6,7,8,9}
#define P288_CALLER_ROLES {2,3,4,5}
#include "/workspace/NewLang_Compiler/build-frontend/p1236-source-native/C-other-index.c"
#undef main
void p1236_case_2(size_t quota){p_reset(quota);int result=p1236_case_2_main();assert(result==0 && p288.finished);}
