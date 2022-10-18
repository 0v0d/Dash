#pragma once
#include "StageClear.h"
#include "Pause.h"
#include "Mof.h"
class GameMenu
{
private:
	StageClear _stageClear;
	Pause _pause;
	int _cursor;
	const int _cursorMin = 0;
	const int _cursorMax = 1;
	bool _stop;
	bool _sceneChange;
	bool _goal;
	int _count;
	char* _title;
	char** _text;
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
	void Select(int cursor);
	void SelectInput();
	void PauseInitialize();
	void ClearInitialize();
	void Create(char* title, char** text, int cnt);
public:
	GameMenu();
	void Initialize();
	void Update();
	void Render();
	void Release();
	void PauseUpdate();
	bool IsPause() { return  _stop; }
	bool IsSceneChange() { return _sceneChange; }
	void SetGoal(bool goal);
	void Show();
};

