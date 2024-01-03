#include <stdio.h>
#include "driver/mcpwm_prelude.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"

void Mcpwm_Init(){
    mcpwm_timer_config_t Timer_Config = {
        .group_id = 0,
        .clk_src = 0,
        .resolution_hz = 1000,
        .count_mode = MCPWM_TIMER_COUNT_MODE_UP,
        .period_ticks = 200,
        .intr_priority = 0,      
    };

    mcpwm_timer_handle_t Timer_Handle_Config = 0;
    mcpwm_new_timer(&Timer_Config, &Timer_Handle_Config);

    mcpwm_operator_config_t Operator_Config = {
        .group_id = 0,
        .intr_priority = 0,
    };

    mcpwm_new_operator(&Operator_Config, &Timer_Handle_Config);

    mcpwm_generator_config_t Generator_Config = {
        .gen_gpio_num = 2,
    };

    mcpwm_new_generator(Operator_Config, &Generator_Config);
}

void app_main(void)
{
    Mcpwm_Init();
}
