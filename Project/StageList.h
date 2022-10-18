#pragma once
#include "Mof.h"
class StageList
{
private:

	Vector2 _texturePos;
	int _cursor;
	const int _stageValue = 2;
	CTexture* _texture = new CTexture[_stageValue];
	const int _eighth = 8;
	const int _sixth = 6;
public:
	void Load();
	void Initialize();
	void Render();
	void Release();
	void SetCursor(int cursor) { _cursor = cursor; }
};