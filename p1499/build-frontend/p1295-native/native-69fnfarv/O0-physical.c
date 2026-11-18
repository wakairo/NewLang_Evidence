#define P1295_ROOT_FRAME 0
#define P1295_SYMBOLS {2,3,5,6,7,8}
#define main p1295_guest_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1295/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1295/native_observer.h"
#include "/workspace/NewLang_Compiler/build-frontend/p1295-native/native-69fnfarv/positive.c"
#undef main
int main(void){for(size_t q=0;q<3;++q){memset(&p1295,0,sizeof(p1295));p1295.quota=q;assert(p1295_guest_main()==0 && p1295.finished);printf("H%zu frees=%zu old=101 current=%u sibling=213 same-pre-H-original=1\n",q,p1295.frees,p1295.computed);}return 0;}
