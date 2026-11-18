#define P1272_BYTE 43
#define P1272_SYMBOLS {17,18,19}
#define main p1272_guest_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1272/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1272/native_observer.h"
#include "/workspace/NewLang_Compiler/build-frontend/p1272-source-native/run-wzp2y214/P-renamed-credit.c"
#undef main
int main(void) { for(size_t q=0;q<3;++q){memset(&p1272,0,sizeof(p1272));p1272.quota=q;assert(p1272_guest_main()==0 && p1272.finished);printf("physical quota=%zu frees=%zu copies=%zu byte=%u\n",q,p1272.frees,p1272.copies,P1272_BYTE); } return 0;}
