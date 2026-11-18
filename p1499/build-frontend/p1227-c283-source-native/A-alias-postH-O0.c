#define main p1227_case_1_original_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1227/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1227/native_observer.h"
#define NEWLANG_CURRENT_LOOP_OBSERVER "/workspace/NewLang_Compiler/tests/p1227/native_observer.h"
#define P280_PREHEAP 0
#define P280_ROLES {11,13,14,15,16}
#include "/workspace/NewLang_Compiler/build-frontend/p1227-c283-source-native/A-alias-postH.c"
#undef main
void p1227_case_1(size_t quota){p_reset(quota);int r=p1227_case_1_original_main();assert(r==0 && p280.finished);}
