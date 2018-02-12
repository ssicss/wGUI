#ifndef _WGUI_H
#define _WGUI_H


#define WGUI_COLOR_RED     (0xff0000)
#define WGUI_COLOR_GREEN   (0x00ff00)
#define WGUI_COLOR_BLUE    (0x0000ff)
#define WGUI_COLOR_BLACK   (0x000000)


typedef enum{
	WGUI_TRUE = 0,
	WGUI_FALSE = !WGUI_TRUE,
}WGUI_STATUS;

typedef enum{
	WGUI_IS_FILL = 0,
	WGUI_IS_NOT_FILL = !WGUI_IS_FILL,
}WGUI_LOWLEVEL_RFILL;


typedef unsigned int WGUI_COLOR;

extern WGUI_COLOR gCoreBkColor;
extern WGUI_COLOR gCoreColor;


void WGUI_SetColor(const WGUI_COLOR color);
WGUI_COLOR WGUI_GetColor(void);
void WGUI_SetBkColor(const WGUI_COLOR color);
WGUI_COLOR WGUI_GetBkColor(void);

WGUI_STATUS WGUI_Init(void);
void WGUI_DrawPoint(unsigned int x, unsigned int y, WGUI_COLOR color);
void WGUI_DrawLine(unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey,WGUI_COLOR color);
void WGUI_DrawRectangle(unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey,WGUI_COLOR color, WGUI_LOWLEVEL_RFILL _is_fill);
void WGUI_Clear(void);


#endif

