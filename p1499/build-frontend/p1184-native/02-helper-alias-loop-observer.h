#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *c245_a,*c245_b;
static size_t c245_phases,c245_results,c245_reads;
static size_t c245_locals[7];
static const size_t c245_headers[]={((size_t)UINTMAX_C(1)),((size_t)UINTMAX_C(3)),((size_t)UINTMAX_C(5)),((size_t)UINTMAX_C(7)),((size_t)UINTMAX_C(9))};
static const size_t c245_header_child[]={((size_t)UINTMAX_C(34)),((size_t)UINTMAX_C(202)),((size_t)UINTMAX_C(87)),((size_t)UINTMAX_C(202)),((size_t)UINTMAX_C(202))};
static const size_t c245_olds[]={((size_t)UINTMAX_C(34)),((size_t)UINTMAX_C(202)),((size_t)UINTMAX_C(87)),((size_t)UINTMAX_C(202))};
static const size_t c245_incoming[]={((size_t)UINTMAX_C(202)),((size_t)UINTMAX_C(87)),((size_t)UINTMAX_C(202)),((size_t)UINTMAX_C(202))};
static const size_t c245_expected_calls=4;
static size_t c245_calls,c245_returns;
static void c245_helper_input(size_t phase){
 assert(c245_calls==c245_returns && c245_calls+1==c245_phases && c245_calls!=c245_expected_calls);
 assert(phase==c245_headers[c245_calls]);
 assert(*((1)?c245_b:c245_a)==c245_header_child[c245_calls]);++c245_calls;
}
static uint8_t c245_helper_output(uint8_t value){
 assert(c245_returns+1==c245_calls && value==c245_incoming[c245_returns]);
 assert(*((1)?c245_b:c245_a)==c245_header_child[c245_returns]);
 printf("C245 actual-helper phase=%zu result=%u\n",c245_headers[c245_returns],(unsigned)value);++c245_returns;return value;
}

static void c245_finish(void){
 assert(c245_calls==c245_expected_calls && c245_returns==c245_calls);
 assert(c245_phases==5 && c245_results==1 && c245_reads==2);
 for(size_t i=0;i<sizeof c245_locals/sizeof c245_locals[0];++i)assert(c245_locals[i]==4);
 puts("C245 actual-original/phase/old/current/sibling/result PASS");
}
static void c245_bind(uint8_t *a,uint8_t *b){
 assert(!c245_a && !c245_b && a!=b && *a==158 && *b==34);
 c245_a=a;c245_b=b;assert(atexit(c245_finish)==0);
}
static void c245_phase(size_t n,uint8_t *a,uint8_t *b){
 assert(a==c245_a && b==c245_b && c245_phases<sizeof c245_headers/sizeof c245_headers[0]);
 assert(n==c245_headers[c245_phases]);
 assert(*((1)?b:a)==c245_header_child[c245_phases]);
 assert(*((1)?a:b)==158);++c245_phases;
}
static void c245_local(size_t symbol,uint8_t v){
 assert(c245_phases && c245_phases<=sizeof c245_olds/sizeof c245_olds[0]);
 switch(symbol){case 6: assert(v==c245_incoming[c245_phases-1]); ++c245_locals[0]; break;
case 7: assert(v==c245_incoming[c245_phases-1]); ++c245_locals[1]; break;
case 8: assert(v==c245_incoming[c245_phases-1]); ++c245_locals[2]; break;
case 10: assert(v==c245_olds[c245_phases-1]); ++c245_locals[3]; break;
case 11: assert(v==c245_olds[c245_phases-1]); ++c245_locals[4]; break;
case 12: assert(v==c245_incoming[c245_phases-1]); ++c245_locals[5]; break;
case 13: assert(v==158); ++c245_locals[6]; break; default: assert(0);}
}
static void c245_result(size_t n){
 assert(n==((size_t)UINTMAX_C(9)));
 assert(*c245_a==158 && *c245_b==202);++c245_results;
}
static void c245_read(uint8_t *a,uint8_t v){
 assert((a==c245_a || a==c245_b) && v==*a);
 assert(v==(a==c245_a?158:202));++c245_reads;
}
#define NL_LOOP_BIND(a,b) c245_bind(a,b)
#define NL_CURRENT_PHASE(n,a,b) c245_phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) c245_local(s,v)
#define NL_CURRENT_RESULT(n) c245_result(n)
#define NL_LOOP_READ(a,v) c245_read(a,v)
