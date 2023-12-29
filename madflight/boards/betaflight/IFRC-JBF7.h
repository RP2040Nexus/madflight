/*==============================================================================
Generated on: 2023-12-29 02:35:19.507827
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: JBF7
Manufacturer ID: IFRC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/IFRC-JBF7.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-IFRC-JBF7"
#define HW_MCU "STM32F7X2"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6500
#define USE_FLASH_M25P16
#define USE_BARO_BMP280
#define USE_MAX7456
#define USE_SDCARD

//Sensor specific setup
#define IMU_ROTATE_CW0
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PC4;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA15;
const int HW_PIN_IMU_EXTI = PA8;

//BARO/MAG I2C: (I2C2)
const int HW_PIN_I2C_SDA  = PB10;
const int HW_PIN_I2C_SCL  = PB11;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PC8,PC6,PC9,PC7,PB6,PB7,PB1,PB0};

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
# Betaflight / STM32F7X2 (S7X2) 4.2.0 May 27 2020 / 13:32:04 (6bada9c5e) MSP API: 1.43

#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_BARO
#define USE_BARO_BMP280
#define USE_MAX7456
#define USE_SDCARD

board_name JBF7
manufacturer_id IFRC

# resources
resource BEEPER 1 C15
resource MOTOR 1 C08
resource MOTOR 2 C06
resource MOTOR 3 C09
resource MOTOR 4 C07
resource MOTOR 5 B06
resource MOTOR 6 B07
resource MOTOR 7 B01
resource MOTOR 8 B00
resource PPM 1 A03
resource LED_STRIP 1 A01
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 C10
resource SERIAL_TX 5 C12
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 C11
resource SERIAL_RX 5 D02
resource I2C_SCL 2 B10
resource I2C_SDA 2 B11
resource LED 1 C04
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource CAMERA_CONTROL 1 A00
resource ADC_BATT 1 C01
resource ADC_RSSI 1 C00
resource ADC_CURR 1 C02
resource SDCARD_CS 1 A04
resource PINIO 1 C13
resource PINIO 2 C14
resource PINIO 3 B08
resource FLASH_CS 1 B09
resource OSD_CS 1 B12
resource GYRO_EXTI 1 A08
resource GYRO_EXTI 2 B02
resource GYRO_CS 1 A15
resource GYRO_CS 2 C03

# timer
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer A01 AF1
# pin A01: TIM2 CH2 (AF1)

# dma
dma ADC 3 0
# ADC 3: DMA2 Stream 0 Channel 2
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin C08 1
# pin C08: DMA2 Stream 4 Channel 7
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin C07 1
# pin C07: DMA2 Stream 3 Channel 7
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin A01 0
# pin A01: DMA1 Stream 6 Channel 3

# feature
feature RX_SERIAL
feature OSD
feature ESC_SENSOR

# beacon
beacon RX_LOST
beacon RX_SET

# serial
serial 0 64 115200 57600 0 115200
serial 3 1024 115200 57600 0 115200
serial 4 2048 115200 57600 0 115200

# master
set gyro_to_use = BOTH
set mag_bustype = I2C
set mag_i2c_device = 2
set baro_bustype = I2C
set baro_i2c_device = 2
set serialrx_provider = SBUS
set adc_device = 3
set blackbox_device = SDCARD
set dshot_burst = ON
set current_meter = ESC
set battery_meter = ADC
set vbat_scale = 110
set ibata_scale = 100
set beeper_inversion = ON
set beeper_od = OFF
set sdcard_mode = SPI
set sdcard_spi_bus = 3
set osd_vbat_pos = 384
set osd_rssi_pos = 2426
set osd_tim_1_pos = 53
set osd_tim_2_pos = 2455
set osd_flymode_pos = 2420
set osd_throttle_pos = 2400
set osd_vtx_channel_pos = 34
set osd_crosshairs_pos = 236
set osd_ah_pos = 199
set osd_current_pos = 2440
set osd_mah_drawn_pos = 2448
set osd_craft_name_pos = 2048
set osd_display_name_pos = 490
set osd_gps_speed_pos = 271
set osd_gps_lon_pos = 82
set osd_gps_lat_pos = 65
set osd_gps_sats_pos = 1410
set osd_home_dir_pos = 302
set osd_home_dist_pos = 303
set osd_compass_bar_pos = 265
set osd_altitude_pos = 246
set osd_pid_roll_pos = 135
set osd_pid_pitch_pos = 167
set osd_pid_yaw_pos = 199
set osd_debug_pos = 0
set osd_power_pos = 320
set osd_pidrate_profile_pos = 344
set osd_warnings_pos = 2406
set osd_avg_cell_voltage_pos = 2432
set osd_pit_ang_pos = 256
set osd_rol_ang_pos = 288
set osd_battery_usage_pos = 391
set osd_disarmed_pos = 75
set osd_nheading_pos = 310
set osd_nvario_pos = 278
set osd_esc_tmp_pos = 82
set osd_esc_rpm_pos = 83
set osd_stat_max_spd = OFF
set max7456_spi_bus = 2
set pinio_config = 129,1,1,1
set pinio_box = 0,255,255,255
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_2_spibus = 1
set gyro_2_sensor_align = CW90
set gyro_2_align_yaw = 900

*/
