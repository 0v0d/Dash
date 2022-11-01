#pragma once
#include "IBaseScene.h"
#include "SceneManager.h"
class Title :public IBaseScene
{
private:
	CTexture _backTexture;
	CRectangle _backSize;
public:

	void Initialize();
	void Update();
	void Render();
	void Release();
};

