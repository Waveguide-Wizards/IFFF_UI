/*
 * UI.c
 *
 *  Created on: Feb 14, 2020
 *      Author: marka
 */

#include "UI.h"

// *** Select Memory Integration Test
//
RectangularButton(g_sMemTest, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 190,
                  50, 50, PB_STYLE_FILL, ClrBlack, ClrBlack, 0, ClrSilver,
                  &g_sFontCm20, "Memory IT", g_pui8Blue50x50, g_pui8Blue50x50Press, 0, 0,
                  OnPrevious);
