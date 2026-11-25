#include "exchange.h"

uint8_t install_mode(uint8_t *slot, uint8_t mode)
{
    const uint8_t displaced = *slot;
    *slot = mode;
    return displaced;
}
