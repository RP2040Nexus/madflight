/*==============================================================================
Generated on: 2023-12-29 02:35:19.370903
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: DREAMFLYF411
Manufacturer ID: DFRC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/DFRC-DREAMFLYF411.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-DFRC-DREAMFLYF411"
#define HW_MCU "STM32F411"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6000
#define USE_IMU_SPI_ICM42688P
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW270
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PC13;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PA1;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB10,PB6,PB7,PB8};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = -1;
const int HW_PIN_GPS_TX   = -1;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PB0;
const int HW_PIN_BAT_I    = PB1;

//Include Libraries
#include <Wire.h>                      //I2C communication
#include <SPI.h>                       //SPI communication
#include "src/hw_STM32/STM32_PWM.h"    //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F411 (S411) 4.3.0 Jun 14 2022 / 00:48:04 (229ac66) MSP API: 1.44

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_ACCGYRO_BMI270
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name DREAMFLYF411
manufacturer_id DFRC

# resources
resource BEEPER 1 C15
resource MOTOR 1 B10
resource MOTOR 2 B06
resource MOTOR 3 B07
resource MOTOR 4 B08
resource PPM 1 A10
resource LED_STRIP 1 A00
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource LED 1 C13
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource ADC_BATT 1 B00
resource ADC_CURR 1 B01
resource FLASH_CS 1 A14
resource OSD_CS 1 B12
resource GYRO_EXTI 1 A01
resource GYRO_CS 1 A04

# timer
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A09 AF1
# pin A09: TIM1 CH2 (AF1)
timer A10 AF1
# pin A10: TIM1 CH3 (AF1)

# dma
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin A09 0
# pin A09: DMA2 Stream 6 Channel 0
dma pin A10 0
# pin A10: DMA2 Stream 6 Channel 0


# feature
feature LED_STRIP
feature OSD
feature RX_SERIAL

# serial
serial 0 64 115200 57600 0 115200

# master
set serialrx_provider = CRSF
set blackbox_device = SPIFLASH
set dshot_burst = AUTO
set dshot_bitbang = OFF
set current_meter = ADC
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set max7456_spi_bus = 2
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270

*/
