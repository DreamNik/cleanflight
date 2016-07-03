extern "C"{
	#include <platform.h>
	#include <drivers/light_led.h>
	
	led_config_t led_config[3];
}



void ledInit( bool alternative_led ){
	led_config[0].gpio = nullptr;
	led_config[0].pin  = 10;
	
	led_config[1].gpio = nullptr;
	led_config[1].pin  = 11;
	
	led_config[2].gpio = nullptr;
	led_config[2].pin  = 12;
	
	//LED0_OFF;
	//LED1_OFF;
	LED2_OFF;

}

