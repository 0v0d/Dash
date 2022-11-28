#pragma once
#include "mof.h"
#include <string>
class PlayerDeadAnimation
{
private:
	CTexture _deadAnimation;
	const std::string _deadAnimationTexture = "effect02.png";
	CSpriteMotionController _controller;
	Vector2 _pos;
	Vector2 _playerPos;
	float _worldPos;
	CRectangle _showRect;
	bool _show;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetPlayerPos(Vector2 playerPos) { _playerPos = playerPos; }
	void SetWorldPos(float worldPos) { _worldPos = worldPos; }
	void SetShow(bool dead) { _show = dead; }
	void SetStatu();
private:
	
};