#ifndef __LEDFX_H__
#define __LEDFX_H__

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

struct animation_config
{
    uint8_t id;
    uint16_t delay;
    void (*leds_update)(CRGB*, uint16_t, const struct animation_config*);
    // Size of the received data in bytes
    uint8_t size;
    // Array for animation parameters
    void* params;
};

struct animation_state
{
    uint16_t iteration;
};

static struct animation_state animation_t;

/* Include auto-generated effects header */
#include <ledfx_effects.h>

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

int ledfx_set_params(uint8_t effect_id, void* params){
    if(params == NULL){
        return -1;
    }

    struct animation_config* config = ledfx_get_config(effect_id);
    if(config == NULL){
        return -2;
    }

    config->params = params;
}

void ledfx_effect(uint8_t effect_id, CRGB* leds, uint16_t num_leds)
{
    const struct animation_config* config = ledfx_get_config(effect_id);
    if(config != NULL){
        config->leds_update(leds, num_leds, config);
        animation_t.iteration++;
    }
}

#endif // __LEDFX_H__
