#include <stdint.h>
#include <stdbool.h>

void LedsCreate(uint16_t *direccion);

void LedsOn (uint16_t led);

void LedsOff(uint16_t led);

void LedsOnAll(void);

void LedsOffAll(void);

bool LedsCheckStatus(uint16_t led);