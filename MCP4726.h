/**************************************************************************/
/*!
    @file     MCP4726.h
*/
/**************************************************************************/

#ifndef _MCP4726_H_
#define _MCP4726_H_

#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

// Programmable Gain definitions
#define MCP4726_GAIN_1X 0x00
#define MCP4726_GAIN_2X 0x01

// Reference Voltage definitions
#define MCP4726_VREF_VDD 0x00
#define MCP4726_VREF_VREFPIN 0x10
#define MCP4726_VREF_VREFPIN_BUFFERED 0x18

#define MCP4726_I2CADDR_DEFAULT (0x60) ///< Default i2c address
#define MCP4726_CMD_WRITEDAC (0x40)    ///< Writes data to the DAC
#define MCP4726_CMD_WRITEDACEEPROM \
  (0x60) ///< Writes data to the DAC and the EEPROM (persisting the assigned
         ///< value after reset)

/**************************************************************************/
/*!
    @brief  Class for communicating with an MCP4726 DAC
*/
/**************************************************************************/
class MCP4726
{
public:
  MCP4726();
  bool begin(uint8_t i2c_address = MCP4726_I2CADDR_DEFAULT,
             TwoWire *wire = &Wire);
  void configure(uint8_t config);
  bool setVoltage(uint16_t output, bool writeEEPROM,
                  uint32_t dac_frequency = 400000);

private:
  Adafruit_I2CDevice *i2c_dev = NULL;
  uint8_t config = MCP4726_VREF_VDD;
};

#endif
