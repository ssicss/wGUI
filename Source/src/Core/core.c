
#include "core.h"

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


WGUI_STATUS WGUI_Init(void)
{
	WGUI_DriverInit();
}
