/*==============================================================================
Generated on: 2023-12-29 02:35:19.384727
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: ELINF722
Manufacturer ID: DRCL

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/DRCL-ELINF722.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-DRCL-ELINF722"
#define HW_MCU "STM32F7X2"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6500
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW0
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PB5;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB0,PB1,PA3,PA2};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

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
# Betaflight / STM32F7X2 (S7X2) 4.0.0 Mar 26 2019 / 19:51:34 (173e958da) MSP API: 1.41

#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_MAX7456

board_name ELINF722
manufacturer_id DRCL

# name

# resources
resource BEEPER 1 B04
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 A03
resource MOTOR 4 A02
resource PPM 1 B06
resource LED_STRIP 1 B06
resource SERIAL_TX 1 A09
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 6 C06
resource SERIAL_TX 11 C09
resource SERIAL_RX 1 A10
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 6 C07
resource SERIAL_RX 12 A08
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 B05
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource CAMERA_CONTROL 1 B07
resource ADC_BATT 1 C02
resource ADC_CURR 1 C01
resource PINIO 1 C13
resource PINIO 2 C14
resource FLASH_CS 1 B03
resource OSD_CS 1 C08
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04
resource USB_DETECT 1 C15

# timer
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin A03 1
# pin A03: DMA1 Stream 6 Channel 3
dma pin A02 0
# pin A02: DMA1 Stream 1 Channel 3
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2

# mixer

# servo

# servo mix


# feature
feature RX_SERIAL
feature SOFTSERIAL
feature TELEMETRY
feature OSD

# beeper

# beacon

# map

# serial
serial 0 64 115200 57600 0 115200

# led

# color

# mode_color

# aux

# adjrange

# rxrange

# vtx

# rxfail

# display_name

# master
set mag_hardware = NONE
set baro_bustype = I2C
set baro_i2c_device = 1
set serialrx_provider = SBUS
set serialrx_halfduplex = ON
set dshot_burst = ON
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set pid_process_denom = 1
set osd_warn_core_temp = OFF
set osd_warn_rc_smoothing = OFF
set osd_warn_fail_safe = OFF
set osd_warn_launch_control = OFF
set osd_warn_no_gps_rescue = OFF
set osd_warn_gps_rescue_disabled = OFF
set osd_vbat_pos = 2401
set osd_rssi_pos = 2106
set osd_vtx_channel_pos = 2424
set osd_crosshairs_pos = 2253
set osd_ah_sbar_pos = 2254
set osd_ah_pos = 2126
set osd_compass_bar_pos = 106
set osd_warnings_pos = 2377
set vcd_video_system = NTSC
set max7456_spi_bus = 2
set pinio_box = 40,41,255,255
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW0
set gyro_2_spibus = 1

*/
