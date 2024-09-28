/**************************************************************************/
/*! 
    @file     trianglewave.pde
    @author   Adafruit Industries
    @license  BSD (see license.txt)

    This example will generate a triangle wave with the MCP4726 DAC.   

*/
/**************************************************************************/
#include <Wire.h>
#include <MCP4726.h>

MCP4726 dac;

void setup(void) {
  Serial.begin(9600);
  Serial.println("Hello!");

  // Update the I2C address below depending on the version of the chip
  dac.begin(0x62);
    
  Serial.println("Generating a triangle wave");
}

void loop(void) {
    uint32_t counter;
    // Run through the full 12-bit scale for a triangle wave
    for (counter = 0; counter < 4095; counter++)
    {
      dac.setVoltage(counter, false);
    }
    for (counter = 4095; counter > 0; counter--)
    {
      dac.setVoltage(counter, false);
    }
}