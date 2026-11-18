#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_C(n) ((size_t)UINTMAX_C(n))
static uint8_t *a0,*a1;
static size_t phases,results,reads;
static size_t locals[4];
static const size_t headers[]={SIZE_C(9)};
static const uint8_t olds[]={0};
static void finish(void) {
 assert(phases==1 && results==1 && reads==2);
 for(size_t i=0;i<sizeof locals/sizeof locals[0];++i) assert(locals[i]==0);
 puts("C238 original-address/old-copy/current/sibling/phase/result PASS");
}
static void bind(uint8_t *a,uint8_t *b) {
 assert(!a0 && !a1 && a!=b && *a==45 && *b==173);
 a0=a; a1=b; assert(atexit(finish)==0);
}
static void phase(size_t n,uint8_t *a,uint8_t *b) {
 assert(a==a0 && b==a1 && phases<sizeof headers/sizeof headers[0]);
 assert(n==headers[phases]);
 assert(*((0)?b:a)==45);
 assert(*((0)?a:b)==173); ++phases;
}
static void local(size_t symbol,uint8_t value) {
 assert(phases && phases<=0);
 switch(symbol){case 4: assert(value==olds[phases-1]); ++locals[0]; break;
case 5: assert(value==olds[phases-1]); ++locals[1]; break;
case 6: assert(value==45); ++locals[2]; break;
case 7: assert(value==173); ++locals[3]; break; default: assert(0); }
}
static void result(size_t n) {
 assert(n==SIZE_C(9));
 assert(*a0==45 && *a1==173); ++results;
}
static void read_value(uint8_t *a,uint8_t v) {
 assert((a==a0 || a==a1) && v==*a);
 assert(v==(a==a0?45:173)); ++reads;
}
#define NL_LOOP_BIND(a,b) bind(a,b)
#define NL_LOOP_READ(a,v) read_value(a,v)
#define NL_CURRENT_PHASE(n,a,b) phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) local(s,v)
#define NL_CURRENT_RESULT(n) result(n)
