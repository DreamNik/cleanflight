#include <stdio.h>
#include <string.h>

extern "C"{
	#include <platform.h>
}

extern uint8_t __config_start;
extern uint8_t __config_end;


void FLASH_Load( ){
	FILE* f = fopen( "eeprom.bin" , "rb" );
	if( f ){
		fread( &__config_start , 1 , &__config_end - &__config_start , f );
		fclose( f );
	}
}


void FLASH_Save( ){
	FILE* f = fopen( "eeprom.bin" , "wb" );
	if( f ){
		fwrite( &__config_start , 1 , &__config_end - &__config_start , f );
		fclose( f );
	}
}


void FLASH_Unlock(void){
}


void FLASH_Lock(void){
}


FLASH_Status FLASH_ErasePage( uint32_t Page_Address ){
	memset( (void*)Page_Address , 0 , FLASH_PAGE_SIZE );
	return FLASH_COMPLETE;
}


FLASH_Status FLASH_ProgramWord( uint32_t Address , uint32_t Data ){
	*(uint32_t*)Address = Data;
	return FLASH_COMPLETE;
}


void FLASH_ClearFlag( uint32_t FLASH_FLAG ){
	UNUSED(FLASH_FLAG);
}
