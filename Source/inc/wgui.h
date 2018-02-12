#ifndef _WGUI_H
#define _WGUI_H


#define WGUI_COLOR_RED     (0xff0000)
#define WGUI_COLOR_GREEN   (0x00ff00)
#define WGUI_COLOR_BLUE    (0x0000ff)

typedef enum{
	WGUI_TRUE = 0,
	WGUI_FALSE = !WGUI_TRUE,
}WGUI_STATUS;

typedef enum{
	WGUI_IS_FILL = 0,
	WGUI_IS_NOT_FILL = !WGUI_IS_FILL,
}WGUI_LOWLEVEL_RFILL;


typedef unsigned int WGUI_COLOR;



#endif

