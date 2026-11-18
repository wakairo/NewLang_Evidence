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
static uint8_t nl_copy_state_12(uint8_t *target,uint8_t next){uint8_t old=*target;*target=next;NL_MIXED_COPY_CALL(target,old,next);return old;}
static void nl_owner_10(const nl_node *nl_b_15_35,nl_allocation nl_b_15_36,nl_domain nl_b_15_37) {
NL_HEAP_RECEIVER_ENTER(nl_b_15_35,nl_b_15_36.handle,nl_b_15_37.token,15,35,36,37,&nl_b_15_36,&nl_b_15_37);
{ const nl_domain *nl_b_16_38 = &nl_b_15_37;
(void)nl_b_16_38;
const nl_node * nl_v_95 = nl_b_15_35;
const nl_domain * nl_v_96 = nl_b_16_38;
const nl_node * nl_v_97 = nl_v_95;
NL_HEAP_ROOT(nl_v_97,nl_v_96->token,0,19,22,6);
(void)nl_v_96;
const nl_node * nl_b_16_39 = nl_v_97;
(void)nl_b_16_39;
NL_NODE_BIND(16, 39, 4, &nl_b_16_39);
NL_HEAP_SCOPE_END(6);
}
nl_slot nl_v_98;
{ const nl_domain *nl_b_17_40 = &nl_b_15_37;
(void)nl_b_17_40;
const nl_node * nl_v_99 = nl_b_15_35;
NL_HEAP_END(nl_v_99,nl_b_17_40->token);
nl_slot nl_v_100 = {(unsigned char *)nl_v_99,24};
nl_v_98 = nl_v_100;
}
nl_slot nl_b_15_41 = nl_v_98;
(void)nl_b_15_41;
NL_NODE_BIND(15, 41, 4, &nl_b_15_41);
nl_slot nl_v_101 = nl_b_15_41;
nl_b_15_41 = (nl_slot){0};
nl_storage nl_v_102 = {nl_v_101.bytes,nl_v_101.length};
NL_HEAP_RAW(nl_v_102.bytes,nl_v_102.length);
nl_storage nl_b_15_42 = nl_v_102;
(void)nl_b_15_42;
NL_NODE_BIND(15, 42, 4, &nl_b_15_42);
nl_domain nl_v_103 = nl_b_15_37;
nl_b_15_37 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_103.token);
(void)nl_v_103;
nl_allocation nl_v_104 = nl_b_15_36;
nl_b_15_36 = (nl_allocation){0};
nl_storage nl_v_105 = nl_b_15_42;
nl_b_15_42 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_104.handle,nl_v_105.bytes,nl_v_105.length);
free(nl_v_104.handle);
nl_v_104.handle=NULL;
nl_v_105.bytes=NULL;
(void)nl_v_105;
NL_HEAP_RECEIVER_EXIT();
}
static nl_live_tail nl_producer_11(nl_node_option * nl_b_14_27,const nl_node * nl_b_14_28,nl_allocation nl_b_14_29,nl_domain nl_b_14_30) {
NL_LIVE_ENTER(nl_b_14_27,nl_b_14_28,nl_b_14_29.handle,nl_b_14_30.token);
nl_node_option * nl_v_84 = nl_b_14_27;
nl_node_option nl_v_85 = { 0, NULL };
nl_node_option nl_v_86 = *nl_v_84;
*nl_v_84 = nl_v_85;
NL_HEAP_CHANGE(nl_v_84,&nl_v_86,2);
(void)nl_v_86;
const nl_node * nl_v_87 = nl_b_14_28;
nl_allocation nl_v_88 = nl_b_14_29;
nl_b_14_29 = (nl_allocation){0};
nl_domain nl_v_89 = nl_b_14_30;
nl_b_14_30 = (nl_domain){0};
nl_live_tail nl_v_90 = {nl_v_87,nl_v_88,nl_v_89};
NL_LIVE_RETURN(nl_v_90);
return nl_v_90;
}
int main(void) {
uint8_t nl_v_1 = 101;
uint8_t nl_v_2 = 213;
nl_copy_record nl_v_3 = {nl_v_2,nl_v_1};
nl_copy_record nl_b_0_1 = nl_v_3;
NL_MIXED_COPY_BIND(0,1,&nl_b_0_1.f0,&nl_b_0_1.f1);
uint8_t nl_v_4;
void *nl_heap_5 = malloc(24);
NL_HEAP_TRIAL(nl_heap_5,24,8);
if (nl_heap_5 == NULL) {
NL_HEAP_ARM(1);
uint8_t nl_v_6 = 13;
nl_v_4 = nl_v_6;
}
if (nl_heap_5 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_2_2 = { {nl_heap_5}, {(unsigned char *)nl_heap_5,24} };
nl_backing nl_v_7 = nl_b_2_2;
nl_b_2_2 = (nl_backing){0};
nl_allocation nl_b_2_3 = nl_v_7.allocation;
(void)nl_b_2_3;
nl_storage nl_b_2_4 = nl_v_7.raw;
(void)nl_b_2_4;
nl_v_7 = (nl_backing){0};
nl_allocation nl_v_8 = nl_b_2_3;
nl_b_2_3 = (nl_allocation){0};
nl_allocation nl_b_2_5 = nl_v_8;
(void)nl_b_2_5;
NL_NODE_BIND(2, 5, 4, &nl_b_2_5);
nl_storage nl_v_9 = nl_b_2_4;
nl_b_2_4 = (nl_storage){0};
nl_slot nl_v_10 = {nl_v_9.bytes,nl_v_9.length};
NL_HEAP_SLOT(nl_v_10.bytes,nl_v_10.length);
nl_slot nl_b_2_6 = nl_v_10;
(void)nl_b_2_6;
NL_NODE_BIND(2, 6, 4, &nl_b_2_6);
nl_domain nl_v_11 = {1};
NL_HEAP_DOMAIN(nl_v_11.token);
nl_domain nl_b_2_7 = nl_v_11;
(void)nl_b_2_7;
NL_NODE_BIND(2, 7, 4, &nl_b_2_7);
const nl_node * nl_v_12;
{ const nl_domain *nl_b_3_8 = &nl_b_2_7;
(void)nl_b_3_8;
nl_slot nl_v_13 = nl_b_2_6;
nl_b_2_6 = (nl_slot){0};
nl_node_option nl_v_14 = { 0, NULL };
uint8_t nl_v_15 = 233;
nl_node nl_v_16 = { nl_v_14, nl_v_15 };
const nl_domain * nl_v_17 = nl_b_3_8;
*(nl_node *)nl_v_13.bytes = nl_v_16;
const nl_node *nl_v_18 = (nl_node *)nl_v_13.bytes;
NL_HEAP_INITIALIZE(nl_v_18,nl_v_17->token);
(void)nl_v_17;
nl_v_12 = nl_v_18;
}
const nl_node * const nl_b_2_9 = nl_v_12;
(void)nl_b_2_9;
NL_NODE_BIND(2, 9, 2, &nl_b_2_9);
uint8_t nl_v_19;
void *nl_heap_20 = malloc(24);
NL_HEAP_TRIAL(nl_heap_20,24,8);
if (nl_heap_20 == NULL) {
NL_HEAP_ARM(1);
nl_slot nl_v_21;
{ const nl_domain *nl_b_5_10 = &nl_b_2_7;
(void)nl_b_5_10;
const nl_node * nl_v_22 = nl_b_2_9;
NL_HEAP_END(nl_v_22,nl_b_5_10->token);
nl_slot nl_v_23 = {(unsigned char *)nl_v_22,24};
nl_v_21 = nl_v_23;
}
nl_slot nl_b_4_11 = nl_v_21;
(void)nl_b_4_11;
NL_NODE_BIND(4, 11, 4, &nl_b_4_11);
nl_slot nl_v_24 = nl_b_4_11;
nl_b_4_11 = (nl_slot){0};
nl_storage nl_v_25 = {nl_v_24.bytes,nl_v_24.length};
NL_HEAP_RAW(nl_v_25.bytes,nl_v_25.length);
nl_storage nl_b_4_12 = nl_v_25;
(void)nl_b_4_12;
NL_NODE_BIND(4, 12, 4, &nl_b_4_12);
nl_domain nl_v_26 = nl_b_2_7;
nl_b_2_7 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_26.token);
(void)nl_v_26;
nl_allocation nl_v_27 = nl_b_2_5;
nl_b_2_5 = (nl_allocation){0};
nl_storage nl_v_28 = nl_b_4_12;
nl_b_4_12 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_27.handle,nl_v_28.bytes,nl_v_28.length);
free(nl_v_27.handle);
nl_v_27.handle=NULL;
nl_v_28.bytes=NULL;
(void)nl_v_28;
uint8_t nl_v_29 = 29;
nl_v_19 = nl_v_29;
}
if (nl_heap_20 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_6_10 = { {nl_heap_20}, {(unsigned char *)nl_heap_20,24} };
nl_backing nl_v_30 = nl_b_6_10;
nl_b_6_10 = (nl_backing){0};
nl_allocation nl_b_6_11 = nl_v_30.allocation;
(void)nl_b_6_11;
nl_storage nl_b_6_12 = nl_v_30.raw;
(void)nl_b_6_12;
nl_v_30 = (nl_backing){0};
nl_allocation nl_v_31 = nl_b_6_11;
nl_b_6_11 = (nl_allocation){0};
nl_allocation nl_b_6_13 = nl_v_31;
(void)nl_b_6_13;
NL_NODE_BIND(6, 13, 4, &nl_b_6_13);
nl_storage nl_v_32 = nl_b_6_12;
nl_b_6_12 = (nl_storage){0};
nl_slot nl_v_33 = {nl_v_32.bytes,nl_v_32.length};
NL_HEAP_SLOT(nl_v_33.bytes,nl_v_33.length);
nl_slot nl_b_6_14 = nl_v_33;
(void)nl_b_6_14;
NL_NODE_BIND(6, 14, 4, &nl_b_6_14);
nl_domain nl_v_34 = {2};
NL_HEAP_DOMAIN(nl_v_34.token);
nl_domain nl_b_6_15 = nl_v_34;
(void)nl_b_6_15;
NL_NODE_BIND(6, 15, 4, &nl_b_6_15);
const nl_node * nl_v_35;
{ const nl_domain *nl_b_7_16 = &nl_b_6_15;
(void)nl_b_7_16;
nl_slot nl_v_36 = nl_b_6_14;
nl_b_6_14 = (nl_slot){0};
nl_node_option nl_v_37 = { 0, NULL };
uint8_t nl_v_38 = 163;
nl_node nl_v_39 = { nl_v_37, nl_v_38 };
const nl_domain * nl_v_40 = nl_b_7_16;
*(nl_node *)nl_v_36.bytes = nl_v_39;
const nl_node *nl_v_41 = (nl_node *)nl_v_36.bytes;
NL_HEAP_INITIALIZE(nl_v_41,nl_v_40->token);
(void)nl_v_40;
nl_v_35 = nl_v_41;
}
const nl_node * const nl_b_6_17 = nl_v_35;
(void)nl_b_6_17;
NL_NODE_BIND(6, 17, 2, &nl_b_6_17);
nl_node_option nl_v_42;
{ const nl_domain *nl_b_8_18 = &nl_b_2_7;
(void)nl_b_8_18;
const nl_node * nl_v_43 = nl_b_2_9;
const nl_domain * nl_v_44 = nl_b_8_18;
nl_node * nl_v_45 = (nl_node *)nl_v_43;
NL_HEAP_ROOT(nl_v_45,nl_v_44->token,1,8,11,3);
(void)nl_v_44;
nl_node * nl_b_8_19 = nl_v_45;
(void)nl_b_8_19;
NL_NODE_BIND(8, 19, 4, &nl_b_8_19);
nl_node * nl_v_46 = nl_b_8_19;
nl_node_option * nl_v_47 = &nl_v_46->f0;
NL_HEAP_FIELD(nl_v_46,nl_v_47,1,11,0,12,12,3);
const nl_node * nl_v_48 = nl_b_6_17;
nl_node_option nl_v_49 = { 1, nl_v_48 };
nl_node_option nl_v_50 = *nl_v_47;
*nl_v_47 = nl_v_49;
NL_HEAP_CHANGE(nl_v_47,&nl_v_50,1);
nl_v_42 = nl_v_50;
NL_HEAP_SCOPE_END(3);
}
nl_node_option nl_b_6_20 = nl_v_42;
(void)nl_b_6_20;
NL_NODE_BIND(6, 20, 3, &nl_b_6_20);
nl_node_option nl_v_51;
{ const nl_domain *nl_b_9_21 = &nl_b_2_7;
(void)nl_b_9_21;
const nl_node * nl_v_52 = nl_b_2_9;
const nl_domain * nl_v_53 = nl_b_9_21;
const nl_node * nl_v_54 = nl_v_52;
NL_HEAP_ROOT(nl_v_54,nl_v_53->token,0,8,11,4);
(void)nl_v_53;
const nl_node * nl_b_9_22 = nl_v_54;
(void)nl_b_9_22;
NL_NODE_BIND(9, 22, 4, &nl_b_9_22);
const nl_node * nl_v_55 = nl_b_9_22;
const nl_node_option * nl_v_56 = &nl_v_55->f0;
NL_HEAP_FIELD(nl_v_55,nl_v_56,0,11,0,12,12,4);
nl_node_option nl_v_57 = *nl_v_56;
NL_HEAP_COPY(nl_v_56,&nl_v_57);
nl_v_51 = nl_v_57;
NL_HEAP_SCOPE_END(4);
}
nl_node_option nl_b_6_23 = nl_v_51;
(void)nl_b_6_23;
NL_NODE_BIND(6, 23, 3, &nl_b_6_23);
nl_node_option nl_v_58 = nl_b_6_23;
uint8_t nl_v_59;
switch (nl_v_58.tag) {
case 0: {
NL_NODE_ARM(1, nl_v_58.ptr);
uint8_t nl_v_60 = 47;
nl_v_59 = nl_v_60;
break; }
case 1: {
const nl_node *const nl_b_11_24 = nl_v_58.ptr;
NL_NODE_ARM(2, nl_b_11_24);
(void)nl_b_11_24;
uint8_t nl_v_61;
{ const nl_domain *nl_b_12_25 = &nl_b_6_15;
(void)nl_b_12_25;
const nl_node * nl_v_62 = nl_b_11_24;
const nl_domain * nl_v_63 = nl_b_12_25;
const nl_node * nl_v_64 = nl_v_62;
NL_HEAP_ROOT(nl_v_64,nl_v_63->token,0,19,22,5);
(void)nl_v_63;
const nl_node * nl_b_12_26 = nl_v_64;
(void)nl_b_12_26;
NL_NODE_BIND(12, 26, 4, &nl_b_12_26);
const nl_node * nl_v_65 = nl_b_12_26;
const uint8_t * nl_v_66 = &nl_v_65->f1;
NL_HEAP_FIELD(nl_v_65,nl_v_66,0,11,1,24,24,5);
uint8_t nl_v_67 = *nl_v_66;
nl_v_61 = nl_v_67;
NL_HEAP_SCOPE_END(5);
}
uint8_t nl_b_11_27 = nl_v_61;
(void)nl_b_11_27;
NL_NODE_BIND(11, 27, 4, &nl_b_11_27);
uint8_t nl_v_68 = 179;
uint8_t nl_v_69 = 71;
nl_copy_record nl_v_70 = {nl_v_68,nl_v_69};
nl_copy_record nl_b_11_28 = nl_v_70;
NL_MIXED_COPY_BIND(11,28,&nl_b_11_28.f0,&nl_b_11_28.f1);
uint8_t nl_v_71 = nl_b_11_27;
uint8_t nl_v_72 = nl_copy_state_12(&nl_b_11_28.f1,nl_v_71);
uint8_t nl_b_11_33 = nl_v_72;
(void)nl_b_11_33;
NL_NODE_BIND(11, 33, 4, &nl_b_11_33);
uint8_t nl_v_73 = nl_b_11_33;
uint8_t nl_b_11_34 = nl_v_73;
(void)nl_b_11_34;
NL_NODE_BIND(11, 34, 4, &nl_b_11_34);
uint8_t nl_v_74 = nl_b_11_34;
nl_v_59 = nl_v_74;
break; }
default: abort();
}
uint8_t nl_b_6_24 = nl_v_59;
(void)nl_b_6_24;
NL_NODE_BIND(6, 24, 4, &nl_b_6_24);
nl_live_tail nl_v_75;
{ const nl_domain *nl_b_13_25 = &nl_b_2_7;
(void)nl_b_13_25;
const nl_node * nl_v_76 = nl_b_2_9;
const nl_domain * nl_v_77 = nl_b_13_25;
nl_node * nl_v_78 = (nl_node *)nl_v_76;
NL_HEAP_ROOT(nl_v_78,nl_v_77->token,1,8,11,5);
(void)nl_v_77;
nl_node * nl_b_13_26 = nl_v_78;
(void)nl_b_13_26;
NL_NODE_BIND(13, 26, 4, &nl_b_13_26);
nl_node * nl_v_79 = nl_b_13_26;
nl_node_option * nl_v_80 = &nl_v_79->f0;
NL_HEAP_FIELD(nl_v_79,nl_v_80,1,11,0,12,12,5);
const nl_node * nl_v_81 = nl_b_6_17;
nl_allocation nl_v_82 = nl_b_6_13;
nl_b_6_13 = (nl_allocation){0};
nl_domain nl_v_83 = nl_b_6_15;
nl_b_6_15 = (nl_domain){0};
NL_LIVE_SEND(nl_v_81,nl_v_82.handle,nl_v_83.token,&nl_b_6_13,&nl_b_6_15);
nl_live_tail nl_v_91 = nl_producer_11(nl_v_80,nl_v_81,nl_v_82,nl_v_83);
NL_LIVE_RECEIVE(nl_v_91,&nl_b_6_13,&nl_b_6_15);
nl_v_75 = nl_v_91;
NL_HEAP_SCOPE_END(5);
}
const nl_node * nl_b_6_32 = nl_v_75.ptr;
(void)nl_b_6_32;
nl_allocation nl_b_6_33 = nl_v_75.allocation;
(void)nl_b_6_33;
nl_domain nl_b_6_34 = nl_v_75.domain;
(void)nl_b_6_34;
nl_v_75 = (nl_live_tail){0};
const nl_node * nl_v_92 = nl_b_6_32;
nl_allocation nl_v_93 = nl_b_6_33;
nl_b_6_33 = (nl_allocation){0};
nl_domain nl_v_94 = nl_b_6_34;
nl_b_6_34 = (nl_domain){0};
NL_HEAP_HANDOFF(nl_v_92,nl_v_93.handle,nl_v_94.token,&nl_b_6_33,&nl_b_6_34);
nl_owner_10(nl_v_92,nl_v_93,nl_v_94);
NL_HEAP_RETURNED(&nl_b_6_33,&nl_b_6_34);
nl_slot nl_v_106;
{ const nl_domain *nl_b_18_43 = &nl_b_2_7;
(void)nl_b_18_43;
const nl_node * nl_v_107 = nl_b_2_9;
NL_HEAP_END(nl_v_107,nl_b_18_43->token);
nl_slot nl_v_108 = {(unsigned char *)nl_v_107,24};
nl_v_106 = nl_v_108;
}
nl_slot nl_b_6_44 = nl_v_106;
(void)nl_b_6_44;
NL_NODE_BIND(6, 44, 4, &nl_b_6_44);
nl_slot nl_v_109 = nl_b_6_44;
nl_b_6_44 = (nl_slot){0};
nl_storage nl_v_110 = {nl_v_109.bytes,nl_v_109.length};
NL_HEAP_RAW(nl_v_110.bytes,nl_v_110.length);
nl_storage nl_b_6_45 = nl_v_110;
(void)nl_b_6_45;
NL_NODE_BIND(6, 45, 4, &nl_b_6_45);
nl_domain nl_v_111 = nl_b_2_7;
nl_b_2_7 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_111.token);
(void)nl_v_111;
nl_allocation nl_v_112 = nl_b_2_5;
nl_b_2_5 = (nl_allocation){0};
nl_storage nl_v_113 = nl_b_6_45;
nl_b_6_45 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_112.handle,nl_v_113.bytes,nl_v_113.length);
free(nl_v_112.handle);
nl_v_112.handle=NULL;
nl_v_113.bytes=NULL;
(void)nl_v_113;
uint8_t nl_v_114 = nl_b_6_24;
nl_v_19 = nl_v_114;
}
nl_v_4 = nl_v_19;
}
uint8_t nl_b_0_2 = nl_v_4;
(void)nl_b_0_2;
NL_NODE_BIND(0, 2, 4, &nl_b_0_2);
uint8_t nl_v_115 = nl_b_0_2;
uint8_t nl_b_0_3 = nl_v_115;
(void)nl_b_0_3;
NL_NODE_BIND(0, 3, 4, &nl_b_0_3);
uint8_t nl_v_116 = nl_b_0_3;
uint8_t nl_v_117 = nl_b_0_1.f1;
nl_b_0_1.f1=nl_v_116;
NL_MIXED_COPY_STORE(&nl_b_0_1.f1,nl_v_117,nl_v_116);
uint8_t nl_b_0_5 = nl_v_117;
(void)nl_b_0_5;
NL_NODE_BIND(0, 5, 4, &nl_b_0_5);
uint8_t nl_v_118=nl_b_0_1.f1;
uint8_t nl_b_0_6 = nl_v_118;
(void)nl_b_0_6;
NL_NODE_BIND(0, 6, 4, &nl_b_0_6);
uint8_t nl_v_119=nl_b_0_1.f0;
uint8_t nl_b_0_7 = nl_v_119;
(void)nl_b_0_7;
NL_NODE_BIND(0, 7, 4, &nl_b_0_7);
uint8_t nl_v_120 = nl_b_0_5;
uint8_t nl_b_0_8 = nl_v_120;
(void)nl_b_0_8;
NL_NODE_BIND(0, 8, 4, &nl_b_0_8);
NL_HEAP_FINISH();
return 0;
}
