#pragma once
#include "IBaseScene.h"
#include "SceneManager.h"

class Title :public IBaseScene
{
private:
	CTexture _backTexture;
	CRectangle _backSize;
public:
	void Initialize() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

