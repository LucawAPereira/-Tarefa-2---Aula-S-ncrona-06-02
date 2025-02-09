#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define servo 22
#define PWM_LED 12  // led blue
#define wrap 62500  // max 16 bits = 65536
#define div 40      // max 255 (0 a 255)

bool ciclo = true;

int main()
{
    stdio_init_all();
    gpio_set_function(servo, GPIO_FUNC_PWM); // habilita o pino da gpio como pwm
    gpio_set_function(PWM_LED, GPIO_FUNC_PWM); // habilita o pino da gpio como pwm

    uint slice = pwm_gpio_to_slice_num(servo); // obter o canal (slice) PWM  da gpio
    uint slice_led = pwm_gpio_to_slice_num(PWM_LED); // referente ao item 6)

    pwm_set_clkdiv(slice, div); // define o divisor de clock do PWM ('di')
    pwm_set_wrap(slice, wrap); // definir o valor de wrap, valor maximo do contador pwm (define o periodo do pwm)
    pwm_set_enabled(slice, true); // habilitar o pwm no slice correspondente

    pwm_set_clkdiv(slice_led, div); // define o divisor de clock do PWM ('di'); referente ao item 6)
    pwm_set_wrap(slice_led, wrap); // definir o valor de wrap, valor maximo do contador pwm (define o periodo do pwm); referente ao item 6)
    pwm_set_enabled(slice_led, true); // habilitar o pwm no slice correspondente; referente ao item 6)

    while (true) {

        if (ciclo)
        {
            pwm_set_gpio_level(servo, 7500); // definir o ciclo de trabalho (duty cycle) do pwm para 0.12 --> 7500/62500 --> 0.12
            pwm_set_gpio_level(PWM_LED, 7500); // referente ao item 6)
            sleep_ms(5000);
            pwm_set_gpio_level(servo, 4593); // ajusta para proximo de 90 graus  4593/62500 --> 0.0735
            pwm_set_gpio_level(PWM_LED, 4593); // referente ao item 6)
            sleep_ms(5000);
            pwm_set_gpio_level(servo, 1562); // ajusta para proximo de 0 graus   1562/62500 --> 0.025
            pwm_set_gpio_level(PWM_LED, 1562); // referente ao item 6)
            sleep_ms(5000);
            ciclo = false;
        } 

        for (int i=1562; i<=7500; i+=16) // 16 wrap equivalente a +-5us para este caso, 62500wap-->20ms, logo 5us equivale a 16 wrap, conta necessaria para a suavizacao do servo
        {
            pwm_set_gpio_level(servo, i); // incrementa
            pwm_set_gpio_level(PWM_LED, i); // referente ao item 6)
            sleep_ms(10);
        }
        for (int i=7500; i>=1562; i-=16)
        {
            pwm_set_gpio_level(servo, i); // decrementa 
            pwm_set_gpio_level(PWM_LED, i); // referente ao item 6)
            sleep_ms(10);
        }
    sleep_ms(1);
    }
}
