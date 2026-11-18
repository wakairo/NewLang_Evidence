#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *original[2];
static size_t phases,calls,returns,results,reads,discards,locals[7];
static const size_t headers[]={ 1,3,5,7 };
static const size_t incoming[]={ 74,74,205 };
static const size_t olds[]={ 19,74,74 };
static const size_t child[]={ 19,74,74,205 };
static void finish(void){
 assert(phases==4 && calls==3 && returns==calls);
 assert(results==1 && reads==2 && discards==18);
 for(size_t i=0;i<sizeof locals/sizeof locals[0];++i)assert(locals[i]==3);
 puts("C250a phase/alias discard physical-original/current PASS");
}
static void bind_original(uint8_t *a,uint8_t *b){
 assert(!original[0] && !original[1] && a!=b && *a==144 && *b==19);
 original[0]=a;original[1]=b;assert(atexit(finish)==0);
}
static void phase(size_t value,uint8_t *a,uint8_t *b){
 assert(a==original[0] && b==original[1] && phases<4);
 assert(value==headers[phases] && *original[1]==child[phases]);
 assert(*original[0]==144);++phases;
}
static void local(size_t symbol,size_t value){
 assert(phases && phases<=3);
 switch(symbol){ case 6: assert(value==headers[phases-1]); ++locals[0]; break;case 7: assert(value==headers[phases-1]); ++locals[1]; break;case 13: assert(value==incoming[phases-1]); ++locals[2]; break;case 15: assert(value==olds[phases-1]); ++locals[3]; break;case 16: assert(value==olds[phases-1]); ++locals[4]; break;case 17: assert(value==incoming[phases-1]); ++locals[5]; break;case 18: assert(value==144); ++locals[6]; break; default:assert(0); }
}
static void discard(size_t value){
 assert(phases && phases<=3 && value==headers[phases-1]);++discards;
}
static void result(size_t value){
 assert(value==7 && *original[1]==205);
 assert(*original[0]==144);++results;
}
static void read_original(uint8_t *p,uint8_t value){
 assert((p==original[0] || p==original[1]) && value==*p);
 assert(value==(p==original[1]?205:144));++reads;
}
#define NL_LOOP_BIND(a,b) bind_original(a,b)
#define NL_CURRENT_PHASE(n,a,b) phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) local(s,v)
#define NL_CURRENT_RESULT(n) result(n)
#define NL_LOOP_READ(a,v) read_original(a,v)

static void helper_input(size_t value){
 assert(calls==returns && calls+1==phases && calls<3);
 assert(value==headers[calls] && *original[1]==child[calls]);++calls;
}
static uint8_t helper_return(uint8_t value){
 assert(returns+1==calls && value==incoming[returns]);
 assert(*original[1]==child[returns]);++returns;return value;
}
