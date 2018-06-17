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

MIDI_CREATE_DEFAULT_INSTANCE();
using namespace midi;

//#define ENABLE_MEM_TEST // uncomment this line and 'Save As' to a new location to test the SPI memory

using namespace BAGuitar;


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=87,102
AudioFilterStateVariable filter1;        //xy=254,119
AudioFilterStateVariable filter2;        //xy=272,254
AudioEffectCompressor    compressor2;    //xy=438,168
AudioEffectCompressor    compressor1;    //xy=440,106
AudioEffectCompressor    compressor5;    //xy=440,382
AudioEffectCompressor    compressor6;    //xy=443,437
AudioEffectCompressor    compressor3;    //xy=444,225
AudioEffectCompressor    compressor4;    //xy=447,336
AudioMixer4              mixer2;         //xy=608,359
AudioMixer4              mixer1;         //xy=610,149
AudioOutputI2S           i2s2;           //xy=740,266
AudioConnection          patchCord1(i2s1, 0, filter1, 0);
AudioConnection          patchCord2(i2s1, 1, filter2, 0);
AudioConnection          patchCord3(filter1, 0, compressor1, 0);
AudioConnection          patchCord4(filter1, 1, compressor2, 0);
AudioConnection          patchCord5(filter1, 2, compressor3, 0);
AudioConnection          patchCord6(filter2, 0, compressor4, 0);
AudioConnection          patchCord7(filter2, 1, compressor5, 0);
AudioConnection          patchCord8(filter2, 2, compressor6, 0);
AudioConnection          patchCord9(compressor2, 0, mixer1, 1);
AudioConnection          patchCord10(compressor1, 0, mixer1, 0);
AudioConnection          patchCord11(compressor5, 0, mixer2, 1);
AudioConnection          patchCord12(compressor6, 0, mixer2, 2);
AudioConnection          patchCord13(compressor3, 0, mixer1, 2);
AudioConnection          patchCord14(compressor4, 0, mixer2, 0);
AudioConnection          patchCord15(mixer2, 0, i2s2, 1);
AudioConnection          patchCord16(mixer1, 0, i2s2, 0);
// GUItool: end automatically generated code


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
