/*==============================================================================
Generated on: 2023-12-29 02:35:19.583124
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: SKYSTARSH7HD
Manufacturer ID: SKST

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/SKST-SKYSTARSH7HD.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-SKST-SKYSTARSH7HD"
#define HW_MCU "STM32H743"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_BARO_BMP280
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW90
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PE3;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PD7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PC15;
const int HW_PIN_IMU_EXTI = PB2;

//BARO/MAG I2C: (I2C2)
const int HW_PIN_I2C_SDA  = PB10;
const int HW_PIN_I2C_SCL  = PB11;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB0,PB1,PD12,PD13,PA0,PA1,PA2,PA3};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PD9;
const int HW_PIN_GPS_TX   = PD8;
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
# Betaflight / STM32H743 (SH74) 4.3.0 Aug 10 2021 / 12:14:35 (8ca4fdc58) MSP API: 1.44

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name SKYSTARSH7HD
manufacturer_id SKST

# resources
resource BEEPER 1 B03
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 D12
resource MOTOR 4 D13
resource MOTOR 5 A00
resource MOTOR 6 A01
resource MOTOR 7 A02
resource MOTOR 8 A03
resource SERVO 1 E05
resource SERVO 2 E06
resource PPM 1 C07
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 D05
resource SERIAL_TX 3 D08
resource SERIAL_TX 4 D01
resource SERIAL_TX 5 B06
resource SERIAL_TX 6 C06
resource SERIAL_TX 7 E08
resource SERIAL_TX 8 E01
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 D06
resource SERIAL_RX 3 D09
resource SERIAL_RX 4 D00
resource SERIAL_RX 5 B05
resource SERIAL_RX 6 C07
resource SERIAL_RX 7 E07
resource SERIAL_RX 8 E00
resource I2C_SCL 1 B08
resource I2C_SCL 2 B10
resource I2C_SDA 1 B09
resource I2C_SDA 2 B11
resource LED 1 E03
resource LED 2 E04
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_SCK 4 E12
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MISO 4 E13
resource SPI_MOSI 1 D07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource SPI_MOSI 4 E14
resource ADC_BATT 1 C00
resource ADC_RSSI 1 C03
resource ADC_CURR 1 C01
resource ADC_EXT 1 C04
resource PINIO 1 C05
resource PINIO 2 C02
resource PINIO 3 D11
resource FLASH_CS 1 A15
resource OSD_CS 1 B12
resource GYRO_EXTI 1 B02
resource GYRO_EXTI 2 E15
resource GYRO_CS 1 C15
resource GYRO_CS 2 E11
resource USB_DETECT 1 E02

# timer
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer D12 AF2
# pin D12: TIM4 CH1 (AF2)
timer D13 AF2
# pin D13: TIM4 CH2 (AF2)
timer D14 AF2
# pin D14: TIM4 CH3 (AF2)
timer D15 AF2
# pin D15: TIM4 CH4 (AF2)
timer E05 AF4
# pin E05: TIM15 CH1 (AF4)
timer E06 AF4
# pin E06: TIM15 CH2 (AF4)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer B08 AF1
# pin B08: TIM16 CH1 (AF1)
timer B09 AF1
# pin B09: TIM17 CH1 (AF1)

# dma
dma ADC 1 8
# ADC 1: DMA2 Stream 0 Request 9
dma ADC 3 9
# ADC 3: DMA2 Stream 1 Request 115
dma TIMUP 1 0
# TIMUP 1: DMA1 Stream 0 Request 15
dma TIMUP 2 0
# TIMUP 2: DMA1 Stream 0 Request 22
dma TIMUP 3 2
# TIMUP 3: DMA1 Stream 2 Request 27
dma TIMUP 4 1
# TIMUP 4: DMA1 Stream 1 Request 32
dma TIMUP 5 0
# TIMUP 5: DMA1 Stream 0 Request 59
dma TIMUP 8 0
# TIMUP 8: DMA1 Stream 0 Request 51
dma pin B00 0
# pin B00: DMA1 Stream 0 Request 25
dma pin B01 1
# pin B01: DMA1 Stream 1 Request 26
dma pin A00 2
# pin A00: DMA1 Stream 2 Request 55
dma pin A01 3
# pin A01: DMA1 Stream 3 Request 56
dma pin A02 4
# pin A02: DMA1 Stream 4 Request 57
dma pin A03 5
# pin A03: DMA1 Stream 5 Request 58
dma pin D12 6
# pin D12: DMA1 Stream 6 Request 29
dma pin D13 7
# pin D13: DMA1 Stream 7 Request 30
dma pin D14 12
# pin D14: DMA2 Stream 4 Request 31
dma pin E05 0
# pin E05: DMA1 Stream 0 Request 105
dma pin A08 14
# pin A08: DMA2 Stream 6 Request 11
dma pin A15 0
# pin A15: DMA1 Stream 0 Request 18
dma pin C07 0
# pin C07: DMA1 Stream 0 Request 48
dma pin C06 0
# pin C06: DMA1 Stream 0 Request 47
dma pin B08 0
# pin B08: DMA1 Stream 0 Request 109
dma pin B09 0
# pin B09: DMA1 Stream 0 Request 111

# feature
feature RX_SERIAL
feature TELEMETRY
feature LED_STRIP
feature OSD

# serial
serial 0 64 115200 57600 0 115200
serial 2 1024 115200 57600 0 115200
serial 3 2 115200 57600 0 115200
serial 4 2048 115200 57600 0 115200
serial 5 1 115200 57600 0 115200

# aux
aux 1 40 2 1700 2100 0 0
aux 2 41 3 1700 2100 0 0

# master
set gyro_to_use = BOTH
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 2
set blackbox_device = SPIFLASH
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 290
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 2
set pinio_box = 40,41,255,255
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW90
set gyro_1_align_yaw = 900
set gyro_2_spibus = 4

*/
