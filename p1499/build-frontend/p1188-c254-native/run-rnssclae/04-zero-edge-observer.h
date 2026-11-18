#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *original[2];
static size_t phases,calls,returns,results,before_reads,after_reads,discards;
static size_t locals[7];
static const size_t headers[]={ 4 };
static const size_t child[]={ 58 };

static void finish(void){
 assert(phases==1 && calls==0 && returns==calls);
 assert(results==1 && before_reads==1 && after_reads==2);
 assert(discards==0);
 for(size_t i=0;i<sizeof locals/sizeof locals[0];++i)assert(locals[i]==calls);
 puts("C254 physical-original/captured-old/current/helper/phase PASS");
}
static void bind_original(uint8_t *a,uint8_t *b){
 assert(!original[0] && !original[1] && a!=b && *a==218 && *b==58);
 original[0]=a;original[1]=b;assert(atexit(finish)==0);
}
static void phase(size_t value,uint8_t *a,uint8_t *b){
 assert(a==original[0] && b==original[1] && phases<1);
 assert(value==headers[phases] && *original[1]==child[phases]);
 assert(*original[0]==218);++phases;
}
static void local(size_t symbol,size_t value){(void)symbol;(void)value;assert(0);}
static void result(size_t value){
 assert(value==4 && *original[1]==58);
 assert(*original[0]==218);++results;
}
static void read_original(uint8_t *p,uint8_t value){
 assert((p==original[0] || p==original[1]) && value==*p);
 if(!phases){
  assert(value==(p==original[1]?58:218));++before_reads;
 }else{
  assert(phases==1 && results==1);
  assert(value==(p==original[1]?58:218));++after_reads;
 }
}
static void helper_input(size_t value){(void)value;assert(0);}
static uint8_t helper_return(uint8_t value){assert(0);return value;}
static void capture_discard(size_t symbol,uint8_t value){
 (void)symbol;(void)value;assert(0);
}

#define NL_LOOP_BIND(a,b) bind_original(a,b)
#define NL_CURRENT_PHASE(n,a,b) phase(n,a,b)
#define NL_CURRENT_LOCAL(s,v) local(s,v)
#define NL_CURRENT_RESULT(n) result(n)
#define NL_LOOP_READ(a,v) read_original(a,v)
