
#include "template.h"


WGUI_STATUS WGUI_DriverInit(void)
{
	return SimulaterInit();
}

void WGUI_DriverDrawPoint(unsigned int x, unsigned int y, WGUI_COLOR color)
{
	SimulaterDrawPoint(x, y, color);
}
