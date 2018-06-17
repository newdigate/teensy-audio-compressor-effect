
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
         a1 = _threshold + (a1 - _threshold) / 3;
        } else if (a1 < -_threshold) {
         a1 = -_threshold - ( - _threshold - a1) / 3;
        }
        
        pa[n] = a1;
    }
    transmit(blocka, 0);
    release(blocka);
}
