#ifndef __INC_PALETTE_THEMES_H
#define __INC_PALETTE_THEMES_H

#define ALL 0x00
#define HALLOWEEN 0x01

#include <FastLED.h>

// Gradient palette "purplefly_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/purplefly.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(purplefly_gp){
    0, 0, 0, 0,
    63, 239, 0, 122,
    191, 252, 255, 78,
    255, 0, 0, 0};

DEFINE_GRADIENT_PALETTE(heatmap_gp){
    0, 0, 0, 0,          // black
    128, 255, 0, 0,      // red
    224, 255, 255, 0,    // bright yellow
    255, 255, 255, 255}; // full white

// Gradient palette "bhw1_28_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_28.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw1_28_gp){
    0, 75, 1, 221,
    30, 252, 73, 255,
    48, 169, 0, 242,
    119, 0, 149, 242,
    170, 43, 0, 242,
    206, 252, 73, 255,
    232, 78, 12, 214,
    255, 0, 149, 242};

// Gradient palette "christmas_candy_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ocal/tn/christmas-candy.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE(christmas_candy_gp){
    0, 255, 255, 255,
    25, 255, 0, 0,
    51, 255, 255, 255,
    76, 0, 55, 0,
    102, 255, 255, 255,
    127, 255, 0, 0,
    153, 255, 255, 255,
    178, 0, 55, 0,
    204, 255, 255, 255,
    229, 255, 0, 0,
    255, 255, 255, 255};

// Gradient palette "GMT_hot_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_hot.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(GMT_hot_gp){
    0, 0, 0, 0,
    95, 255, 0, 0,
    191, 255, 255, 0,
    255, 255, 255, 255};

// Gradient palette "bhw2_22_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_22.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw2_22_gp){
    0, 0, 0, 0,
    99, 227, 1, 1,
    130, 249, 199, 95,
    155, 227, 1, 1,
    255, 0, 0, 0};

// Gradient palette "scoutie_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/scoutie.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(scoutie_gp){
    0, 255, 156, 0,
    127, 0, 195, 18,
    216, 1, 0, 39,
    255, 1, 0, 39};

// Gradient palette "bhw1_07_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_07.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw1_07_gp){
    0, 232, 65, 1,
    255, 229, 227, 1};

// Gradient palette "es_vintage_01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/vintage/tn/es_vintage_01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_vintage_01_gp){
    0, 4, 1, 1,
    51, 16, 0, 1,
    76, 97, 104, 3,
    101, 255, 131, 19,
    127, 67, 9, 4,
    153, 16, 0, 1,
    229, 4, 1, 1,
    255, 4, 1, 1};

// Gradient palette "curvature_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/grass/tn/curvature.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.
DEFINE_GRADIENT_PALETTE(curvature_gp){
    0, 0, 0, 0,
    114, 0, 0, 255,
    126, 22, 55, 255,
    127, 0, 255, 255,
    127, 255, 255, 255,
    127, 255, 255, 0,
    128, 255, 55, 0,
    140, 255, 0, 0,
    255, 255, 0, 255};

// Gradient palette "autumnrose_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/autumnrose.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE(autumnrose_gp){
    0, 71, 3, 1,
    45, 128, 5, 2,
    84, 186, 11, 3,
    127, 215, 27, 8,
    153, 224, 69, 13,
    188, 229, 84, 6,
    226, 242, 135, 17,
    255, 247, 161, 79};

// Gradient palette "dense_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cmocean/tn/dense.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 2048 bytes of program space.

DEFINE_GRADIENT_PALETTE(dense_gp){
    0, 194, 225, 221,
    0, 194, 225, 221,
    0, 190, 223, 219,
    1, 190, 223, 219,
    1, 188, 221, 216,
    2, 188, 221, 216,
    2, 184, 219, 216,
    3, 184, 219, 216,
    3, 179, 217, 214,
    4, 179, 217, 214,
    4, 175, 217, 212,
    5, 175, 217, 212,
    5, 173, 215, 212,
    6, 173, 215, 212,
    6, 169, 213, 210,
    7, 169, 213, 210,
    7, 165, 211, 210,
    8, 165, 211, 210,
    8, 163, 209, 207,
    9, 163, 209, 207,
    9, 159, 209, 207,
    10, 159, 209, 207,
    10, 155, 207, 205,
    11, 155, 207, 205,
    11, 152, 205, 205,
    12, 152, 205, 205,
    12, 150, 203, 203,
    13, 150, 203, 203,
    13, 146, 201, 203,
    14, 146, 201, 203,
    14, 142, 199, 201,
    15, 142, 199, 201,
    15, 140, 199, 201,
    16, 140, 199, 201,
    16, 137, 197, 201,
    17, 137, 197, 201,
    17, 133, 195, 199,
    30, 13, 1, 9,
    231, 13, 1, 9,
    231, 12, 1, 9,
    232, 12, 1, 9,
    232, 12, 1, 8,
    233, 12, 1, 8,
    233, 12, 1, 8,
    234, 12, 1, 8,
    234, 11, 1, 7,
    235, 11, 1, 7,
    235, 11, 1, 7,
    236, 11, 1, 7,
    236, 10, 1, 6,
    237, 10, 1, 6,
    237, 10, 1, 6,
    238, 10, 1, 6,
    238, 9, 1, 5,
    239, 9, 1, 5,
    239, 9, 1, 5,
    240, 9, 1, 5,
    240, 9, 1, 5,
    241, 9, 1, 5,
    241, 8, 1, 4,
    242, 8, 1, 4,
    242, 8, 1, 4,
    243, 8, 1, 4,
    243, 8, 1, 4,
    244, 8, 1, 4,
    244, 7, 1, 3,
    245, 7, 1, 3,
    245, 7, 1, 3,
    246, 7, 1, 3,
    246, 7, 1, 3,
    247, 7, 1, 3,
    247, 6, 1, 3,
    248, 6, 1, 3,
    248, 6, 1, 2,
    249, 6, 1, 2,
    249, 5, 1, 2,
    250, 5, 1, 2,
    250, 5, 1, 2,
    251, 5, 1, 2,
    251, 5, 1, 2,
    252, 5, 1, 2,
    252, 5, 1, 2,
    253, 5, 1, 2,
    253, 4, 1, 2,
    254, 4, 1, 2,
    254, 4, 1, 1,
    255, 4, 1, 1};

// Gradient palette "quagga_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/quagga.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE(quagga_gp){
    0, 1, 9, 84,
    40, 42, 24, 72,
    84, 6, 58, 2,
    168, 88, 169, 24,
    211, 42, 24, 72,
    255, 1, 9, 84};

// Gradient palette "YlOrRd_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cb/seq/tn/YlOrRd_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 72 bytes of program space.

DEFINE_GRADIENT_PALETTE(YlOrRd_09_gp){
    0, 255, 255, 145,
    28, 255, 255, 145,
    28, 255, 217, 79,
    56, 255, 217, 79,
    56, 252, 178, 37,
    84, 252, 178, 37,
    84, 252, 115, 12,
    113, 252, 115, 12,
    113, 249, 69, 6,
    141, 249, 69, 6,
    141, 247, 18, 2,
    170, 247, 18, 2,
    170, 188, 1, 1,
    198, 188, 1, 1,
    198, 117, 0, 2,
    226, 117, 0, 2,
    226, 42, 0, 2,
    255, 42, 0, 2};

// Gradient palette "cloud_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/cloud.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space.

DEFINE_GRADIENT_PALETTE(cloud_gp){
    0, 247, 149, 91,
    127, 208, 32, 71,
    255, 42, 79, 188};

// Gradient palette "bhw1_three_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_three.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw1_three_gp){
    0, 255, 255, 255,
    45, 7, 12, 255,
    112, 227, 1, 127,
    112, 227, 1, 127,
    140, 255, 255, 255,
    155, 227, 1, 127,
    196, 45, 1, 99,
    255, 255, 255, 255};

DEFINE_GRADIENT_PALETTE(purply){
    155, 227, 1, 127,
    196, 45, 1, 99,
    255, 255, 255, 255};

TProgmemRGBGradientPalettePtr gHalloweenPalettes[] = {
    purply,
    YlOrRd_09_gp,
    dense_gp,
    autumnrose_gp,
    cloud_gp,
    bhw1_three_gp,
    purplefly_gp};

TProgmemRGBGradientPalettePtr gTestPalettes[] = {
    christmas_candy_gp,
    bhw1_28_gp,
    GMT_hot_gp,
    scoutie_gp,
    bhw1_07_gp,
    es_vintage_01_gp,
    dense_gp,
    autumnrose_gp,
    curvature_gp,
    YlOrRd_09_gp,
    quagga_gp};

#endif
