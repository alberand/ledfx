#ifndef __LEDFX_H__
#define __LEDFX_H__

#include <ledfx_common.h>
#include <effects/bpm.h>
#include <effects/color_wipe.h>
#include <effects/confetti.h>
#include <effects/cylon.h>
#include <effects/fadeinout.h>
#include <effects/fire.h>
#include <effects/gradient.h>
#include <effects/juggle.h>
#include <effects/rainbow_classic.h>
#include <effects/rainbow.h>
#include <effects/sinelon.h>
#include <effects/snowsparkle.h>
#include <effects/solid.h>
#include <effects/stroboscope.h>
#include <effects/theater_chase.h>
#include <effects/train.h>
#include <effects/twinkle.h>

#define MAX_CONFIGS 1

static struct animation_config* configs[MAX_CONFIGS] = {
    &bpm_config    
};


void animation_state_reset()
{
    animation_t.iteration = 0;
}

void fadeall(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    for(uint16_t i = 0; i < num_leds; i++) {
        leds[i].nscale8(250);
    }
}

const struct animation_config* ledfx_get_config(uint8_t effect_id){
    for(int i = 0; i < COUNT_OF(configs); i++){
        if(configs[i]->id == effect_id){
            return configs[i];
        }
    }

    return NULL;
}

int ledfx_effect(uint8_t effect_id, CRGB* leds, uint16_t num_leds)
{
    const struct animation_config* config = ledfx_get_config(effect_id);
    if(config != NULL){
        config->leds_update(leds, num_leds, config);
        animation_t.iteration++;
    }
}

#endif // __LEDFX_H__
