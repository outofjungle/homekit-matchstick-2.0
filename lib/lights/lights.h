#ifndef __INC_LIGHTS_H
#define __INC_LIGHTS_H

#include <FastLED.h>
#include <vector>

#include "task.h"

class Lights : public Task
{
  CRGB *leds;
  unsigned int numLeds;
  // TODO: Pass these into the constructor
  unsigned int FPS = 100;
  unsigned int hue = 200;
  unsigned int curpattern = 0;
  unsigned int brightness = 0xFF;

  std::vector<std::function<void()>> patterns;

  unsigned long curtime;
  unsigned long prevtime = millis();

  CRGBPalette16 currentPalette;
  CRGBPalette16 targetPalette;
  uint8_t targetPaletteNumber = 0;
  const TProgmemRGBGradientPalettePtr *currentPaletteList;

public:
  void Setup();

  template <template <uint8_t DATA_PIN, EOrder RGB_ORDER> class CHIPSET, uint8_t LED_PIN, EOrder RGB_ORDER>
  void Init(CRGB *_leds, int _numLeds)
  {
    leds = _leds;
    numLeds = _numLeds;
    FastLED.addLeds<CHIPSET, LED_PIN, RGB_ORDER>(leds, numLeds);
  }

  void AddPattern(std::function<void()> pattern);

  void Black();
  void Tick();
  void Cylon();
  void Rainbow();
  void Gradient();
  void CoolPalette();
  void Blur();
  void BlurWithPalette();
  void RandomWaves();
  void AddGlitter(fract8 chanceOfGlitter);
};

#endif
