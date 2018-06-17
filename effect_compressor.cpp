#include "effect_compressor.h"

void AudioEffectCompressor::update(void)
{
    audio_block_t *blocka;
    int16_t *pa;
    int16_t a1;
    
    blocka = receiveWritable(0);
    if (!blocka) {
        return;
    }
    pa = (int16_t *)(blocka->data);
    
    for (uint32_t n = 0; n < AUDIO_BLOCK_SAMPLES; n++) {
        a1 = pa[n];
        
        if (a1 > _threshold) {
            a1 = _threshold + (a1 - _threshold) / _gainReduction;
        } else if (a1 < -_threshold) {
            a1 = -_threshold - ( - _threshold - a1) / _gainReduction;
        }
        
        pa[n] = a1;
    }
    transmit(blocka);
    release(blocka);
}

void AudioEffectCompressor::setThreshold(uint16_t threshold) {
    _threshold = threshold;
}

void AudioEffectCompressor::setGainReduction(uint8_t gainReduction) {
    _gainReduction = gainReduction;
}
