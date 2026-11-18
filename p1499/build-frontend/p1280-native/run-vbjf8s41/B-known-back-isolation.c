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
static uint8_t nl_copy_state_13(uint8_t *target,uint8_t next){uint8_t old=*target;*target=next;NL_MIXED_COPY_CALL(target,old,next);return old;}
static void nl_owner_12(const nl_node *nl_b_13_46,nl_allocation nl_b_13_47,nl_domain nl_b_13_48) {
NL_HEAP_RECEIVER_ENTER(nl_b_13_46,nl_b_13_47.handle,nl_b_13_48.token,13,46,47,48,&nl_b_13_47,&nl_b_13_48);
{ const nl_domain *nl_b_14_49 = &nl_b_13_48;
(void)nl_b_14_49;
const nl_node * nl_v_87 = nl_b_13_46;
const nl_domain * nl_v_88 = nl_b_14_49;
const nl_node * nl_v_89 = nl_v_87;
NL_HEAP_ROOT(nl_v_89,nl_v_88->token,0,16,19,8);
(void)nl_v_88;
const nl_node * nl_b_14_50 = nl_v_89;
(void)nl_b_14_50;
NL_NODE_BIND(14, 50, 4, &nl_b_14_50);
NL_HEAP_SCOPE_END(8);
}
nl_slot nl_v_90;
{ const nl_domain *nl_b_15_51 = &nl_b_13_48;
(void)nl_b_15_51;
const nl_node * nl_v_91 = nl_b_13_46;
NL_HEAP_END(nl_v_91,nl_b_15_51->token);
nl_slot nl_v_92 = {(unsigned char *)nl_v_91,24};
nl_v_90 = nl_v_92;
}
nl_slot nl_b_13_52 = nl_v_90;
(void)nl_b_13_52;
NL_NODE_BIND(13, 52, 4, &nl_b_13_52);
nl_slot nl_v_93 = nl_b_13_52;
nl_b_13_52 = (nl_slot){0};
nl_storage nl_v_94 = {nl_v_93.bytes,nl_v_93.length};
NL_HEAP_RAW(nl_v_94.bytes,nl_v_94.length);
nl_storage nl_b_13_53 = nl_v_94;
(void)nl_b_13_53;
NL_NODE_BIND(13, 53, 4, &nl_b_13_53);
nl_domain nl_v_95 = nl_b_13_48;
nl_b_13_48 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_95.token);
(void)nl_v_95;
nl_allocation nl_v_96 = nl_b_13_47;
nl_b_13_47 = (nl_allocation){0};
nl_storage nl_v_97 = nl_b_13_53;
nl_b_13_53 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_96.handle,nl_v_97.bytes,nl_v_97.length);
free(nl_v_96.handle);
nl_v_96.handle=NULL;
nl_v_97.bytes=NULL;
(void)nl_v_97;
NL_HEAP_RECEIVER_EXIT();
}
static nl_live_tail nl_producer_10(nl_node_option * nl_b_12_38,const nl_node * nl_b_12_39,nl_allocation nl_b_12_40,nl_domain nl_b_12_41) {
NL_LIVE_ENTER(nl_b_12_38,nl_b_12_39,nl_b_12_40.handle,nl_b_12_41.token);
nl_node_option * nl_v_76 = nl_b_12_38;
nl_node_option nl_v_77 = { 0, NULL };
nl_node_option nl_v_78 = *nl_v_76;
*nl_v_76 = nl_v_77;
NL_HEAP_CHANGE(nl_v_76,&nl_v_78,2);
(void)nl_v_78;
const nl_node * nl_v_79 = nl_b_12_39;
nl_allocation nl_v_80 = nl_b_12_40;
nl_b_12_40 = (nl_allocation){0};
nl_domain nl_v_81 = nl_b_12_41;
nl_b_12_41 = (nl_domain){0};
nl_live_tail nl_v_82 = {nl_v_79,nl_v_80,nl_v_81};
NL_LIVE_RETURN(nl_v_82);
return nl_v_82;
}
int main(void) {
void *nl_heap_1 = malloc(24);
NL_HEAP_TRIAL(nl_heap_1,24,8);
if (nl_heap_1 == NULL) {
NL_HEAP_ARM(1);
}
if (nl_heap_1 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_2_1 = { {nl_heap_1}, {(unsigned char *)nl_heap_1,24} };
nl_backing nl_v_2 = nl_b_2_1;
nl_b_2_1 = (nl_backing){0};
nl_allocation nl_b_2_2 = nl_v_2.allocation;
(void)nl_b_2_2;
nl_storage nl_b_2_3 = nl_v_2.raw;
(void)nl_b_2_3;
nl_v_2 = (nl_backing){0};
nl_allocation nl_v_3 = nl_b_2_2;
nl_b_2_2 = (nl_allocation){0};
nl_allocation nl_b_2_4 = nl_v_3;
(void)nl_b_2_4;
NL_NODE_BIND(2, 4, 4, &nl_b_2_4);
nl_storage nl_v_4 = nl_b_2_3;
nl_b_2_3 = (nl_storage){0};
nl_slot nl_v_5 = {nl_v_4.bytes,nl_v_4.length};
NL_HEAP_SLOT(nl_v_5.bytes,nl_v_5.length);
nl_slot nl_b_2_5 = nl_v_5;
(void)nl_b_2_5;
NL_NODE_BIND(2, 5, 4, &nl_b_2_5);
nl_domain nl_v_6 = {1};
NL_HEAP_DOMAIN(nl_v_6.token);
nl_domain nl_b_2_6 = nl_v_6;
(void)nl_b_2_6;
NL_NODE_BIND(2, 6, 4, &nl_b_2_6);
const nl_node * nl_v_7;
{ const nl_domain *nl_b_3_7 = &nl_b_2_6;
(void)nl_b_3_7;
nl_slot nl_v_8 = nl_b_2_5;
nl_b_2_5 = (nl_slot){0};
nl_node_option nl_v_9 = { 0, NULL };
uint8_t nl_v_10 = 231;
nl_node nl_v_11 = { nl_v_9, nl_v_10 };
const nl_domain * nl_v_12 = nl_b_3_7;
*(nl_node *)nl_v_8.bytes = nl_v_11;
const nl_node *nl_v_13 = (nl_node *)nl_v_8.bytes;
NL_HEAP_INITIALIZE(nl_v_13,nl_v_12->token);
(void)nl_v_12;
nl_v_7 = nl_v_13;
}
const nl_node * const nl_b_2_8 = nl_v_7;
(void)nl_b_2_8;
NL_NODE_BIND(2, 8, 2, &nl_b_2_8);
void *nl_heap_14 = malloc(24);
NL_HEAP_TRIAL(nl_heap_14,24,8);
if (nl_heap_14 == NULL) {
NL_HEAP_ARM(1);
nl_slot nl_v_15;
{ const nl_domain *nl_b_5_9 = &nl_b_2_6;
(void)nl_b_5_9;
const nl_node * nl_v_16 = nl_b_2_8;
NL_HEAP_END(nl_v_16,nl_b_5_9->token);
nl_slot nl_v_17 = {(unsigned char *)nl_v_16,24};
nl_v_15 = nl_v_17;
}
nl_slot nl_b_4_10 = nl_v_15;
(void)nl_b_4_10;
NL_NODE_BIND(4, 10, 4, &nl_b_4_10);
nl_slot nl_v_18 = nl_b_4_10;
nl_b_4_10 = (nl_slot){0};
nl_storage nl_v_19 = {nl_v_18.bytes,nl_v_18.length};
NL_HEAP_RAW(nl_v_19.bytes,nl_v_19.length);
nl_storage nl_b_4_11 = nl_v_19;
(void)nl_b_4_11;
NL_NODE_BIND(4, 11, 4, &nl_b_4_11);
nl_domain nl_v_20 = nl_b_2_6;
nl_b_2_6 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_20.token);
(void)nl_v_20;
nl_allocation nl_v_21 = nl_b_2_4;
nl_b_2_4 = (nl_allocation){0};
nl_storage nl_v_22 = nl_b_4_11;
nl_b_4_11 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_21.handle,nl_v_22.bytes,nl_v_22.length);
free(nl_v_21.handle);
nl_v_21.handle=NULL;
nl_v_22.bytes=NULL;
(void)nl_v_22;
}
if (nl_heap_14 != NULL) {
NL_HEAP_ARM(2);
nl_backing nl_b_6_9 = { {nl_heap_14}, {(unsigned char *)nl_heap_14,24} };
nl_backing nl_v_23 = nl_b_6_9;
nl_b_6_9 = (nl_backing){0};
nl_allocation nl_b_6_10 = nl_v_23.allocation;
(void)nl_b_6_10;
nl_storage nl_b_6_11 = nl_v_23.raw;
(void)nl_b_6_11;
nl_v_23 = (nl_backing){0};
nl_allocation nl_v_24 = nl_b_6_10;
nl_b_6_10 = (nl_allocation){0};
nl_allocation nl_b_6_12 = nl_v_24;
(void)nl_b_6_12;
NL_NODE_BIND(6, 12, 4, &nl_b_6_12);
nl_storage nl_v_25 = nl_b_6_11;
nl_b_6_11 = (nl_storage){0};
nl_slot nl_v_26 = {nl_v_25.bytes,nl_v_25.length};
NL_HEAP_SLOT(nl_v_26.bytes,nl_v_26.length);
nl_slot nl_b_6_13 = nl_v_26;
(void)nl_b_6_13;
NL_NODE_BIND(6, 13, 4, &nl_b_6_13);
nl_domain nl_v_27 = {2};
NL_HEAP_DOMAIN(nl_v_27.token);
nl_domain nl_b_6_14 = nl_v_27;
(void)nl_b_6_14;
NL_NODE_BIND(6, 14, 4, &nl_b_6_14);
const nl_node * nl_v_28;
{ const nl_domain *nl_b_7_15 = &nl_b_6_14;
(void)nl_b_7_15;
nl_slot nl_v_29 = nl_b_6_13;
nl_b_6_13 = (nl_slot){0};
nl_node_option nl_v_30 = { 0, NULL };
uint8_t nl_v_31 = 167;
nl_node nl_v_32 = { nl_v_30, nl_v_31 };
const nl_domain * nl_v_33 = nl_b_7_15;
*(nl_node *)nl_v_29.bytes = nl_v_32;
const nl_node *nl_v_34 = (nl_node *)nl_v_29.bytes;
NL_HEAP_INITIALIZE(nl_v_34,nl_v_33->token);
(void)nl_v_33;
nl_v_28 = nl_v_34;
}
const nl_node * const nl_b_6_16 = nl_v_28;
(void)nl_b_6_16;
NL_NODE_BIND(6, 16, 2, &nl_b_6_16);
nl_node_option nl_v_35;
{ const nl_domain *nl_b_8_17 = &nl_b_2_6;
(void)nl_b_8_17;
const nl_node * nl_v_36 = nl_b_2_8;
const nl_domain * nl_v_37 = nl_b_8_17;
nl_node * nl_v_38 = (nl_node *)nl_v_36;
NL_HEAP_ROOT(nl_v_38,nl_v_37->token,1,5,8,3);
(void)nl_v_37;
nl_node * nl_b_8_18 = nl_v_38;
(void)nl_b_8_18;
NL_NODE_BIND(8, 18, 4, &nl_b_8_18);
nl_node * nl_v_39 = nl_b_8_18;
nl_node_option * nl_v_40 = &nl_v_39->f0;
NL_HEAP_FIELD(nl_v_39,nl_v_40,1,11,0,9,9,3);
const nl_node * nl_v_41 = nl_b_6_16;
nl_node_option nl_v_42 = { 1, nl_v_41 };
nl_node_option nl_v_43 = *nl_v_40;
*nl_v_40 = nl_v_42;
NL_HEAP_CHANGE(nl_v_40,&nl_v_43,1);
nl_v_35 = nl_v_43;
NL_HEAP_SCOPE_END(3);
}
nl_node_option nl_b_6_19 = nl_v_35;
(void)nl_b_6_19;
NL_NODE_BIND(6, 19, 3, &nl_b_6_19);
nl_node_option nl_v_44;
{ const nl_domain *nl_b_9_20 = &nl_b_2_6;
(void)nl_b_9_20;
const nl_node * nl_v_45 = nl_b_2_8;
const nl_domain * nl_v_46 = nl_b_9_20;
const nl_node * nl_v_47 = nl_v_45;
NL_HEAP_ROOT(nl_v_47,nl_v_46->token,0,5,8,4);
(void)nl_v_46;
const nl_node * nl_b_9_21 = nl_v_47;
(void)nl_b_9_21;
NL_NODE_BIND(9, 21, 4, &nl_b_9_21);
const nl_node * nl_v_48 = nl_b_9_21;
const nl_node_option * nl_v_49 = &nl_v_48->f0;
NL_HEAP_FIELD(nl_v_48,nl_v_49,0,11,0,9,9,4);
nl_node_option nl_v_50 = *nl_v_49;
NL_HEAP_COPY(nl_v_49,&nl_v_50);
nl_v_44 = nl_v_50;
NL_HEAP_SCOPE_END(4);
}
nl_node_option nl_b_6_22 = nl_v_44;
(void)nl_b_6_22;
NL_NODE_BIND(6, 22, 3, &nl_b_6_22);
uint8_t nl_v_51;
{ const nl_domain *nl_b_10_23 = &nl_b_6_14;
(void)nl_b_10_23;
const nl_node * nl_v_52 = nl_b_6_16;
const nl_domain * nl_v_53 = nl_b_10_23;
const nl_node * nl_v_54 = nl_v_52;
NL_HEAP_ROOT(nl_v_54,nl_v_53->token,0,16,19,5);
(void)nl_v_53;
const nl_node * nl_b_10_24 = nl_v_54;
(void)nl_b_10_24;
NL_NODE_BIND(10, 24, 4, &nl_b_10_24);
const nl_node * nl_v_55 = nl_b_10_24;
const uint8_t * nl_v_56 = &nl_v_55->f1;
NL_HEAP_FIELD(nl_v_55,nl_v_56,0,11,1,21,21,5);
uint8_t nl_v_57 = *nl_v_56;
nl_v_51 = nl_v_57;
NL_HEAP_SCOPE_END(5);
}
uint8_t nl_b_6_25 = nl_v_51;
(void)nl_b_6_25;
NL_NODE_BIND(6, 25, 4, &nl_b_6_25);
uint8_t nl_v_58 = nl_b_6_25;
uint8_t nl_b_6_26 = nl_v_58;
(void)nl_b_6_26;
NL_NODE_BIND(6, 26, 4, &nl_b_6_26);
uint8_t nl_v_59 = 31;
uint8_t nl_v_60 = 127;
nl_copy_record nl_v_61 = {nl_v_59,nl_v_60};
nl_copy_record nl_b_6_27 = nl_v_61;
NL_MIXED_COPY_BIND(6,27,&nl_b_6_27.f0,&nl_b_6_27.f1);
uint8_t nl_v_62 = nl_b_6_26;
uint8_t nl_v_63 = nl_copy_state_13(&nl_b_6_27.f0,nl_v_62);
uint8_t nl_b_6_32 = nl_v_63;
(void)nl_b_6_32;
NL_NODE_BIND(6, 32, 4, &nl_b_6_32);
uint8_t nl_v_64 = nl_b_6_32;
uint8_t nl_b_6_33 = nl_v_64;
(void)nl_b_6_33;
NL_NODE_BIND(6, 33, 4, &nl_b_6_33);
uint8_t nl_v_65=nl_b_6_27.f0;
uint8_t nl_b_6_34 = nl_v_65;
(void)nl_b_6_34;
NL_NODE_BIND(6, 34, 4, &nl_b_6_34);
uint8_t nl_v_66=nl_b_6_27.f1;
uint8_t nl_b_6_35 = nl_v_66;
(void)nl_b_6_35;
NL_NODE_BIND(6, 35, 4, &nl_b_6_35);
nl_live_tail nl_v_67;
{ const nl_domain *nl_b_11_36 = &nl_b_2_6;
(void)nl_b_11_36;
const nl_node * nl_v_68 = nl_b_2_8;
const nl_domain * nl_v_69 = nl_b_11_36;
nl_node * nl_v_70 = (nl_node *)nl_v_68;
NL_HEAP_ROOT(nl_v_70,nl_v_69->token,1,5,8,7);
(void)nl_v_69;
nl_node * nl_b_11_37 = nl_v_70;
(void)nl_b_11_37;
NL_NODE_BIND(11, 37, 4, &nl_b_11_37);
nl_node * nl_v_71 = nl_b_11_37;
nl_node_option * nl_v_72 = &nl_v_71->f0;
NL_HEAP_FIELD(nl_v_71,nl_v_72,1,11,0,9,9,7);
const nl_node * nl_v_73 = nl_b_6_16;
nl_allocation nl_v_74 = nl_b_6_12;
nl_b_6_12 = (nl_allocation){0};
nl_domain nl_v_75 = nl_b_6_14;
nl_b_6_14 = (nl_domain){0};
NL_LIVE_SEND(nl_v_73,nl_v_74.handle,nl_v_75.token,&nl_b_6_12,&nl_b_6_14);
nl_live_tail nl_v_83 = nl_producer_10(nl_v_72,nl_v_73,nl_v_74,nl_v_75);
NL_LIVE_RECEIVE(nl_v_83,&nl_b_6_12,&nl_b_6_14);
nl_v_67 = nl_v_83;
NL_HEAP_SCOPE_END(7);
}
const nl_node * nl_b_6_43 = nl_v_67.ptr;
(void)nl_b_6_43;
nl_allocation nl_b_6_44 = nl_v_67.allocation;
(void)nl_b_6_44;
nl_domain nl_b_6_45 = nl_v_67.domain;
(void)nl_b_6_45;
nl_v_67 = (nl_live_tail){0};
const nl_node * nl_v_84 = nl_b_6_43;
nl_allocation nl_v_85 = nl_b_6_44;
nl_b_6_44 = (nl_allocation){0};
nl_domain nl_v_86 = nl_b_6_45;
nl_b_6_45 = (nl_domain){0};
NL_HEAP_HANDOFF(nl_v_84,nl_v_85.handle,nl_v_86.token,&nl_b_6_44,&nl_b_6_45);
nl_owner_12(nl_v_84,nl_v_85,nl_v_86);
NL_HEAP_RETURNED(&nl_b_6_44,&nl_b_6_45);
nl_slot nl_v_98;
{ const nl_domain *nl_b_16_54 = &nl_b_2_6;
(void)nl_b_16_54;
const nl_node * nl_v_99 = nl_b_2_8;
NL_HEAP_END(nl_v_99,nl_b_16_54->token);
nl_slot nl_v_100 = {(unsigned char *)nl_v_99,24};
nl_v_98 = nl_v_100;
}
nl_slot nl_b_6_55 = nl_v_98;
(void)nl_b_6_55;
NL_NODE_BIND(6, 55, 4, &nl_b_6_55);
nl_slot nl_v_101 = nl_b_6_55;
nl_b_6_55 = (nl_slot){0};
nl_storage nl_v_102 = {nl_v_101.bytes,nl_v_101.length};
NL_HEAP_RAW(nl_v_102.bytes,nl_v_102.length);
nl_storage nl_b_6_56 = nl_v_102;
(void)nl_b_6_56;
NL_NODE_BIND(6, 56, 4, &nl_b_6_56);
nl_domain nl_v_103 = nl_b_2_6;
nl_b_2_6 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_103.token);
(void)nl_v_103;
nl_allocation nl_v_104 = nl_b_2_4;
nl_b_2_4 = (nl_allocation){0};
nl_storage nl_v_105 = nl_b_6_56;
nl_b_6_56 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_104.handle,nl_v_105.bytes,nl_v_105.length);
free(nl_v_104.handle);
nl_v_104.handle=NULL;
nl_v_105.bytes=NULL;
(void)nl_v_105;
}
}
NL_HEAP_FINISH();
return 0;
}
