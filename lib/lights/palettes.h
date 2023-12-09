#ifndef __INC_PALETTES_H
#define __INC_PALETTES_H

#include <FastLED.h>

class Palettes
{
    TProgmemRGBGradientPalettePtr *playlist;

    CRGBPalette16 currentPalette;
    CRGBPalette16 targetPalette;
    uint8_t targetPaletteNumber = 0;
    uint8_t paletteCount;

public:
    Palettes();
    TProgmemRGBGradientPalettePtr *Playlist();
    CRGBPalette16 *Current();
    CRGBPalette16 *Target();
    uint8_t Next();
};

#endif
