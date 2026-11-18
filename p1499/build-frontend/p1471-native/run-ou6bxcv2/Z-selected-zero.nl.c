/* Bounded Checked-C representation, not a NewLang ABI. */
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
_Static_assert(CHAR_BIT == 8, "NewLang C17 requires 8-bit bytes");
_Static_assert(UINT8_MAX == 255 && sizeof(uint8_t) == 1 && ((uint8_t)-1) == 255, "NewLang C17 requires exact 8-bit uint8_t");
typedef struct nl_node nl_node;
typedef struct { unsigned tag; const nl_node *ptr; } nl_node_option;
struct nl_node { nl_node_option f0; uint8_t f1; };
#ifdef NEWLANG_NODE_OBSERVER
#include NEWLANG_NODE_OBSERVER
#else
#define NL_NODE_BIND(...) ((void)0)
#define NL_NODE_REPLACE(...) ((void)0)
#define NL_NODE_ARM(...) ((void)0)
#define NL_NODE_RELOAN(...) ((void)0)
#define NL_NODE_FINISH() ((void)0)
#endif
_Static_assert(sizeof(nl_node)==24 && _Alignof(nl_node)==8, "checked H target layout");
_Static_assert(sizeof(void*)==8 && offsetof(nl_node,f0)==0 && offsetof(nl_node,f1)==16, "private member plan");
_Static_assert(sizeof(nl_node_option)==16 && _Alignof(nl_node_option)==8 && _Generic(((nl_node *)0)->f0,nl_node_option:1,default:0) && _Generic(((nl_node *)0)->f1,uint8_t:1,default:0) && _Generic(((nl_node_option *)0)->ptr,const nl_node *:1,default:0), "private member types");
typedef struct {void *handle;} nl_allocation;
typedef struct {unsigned char *bytes;size_t length;} nl_storage;
typedef struct {unsigned char *bytes;size_t length;} nl_slot;
typedef struct {size_t token;} nl_domain;
typedef struct {const nl_node *ptr;nl_allocation allocation;nl_domain domain;} nl_live_tail;
typedef struct {unsigned tag;nl_live_tail packet;} nl_custody;
typedef struct {nl_allocation allocation;nl_storage raw;} nl_backing;
#ifdef NEWLANG_HEAP_OBSERVER
#include NEWLANG_HEAP_OBSERVER
#else
#define NL_HEAP_TRIAL(...) ((void)0)
#define NL_HEAP_ARM(...) ((void)0)
#define NL_HEAP_DOMAIN(...) ((void)0)
#define NL_HEAP_SLOT(...) ((void)0)
#define NL_HEAP_INITIALIZE(...) ((void)0)
#define NL_HEAP_RELOAN(...) ((void)0)
#define NL_HEAP_ROOT(...) ((void)0)
#define NL_HEAP_FIELD(...) ((void)0)
#define NL_HEAP_COPY(...) ((void)0)
#define NL_HEAP_CHANGE(...) ((void)0)
#define NL_HEAP_SCOPE_END(...) ((void)0)
#define NL_HEAP_END(...) ((void)0)
#define NL_HEAP_RAW(...) ((void)0)
#define NL_HEAP_FINALIZE(...) ((void)0)
#define NL_HEAP_RELEASE(...) ((void)0)
#define NL_HEAP_FINISH() ((void)0)
#define NL_HEAP_HANDOFF(...) ((void)0)
#define NL_HEAP_RECEIVER_ENTER(...) ((void)0)
#define NL_HEAP_RECEIVER_EXIT() ((void)0)
#define NL_HEAP_RETURNED(...) ((void)0)
#define NL_LIVE_SEND(...) ((void)0)
#define NL_LIVE_ENTER(...) ((void)0)
#define NL_LIVE_RETURN(...) ((void)0)
#define NL_LIVE_RECEIVE(...) ((void)0)
#endif
#ifndef NL_CUSTODY_ENTER
#define NL_CUSTODY_ENTER(...) ((void)0)
#define NL_CUSTODY_STORED(...) ((void)0)
#define NL_CUSTODY_RETURNED(...) ((void)0)
#define NL_CUSTODY_EXTRACT(...) ((void)0)
#define NL_CUSTODY_NONE(...) ((void)0)
#define NL_CUSTODY_POLICY(...) ((void)0)
#define NL_CUSTODY_LOAN(...) ((void)0)
#endif
_Static_assert(SIZE_MAX==UINTMAX_C(18446744073709551615),"usize width");
#ifndef NL_SCALAR_BOOL_RESULT
#define NL_SCALAR_BOOL_RESULT(...) ((void)0)
#endif
#ifndef NL_SCALAR_IF_CONDITION
#define NL_SCALAR_IF_CONDITION(...) ((void)0)
#endif
#ifndef NL_SCALAR_IF_RESULT
#define NL_SCALAR_IF_RESULT(...) ((void)0)
#endif
typedef struct {uint8_t f0,f1;} nl_copy_record;
#ifndef NL_MIXED_OWNER_LOCAL
#define NL_MIXED_OWNER_LOCAL(...) ((void)0)
#endif
#ifndef NL_MIXED_COPY_BIND
#define NL_MIXED_COPY_BIND(...) ((void)0)
#endif
#ifndef NL_MIXED_COPY_STORE
#define NL_MIXED_COPY_STORE(...) ((void)0)
#endif
#ifndef NL_MIXED_COPY_CALL
#define NL_MIXED_COPY_CALL(...) ((void)0)
#endif
static uint8_t nl_copy_state_10(uint8_t *target,uint8_t next){uint8_t old=*target;*target=next;NL_MIXED_COPY_CALL(target,old,next);return old;}
static void nl_owner_13(const nl_node *nl_b_19_51,nl_allocation nl_b_19_52,nl_domain nl_b_19_53) {
NL_HEAP_RECEIVER_ENTER(nl_b_19_51,nl_b_19_52.handle,nl_b_19_53.token,19,51,52,53,&nl_b_19_52,&nl_b_19_53);
nl_slot nl_v_116;
{ const nl_domain *nl_b_20_54 = &nl_b_19_53;
(void)nl_b_20_54;
const nl_node * nl_v_117 = nl_b_19_51;
NL_HEAP_END(nl_v_117,nl_b_20_54->token);
nl_slot nl_v_118 = {(unsigned char *)nl_v_117,24};
nl_v_116 = nl_v_118;
}
nl_slot nl_b_19_55 = nl_v_116;
(void)nl_b_19_55;
NL_NODE_BIND(19, 55, 4, &nl_b_19_55);
nl_slot nl_v_119 = nl_b_19_55;
nl_b_19_55 = (nl_slot){0};
nl_storage nl_v_120 = {nl_v_119.bytes,nl_v_119.length};
NL_HEAP_RAW(nl_v_120.bytes,nl_v_120.length);
nl_storage nl_b_19_56 = nl_v_120;
(void)nl_b_19_56;
NL_NODE_BIND(19, 56, 4, &nl_b_19_56);
nl_domain nl_v_121 = nl_b_19_53;
nl_b_19_53 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_121.token);
(void)nl_v_121;
nl_allocation nl_v_122 = nl_b_19_52;
nl_b_19_52 = (nl_allocation){0};
nl_storage nl_v_123 = nl_b_19_56;
nl_b_19_56 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_122.handle,nl_v_123.bytes,nl_v_123.length);
free(nl_v_122.handle);
nl_v_122.handle=NULL;
nl_v_123.bytes=NULL;
(void)nl_v_123;
NL_HEAP_RECEIVER_EXIT();
}
static nl_live_tail nl_producer_14(nl_node_option * nl_b_17_38,const nl_node * nl_b_17_39,nl_allocation nl_b_17_40,nl_domain nl_b_17_41) {
NL_LIVE_ENTER(nl_b_17_38,nl_b_17_39,nl_b_17_40.handle,nl_b_17_41.token);
nl_node_option * nl_v_95 = nl_b_17_38;
nl_node_option nl_v_96 = { 0, NULL };
nl_node_option nl_v_97 = *nl_v_95;
*nl_v_95 = nl_v_96;
NL_HEAP_CHANGE(nl_v_95,&nl_v_97,2);
(void)nl_v_97;
const nl_node * nl_v_98 = nl_b_17_39;
nl_allocation nl_v_99 = nl_b_17_40;
nl_b_17_40 = (nl_allocation){0};
nl_domain nl_v_100 = nl_b_17_41;
nl_b_17_41 = (nl_domain){0};
nl_live_tail nl_v_101 = {nl_v_98,nl_v_99,nl_v_100};
nl_live_tail nl_b_17_43 = nl_v_101;
nl_v_101 = (nl_live_tail){0};
NL_MIXED_OWNER_LOCAL(&nl_b_17_43);
nl_live_tail nl_v_102 = nl_b_17_43;
nl_b_17_43 = (nl_live_tail){0};
NL_LIVE_RETURN(nl_v_102);
return nl_v_102;
}
int main(void) {
uint8_t nl_v_1 = 87;
uint8_t nl_v_2 = 13;
nl_copy_record nl_v_3 = {nl_v_1,nl_v_2};
nl_copy_record nl_b_0_1 = nl_v_3;
NL_MIXED_COPY_BIND(0,1,&nl_b_0_1.f0,&nl_b_0_1.f1);
uint8_t nl_v_4 = 0;
uint8_t nl_v_5 = nl_copy_state_10(&nl_b_0_1.f0,nl_v_4);
uint8_t nl_b_0_6 = nl_v_5;
(void)nl_b_0_6;
NL_NODE_BIND(0, 6, 4, &nl_b_0_6);
uint8_t nl_v_6;
void *nl_heap_7 = malloc(24);
NL_HEAP_TRIAL(nl_heap_7,24,8);
if (nl_heap_7 == NULL) {
NL_HEAP_ARM(1);
uint8_t nl_v_8=nl_b_0_1.f0;
uint8_t nl_b_1_7 = nl_v_8;
(void)nl_b_1_7;
NL_NODE_BIND(1, 7, 4, &nl_b_1_7);
uint8_t nl_v_9=nl_b_0_1.f1;
uint8_t nl_b_1_8 = nl_v_9;
(void)nl_b_1_8;
NL_NODE_BIND(1, 8, 4, &nl_b_1_8);
uint8_t nl_v_10 = nl_b_0_6;
uint8_t nl_b_1_9 = nl_v_10;
(void)nl_b_1_9;
NL_NODE_BIND(1, 9, 4, &nl_b_1_9);
NL_HEAP_FINISH();
return 0;
}
else {
NL_HEAP_ARM(2);
nl_backing nl_b_2_7 = { {nl_heap_7}, {(unsigned char *)nl_heap_7,24} };
nl_backing nl_v_11 = nl_b_2_7;
nl_b_2_7 = (nl_backing){0};
nl_allocation nl_b_2_8 = nl_v_11.allocation;
(void)nl_b_2_8;
nl_storage nl_b_2_9 = nl_v_11.raw;
(void)nl_b_2_9;
nl_v_11 = (nl_backing){0};
nl_allocation nl_v_12 = nl_b_2_8;
nl_b_2_8 = (nl_allocation){0};
nl_allocation nl_b_2_10 = nl_v_12;
(void)nl_b_2_10;
NL_NODE_BIND(2, 10, 4, &nl_b_2_10);
nl_storage nl_v_13 = nl_b_2_9;
nl_b_2_9 = (nl_storage){0};
nl_slot nl_v_14 = {nl_v_13.bytes,nl_v_13.length};
NL_HEAP_SLOT(nl_v_14.bytes,nl_v_14.length);
nl_slot nl_b_2_11 = nl_v_14;
(void)nl_b_2_11;
NL_NODE_BIND(2, 11, 4, &nl_b_2_11);
nl_domain nl_v_15 = {1};
NL_HEAP_DOMAIN(nl_v_15.token);
nl_domain nl_b_2_12 = nl_v_15;
(void)nl_b_2_12;
NL_NODE_BIND(2, 12, 4, &nl_b_2_12);
const nl_node * nl_v_16;
{ const nl_domain *nl_b_3_13 = &nl_b_2_12;
(void)nl_b_3_13;
nl_slot nl_v_17 = nl_b_2_11;
nl_b_2_11 = (nl_slot){0};
nl_node_option nl_v_18 = { 0, NULL };
uint8_t nl_v_19 = 76;
nl_node nl_v_20 = { nl_v_18, nl_v_19 };
const nl_domain * nl_v_21 = nl_b_3_13;
*(nl_node *)nl_v_17.bytes = nl_v_20;
const nl_node *nl_v_22 = (nl_node *)nl_v_17.bytes;
NL_HEAP_INITIALIZE(nl_v_22,nl_v_21->token);
(void)nl_v_21;
nl_v_16 = nl_v_22;
}
const nl_node * const nl_b_2_14 = nl_v_16;
(void)nl_b_2_14;
NL_NODE_BIND(2, 14, 2, &nl_b_2_14);
uint8_t nl_v_23;
void *nl_heap_24 = malloc(24);
NL_HEAP_TRIAL(nl_heap_24,24,8);
if (nl_heap_24 == NULL) {
NL_HEAP_ARM(1);
nl_slot nl_v_25;
{ const nl_domain *nl_b_5_15 = &nl_b_2_12;
(void)nl_b_5_15;
const nl_node * nl_v_26 = nl_b_2_14;
NL_HEAP_END(nl_v_26,nl_b_5_15->token);
nl_slot nl_v_27 = {(unsigned char *)nl_v_26,24};
nl_v_25 = nl_v_27;
}
nl_slot nl_b_4_16 = nl_v_25;
(void)nl_b_4_16;
NL_NODE_BIND(4, 16, 4, &nl_b_4_16);
nl_slot nl_v_28 = nl_b_4_16;
nl_b_4_16 = (nl_slot){0};
nl_storage nl_v_29 = {nl_v_28.bytes,nl_v_28.length};
NL_HEAP_RAW(nl_v_29.bytes,nl_v_29.length);
nl_storage nl_b_4_17 = nl_v_29;
(void)nl_b_4_17;
NL_NODE_BIND(4, 17, 4, &nl_b_4_17);
nl_domain nl_v_30 = nl_b_2_12;
nl_b_2_12 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_30.token);
(void)nl_v_30;
nl_allocation nl_v_31 = nl_b_2_10;
nl_b_2_10 = (nl_allocation){0};
nl_storage nl_v_32 = nl_b_4_17;
nl_b_4_17 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_31.handle,nl_v_32.bytes,nl_v_32.length);
free(nl_v_31.handle);
nl_v_31.handle=NULL;
nl_v_32.bytes=NULL;
(void)nl_v_32;
uint8_t nl_v_33=nl_b_0_1.f0;
uint8_t nl_b_4_18 = nl_v_33;
(void)nl_b_4_18;
NL_NODE_BIND(4, 18, 4, &nl_b_4_18);
uint8_t nl_v_34=nl_b_0_1.f1;
uint8_t nl_b_4_19 = nl_v_34;
(void)nl_b_4_19;
NL_NODE_BIND(4, 19, 4, &nl_b_4_19);
uint8_t nl_v_35 = nl_b_0_6;
uint8_t nl_b_4_20 = nl_v_35;
(void)nl_b_4_20;
NL_NODE_BIND(4, 20, 4, &nl_b_4_20);
NL_HEAP_FINISH();
return 0;
}
else {
NL_HEAP_ARM(2);
nl_backing nl_b_6_15 = { {nl_heap_24}, {(unsigned char *)nl_heap_24,24} };
nl_backing nl_v_36 = nl_b_6_15;
nl_b_6_15 = (nl_backing){0};
nl_allocation nl_b_6_16 = nl_v_36.allocation;
(void)nl_b_6_16;
nl_storage nl_b_6_17 = nl_v_36.raw;
(void)nl_b_6_17;
nl_v_36 = (nl_backing){0};
nl_allocation nl_v_37 = nl_b_6_16;
nl_b_6_16 = (nl_allocation){0};
nl_allocation nl_b_6_18 = nl_v_37;
(void)nl_b_6_18;
NL_NODE_BIND(6, 18, 4, &nl_b_6_18);
nl_storage nl_v_38 = nl_b_6_17;
nl_b_6_17 = (nl_storage){0};
nl_slot nl_v_39 = {nl_v_38.bytes,nl_v_38.length};
NL_HEAP_SLOT(nl_v_39.bytes,nl_v_39.length);
nl_slot nl_b_6_19 = nl_v_39;
(void)nl_b_6_19;
NL_NODE_BIND(6, 19, 4, &nl_b_6_19);
nl_domain nl_v_40 = {2};
NL_HEAP_DOMAIN(nl_v_40.token);
nl_domain nl_b_6_20 = nl_v_40;
(void)nl_b_6_20;
NL_NODE_BIND(6, 20, 4, &nl_b_6_20);
const nl_node * nl_v_41;
{ const nl_domain *nl_b_7_21 = &nl_b_6_20;
(void)nl_b_7_21;
nl_slot nl_v_42 = nl_b_6_19;
nl_b_6_19 = (nl_slot){0};
nl_node_option nl_v_43 = { 0, NULL };
uint8_t nl_v_44 = 0;
nl_node nl_v_45 = { nl_v_43, nl_v_44 };
const nl_domain * nl_v_46 = nl_b_7_21;
*(nl_node *)nl_v_42.bytes = nl_v_45;
const nl_node *nl_v_47 = (nl_node *)nl_v_42.bytes;
NL_HEAP_INITIALIZE(nl_v_47,nl_v_46->token);
(void)nl_v_46;
nl_v_41 = nl_v_47;
}
const nl_node * const nl_b_6_22 = nl_v_41;
(void)nl_b_6_22;
NL_NODE_BIND(6, 22, 2, &nl_b_6_22);
nl_node_option nl_v_48;
{ const nl_domain *nl_b_8_23 = &nl_b_2_12;
(void)nl_b_8_23;
const nl_node * nl_v_49 = nl_b_2_14;
const nl_domain * nl_v_50 = nl_b_8_23;
nl_node * nl_v_51 = (nl_node *)nl_v_49;
NL_HEAP_ROOT(nl_v_51,nl_v_50->token,1,13,16,4);
(void)nl_v_50;
nl_node * nl_b_8_24 = nl_v_51;
(void)nl_b_8_24;
NL_NODE_BIND(8, 24, 4, &nl_b_8_24);
nl_node * nl_v_52 = nl_b_8_24;
nl_node_option * nl_v_53 = &nl_v_52->f0;
NL_HEAP_FIELD(nl_v_52,nl_v_53,1,11,0,17,17,4);
const nl_node * nl_v_54 = nl_b_6_22;
nl_node_option nl_v_55 = { 1, nl_v_54 };
nl_node_option nl_v_56 = *nl_v_53;
*nl_v_53 = nl_v_55;
NL_HEAP_CHANGE(nl_v_53,&nl_v_56,1);
nl_v_48 = nl_v_56;
NL_HEAP_SCOPE_END(4);
}
nl_node_option nl_b_6_25 = nl_v_48;
(void)nl_b_6_25;
NL_NODE_BIND(6, 25, 3, &nl_b_6_25);
uint8_t nl_v_57;
{ const nl_domain *nl_b_9_26 = &nl_b_6_20;
(void)nl_b_9_26;
const nl_node * nl_v_58 = nl_b_6_22;
const nl_domain * nl_v_59 = nl_b_9_26;
const nl_node * nl_v_60 = nl_v_58;
NL_HEAP_ROOT(nl_v_60,nl_v_59->token,0,24,27,5);
(void)nl_v_59;
const nl_node * nl_b_9_27 = nl_v_60;
(void)nl_b_9_27;
NL_NODE_BIND(9, 27, 4, &nl_b_9_27);
const nl_node * nl_v_61 = nl_b_9_27;
const uint8_t * nl_v_62 = &nl_v_61->f1;
NL_HEAP_FIELD(nl_v_61,nl_v_62,0,11,1,29,29,5);
uint8_t nl_v_63 = *nl_v_62;
nl_v_57 = nl_v_63;
NL_HEAP_SCOPE_END(5);
}
uint8_t nl_b_6_28 = nl_v_57;
(void)nl_b_6_28;
NL_NODE_BIND(6, 28, 4, &nl_b_6_28);
nl_node_option nl_v_64;
{ const nl_domain *nl_b_10_29 = &nl_b_6_20;
(void)nl_b_10_29;
const nl_node * nl_v_65 = nl_b_6_22;
const nl_domain * nl_v_66 = nl_b_10_29;
const nl_node * nl_v_67 = nl_v_65;
NL_HEAP_ROOT(nl_v_67,nl_v_66->token,0,24,27,6);
(void)nl_v_66;
const nl_node * nl_b_10_30 = nl_v_67;
(void)nl_b_10_30;
NL_NODE_BIND(10, 30, 4, &nl_b_10_30);
const nl_node * nl_v_68 = nl_b_10_30;
const nl_node_option * nl_v_69 = &nl_v_68->f0;
NL_HEAP_FIELD(nl_v_68,nl_v_69,0,11,0,28,28,6);
nl_node_option nl_v_70 = *nl_v_69;
NL_HEAP_COPY(nl_v_69,&nl_v_70);
nl_v_64 = nl_v_70;
NL_HEAP_SCOPE_END(6);
}
nl_node_option nl_b_6_31 = nl_v_64;
(void)nl_b_6_31;
NL_NODE_BIND(6, 31, 3, &nl_b_6_31);
nl_node_option nl_v_71 = nl_b_6_31;
uint8_t nl_v_72;
switch (nl_v_71.tag) {
case 0: {
NL_NODE_ARM(1, nl_v_71.ptr);
size_t nl_v_73=(size_t)UINTMAX_C(0);
size_t nl_v_74=(size_t)UINTMAX_C(0);
uint8_t nl_v_75=(uint8_t)(nl_v_73< nl_v_74);
nl_v_72 = nl_v_75;
break; }
case 1: {
const nl_node *const nl_b_12_32 = nl_v_71.ptr;
NL_NODE_ARM(2, nl_b_12_32);
(void)nl_b_12_32;
size_t nl_v_76=(size_t)UINTMAX_C(0);
size_t nl_v_77=(size_t)UINTMAX_C(0);
uint8_t nl_v_78=(uint8_t)(nl_v_76== nl_v_77);
nl_v_72 = nl_v_78;
break; }
default: abort();
}
NL_SCALAR_BOOL_RESULT(nl_v_72,0);
uint8_t nl_b_6_32 = nl_v_72;
(void)nl_b_6_32;
NL_NODE_BIND(6, 32, 4, &nl_b_6_32);
uint8_t nl_v_79 = nl_b_6_32;
uint8_t nl_v_80 = nl_b_6_28;
uint8_t nl_v_81;
{
const uint8_t nl_b_13_33=nl_v_79;
const uint8_t nl_b_13_34=nl_v_80;
uint8_t nl_v_82 = nl_b_13_33;
uint8_t nl_v_83;
NL_SCALAR_IF_CONDITION(nl_v_82);
if(nl_v_82){
uint8_t nl_v_84 = 0;
nl_v_83=nl_v_84;
NL_SCALAR_IF_RESULT(0,nl_v_83);
}else{
uint8_t nl_v_85 = nl_b_13_34;
nl_v_83=nl_v_85;
NL_SCALAR_IF_RESULT(1,nl_v_83);
}
nl_v_81=nl_v_83;
}
uint8_t nl_b_6_35 = nl_v_81;
(void)nl_b_6_35;
NL_NODE_BIND(6, 35, 4, &nl_b_6_35);
nl_live_tail nl_v_86;
{ const nl_domain *nl_b_16_36 = &nl_b_2_12;
(void)nl_b_16_36;
const nl_node * nl_v_87 = nl_b_2_14;
const nl_domain * nl_v_88 = nl_b_16_36;
nl_node * nl_v_89 = (nl_node *)nl_v_87;
NL_HEAP_ROOT(nl_v_89,nl_v_88->token,1,13,16,7);
(void)nl_v_88;
nl_node * nl_b_16_37 = nl_v_89;
(void)nl_b_16_37;
NL_NODE_BIND(16, 37, 4, &nl_b_16_37);
nl_node * nl_v_90 = nl_b_16_37;
nl_node_option * nl_v_91 = &nl_v_90->f0;
NL_HEAP_FIELD(nl_v_90,nl_v_91,1,11,0,17,17,7);
const nl_node * nl_v_92 = nl_b_6_22;
nl_allocation nl_v_93 = nl_b_6_18;
nl_b_6_18 = (nl_allocation){0};
nl_domain nl_v_94 = nl_b_6_20;
nl_b_6_20 = (nl_domain){0};
NL_LIVE_SEND(nl_v_92,nl_v_93.handle,nl_v_94.token,&nl_b_6_18,&nl_b_6_20);
nl_live_tail nl_v_103 = nl_producer_14(nl_v_91,nl_v_92,nl_v_93,nl_v_94);
NL_LIVE_RECEIVE(nl_v_103,&nl_b_6_18,&nl_b_6_20);
nl_v_86 = nl_v_103;
NL_HEAP_SCOPE_END(7);
}
nl_live_tail nl_b_6_44 = nl_v_86;
nl_v_86 = (nl_live_tail){0};
NL_NODE_BIND(6,44,4,&nl_b_6_44);
nl_live_tail nl_v_104 = nl_b_6_44;
nl_b_6_44 = (nl_live_tail){0};
const nl_node * nl_b_6_45 = nl_v_104.ptr;
(void)nl_b_6_45;
nl_allocation nl_b_6_46 = nl_v_104.allocation;
(void)nl_b_6_46;
nl_domain nl_b_6_47 = nl_v_104.domain;
(void)nl_b_6_47;
nl_v_104 = (nl_live_tail){0};
nl_slot nl_v_105;
{ const nl_domain *nl_b_18_48 = &nl_b_2_12;
(void)nl_b_18_48;
const nl_node * nl_v_106 = nl_b_2_14;
NL_HEAP_END(nl_v_106,nl_b_18_48->token);
nl_slot nl_v_107 = {(unsigned char *)nl_v_106,24};
nl_v_105 = nl_v_107;
}
nl_slot nl_b_6_49 = nl_v_105;
(void)nl_b_6_49;
NL_NODE_BIND(6, 49, 4, &nl_b_6_49);
nl_slot nl_v_108 = nl_b_6_49;
nl_b_6_49 = (nl_slot){0};
nl_storage nl_v_109 = {nl_v_108.bytes,nl_v_108.length};
NL_HEAP_RAW(nl_v_109.bytes,nl_v_109.length);
nl_storage nl_b_6_50 = nl_v_109;
(void)nl_b_6_50;
NL_NODE_BIND(6, 50, 4, &nl_b_6_50);
nl_domain nl_v_110 = nl_b_2_12;
nl_b_2_12 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_110.token);
(void)nl_v_110;
nl_allocation nl_v_111 = nl_b_2_10;
nl_b_2_10 = (nl_allocation){0};
nl_storage nl_v_112 = nl_b_6_50;
nl_b_6_50 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_111.handle,nl_v_112.bytes,nl_v_112.length);
free(nl_v_111.handle);
nl_v_111.handle=NULL;
nl_v_112.bytes=NULL;
(void)nl_v_112;
const nl_node * nl_v_113 = nl_b_6_45;
nl_allocation nl_v_114 = nl_b_6_46;
nl_b_6_46 = (nl_allocation){0};
nl_domain nl_v_115 = nl_b_6_47;
nl_b_6_47 = (nl_domain){0};
NL_HEAP_HANDOFF(nl_v_113,nl_v_114.handle,nl_v_115.token,&nl_b_6_46,&nl_b_6_47);
nl_owner_13(nl_v_113,nl_v_114,nl_v_115);
NL_HEAP_RETURNED(&nl_b_6_46,&nl_b_6_47);
uint8_t nl_v_124 = nl_b_6_35;
nl_v_23 = nl_v_124;
}
nl_v_6 = nl_v_23;
}
uint8_t nl_b_0_7 = nl_v_6;
(void)nl_b_0_7;
NL_NODE_BIND(0, 7, 4, &nl_b_0_7);
uint8_t nl_v_125 = nl_b_0_6;
uint8_t nl_b_0_8 = nl_v_125;
(void)nl_b_0_8;
NL_NODE_BIND(0, 8, 4, &nl_b_0_8);
uint8_t nl_v_126 = nl_b_0_7;
uint8_t nl_v_127 = nl_copy_state_10(&nl_b_0_1.f0,nl_v_126);
uint8_t nl_b_0_13 = nl_v_127;
(void)nl_b_0_13;
NL_NODE_BIND(0, 13, 4, &nl_b_0_13);
uint8_t nl_v_128 = nl_b_0_13;
uint8_t nl_b_0_14 = nl_v_128;
(void)nl_b_0_14;
NL_NODE_BIND(0, 14, 4, &nl_b_0_14);
uint8_t nl_v_129=nl_b_0_1.f0;
uint8_t nl_b_0_15 = nl_v_129;
(void)nl_b_0_15;
NL_NODE_BIND(0, 15, 4, &nl_b_0_15);
uint8_t nl_v_130=nl_b_0_1.f1;
uint8_t nl_b_0_16 = nl_v_130;
(void)nl_b_0_16;
NL_NODE_BIND(0, 16, 4, &nl_b_0_16);
NL_HEAP_FINISH();
return 0;
}
