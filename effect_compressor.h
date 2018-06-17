#ifndef PAULSTOFFREGEN_EFFECT_COMPRESSOR_H
#define PAULSTOFFREGEN_EFFECT_COMPRESSOR_H

#include <Arduino.h>
#include "AudioStream.h"

class AudioEffectCompressor : public AudioStream {
public:
    AudioEffectCompressor() : AudioStream(1, inputQueueArray) { }
    virtual void update(void);
private:
    int16_t _threshold = 0x08FF;
    audio_block_t *inputQueueArray[1];
};

#endif //PAULSTOFFREGEN_EFFECT_COMPRESSOR_H
