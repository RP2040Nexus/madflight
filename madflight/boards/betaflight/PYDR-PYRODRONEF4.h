/*==============================================================================
Generated on: 2023-12-29 02:35:19.559734
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: PYRODRONEF4
Manufacturer ID: PYDR

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/PYDR-PYRODRONEF4.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-PYDR-PYRODRONEF4"
#define HW_MCU "STM32F405"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6000
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW0
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PB4;
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
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB1,PB0,PC9,PA8};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = PC3;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC2;
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
# Betaflight / STM32F405 (S405) 4.1.1 Nov 15 2019 / 12:54:53 (1e5e3d369) MSP API: 1.42

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_MAX7456

board_name PYRODRONEF4
manufacturer_id PYDR

# resources
resource BEEPER 1 B05
resource MOTOR 1 B01
resource MOTOR 2 B00
resource MOTOR 3 C09
resource MOTOR 4 A08
resource LED_STRIP 1 B08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 5 C12
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource INVERTER 1 C03
resource LED 1 B04
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource ESCSERIAL 1 B09
resource CAMERA_CONTROL 1 B09
resource ADC_BATT 1 C02
resource ADC_CURR 1 C01
resource PINIO 1 A15
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04

# timer
timer B09 AF3           # pin B09: TIM11 CH1 (AF3)
timer B01 AF2           # pin B01: TIM3 CH4 (AF2)
timer B00 AF3           # pin B00: TIM8 CH2N (AF3)
timer C09 AF3           # pin C09: TIM8 CH4 (AF3)
timer A08 AF1           # pin A08: TIM1 CH1 (AF1)
timer B08 AF2           # pin B08: TIM4 CH3 (AF2)

# dma
dma ADC 1 1             # ADC 1: DMA2 Stream 4 Channel 0
dma pin B01 0           # pin B01: DMA1 Stream 2 Channel 5
dma pin B00 0           # pin B00: DMA2 Stream 2 Channel 0
dma pin C09 0           # pin C09: DMA2 Stream 7 Channel 7
dma pin A08 1           # pin A08: DMA2 Stream 1 Channel 6
dma pin B08 0           # pin B08: DMA1 Stream 7 Channel 2

# feature
feature OSD

# aux
aux 0 40 255 900 2100 0 0

# master
set mag_hardware = NONE
set baro_hardware = NONE
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set vbat_scale = 160
set ibata_scale = 150
set beeper_inversion = ON
set beeper_od = OFF
set pid_process_denom = 1
set system_hse_mhz = 8
set max7456_spi_bus = 2
set pinio_box = 40,255,255,255
set gyro_1_bustype = SPI
set gyro_1_spibus = 1

*/
