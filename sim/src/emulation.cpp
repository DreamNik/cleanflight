#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

extern "C"{
	void SetSysClock(bool overclock);
	#include "platform.h"
	#include "common/color.h"
	#include "drivers/gpio.h"
	#include "drivers/system.h"
	#include "drivers/light_led.h"
	#include "drivers/timer.h"
	#include "drivers/bus_i2c.h"

	#include "drivers/sound_beeper.h"
	#include "drivers/flash_m25p16.h"
	#include "drivers/serial.h"
	#include "drivers/exti.h"

	#include "drivers/display_ug2864hsweg01.h"
	#include "drivers/light_led.h"
	#include "drivers/light_ws2811strip.h"
	#include "drivers/flash_m25p16.h"
	#include "drivers/serial.h"
	#include "drivers/dma.h"
	#include "drivers/transponder_ir.h"
}

#include "main.h"


void systemInit(){

}





void dmaInit(void){
}





void failureMode(uint8_t mode){
	exit(-1000 - mode);
}

void digitalHi( GPIO_TypeDef* p , int i ){
	UNUSED(p);
	gui_toggle_led( i - 10 , +1 );
}

void digitalLo( GPIO_TypeDef* p , int i ){
	UNUSED(p);
	gui_toggle_led( i - 10 , -1 );
}

void digitalToggle( GPIO_TypeDef* p , int i ){
	UNUSED(p);
	gui_toggle_led( i - 10 , 0 );
}




void systemBeep(bool onoff){
	UNUSED(onoff);
}


void beeperInit(beeperConfig_t *beeperConfig){
	UNUSED(beeperConfig);
}

void timerInit( ){
}

void SetSysClock( bool overclock ){
	UNUSED(overclock);
}


static int OLED_x;
static int OLED_y;
void i2c_OLED_set_xy( uint8_t col , uint8_t row ){
	OLED_x = col;
	OLED_y = row;
}

void i2c_OLED_set_line( uint8_t row ){
	OLED_x = 0;
	OLED_y = row;
}

void i2c_OLED_send_char( unsigned char ascii ){
	gui_lcd_put( OLED_x , OLED_y , ascii );
	OLED_x++;
}

void i2c_OLED_send_string( const char* string ){
	for( const char* c = string ; *c ; c++ ){
		i2c_OLED_send_char( *c );
	}
}

void i2c_OLED_clear_display_quick(void){
	gui_lcd_clear( );
}




bool m25p16_init(){
	return true;
}

void m25p16_eraseSector(uint32_t address){
	UNUSED(address);
}
void m25p16_eraseCompletely(){
}

void m25p16_pageProgram(uint32_t address, const uint8_t *data, int length){
	UNUSED(address);
	UNUSED(data);
	UNUSED(length);
}

void m25p16_pageProgramBegin(uint32_t address){
	UNUSED(address);
}
void m25p16_pageProgramContinue(const uint8_t *data, int length){
	UNUSED(data);
	UNUSED(length);
}
void m25p16_pageProgramFinish(){
}

int m25p16_readBytes(uint32_t address, uint8_t *buffer, int length){
	UNUSED(address);
	UNUSED(buffer);
	UNUSED(length);
	return 0;
}

bool m25p16_isReady(){
	return true;
}
bool m25p16_waitForReady(uint32_t timeoutMillis){
	UNUSED(timeoutMillis);
	return true;
}

const flashGeometry_t* m25p16_getGeometry(){
	return 0;
}






bool ug2864hsweg01InitI2C(){
	return true;
}






void ws2811LedStripInit(void){
}
void ws2811UpdateStrip(void){
}

bool isWS2811LedStripReady(void){
	return false;
}

void setLedHsv(int index, const hsvColor_t *color){
	UNUSED(index);
	UNUSED(color);
}

void getLedHsv(int index, hsvColor_t *color){
	UNUSED(index);
	UNUSED(color);
}

void setStripColor(const hsvColor_t *color){
	UNUSED(color);
}

bool isMPUSoftReset(void){
	return false;
}

void i2cSetOverclock(uint8_t OverClock){
	UNUSED(OverClock);
}



void timerStart( ){
}


void transponderIrInit(void){
}
//void transponderIrDisable(void);

//void transponderIrHardwareInit(void);
//void transponderIrDMAEnable(void);

//void transponderIrWaitForTransmitComplete(void);

void transponderIrUpdateData(const uint8_t* transponderData){
	UNUSED(transponderData);
}

void transponderIrTransmit(void){
}

bool isTransponderIrReady(void){
	return false;
}

//uint8_t __pg_registry_start;
//uint8_t __pg_registry_end;
//uint8_t __pg_resetdata_start;
//uint8_t __pg_resetdata_end;
//uint8_t __config_start;
//uint8_t __config_end;
/*




void i2cInit(I2CDevice index){
	UNUSED(index);
}


bool i2cWriteBuffer(uint8_t addr_, uint8_t reg_, uint8_t len_, uint8_t *data){
}

bool i2cWrite(uint8_t addr_, uint8_t reg, uint8_t data){
}

bool i2cRead(uint8_t addr_, uint8_t reg, uint8_t len, uint8_t* buf){
}

uint16_t i2cGetErrorCounter(void){
}






//void initBeeperHardware(beeperConfig_t *config){}







*/


