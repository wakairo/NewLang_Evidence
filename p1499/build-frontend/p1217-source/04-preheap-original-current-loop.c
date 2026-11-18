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
typedef struct {uint8_t f0,f1;} nl_current_record;
_Static_assert(SIZE_MAX==UINTMAX_C(18446744073709551615),"NewLang usize target");
#ifdef NEWLANG_CURRENT_LOOP_OBSERVER
#include NEWLANG_CURRENT_LOOP_OBSERVER
#endif
#ifndef NL_CURRENT_PHASE
#define NL_CURRENT_PHASE(...) ((void)0)
#endif
#ifndef NL_CURRENT_LOCAL
#define NL_CURRENT_LOCAL(...) ((void)0)
#endif
#ifndef NL_CURRENT_RESULT
#define NL_CURRENT_RESULT(...) ((void)0)
#endif
#ifndef NL_MIXED_COPY_BIND
#define NL_MIXED_COPY_BIND(...) ((void)0)
#endif
#ifndef NL_MIXED_COPY_STORE
#define NL_MIXED_COPY_STORE(...) ((void)0)
#endif
#ifndef NL_LOOP_READ
#define NL_LOOP_READ(...) ((void)0)
#endif
static void nl_owner_10(const nl_node *nl_b_16_36,nl_allocation nl_b_16_37,nl_domain nl_b_16_38) {
NL_HEAP_RECEIVER_ENTER(nl_b_16_36,nl_b_16_37.handle,nl_b_16_38.token,16,36,37,38,&nl_b_16_37,&nl_b_16_38);
{ const nl_domain *nl_b_17_39 = &nl_b_16_38;
(void)nl_b_17_39;
const nl_node * nl_v_78 = nl_b_16_36;
const nl_domain * nl_v_79 = nl_b_17_39;
const nl_node * nl_v_80 = nl_v_78;
NL_HEAP_ROOT(nl_v_80,nl_v_79->token,0,19,22,7);
(void)nl_v_79;
const nl_node * nl_b_17_40 = nl_v_80;
(void)nl_b_17_40;
NL_NODE_BIND(17, 40, 4, &nl_b_17_40);
NL_HEAP_SCOPE_END(7);
}
nl_slot nl_v_81;
{ const nl_domain *nl_b_18_41 = &nl_b_16_38;
(void)nl_b_18_41;
const nl_node * nl_v_82 = nl_b_16_36;
NL_HEAP_END(nl_v_82,nl_b_18_41->token);
nl_slot nl_v_83 = {(unsigned char *)nl_v_82,24};
nl_v_81 = nl_v_83;
}
nl_slot nl_b_16_42 = nl_v_81;
(void)nl_b_16_42;
NL_NODE_BIND(16, 42, 4, &nl_b_16_42);
nl_slot nl_v_84 = nl_b_16_42;
nl_b_16_42 = (nl_slot){0};
nl_storage nl_v_85 = {nl_v_84.bytes,nl_v_84.length};
NL_HEAP_RAW(nl_v_85.bytes,nl_v_85.length);
nl_storage nl_b_16_43 = nl_v_85;
(void)nl_b_16_43;
NL_NODE_BIND(16, 43, 4, &nl_b_16_43);
nl_domain nl_v_86 = nl_b_16_38;
nl_b_16_38 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_86.token);
(void)nl_v_86;
nl_allocation nl_v_87 = nl_b_16_37;
nl_b_16_37 = (nl_allocation){0};
nl_storage nl_v_88 = nl_b_16_43;
nl_b_16_43 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_87.handle,nl_v_88.bytes,nl_v_88.length);
free(nl_v_87.handle);
nl_v_87.handle=NULL;
nl_v_88.bytes=NULL;
(void)nl_v_88;
NL_HEAP_RECEIVER_EXIT();
}
static nl_live_tail nl_producer_13(nl_node_option * nl_b_14_26,const nl_node * nl_b_14_27,nl_allocation nl_b_14_28,nl_domain nl_b_14_29) {
NL_LIVE_ENTER(nl_b_14_26,nl_b_14_27,nl_b_14_28.handle,nl_b_14_29.token);
nl_node_option * nl_v_64 = nl_b_14_26;
nl_node_option nl_v_65 = { 0, NULL };
nl_node_option nl_v_66 = *nl_v_64;
*nl_v_64 = nl_v_65;
NL_HEAP_CHANGE(nl_v_64,&nl_v_66,2);
(void)nl_v_66;
const nl_node * nl_v_67 = nl_b_14_27;
nl_allocation nl_v_68 = nl_b_14_28;
nl_b_14_28 = (nl_allocation){0};
nl_domain nl_v_69 = nl_b_14_29;
nl_b_14_29 = (nl_domain){0};
nl_live_tail nl_v_70 = {nl_v_67,nl_v_68,nl_v_69};
NL_LIVE_RETURN(nl_v_70);
return nl_v_70;
}
int main(void) {
nl_current_record nl_b_0_1={.f0=43,.f1=229,};
NL_MIXED_COPY_BIND(0,1,&nl_b_0_1.f0,&nl_b_0_1.f1);
void *nl_heap_1 = malloc(24);
NL_HEAP_TRIAL(nl_heap_1,24,8);
if (nl_heap_1 == NULL) {
NL_HEAP_ARM(1);
}
if (nl_heap_1 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_2_2 = { {nl_heap_1}, {(unsigned char *)nl_heap_1,24} };
nl_backing nl_v_2 = nl_b_2_2;
nl_b_2_2 = (nl_backing){0};
nl_allocation nl_b_2_3 = nl_v_2.allocation;
(void)nl_b_2_3;
nl_storage nl_b_2_4 = nl_v_2.raw;
(void)nl_b_2_4;
nl_v_2 = (nl_backing){0};
nl_allocation nl_v_3 = nl_b_2_3;
nl_b_2_3 = (nl_allocation){0};
nl_allocation nl_b_2_5 = nl_v_3;
(void)nl_b_2_5;
NL_NODE_BIND(2, 5, 4, &nl_b_2_5);
nl_storage nl_v_4 = nl_b_2_4;
nl_b_2_4 = (nl_storage){0};
nl_slot nl_v_5 = {nl_v_4.bytes,nl_v_4.length};
NL_HEAP_SLOT(nl_v_5.bytes,nl_v_5.length);
nl_slot nl_b_2_6 = nl_v_5;
(void)nl_b_2_6;
NL_NODE_BIND(2, 6, 4, &nl_b_2_6);
nl_domain nl_v_6 = {1};
NL_HEAP_DOMAIN(nl_v_6.token);
nl_domain nl_b_2_7 = nl_v_6;
(void)nl_b_2_7;
NL_NODE_BIND(2, 7, 4, &nl_b_2_7);
const nl_node * nl_v_7;
{ const nl_domain *nl_b_3_8 = &nl_b_2_7;
(void)nl_b_3_8;
nl_slot nl_v_8 = nl_b_2_6;
nl_b_2_6 = (nl_slot){0};
nl_node_option nl_v_9 = { 0, NULL };
uint8_t nl_v_10 = 14;
nl_node nl_v_11 = { nl_v_9, nl_v_10 };
const nl_domain * nl_v_12 = nl_b_3_8;
*(nl_node *)nl_v_8.bytes = nl_v_11;
const nl_node *nl_v_13 = (nl_node *)nl_v_8.bytes;
NL_HEAP_INITIALIZE(nl_v_13,nl_v_12->token);
(void)nl_v_12;
nl_v_7 = nl_v_13;
}
const nl_node * const nl_b_2_9 = nl_v_7;
(void)nl_b_2_9;
NL_NODE_BIND(2, 9, 2, &nl_b_2_9);
void *nl_heap_14 = malloc(24);
NL_HEAP_TRIAL(nl_heap_14,24,8);
if (nl_heap_14 == NULL) {
NL_HEAP_ARM(1);
nl_slot nl_v_15;
{ const nl_domain *nl_b_5_10 = &nl_b_2_7;
(void)nl_b_5_10;
const nl_node * nl_v_16 = nl_b_2_9;
NL_HEAP_END(nl_v_16,nl_b_5_10->token);
nl_slot nl_v_17 = {(unsigned char *)nl_v_16,24};
nl_v_15 = nl_v_17;
}
nl_slot nl_b_4_11 = nl_v_15;
(void)nl_b_4_11;
NL_NODE_BIND(4, 11, 4, &nl_b_4_11);
nl_slot nl_v_18 = nl_b_4_11;
nl_b_4_11 = (nl_slot){0};
nl_storage nl_v_19 = {nl_v_18.bytes,nl_v_18.length};
NL_HEAP_RAW(nl_v_19.bytes,nl_v_19.length);
nl_storage nl_b_4_12 = nl_v_19;
(void)nl_b_4_12;
NL_NODE_BIND(4, 12, 4, &nl_b_4_12);
nl_domain nl_v_20 = nl_b_2_7;
nl_b_2_7 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_20.token);
(void)nl_v_20;
nl_allocation nl_v_21 = nl_b_2_5;
nl_b_2_5 = (nl_allocation){0};
nl_storage nl_v_22 = nl_b_4_12;
nl_b_4_12 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_21.handle,nl_v_22.bytes,nl_v_22.length);
free(nl_v_21.handle);
nl_v_21.handle=NULL;
nl_v_22.bytes=NULL;
(void)nl_v_22;
}
if (nl_heap_14 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_6_10 = { {nl_heap_14}, {(unsigned char *)nl_heap_14,24} };
nl_backing nl_v_23 = nl_b_6_10;
nl_b_6_10 = (nl_backing){0};
nl_allocation nl_b_6_11 = nl_v_23.allocation;
(void)nl_b_6_11;
nl_storage nl_b_6_12 = nl_v_23.raw;
(void)nl_b_6_12;
nl_v_23 = (nl_backing){0};
nl_allocation nl_v_24 = nl_b_6_11;
nl_b_6_11 = (nl_allocation){0};
nl_allocation nl_b_6_13 = nl_v_24;
(void)nl_b_6_13;
NL_NODE_BIND(6, 13, 4, &nl_b_6_13);
nl_storage nl_v_25 = nl_b_6_12;
nl_b_6_12 = (nl_storage){0};
nl_slot nl_v_26 = {nl_v_25.bytes,nl_v_25.length};
NL_HEAP_SLOT(nl_v_26.bytes,nl_v_26.length);
nl_slot nl_b_6_14 = nl_v_26;
(void)nl_b_6_14;
NL_NODE_BIND(6, 14, 4, &nl_b_6_14);
nl_domain nl_v_27 = {2};
NL_HEAP_DOMAIN(nl_v_27.token);
nl_domain nl_b_6_15 = nl_v_27;
(void)nl_b_6_15;
NL_NODE_BIND(6, 15, 4, &nl_b_6_15);
const nl_node * nl_v_28;
{ const nl_domain *nl_b_7_16 = &nl_b_6_15;
(void)nl_b_7_16;
nl_slot nl_v_29 = nl_b_6_14;
nl_b_6_14 = (nl_slot){0};
nl_node_option nl_v_30 = { 0, NULL };
uint8_t nl_v_31 = 235;
nl_node nl_v_32 = { nl_v_30, nl_v_31 };
const nl_domain * nl_v_33 = nl_b_7_16;
*(nl_node *)nl_v_29.bytes = nl_v_32;
const nl_node *nl_v_34 = (nl_node *)nl_v_29.bytes;
NL_HEAP_INITIALIZE(nl_v_34,nl_v_33->token);
(void)nl_v_33;
nl_v_28 = nl_v_34;
}
const nl_node * const nl_b_6_17 = nl_v_28;
(void)nl_b_6_17;
NL_NODE_BIND(6, 17, 2, &nl_b_6_17);
nl_node_option nl_v_35;
{ const nl_domain *nl_b_8_18 = &nl_b_2_7;
(void)nl_b_8_18;
const nl_node * nl_v_36 = nl_b_2_9;
const nl_domain * nl_v_37 = nl_b_8_18;
nl_node * nl_v_38 = (nl_node *)nl_v_36;
NL_HEAP_ROOT(nl_v_38,nl_v_37->token,1,8,11,3);
(void)nl_v_37;
nl_node * nl_b_8_19 = nl_v_38;
(void)nl_b_8_19;
NL_NODE_BIND(8, 19, 4, &nl_b_8_19);
nl_node * nl_v_39 = nl_b_8_19;
nl_node_option * nl_v_40 = &nl_v_39->f0;
NL_HEAP_FIELD(nl_v_39,nl_v_40,1,11,0,12,12,3);
const nl_node * nl_v_41 = nl_b_6_17;
nl_node_option nl_v_42 = { 1, nl_v_41 };
nl_node_option nl_v_43 = *nl_v_40;
*nl_v_40 = nl_v_42;
NL_HEAP_CHANGE(nl_v_40,&nl_v_43,1);
nl_v_35 = nl_v_43;
NL_HEAP_SCOPE_END(3);
}
nl_node_option nl_b_6_20 = nl_v_35;
(void)nl_b_6_20;
NL_NODE_BIND(6, 20, 3, &nl_b_6_20);
nl_node_option nl_v_44;
{ const nl_domain *nl_b_9_21 = &nl_b_2_7;
(void)nl_b_9_21;
const nl_node * nl_v_45 = nl_b_2_9;
const nl_domain * nl_v_46 = nl_b_9_21;
const nl_node * nl_v_47 = nl_v_45;
NL_HEAP_ROOT(nl_v_47,nl_v_46->token,0,8,11,4);
(void)nl_v_46;
const nl_node * nl_b_9_22 = nl_v_47;
(void)nl_b_9_22;
NL_NODE_BIND(9, 22, 4, &nl_b_9_22);
const nl_node * nl_v_48 = nl_b_9_22;
const nl_node_option * nl_v_49 = &nl_v_48->f0;
NL_HEAP_FIELD(nl_v_48,nl_v_49,0,11,0,12,12,4);
nl_node_option nl_v_50 = *nl_v_49;
NL_HEAP_COPY(nl_v_49,&nl_v_50);
nl_v_44 = nl_v_50;
NL_HEAP_SCOPE_END(4);
}
nl_node_option nl_b_6_23 = nl_v_44;
(void)nl_b_6_23;
NL_NODE_BIND(6, 23, 3, &nl_b_6_23);
nl_node_option nl_v_51 = nl_b_6_23;
switch (nl_v_51.tag) {
case 0: {
NL_NODE_ARM(1, nl_v_51.ptr);
break; }
case 1: {
const nl_node *const nl_b_11_24 = nl_v_51.ptr;
NL_NODE_ARM(2, nl_b_11_24);
(void)nl_b_11_24;
{ const nl_domain *nl_b_12_25 = &nl_b_6_15;
(void)nl_b_12_25;
const nl_node * nl_v_52 = nl_b_11_24;
const nl_domain * nl_v_53 = nl_b_12_25;
const nl_node * nl_v_54 = nl_v_52;
NL_HEAP_ROOT(nl_v_54,nl_v_53->token,0,19,22,5);
(void)nl_v_53;
const nl_node * nl_b_12_26 = nl_v_54;
(void)nl_b_12_26;
NL_NODE_BIND(12, 26, 4, &nl_b_12_26);
NL_HEAP_SCOPE_END(5);
}
break; }
}
nl_live_tail nl_v_55;
{ const nl_domain *nl_b_13_24 = &nl_b_2_7;
(void)nl_b_13_24;
const nl_node * nl_v_56 = nl_b_2_9;
const nl_domain * nl_v_57 = nl_b_13_24;
nl_node * nl_v_58 = (nl_node *)nl_v_56;
NL_HEAP_ROOT(nl_v_58,nl_v_57->token,1,8,11,5);
(void)nl_v_57;
nl_node * nl_b_13_25 = nl_v_58;
(void)nl_b_13_25;
NL_NODE_BIND(13, 25, 4, &nl_b_13_25);
nl_node * nl_v_59 = nl_b_13_25;
nl_node_option * nl_v_60 = &nl_v_59->f0;
NL_HEAP_FIELD(nl_v_59,nl_v_60,1,11,0,12,12,5);
const nl_node * nl_v_61 = nl_b_6_17;
nl_allocation nl_v_62 = nl_b_6_13;
nl_b_6_13 = (nl_allocation){0};
nl_domain nl_v_63 = nl_b_6_15;
nl_b_6_15 = (nl_domain){0};
NL_LIVE_SEND(nl_v_61,nl_v_62.handle,nl_v_63.token,&nl_b_6_13,&nl_b_6_15);
nl_live_tail nl_v_71 = nl_producer_13(nl_v_60,nl_v_61,nl_v_62,nl_v_63);
NL_LIVE_RECEIVE(nl_v_71,&nl_b_6_13,&nl_b_6_15);
nl_v_55 = nl_v_71;
NL_HEAP_SCOPE_END(5);
}
const nl_node * nl_b_6_31 = nl_v_55.ptr;
(void)nl_b_6_31;
nl_allocation nl_b_6_32 = nl_v_55.allocation;
(void)nl_b_6_32;
nl_domain nl_b_6_33 = nl_v_55.domain;
(void)nl_b_6_33;
nl_v_55 = (nl_live_tail){0};
{ const nl_domain *nl_b_15_34 = &nl_b_6_33;
(void)nl_b_15_34;
const nl_node * nl_v_72 = nl_b_6_31;
const nl_domain * nl_v_73 = nl_b_15_34;
const nl_node * nl_v_74 = nl_v_72;
NL_HEAP_ROOT(nl_v_74,nl_v_73->token,0,19,22,6);
(void)nl_v_73;
const nl_node * nl_b_15_35 = nl_v_74;
(void)nl_b_15_35;
NL_NODE_BIND(15, 35, 4, &nl_b_15_35);
NL_HEAP_SCOPE_END(6);
}
const nl_node * nl_v_75 = nl_b_6_31;
nl_allocation nl_v_76 = nl_b_6_32;
nl_b_6_32 = (nl_allocation){0};
nl_domain nl_v_77 = nl_b_6_33;
nl_b_6_33 = (nl_domain){0};
NL_HEAP_HANDOFF(nl_v_75,nl_v_76.handle,nl_v_77.token,&nl_b_6_32,&nl_b_6_33);
nl_owner_10(nl_v_75,nl_v_76,nl_v_77);
NL_HEAP_RETURNED(&nl_b_6_32,&nl_b_6_33);
nl_slot nl_v_89;
{ const nl_domain *nl_b_19_44 = &nl_b_2_7;
(void)nl_b_19_44;
const nl_node * nl_v_90 = nl_b_2_9;
NL_HEAP_END(nl_v_90,nl_b_19_44->token);
nl_slot nl_v_91 = {(unsigned char *)nl_v_90,24};
nl_v_89 = nl_v_91;
}
nl_slot nl_b_6_45 = nl_v_89;
(void)nl_b_6_45;
NL_NODE_BIND(6, 45, 4, &nl_b_6_45);
nl_slot nl_v_92 = nl_b_6_45;
nl_b_6_45 = (nl_slot){0};
nl_storage nl_v_93 = {nl_v_92.bytes,nl_v_92.length};
NL_HEAP_RAW(nl_v_93.bytes,nl_v_93.length);
nl_storage nl_b_6_46 = nl_v_93;
(void)nl_b_6_46;
NL_NODE_BIND(6, 46, 4, &nl_b_6_46);
nl_domain nl_v_94 = nl_b_2_7;
nl_b_2_7 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_94.token);
(void)nl_v_94;
nl_allocation nl_v_95 = nl_b_2_5;
nl_b_2_5 = (nl_allocation){0};
nl_storage nl_v_96 = nl_b_6_46;
nl_b_6_46 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_95.handle,nl_v_96.bytes,nl_v_96.length);
free(nl_v_95.handle);
nl_v_95.handle=NULL;
nl_v_96.bytes=NULL;
(void)nl_v_96;
}
}
size_t nl_v_97=(size_t)UINTMAX_C(0);
size_t nl_b_0_2=nl_v_97;
(void)nl_b_0_2;
size_t nl_v_98=nl_b_0_2;
size_t nl_b_0_3=nl_v_98;
(void)nl_b_0_3;
size_t nl_v_99=nl_b_0_3;
size_t nl_v_100;
{
size_t nl_current_carry=nl_v_99;
for (;;) {
const size_t nl_current_phase=nl_current_carry;
NL_CURRENT_PHASE(nl_current_phase,&nl_b_0_1.f0,&nl_b_0_1.f1);
if (nl_current_phase < (size_t)UINTMAX_C(4)) {
size_t nl_v_101=nl_current_phase;
size_t nl_b_20_5=nl_v_101;
(void)nl_b_20_5;
NL_CURRENT_LOCAL(5,nl_b_20_5);
size_t nl_v_102=nl_b_20_5;
uint8_t nl_v_103=(nl_v_102 == (size_t)UINTMAX_C(1) ? 83 : 173);
uint8_t nl_b_20_7=nl_v_103;
(void)nl_b_20_7;
NL_CURRENT_LOCAL(7,nl_b_20_7);
uint8_t nl_v_104=nl_b_20_7;
uint8_t nl_v_105;
{
uint8_t *const nl_current_write=&nl_b_0_1.f1;
nl_v_105=*nl_current_write;
*nl_current_write=nl_v_104;
NL_MIXED_COPY_STORE(nl_current_write,nl_v_105,nl_v_104);
}
uint8_t nl_b_20_9=nl_v_105;
(void)nl_b_20_9;
NL_CURRENT_LOCAL(9,nl_b_20_9);
uint8_t nl_v_106=nl_b_20_9;
uint8_t nl_b_20_10=nl_v_106;
(void)nl_b_20_10;
NL_CURRENT_LOCAL(10,nl_b_20_10);
uint8_t nl_v_107=nl_b_20_10;
(void)nl_v_107;
uint8_t nl_v_108=nl_b_0_1.f1;
uint8_t nl_b_20_11=nl_v_108;
(void)nl_b_20_11;
NL_CURRENT_LOCAL(11,nl_b_20_11);
uint8_t nl_v_109=nl_b_0_1.f0;
uint8_t nl_b_20_12=nl_v_109;
(void)nl_b_20_12;
NL_CURRENT_LOCAL(12,nl_b_20_12);
uint8_t nl_v_110=nl_b_20_11;
(void)nl_v_110;
uint8_t nl_v_111=nl_b_20_12;
(void)nl_v_111;
nl_current_carry=nl_current_phase+(size_t)UINTMAX_C(1);
continue;
}
nl_v_100=nl_current_phase;
NL_CURRENT_RESULT(nl_v_100);
break;
}
}
size_t nl_b_0_4=nl_v_100;
(void)nl_b_0_4;
uint8_t nl_v_112=nl_b_0_1.f1;
NL_LOOP_READ(&nl_b_0_1.f1,nl_v_112);
uint8_t nl_b_0_5=nl_v_112;
(void)nl_b_0_5;
uint8_t nl_v_113=nl_b_0_1.f0;
NL_LOOP_READ(&nl_b_0_1.f0,nl_v_113);
uint8_t nl_b_0_6=nl_v_113;
(void)nl_b_0_6;
size_t nl_v_114=nl_b_0_4;
size_t nl_b_0_7=nl_v_114;
(void)nl_b_0_7;
NL_HEAP_FINISH();
return 0;
}
