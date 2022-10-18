#pragma once
#include "Mof.h"
class Font
{
private:
	CTexture fontTexture;
	const float _fontSize = 64;
	const int _adjust = 2;
	const int _row = 16;
	const int _line = 32;
public:
	void Load();
	void String(int sizex, int sizey, int fontsize, const char* string);
	void Release();
};

