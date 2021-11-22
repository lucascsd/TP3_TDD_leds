#include "leds.h"

#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON 0xFFFF
#define LEDS_OFFSET 1
#define LEDS_ON_SET 1
#define LEDS_START 1
#define LEDS_END 16

static uint16_t *puerto;

uint16_t LedToMask(uint16_t led)
{
    return (LEDS_ON_SET << (led - LEDS_OFFSET));
}

void LedsCreate(uint16_t *direccion)
{
    puerto = direccion;
    *puerto = LEDS_ALL_OFF;
}

void LedsOn(uint16_t led)
{
    *puerto |= LedToMask(led);
}

void LedsOff(uint16_t led)
{
    *puerto &= ~LedToMask(led);
}

void LedsOnAll(void)
{
    *puerto = LEDS_ALL_ON;
}

void LedsOffAll(void)
{
    *puerto = LEDS_ALL_OFF;
}

bool LedsCheckStatus(uint16_t led)
{
    uint16_t ledsUnderTest;

    if ((led >= LEDS_START) && (led <= LEDS_END))
    {
        ledsUnderTest = *puerto & LedToMask(led);

        return (ledsUnderTest >> (led - LEDS_OFFSET));
    }
    else
    {
        return false;
    }
}