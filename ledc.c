#include <stdio.h>
#include "driver/ledc.h"


#define MOTO_GPIO_1 2
// #define MOTO_GPIO_1 2
// #define AIN1 13
// #define AIN2 12
// #define I2C_MASTER_TIMEOUT_MS 1000


void Timer_Init(){
    ledc_timer_config_t Ledc_Timer = {
        .duty_resolution = LEDC_TIMER_13_BIT,
        .freq_hz = 1000,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0
    };

    ledc_timer_config(&Ledc_Timer);

    ledc_channel_config_t ledc_channel = { 
	.channel =	0,	// LED控制器通道号, 
	.duty = 0, 
	.gpio_num = 2,				// LED控制器通道对应GPIO, 
	.speed_mode = LEDC_LOW_SPEED_MODE, // 模式, 
	.timer_sel = LEDC_TIMER_0,   		// 使用哪个定时器0-3
    };
    // 配置LED控制器
    ledc_channel_config(&ledc_channel);

}

void app_main(void)
{
    Timer_Init();
    ledc_fade_func_install(0);
    printf("fade has installed\n");
    while(1){
        ledc_set_fade_with_time(LEDC_LOW_SPEED_MODE, 0, 5000, 1500);
        ledc_fade_start(LEDC_LOW_SPEED_MODE, 0, LEDC_FADE_WAIT_DONE);
        ledc_set_fade_with_time(LEDC_LOW_SPEED_MODE, 0, 0, 1500);
        ledc_fade_start(LEDC_LOW_SPEED_MODE, 0, LEDC_FADE_WAIT_DONE);
    }
    
}
