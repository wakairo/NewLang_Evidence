#include "exchange.h"

uint8_t exchange(uint8_t *slot, uint8_t mode)
{
    const uint8_t old = *slot;
    *slot = mode;
    return old;
}
