/*==============================================================================
Generated on: 2023-12-29 02:35:19.521568
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: STACKX
Manufacturer ID: LEGA

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/LEGA-STACKX.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-LEGA-STACKX"
#define HW_MCU "STM32F405"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6500
#define USE_MAX7456
#define USE_SDCARD

//Sensor specific setup
#define IMU_ROTATE_CW90
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
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB8,PA2,PA15,PA3};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC0;
const int HW_PIN_BAT_I    = PA1;

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
# Betaflight / STM32F405 (S405) 4.2.0 Mar  5 2020 / 22:29:55 (c29b125a59) MSP API: 1.43

#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_MAX7456
#define USE_SDCARD

board_name STACKX
manufacturer_id LEGA

# resources
resource BEEPER 1 C15
resource MOTOR 1 B08
resource MOTOR 2 A02
resource MOTOR 3 A15
resource MOTOR 4 A03
resource PPM 1 B00
resource LED_STRIP 1 A00
resource SERIAL_TX 1 A09
resource SERIAL_TX 3 B10
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 3 B11
resource SERIAL_RX 6 C07
resource INVERTER 6 C08
resource LED 1 C13
resource LED 2 C14
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 C02
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 C03
resource SPI_MOSI 3 C12
resource ESCSERIAL 1 B00
resource ADC_BATT 1 C00
resource ADC_RSSI 1 C01
resource ADC_CURR 1 A01
resource SDCARD_CS 1 B09
resource SDCARD_DETECT 1 B07
resource FLASH_CS 1 D02
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04
resource USB_DETECT 1 A08
resource VTX_CS 1 B03
resource VTX_DATA 1 B05
resource VTX_CLK 1 B04

# timer
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)

# dma
dma SPI_TX 3 0
# SPI_TX 3: DMA1 Stream 5 Channel 0
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin A02 0
# pin A02: DMA1 Stream 1 Channel 3
dma pin A15 0
# pin A15: DMA1 Stream 5 Channel 3
dma pin A03 1
# pin A03: DMA1 Stream 6 Channel 3
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6

# feature
feature OSD

# master
set blackbox_device = SDCARD
set current_meter = ADC
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 3
set system_hse_mhz = 8
set max7456_spi_bus = 2
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW90
set gyro_1_align_yaw = 900

*/
