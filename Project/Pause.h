#pragma once
#include "GameMenu.h"
#include "MenuInput.h"
class Pause
{
private:
	GameMenu _menu;
	MenuInput _input;
	char* _title;
	enum { _textCount = 2 };
	char* _text[_textCount] = {
	"StageSelect",
	"Exit"
	};
	bool _pause;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	bool IsPause() const{ return _pause; }
};