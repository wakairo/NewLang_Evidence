#include "queue_writer.h"

size_t bounded_bytes(size_t blocks)
{
    return blocks < 1024u ? blocks * 64u : 0u;
}

uint8_t select_mode(size_t bytes)
{
    return bytes < 4096u ? 35u : 93u;
}

uint8_t install(uint8_t *slot, uint8_t mode)
{
    const uint8_t old = *slot;
    *slot = mode;
    return old;
}
