// For Blueled
// #define F_CPU 8000000L
#include <Arduino.h>
#include <FastLED.h>

#include "ledfx.h"

// How many leds in your strip?
#define NUM_LEDS 30
#define DATA_PIN 7

// Define the array of leds
CRGB fastleds[NUM_LEDS];

ledfx_color leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(fastleds, NUM_LEDS);

    ledfx_init((ledfx_color*)&leds, NUM_LEDS);
    // ledfx_add_param(0xff00);
    // ledfx_add_param(1000);
    // ledfx_add_param(100);
    ledfx_effect(4);
}

void copy(ledfx_color* leds, CRGB* fastleds, uint16_t len){
    for(uint16_t i = 0; i < len; i++){
        fastleds[i] = ledfx_color_to_int(leds[i]);
    }
}

void loop() { 
    ledfx_service();
    copy(leds, fastleds, NUM_LEDS);
    FastLED.show();
    FastLED.setBrightness(animation_t.brightness);
    delay(100);
}
