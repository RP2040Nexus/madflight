/*==============================================================================
Generated on: 2023-12-29 02:35:19.431724
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: FOXEERF745V2_AIO
Manufacturer ID: FOXE

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/FOXE-FOXEERF745V2_AIO.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FOXE-FOXEERF745V2_AIO"
#define HW_MCU "STM32F745"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_FLASH_W25Q128FV
#define USE_MAX7456
#define USE_CAMERA_CONTROL

//Sensor specific setup
#define IMU_ROTATE_CW0
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PC13;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI3)
const int HW_PIN_SPI_MISO = PC11;
const int HW_PIN_SPI_MOSI = PC12;
const int HW_PIN_SPI_SCLK = PC10;
const int HW_PIN_IMU_CS   = PA15;
const int HW_PIN_IMU_EXTI = PD0;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB4,PB5,PB1,PB0};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC3;
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
# Betaflight / STM32F745 (S745) 4.1.0 Sep 25 2020 / 01:23:16 (064ca9b75) MSP API: 1.42

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456
#define USE_CAMERA_CONTROL

board_name FOXEERF745V2_AIO
manufacturer_id FOXE

# resources
resource BEEPER 1 D02
resource MOTOR 1 B04
resource MOTOR 2 B05
resource MOTOR 3 B01
resource MOTOR 4 B00
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 7 E08
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 7 E07
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 C13
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_SCK 4 E02
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MISO 4 E05
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource SPI_MOSI 4 E06
resource CAMERA_CONTROL 1 B03
resource ADC_BATT 1 C03
resource ADC_RSSI 1 C05
resource ADC_CURR 1 C02
resource ADC_EXT 1 C01
resource FLASH_CS 1 E04
resource OSD_CS 1 A04
resource GYRO_EXTI 1 D00
resource GYRO_CS 1 A15

# timer
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)

# dma
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin B03 0
# pin B03: DMA1 Stream 6 Channel 3
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5

# feature
feature RX_SERIAL
feature TELEMETRY
feature OSD

# serial
serial 0 64 115200 57600 0 115200

# master
set align_mag = CW180
set mag_align_yaw = 1800
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 1
set serialrx_provider = SBUS
set blackbox_device = SPIFLASH
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 100
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 1
set flash_spi_bus = 4
set gyro_1_bustype = SPI
set gyro_1_spibus = 3
set gyro_1_sensor_align = CW0
set gyro_1_align_yaw = 1800

*/
