#include <Arduino.h>
#include <FastLED.h>

#include "ledfx.h"

// How many leds in your strip?
#define NUM_LEDS 200
#define DATA_PIN 7

// Define the array of leds
CRGB fastleds[NUM_LEDS];

ledfx_color leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(fastleds, NUM_LEDS);

    ledfx_init((ledfx_color*)&leds, NUM_LEDS);
    ledfx_add_param(0xff00ff);
    ledfx_add_param(10);
    ledfx_add_param(0);
    ledfx_effect(1);
}

void copy(ledfx_color* leds, CRGB* fastleds, uint16_t len){
    for(int i = 0; i < len; i++){
        fastleds[i] = ledfx_color_to_int(leds[i]);
    }
}

void loop() { 
    ledfx_service();
    copy(leds, fastleds, NUM_LEDS);
    FastLED.show();
    delay(100);
}
