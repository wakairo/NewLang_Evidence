#define P314_INDEX 1
#define P314_LOOP_STORES 3
#define P314_STORES 5
#define P314_BREAK 219
#define P314_INITIAL {151,31}
#define P314_FINAL {219,151}
#define P314_FIELDS {1,1,1,0,1}
#define P314_OLD {31,137,219,151,151}
#define P314_NEW {137,219,151,219,151}
#define P314_SYMBOLS {3,4,5,6,11,16,17,18,19}
#define P314_VALUES {151,151,219,219,151,151,151,151,219}
#define main p1260_case_1_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1260/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1260/native_observer.h"
#define NEWLANG_CURRENT_LOOP_OBSERVER "/workspace/NewLang_Compiler/tests/p1260/native_observer.h"
#include "/workspace/NewLang_Compiler/build-frontend/p1260-source-native/B-second-field-restore-known-return.c"
#undef main
void p1260_case_1(size_t q){p_reset(q);assert(p1260_case_1_main()==0 && p314.finished);}
