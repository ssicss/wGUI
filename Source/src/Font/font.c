#include "font.h"

struct WGUI_FONT gWGUI_Font={
	&font_0812_sum[0],
};


//未检查输入参数ch,只能在本函数调用，防止出错
static _FontDrawChar(unsigned int x, unsigned int y, WGUI_COLOR color, const char ch)
{
	unsigned int xdst = 0;
	unsigned int ydst = 0;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int db_index = 0;
	unsigned int db_bit_mask = 0;

	//获取字符间距
	xdst = gWGUI_Font.finfo[ch - 0x20].x;
	ydst = gWGUI_Font.finfo[ch - 0x20].y;

	//使用逐点扫描的方式显示字符
	for(j=y; j<=ydst+y; j++ )
	{
		for(i=x; i<=xdst+x; i++ )
		{
			db_index = (j-y)*(xdst/8) + (i-x)/8;
			db_bit_mask = 1<<(7-(i-x)%8);
			if(((gWGUI_Font.finfo[ch - 0x20].db[db_index])&(db_bit_mask)) == 0)
			{
				WGUI_DrawPoint(i,j,gCoreBkColor);
			}else{
				WGUI_DrawPoint(i,j,gCoreColor);
			}
			
		}
	}

	
}

//显示字符串
void WGUI_ShowTextAt(unsigned int x, unsigned int y, WGUI_COLOR color, const char *str)
{
	char * tmp_str = (char *)str;

	while(*tmp_str!= '\0')
	{
		//确认输入ASICC范围
		if((*tmp_str<0x20)||(*tmp_str>0x7f))
		{
			return;
		}
		_FontDrawChar(x,y,color,*tmp_str);
		x+=gWGUI_Font.finfo[*tmp_str - 0x20].x;
		tmp_str++;
	}

}

