#pragma once
#include "GameMenu.h"
class StageClear
{
private:
	GameMenu _menu;
	char* _title;
	static const int _textCount = 2;
	char* _text[_textCount] = {
		"StageSelect",
		"Exit"
	};
	bool _goal;
public:
	void Initialize();
	void Update();
	void Render();
	void SetGoal(bool goal) { _goal = goal; }
	bool IsGoal() { return _goal; }
	void Release();
};