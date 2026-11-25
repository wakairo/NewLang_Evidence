#ifndef P1786_EXCHANGE_H
#define P1786_EXCHANGE_H

#include <stdint.h>

/* The caller supplies a live writable field for the duration of this call. */
uint8_t install_mode(uint8_t *slot, uint8_t mode);

#endif
