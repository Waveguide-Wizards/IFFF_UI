/*
 * UI.h
 *
 *  Created on: Feb 14, 2020
 *      Author: marka
 */

#ifndef UI_H_
#define UI_H_

// *** Includes
//
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
//
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
//
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/flash.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/uart.h"
#include "driverlib/udma.h"
#include "driverlib/rom.h"
//
#include "drivers/Kentec320x240x16_ssd2119_spi.h"
#include "drivers/touch.h"
//
#include "grlib/grlib.h"
#include "grlib/widget.h"
#include "grlib/canvas.h"
#include "grlib/checkbox.h"
#include "grlib/container.h"
#include "grlib/pushbutton.h"
#include "grlib/radiobutton.h"
#include "grlib/slider.h"
//
#include "images.h"

// *** Defines
//
#define UI_WARMUP_TIMEOUT_VAL               3000000
//
#define UI_UTMENU_SEL_MEM_X                 60
#define UI_UTMENU_SEL_MEM_Y                 60
#define UI_UTMENU_SEL_MEM_W                 200
#define UI_UTMENU_SEL_MEM_H                 50


// *** Function Definitions
//
void UI_Init(void);
void UI_InitWidgetsIntegrationTest(void);
void UI_GenerateHeader(void);
//
void UI_OnWarmUpPaint(tWidget *psWidget, tContext *psContext);      /*      */
void UI_OnIntroPaint(tWidget *psWidget, tContext *psContext);       /*      */
void UI_OnTestMenuPaint(tWidget *psWidget, tContext *psContext);    /*      */
void UI_OnMemTestPaint(tWidget *psWidget, tContext *psContext);     /*      */
void UI_OnFilesystemPaint(tWidget *psWidget, tContext *psContext);  /*      */
//
void UI_ReturnHome(tWidget * psWidget);


#endif /* UI_H_ */