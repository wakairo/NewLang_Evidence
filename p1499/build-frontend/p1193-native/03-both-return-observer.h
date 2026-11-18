#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *original[2];
static size_t phases,calls,returns,results,before_reads,after_reads,discards;
static size_t locals[6];
static const size_t headers[]={ 0,1,2,3,4 };
static const size_t child[]={ 85,193,61,193,193 };
static const size_t incoming[]={ 193,61,193,193 };
static const size_t olds[]={ 85,193,61,193 };

static void finish(void){
 assert(phases==5 && calls==4 && returns==calls);
 assert(results==1 && before_reads==0 && after_reads==2);
 assert(discards==0);
 for(size_t i=0;i<sizeof locals/sizeof locals[0];++i)assert(locals[i]==calls);
 puts("C256 physical-original/old/current/helper/phase PASS");
}
static void bind_original(uint8_t *a,uint8_t *b){
 assert(!original[0] && !original[1] && a!=b && *a==221 && *b==85);
 original[0]=a;original[1]=b;assert(atexit(finish)==0);
}
static void phase(size_t value,uint8_t *a,uint8_t *b){
 assert(a==original[0] && b==original[1] && phases<5);
 assert(value==headers[phases] && *original[1]==child[phases]);
 assert(*original[0]==221);++phases;
}
static void local(size_t symbol,size_t value){assert(phases && phases<=4);
 switch(symbol){case 5: assert(value==headers[phases-1]); ++locals[0]; break;case 8: assert(value==incoming[phases-1]); ++locals[1]; break;case 10: assert(value==olds[phases-1]); ++locals[2]; break;case 11: assert(value==olds[phases-1]); ++locals[3]; break;case 12: assert(value==incoming[phases-1]); ++locals[4]; break;case 13: assert(value==221); ++locals[5]; break; default:assert(0);}}
static void result(size_t value){
 assert(value==4 && *original[1]==193);
 assert(*original[0]==221);++results;
}
static void read_original(uint8_t *p,uint8_t value){
 assert((p==original[0] || p==original[1]) && value==*p);
 if(!phases){
  assert(value==(p==original[1]?85:221));++before_reads;
 }else{
  assert(phases==5 && results==1);
  assert(value==(p==original[1]?193:221));++after_reads;
 }
}
static void helper_input(size_t value){
 assert(calls==returns && calls+1==phases && calls<4);
 assert(value==headers[calls] && *original[1]==child[calls]);++calls;
}
static uint8_t helper_return(uint8_t value){
 assert(returns+1==calls && value==incoming[returns]);
 assert(*original[1]==child[returns]);++returns;return value;
}

#define NL_LOOP_BIND(a,b) bind_original(a,b)
#define NL_CURRENT_PHASE(n,a,b) phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) local(s,v)
#define NL_CURRENT_RESULT(n) result(n)
#define NL_LOOP_READ(a,v) read_original(a,v)
