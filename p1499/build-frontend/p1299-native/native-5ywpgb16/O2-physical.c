#define P1299_ROOT_FRAME 0
#define P1299_SYMBOLS {2,3,9,10,11,12}
#define main p1299_guest_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1299/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1299/native_observer.h"
#include "/workspace/NewLang_Compiler/build-frontend/p1299-native/native-5ywpgb16/named.c"
#undef main
int main(void){for(size_t q=0;q<3;++q){memset(&p1299,0,sizeof(p1299));p1299.quota=q;assert(p1299_guest_main()==0 && p1299.finished);printf("H%zu frees=%zu old=103 current=%u sibling=227 same-original=1 named-callee-calls=%zu\n",q,p1299.frees,p1299.computed,p1299.calls+p1299.root_calls);}return 0;}
