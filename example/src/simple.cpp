#include <Arduino.h>
#include <FastLED.h>

#include "ledfx.h"

// How many leds in your strip?
#define NUM_LEDS 10
#define DATA_PIN 7

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

    ledfx_init();
    ledfx_set_param(0, 0xFF0000);
    ledfx_set_param(1, 0);
    ledfx_set_param(2, NUM_LEDS);
}

void loop() { 
    ledfx_effect(0x41, leds, NUM_LEDS);
    FastLED.show();
    delay(10);
}
