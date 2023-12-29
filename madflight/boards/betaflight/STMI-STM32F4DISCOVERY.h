/*==============================================================================
Generated on: 2023-12-29 02:35:19.613078
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: STM32F4DISCOVERY
Manufacturer ID: STMI

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/STMI-STM32F4DISCOVERY.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-STMI-STM32F4DISCOVERY"
#define HW_MCU "STM32F405"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6500
#define USE_SDCARD

//Sensor specific setup
#define IMU_ROTATE_CW180FLIP
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PD12;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PC4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 6;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB1,PB0,PA2,PA3,PA10,PA8};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PB7;
const int HW_PIN_RCIN_TX  = PB6;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC1;
const int HW_PIN_BAT_I    = PC2;

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
# Betaflight / STM32F405 (S405) 4.2.0 Feb  2 2020 / 14:39:25 (30bf9e809f) MSP API: 1.43

#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_SDCARD

board_name STM32F4DISCOVERY
manufacturer_id STMI

# resources
resource MOTOR 1 B01
resource MOTOR 2 B00
resource MOTOR 3 A02
resource MOTOR 4 A03
resource MOTOR 5 A10
resource MOTOR 6 A08
resource PPM 1 B09
resource LED_STRIP 1 B09
resource SERIAL_TX 1 B06
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 B07
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 6 C07
resource LED 1 D12
resource LED 2 D13
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource ESCSERIAL 1 B09
resource ADC_BATT 1 C01
resource ADC_CURR 1 C02
resource SDCARD_CS 1 D08
resource USB_MSC_PIN 1 A00
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 C04
resource USB_DETECT 1 A09

# timer
timer B09 AF2
# pin B09: TIM4 CH4 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer A10 AF1
# pin A10: TIM1 CH3 (AF1)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)

# dma
dma SPI_TX 2 0
# SPI_TX 2: DMA1 Stream 4 Channel 0
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin A02 0
# pin A02: DMA1 Stream 1 Channel 3
dma pin A03 1
# pin A03: DMA1 Stream 6 Channel 3
dma pin A10 1
# pin A10: DMA2 Stream 6 Channel 6
dma pin A08 1
# pin A08: DMA2 Stream 1 Channel 6

# master
set current_meter = ADC
set battery_meter = ADC
set sdcard_mode = SPI
set sdcard_spi_bus = 2
set system_hse_mhz = 8
set led_inversion = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180FLIP
set gyro_1_align_pitch = 1800
set gyro_1_align_yaw = 1800

*/
