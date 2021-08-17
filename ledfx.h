#ifndef __LEDFX_H__
#define __LEDFX_H__

#define MAX_PARAMS 20

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} ledfx_color;

struct ledfx_state {
    // strip configuration
    ledfx_color* leds;
    uint16_t num_leds;
    uint16_t brightness;

    // current animation
    uint16_t iteration;
    uint8_t current;

    // params storage
    uint8_t index;
    uint32_t* params;
};

static struct ledfx_state animation_t;

const ledfx_color ledfx_int_to_color(uint32_t c) {
    const ledfx_color color_t = {
        .r = (uint8_t)((c >> 16) & 0xFF),
        .g = (uint8_t)((c >> 8) & 0xFF),
        .b = (uint8_t)((c >> 0) & 0xFF),
    };

    return color_t;
}

uint32_t ledfx_color_to_int(const ledfx_color c) {
    return ((uint32_t)c.r << 16) | ((uint32_t)c.g << 8) | ((uint32_t)c.b << 0);
}

const ledfx_color ledfx_color_init(uint32_t color) {
    return ledfx_int_to_color(color);
}

const ledfx_color ledfx_color_init(uint8_t r, uint8_t g, uint8_t b) {
    const ledfx_color c = {
        .r = r,
        .g = g,
        .b = b,
    };

    return c;
}

void ledfx_params_reset(){
    if(animation_t.params != NULL){
        free(animation_t.params);
    }

    animation_t.index = 0;
    animation_t.params = (uint32_t*)malloc(MAX_PARAMS*sizeof(uint32_t));
}

uint8_t ledfx_params_count(){
    return animation_t.index + 1;
}

void ledfx_add_param(uint32_t param){
    if(animation_t.params == NULL){
        return;
    }

    if(animation_t.index + 1 == MAX_PARAMS){
        return;
    }

    animation_t.params[animation_t.index++] = param;
}

void ledfx_set_param(uint8_t index, uint32_t param){
    if(index > animation_t.index){
        return;
    }

    animation_t.params[index] = param;
}

uint32_t ledfx_get_param(uint8_t index){
    if(animation_t.params == NULL){
        return 0xDEADBABE;
    }

    if(index >= animation_t.index){
        return 0xDEADBABE;
    }

    return animation_t.params[index];
}

void ledfx_init(ledfx_color* leds, uint16_t num_leds){
    animation_t.leds = leds;
    animation_t.num_leds = num_leds;
    animation_t.iteration = 0;
    ledfx_params_reset();
}

void ledfx_effect(const uint8_t effect_id) {
    animation_t.current = effect_id;
}

void ledfx_set_pixel(const uint16_t id, const ledfx_color color){
	animation_t.leds[id] = color;
}

void ledfx_set_pixel(const uint16_t id, const uint32_t color){
	ledfx_set_pixel(id, ledfx_int_to_color(color));
}

void ledfx_set_brightness(const uint32_t brightness){
    animation_t.brightness = brightness;
}

void ledfx_set_all(const ledfx_color color){
    for( uint16_t i = 0; i < animation_t.num_leds; ++i) {
		ledfx_set_pixel(i, color);
    }
}

/* Include auto-generated effects header */
#include <ledfx_effects.h>

void ledfx_service(){
    effect_ptr[animation_t.current]();
    animation_t.iteration++;
}

#endif // __LEDFX_H__
