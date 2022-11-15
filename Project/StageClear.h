#pragma once
#include "GameMenu.h"
#include "MenuInput.h"

class StageClear
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
	bool _goal;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetGoal(bool goal);
	bool IsGoal()const;
};
