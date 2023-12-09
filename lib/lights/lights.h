#ifndef __INC_LIGHTS_H
#define __INC_LIGHTS_H

#include <FastLED.h>
#include <vector>

#include "task.h"
#include "palettes.h"

class Lights : public Task
{
  CRGB *leds;
  unsigned int numLeds;
  // TODO: Pass these into the constructor
  unsigned int FPS = 100;
  unsigned int curpattern = 0;
  unsigned int brightness = 0xFF;

  std::vector<std::function<void()>> patterns;

  Palettes *palettes = new Palettes();

public:
  void Setup();

  template <template <uint8_t DATA_PIN, EOrder RGB_ORDER> class CHIPSET, uint8_t LED_PIN, EOrder RGB_ORDER>
  void Init(CRGB *_leds, int _numLeds);

  void AddPattern(std::function<void()> pattern);

  void Black();
  void Blur();
  void BlurWithPalette();
  void CoolPalette();
  void Cylon();
  void RandomWaves();
  void Tick();
  void AddGlitter(fract8 chanceOfGlitter);
};

template <template <uint8_t DATA_PIN, EOrder RGB_ORDER> class CHIPSET, uint8_t LED_PIN, EOrder RGB_ORDER>
void Lights::Init(CRGB *_leds, int _numLeds)
{
  leds = _leds;
  numLeds = _numLeds;
  FastLED.addLeds<CHIPSET, LED_PIN, RGB_ORDER>(leds, numLeds);
}

#endif
