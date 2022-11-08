#pragma once
#include "Mof.h"
#include "DeathCount.h"
#include "StageList.h"

class ListManager
{
private:
	DeathCount _deathCount;
	StageList* _stageList;
	int _cursor;
	const int _stageNoMin = 0;
	const int _stageNoMax = 1;
	const int _stageValue = 2;
	const Vector2 _scorePos = Vector2(0, 30);
	const Vector2 _debugPos = Vector2(500, 0);
	int _bestScore[2];
	int _iniScore;
	bool _debug;
	const int _cursorMoveVelue = 1;
	const int _index = 1;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void Select();
	int GetCursor() const{ return _cursor; }
};

