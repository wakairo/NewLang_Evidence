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
static void nl_owner_12(const nl_node *nl_b_13_38,nl_allocation nl_b_13_39,nl_domain nl_b_13_40) {
NL_HEAP_RECEIVER_ENTER(nl_b_13_38,nl_b_13_39.handle,nl_b_13_40.token,13,38,39,40,&nl_b_13_39,&nl_b_13_40);
{ const nl_domain *nl_b_14_41 = &nl_b_13_40;
(void)nl_b_14_41;
const nl_node * nl_v_80 = nl_b_13_38;
const nl_domain * nl_v_81 = nl_b_14_41;
const nl_node * nl_v_82 = nl_v_80;
NL_HEAP_ROOT(nl_v_82,nl_v_81->token,0,16,24,7);
(void)nl_v_81;
const nl_node * nl_b_14_42 = nl_v_82;
(void)nl_b_14_42;
NL_NODE_BIND(14, 42, 4, &nl_b_14_42);
NL_HEAP_SCOPE_END(7);
}
nl_slot nl_v_83;
{ const nl_domain *nl_b_15_43 = &nl_b_13_40;
(void)nl_b_15_43;
const nl_node * nl_v_84 = nl_b_13_38;
NL_HEAP_END(nl_v_84,nl_b_15_43->token);
nl_slot nl_v_85 = {(unsigned char *)nl_v_84,24};
nl_v_83 = nl_v_85;
}
nl_slot nl_b_13_44 = nl_v_83;
(void)nl_b_13_44;
NL_NODE_BIND(13, 44, 4, &nl_b_13_44);
nl_slot nl_v_86 = nl_b_13_44;
nl_b_13_44 = (nl_slot){0};
nl_storage nl_v_87 = {nl_v_86.bytes,nl_v_86.length};
NL_HEAP_RAW(nl_v_87.bytes,nl_v_87.length);
nl_storage nl_b_13_45 = nl_v_87;
(void)nl_b_13_45;
NL_NODE_BIND(13, 45, 4, &nl_b_13_45);
nl_domain nl_v_88 = nl_b_13_40;
nl_b_13_40 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_88.token);
(void)nl_v_88;
nl_allocation nl_v_89 = nl_b_13_39;
nl_b_13_39 = (nl_allocation){0};
nl_storage nl_v_90 = nl_b_13_45;
nl_b_13_45 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_89.handle,nl_v_90.bytes,nl_v_90.length);
free(nl_v_89.handle);
nl_v_89.handle=NULL;
nl_v_90.bytes=NULL;
(void)nl_v_90;
NL_HEAP_RECEIVER_EXIT();
}
static nl_live_tail nl_producer_10(nl_node_option * nl_b_12_30,const nl_node * nl_b_12_31,nl_allocation nl_b_12_32,nl_domain nl_b_12_33) {
NL_LIVE_ENTER(nl_b_12_30,nl_b_12_31,nl_b_12_32.handle,nl_b_12_33.token);
nl_node_option * nl_v_69 = nl_b_12_30;
nl_node_option nl_v_70 = { 0, NULL };
nl_node_option nl_v_71 = *nl_v_69;
*nl_v_69 = nl_v_70;
NL_HEAP_CHANGE(nl_v_69,&nl_v_71,2);
(void)nl_v_71;
const nl_node * nl_v_72 = nl_b_12_31;
nl_domain nl_v_73 = nl_b_12_33;
nl_b_12_33 = (nl_domain){0};
nl_allocation nl_v_74 = nl_b_12_32;
nl_b_12_32 = (nl_allocation){0};
nl_live_tail nl_v_75 = {nl_v_72,nl_v_74,nl_v_73};
NL_LIVE_RETURN(nl_v_75);
return nl_v_75;
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
uint8_t nl_v_10 = 181;
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
uint8_t nl_v_28;
{ const nl_domain *nl_b_7_15 = &nl_b_2_6;
(void)nl_b_7_15;
const nl_node * nl_v_29 = nl_b_2_8;
const nl_domain * nl_v_30 = nl_b_7_15;
const nl_node * nl_v_31 = nl_v_29;
NL_HEAP_ROOT(nl_v_31,nl_v_30->token,0,5,8,2);
(void)nl_v_30;
const nl_node * nl_b_7_16 = nl_v_31;
(void)nl_b_7_16;
NL_NODE_BIND(7, 16, 4, &nl_b_7_16);
const nl_node * nl_v_32 = nl_b_7_16;
const uint8_t * nl_v_33 = &nl_v_32->f1;
NL_HEAP_FIELD(nl_v_32,nl_v_33,0,11,1,10,10,2);
uint8_t nl_v_34 = *nl_v_33;
nl_v_28 = nl_v_34;
NL_HEAP_SCOPE_END(2);
}
uint8_t nl_b_6_17 = nl_v_28;
(void)nl_b_6_17;
NL_NODE_BIND(6, 17, 4, &nl_b_6_17);
uint8_t nl_v_35 = nl_b_6_17;
uint8_t nl_b_6_18 = nl_v_35;
(void)nl_b_6_18;
NL_NODE_BIND(6, 18, 4, &nl_b_6_18);
uint8_t nl_v_36 = nl_b_6_18;
uint8_t nl_b_6_19 = nl_v_36;
(void)nl_b_6_19;
NL_NODE_BIND(6, 19, 4, &nl_b_6_19);
const nl_node * nl_v_37;
{ const nl_domain *nl_b_8_20 = &nl_b_6_14;
(void)nl_b_8_20;
nl_slot nl_v_38 = nl_b_6_13;
nl_b_6_13 = (nl_slot){0};
nl_node_option nl_v_39 = { 0, NULL };
uint8_t nl_v_40 = nl_b_6_19;
nl_node nl_v_41 = { nl_v_39, nl_v_40 };
const nl_domain * nl_v_42 = nl_b_8_20;
*(nl_node *)nl_v_38.bytes = nl_v_41;
const nl_node *nl_v_43 = (nl_node *)nl_v_38.bytes;
NL_HEAP_INITIALIZE(nl_v_43,nl_v_42->token);
(void)nl_v_42;
nl_v_37 = nl_v_43;
}
const nl_node * const nl_b_6_21 = nl_v_37;
(void)nl_b_6_21;
NL_NODE_BIND(6, 21, 2, &nl_b_6_21);
nl_node_option nl_v_44;
{ const nl_domain *nl_b_9_22 = &nl_b_2_6;
(void)nl_b_9_22;
const nl_node * nl_v_45 = nl_b_2_8;
const nl_domain * nl_v_46 = nl_b_9_22;
nl_node * nl_v_47 = (nl_node *)nl_v_45;
NL_HEAP_ROOT(nl_v_47,nl_v_46->token,1,5,8,4);
(void)nl_v_46;
nl_node * nl_b_9_23 = nl_v_47;
(void)nl_b_9_23;
NL_NODE_BIND(9, 23, 4, &nl_b_9_23);
nl_node * nl_v_48 = nl_b_9_23;
nl_node_option * nl_v_49 = &nl_v_48->f0;
NL_HEAP_FIELD(nl_v_48,nl_v_49,1,11,0,9,9,4);
const nl_node * nl_v_50 = nl_b_6_21;
nl_node_option nl_v_51 = { 1, nl_v_50 };
nl_node_option nl_v_52 = *nl_v_49;
*nl_v_49 = nl_v_51;
NL_HEAP_CHANGE(nl_v_49,&nl_v_52,1);
nl_v_44 = nl_v_52;
NL_HEAP_SCOPE_END(4);
}
nl_node_option nl_b_6_24 = nl_v_44;
(void)nl_b_6_24;
NL_NODE_BIND(6, 24, 3, &nl_b_6_24);
nl_node_option nl_v_53;
{ const nl_domain *nl_b_10_25 = &nl_b_2_6;
(void)nl_b_10_25;
const nl_node * nl_v_54 = nl_b_2_8;
const nl_domain * nl_v_55 = nl_b_10_25;
const nl_node * nl_v_56 = nl_v_54;
NL_HEAP_ROOT(nl_v_56,nl_v_55->token,0,5,8,5);
(void)nl_v_55;
const nl_node * nl_b_10_26 = nl_v_56;
(void)nl_b_10_26;
NL_NODE_BIND(10, 26, 4, &nl_b_10_26);
const nl_node * nl_v_57 = nl_b_10_26;
const nl_node_option * nl_v_58 = &nl_v_57->f0;
NL_HEAP_FIELD(nl_v_57,nl_v_58,0,11,0,9,9,5);
nl_node_option nl_v_59 = *nl_v_58;
NL_HEAP_COPY(nl_v_58,&nl_v_59);
nl_v_53 = nl_v_59;
NL_HEAP_SCOPE_END(5);
}
nl_node_option nl_b_6_27 = nl_v_53;
(void)nl_b_6_27;
NL_NODE_BIND(6, 27, 3, &nl_b_6_27);
nl_live_tail nl_v_60;
{ const nl_domain *nl_b_11_28 = &nl_b_2_6;
(void)nl_b_11_28;
const nl_node * nl_v_61 = nl_b_2_8;
const nl_domain * nl_v_62 = nl_b_11_28;
nl_node * nl_v_63 = (nl_node *)nl_v_61;
NL_HEAP_ROOT(nl_v_63,nl_v_62->token,1,5,8,6);
(void)nl_v_62;
nl_node * nl_b_11_29 = nl_v_63;
(void)nl_b_11_29;
NL_NODE_BIND(11, 29, 4, &nl_b_11_29);
nl_node * nl_v_64 = nl_b_11_29;
nl_node_option * nl_v_65 = &nl_v_64->f0;
NL_HEAP_FIELD(nl_v_64,nl_v_65,1,11,0,9,9,6);
const nl_node * nl_v_66 = nl_b_6_21;
nl_allocation nl_v_67 = nl_b_6_12;
nl_b_6_12 = (nl_allocation){0};
nl_domain nl_v_68 = nl_b_6_14;
nl_b_6_14 = (nl_domain){0};
NL_LIVE_SEND(nl_v_66,nl_v_67.handle,nl_v_68.token,&nl_b_6_12,&nl_b_6_14);
nl_live_tail nl_v_76 = nl_producer_10(nl_v_65,nl_v_66,nl_v_67,nl_v_68);
NL_LIVE_RECEIVE(nl_v_76,&nl_b_6_12,&nl_b_6_14);
nl_v_60 = nl_v_76;
NL_HEAP_SCOPE_END(6);
}
const nl_node * nl_b_6_35 = nl_v_60.ptr;
(void)nl_b_6_35;
nl_allocation nl_b_6_36 = nl_v_60.allocation;
(void)nl_b_6_36;
nl_domain nl_b_6_37 = nl_v_60.domain;
(void)nl_b_6_37;
nl_v_60 = (nl_live_tail){0};
const nl_node * nl_v_77 = nl_b_6_35;
nl_allocation nl_v_78 = nl_b_6_36;
nl_b_6_36 = (nl_allocation){0};
nl_domain nl_v_79 = nl_b_6_37;
nl_b_6_37 = (nl_domain){0};
NL_HEAP_HANDOFF(nl_v_77,nl_v_78.handle,nl_v_79.token,&nl_b_6_36,&nl_b_6_37);
nl_owner_12(nl_v_77,nl_v_78,nl_v_79);
NL_HEAP_RETURNED(&nl_b_6_36,&nl_b_6_37);
nl_slot nl_v_91;
{ const nl_domain *nl_b_16_46 = &nl_b_2_6;
(void)nl_b_16_46;
const nl_node * nl_v_92 = nl_b_2_8;
NL_HEAP_END(nl_v_92,nl_b_16_46->token);
nl_slot nl_v_93 = {(unsigned char *)nl_v_92,24};
nl_v_91 = nl_v_93;
}
nl_slot nl_b_6_47 = nl_v_91;
(void)nl_b_6_47;
NL_NODE_BIND(6, 47, 4, &nl_b_6_47);
nl_slot nl_v_94 = nl_b_6_47;
nl_b_6_47 = (nl_slot){0};
nl_storage nl_v_95 = {nl_v_94.bytes,nl_v_94.length};
NL_HEAP_RAW(nl_v_95.bytes,nl_v_95.length);
nl_storage nl_b_6_48 = nl_v_95;
(void)nl_b_6_48;
NL_NODE_BIND(6, 48, 4, &nl_b_6_48);
nl_domain nl_v_96 = nl_b_2_6;
nl_b_2_6 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_96.token);
(void)nl_v_96;
nl_allocation nl_v_97 = nl_b_2_4;
nl_b_2_4 = (nl_allocation){0};
nl_storage nl_v_98 = nl_b_6_48;
nl_b_6_48 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_97.handle,nl_v_98.bytes,nl_v_98.length);
free(nl_v_97.handle);
nl_v_97.handle=NULL;
nl_v_98.bytes=NULL;
(void)nl_v_98;
}
}
NL_HEAP_FINISH();
return 0;
}
