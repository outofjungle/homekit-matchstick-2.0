#include <Arduino.h>
#include <FastLED.h>
#include "SimpleButton.h"
#include "lights.h"

#define M5_BUTTON_PIN 39
#define S1_PIN 0
#define LED_PIN 22
#define CH1_PIN 26
#define CH2_PIN 18
#define CH3_PIN 19
#define CH4_PIN 25

#define LED_LENGTH 200

CRGB ch1[LED_LENGTH];
CRGB ch2[LED_LENGTH];
CRGB ch3[LED_LENGTH];
CRGB ch4[LED_LENGTH];

SimpleButton *s1 = new SimpleButton(S1_PIN);
Lights *lights1 = new Lights();
Task *tasks[] = {lights1};

void update_led(bool update)
{
    static int led_state = LOW;

    if (update)
    {
        led_state = !led_state;
        digitalWrite(LED_PIN, led_state);
    }
}

void setup()
{
    Serial.begin(115200);

    pinMode(M5_BUTTON_PIN, INPUT_PULLUP);
    pinMode(S1_PIN, INPUT_PULLUP);

    pinMode(LED_PIN, OUTPUT);

    lights1->Init<WS2811, CH1_PIN, GBR>(ch1, LED_LENGTH);

    int size = sizeof(tasks) / sizeof(tasks[0]);
    for (int i = 0; i < size; i++)
    {
        tasks[i]->Setup();
    }

    update_led(true);
}

void loop()
{
    bool pressed = s1->pressed();

    update_led(pressed);

    int size = sizeof(tasks) / sizeof(tasks[0]);
    for (int i = 0; i < size; i++)
    {
        tasks[i]->Tick();
    }
}
