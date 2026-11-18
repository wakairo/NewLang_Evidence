#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static uint8_t *original[2];
static size_t phases,results,reads,local_count;
static const size_t headers[]={9,11};
static const size_t incoming[]={211};
static const size_t olds[]={31};
static const size_t child[]={31,211};
static void finish(void){
 assert(phases==2 && results==1 && reads==2);
 assert(local_count==5);
 puts("P1203 physical-original/old/current/sibling/actual-Break PASS");
}
static void bind(uint8_t *a,uint8_t *b){
 assert(!original[0] && a!=b && *a==31 && *b==199);
 original[0]=a;original[1]=b;assert(atexit(finish)==0);
}
static void phase(size_t value,uint8_t *a,uint8_t *b){
 assert(a==original[0] && b==original[1] && phases<2);
 assert(value==headers[phases] && *original[0]==child[phases]);
 assert(*original[1]==199);++phases;
}
static void local(size_t symbol,size_t value){
 assert(phases && phases<=1);
 switch(symbol){case 4: assert(value==incoming[phases-1]); break;case 6: assert(value==olds[phases-1]); break;case 7: assert(value==olds[phases-1]); break;case 8: assert(value==incoming[phases-1]); break;case 9: assert(value==199); break; default:assert(0);}++local_count;
}
static void result(size_t value){
 assert(phases==2 && value==(size_t)UINTMAX_C(73));
 assert(*original[0]==211 && *original[1]==199);++results;
}
static void read_original(uint8_t *p,uint8_t value){
 assert(results==1 && (p==original[0] || p==original[1]) && value==*p);++reads;
}
#define NL_LOOP_BIND(a,b) bind(a,b)
#define NL_CURRENT_PHASE(v,a,b) phase(v,a,b)
#define NL_CURRENT_LOCAL(s,v) local(s,v)
#define NL_CURRENT_RESULT(v) result(v)
#define NL_LOOP_READ(p,v) read_original(p,v)
