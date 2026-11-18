#define P1291_OLD 61
#define P1291_NEW 131
#define P1291_SIBLING 181
#define P1291_FIELD 1
#define P1291_FRONT 227
#define P1291_H0 7
#define P1291_H1 19
#define P1291_FRAME 11
#define P1291_ARM_FRAME 6
#define P1291_ARM_SYMBOL 23
#define P1291_OUTER_FRAME 0
#define P1291_SYMBOLS {26,27,33,34,35,36}
#define P1291_RESULTS {1,2,3}
#define main p1291_guest_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1291/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1291/native_observer.h"
#include "/workspace/NewLang_Compiler/build-frontend/p1291-native/native-qffrhv0p/B-index-value-control.nl.c"
#undef main
int main(void){for(size_t q=0;q<3;++q){memset(&p1291,0,sizeof(p1291));p1291.quota=q;assert(p1291_guest_main()==0 && p1291.finished);printf("H%zu frees=%zu writes=%zu continuation=%zu\n",q,p1291.frees,p1291.writes,p1291.outer);}return 0;}
