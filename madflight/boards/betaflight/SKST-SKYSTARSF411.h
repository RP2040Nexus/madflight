/*==============================================================================
Generated on: 2023-12-29 02:35:19.580972
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: SKYSTARSF411
Manufacturer ID: SKST

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/SKST-SKYSTARSF411.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-SKST-SKYSTARSF411"
#define HW_MCU "STM32F411"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6000
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW180
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PC13;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PC15;
const int HW_PIN_IMU_EXTI = PC14;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 6;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PA0,PA1,PB6,PB7,PB10,PNONE};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = -1;
const int HW_PIN_GPS_TX   = -1;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PB1;
const int HW_PIN_BAT_I    = PA4;

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
# Betaflight / STM32F411 (S411) 4.1.0 Jun 25 2019 / 10:27:57 (2a6e94d03) MSP API: 1.42

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACCGYRO_BMI270
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name SKYSTARSF411
manufacturer_id SKST

# resources
resource LED 1 C13
resource PPM 1 A03
resource BEEPER 1 B02
resource LED_STRIP 1 A08

# Motor
resource MOTOR 1 A00
resource MOTOR 2 A01
resource MOTOR 3 B06
resource MOTOR 4 B07
resource MOTOR 5 B10
resource MOTOR 6 NONE

# UART1
resource SERIAL_TX 1 A09
resource SERIAL_RX 1 A10

# UART2
resource SERIAL_TX 2 A02
resource SERIAL_RX 2 A03

# SOFTSERIAL1
resource SERIAL_TX 11 B00
resource SERIAL_RX 11 B00

# IIC1
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09

#GYRO & ACC --> SPI1
resource GYRO_CS 1 C15
resource SPI_SCK 1 A05
resource SPI_MISO 1 A06
resource SPI_MOSI 1 A07
resource GYRO_EXTI 1 C14

# OSD --> SPI2
resource OSD_CS 1 B12
resource SPI_SCK 2 B13
resource SPI_MISO 2 B14
resource SPI_MOSI 2 B15

# FLASH --> SPI3
resource FLASH_CS 1 A15
resource SPI_SCK 3 B03
resource SPI_MISO 3 B04
resource SPI_MOSI 3 B05

# ADC
resource ADC_BATT 1 B01
resource ADC_CURR 1 A04

# Timer list
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer A00 AF1
# pin A00: TIM2 CH1 (AF1)
timer A01 AF1
# pin A01: TIM2 CH2 (AF1)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)


# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin A00 0
# pin A00: DMA1 Stream 5 Channel 3
dma pin A01 0
# pin A01: DMA1 Stream 6 Channel 3
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin A08 0
# pin A08: DMA2 Stream 3 Channel 6

# feature
feature RX_SERIAL
feature SOFTSERIAL
feature TELEMETRY
feature OSD

# serial
serial 0 64 115200 57600 0 115200
serial 30 2048 115200 57600 0 115200

# master
set baro_bustype = I2C
set baro_i2c_device = 1
set baro_hardware = NONE
set serialrx_provider = SBUS
set blackbox_device = SPIFLASH
set flash_spi_bus = 3
set dshot_idle_value = 450
set dshot_burst = AUTO
set dshot_bitbang = OFF
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set mag_hardware = NONE
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set max7456_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180
set gyro_1_align_yaw = 1800

*/
