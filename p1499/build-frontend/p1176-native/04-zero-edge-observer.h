#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *c243_a,*c243_b;
static size_t c243_phases,c243_results,c243_reads;
static size_t c243_locals[5];
static const size_t c243_headers[]={((size_t)UINTMAX_C(7))};
static const size_t c243_header_child[]={((size_t)UINTMAX_C(37))};
static const size_t c243_olds[]={0};
static const size_t c243_incoming[]={0};
static void c243_finish(void){
 assert(c243_phases==1 && c243_results==1 && c243_reads==2);
 for(size_t i=0;i<sizeof c243_locals/sizeof c243_locals[0];++i)assert(c243_locals[i]==0);
 puts("C243 actual-original/phase/old/current/sibling/result PASS");
}
static void c243_bind(uint8_t *a,uint8_t *b){
 assert(!c243_a && !c243_b && a!=b && *a==192 && *b==37);
 c243_a=a;c243_b=b;assert(atexit(c243_finish)==0);
}
static void c243_phase(size_t n,uint8_t *a,uint8_t *b){
 assert(a==c243_a && b==c243_b && c243_phases<sizeof c243_headers/sizeof c243_headers[0]);
 assert(n==c243_headers[c243_phases]);
 assert(*((1)?b:a)==c243_header_child[c243_phases]);
 assert(*((1)?a:b)==192);++c243_phases;
}
static void c243_local(size_t symbol,uint8_t v){
 assert(c243_phases && c243_phases<=sizeof c243_olds/sizeof c243_olds[0]);
 switch(symbol){case 3: assert(v==c243_incoming[c243_phases-1]); ++c243_locals[0]; break;
case 5: assert(v==c243_olds[c243_phases-1]); ++c243_locals[1]; break;
case 6: assert(v==c243_olds[c243_phases-1]); ++c243_locals[2]; break;
case 7: assert(v==c243_incoming[c243_phases-1]); ++c243_locals[3]; break;
case 8: assert(v==192); ++c243_locals[4]; break; default: assert(0);}
}
static void c243_result(size_t n){
 assert(n==((size_t)UINTMAX_C(7)));
 assert(*c243_a==192 && *c243_b==37);++c243_results;
}
static void c243_read(uint8_t *a,uint8_t v){
 assert((a==c243_a || a==c243_b) && v==*a);
 assert(v==(a==c243_a?192:37));++c243_reads;
}
#define NL_LOOP_BIND(a,b) c243_bind(a,b)
#define NL_CURRENT_PHASE(n,a,b) c243_phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) c243_local(s,v)
#define NL_CURRENT_RESULT(n) c243_result(n)
#define NL_LOOP_READ(a,v) c243_read(a,v)
