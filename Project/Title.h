#pragma once
#include "IBaseScene.h"
#include "SceneManager.h"
#include "Font.h"
class Title:public IBaseScene
{
private:
	Font _font;
	CTexture _backTexture;
	LPMofChar _message;
	CRectangle _backSize;
	const Vector2 _strPos = Vector2(150, 350);
	const float _fontSize = 32;
public:
	
	void Initialize();
	void Update();
	void Render();
	void Release();
};

