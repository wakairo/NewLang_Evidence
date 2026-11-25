#ifndef COMPARE_EXCHANGE_H
#define COMPARE_EXCHANGE_H

#include <stdint.h>

typedef struct {
    uint8_t class_tag;
    uint8_t coalescing;
} ReceiveDescriptor;

uint8_t exchange(uint8_t *slot, uint8_t mode);

#endif
