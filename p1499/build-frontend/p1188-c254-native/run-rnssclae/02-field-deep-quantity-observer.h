#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *original[2];
static size_t phases,calls,returns,results,before_reads,after_reads,discards;
static size_t locals[9];
static const size_t headers[]={ 1,3,5,7 };
static const size_t child[]={ 11,11,97,11 };
static const size_t incoming[]={ 11,97,11 };
static const size_t olds[]={ 11,11,97 };

static void finish(void){
 assert(phases==4 && calls==3 && returns==calls);
 assert(results==1 && before_reads==1 && after_reads==2);
 assert(discards==6);
 for(size_t i=0;i<sizeof locals/sizeof locals[0];++i)assert(locals[i]==calls);
 puts("C254 physical-original/captured-old/current/helper/phase PASS");
}
static void bind_original(uint8_t *a,uint8_t *b){
 assert(!original[0] && !original[1] && a!=b && *a==227 && *b==11);
 original[0]=a;original[1]=b;assert(atexit(finish)==0);
}
static void phase(size_t value,uint8_t *a,uint8_t *b){
 assert(a==original[0] && b==original[1] && phases<4);
 assert(value==headers[phases] && *original[1]==child[phases]);
 assert(*original[0]==227);++phases;
}
static void local(size_t symbol,size_t value){assert(phases && phases<=3);
 switch(symbol){case 10: assert(value==11); ++locals[0]; break;case 11: assert(value==headers[phases-1]); ++locals[1]; break;case 12: assert(value==headers[phases-1]); ++locals[2]; break;case 16: assert(value==incoming[phases-1]); ++locals[3]; break;case 18: assert(value==olds[phases-1]); ++locals[4]; break;case 19: assert(value==olds[phases-1]); ++locals[5]; break;case 20: assert(value==incoming[phases-1]); ++locals[6]; break;case 21: assert(value==227); ++locals[7]; break;case 22: assert(value==11); ++locals[8]; break; default:assert(0);}}
static void result(size_t value){
 assert(value==7 && *original[1]==11);
 assert(*original[0]==227);++results;
}
static void read_original(uint8_t *p,uint8_t value){
 assert((p==original[0] || p==original[1]) && value==*p);
 if(!phases){
  assert(value==(p==original[1]?11:227));++before_reads;
 }else{
  assert(phases==4 && results==1);
  assert(value==(p==original[1]?11:227));++after_reads;
 }
}
static void helper_input(size_t value){
 assert(calls==returns && calls+1==phases && calls<3);
 assert(value==headers[calls] && *original[1]==child[calls]);++calls;
}
static uint8_t helper_return(uint8_t value){
 assert(returns+1==calls && value==incoming[returns]);
 assert(*original[1]==child[returns]);++returns;return value;
}
static void capture_discard(size_t symbol,uint8_t value){
 assert(phases && phases<=3);switch(symbol){case 2: assert(value==11); break;case 3: assert(value==11); break;case 4: assert(value==11); break;case 5: assert(value==11); break;default:assert(0);}++discards;
}

#define NL_LOOP_BIND(a,b) bind_original(a,b)
#define NL_CURRENT_PHASE(n,a,b) phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) local(s,v)
#define NL_CURRENT_RESULT(n) result(n)
#define NL_LOOP_READ(a,v) read_original(a,v)
