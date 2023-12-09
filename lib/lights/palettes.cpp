#include "palettes.h"
#include "palette_themes.h"

Palettes::Palettes()
{
    playlist = gTestPalettes;
    paletteCount = sizeof(gTestPalettes) / sizeof(TProgmemRGBGradientPalettePtr);
    targetPaletteNumber = 0;
    currentPalette = playlist[targetPaletteNumber];
    targetPalette = playlist[targetPaletteNumber + 1];
}

TProgmemRGBGradientPalettePtr *Palettes::Playlist()
{
    return playlist;
}

CRGBPalette16 *Palettes::Current()
{
    return &currentPalette;
}
CRGBPalette16 *Palettes::Target()
{
    return &targetPalette;
}

uint8_t Palettes::Next()
{
    currentPalette = targetPalette;
    targetPaletteNumber = addmod8(targetPaletteNumber, 1, paletteCount);
    targetPalette = playlist[targetPaletteNumber];
    return targetPaletteNumber;
}
