#ifndef P1806_QUEUE_WRITER_H
#define P1806_QUEUE_WRITER_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t reserve_mode;
    uint8_t normal_mode;
} PollDescriptor;

size_t bounded_bytes(size_t blocks);
uint8_t select_mode(size_t bytes);
uint8_t install(uint8_t *slot, uint8_t mode);

#endif
