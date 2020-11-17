#include <Arduino.h>
#include <FastLED.h>

#include "ledfx.h"
#include <effects/bpm.h>

// How many leds in your strip?
#define NUM_LEDS 10
#define DATA_PIN 7

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() { 
    ledfx_effect(0x44, leds, NUM_LEDS);
    FastLED.show();
    delay(ledfx_get_config(0x44)->delay);
}
