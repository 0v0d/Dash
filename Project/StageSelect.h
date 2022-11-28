#pragma once
#include "IBaseScene.h"
#include "SceneManager.h"
#include "ListManager.h"
class StageSelect : public IBaseScene
{
private:
	CTexture _backTexture;
	ListManager _listManager;
	Vector2 _backTexturePos = Vector2(0, 0);
	const Vector2 _configurationPos = Vector2(600,0);
public:
	void Initialize()  override;
	void Update() override;
	void Render() override;
	void Release() override;
};