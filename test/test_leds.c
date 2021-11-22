#include "unity.h"
#include "leds.h"
/* TP3: TDD */

/*
 * --->         Obligatorias                  <---
 * Prender todos los led juntosx
 * Apagar todos los leds juntosx
 * Consultar el estado de un led apagado
 * Consultar el estado de un led encendido
 * --->         Opcionales                  <---
 * Revisar los valores limites de los parametros
 * Probar valores invalidos para los parametros
*/

#define LED 3
#define LED_BIT(x) (1 << (x - 1))
#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON 0xFFFF
#define LEDS_ON 1
#define LEDS_OFF 0

static uint16_t puertoVirtual;

/* Bloque de Set up */
void setUp(void)
{
    LedsCreate(&puertoVirtual);
}

/* Despues de la configuracion todos los leds deben quedar apagados */
void test_todos_los_leds_iniciar_apagados(void)
{
    uint16_t puertoVirtual = LEDS_ALL_ON;
    LedsCreate(&puertoVirtual);
    TEST_ASSERT_EQUAL_HEX16(LEDS_ALL_OFF, puertoVirtual);
}

/* Prender un led cualquiera */
/*
    1 Inicializo siempre los puertos
    2 Enciendo el led deseado
*/
void test_prender_un_led(void)
{
    LedsOn(LED);
    TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED), puertoVirtual);
}

/* Prender un led cualquiera */
void test_apagar_un_led(void)
{
    LedsOn(LED);
    LedsOff(LED);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual);
}

/* Prender y apagar algunos leds */
void test_prender_y_apagar_varios_leds(void)
{
    LedsOn(LED);
    LedsOn(LED + 3);
    LedsOff(LED);
    LedsOn(LED + 5);
    TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED + 3) + LED_BIT(LED + 5), puertoVirtual);
}

/* Prender todos los led juntos */
void test_prender_todos_los_leds_juntos(void)
{
    LedsOnAll();
    TEST_ASSERT_EQUAL_HEX16(LEDS_ALL_ON, puertoVirtual);
}

/* Apagar todos los led juntos */
void test_apagar_todos_los_leds_juntos(void)
{
    LedsOnAll();
    LedsOffAll();
    TEST_ASSERT_EQUAL_HEX16(LEDS_ALL_OFF, puertoVirtual);
}

/* Consultar el estado de un led encendido */
void test_consultar_estado_de_un_led(void)
{
    bool LedsStatus = false;

    /* Consulta estado de led encendido */
    LedsOn(LED);
    LedsStatus = LedsCheckStatus(LED);
    TEST_ASSERT_EQUAL(LEDS_ON, LedsStatus);

    /* Consulta estado de led apagado */
    LedsOff(LED);
    LedsStatus = LedsCheckStatus(LED);
    TEST_ASSERT_EQUAL(LEDS_OFF, LedsStatus);
}