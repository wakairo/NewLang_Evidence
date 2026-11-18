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
static void nl_owner_12(const nl_node *nl_b_18_38,nl_allocation nl_b_18_39,nl_domain nl_b_18_40) {
NL_HEAP_RECEIVER_ENTER(nl_b_18_38,nl_b_18_39.handle,nl_b_18_40.token,18,38,39,40,&nl_b_18_39,&nl_b_18_40);
{ const nl_domain *nl_b_19_41 = &nl_b_18_40;
(void)nl_b_19_41;
const nl_node * nl_v_113 = nl_b_18_38;
const nl_domain * nl_v_114 = nl_b_19_41;
const nl_node * nl_v_115 = nl_v_113;
NL_HEAP_ROOT(nl_v_115,nl_v_114->token,0,16,19,7);
(void)nl_v_114;
const nl_node * nl_b_19_42 = nl_v_115;
(void)nl_b_19_42;
NL_NODE_BIND(19, 42, 4, &nl_b_19_42);
NL_HEAP_SCOPE_END(7);
}
nl_slot nl_v_116;
{ const nl_domain *nl_b_20_43 = &nl_b_18_40;
(void)nl_b_20_43;
const nl_node * nl_v_117 = nl_b_18_38;
NL_HEAP_END(nl_v_117,nl_b_20_43->token);
nl_slot nl_v_118 = {(unsigned char *)nl_v_117,24};
nl_v_116 = nl_v_118;
}
nl_slot nl_b_18_44 = nl_v_116;
(void)nl_b_18_44;
NL_NODE_BIND(18, 44, 4, &nl_b_18_44);
nl_slot nl_v_119 = nl_b_18_44;
nl_b_18_44 = (nl_slot){0};
nl_storage nl_v_120 = {nl_v_119.bytes,nl_v_119.length};
NL_HEAP_RAW(nl_v_120.bytes,nl_v_120.length);
nl_storage nl_b_18_45 = nl_v_120;
(void)nl_b_18_45;
NL_NODE_BIND(18, 45, 4, &nl_b_18_45);
nl_domain nl_v_121 = nl_b_18_40;
nl_b_18_40 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_121.token);
(void)nl_v_121;
nl_allocation nl_v_122 = nl_b_18_39;
nl_b_18_39 = (nl_allocation){0};
nl_storage nl_v_123 = nl_b_18_45;
nl_b_18_45 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_122.handle,nl_v_123.bytes,nl_v_123.length);
free(nl_v_122.handle);
nl_v_122.handle=NULL;
nl_v_123.bytes=NULL;
(void)nl_v_123;
NL_HEAP_RECEIVER_EXIT();
}
static nl_live_tail nl_producer_13(nl_node_option * nl_b_14_26,const nl_node * nl_b_14_27,nl_allocation nl_b_14_28,nl_domain nl_b_14_29) {
NL_LIVE_ENTER(nl_b_14_26,nl_b_14_27,nl_b_14_28.handle,nl_b_14_29.token);
nl_node_option * nl_v_87 = nl_b_14_26;
nl_node_option nl_v_88 = { 0, NULL };
nl_node_option nl_v_89 = *nl_v_87;
*nl_v_87 = nl_v_88;
NL_HEAP_CHANGE(nl_v_87,&nl_v_89,2);
(void)nl_v_89;
const nl_node * nl_v_90 = nl_b_14_27;
nl_allocation nl_v_91 = nl_b_14_28;
nl_b_14_28 = (nl_allocation){0};
nl_domain nl_v_92 = nl_b_14_29;
nl_b_14_29 = (nl_domain){0};
nl_live_tail nl_v_93 = {nl_v_90,nl_v_91,nl_v_92};
NL_LIVE_RETURN(nl_v_93);
return nl_v_93;
}
int main(void) {
uint8_t nl_v_1;
void *nl_heap_2 = malloc(24);
NL_HEAP_TRIAL(nl_heap_2,24,8);
if (nl_heap_2 == NULL) {
NL_HEAP_ARM(1);
size_t nl_v_3=(size_t)UINTMAX_C(1);
size_t nl_v_4=(size_t)UINTMAX_C(0);
uint8_t nl_v_5=(uint8_t)(nl_v_3< nl_v_4);
nl_v_1 = nl_v_5;
}
if (nl_heap_2 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_2_1 = { {nl_heap_2}, {(unsigned char *)nl_heap_2,24} };
nl_backing nl_v_6 = nl_b_2_1;
nl_b_2_1 = (nl_backing){0};
nl_allocation nl_b_2_2 = nl_v_6.allocation;
(void)nl_b_2_2;
nl_storage nl_b_2_3 = nl_v_6.raw;
(void)nl_b_2_3;
nl_v_6 = (nl_backing){0};
nl_allocation nl_v_7 = nl_b_2_2;
nl_b_2_2 = (nl_allocation){0};
nl_allocation nl_b_2_4 = nl_v_7;
(void)nl_b_2_4;
NL_NODE_BIND(2, 4, 4, &nl_b_2_4);
nl_storage nl_v_8 = nl_b_2_3;
nl_b_2_3 = (nl_storage){0};
nl_slot nl_v_9 = {nl_v_8.bytes,nl_v_8.length};
NL_HEAP_SLOT(nl_v_9.bytes,nl_v_9.length);
nl_slot nl_b_2_5 = nl_v_9;
(void)nl_b_2_5;
NL_NODE_BIND(2, 5, 4, &nl_b_2_5);
nl_domain nl_v_10 = {1};
NL_HEAP_DOMAIN(nl_v_10.token);
nl_domain nl_b_2_6 = nl_v_10;
(void)nl_b_2_6;
NL_NODE_BIND(2, 6, 4, &nl_b_2_6);
const nl_node * nl_v_11;
{ const nl_domain *nl_b_3_7 = &nl_b_2_6;
(void)nl_b_3_7;
nl_slot nl_v_12 = nl_b_2_5;
nl_b_2_5 = (nl_slot){0};
nl_node_option nl_v_13 = { 0, NULL };
uint8_t nl_v_14 = 41;
nl_node nl_v_15 = { nl_v_13, nl_v_14 };
const nl_domain * nl_v_16 = nl_b_3_7;
*(nl_node *)nl_v_12.bytes = nl_v_15;
const nl_node *nl_v_17 = (nl_node *)nl_v_12.bytes;
NL_HEAP_INITIALIZE(nl_v_17,nl_v_16->token);
(void)nl_v_16;
nl_v_11 = nl_v_17;
}
const nl_node * const nl_b_2_8 = nl_v_11;
(void)nl_b_2_8;
NL_NODE_BIND(2, 8, 2, &nl_b_2_8);
uint8_t nl_v_18;
void *nl_heap_19 = malloc(24);
NL_HEAP_TRIAL(nl_heap_19,24,8);
if (nl_heap_19 == NULL) {
NL_HEAP_ARM(1);
nl_slot nl_v_20;
{ const nl_domain *nl_b_5_9 = &nl_b_2_6;
(void)nl_b_5_9;
const nl_node * nl_v_21 = nl_b_2_8;
NL_HEAP_END(nl_v_21,nl_b_5_9->token);
nl_slot nl_v_22 = {(unsigned char *)nl_v_21,24};
nl_v_20 = nl_v_22;
}
nl_slot nl_b_4_10 = nl_v_20;
(void)nl_b_4_10;
NL_NODE_BIND(4, 10, 4, &nl_b_4_10);
nl_slot nl_v_23 = nl_b_4_10;
nl_b_4_10 = (nl_slot){0};
nl_storage nl_v_24 = {nl_v_23.bytes,nl_v_23.length};
NL_HEAP_RAW(nl_v_24.bytes,nl_v_24.length);
nl_storage nl_b_4_11 = nl_v_24;
(void)nl_b_4_11;
NL_NODE_BIND(4, 11, 4, &nl_b_4_11);
nl_domain nl_v_25 = nl_b_2_6;
nl_b_2_6 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_25.token);
(void)nl_v_25;
nl_allocation nl_v_26 = nl_b_2_4;
nl_b_2_4 = (nl_allocation){0};
nl_storage nl_v_27 = nl_b_4_11;
nl_b_4_11 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_26.handle,nl_v_27.bytes,nl_v_27.length);
free(nl_v_26.handle);
nl_v_26.handle=NULL;
nl_v_27.bytes=NULL;
(void)nl_v_27;
size_t nl_v_28=(size_t)UINTMAX_C(0);
size_t nl_v_29=(size_t)UINTMAX_C(1);
uint8_t nl_v_30=(uint8_t)(nl_v_28< nl_v_29);
nl_v_18 = nl_v_30;
}
if (nl_heap_19 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_6_9 = { {nl_heap_19}, {(unsigned char *)nl_heap_19,24} };
nl_backing nl_v_31 = nl_b_6_9;
nl_b_6_9 = (nl_backing){0};
nl_allocation nl_b_6_10 = nl_v_31.allocation;
(void)nl_b_6_10;
nl_storage nl_b_6_11 = nl_v_31.raw;
(void)nl_b_6_11;
nl_v_31 = (nl_backing){0};
nl_allocation nl_v_32 = nl_b_6_10;
nl_b_6_10 = (nl_allocation){0};
nl_allocation nl_b_6_12 = nl_v_32;
(void)nl_b_6_12;
NL_NODE_BIND(6, 12, 4, &nl_b_6_12);
nl_storage nl_v_33 = nl_b_6_11;
nl_b_6_11 = (nl_storage){0};
nl_slot nl_v_34 = {nl_v_33.bytes,nl_v_33.length};
NL_HEAP_SLOT(nl_v_34.bytes,nl_v_34.length);
nl_slot nl_b_6_13 = nl_v_34;
(void)nl_b_6_13;
NL_NODE_BIND(6, 13, 4, &nl_b_6_13);
nl_domain nl_v_35 = {2};
NL_HEAP_DOMAIN(nl_v_35.token);
nl_domain nl_b_6_14 = nl_v_35;
(void)nl_b_6_14;
NL_NODE_BIND(6, 14, 4, &nl_b_6_14);
const nl_node * nl_v_36;
{ const nl_domain *nl_b_7_15 = &nl_b_6_14;
(void)nl_b_7_15;
nl_slot nl_v_37 = nl_b_6_13;
nl_b_6_13 = (nl_slot){0};
nl_node_option nl_v_38 = { 0, NULL };
uint8_t nl_v_39 = 197;
nl_node nl_v_40 = { nl_v_38, nl_v_39 };
const nl_domain * nl_v_41 = nl_b_7_15;
*(nl_node *)nl_v_37.bytes = nl_v_40;
const nl_node *nl_v_42 = (nl_node *)nl_v_37.bytes;
NL_HEAP_INITIALIZE(nl_v_42,nl_v_41->token);
(void)nl_v_41;
nl_v_36 = nl_v_42;
}
const nl_node * const nl_b_6_16 = nl_v_36;
(void)nl_b_6_16;
NL_NODE_BIND(6, 16, 2, &nl_b_6_16);
nl_node_option nl_v_43;
{ const nl_domain *nl_b_8_17 = &nl_b_2_6;
(void)nl_b_8_17;
const nl_node * nl_v_44 = nl_b_2_8;
const nl_domain * nl_v_45 = nl_b_8_17;
nl_node * nl_v_46 = (nl_node *)nl_v_44;
NL_HEAP_ROOT(nl_v_46,nl_v_45->token,1,5,8,3);
(void)nl_v_45;
nl_node * nl_b_8_18 = nl_v_46;
(void)nl_b_8_18;
NL_NODE_BIND(8, 18, 4, &nl_b_8_18);
nl_node * nl_v_47 = nl_b_8_18;
nl_node_option * nl_v_48 = &nl_v_47->f0;
NL_HEAP_FIELD(nl_v_47,nl_v_48,1,11,0,9,9,3);
const nl_node * nl_v_49 = nl_b_6_16;
nl_node_option nl_v_50 = { 1, nl_v_49 };
nl_node_option nl_v_51 = *nl_v_48;
*nl_v_48 = nl_v_50;
NL_HEAP_CHANGE(nl_v_48,&nl_v_51,1);
nl_v_43 = nl_v_51;
NL_HEAP_SCOPE_END(3);
}
nl_node_option nl_b_6_19 = nl_v_43;
(void)nl_b_6_19;
NL_NODE_BIND(6, 19, 3, &nl_b_6_19);
nl_node_option nl_v_52;
{ const nl_domain *nl_b_9_20 = &nl_b_2_6;
(void)nl_b_9_20;
const nl_node * nl_v_53 = nl_b_2_8;
const nl_domain * nl_v_54 = nl_b_9_20;
const nl_node * nl_v_55 = nl_v_53;
NL_HEAP_ROOT(nl_v_55,nl_v_54->token,0,5,8,4);
(void)nl_v_54;
const nl_node * nl_b_9_21 = nl_v_55;
(void)nl_b_9_21;
NL_NODE_BIND(9, 21, 4, &nl_b_9_21);
const nl_node * nl_v_56 = nl_b_9_21;
const nl_node_option * nl_v_57 = &nl_v_56->f0;
NL_HEAP_FIELD(nl_v_56,nl_v_57,0,11,0,9,9,4);
nl_node_option nl_v_58 = *nl_v_57;
NL_HEAP_COPY(nl_v_57,&nl_v_58);
nl_v_52 = nl_v_58;
NL_HEAP_SCOPE_END(4);
}
nl_node_option nl_b_6_22 = nl_v_52;
(void)nl_b_6_22;
NL_NODE_BIND(6, 22, 3, &nl_b_6_22);
nl_node_option nl_v_59 = nl_b_6_22;
uint8_t nl_v_60;
switch (nl_v_59.tag) {
case 0: {
NL_NODE_ARM(1, nl_v_59.ptr);
uint8_t nl_v_61 = 13;
nl_v_60 = nl_v_61;
break; }
case 1: {
const nl_node *const nl_b_11_23 = nl_v_59.ptr;
NL_NODE_ARM(2, nl_b_11_23);
(void)nl_b_11_23;
uint8_t nl_v_62;
{ const nl_domain *nl_b_12_24 = &nl_b_6_14;
(void)nl_b_12_24;
const nl_node * nl_v_63 = nl_b_11_23;
const nl_domain * nl_v_64 = nl_b_12_24;
const nl_node * nl_v_65 = nl_v_63;
NL_HEAP_ROOT(nl_v_65,nl_v_64->token,0,16,19,5);
(void)nl_v_64;
const nl_node * nl_b_12_25 = nl_v_65;
(void)nl_b_12_25;
NL_NODE_BIND(12, 25, 4, &nl_b_12_25);
const nl_node * nl_v_66 = nl_b_12_25;
const uint8_t * nl_v_67 = &nl_v_66->f1;
NL_HEAP_FIELD(nl_v_66,nl_v_67,0,11,1,21,21,5);
uint8_t nl_v_68 = *nl_v_67;
nl_v_62 = nl_v_68;
NL_HEAP_SCOPE_END(5);
}
uint8_t nl_b_11_26 = nl_v_62;
(void)nl_b_11_26;
NL_NODE_BIND(11, 26, 4, &nl_b_11_26);
uint8_t nl_v_69 = 31;
uint8_t nl_v_70 = 251;
nl_copy_record nl_v_71 = {nl_v_69,nl_v_70};
nl_copy_record nl_b_11_27 = nl_v_71;
NL_MIXED_COPY_BIND(11,27,&nl_b_11_27.f0,&nl_b_11_27.f1);
uint8_t nl_v_72 = nl_b_11_26;
uint8_t nl_v_73 = nl_copy_state_10(&nl_b_11_27.f0,nl_v_72);
uint8_t nl_b_11_32 = nl_v_73;
(void)nl_b_11_32;
NL_NODE_BIND(11, 32, 4, &nl_b_11_32);
uint8_t nl_v_74 = nl_b_11_32;
uint8_t nl_b_11_33 = nl_v_74;
(void)nl_b_11_33;
NL_NODE_BIND(11, 33, 4, &nl_b_11_33);
uint8_t nl_v_75=nl_b_11_27.f0;
uint8_t nl_b_11_34 = nl_v_75;
(void)nl_b_11_34;
NL_NODE_BIND(11, 34, 4, &nl_b_11_34);
uint8_t nl_v_76=nl_b_11_27.f1;
uint8_t nl_b_11_35 = nl_v_76;
(void)nl_b_11_35;
NL_NODE_BIND(11, 35, 4, &nl_b_11_35);
uint8_t nl_v_77 = nl_b_11_33;
nl_v_60 = nl_v_77;
break; }
default: abort();
}
uint8_t nl_b_6_23 = nl_v_60;
(void)nl_b_6_23;
NL_NODE_BIND(6, 23, 4, &nl_b_6_23);
nl_live_tail nl_v_78;
{ const nl_domain *nl_b_13_24 = &nl_b_2_6;
(void)nl_b_13_24;
const nl_node * nl_v_79 = nl_b_2_8;
const nl_domain * nl_v_80 = nl_b_13_24;
nl_node * nl_v_81 = (nl_node *)nl_v_79;
NL_HEAP_ROOT(nl_v_81,nl_v_80->token,1,5,8,5);
(void)nl_v_80;
nl_node * nl_b_13_25 = nl_v_81;
(void)nl_b_13_25;
NL_NODE_BIND(13, 25, 4, &nl_b_13_25);
nl_node * nl_v_82 = nl_b_13_25;
nl_node_option * nl_v_83 = &nl_v_82->f0;
NL_HEAP_FIELD(nl_v_82,nl_v_83,1,11,0,9,9,5);
const nl_node * nl_v_84 = nl_b_6_16;
nl_allocation nl_v_85 = nl_b_6_12;
nl_b_6_12 = (nl_allocation){0};
nl_domain nl_v_86 = nl_b_6_14;
nl_b_6_14 = (nl_domain){0};
NL_LIVE_SEND(nl_v_84,nl_v_85.handle,nl_v_86.token,&nl_b_6_12,&nl_b_6_14);
nl_live_tail nl_v_94 = nl_producer_13(nl_v_83,nl_v_84,nl_v_85,nl_v_86);
NL_LIVE_RECEIVE(nl_v_94,&nl_b_6_12,&nl_b_6_14);
nl_v_78 = nl_v_94;
NL_HEAP_SCOPE_END(5);
}
const nl_node * nl_b_6_31 = nl_v_78.ptr;
(void)nl_b_6_31;
nl_allocation nl_b_6_32 = nl_v_78.allocation;
(void)nl_b_6_32;
nl_domain nl_b_6_33 = nl_v_78.domain;
(void)nl_b_6_33;
nl_v_78 = (nl_live_tail){0};
nl_node_option nl_v_95;
{ const nl_domain *nl_b_15_34 = &nl_b_2_6;
(void)nl_b_15_34;
const nl_node * nl_v_96 = nl_b_2_8;
const nl_domain * nl_v_97 = nl_b_15_34;
const nl_node * nl_v_98 = nl_v_96;
NL_HEAP_ROOT(nl_v_98,nl_v_97->token,0,5,8,6);
(void)nl_v_97;
const nl_node * nl_b_15_35 = nl_v_98;
(void)nl_b_15_35;
NL_NODE_BIND(15, 35, 4, &nl_b_15_35);
const nl_node * nl_v_99 = nl_b_15_35;
const nl_node_option * nl_v_100 = &nl_v_99->f0;
NL_HEAP_FIELD(nl_v_99,nl_v_100,0,11,0,9,9,6);
nl_node_option nl_v_101 = *nl_v_100;
NL_HEAP_COPY(nl_v_100,&nl_v_101);
nl_v_95 = nl_v_101;
NL_HEAP_SCOPE_END(6);
}
nl_node_option nl_b_6_36 = nl_v_95;
(void)nl_b_6_36;
NL_NODE_BIND(6, 36, 3, &nl_b_6_36);
nl_node_option nl_v_102 = nl_b_6_36;
uint8_t nl_v_103;
switch (nl_v_102.tag) {
case 1: {
const nl_node *const nl_b_16_37 = nl_v_102.ptr;
NL_NODE_ARM(2, nl_b_16_37);
(void)nl_b_16_37;
size_t nl_v_104=(size_t)UINTMAX_C(1);
size_t nl_v_105=(size_t)UINTMAX_C(0);
uint8_t nl_v_106=(uint8_t)(nl_v_104< nl_v_105);
nl_v_103 = nl_v_106;
break; }
case 0: {
NL_NODE_ARM(1, nl_v_102.ptr);
size_t nl_v_107=(size_t)UINTMAX_C(0);
size_t nl_v_108=(size_t)UINTMAX_C(1);
uint8_t nl_v_109=(uint8_t)(nl_v_107< nl_v_108);
nl_v_103 = nl_v_109;
break; }
default: abort();
}
NL_SCALAR_BOOL_RESULT(nl_v_103,0);
uint8_t nl_b_6_37 = nl_v_103;
(void)nl_b_6_37;
NL_NODE_BIND(6, 37, 4, &nl_b_6_37);
const nl_node * nl_v_110 = nl_b_6_31;
nl_allocation nl_v_111 = nl_b_6_32;
nl_b_6_32 = (nl_allocation){0};
nl_domain nl_v_112 = nl_b_6_33;
nl_b_6_33 = (nl_domain){0};
NL_HEAP_HANDOFF(nl_v_110,nl_v_111.handle,nl_v_112.token,&nl_b_6_32,&nl_b_6_33);
nl_owner_12(nl_v_110,nl_v_111,nl_v_112);
NL_HEAP_RETURNED(&nl_b_6_32,&nl_b_6_33);
nl_slot nl_v_124;
{ const nl_domain *nl_b_21_46 = &nl_b_2_6;
(void)nl_b_21_46;
const nl_node * nl_v_125 = nl_b_2_8;
NL_HEAP_END(nl_v_125,nl_b_21_46->token);
nl_slot nl_v_126 = {(unsigned char *)nl_v_125,24};
nl_v_124 = nl_v_126;
}
nl_slot nl_b_6_47 = nl_v_124;
(void)nl_b_6_47;
NL_NODE_BIND(6, 47, 4, &nl_b_6_47);
nl_slot nl_v_127 = nl_b_6_47;
nl_b_6_47 = (nl_slot){0};
nl_storage nl_v_128 = {nl_v_127.bytes,nl_v_127.length};
NL_HEAP_RAW(nl_v_128.bytes,nl_v_128.length);
nl_storage nl_b_6_48 = nl_v_128;
(void)nl_b_6_48;
NL_NODE_BIND(6, 48, 4, &nl_b_6_48);
nl_domain nl_v_129 = nl_b_2_6;
nl_b_2_6 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_129.token);
(void)nl_v_129;
nl_allocation nl_v_130 = nl_b_2_4;
nl_b_2_4 = (nl_allocation){0};
nl_storage nl_v_131 = nl_b_6_48;
nl_b_6_48 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_130.handle,nl_v_131.bytes,nl_v_131.length);
free(nl_v_130.handle);
nl_v_130.handle=NULL;
nl_v_131.bytes=NULL;
(void)nl_v_131;
uint8_t nl_v_132 = nl_b_6_23;
(void)nl_v_132;
uint8_t nl_v_133 = nl_b_6_37;
nl_v_18 = nl_v_133;
}
NL_SCALAR_BOOL_RESULT(nl_v_18,1);
nl_v_1 = nl_v_18;
}
NL_SCALAR_BOOL_RESULT(nl_v_1,1);
uint8_t nl_b_0_1 = nl_v_1;
(void)nl_b_0_1;
NL_NODE_BIND(0, 1, 4, &nl_b_0_1);
uint8_t nl_v_134 = nl_b_0_1;
uint8_t nl_b_0_2 = nl_v_134;
(void)nl_b_0_2;
NL_NODE_BIND(0, 2, 4, &nl_b_0_2);
uint8_t nl_v_135 = nl_b_0_2;
uint8_t nl_b_0_3 = nl_v_135;
(void)nl_b_0_3;
NL_NODE_BIND(0, 3, 4, &nl_b_0_3);
uint8_t nl_v_136 = nl_b_0_3;
uint8_t nl_v_137;
NL_SCALAR_IF_CONDITION(nl_v_136);
if(nl_v_136){
uint8_t nl_v_138 = 83;
nl_v_137=nl_v_138;
NL_SCALAR_IF_RESULT(0,nl_v_137);
}else{
uint8_t nl_v_139 = 227;
nl_v_137=nl_v_139;
NL_SCALAR_IF_RESULT(1,nl_v_137);
}
uint8_t nl_b_0_4 = nl_v_137;
(void)nl_b_0_4;
NL_NODE_BIND(0, 4, 4, &nl_b_0_4);
uint8_t nl_v_140 = nl_b_0_4;
uint8_t nl_b_0_5 = nl_v_140;
(void)nl_b_0_5;
NL_NODE_BIND(0, 5, 4, &nl_b_0_5);
uint8_t nl_v_141 = nl_b_0_5;
(void)nl_v_141;
NL_HEAP_FINISH();
return 0;
}
