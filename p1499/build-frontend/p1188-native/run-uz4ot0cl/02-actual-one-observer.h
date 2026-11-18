#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *original[2];
static size_t phases,calls,returns,results,reads,locals[6];
static const size_t headers[]={ 1,3,5,7,9 };
static const size_t incoming[]={ 87,202,202,202 };
static const size_t olds[]={ 34,87,202,202 };
static const size_t child[]={ 34,87,202,202,202 };
static void finish(void){
 assert(phases==5 && calls==4 && returns==calls);
 assert(results==1 && reads==2);
 for(size_t i=0;i<sizeof locals/sizeof locals[0];++i)assert(locals[i]==calls);
 puts("C247 actual physical-original/old/current/sibling/phase/result PASS");
}
static void bind_original(uint8_t *a,uint8_t *b){
 assert(!original[0] && !original[1] && a!=b && *a==158 && *b==34);
 original[0]=a;original[1]=b;assert(atexit(finish)==0);
}
static void phase(size_t n,uint8_t *a,uint8_t *b){
 assert(a==original[0] && b==original[1] && phases<5);
 assert(n==headers[phases] && *original[1]==child[phases]);
 assert(*original[0]==158);++phases;
}
static void local(size_t symbol,size_t value){
 assert(phases && phases<=4);
 switch(symbol){ case 3: assert(value==headers[phases-1]); ++locals[0]; break;
case 5: assert(value==incoming[phases-1]); ++locals[1]; break;
case 7: assert(value==olds[phases-1]); ++locals[2]; break;
case 8: assert(value==olds[phases-1]); ++locals[3]; break;
case 9: assert(value==incoming[phases-1]); ++locals[4]; break;
case 10: assert(value==158); ++locals[5]; break; default:assert(0); }
}
static void helper_input(size_t n){
 assert(calls==returns && calls+1==phases && calls<4);
 assert(n==headers[calls] && *original[1]==child[calls]);++calls;
}
static uint8_t helper_return(uint8_t value){
 assert(returns+1==calls && value==incoming[returns]);
 assert(*original[1]==child[returns]);++returns;return value;
}
static void result(size_t value){
 assert(value==9 && *original[1]==202);
 assert(*original[0]==158);++results;
}
static void read_original(uint8_t *p,uint8_t value){
 assert((p==original[0] || p==original[1]) && value==*p);
 assert(value==(p==original[1]?202:158));++reads;
}
#define NL_LOOP_BIND(a,b) bind_original(a,b)
#define NL_CURRENT_PHASE(n,a,b) phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) local(s,v)
#define NL_CURRENT_RESULT(n) result(n)
#define NL_LOOP_READ(a,v) read_original(a,v)
