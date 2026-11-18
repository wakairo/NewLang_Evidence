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
static void nl_owner_10(const nl_node *nl_b_9_28,nl_allocation nl_b_9_29,nl_domain nl_b_9_30) {
NL_HEAP_RECEIVER_ENTER(nl_b_9_28,nl_b_9_29.handle,nl_b_9_30.token,9,28,29,30,&nl_b_9_29,&nl_b_9_30);
nl_slot nl_v_52;
{ const nl_domain *nl_b_10_31 = &nl_b_9_30;
(void)nl_b_10_31;
const nl_node * nl_v_53 = nl_b_9_28;
NL_HEAP_END(nl_v_53,nl_b_10_31->token);
nl_slot nl_v_54 = {(unsigned char *)nl_v_53,24};
nl_v_52 = nl_v_54;
}
nl_slot nl_b_9_32 = nl_v_52;
(void)nl_b_9_32;
NL_NODE_BIND(9, 32, 4, &nl_b_9_32);
nl_slot nl_v_55 = nl_b_9_32;
nl_b_9_32 = (nl_slot){0};
nl_storage nl_v_56 = {nl_v_55.bytes,nl_v_55.length};
NL_HEAP_RAW(nl_v_56.bytes,nl_v_56.length);
nl_storage nl_b_9_33 = nl_v_56;
(void)nl_b_9_33;
NL_NODE_BIND(9, 33, 4, &nl_b_9_33);
nl_domain nl_v_57 = nl_b_9_30;
nl_b_9_30 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_57.token);
(void)nl_v_57;
nl_allocation nl_v_58 = nl_b_9_29;
nl_b_9_29 = (nl_allocation){0};
nl_storage nl_v_59 = nl_b_9_33;
nl_b_9_33 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_58.handle,nl_v_59.bytes,nl_v_59.length);
free(nl_v_58.handle);
nl_v_58.handle=NULL;
nl_v_59.bytes=NULL;
(void)nl_v_59;
NL_HEAP_RECEIVER_EXIT();
}
int main(void) {
uint8_t nl_v_1 = 83;
uint8_t nl_v_2 = 27;
nl_copy_record nl_v_3 = {nl_v_1,nl_v_2};
nl_copy_record nl_b_0_1 = nl_v_3;
NL_MIXED_COPY_BIND(0,1,&nl_b_0_1.f0,&nl_b_0_1.f1);
uint8_t nl_v_4 = 0;
uint8_t nl_v_5 = nl_copy_state_12(&nl_b_0_1.f0,nl_v_4);
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
uint8_t nl_v_17 = 83;
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
uint8_t nl_v_42;
{ const nl_domain *nl_b_8_25 = &nl_b_6_22;
(void)nl_b_8_25;
const nl_node * nl_v_43 = nl_b_6_24;
const nl_domain * nl_v_44 = nl_b_8_25;
const nl_node * nl_v_45 = nl_v_43;
NL_HEAP_ROOT(nl_v_45,nl_v_44->token,0,26,29,4);
(void)nl_v_44;
const nl_node * nl_b_8_26 = nl_v_45;
(void)nl_b_8_26;
NL_NODE_BIND(8, 26, 4, &nl_b_8_26);
const nl_node * nl_v_46 = nl_b_8_26;
const uint8_t * nl_v_47 = &nl_v_46->f1;
NL_HEAP_FIELD(nl_v_46,nl_v_47,0,11,1,31,31,4);
uint8_t nl_v_48 = *nl_v_47;
nl_v_42 = nl_v_48;
NL_HEAP_SCOPE_END(4);
}
uint8_t nl_b_6_27 = nl_v_42;
(void)nl_b_6_27;
NL_NODE_BIND(6, 27, 4, &nl_b_6_27);
const nl_node * nl_v_49 = nl_b_6_24;
nl_allocation nl_v_50 = nl_b_6_20;
nl_b_6_20 = (nl_allocation){0};
nl_domain nl_v_51 = nl_b_6_22;
nl_b_6_22 = (nl_domain){0};
NL_HEAP_HANDOFF(nl_v_49,nl_v_50.handle,nl_v_51.token,&nl_b_6_20,&nl_b_6_22);
nl_owner_10(nl_v_49,nl_v_50,nl_v_51);
NL_HEAP_RETURNED(&nl_b_6_20,&nl_b_6_22);
nl_slot nl_v_60;
{ const nl_domain *nl_b_11_34 = &nl_b_2_14;
(void)nl_b_11_34;
const nl_node * nl_v_61 = nl_b_2_16;
NL_HEAP_END(nl_v_61,nl_b_11_34->token);
nl_slot nl_v_62 = {(unsigned char *)nl_v_61,24};
nl_v_60 = nl_v_62;
}
nl_slot nl_b_6_35 = nl_v_60;
(void)nl_b_6_35;
NL_NODE_BIND(6, 35, 4, &nl_b_6_35);
nl_slot nl_v_63 = nl_b_6_35;
nl_b_6_35 = (nl_slot){0};
nl_storage nl_v_64 = {nl_v_63.bytes,nl_v_63.length};
NL_HEAP_RAW(nl_v_64.bytes,nl_v_64.length);
nl_storage nl_b_6_36 = nl_v_64;
(void)nl_b_6_36;
NL_NODE_BIND(6, 36, 4, &nl_b_6_36);
nl_domain nl_v_65 = nl_b_2_14;
nl_b_2_14 = (nl_domain){0};
NL_HEAP_FINALIZE(nl_v_65.token);
(void)nl_v_65;
nl_allocation nl_v_66 = nl_b_2_12;
nl_b_2_12 = (nl_allocation){0};
nl_storage nl_v_67 = nl_b_6_36;
nl_b_6_36 = (nl_storage){0};
NL_HEAP_RELEASE(nl_v_66.handle,nl_v_67.bytes,nl_v_67.length);
free(nl_v_66.handle);
nl_v_66.handle=NULL;
nl_v_67.bytes=NULL;
(void)nl_v_67;
uint8_t nl_v_68 = nl_b_6_27;
uint8_t nl_v_69 = nl_copy_state_12(&nl_b_0_1.f0,nl_v_68);
uint8_t nl_b_6_41 = nl_v_69;
(void)nl_b_6_41;
NL_NODE_BIND(6, 41, 4, &nl_b_6_41);
uint8_t nl_v_70 = nl_b_6_41;
uint8_t nl_b_6_42 = nl_v_70;
(void)nl_b_6_42;
NL_NODE_BIND(6, 42, 4, &nl_b_6_42);
}
}
uint8_t nl_v_71 = nl_b_0_6;
uint8_t nl_b_0_9 = nl_v_71;
(void)nl_b_0_9;
NL_NODE_BIND(0, 9, 4, &nl_b_0_9);
uint8_t nl_v_72=nl_b_0_1.f0;
uint8_t nl_b_0_10 = nl_v_72;
(void)nl_b_0_10;
NL_NODE_BIND(0, 10, 4, &nl_b_0_10);
uint8_t nl_v_73=nl_b_0_1.f1;
uint8_t nl_b_0_11 = nl_v_73;
(void)nl_b_0_11;
NL_NODE_BIND(0, 11, 4, &nl_b_0_11);
NL_HEAP_FINISH();
return 0;
}
