#ifndef PAULSTOFFREGEN_EFFECT_COMPRESSOR_H
#define PAULSTOFFREGEN_EFFECT_COMPRESSOR_H

#include <Arduino.h>
#include "AudioStream.h"

class AudioEffectCompressor : public AudioStream {
public:
    AudioEffectCompressor() : AudioStream(1, inputQueueArray) { }
    virtual void update(void);
    void setThreshold(uint16_t threshold);
    void setGainReduction(uint8_t gainReduction);
private:
    uint16_t _threshold = 0x5000;
    uint8_t _gainReduction = 3;
    audio_block_t *inputQueueArray[1];
};

#endif //PAULSTOFFREGEN_EFFECT_COMPRESSOR_H
