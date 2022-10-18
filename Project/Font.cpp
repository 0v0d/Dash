#include "Font.h"
void Font::Load()
{
	fontTexture.Load("font.png");
}

void Font::String(int sizex, int sizey, int fontsize, const char* string)
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		float x = string[i] % _row;
		float y = ((string[i] - _line) / _row);
		CRectangle _rect(x * _fontSize, y * _fontSize,
			x * _fontSize + _fontSize, y * _fontSize + _fontSize);
		sizex += fontsize;
		fontTexture.RenderScale(sizex, sizey, fontsize / _fontSize, _rect);
	}
}

void Font::Release()
{
	fontTexture.Release();
}