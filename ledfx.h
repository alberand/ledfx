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
    void (*leds_update)(ledfx_RGB*, uint16_t, const struct animation_config*);
    // Number of parameters
    uint8_t num;
};

struct ledfx_state
{
    uint16_t iteration;
    // Array for animation parameters
    uint32_t* params;
};

static struct ledfx_state animation_t;

const ledfx_RGB ledfx_color(uint32_t color)
{
    const ledfx_RGB c = {
        .r = (color >> 16) & 0xFF,
        .g = (color >> 8) & 0xFF,
        .b = (color >> 0) & 0xFF,
    };

    return c;
}

uint32_t ledfx_color(ledfx_RGB color)
{
    return (color.r << 16) | (color.g << 8) | (color.b << 0);
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
    memset(animation_t.params, 0, sizeof(uint32_t)*MAX_PARAMS);
}

const struct animation_config* ledfx_get_config(uint8_t effect_id){
    for(int i = 0; i < COUNT_OF(configs); i++){
        if(configs[i]->id == effect_id){
            return configs[i];
        }
    }

    return NULL;
}

int ledfx_set_param(uint8_t index, uint32_t param){
    if(animation_t.params == nullptr){
        animation_t.params = malloc(sizeof(uint32_t)*MAX_PARAMS);
    }

    animation_t.params[index] = param;
}

void ledfx_effect(uint8_t effect_id, ledfx_RGB* leds, uint16_t num_leds)
{
    const struct animation_config* config = ledfx_get_config(effect_id);
    if(config != NULL){
        config->leds_update(leds, num_leds, config);
        animation_t.iteration++;
    }
}

#endif // __LEDFX_H__
