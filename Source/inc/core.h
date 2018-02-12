#ifndef _CORE_H
#define _CORE_H

#include "wgui.h"
#include "wgui_config.h"

#include "template.h"

WGUI_STATUS WGUI_Init(void);
void WGUI_DrawPoint(unsigned int x, unsigned int y, WGUI_COLOR color);
void WGUI_DrawLine(unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey,WGUI_COLOR color);
void WGUI_DrawRectangle(unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey,WGUI_COLOR color, WGUI_LOWLEVEL_RFILL _is_fill);



#endif
