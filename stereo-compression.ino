/*************************************************************************
 * This demo uses the BAGuitar library to provide enhanced control of
 * the TGA Pro board.
 * 
 * The latest copy of the BA Guitar library can be obtained from
 * https://github.com/Blackaddr/BAGuitar
 * 
 * This demo will provide an audio passthrough, as well as exercise the
 * MIDI interface.
 * 
 * It can optionally exercise the SPI MEM0 if installed on the TGA Pro board.
 * 
 */
#include <Wire.h>
#include <Audio.h>
#include <MIDI.h>
#include "BAGuitar.h"
#include "effect_compressor.h"

MIDI_CREATE_DEFAULT_INSTANCE();
using namespace midi;

//#define ENABLE_MEM_TEST // uncomment this line and 'Save As' to a new location to test the SPI memory

using namespace BAGuitar;
AudioInputI2S            i2s1;           //xy=178,112
AudioEffectCompressor    compressor1;    //xy=472,108
AudioEffectCompressor    compressor2;    //xy=472,208
AudioOutputI2S           i2s2;           //xy=637,105
AudioConnection          patchCord1(i2s1, 0, compressor1, 0);
AudioConnection          patchCord2(i2s1, 1, compressor2, 0);
AudioConnection          patchCord3(compressor1, 0, i2s2, 0);
AudioConnection          patchCord4(compressor2, 0, i2s2, 1);

BAAudioControlWM8731      codecControl;
BAGpio                    gpio;  // access to User LED

unsigned long t=0;

// SPI stuff
int spiAddress = 0;
int spiData = 0xff;
int spiErrorCount = 0;


void setup() {

  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(57600);
  delay(5);

  // If the codec was already powered up (due to reboot) power itd own first
  codecControl.disable();
  delay(100);
  AudioMemory(24);

  Serial.println("Enabling codec...\n");
  codecControl.enable();
  delay(100);
  
}

void loop() {  


 

  // Toggle the USR LED state
  gpio.toggleLed();
  delay(50);

}
