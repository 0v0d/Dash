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
	void SetGoal(const bool goal);
	bool IsGoal()const;
	void Release();
};