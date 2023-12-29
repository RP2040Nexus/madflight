/*==============================================================================
Generated on: 2023-12-29 02:35:19.554302
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: NEUTRONRCG4AIO
Manufacturer ID: NERC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/NERC-NEUTRONRCG4AIO.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-NERC-NEUTRONRCG4AIO"
#define HW_MCU "STM32G47X"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)

//Sensor specific setup
#define IMU_ROTATE_CW270
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
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PA15;
const int HW_PIN_I2C_SCL  = PB7;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB1,PB0,PB3,PB4};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PA0;
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
# Betaflight / STM32G47X (SG47) 4.3.0 Apr 27 2021 / 03:49:09 (e228d797c) MSP API: 1.44

board_name NEUTRONRCG4AIO
manufacturer_id NERC

# resources
resource BEEPER 1 C14
resource MOTOR 1 B01
resource MOTOR 2 B00
resource MOTOR 3 B03
resource MOTOR 4 B04
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource I2C_SCL 1 A15
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
resource ESCSERIAL 1 C06
resource CAMERA_CONTROL 1 B06
resource ADC_BATT 1 A00
resource ADC_CURR 1 A01
resource FLASH_CS 1 B09
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04

# timer
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer A08 AF6
# pin A08: TIM1 CH1 (AF6)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer A02 AF9
# pin A02: TIM15 CH1 (AF9)

# dma
dma ADC 1 12
# ADC 1: DMA2 Channel 5 Request 5
dma TIMUP 1 0
# TIMUP 1: DMA1 Channel 1 Request 46
dma TIMUP 2 0
# TIMUP 2: DMA1 Channel 1 Request 60
dma TIMUP 3 0
# TIMUP 3: DMA1 Channel 1 Request 65
dma TIMUP 4 0
# TIMUP 4: DMA1 Channel 1 Request 71
dma TIMUP 5 0
# TIMUP 5: DMA1 Channel 1 Request 76
dma pin B00 0
# pin B00: DMA1 Channel 1 Request 63
dma pin B01 1
# pin B01: DMA1 Channel 2 Request 64
dma pin B04 2
# pin B04: DMA1 Channel 3 Request 61
dma pin B03 3
# pin B03: DMA1 Channel 4 Request 57
dma pin A08 8
# pin A08: DMA2 Channel 1 Request 42
dma pin B06 0
# pin B06: DMA1 Channel 1 Request 67
dma pin A02 0
# pin A02: DMA1 Channel 1 Request 78

# feature
feature OSD

# serial
serial 0 1 115200 57600 0 115200
serial 1 64 115200 57600 0 115200
serial 2 1024 115200 57600 0 115200

# master
set baro_bustype = I2C
set baro_i2c_device = 1
set blackbox_device = SPIFLASH
set dshot_burst = OFF
set dshot_bitbang = OFF
set motor_pwm_protocol = DSHOT300
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 100
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set max7456_spi_bus = 2
set led_inversion = 1
set flash_spi_bus = 3
set pid_process_denom = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270
set gyro_1_align_yaw = 2700

*/
