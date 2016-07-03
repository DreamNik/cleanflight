#pragma once
#include <stdint.h>

#pragma pack(1)

#define TARGET_BOARD_IDENTIFIER "AFNA" // AFroNAze - NAZE might be considered misleading on Naze clones like the flip32.
#define USE_HARDWARE_REVISION_DETECTION

#define BOARD_HAS_VOLTAGE_DIVIDER

#define BEEP_GPIO       0
#define BEEP_PIN        0
#define BEEP_PERIPHERAL 0

#define LED0
#define LED0_INVERTED
#define LED1
#define LED1_INVERTED
#define LED2
#define LED2_INVERTED

// SPI2
// PB15 28 SPI2_MOSI
// PB14 27 SPI2_MISO
// PB13 26 SPI2_SCK
// PB12 25 SPI2_NSS

//#define USE_SPI
//#define USE_SPI_DEVICE_2

#define NAZE_SPI_INSTANCE     SPI2
#define NAZE_SPI_CS_GPIO      GPIOB
#define NAZE_SPI_CS_PIN       GPIO_Pin_12
#define NAZE_CS_GPIO_CLK_PERIPHERAL RCC_APB2Periph_GPIOB

// We either have this 16mbit flash chip on SPI or the MPU6500 acc/gyro depending on board revision:
#define M25P16_CS_GPIO        NAZE_SPI_CS_GPIO
#define M25P16_CS_PIN         NAZE_SPI_CS_PIN
#define M25P16_SPI_INSTANCE   NAZE_SPI_INSTANCE

#define MPU6500_CS_GPIO_CLK_PERIPHERAL   NAZE_CS_GPIO_CLK_PERIPHERAL
#define MPU6500_CS_GPIO                  NAZE_SPI_CS_GPIO
#define MPU6500_CS_PIN                   NAZE_SPI_CS_PIN
#define MPU6500_SPI_INSTANCE             NAZE_SPI_INSTANCE


//#define USE_FLASHFS
//#define USE_FLASH_M25P16

#define EXTI_CALLBACK_HANDLER_COUNT 3 // MPU data ready, MAG data ready, BMP085 EOC

//#define DEBUG_MPU_DATA_READY_INTERRUPT
#define USE_MPU_DATA_READY_SIGNAL

//#define DEBUG_MAG_DATA_READY_INTERRUPT
#define USE_MAG_DATA_READY_SIGNAL

#define GYRO
#define USE_GYRO_MPU6500
#define GYRO_MPU6500_ALIGN CW0_DEG

#define ACC
#define USE_ACC_MPU6500
#define ACC_MPU6500_ALIGN CW0_DEG

#define BARO
#define USE_BARO_BMP280

#define MAG
#define USE_MAG_HMC5883
#define MAG_HMC5883_ALIGN CW180_DEG

#define SONAR
#define BEEPER
#define DISPLAY

#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_SOFTSERIAL1
#define USE_SOFTSERIAL2
#define SERIAL_PORT_COUNT 5

#define SOFTSERIAL_2_TIMER 2
#define SOFTSERIAL_1_TIMER 3
#define LED_STRIP_TIMER    4

//#define USE_I2C
#define I2C_DEVICE 0

#define USE_ADC
#define GPS
#define LED_STRIP

#define BLACKBOX
#define TELEMETRY
#define SERIAL_RX
#define USE_SERVOS
#define USE_CLI

#define ESC_COUNT 16
#define GTUNE



#define UNIT_TEST
#define IRQn_Type    int
#define GPIO_TypeDef void
#define TIM_TypeDef  void
#define FunctionalState int
#define DMA_Channel_TypeDef void
#define USART_TypeDef void
#define SPI_TypeDef void

#define GPIOA (void*)0
#define GPIOB (void*)0
#define GPIOC (void*)0

#define EXTI_Line1 0
#define EXTI_Line9 0
#define GPIO_PinSource9 0
#define EXTI9_5_IRQn 0
#define GPIO_PinSource1 0
#define EXTI1_IRQn 0
#define RCC_APB2Periph_GPIOB 0
#define GPIO_PortSourceGPIOB 0
#define EXTI_Line13 0
#define GPIO_PinSource13 0
#define EXTI15_10_IRQn 0
#define RCC_APB2Periph_GPIOC 0
#define GPIO_PortSourceGPIOC 0
#define EXTI_Line14 0
#define GPIO_PinSource14 0

#define USART1 (void*)0
#define USART2 (void*)1
#define USART3 (void*)2
#define SystemCoreClock 100000000


#define UNUSED(x) (void)(x)
void digitalHi(GPIO_TypeDef *p, int i);
void digitalLo(GPIO_TypeDef *p, int i);
void digitalToggle(GPIO_TypeDef *p, int i);


typedef enum{
  FLASH_BUSY = 1,
  FLASH_ERROR_PG,
  FLASH_ERROR_WRP,
  FLASH_COMPLETE,
  FLASH_TIMEOUT
}FLASH_Status;

#define FLASH_FLAG_BSY      0
#define FLASH_FLAG_EOP      0
#define FLASH_FLAG_PGERR    0
#define FLASH_FLAG_WRPRTERR 0
#define FLASH_FLAG_OPTERR   0



void         FLASH_Unlock(void);
void         FLASH_Lock(void);
FLASH_Status FLASH_ErasePage(uint32_t Page_Address);
FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data);
void         FLASH_ClearFlag(uint32_t FLASH_FLAG);

#define FLASH_SIZE       0x100000
#define FLASH_PAGE_SIZE  1024


#undef U_ID_0
#undef U_ID_1
#undef U_ID_2

#define U_ID_0 0x12345678
#define U_ID_1 0x12345678
#define U_ID_2 0x12345678

#ifdef main
	#undef main
#endif

#define main cf_main
