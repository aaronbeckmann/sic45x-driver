// This file was generated by the generateApi.js, do not edit it manually.
// Change the pmbusConfig in generateApi.js and call node generateApi.js to
// regenerate this file.

#ifndef SIC45X_H_
#define SIC45X_H_

#include <Wire.h>
#include <stdint.h>

#include "smbus.h"

#define SIC45X_OPERATION_CMD 0x01
// Output is disabled
#define SIC45X_OPERATION_ON_OFF_DISABLED 0x0 << 7
// Output is enabled
#define SIC45X_OPERATION_ON_OFF_ENABLED 0x1 << 7
// Output is turned off immediately and power off sequence commands ignored
#define SIC45X_OPERATION_OFF_B_IMMEDIATE 0x0 << 6
// Regulator turns off following the TOFF_DELAY and TOFF_FALL command
#define SIC45X_OPERATION_OFF_B_DELAYED 0x1 << 6
// Output voltage is set by the PMBus VOUT_COMMAND data
#define SIC45X_OPERATION_MARGIN_COMMAND 0x00 << 4
// Output voltage is set by the PMBus VOUT_MARGIN_LOW data
#define SIC45X_OPERATION_MARGIN_LOW 0x01 << 4
// Output voltage is set by the PMBus VOUT_MARGIN_HIGH data
#define SIC45X_OPERATION_MARGIN_HIGH 0x02 << 4
// Not supported
#define SIC45X_OPERATION_MARGIN_NOT_SUPPORTED 0x03 << 4
// Not supported
#define SIC45X_OPERATION_MRGNFLT_NOT_SUPPORTED_1 0x00 << 2
// Faults caused by selecting VOUT_MARGIN_HIGH or VOUT_MARGIN_LOW as the nominal
// output voltage source are ignored
#define SIC45X_OPERATION_MRGNFLT_IGNORE 0x01 << 2
// Faults caused by selecting VOUT_MARGIN_HIGH or VOUT_MARGIN_LOW as the nominal
// output voltage source are acted upon according to the settings of the
// VOUT_OV_FAULT_RESPONSE and VOUT_UV_FAULT_RESPONSE
#define SIC45X_OPERATION_MRGNFLT_FOLLOW 0x02 << 2
// Not supported
#define SIC45X_OPERATION_MRGNFLT_NOT_SUPPORTED_2 0x03 << 2
#define SIC45X_ON_OFF_CONFIGURATION_CMD 0x02
// Regulator powers up any time power is present regardless of state of the EN
// pin
#define SIC45X_ON_OFF_CONFIGURATION_PU_POWER 0x0 << 4
// Regulator does not power up until commanded by the CONTROLEN pin and
// OPERATION command
#define SIC45X_ON_OFF_CONFIGURATION_PU_COMMAND 0x1 << 4
// Regulator ignores the "on" bit in the OPERATION command
#define SIC45X_ON_OFF_CONFIGURATION_CMD_IGNORE 0x0 << 3
// Regulator responds the "on" bit in the OPERATION command
#define SIC45X_ON_OFF_CONFIGURATION_CMD_RESPOND 0x1 << 3
// Regulator ignores the EN pin. Power conversion is controlled only by the
// OPERATION command
#define SIC45X_ON_OFF_CONFIGURATION_EN_IGNORE 0x0 << 2
// Regulator requires the EN pin to be asserted to start the unit
#define SIC45X_ON_OFF_CONFIGURATION_EN_REQUIRE 0x1 << 2
// EN signal is active low
#define SIC45X_ON_OFF_CONFIGURATION_ENPOL_LOW 0x0 << 1
// EN signal is active high
#define SIC45X_ON_OFF_CONFIGURATION_ENPOL_HIGH 0x1 << 1
// Regulator turns off following the t OFF_DELAY and t OFF_FALL command when EN
// signal is used to turn off
#define SIC45X_ON_OFF_CONFIGURATION_OFFB1_DELAYED 0x0 << 0
// Regulator turns off immediately
#define SIC45X_ON_OFF_CONFIGURATION_OFFB1_IMMEDIATE 0x1 << 0
#define SIC45X_CLEAR_FAULTS_CMD 0x03
#define SIC45X_WRITE_PROTECT_CMD 0x10
// Enable writes to all commands
#define SIC45X_WRITE_PROTECT_WTPRT_ALL 0x000 << 5
// Disable all writes except to the WRITE_PROTECT command
#define SIC45X_WRITE_PROTECT_WTPRT_PROTECTED 0x004 << 5
// Disable all writes except to the WRITE_PROTECT and OPERATION commands
#define SIC45X_WRITE_PROTECT_WTPRT_OPERATION_COMMAND 0x002 << 5
// Disable all writes except to the WRITE_PROTECT, OPERATION, ON_OFF_CONFIG and
// VOUT_COMMAND commands
#define SIC45X_WRITE_PROTECT_WTPRT_ON_OFF_VOUT 0x001 << 5
#define SIC45X_STORE_USER_ALL_CMD 0x15
#define SIC45X_RESTORE_USER_ALL_CMD 0x16
#define SIC45X_CAPABILITY_CMD 0x19
// Packet error checking is supported
#define SIC45X_CAPABILITY_PEC_SUPPORTED 0x1 << 7
// Maximum supported bus speed is 1 MHz
#define SIC45X_CAPABILITY_SPD_M1 0x02 << 5
// The unit has ALERT# pin and supports PMBus alert response protocol
#define SIC45X_CAPABILITY_ALRT_SUPPORTED 0x1 << 4
// Numeric data is in LINEAR11, LINEAR16, or DIRECT format
#define SIC45X_CAPABILITY_NFMT_L11_L16_DIRECT 0x1 << 3
// AVSBUS not supported
#define SIC45X_CAPABILITY_AVS_NOT_SUPPORTED 0x1 << 3
#define SIC45X_VOUT_MODE_CMD 0x20
#define SIC45X_VOUT_COMMAND_CMD 0x21
#define SIC45X_VOUT_MAX_CMD 0x24
#define SIC45X_VOUT_MARGIN_HIGH_CMD 0x25
#define SIC45X_VOUT_MARGIN_LOW_CMD 0x26
#define SIC45X_VOUT_TRANSITION_RATE_CMD 0x27
#define SIC45X_VOUT_TRANSITION_RATE_EXP -4
#define SIC45X_VOUT_SCALE_LOOP_CMD 0x29
#define SIC45X_VOUT_SCALE_LOOP_EXP -3
#define SIC45X_FREQUENCY_SWITCH_CMD 0x33
#define SIC45X_FREQUENCY_SWITCH_EXP 0
#define SIC45X_VIN_ON_CMD 0x35
#define SIC45X_VIN_ON_EXP -1
#define SIC45X_VIN_OFF_CMD 0x36
#define SIC45X_VIN_OFF_EXP -1
#define SIC45X_INTERLEAVE_CMD 0x37
// The RT/SYNC pin shall not be used for other purposes
#define SIC45X_INTERLEAVE_MODE_STANDALONE 0x0000000000000000 << 0
// After inside power VDD of the unit is above its under voltage level, the
// RT/SYNC pin will output a 50% duty cycle pulse signal in phase with the
// switching frequency, which may be used to drive other units set as the SLAVE
// mode by INTERLEAVE command
#define SIC45X_INTERLEAVE_MODE_MASTER 0x0000000000000100 << 0
// When an external pulse switching signal is connected to the /SYNC pin, the
// unit will synchronize its switching frequency to the external pulse switching
// signal with 0º phase difference
#define SIC45X_INTERLEAVE_MODE_SLAVE_IN_PHASE 0x0000000000000120 << 0
// When an external pulse switching signal is connected to the /SYNC pin, the
// unit will synchronize its switching frequency to the external pulse switching
// signal with 180º phase difference
#define SIC45X_INTERLEAVE_MODE_SLAVE_OUT_OF_PHASE 0x0000000000000121 << 0
#define SIC45X_VOUT_OV_FAULT_LIMIT_CMD 0x40
#define SIC45X_VOUT_OV_FAULT_RESPONSE_CMD 0x41
// The PMBus device continues operation without interruption
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVRSP_CONTINUE 0x00 << 6
// The device's output is disabled while the fault is present. Operation resumes
// and the output is enabled when the fault condition no longer exists.
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVRSP_DISABLED_WHILE_FAULTY 0x03 << 6
// Unit does not attempt to restart. The output remains disabled until the fault
// is cleared
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVRTY_NO_RESTART 0x000 << 3
// 2 attempts to restart
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVRTY_RETRIES_2 0x002 << 3
// 4 attempts to restart
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVRTY_RETRIES_4 0x004 << 3
// 6 attempts to restart
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVRTY_RETRIES_6 0x006 << 3
// The device attempts to restart continuously
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVRTY_RETRIES 0x007 << 3
// No delay
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVDLY_NO_DELAY 0x000 << 0
// 2 time units delay
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVDLY_DELAY_2 0x002 << 0
// 6 time units delay
#define SIC45X_VOUT_OV_FAULT_RESPONSE_OVDLY_DELAY_6 0x006 << 0
#define SIC45X_VOUT_OV_WARN_LIMIT_CMD 0x42
#define SIC45X_VOUT_UV_WARN_LIMIT_CMD 0x43
#define SIC45X_VOUT_UV_FAULT_LIMIT_CMD 0x44
#define SIC45X_VOUT_UV_FAULT_RESPONSE_CMD 0x45
// The device continues operation without interruption
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVRSP_CONTINUE 0x00 << 6
// The device shuts down (disables the output) and responds according to the
// UVRTY setting
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVRSP_RETRY 0x02 << 6
// The device's output is disabled while the fault is present. Operation resumes
// and the output is enabled when the fault condition no longer exists.
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVRSP_DISABLED_WHILE_FAULTY 0x03 << 6
// Unit does not attempt to restart. The output remains disabled until the fault
// is cleared
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVRTY_NO_RESTART 0x000 << 3
// 1 attempt to restart
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVRTY_RETRIES_1 0x002 << 3
// 2 attempts to restart
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVRTY_RETRIES_2 0x002 << 3
// 6 attempts to restart
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVRTY_RETRIES_6 0x006 << 3
// The device attempts to restart continuously
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVRTY_RETRIES 0x007 << 3
// No delay
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVDLY_NO_DELAY 0x000 << 0
// 2 time units delay
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVDLY_DELAY_2 0x002 << 0
// 6 time units delay
#define SIC45X_VOUT_UV_FAULT_RESPONSE_UVDLY_DELAY_6 0x006 << 0
#define SIC45X_IOUT_OC_FAULT_LIMIT_CMD 0x46
#define SIC45X_IOUT_OC_FAULT_LIMIT_EXP -1
#define SIC45X_IOUT_OC_FAULT_RESPONSE_CMD 0x47
// The device continues operation without interruption
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCRSP_CONTINUE 0x00 << 6
// The device shuts down (disables the output) and responds according to the
// UVRTY setting
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCRSP_RETRY 0x02 << 6
// The device's output is disabled while the fault is present. Operation resumes
// and the output is enabled when the fault condition no longer exists.
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCRSP_DISABLED_WHILE_FAULTY 0x03 << 6
// Unit does not attempt to restart. The output remains disabled until the fault
// is cleared
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCRTY_NO_RESTART 0x000 << 3
// 2 attempts to restart
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCRTY_RETRIES_2 0x002 << 3
// 4 attempts to restart
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCRTY_RETRIES_4 0x004 << 3
// 6 attempts to restart
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCRTY_RETRIES_6 0x006 << 3
// The device attempts to restart continuously
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCRTY_RETRIES 0x007 << 3
// No delay
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCDLY_NO_DELAY 0x000 << 0
// 2 time units delay
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCDLY_DELAY_2 0x002 << 0
// 6 time units delay
#define SIC45X_IOUT_OC_FAULT_RESPONSE_OCDLY_DELAY_6 0x006 << 0
#define SIC45X_IOUT_OC_WARN_LIMIT_CMD 0x4a
#define SIC45X_IOUT_OC_WARN_LIMIT_EXP -1
#define SIC45X_OT_FAULT_LIMIT_CMD 0x4f
#define SIC45X_OT_FAULT_LIMIT_EXP 0
#define SIC45X_OT_FAULT_RESPONSE_CMD 0x50
// The device continues operation without interruption
#define SIC45X_OT_FAULT_RESPONSE_OTRSP_CONTINUE 0x00 << 6
// The device shuts down (disables the output) and responds according to the
// retry setting
#define SIC45X_OT_FAULT_RESPONSE_OTRSP_RETRY 0x02 << 6
// The device's output is disabled while the fault is present. Operation resumes
// and the output is enabled when the fault condition no longer exists.
#define SIC45X_OT_FAULT_RESPONSE_OTRSP_DISABLED_WHILE_FAULTY 0x03 << 6
// Unit does not attempt to restart. The output remains disabled until the fault
// is cleared
#define SIC45X_OT_FAULT_RESPONSE_OTRTY_NO_RESTART 0x000 << 3
// 2 attempts to restart
#define SIC45X_OT_FAULT_RESPONSE_OTRTY_RETRIES_2 0x002 << 3
// 4 attempts to restart
#define SIC45X_OT_FAULT_RESPONSE_OTRTY_RETRIES_4 0x004 << 3
// 6 attempts to restart
#define SIC45X_OT_FAULT_RESPONSE_OTRTY_RETRIES_6 0x006 << 3
// The device attempts to restart continuously
#define SIC45X_OT_FAULT_RESPONSE_OTRTY_RETRIES 0x007 << 3
// No delay
#define SIC45X_OT_FAULT_RESPONSE_OTDLY_NO_DELAY 0x000 << 0
// 1 time unit delay
#define SIC45X_OT_FAULT_RESPONSE_OTDLY_DELAY_1 0x001 << 0
// 2 time units delay
#define SIC45X_OT_FAULT_RESPONSE_OTDLY_DELAY_2 0x002 << 0
// 6 time units delay
#define SIC45X_OT_FAULT_RESPONSE_OTDLY_DELAY_6 0x006 << 0
#define SIC45X_OT_WARN_LIMIT_CMD 0x51
#define SIC45X_OT_WARN_LIMIT_EXP 0
#define SIC45X_VIN_OV_FAULT_LIMIT_CMD 0x55
#define SIC45X_VIN_OV_FAULT_LIMIT_EXP -1
#define SIC45X_VIN_OV_FAULT_RESPONSE_CMD 0x56
// The device continues operation without interruption
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVRSP_CONTINUE 0x00 << 6
// The device's output is disabled while the fault is present. Operation resumes
// and the output is enabled when the fault condition no longer exists.
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVRSP_DISABLED_WHILE_FAULTY 0x03 << 6
// Unit does not attempt to restart. The output remains disabled until the fault
// is cleared
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVRTY_NO_RESTART 0x000 << 3
// 2 attempts to restart
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVRTY_RETRIES_2 0x002 << 3
// 4 attempts to restart
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVRTY_RETRIES_4 0x004 << 3
// 6 attempts to restart
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVRTY_RETRIES_6 0x006 << 3
// The device attempts to restart continuously
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVRTY_RETRIES 0x007 << 3
// No delay
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVDLY_NO_DELAY 0x000 << 0
// 2 time units delay
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVDLY_DELAY_2 0x002 << 0
// 6 time units delay
#define SIC45X_VIN_OV_FAULT_RESPONSE_OVDLY_DELAY_6 0x006 << 0
#define SIC45X_VIN_UV_WARN_LIMIT_CMD 0x58
#define SIC45X_VIN_UV_WARN_LIMIT_EXP -1
#define SIC45X_IIN_OC_WARN_LIMIT_CMD 0x5d
#define SIC45X_IIN_OC_WARN_LIMIT_EXP -1
#define SIC45X_POWER_GOOD_ON_CMD 0x5e
#define SIC45X_POWER_GOOD_OFF_CMD 0x5f
#define SIC45X_TON_DELAY_CMD 0x60
#define SIC45X_TON_DELAY_EXP 0
#define SIC45X_TON_RISE_CMD 0x61
#define SIC45X_TON_RISE_EXP 0
#define SIC45X_TON_MAX_FAULT_LIMIT_CMD 0x62
#define SIC45X_TON_MAX_FAULT_LIMIT_EXP 0
#define SIC45X_TON_MAX_FAULT_RESPONSE_CMD 0x63
// The device shuts down (disables the output) and responds according to the
// retry setting
#define SIC45X_TON_MAX_FAULT_RESPONSE_ONMXRSP_RETRY 0x02 << 6
// Unit does not attempt to restart. The output remains disabled until the fault
// is cleared
#define SIC45X_TON_MAX_FAULT_RESPONSE_ONMXRTY_NO_RESTART 0x000 << 3
// 1 attempt to restart
#define SIC45X_TON_MAX_FAULT_RESPONSE_ONMXRTY_RETRIES_1 0x001 << 3
// The device attempts to restart continuously
#define SIC45X_TON_MAX_FAULT_RESPONSE_ONMXRTY_RETRIES 0x007 << 3
// No delay
#define SIC45X_TON_MAX_FAULT_RESPONSE_ONMXDLY_NO_DELAY 0x000 << 0
// 1 time unit delay
#define SIC45X_TON_MAX_FAULT_RESPONSE_ONMXDLY_DELAY_1 0x001 << 0
// 2 time units delay
#define SIC45X_TON_MAX_FAULT_RESPONSE_ONMXDLY_DELAY_2 0x002 << 0
// 3 time units delay
#define SIC45X_TON_MAX_FAULT_RESPONSE_ONMXDLY_DELAY_3 0x003 << 0
// 6 time units delay
#define SIC45X_TON_MAX_FAULT_RESPONSE_ONMXDLY_DELAY_6 0x006 << 0
#define SIC45X_TOFF_DELAY_CMD 0x64
#define SIC45X_TOFF_DELAY_EXP 0
#define SIC45X_TOFF_FALL_CMD 0x65
#define SIC45X_TOFF_FALL_EXP 0
#define SIC45X_TOFF_MAX_WARN_LIMIT_CMD 0x66
#define SIC45X_TOFF_MAX_WARN_LIMIT_EXP 0
#define SIC45X_STATUS_BYTE_CMD 0x78
#define SIC45X_STATUS_BYTE_BUSY_NO_FAULT 0x0 << 7
// A fault was declared because the device was busy and unable to respond
#define SIC45X_STATUS_BYTE_BUSY_FAULT 0x1 << 7
#define SIC45X_STATUS_BYTE_OFF_NO_FAULT 0x0 << 6
// This bit is asserted if the unit is not providing power to the output,
// regardless of the reason, including simply not being enabled
#define SIC45X_STATUS_BYTE_OFF_FAULT 0x1 << 6
#define SIC45X_STATUS_BYTE_VOUT_OV_FAULT_NO_FAULT 0x0 << 5
// An output overvoltage fault has occurred
#define SIC45X_STATUS_BYTE_VOUT_OV_FAULT_FAULT 0x1 << 5
#define SIC45X_STATUS_BYTE_IOUT_UV_FAULT_NO_FAULT 0x0 << 4
// An output overcurrent fault has occurred
#define SIC45X_STATUS_BYTE_IOUT_UV_FAULT_FAULT 0x1 << 4
#define SIC45X_STATUS_BYTE_VIN_UV_FAULT_NO_FAULT 0x0 << 3
// An input undervoltage fault has occurred
#define SIC45X_STATUS_BYTE_VIN_UV_FAULT_FAULT 0x1 << 3
#define SIC45X_STATUS_BYTE_TEMPERATURE_NO_FAULT 0x0 << 2
// A temperature fault or warning has occurred
#define SIC45X_STATUS_BYTE_TEMPERATURE_FAULT 0x1 << 2
#define SIC45X_STATUS_BYTE_CML_NO_FAULT 0x0 << 1
// A communications, memory or logic fault has occurred
#define SIC45X_STATUS_BYTE_CML_FAULT 0x1 << 1
#define SIC45X_STATUS_BYTE_OTHER_NO_FAULT 0x0 << 0
// A fault or warning not listed in bits (7 to 1) has occurred
#define SIC45X_STATUS_BYTE_OTHER_FAULT 0x1 << 0
#define SIC45X_STATUS_WORD_CMD 0x79
#define SIC45X_STATUS_WORD_BUSY_NO_FAULT 0x0 << 15
// A fault was declared because the device was busy and unable to respond
#define SIC45X_STATUS_WORD_BUSY_FAULT 0x1 << 15
#define SIC45X_STATUS_WORD_OFF_NO_FAULT 0x0 << 14
// This bit is asserted if the unit is not providing power to the output,
// regardless of the reason, including simply not being enabled
#define SIC45X_STATUS_WORD_OFF_FAULT 0x1 << 14
#define SIC45X_STATUS_WORD_VOUT_OV_FAULT_NO_FAULT 0x0 << 13
// An output overvoltage fault has occurred
#define SIC45X_STATUS_WORD_VOUT_OV_FAULT_FAULT 0x1 << 13
#define SIC45X_STATUS_WORD_IOUT_UV_FAULT_NO_FAULT 0x0 << 12
// An output overcurrent fault has occurred
#define SIC45X_STATUS_WORD_IOUT_UV_FAULT_FAULT 0x1 << 12
#define SIC45X_STATUS_WORD_VIN_UV_FAULT_NO_FAULT 0x0 << 11
// An input undervoltage fault has occurred
#define SIC45X_STATUS_WORD_VIN_UV_FAULT_FAULT 0x1 << 11
#define SIC45X_STATUS_WORD_TEMPERATURE_NO_FAULT 0x0 << 10
// A temperature fault or warning has occurred
#define SIC45X_STATUS_WORD_TEMPERATURE_FAULT 0x1 << 10
#define SIC45X_STATUS_WORD_CML_NO_FAULT 0x0 << 9
// A communications, memory or logic fault has occurred
#define SIC45X_STATUS_WORD_CML_FAULT 0x1 << 9
#define SIC45X_STATUS_WORD_OTHER_NO_FAULT 0x0 << 8
// A fault or warning not listed in bits (7 to 1) has occurred
#define SIC45X_STATUS_WORD_OTHER_FAULT 0x1 << 8
#define SIC45X_STATUS_WORD_VOUT_NO_FAULT 0x0 << 7
// An output voltage fault or warning has occurred
#define SIC45X_STATUS_WORD_VOUT_FAULT 0x1 << 7
#define SIC45X_STATUS_WORD_IOUT_POUT_NO_FAULT 0x0 << 6
// An output current or output power fault or warning has occurred
#define SIC45X_STATUS_WORD_IOUT_POUT_FAULT 0x1 << 6
#define SIC45X_STATUS_WORD_INPUT_NO_FAULT 0x0 << 5
// An input voltage, input current, or input power fault or warning has occurred
#define SIC45X_STATUS_WORD_INPUT_FAULT 0x1 << 5
#define SIC45X_STATUS_WORD_MFR_NO_FAULT 0x0 << 4
// A manufacturer specific fault or warning has occurred
#define SIC45X_STATUS_WORD_MFR_FAULT 0x1 << 4
#define SIC45X_STATUS_WORD_POWER_GOOD_NO_FAULT 0x0 << 3
// The power good signal, if present, is negated
#define SIC45X_STATUS_WORD_POWER_GOOD_FAULT 0x1 << 3
#define SIC45X_STATUS_VOUT_CMD 0x7a
#define SIC45X_STATUS_VOUT_VOUT_OV_FAULT_NO_FAULT 0x0 << 7
// VOUT OV fault (output overvoltage fault)
#define SIC45X_STATUS_VOUT_VOUT_OV_FAULT_FAULT 0x1 << 7
#define SIC45X_STATUS_VOUT_VOUT_OV_WARNING_NO_WARNING 0x0 << 6
// VOUT OV warning (output overvoltage warning)
#define SIC45X_STATUS_VOUT_VOUT_OV_WARNING_WARNING 0x1 << 6
#define SIC45X_STATUS_VOUT_VOUT_UV_WARNING_NO_WARNING 0x0 << 5
// VOUT UV warning (output undervoltage warning)
#define SIC45X_STATUS_VOUT_VOUT_UV_WARNING_WARNING 0x1 << 5
#define SIC45X_STATUS_VOUT_VOUT_UV_FAULT_NO_FAULT 0x0 << 4
// VOUT UV fault (output undervoltage fault)
#define SIC45X_STATUS_VOUT_VOUT_UV_FAULT_FAULT 0x1 << 4
#define SIC45X_STATUS_VOUT_VOUT_MAX_MIN_NO_FAULT 0x0 << 3
// V OUT max. min. (an attempt has been made to set the output voltage toa value
// higher than allowed by the V OUT max. or lower than the limited allowed by
// the VOUT min.)
#define SIC45X_STATUS_VOUT_VOUT_MAX_MIN_FAULT 0x1 << 3
#define SIC45X_STATUS_VOUT_TON_MAX_FAULT_NO_FAULT 0x0 << 2
// tON max fault
#define SIC45X_STATUS_VOUT_TON_MAX_FAULT_FAULT 0x1 << 2
#define SIC45X_STATUS_VOUT_TOFF_MAX_WARNING_NO_WARNING 0x0 << 1
// tOFF max warning
#define SIC45X_STATUS_VOUT_TOFF_MAX_WARNING_WARNING 0x1 << 1
#define SIC45X_STATUS_IOUT_CMD 0x7b
#define SIC45X_STATUS_IOUT_IOUT_OC_FAULT_NO_FAULT 0x0 << 7
// IOUT OC fault (output overcurrent fault)
#define SIC45X_STATUS_IOUT_IOUT_OC_FAULT_FAULT 0x1 << 7
#define SIC45X_STATUS_IOUT_IOUT_OC_WARNING_NO_WARNING 0x0 << 5
// IOUT OC warning (output overcurrent warning)
#define SIC45X_STATUS_IOUT_IOUT_OC_WARNING_WARNING 0x1 << 5
#define SIC45X_STATUS_INPUT_CMD 0x7c
#define SIC45X_STATUS_INPUT_VIN_OV_FAULT_NO_FAULT 0x0 << 7
// VIN OV fault (input overvoltage fault)
#define SIC45X_STATUS_INPUT_VIN_OV_FAULT_FAULT 0x1 << 7
#define SIC45X_STATUS_INPUT_VIN_UV_WARNING_NO_WARNING 0x0 << 5
// VIN UV warning (input undervoltage warning)
#define SIC45X_STATUS_INPUT_VIN_UV_WARNING_WARNING 0x1 << 5
#define SIC45X_STATUS_INPUT_VIN_OFF_NO_FAULT 0x0 << 3
// Unit off for insufficient input voltage
#define SIC45X_STATUS_INPUT_VIN_OFF_FAULT 0x1 << 3
#define SIC45X_STATUS_INPUT_IIN_OC_WARNING_NO_WARNING 0x0 << 1
// IIN OC warning (input overcurrent warning)
#define SIC45X_STATUS_INPUT_IIN_OC_WARNING_WARNING 0x1 << 1
#define SIC45X_STATUS_TEMPERATURE_CMD 0x7d
#define SIC45X_STATUS_TEMPERATURE_OT_FAULT_NO_FAULT 0x0 << 7
// OT fault (overtemperature fault)
#define SIC45X_STATUS_TEMPERATURE_OT_FAULT_FAULT 0x1 << 7
#define SIC45X_STATUS_TEMPERATURE_OT_WARNING_NO_WARNING 0x0 << 6
// OT warning (overtemperature warning)
#define SIC45X_STATUS_TEMPERATURE_OT_WARNING_WARNING 0x1 << 6
#define SIC45X_STATUS_CML_CMD 0x7e
#define SIC45X_STATUS_CML_INVALID_COMMAND_NO_FAULT 0x0 << 7
// Invalid or unsupported command received
#define SIC45X_STATUS_CML_INVALID_COMMAND_FAULT 0x1 << 7
#define SIC45X_STATUS_CML_INVALID_DATA_NO_FAULT 0x0 << 6
// Invalid or unsupported data received
#define SIC45X_STATUS_CML_INVALID_DATA_FAULT 0x1 << 6
#define SIC45X_STATUS_CML_PEC_FAILED_NO_FAULT 0x0 << 5
// Packet error check failed
#define SIC45X_STATUS_CML_PEC_FAILED_FAULT 0x1 << 5
#define SIC45X_STATUS_CML_MEMORY_FAULT_NO_FAULT 0x0 << 4
// Memory fault detected
#define SIC45X_STATUS_CML_MEMORY_FAULT_FAULT 0x1 << 4
#define SIC45X_STATUS_CML_OTHER_NO_FAULT 0x0 << 1
// A communication fault other than the ones listed in this table has occurred
#define SIC45X_STATUS_CML_OTHER_FAULT 0x1 << 1
#define SIC45X_STATUS_MFR_SPECIFIC_CMD 0x80
#define SIC45X_STATUS_MFR_SPECIFIC_IL_MASTER_NO_FAULT 0x0 << 3
// IL master fault
#define SIC45X_STATUS_MFR_SPECIFIC_IL_MASTER_FAULT 0x1 << 3
#define SIC45X_STATUS_MFR_SPECIFIC_YF_VERIFY_NO_FAULT 0x0 << 2
// YF verify fault
#define SIC45X_STATUS_MFR_SPECIFIC_YF_VERIFY_FAULT 0x1 << 2
#define SIC45X_STATUS_MFR_SPECIFIC_YF_ERASE_NO_FAULT 0x0 << 1
// YF erase fault
#define SIC45X_STATUS_MFR_SPECIFIC_YF_ERASE_FAULT 0x1 << 1
#define SIC45X_STATUS_MFR_SPECIFIC_YF_PGM_NO_FAULT 0x0 << 0
// YF PGM fault
#define SIC45X_STATUS_MFR_SPECIFIC_YF_PGM_FAULT 0x1 << 0
#define SIC45X_READ_VIN_CMD 0x88
#define SIC45X_READ_IIN_CMD 0x89
#define SIC45X_READ_VOUT_CMD 0x8b
#define SIC45X_READ_IOUT_CMD 0x8c
#define SIC45X_READ_TEMPERATURE_CMD 0x8d
#define SIC45X_READ_DUTY_CYCLE_CMD 0x94
#define SIC45X_READ_POUT_CMD 0x96
#define SIC45X_READ_PIN_CMD 0x97
#define SIC45X_PMBUS_REVISION_CMD 0x98
#define SIC45X_PMBUS_REVISION_PART_1_REVISION_1_0 0x0000 << 4
#define SIC45X_PMBUS_REVISION_PART_1_REVISION_1_1 0x0001 << 4
#define SIC45X_PMBUS_REVISION_PART_1_REVISION_1_2 0x0002 << 4
#define SIC45X_PMBUS_REVISION_PART_1_REVISION_1_3 0x0003 << 4
#define SIC45X_PMBUS_REVISION_PART_2_REVISION_1_0 0x0000 << 0
#define SIC45X_PMBUS_REVISION_PART_2_REVISION_1_1 0x0001 << 0
#define SIC45X_PMBUS_REVISION_PART_2_REVISION_1_2 0x0002 << 0
#define SIC45X_PMBUS_REVISION_PART_2_REVISION_1_3 0x0003 << 0
#define SIC45X_MFR_SERIAL_CMD 0x9e
#define SIC45X_IC_DEVICE_ID_CMD 0xad
// Scale loop constants for VOUT ranges
#define SIC45X_VOUT_SCALE_LOOP_0V3_1V8 1.0
#define SIC45X_VOUT_SCALE_LOOP_1V8_3V3 0.5
#define SIC45X_VOUT_SCALE_LOOP_3V3_5V0 0.25
#define SIC45X_VOUT_SCALE_LOOP_5V0_12V0 0.125

class SiC45x {
  Smbus smbus_;
  float l16ToFloat(uint16_t inputVal);
  uint16_t floatToL16(float inputVal);

 public:
  SiC45x();
  SiC45x(uint8_t i2cAddress);
  SiC45x(uint8_t i2cAddress, TwoWire& wire);

  bool begin(uint8_t i2cAddress, TwoWire& wire);
  bool begin();

  // The OPERATION command sets the operational state of the regulator.
  uint8_t getOperation();
  String printOperation();
  void setOperation(uint8_t value);
  // The ON_OFF_CONFIG command configures the combination of EN pin input and
  // PMBus commands needed to turn the unit on and off. This includes how the unit
  // responds when power is applied.
  uint8_t getOnOffConfiguration();
  String printOnOffConfiguration();
  void setOnOffConfiguration(uint8_t value);
  // The CLEAR_FAULTS command is used to clear any fault bits that have been set
  void sendClearFaults();
  // The WRITE_PROTECT command is used to control writing to the PMBus device
  void setWriteProtect(uint8_t value);
  // The STORE_USER_ALL command instructs the PMBus device to copy the entire
  // contents of the operating memory to the matching locations in the
  // non-volatile User Store memory.
  void sendStoreUserAll();
  // The RESTORE_USER_ALL command instructs the PMBus device to copy the entire
  // contents of the nonvolatile user store memory (NVM) to the matching locations
  // in the operating memory.
  void sendRestoreUserAll();
  // The CAPABILITY command provides a way for a host system to determine some key
  // capabilities of the PMBus device.
  uint8_t getCapability();
  String printCapability();
  // The PMBus specification dictates that the data word for the V OUT_MODE
  // command is one byte that consists of a 3-bit mode and 5-bit exponent
  // parameter, as shown below. The 3-bit mode sets whether the device uses the
  // linear or direct modes for output voltage related commands. The 5-bit
  // parameter sets the exponent value for the linear data mode. The mode and
  // exponent parameters are fixed and do not permit the user to change the
  // values.
  float getVoutMode();
  // The VOUT_COMMAND is used to directly set the output voltage
  float getVoutCommand();
  void setVoutCommand(float value);
  // The VOUT_MAX command sets an upper limit on the output voltage the unit can
  // command regardless of any other commands or combinations
  float getVoutMax();
  void setVoutMax(float value);
  // The VOUT_MARGIN_HIGH command loads the unit with the voltage to which the
  // output is to be changed when the OPERATION command is set to "margin high"
  float getVoutMarginHigh();
  void setVoutMarginHigh(float value);
  // The VOUT_MARGIN_LOW command loads the unit with the voltage to which the
  // output is to be changed when the OPERATION command is set to margin low
  float getVoutMarginLow();
  void setVoutMarginLow(float value);
  // The VOUT_TRANSITION_RATE command sets the rate in mV/μs at which the output
  // voltage should change voltage when a PMBus device receives either a
  // VOUT_COMMAND or OPERATION (margin high, margin low) that causes the output
  // voltage to change
  float getVoutTransitionRate();
  void setVoutTransitionRate(float value);
  // The VOUT_SCALE_LOOP command is used to scale down both the VOUT_COMMAND and
  // the sense differential output voltage at the unit input, so as to extend
  // operational range of the PMBus unit to reach the maximum output voltage 12 V
  // without the requirement of external resistor divider on board
  float getVoutScaleLoop();
  void setVoutScaleLoop(float value);
  // The FREQUENCY_SWITCH command sets the switching frequency, in kHz, of the
  // PMBus unit
  float getFrequencySwitch();
  void setFrequencySwitch(float value);
  // The VIN_ON command sets the value of the input voltage, in volt, at which the
  // PMBus unit should start power conversion
  float getVinOn();
  void setVinOn(float value);
  // The VIN_OFF command sets the value of the input voltage, in volt, at which
  // the PMBus unit, once operation has started, should stop power conversion
  float getVinOff();
  void setVinOff(float value);
  // The INTERLEAVE command is used to sets the mode of switching frequency and
  // phase, at which the PMBus unit, once operation has started, should use to
  // generate switching frequency and phase angle
  uint16_t getInterleave();
  String printInterleave();
  void setInterleave(uint16_t value);
  // The VOUT_OV_FAULT_LIMIT command sets the value of the output voltage measured
  // at the sense of output pins that causes an output overvoltage fault
  float getVoutOvFaultLimit();
  void setVoutOvFaultLimit(float value);
  uint8_t getVoutOvFaultResponse();
  String printVoutOvFaultResponse();
  void setVoutOvFaultResponse(uint8_t value);
  // The VOUT_OV_WARN_LIMIT command sets the value of the output voltage measured
  // at the sense of output pins that causes an output voltage high warning
  float getVoutOvWarnLimit();
  void setVoutOvWarnLimit(float value);
  // The VOUT_UV_WARN_LIMIT command sets the value of the output voltage measured
  // at the sense of output pins that causes an output voltage low warning
  float getVoutUvWarnLimit();
  void setVoutUvWarnLimit(float value);
  // The VOUT_UV_FAULT_LIMIT command sets the value of the output voltage measured
  // at the sense of output pins that causes an output undervoltage fault
  float getVoutUvFaultLimit();
  void setVoutUvFaultLimit(float value);
  // The VOUT_UV_FAULT_RESPONSE command instructs the device on what action to
  // take in response to an output undervoltage fault
  uint8_t getVoutUvFaultResponse();
  String printVoutUvFaultResponse();
  void setVoutUvFaultResponse(uint8_t value);
  // The IOUT_OC_FAULT_LIMIT command sets the value of the output current, in
  // Amperes, that causes the overcurrent detector to indicate an overcurrent
  // fault condition.
  float getIoutOcFaultLimit();
  void setIoutOcFaultLimit(float value);
  // The IOUT_OC_FAULT_RESPONSE is used to set device over current protection
  // response (OCP) when valley inductor current is higher than
  // IOUT_OC_FAULT_LIMIT
  uint8_t getIoutOcFaultResponse();
  String printIoutOcFaultResponse();
  void setIoutOcFaultResponse(uint8_t value);
  // The IOUT_OC_WARN_LIMIT command sets the value of the output current, in
  // ampere, that causes an output overcurrent warning. This is a read and write
  // register
  float getIoutOcWarnLimit();
  void setIoutOcWarnLimit(float value);
  // The OT FAULT LIMIT command sets the temperature of the unit, in degree
  // celsius, at which it should indicate an overtemperature fault. This is a read
  // and write register
  float getOtFaultLimit();
  void setOtFaultLimit(float value);
  // The OT_FAULT_RESPONSE command instructs the device on what action to take in
  // response to an overtemperature fault
  uint8_t getOtFaultResponse();
  String printOtFaultResponse();
  void setOtFaultResponse(uint8_t value);
  // The OT_WARN_LIMIT command sets the temperature of the unit, in degree
  // celsius, at which it should indicate an overtemperature warning alarm
  float getOtWarnLimit();
  void setOtWarnLimit(float value);
  // The VIN_OV_FAULT_LIMIT command sets the value of the input voltage, in volt,
  // that causes an input overvoltage fault
  float getVinOvFaultLimit();
  void setVinOvFaultLimit(float value);
  // The VIN_OV_FAULT_RESPONSE command instructs the device on what action to take
  // in response to an input overvoltage fault
  uint8_t getVinOvFaultResponse();
  String printVinOvFaultResponse();
  void setVinOvFaultResponse(uint8_t value);
  // The VIN_UV_WARN_LIMIT command sets the value of the input voltage, in volt,
  // that causes an input voltage low warning
  float getVinUvWarnLimit();
  void setVinUvWarnLimit(float value);
  // The IIN_OC_WARN_LIMIT command sets the value of the input current, in ampere,
  // that causes an input current overcurrent Warning
  float getIinOcWarnLimit();
  void setIinOcWarnLimit(float value);
  // The POWER_GOOD_ON command sets the value of the output voltage at which an
  // optional power good signal should be asserted, indicating that the output
  // voltage is valid.
  float getPowerGoodOn();
  void setPowerGoodOn(float value);
  // The POWER_GOOD_OFF command sets the value of the output voltage at which an
  // optional power good signal should be negated, indicating that the output
  // voltage is not valid.
  float getPowerGoodOff();
  void setPowerGoodOff(float value);
  // The TON_DELAY command sets the time, in millisecond, from which a start
  // condition is received (as programmed by the ON_OFF_CONFIG command) until the
  // output voltage starts to rise
  float getTonDelay();
  void setTonDelay(float value);
  // The TON_RISE command sets the time, in millisecond, from when the output
  // starts to rise until the voltage has entered the regulation band
  float getTonRise();
  void setTonRise(float value);
  // The TON_MAX_FAULT_LIMIT command sets an upper limit, in millisecond, on how
  // long the unit can attempt to power up the output without reaching the output
  // undervoltage fault limit.
  float getTonMaxFaultLimit();
  void setTonMaxFaultLimit(float value);
  // The TON_MAX_FAULT_RESPONSE command instructs the device on what action to
  // take in response to an input overcurrent fault
  uint8_t getTonMaxFaultResponse();
  String printTonMaxFaultResponse();
  void setTonMaxFaultResponse(uint8_t value);
  // The TOFF_DELAY command sets the time, in millisecond, from when a stop
  // condition is received until the unit stops transferring energy to the output.
  float getToffDelay();
  void setToffDelay(float value);
  // The TOFF_FALL command sets the time, in millisecond, from the end of the
  // turn-off delay time until the voltage is commanded to zero. Note that this
  // command can only be used with a device whose output can sink enough current
  // to cause the output voltage to decrease at a controlled rate
  float getToffFall();
  void setToffFall(float value);
  // The TOFF_MAX_WARN_LIMIT command sets an upper limit, in millisecond, on how
  // long the unit can attempt to power down the output without reaching 12.5 % of
  // the output voltage programmed at the time the unit is turned off.
  float getToffMaxWarnLimit();
  void setToffMaxWarnLimit(float value);
  // The STATUS_BYTE command returns one byte of information with a summary of the
  // most critical faults. 
  uint8_t getStatusByte();
  String printStatusByte();
  // The STATUS_WORD command returns two bytes of information with a summary of
  // the unit’s fault condition. Based on the information in these bytes, the host
  // can get more information by reading the appropriate status registers.
  uint16_t getStatusWord();
  String printStatusWord();
  uint8_t getStatusVout();
  String printStatusVout();
  uint8_t getStatusIout();
  String printStatusIout();
  uint8_t getStatusInput();
  String printStatusInput();
  uint8_t getStatusTemperature();
  String printStatusTemperature();
  uint8_t getStatusCml();
  String printStatusCml();
  uint8_t getStatusMfrSpecific();
  String printStatusMfrSpecific();
  // The READ_VIN command returns the input voltage in volt.
  float getReadVin();
  // The READ_IIN command returns the input current in ampere
  float getReadIin();
  // The read VOUT command returns the actual, measured output voltage in volt.
  float getReadVout();
  // The READ_IOUT command returns the measured output current in ampere.
  float getReadIout();
  // The READ_TEMPERATURE command returns the measured temperature of the PMBus
  // unit in degree celsius.
  float getReadTemperature();
  // The READ_DUTY_CYCLE command returns the duty of the PMBus unit’s power
  // conversion in percent.
  float getReadDutyCycle();
  // The READ_POUT command returns the output power, in watt, of the PMBus unit.
  float getReadPout();
  // The READ_PIN command returns the input power, in watt, of the PMBus unit.
  float getReadPin();
  // The PMBUS_REVISION command stores or reads the revision of the PMBus to which
  // the device is compliant.
  uint8_t getPmbusRevision();
  String printPmbusRevision();
  // The MFR_SERIAL command is used to store user’s customized information.
  uint16_t getMfrSerial();
  void setMfrSerial(uint16_t value);
  // The IC_DEVICE_ID command is used to either set or read the type or part
  // number of an IC embedded within a PMBus that is used for the PMBus interface.
  // Each manufacturer uses the format of their choice for the IC device
  // identification. IC_DEVICE_ID is typically only set once, at the time of
  // manufacture.
  uint16_t getIcDeviceId();
  void setIcDeviceId(uint16_t value);

  String printIfEq(uint16_t value, uint16_t mask, uint16_t flag, const __FlashStringHelper *str);
};

#endif