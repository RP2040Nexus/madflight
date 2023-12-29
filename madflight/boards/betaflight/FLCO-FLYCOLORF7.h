/*==============================================================================
Generated on: 2023-12-29 02:35:19.402199
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: FLYCOLORF7
Manufacturer ID: FLCO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/FLCO-FLYCOLORF7.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FLCO-FLYCOLORF7"
#define HW_MCU "STM32F7X2"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6000
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW180FLIP
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PC15;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC3;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB6;
const int HW_PIN_I2C_SCL  = PB7;

//Outputs:
const int HW_OUT_COUNT    = 6;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB1,PB4,PB3,PA15,PC8,PC9};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC1;
const int HW_PIN_BAT_I    = PC0;

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
# Betaflight / STM32F7X2 (S7X2) 4.2.0 Jun 14 2020 / 03:05:26 (8f2d21460) MSP API: 1.43

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name FLYCOLORF7
manufacturer_id FLCO

# resources
resource BEEPER 1 C14
resource MOTOR 1 B01
resource MOTOR 2 B04
resource MOTOR 3 B03
resource MOTOR 4 A15
resource MOTOR 5 C08
resource MOTOR 6 C09
resource PPM 1 C06
resource LED_STRIP 1 A08
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
resource I2C_SCL 1 B06
resource I2C_SDA 1 B07
resource LED 1 C15
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource CAMERA_CONTROL 1 B08
resource ADC_BATT 1 C01
resource ADC_RSSI 1 C02
resource ADC_CURR 1 C00
resource PINIO 1 B00
resource PINIO 2 B09
resource FLASH_CS 1 C13
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C03
resource GYRO_EXTI 2 C04
resource GYRO_CS 1 A04
resource GYRO_CS 2 B02

# timer
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)

# dma
dma ADC 3 1
# ADC 3: DMA2 Stream 1 Channel 2
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin B03 0
# pin B03: DMA1 Stream 6 Channel 3
dma pin A15 0
# pin A15: DMA1 Stream 5 Channel 3
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin A02 0
# pin A02: DMA1 Stream 0 Channel 6
dma pin A03 1
# pin A03: DMA1 Stream 3 Channel 6

# feature
feature RX_SERIAL
feature TELEMETRY
feature RSSI_ADC
feature LED_STRIP
feature OSD

# serial
serial 0 64 115200 57600 0 115200
serial 3 1 115200 57600 0 115200

# master
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 1
set adc_device = 3
set blackbox_device = SPIFLASH
set dshot_burst = ON
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 170
set beeper_inversion = ON
set beeper_od = OFF
set pid_process_denom = 4
set max7456_spi_bus = 2
set pinio_box = 40,41,255,255
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180FLIP
set gyro_1_align_pitch = 1800
set gyro_1_align_yaw = 1800
set gyro_2_spibus = 1
set gyro_2_sensor_align = CW270
set gyro_2_align_yaw = 2700

*/
