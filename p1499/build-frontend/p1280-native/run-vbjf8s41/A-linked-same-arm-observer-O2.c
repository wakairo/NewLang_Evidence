#define P1280_BYTE 83
#define P1280_LINKED 1
#define P1280_SYMBOLS {27,34,35,36}
#define main p1280_guest_main
#define NEWLANG_NODE_OBSERVER "/workspace/NewLang_Compiler/tests/p1280/native_observer.h"
#define NEWLANG_HEAP_OBSERVER "/workspace/NewLang_Compiler/tests/p1280/native_observer.h"
#include "/workspace/NewLang_Compiler/build-frontend/p1280-native/run-vbjf8s41/A-linked-same-arm.c"
#undef main
int main(void) { for(size_t q=0;q<3;++q){memset(&p1280,0,sizeof(p1280));p1280.quota=q;assert(p1280_guest_main()==0 && p1280.finished);printf("physical quota=%zu frees=%zu copies=%zu byte=%u\n",q,p1280.frees,p1280.t_writes,P1280_BYTE); } return 0;}
