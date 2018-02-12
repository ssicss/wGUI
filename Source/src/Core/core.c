
#include "core.h"

WGUI_COLOR gCoreBkColor;
WGUI_COLOR gCoreColor;


void WGUI_DrawPoint(unsigned int x, unsigned int y, WGUI_COLOR color)
{
	WGUI_DriverDrawPoint(x, y, color);
}

void WGUI_DrawLine(unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey,WGUI_COLOR color)
{
	unsigned int i=0;

	for(i=sx; i<ex; i++)
	{
		WGUI_DriverDrawPoint(i, i*(ey-sy)/(ex-sx) + sy, color);
	}
}

void WGUI_DrawRectangle(unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey,WGUI_COLOR color, WGUI_LOWLEVEL_RFILL _is_fill)
{
	unsigned int i=0;
	unsigned int j=0;

	for(i=sx; i<=ex; i++)
	{
		for(j=sy; j<=ey; j++)
		{
			if(_is_fill == WGUI_IS_FILL)
			{
				WGUI_DriverDrawPoint(i, j, color);
			}else{
				if((i==sx)||(i==ex)||(j==sy)||(j==ey))
				{
					WGUI_DriverDrawPoint(i, j, color);
				}	
			}	
		}
	}
}
void WGUI_Clear(void)
{
	WGUI_DrawRectangle(0, 0, WGUI_LCD_WIDTH, WGUI_LCD_HEIGHT, gCoreColor, WGUI_IS_FILL);
}

void WGUI_SetColor(const WGUI_COLOR color)
{
	gCoreColor = color;
}
WGUI_COLOR WGUI_GetColor(void)
{
	return gCoreColor;
}

void WGUI_SetBkColor(const WGUI_COLOR color)
{
	gCoreBkColor = color;
}
WGUI_COLOR WGUI_GetBkColor(void)
{
	return gCoreBkColor;
}





WGUI_STATUS WGUI_Init(void)
{
	WGUI_STATUS res = WGUI_FALSE;
	
	res = WGUI_DriverInit();

	gCoreBkColor = WGUI_DEFAULT_BKCOLOR;
	gCoreColor   = WGUI_DEFAULT_COLOR;

	return res;
}
