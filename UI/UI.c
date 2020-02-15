/*
 * UI.c
 *
 *  Created on: Feb 14, 2020
 *      Author: marka
 */

// *** Includes
//
#include "UI.h"

// *** Variables
//
#pragma DATA_ALIGN(psDMAControlTable, 1024)
static tDMAControlTable psDMAControlTable[64];
static tContext sContext;
static tRectangle sRect;
extern tCanvasWidget g_psPanelsUI[];

// *** Select Memory Integration Test
//
//RectangularButton(g_sMemTest, 0, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 190,
//                  50, 50, PB_STYLE_FILL, ClrBlack, ClrBlack, 0, ClrSilver,
//                  &g_sFontCm20, "[]", g_pui8Blue50x50, g_pui8Blue50x50Press, 0, 0,
//                  UI_ReturnHome);


//*****************************************************************************
// The names for each of the panels, which is displayed at the bottom of the
// screen.
//*****************************************************************************
char *g_pcPanei32NamesUI[] =
{
    "     Warm Up       ",
    "     Introduction  ",
    "     Test Menu     ",
    "     Memory Test   ",
    "     File System   ",
    "     Confirm File  ",
    "     Transferring  ",
    "     Test Complete ",
    "     S/W Update    ",
    "     Motor Test    ",
    "     In Progress   ",
    "     Limit Reached ",
    "     Test Complete "
};

//*****************************************************************************
// The panel that is currently being displayed.
//*****************************************************************************
uint32_t g_ui32Panel;

//*****************************************************************************
// 0 - Warm Up Panel
//*****************************************************************************
Canvas(g_sWarmUp, g_psPanelsUI, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnWarmUpPaint);

//*****************************************************************************
// 1 - Introduction Panel
//*****************************************************************************
Canvas(g_sIntro, g_psPanelsUI + 1, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnIntroPaint);

//*****************************************************************************
// 2 - Integration Test Menu Panel
//*****************************************************************************
Canvas(g_sTestMenu, g_psPanelsUI + 2, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnTestMenuPaint);

//*****************************************************************************
// 3 - Memory Test Panel
//*****************************************************************************
Canvas(g_sMemTest, g_psPanelsUI + 3, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnMemTestPaint);

//*****************************************************************************
// 4 - File System Panel
//*****************************************************************************
Canvas(g_sFilesystem, g_psPanelsUI + 4, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnFilesystemPaint);

//*****************************************************************************
// 5 - Confirm File Selection Panel
//*****************************************************************************
Canvas(g_sFileSel, g_psPanelsUI + 5, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnFileSelPaint);

//*****************************************************************************
// 6 - Memory Transfer In Progress Panel
//*****************************************************************************
Canvas(g_sTransfer, g_psPanelsUI + 6, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnTransferPaint);

//*****************************************************************************
// 7 - Memory Test Complete Panel
//*****************************************************************************
Canvas(g_sMemComplete, g_psPanelsUI + 7, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnMemCompletePaint);

//*****************************************************************************
// 8 - Motor Test Start Panel
//*****************************************************************************
Canvas(g_sMotorTest, g_psPanelsUI + 8, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnMotorTestPaint);

//*****************************************************************************
// 9 - Motor Test In Progress Panel
//*****************************************************************************
Canvas(g_sMotorGo, g_psPanelsUI + 9, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnMotorGoPaint);

//*****************************************************************************
// 10 - Motor Collision Panel
//*****************************************************************************
Canvas(g_sMotorCol, g_psPanelsUI + 10, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnMotorColPaint);

//*****************************************************************************
// 11 - Motor Test Complete Panel
//*****************************************************************************
Canvas(g_sMotorComplete, g_psPanelsUI + 11, 0, 0, &g_sKentec320x240x16_SSD2119, 0, 24,
       320, 166, CANVAS_STYLE_APP_DRAWN, 0, 0, 0, 0, 0, 0, UI_OnMotorCompletePaint);

//*****************************************************************************
// An array of canvas widgets, one per panel.  Each canvas is filled with
// black, overwriting the contents of the previous panel.
//*****************************************************************************
tCanvasWidget g_psPanelsUI[] =
{
    CanvasStruct(0, 0, &g_sWarmUp, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sIntro, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sTestMenu, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sMemTest, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sFilesystem, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sFileSel, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sTransfer, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sMemComplete, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sMotorTest, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sMotorGo, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sMotorCol, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0),
    CanvasStruct(0, 0, &g_sMotorComplete, &g_sKentec320x240x16_SSD2119, 0, 24,
                 320, 166, CANVAS_STYLE_FILL, ClrBlack, 0, 0, 0, 0, 0, 0)
};

#define NUM_PANELS              (sizeof(g_psPanels) / sizeof(g_psPanels[0]))



//*****************************************************************************
//
// Initializes User Interface
//
//*****************************************************************************
void UI_Init(void)
{
    FPUEnable();
    FPULazyStackingEnable();

    // Set the clock to 40Mhz derived from the PLL and the external oscillator
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |
                       SYSCTL_OSC_MAIN);

    uint32_t ui32SysClock = ROM_SysCtlClockGet();

    // Initialize the display driver.
    Kentec320x240x16_SSD2119Init(ui32SysClock);   //screen goes white

    // Initialize the graphics context.
    GrContextInit(&sContext, &g_sKentec320x240x16_SSD2119);

    // Create banner at the top of the LCD
    UI_GenerateHeader();

    // Configure and enable uDMA
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UDMA);
    SysCtlDelay(10);
    uDMAControlBaseSet(&psDMAControlTable[0]);
    uDMAEnable();

    // Initialize the touch screen driver and have it route its messages to the
    // widget tree.
    TouchScreenInit(ui32SysClock);
    TouchScreenCallbackSet(WidgetPointerMessage);

    // Initialize the widget tree
    UI_InitWidgetsIntegrationTest();
}

//*****************************************************************************
//
// Initializes Widgets for Integration Testing
//
//*****************************************************************************
void UI_InitWidgetsIntegrationTest(void)
{

}

//*****************************************************************************
//
// Creates IFFF Header at the top of the LCD
//
//*****************************************************************************
void UI_GenerateHeader(void)
{
    // Fill the top 24 rows of the screen with blue to create the banner.
    sRect.i16XMin = 0;
    sRect.i16YMin = 0;
    sRect.i16XMax = GrContextDpyWidthGet(&sContext) - 1;
    sRect.i16YMax = 23;
    GrContextForegroundSet(&sContext, ClrDarkBlue);
    GrRectFill(&sContext, &sRect);

    // Put a white box around the banner.
    GrContextForegroundSet(&sContext, ClrWhite);
    GrRectDraw(&sContext, &sRect);

    // Put the application name in the middle of the banner.
    GrContextFontSet(&sContext, &g_sFontCm20);
    GrStringDrawCentered(&sContext, "IFFF", -1,
                         GrContextDpyWidthGet(&sContext) / 2, 8, 0);
}

//*****************************************************************************
//
// Handles paint requests for the warm up canvas widget.
//
//*****************************************************************************
void UI_OnWarmUpPaint(tWidget *psWidget, tContext *psContext)
{
    uint32_t ui32Idx;
    tRectangle sRect;
    uint32_t timeout = 0;

    //
    // Draw a vertical sweep of lines from red to green.
    //
    for(ui32Idx = 0; ui32Idx <= 8; ui32Idx++)
    {
        GrContextForegroundSet(psContext,
                               (((((10 - ui32Idx) * 255) / 10) << ClrRedShift) |
                                (((ui32Idx * 255) / 10) << ClrGreenShift)));
        GrLineDraw(psContext, GrContextDpyWidthGet(psContext) / 2, 120, 5, 120 - (11 * ui32Idx));
        for(timeout = 0; timeout < UI_WARMUP_TIMEOUT_VAL; timeout++);
    }

    //
    // Draw a horizontal sweep of lines from green to blue.
    //
    for(ui32Idx = 1; ui32Idx <= 10; ui32Idx++)
    {
        GrContextForegroundSet(psContext,
                               (((((10 - ui32Idx) * 255) / 10) <<
                                 ClrGreenShift) |
                                (((ui32Idx * 255) / 10) << ClrBlueShift)));
        GrLineDraw(psContext, GrContextDpyWidthGet(psContext) / 2, 120, 5 + (ui32Idx * 15), 29);
        for(timeout = 0; timeout < UI_WARMUP_TIMEOUT_VAL; timeout++);
    }

    //
    // Draw a horizontal sweep of lines from blue to green.
    //
    for(ui32Idx = 1; ui32Idx <= 10; ui32Idx++)
    {
        GrContextForegroundSet(psContext,
                               (((((10 - ui32Idx) * 255) / 10) <<
                                 ClrBlueShift) |
                                (((ui32Idx * 255) / 10) << ClrGreenShift)));
        GrLineDraw(psContext, GrContextDpyWidthGet(psContext) / 2, 120, 140 + (ui32Idx * 15), 29);
        for(timeout = 0; timeout < UI_WARMUP_TIMEOUT_VAL; timeout++);
    }

    //
    // Draw a vertical sweep of lines from green to red.
    //
    for(ui32Idx = 8; ui32Idx > 0; ui32Idx--)
    {
        GrContextForegroundSet(psContext,
                               (((((10 - ui32Idx) * 255) / 10) << ClrRedShift) |
                                (((ui32Idx * 255) / 10) << ClrGreenShift)));
        GrLineDraw(psContext, GrContextDpyWidthGet(psContext) / 2, 120, 305, 120 - (11 * ui32Idx));
        for(timeout = 0; timeout < UI_WARMUP_TIMEOUT_VAL; timeout++);
    }

    GrContextForegroundSet(psContext, (255 << ClrRedShift) | (0 << ClrGreenShift));
    GrLineDraw(psContext, GrContextDpyWidthGet(psContext) / 2, 120, 305, 120);
}

//*****************************************************************************
//
// Handles paint requests for the introduction canvas widget.
//
//*****************************************************************************
void UI_OnIntroPaint(tWidget *psWidget, tContext *psContext)
{
    //
    // Display the introduction text in the canvas.
    //
    GrContextFontSet(psContext, &g_sFontCm18);
    GrContextForegroundSet(psContext, ClrSilver);

    GrStringDrawCentered(psContext, "~*~*~ Waveguide Wizards ~*~*~", -1,
                         GrContextDpyWidthGet(psContext) / 2, 32, 0);
    GrStringDrawCentered(psContext, "Welcome to the incredible fused", -1,
                         GrContextDpyWidthGet(psContext) / 2, 74, 0);
    GrStringDrawCentered(psContext, "filament fabricator (IFFF)", -1,
                         GrContextDpyWidthGet(psContext) / 2, 92, 0);
    GrStringDrawCentered(psContext, "Press the + button at the bottom", -1,
                         GrContextDpyWidthGet(psContext) / 2, 146, 0);
    GrStringDrawCentered(psContext, "to select an integration test: ", -1,
                         GrContextDpyWidthGet(psContext) / 2, 164, 0);
}

void UI_OnTestMenuPaint(tWidget *psWidget, tContext *psContext)
{

}
