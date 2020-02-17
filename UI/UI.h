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
#define UI_UTMENU_SEL_MEM_X                 60
#define UI_UTMENU_SEL_MEM_Y                 60
#define UI_UTMENU_SEL_MEM_W                 200
#define UI_UTMENU_SEL_MEM_H                 50
//
#define UI_TICKS_TO_MS(x)                   (x * 40000 / 3)
#define UI_WARMUP_DELAY_TIME                40


// *** Function Definitions
//
void UI_Init(void);
void UI_InitWidgetsIntegrationTest(uint32_t sysClock);
void UI_GenerateHeader(void);
//
void UI_OnWarmUpPaint(tWidget *psWidget, tContext *psContext);          /*      */
void UI_OnIntroPaint(tWidget *psWidget, tContext *psContext);           /*      */
void UI_OnTestMenuPaint(tWidget *psWidget, tContext *psContext);        /*      */
void UI_OnMemTestPaint(tWidget *psWidget, tContext *psContext);         /*      */
void UI_OnFilesystemPaint(tWidget *psWidget, tContext *psContext);      /*      */
void UI_OnFileSelPaint(tWidget *psWidget, tContext *psContext);         /*      */
void UI_OnTransferPaint(tWidget *psWidget, tContext *psContext);        /*      */
void UI_OnMemCompletePaint(tWidget *psWidget, tContext *psContext);     /*      */
void UI_OnMotorTestPaint(tWidget *psWidget, tContext *psContext);       /*      */
void UI_OnMotorGoPaint(tWidget *psWidget, tContext *psContext);         /*      */
void UI_OnMotorColPaint(tWidget *psWidget, tContext *psContext);        /*      */
void UI_OnMotorCompletePaint(tWidget *psWidget, tContext *psContext);   /*      */
//
void UI_ReturnHome(tWidget * psWidget);
void UI_OnPrevious(tWidget *psWidget);
void UI_OnNext(tWidget *psWidget);

#endif /* UI_H_ */
