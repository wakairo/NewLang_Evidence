#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *original[2];
static size_t phases,calls,returns,results,reads,locals[5];
static const size_t headers[]={ 0,1,2,3,4,5 };
static const size_t incoming[]={ 53,53,149,149,149 };
static const size_t olds[]={ 26,53,53,149,149 };
static const size_t child[]={ 26,53,53,149,149,149 };
static void finish(void){
 assert(phases==6 && calls==5 && returns==calls);
 assert(results==1 && reads==2);
 for(size_t i=0;i<sizeof locals/sizeof locals[0];++i)assert(locals[i]==calls);
 puts("C247 actual physical-original/old/current/sibling/phase/result PASS");
}
static void bind_original(uint8_t *a,uint8_t *b){
 assert(!original[0] && !original[1] && a!=b && *a==26 && *b==211);
 original[0]=a;original[1]=b;assert(atexit(finish)==0);
}
static void phase(size_t n,uint8_t *a,uint8_t *b){
 assert(a==original[0] && b==original[1] && phases<6);
 assert(n==headers[phases] && *original[0]==child[phases]);
 assert(*original[1]==211);++phases;
}
static void local(size_t symbol,size_t value){
 assert(phases && phases<=5);
 switch(symbol){ case 6: assert(value==incoming[phases-1]); ++locals[0]; break;
case 8: assert(value==olds[phases-1]); ++locals[1]; break;
case 9: assert(value==olds[phases-1]); ++locals[2]; break;
case 10: assert(value==incoming[phases-1]); ++locals[3]; break;
case 11: assert(value==211); ++locals[4]; break; default:assert(0); }
}
static void helper_input(size_t n){
 assert(calls==returns && calls+1==phases && calls<5);
 assert(n==headers[calls] && *original[0]==child[calls]);++calls;
}
static uint8_t helper_return(uint8_t value){
 assert(returns+1==calls && value==incoming[returns]);
 assert(*original[0]==child[returns]);++returns;return value;
}
static void result(size_t value){
 assert(value==5 && *original[0]==149);
 assert(*original[1]==211);++results;
}
static void read_original(uint8_t *p,uint8_t value){
 assert((p==original[0] || p==original[1]) && value==*p);
 assert(value==(p==original[0]?149:211));++reads;
}
#define NL_LOOP_BIND(a,b) bind_original(a,b)
#define NL_CURRENT_PHASE(n,a,b) phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) local(s,v)
#define NL_CURRENT_RESULT(n) result(n)
#define NL_LOOP_READ(a,v) read_original(a,v)
