#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *original[2];
static size_t phases,calls,returns,results,before_reads,after_reads,discards;
static size_t locals[5];
static const size_t headers[]={ 0,1,2,3 };
static const size_t child[]={ 8,41,142,142 };
static const size_t incoming[]={ 41,142,142 };
static const size_t olds[]={ 8,41,142 };

static void finish(void){
 assert(phases==4 && calls==3 && returns==calls);
 assert(results==1 && before_reads==0 && after_reads==2);
 assert(discards==0);
 for(size_t i=0;i<sizeof locals/sizeof locals[0];++i)assert(locals[i]==calls);
 puts("C256 physical-original/old/current/helper/phase PASS");
}
static void bind_original(uint8_t *a,uint8_t *b){
 assert(!original[0] && !original[1] && a!=b && *a==8 && *b==233);
 original[0]=a;original[1]=b;assert(atexit(finish)==0);
}
static void phase(size_t value,uint8_t *a,uint8_t *b){
 assert(a==original[0] && b==original[1] && phases<4);
 assert(value==headers[phases] && *original[0]==child[phases]);
 assert(*original[1]==233);++phases;
}
static void local(size_t symbol,size_t value){assert(phases && phases<=3);
 switch(symbol){case 4: assert(value==incoming[phases-1]); ++locals[0]; break;case 6: assert(value==olds[phases-1]); ++locals[1]; break;case 7: assert(value==olds[phases-1]); ++locals[2]; break;case 8: assert(value==incoming[phases-1]); ++locals[3]; break;case 9: assert(value==233); ++locals[4]; break; default:assert(0);}}
static void result(size_t value){
 assert(value==3 && *original[0]==142);
 assert(*original[1]==233);++results;
}
static void read_original(uint8_t *p,uint8_t value){
 assert((p==original[0] || p==original[1]) && value==*p);
 if(!phases){
  assert(value==(p==original[0]?8:233));++before_reads;
 }else{
  assert(phases==4 && results==1);
  assert(value==(p==original[0]?142:233));++after_reads;
 }
}
static void helper_input(size_t value){
 assert(calls==returns && calls+1==phases && calls<3);
 assert(value==headers[calls] && *original[0]==child[calls]);++calls;
}
static uint8_t helper_return(uint8_t value){
 assert(returns+1==calls && value==incoming[returns]);
 assert(*original[0]==child[returns]);++returns;return value;
}

#define NL_LOOP_BIND(a,b) bind_original(a,b)
#define NL_CURRENT_PHASE(n,a,b) phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) local(s,v)
#define NL_CURRENT_RESULT(n) result(n)
#define NL_LOOP_READ(a,v) read_original(a,v)
