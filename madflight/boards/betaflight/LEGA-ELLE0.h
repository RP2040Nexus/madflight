/*==============================================================================
Generated on: 2023-12-29 02:35:19.517724
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: ELLE0
Manufacturer ID: LEGA

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/LEGA-ELLE0.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-LEGA-ELLE0"
#define HW_MCU "STM32F405"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6500

//Sensor specific setup
#define IMU_ROTATE_CW270
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PA8;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI2)
const int HW_PIN_SPI_MISO = PB14;
const int HW_PIN_SPI_MOSI = PB15;
const int HW_PIN_SPI_SCLK = PB13;
const int HW_PIN_IMU_CS   = PB12;
const int HW_PIN_IMU_EXTI = PB5;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PC6,PC7,PC8,PC9,PA0,PA1,PB8,PB9};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = -1;
const int HW_PIN_RCIN_TX  = -1;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC4;
const int HW_PIN_BAT_I    = PC5;

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
# Betaflight / STM32F405 (S405) 4.2.0 Feb  8 2020 / 16:03:40 (norevision) MSP API: 1.43

#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO
#define USE_GYRO_SPI_MPU6500

board_name ELLE0
manufacturer_id LEGA

# resources
resource MOTOR 1 C06
resource MOTOR 2 C07
resource MOTOR 3 C08
resource MOTOR 4 C09
resource MOTOR 5 A00
resource MOTOR 6 A01
resource MOTOR 7 B08
resource MOTOR 8 B09
resource PPM 1 A02
resource PWM 1 A02
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource LED 1 A08
resource LED 2 B04
resource LED 3 C02
resource SPI_SCK 2 B13
resource SPI_MISO 2 B14
resource SPI_MOSI 2 B15
resource ADC_BATT 1 C04
resource ADC_CURR 1 C05
resource GYRO_EXTI 1 B05
resource GYRO_CS 1 B12

# timer
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer B09 AF2
# pin B09: TIM4 CH4 (AF2)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin A02 0
# pin A02: DMA1 Stream 1 Channel 3
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0
dma pin C07 0
# pin C07: DMA2 Stream 2 Channel 0
dma pin C08 1
# pin C08: DMA2 Stream 4 Channel 7
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2

# master
set mag_bustype = SLAVE
set system_hse_mhz = 25
set gyro_1_bustype = SPI
set gyro_1_spibus = 2
set gyro_1_sensor_align = CW270
set gyro_1_align_yaw = 2700

*/
