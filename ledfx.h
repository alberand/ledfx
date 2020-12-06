#ifndef __LEDFX_H__
#define __LEDFX_H__

#define MAX_PARAMS 20

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} ledfx_RGB;

struct animation_config
{
    uint8_t id;
    void (*leds_update)(CRGB*, uint16_t, const struct animation_config*);
    // Number of parameters
    uint8_t num;
};

struct ledfx_state
{
    uint16_t iteration;
    // Array for animation parameters
    uint8_t num;
    uint32_t* params;
};

static struct ledfx_state animation_t;

const ledfx_RGB ledfx_color(uint32_t color)
{
    const ledfx_RGB c = {
        .r = (uint8_t)((color >> 16) & 0xFF),
        .g = (uint8_t)((color >> 8) & 0xFF),
        .b = (uint8_t)((color >> 0) & 0xFF),
    };

    return c;
}

uint32_t ledfx_color(ledfx_RGB color)
{
    return ((uint32_t)color.r << 16) | ((uint32_t)color.g << 8) | ((uint32_t)color.b << 0);
}

const ledfx_RGB ledfx_color(uint8_t r, uint8_t g, uint8_t b)
{
    const ledfx_RGB c = {
        .r = r,
        .g = g,
        .b = b,
    };

    return c;
}

/* Include auto-generated effects header */
#include <ledfx_effects.h>

void ledfx_state_reset()
{
    animation_t.iteration = 0;
    animation_t.num = 0;
    memset(animation_t.params, 0, sizeof(uint32_t)*MAX_PARAMS);
}

void ledfx_init(){
    animation_t.params = (uint32_t*)malloc(MAX_PARAMS*sizeof(uint32_t));
    ledfx_state_reset();
}

const struct animation_config* ledfx_get_config(uint8_t effect_id){
    for(uint8_t i = 0; i < COUNT_OF(configs); i++){
        if(configs[i]->id == effect_id){
            return configs[i];
        }
    }

    return NULL;
}

void ledfx_set_param(uint8_t index, uint32_t param){
    if(animation_t.params == NULL){
        ledfx_init();
    }

    if(animation_t.num + 1 == MAX_PARAMS){
        return;
    }

    animation_t.params[index] = param;
    animation_t.num += 1;
}

void ledfx_effect(const uint8_t effect_id, CRGB* leds, const uint16_t num_leds)
{
    const struct animation_config* config = ledfx_get_config(effect_id);
    if(config != NULL){
        config->leds_update(leds, num_leds, config);
        animation_t.iteration++;
    }
}

#endif // __LEDFX_H__
