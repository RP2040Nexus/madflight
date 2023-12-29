/*==============================================================================
Generated on: 2023-12-29 02:35:19.320623
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: ALIENFLIGHTNGF7_DUAL
Manufacturer ID: AFNG

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/AFNG-ALIENFLIGHTNGF7_DUAL.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-AFNG-ALIENFLIGHTNGF7_DUAL"
#define HW_MCU "STM32F7X2"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6500
#define USE_IMU_SPI_ICM20602
#define USE_MAX7456
#define USE_SDCARD

//Sensor specific setup
#define IMU_ROTATE_CW270
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PC12;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC14;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB6;
const int HW_PIN_I2C_SCL  = PB7;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PC6,PC7,PB14,PB0,PA0,PC8,PA1,PC9};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = -1;
const int HW_PIN_GPS_TX   = -1;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC0;
const int HW_PIN_BAT_I    = PC1;

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
# Betaflight / STM32F7X2 (S7X2) 4.3.2 Nov 28 2022 / 07:30:19 (60c9521) MSP API: 1.44

#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO_SPI_ICM20602
#define USE_ACC_SPI_ICM20602
#define USE_MAX7456
#define USE_SDCARD

board_name ALIENFLIGHTNGF7_DUAL
manufacturer_id AFNG

# resources
resource BEEPER 1 C13
resource MOTOR 1 C06
resource MOTOR 2 C07
resource MOTOR 3 B14
resource MOTOR 4 B00
resource MOTOR 5 A00
resource MOTOR 6 C08
resource MOTOR 7 A01
resource MOTOR 8 C09
resource PPM 1 A08
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 4 C10
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 4 C11
resource I2C_SCL 1 B06
resource I2C_SDA 1 B07
resource LED 1 C12
resource LED 2 D02
resource RX_BIND 1 B02
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 C02
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 C03
resource SPI_MOSI 3 B05
resource ADC_BATT 1 C00
resource ADC_RSSI 1 C04
resource ADC_CURR 1 C01
resource SDCARD_CS 1 B10
resource SDCARD_DETECT 1 B11
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C14
resource GYRO_EXTI 2 C15
resource GYRO_CS 1 A04
resource GYRO_CS 2 A15

# timer
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C07 AF2
# pin C07: TIM3 CH2 (AF2)
timer B14 AF3
# pin B14: TIM8 CH2N (AF3)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B15 AF1
# pin B15: TIM1 CH3N (AF1)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer B09 AF2
# pin B09: TIM4 CH4 (AF2)

# dma
dma SPI_TX 2 0
# SPI_TX 2: DMA1 Stream 4 Channel 0
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin A08 1
# pin A08: DMA2 Stream 1 Channel 6
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0
dma pin C07 0
# pin C07: DMA1 Stream 5 Channel 5
dma pin B14 1
# pin B14: DMA2 Stream 3 Channel 7
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin C08 1
# pin C08: DMA2 Stream 4 Channel 7
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B15 0
# pin B15: DMA2 Stream 6 Channel 0
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2

# feature
feature RX_SERIAL
feature MOTOR_STOP
feature OSD

# map
map TAER1234

# serial
serial 1 64 115200 57600 0 115200

# master
set serialrx_provider = SPEK2048
set spektrum_sat_bind = 9
set blackbox_device = SDCARD
set dshot_burst = ON
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 2
set max7456_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270
set gyro_1_align_yaw = 2700
set gyro_2_bustype = SPI
set gyro_2_spibus = 3
set gyro_2_sensor_align = CW270
set gyro_2_align_yaw = 2700
set i2c1_pullup = ON

*/
