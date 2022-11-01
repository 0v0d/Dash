#pragma once
#include "Mof.h"
class GameMenu
{
private:
	int _cursor = 0;
	int _count = 0;
	char* _title = nullptr;
	char** _text = nullptr;
	const int strIndex = 1;
	CRectangle _rect;
	CRectangle _headerRect;
	const int _heightSpace = 12;
	const int _adjust = 2;
	const int _space = 8;
	float _screenWidth;
	float _screenHeight;
	float _rectWidth;
	float _rectHeight;
	const float _half = 0.5;
public:
	void Create(char* title, char** text, int cnt);
	void Render();
	void Release();
	void Show();
	void SetCoursor(int cursor) { _cursor = cursor; }
};

