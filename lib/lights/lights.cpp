#include "lights.h"
#include "palettes.h"

void Lights::Setup()
{
  Serial.println("Lights starting");

  FastLED.setBrightness(brightness);

  TProgmemRGBGradientPalettePtr *currentPaletteList = palettes->Playlist();

  // AddPattern(std::bind(&Lights::Black, this));
  AddPattern(std::bind(&Lights::Blur, this));
  AddPattern(std::bind(&Lights::BlurWithPalette, this));
  AddPattern(std::bind(&Lights::CoolPalette, this));
  AddPattern(std::bind(&Lights::Cylon, this));
  AddPattern(std::bind(&Lights::RandomWaves, this));

  Serial.println("Lights initialized");
}

void Lights::AddPattern(std::function<void()> pattern)
{
  patterns.push_back(pattern);
}

void Lights::Tick()
{
  static unsigned long curtime;
  static unsigned long prevtime = millis();

  EVERY_N_SECONDS(20)
  {
    uint8_t targetPaletteNumber = palettes->Next();
    Serial.print("Target Palette [");
    Serial.print(targetPaletteNumber);
    Serial.println("]");
  }

  EVERY_N_MILLISECONDS(100)
  {
    uint8_t maxChanges = 24;
    nblendPaletteTowardPalette(*palettes->Current(), *palettes->Target(), maxChanges);
    AddGlitter(30);
  }

  EVERY_N_SECONDS(10)
  {
    randomSeed(analogRead(0));
  }

  EVERY_N_SECONDS(5)
  {
    // Set curpattern to a random value between 0 and the number of patterns
    curpattern = random8(patterns.size() + 1);

    // curpattern = 0;
    if (curpattern > patterns.size() + 1)
    {
      curpattern = 0;
    }
    Serial.print("Pattern [");
    Serial.print(curpattern);
    Serial.println("]");
  }

  curtime = millis();
  if (curtime - prevtime >= (1000 / FPS))
  {
    prevtime = curtime;
    EVERY_N_MILLISECONDS(100)
    {
      // hue++;
    }

    unsigned int size = patterns.size();
    patterns[curpattern % size]();

    FastLED.show();
  }
}

void Lights::Black()
{
  fadeToBlackBy(leds, numLeds, 20);
  int pos = beatsin16(13, 0, numLeds - 1);
  leds[pos] = CHSV(0, 0, 0);
}

void Lights::Cylon()
{
  static uint8_t index = random8();
  fadeToBlackBy(leds, numLeds, 1);
  int pos = beatsin16(5, 0, numLeds - 1);
  leds[pos] = ColorFromPalette(*palettes->Current(), index, 255);
}

void Lights::CoolPalette()
{
  TProgmemRGBGradientPalettePtr *currentPaletteList = palettes->Playlist();
  //  CRGBPalette16 myPal = christmas_candy_gp;
  //  CRGBPalette16 myPal = bhw1_28_gp;
  //  CRGBPalette16 myPal = GMT_hot_gp;
  //  CRGBPalette16 myPal = scoutie_gp;

  //  CRGBPalette16 myPal = bhw1_07_gp;
  //  CRGBPalette16 myPal = es_vintage_01_gp;
  // CRGBPalette16 myPal = currentPaletteList[0];
  //  CRGBPalette16 myPal = autumnrose_gp;
  //  CRGBPalette16 myPal = curvature_gp;
  static uint8_t heatindex = 0;

  CRGBPalette16 myPal = *palettes->Current();

  EVERY_N_MILLISECONDS(10)
  {
    heatindex++;
  }

  fill_palette(leds, numLeds - 1, heatindex, 2, myPal, 255, LINEARBLEND);
}

// Gets weird with more than 144 LEDs
void Lights::Blur()
{
  //    CRGBPalette16 myPal = quagga_gp;

  uint8_t blurAmount = dim8_raw(beatsin8(3, 64, 192)); // A sinewave at 3 Hz with values ranging from 64 to 192.
  blur1d(leds, numLeds, blurAmount);                   // Apply some blurring to whatever's already on the strip, which will eventually go black.

  uint8_t i = beatsin8(9, 0, numLeds);
  uint8_t j = beatsin8(7, 0, numLeds);
  uint8_t k = beatsin8(5, 0, numLeds);

  // The color of each point shifts over time, each at a different speed.
  uint16_t ms = millis();
  leds[(i + j) / 2] = CHSV(ms / 29, 200, 255);
  leds[(j + k) / 2] = CHSV(ms / 41, 200, 255);
  leds[(k + i) / 2] = CHSV(ms / 73, 200, 255);
  leds[(k + i + j) / 3] = CHSV(ms / 53, 200, 255);
}

void Lights::AddGlitter(fract8 chanceOfGlitter)
{
  if (random8() < chanceOfGlitter)
  {
    leds[random16(numLeds)] += CRGB::Red;
  }
}

void Lights::BlurWithPalette()
{
  uint8_t blurAmount = dim8_raw(beatsin8(3, 77, 210)); // A sinewave at 3 BPM with values ranging from 64 to 192.
  blur1d(leds, numLeds, blurAmount);                   // Apply some blurring to whatever's already on the strip, which will eventually go black.

  //  uint16_t  i = beatsin16(  5, 0, numLeds - 1);
  //  uint16_t  j = beatsin16( 3, i, numLeds - 1);
  //  uint16_t  k = beatsin16(  1, i, j);

  //  uint16_t  i = beatsin88(  127, 0, numLeds - 1);
  //  uint16_t  j = beatsin88( 89, i, numLeds - 1);
  //  uint16_t  k = beatsin88(  61, i, j);

  uint16_t i = beatsin88(257, 0, numLeds - 1);
  uint16_t j = beatsin88(89, i, numLeds - 1);
  uint16_t k = beatsin88(61, i, j);

  uint8_t index = random8();
  leds[i] = ColorFromPalette(*palettes->Current(), index, 255);
  leds[(numLeds - 1) - i] = ColorFromPalette(*palettes->Current(), index * 11, 255);
  leds[j] = ColorFromPalette(*palettes->Current(), index * 3, 255);
  leds[k] = ColorFromPalette(*palettes->Current(), index * 5, 255);
}

void Lights::RandomWaves()
{
  uint8_t blurAmount = dim8_raw(beatsin8(3, 77, 210)); // A sinewave at 3 Hz with values ranging from 64 to 192.
  blur1d(leds, numLeds, blurAmount);                   // Apply some blurring to whatever's already on the strip, which will eventually go black.

  static uint8_t ir = random8(numLeds - 1);
  static uint8_t jr = random8(numLeds - 1);
  static uint8_t kr = random8(numLeds - 1);
  static uint8_t lr = random8(numLeds - 1);

  EVERY_N_SECONDS(7)
  {
    ir = random8(numLeds - 1);
  }

  EVERY_N_SECONDS(13)
  {
    jr = random8(numLeds - 1);
  }

  EVERY_N_SECONDS(17)
  {
    kr = random8(numLeds - 1);
  }

  EVERY_N_SECONDS(23)
  {
    lr = random8(numLeds - 1);
  }

  uint8_t i = beatsin88(7, 0, ir);
  uint8_t j = beatsin88(5, jr, numLeds - 1);
  uint8_t k = beatsin88(1, kr / 2, kr);
  uint8_t l = beatsin88((lr >> 6), jr / 2, kr);

  i = i > numLeds - 1 ? numLeds - 1 : i;
  j = j > numLeds - 1 ? numLeds - 1 : j;
  k = k > numLeds - 1 ? numLeds - 1 : k;
  l = l > numLeds - 1 ? numLeds - 1 : l;

  uint8_t index = random8();
  leds[i] = ColorFromPalette(*palettes->Current(), index, 255);
  leds[j] = ColorFromPalette(*palettes->Current(), index * 3, 255);
  leds[k] = ColorFromPalette(*palettes->Current(), index * 5, 255);
  leds[l] = ColorFromPalette(*palettes->Current(), index * 7, 255);
}
