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
static void nl_owner_13(const nl_node *nl_b_19_53,nl_allocation nl_b_19_54,nl_domain nl_b_19_55) {
NL_HEAP_RECEIVER_ENTER(nl_b_19_53,nl_b_19_54.handle,nl_b_19_55.token,19,53,54,55,&nl_b_19_54,&nl_b_19_55);
nl_slot nl_v_110;
{ const nl_domain *nl_b_20_56 = &nl_b_19_55;
(void)nl_b_20_56;
const nl_node * nl_v_111 = nl_b_19_53;
NL_HEAP_END(nl_v_111,nl_b_20_56->token);
nl_slot nl_v_112 = {(unsigned char *)nl_v_111,24};
nl_v_110 = nl_v_112;
}
nl_slot nl_b_19_57 = nl_v_110;
(void)nl_b_19_57;
NL_NODE_BIND(19, 57, 4, &nl_b_19_57);
nl_slot nl_v_113 = nl_b_19_57;
nl_b_19_57 = (nl_slot){0};
nl_storage nl_v_114 = {nl_v_113.bytes,nl_v_113.length};
NL_HEAP_RAW(nl_v_114.bytes,nl_v_114.length);
nl_storage nl_b_19_58 = nl_v_114;
(void)nl_b_19_58;
NL_NODE_BIND(19, 58, 4, &nl_b_19_58);
nl_domain nl_v_115 = nl_b_19_55;
nl_b_19_55 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_115.token);
(void)nl_v_115;
nl_allocation nl_v_116 = nl_b_19_54;
nl_b_19_54 = (nl_allocation){0};
nl_storage nl_v_117 = nl_b_19_58;
nl_b_19_58 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_116.handle,nl_v_117.bytes,nl_v_117.length);
free(nl_v_116.handle);
nl_v_116.handle=NULL;
nl_v_117.bytes=NULL;
(void)nl_v_117;
NL_HEAP_RECEIVER_EXIT();
}
static nl_live_tail nl_producer_14(nl_node_option * nl_b_17_40,const nl_node * nl_b_17_41,nl_allocation nl_b_17_42,nl_domain nl_b_17_43) {
NL_LIVE_ENTER(nl_b_17_40,nl_b_17_41,nl_b_17_42.handle,nl_b_17_43.token);
nl_node_option * nl_v_89 = nl_b_17_40;
nl_node_option nl_v_90 = { 0, NULL };
nl_node_option nl_v_91 = *nl_v_89;
*nl_v_89 = nl_v_90;
NL_HEAP_CHANGE(nl_v_89,&nl_v_91,2);
(void)nl_v_91;
const nl_node * nl_v_92 = nl_b_17_41;
nl_allocation nl_v_93 = nl_b_17_42;
nl_b_17_42 = (nl_allocation){0};
nl_domain nl_v_94 = nl_b_17_43;
nl_b_17_43 = (nl_domain){0};
nl_live_tail nl_v_95 = {nl_v_92,nl_v_93,nl_v_94};
nl_live_tail nl_b_17_45 = nl_v_95;
nl_v_95 = (nl_live_tail){0};
NL_MIXED_OWNER_LOCAL(&nl_b_17_45);
nl_live_tail nl_v_96 = nl_b_17_45;
nl_b_17_45 = (nl_live_tail){0};
NL_LIVE_RETURN(nl_v_96);
return nl_v_96;
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
uint8_t nl_v_6=nl_b_0_1.f0;
uint8_t nl_b_0_7 = nl_v_6;
(void)nl_b_0_7;
NL_NODE_BIND(0, 7, 4, &nl_b_0_7);
uint8_t nl_v_7=nl_b_0_1.f1;
uint8_t nl_b_0_8 = nl_v_7;
(void)nl_b_0_8;
NL_NODE_BIND(0, 8, 4, &nl_b_0_8);
void *nl_heap_8 = malloc(24);
NL_HEAP_TRIAL(nl_heap_8,24,8);
if (nl_heap_8 == NULL) {
NL_HEAP_ARM(1);
}
if (nl_heap_8 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_2_9 = { {nl_heap_8}, {(unsigned char *)nl_heap_8,24} };
nl_backing nl_v_9 = nl_b_2_9;
nl_b_2_9 = (nl_backing){0};
nl_allocation nl_b_2_10 = nl_v_9.allocation;
(void)nl_b_2_10;
nl_storage nl_b_2_11 = nl_v_9.raw;
(void)nl_b_2_11;
nl_v_9 = (nl_backing){0};
nl_allocation nl_v_10 = nl_b_2_10;
nl_b_2_10 = (nl_allocation){0};
nl_allocation nl_b_2_12 = nl_v_10;
(void)nl_b_2_12;
NL_NODE_BIND(2, 12, 4, &nl_b_2_12);
nl_storage nl_v_11 = nl_b_2_11;
nl_b_2_11 = (nl_storage){0};
nl_slot nl_v_12 = {nl_v_11.bytes,nl_v_11.length};
NL_HEAP_SLOT(nl_v_12.bytes,nl_v_12.length);
nl_slot nl_b_2_13 = nl_v_12;
(void)nl_b_2_13;
NL_NODE_BIND(2, 13, 4, &nl_b_2_13);
nl_domain nl_v_13 = {1};
NL_HEAP_DOMAIN(nl_v_13.token);
nl_domain nl_b_2_14 = nl_v_13;
(void)nl_b_2_14;
NL_NODE_BIND(2, 14, 4, &nl_b_2_14);
const nl_node * nl_v_14;
{ const nl_domain *nl_b_3_15 = &nl_b_2_14;
(void)nl_b_3_15;
nl_slot nl_v_15 = nl_b_2_13;
nl_b_2_13 = (nl_slot){0};
nl_node_option nl_v_16 = { 0, NULL };
uint8_t nl_v_17 = 76;
nl_node nl_v_18 = { nl_v_16, nl_v_17 };
const nl_domain * nl_v_19 = nl_b_3_15;
*(nl_node *)nl_v_15.bytes = nl_v_18;
const nl_node *nl_v_20 = (nl_node *)nl_v_15.bytes;
NL_HEAP_INITIALIZE(nl_v_20,nl_v_19->token);
(void)nl_v_19;
nl_v_14 = nl_v_20;
}
const nl_node * const nl_b_2_16 = nl_v_14;
(void)nl_b_2_16;
NL_NODE_BIND(2, 16, 2, &nl_b_2_16);
void *nl_heap_21 = malloc(24);
NL_HEAP_TRIAL(nl_heap_21,24,8);
if (nl_heap_21 == NULL) {
NL_HEAP_ARM(1);
nl_slot nl_v_22;
{ const nl_domain *nl_b_5_17 = &nl_b_2_14;
(void)nl_b_5_17;
const nl_node * nl_v_23 = nl_b_2_16;
NL_HEAP_END(nl_v_23,nl_b_5_17->token);
nl_slot nl_v_24 = {(unsigned char *)nl_v_23,24};
nl_v_22 = nl_v_24;
}
nl_slot nl_b_4_18 = nl_v_22;
(void)nl_b_4_18;
NL_NODE_BIND(4, 18, 4, &nl_b_4_18);
nl_slot nl_v_25 = nl_b_4_18;
nl_b_4_18 = (nl_slot){0};
nl_storage nl_v_26 = {nl_v_25.bytes,nl_v_25.length};
NL_HEAP_RAW(nl_v_26.bytes,nl_v_26.length);
nl_storage nl_b_4_19 = nl_v_26;
(void)nl_b_4_19;
NL_NODE_BIND(4, 19, 4, &nl_b_4_19);
nl_domain nl_v_27 = nl_b_2_14;
nl_b_2_14 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_27.token);
(void)nl_v_27;
nl_allocation nl_v_28 = nl_b_2_12;
nl_b_2_12 = (nl_allocation){0};
nl_storage nl_v_29 = nl_b_4_19;
nl_b_4_19 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_28.handle,nl_v_29.bytes,nl_v_29.length);
free(nl_v_28.handle);
nl_v_28.handle=NULL;
nl_v_29.bytes=NULL;
(void)nl_v_29;
}
if (nl_heap_21 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_6_17 = { {nl_heap_21}, {(unsigned char *)nl_heap_21,24} };
nl_backing nl_v_30 = nl_b_6_17;
nl_b_6_17 = (nl_backing){0};
nl_allocation nl_b_6_18 = nl_v_30.allocation;
(void)nl_b_6_18;
nl_storage nl_b_6_19 = nl_v_30.raw;
(void)nl_b_6_19;
nl_v_30 = (nl_backing){0};
nl_allocation nl_v_31 = nl_b_6_18;
nl_b_6_18 = (nl_allocation){0};
nl_allocation nl_b_6_20 = nl_v_31;
(void)nl_b_6_20;
NL_NODE_BIND(6, 20, 4, &nl_b_6_20);
nl_storage nl_v_32 = nl_b_6_19;
nl_b_6_19 = (nl_storage){0};
nl_slot nl_v_33 = {nl_v_32.bytes,nl_v_32.length};
NL_HEAP_SLOT(nl_v_33.bytes,nl_v_33.length);
nl_slot nl_b_6_21 = nl_v_33;
(void)nl_b_6_21;
NL_NODE_BIND(6, 21, 4, &nl_b_6_21);
nl_domain nl_v_34 = {2};
NL_HEAP_DOMAIN(nl_v_34.token);
nl_domain nl_b_6_22 = nl_v_34;
(void)nl_b_6_22;
NL_NODE_BIND(6, 22, 4, &nl_b_6_22);
const nl_node * nl_v_35;
{ const nl_domain *nl_b_7_23 = &nl_b_6_22;
(void)nl_b_7_23;
nl_slot nl_v_36 = nl_b_6_21;
nl_b_6_21 = (nl_slot){0};
nl_node_option nl_v_37 = { 0, NULL };
uint8_t nl_v_38 = 0;
nl_node nl_v_39 = { nl_v_37, nl_v_38 };
const nl_domain * nl_v_40 = nl_b_7_23;
*(nl_node *)nl_v_36.bytes = nl_v_39;
const nl_node *nl_v_41 = (nl_node *)nl_v_36.bytes;
NL_HEAP_INITIALIZE(nl_v_41,nl_v_40->token);
(void)nl_v_40;
nl_v_35 = nl_v_41;
}
const nl_node * const nl_b_6_24 = nl_v_35;
(void)nl_b_6_24;
NL_NODE_BIND(6, 24, 2, &nl_b_6_24);
nl_node_option nl_v_42;
{ const nl_domain *nl_b_8_25 = &nl_b_2_14;
(void)nl_b_8_25;
const nl_node * nl_v_43 = nl_b_2_16;
const nl_domain * nl_v_44 = nl_b_8_25;
nl_node * nl_v_45 = (nl_node *)nl_v_43;
NL_HEAP_ROOT(nl_v_45,nl_v_44->token,1,15,18,4);
(void)nl_v_44;
nl_node * nl_b_8_26 = nl_v_45;
(void)nl_b_8_26;
NL_NODE_BIND(8, 26, 4, &nl_b_8_26);
nl_node * nl_v_46 = nl_b_8_26;
nl_node_option * nl_v_47 = &nl_v_46->f0;
NL_HEAP_FIELD(nl_v_46,nl_v_47,1,11,0,19,19,4);
const nl_node * nl_v_48 = nl_b_6_24;
nl_node_option nl_v_49 = { 1, nl_v_48 };
nl_node_option nl_v_50 = *nl_v_47;
*nl_v_47 = nl_v_49;
NL_HEAP_CHANGE(nl_v_47,&nl_v_50,1);
nl_v_42 = nl_v_50;
NL_HEAP_SCOPE_END(4);
}
nl_node_option nl_b_6_27 = nl_v_42;
(void)nl_b_6_27;
NL_NODE_BIND(6, 27, 3, &nl_b_6_27);
uint8_t nl_v_51;
{ const nl_domain *nl_b_9_28 = &nl_b_6_22;
(void)nl_b_9_28;
const nl_node * nl_v_52 = nl_b_6_24;
const nl_domain * nl_v_53 = nl_b_9_28;
const nl_node * nl_v_54 = nl_v_52;
NL_HEAP_ROOT(nl_v_54,nl_v_53->token,0,26,29,5);
(void)nl_v_53;
const nl_node * nl_b_9_29 = nl_v_54;
(void)nl_b_9_29;
NL_NODE_BIND(9, 29, 4, &nl_b_9_29);
const nl_node * nl_v_55 = nl_b_9_29;
const uint8_t * nl_v_56 = &nl_v_55->f1;
NL_HEAP_FIELD(nl_v_55,nl_v_56,0,11,1,31,31,5);
uint8_t nl_v_57 = *nl_v_56;
nl_v_51 = nl_v_57;
NL_HEAP_SCOPE_END(5);
}
uint8_t nl_b_6_30 = nl_v_51;
(void)nl_b_6_30;
NL_NODE_BIND(6, 30, 4, &nl_b_6_30);
nl_node_option nl_v_58;
{ const nl_domain *nl_b_10_31 = &nl_b_6_22;
(void)nl_b_10_31;
const nl_node * nl_v_59 = nl_b_6_24;
const nl_domain * nl_v_60 = nl_b_10_31;
const nl_node * nl_v_61 = nl_v_59;
NL_HEAP_ROOT(nl_v_61,nl_v_60->token,0,26,29,6);
(void)nl_v_60;
const nl_node * nl_b_10_32 = nl_v_61;
(void)nl_b_10_32;
NL_NODE_BIND(10, 32, 4, &nl_b_10_32);
const nl_node * nl_v_62 = nl_b_10_32;
const nl_node_option * nl_v_63 = &nl_v_62->f0;
NL_HEAP_FIELD(nl_v_62,nl_v_63,0,11,0,30,30,6);
nl_node_option nl_v_64 = *nl_v_63;
NL_HEAP_COPY(nl_v_63,&nl_v_64);
nl_v_58 = nl_v_64;
NL_HEAP_SCOPE_END(6);
}
nl_node_option nl_b_6_33 = nl_v_58;
(void)nl_b_6_33;
NL_NODE_BIND(6, 33, 3, &nl_b_6_33);
nl_node_option nl_v_65 = nl_b_6_33;
uint8_t nl_v_66;
switch (nl_v_65.tag) {
case 0: {
NL_NODE_ARM(1, nl_v_65.ptr);
size_t nl_v_67=(size_t)UINTMAX_C(0);
size_t nl_v_68=(size_t)UINTMAX_C(0);
uint8_t nl_v_69=(uint8_t)(nl_v_67< nl_v_68);
nl_v_66 = nl_v_69;
break; }
case 1: {
const nl_node *const nl_b_12_34 = nl_v_65.ptr;
NL_NODE_ARM(2, nl_b_12_34);
(void)nl_b_12_34;
size_t nl_v_70=(size_t)UINTMAX_C(0);
size_t nl_v_71=(size_t)UINTMAX_C(0);
uint8_t nl_v_72=(uint8_t)(nl_v_70== nl_v_71);
nl_v_66 = nl_v_72;
break; }
default: abort();
}
NL_SCALAR_BOOL_RESULT(nl_v_66,0);
uint8_t nl_b_6_34 = nl_v_66;
(void)nl_b_6_34;
NL_NODE_BIND(6, 34, 4, &nl_b_6_34);
uint8_t nl_v_73 = nl_b_6_34;
uint8_t nl_v_74 = nl_b_6_30;
uint8_t nl_v_75;
{
const uint8_t nl_b_13_35=nl_v_73;
const uint8_t nl_b_13_36=nl_v_74;
uint8_t nl_v_76 = nl_b_13_35;
uint8_t nl_v_77;
NL_SCALAR_IF_CONDITION(nl_v_76);
if(nl_v_76){
uint8_t nl_v_78 = 0;
nl_v_77=nl_v_78;
NL_SCALAR_IF_RESULT(0,nl_v_77);
}else{
uint8_t nl_v_79 = nl_b_13_36;
nl_v_77=nl_v_79;
NL_SCALAR_IF_RESULT(1,nl_v_77);
}
nl_v_75=nl_v_77;
}
uint8_t nl_b_6_37 = nl_v_75;
(void)nl_b_6_37;
NL_NODE_BIND(6, 37, 4, &nl_b_6_37);
nl_live_tail nl_v_80;
{ const nl_domain *nl_b_16_38 = &nl_b_2_14;
(void)nl_b_16_38;
const nl_node * nl_v_81 = nl_b_2_16;
const nl_domain * nl_v_82 = nl_b_16_38;
nl_node * nl_v_83 = (nl_node *)nl_v_81;
NL_HEAP_ROOT(nl_v_83,nl_v_82->token,1,15,18,7);
(void)nl_v_82;
nl_node * nl_b_16_39 = nl_v_83;
(void)nl_b_16_39;
NL_NODE_BIND(16, 39, 4, &nl_b_16_39);
nl_node * nl_v_84 = nl_b_16_39;
nl_node_option * nl_v_85 = &nl_v_84->f0;
NL_HEAP_FIELD(nl_v_84,nl_v_85,1,11,0,19,19,7);
const nl_node * nl_v_86 = nl_b_6_24;
nl_allocation nl_v_87 = nl_b_6_20;
nl_b_6_20 = (nl_allocation){0};
nl_domain nl_v_88 = nl_b_6_22;
nl_b_6_22 = (nl_domain){0};
NL_LIVE_SEND(nl_v_86,nl_v_87.handle,nl_v_88.token,&nl_b_6_20,&nl_b_6_22);
nl_live_tail nl_v_97 = nl_producer_14(nl_v_85,nl_v_86,nl_v_87,nl_v_88);
NL_LIVE_RECEIVE(nl_v_97,&nl_b_6_20,&nl_b_6_22);
nl_v_80 = nl_v_97;
NL_HEAP_SCOPE_END(7);
}
nl_live_tail nl_b_6_46 = nl_v_80;
nl_v_80 = (nl_live_tail){0};
NL_NODE_BIND(6,46,4,&nl_b_6_46);
nl_live_tail nl_v_98 = nl_b_6_46;
nl_b_6_46 = (nl_live_tail){0};
const nl_node * nl_b_6_47 = nl_v_98.ptr;
(void)nl_b_6_47;
nl_allocation nl_b_6_48 = nl_v_98.allocation;
(void)nl_b_6_48;
nl_domain nl_b_6_49 = nl_v_98.domain;
(void)nl_b_6_49;
nl_v_98 = (nl_live_tail){0};
nl_slot nl_v_99;
{ const nl_domain *nl_b_18_50 = &nl_b_2_14;
(void)nl_b_18_50;
const nl_node * nl_v_100 = nl_b_2_16;
NL_HEAP_END(nl_v_100,nl_b_18_50->token);
nl_slot nl_v_101 = {(unsigned char *)nl_v_100,24};
nl_v_99 = nl_v_101;
}
nl_slot nl_b_6_51 = nl_v_99;
(void)nl_b_6_51;
NL_NODE_BIND(6, 51, 4, &nl_b_6_51);
nl_slot nl_v_102 = nl_b_6_51;
nl_b_6_51 = (nl_slot){0};
nl_storage nl_v_103 = {nl_v_102.bytes,nl_v_102.length};
NL_HEAP_RAW(nl_v_103.bytes,nl_v_103.length);
nl_storage nl_b_6_52 = nl_v_103;
(void)nl_b_6_52;
NL_NODE_BIND(6, 52, 4, &nl_b_6_52);
nl_domain nl_v_104 = nl_b_2_14;
nl_b_2_14 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_104.token);
(void)nl_v_104;
nl_allocation nl_v_105 = nl_b_2_12;
nl_b_2_12 = (nl_allocation){0};
nl_storage nl_v_106 = nl_b_6_52;
nl_b_6_52 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_105.handle,nl_v_106.bytes,nl_v_106.length);
free(nl_v_105.handle);
nl_v_105.handle=NULL;
nl_v_106.bytes=NULL;
(void)nl_v_106;
const nl_node * nl_v_107 = nl_b_6_47;
nl_allocation nl_v_108 = nl_b_6_48;
nl_b_6_48 = (nl_allocation){0};
nl_domain nl_v_109 = nl_b_6_49;
nl_b_6_49 = (nl_domain){0};
NL_HEAP_HANDOFF(nl_v_107,nl_v_108.handle,nl_v_109.token,&nl_b_6_48,&nl_b_6_49);
nl_owner_13(nl_v_107,nl_v_108,nl_v_109);
NL_HEAP_RETURNED(&nl_b_6_48,&nl_b_6_49);
uint8_t nl_v_118 = nl_b_6_37;
uint8_t nl_v_119 = nl_copy_state_10(&nl_b_0_1.f0,nl_v_118);
uint8_t nl_b_6_63 = nl_v_119;
(void)nl_b_6_63;
NL_NODE_BIND(6, 63, 4, &nl_b_6_63);
uint8_t nl_v_120 = nl_b_6_63;
uint8_t nl_b_6_64 = nl_v_120;
(void)nl_b_6_64;
NL_NODE_BIND(6, 64, 4, &nl_b_6_64);
}
}
uint8_t nl_v_121 = nl_b_0_6;
uint8_t nl_b_0_9 = nl_v_121;
(void)nl_b_0_9;
NL_NODE_BIND(0, 9, 4, &nl_b_0_9);
uint8_t nl_v_122=nl_b_0_1.f0;
uint8_t nl_b_0_10 = nl_v_122;
(void)nl_b_0_10;
NL_NODE_BIND(0, 10, 4, &nl_b_0_10);
uint8_t nl_v_123=nl_b_0_1.f1;
uint8_t nl_b_0_11 = nl_v_123;
(void)nl_b_0_11;
NL_NODE_BIND(0, 11, 4, &nl_b_0_11);
NL_HEAP_FINISH();
return 0;
}
