#pragma once
#include	"Mof.h"
#include "PlayerJump.h"
#include <string>
class Player
{
private:
	PlayerJump _playerJump;
	const float _speed = 7;
	const Vector2 _iniPos = Vector2(50, 526);
	const std::string _playerTexture = "Player.png";
	float _textureWidth;
	float _textureHeight;
	const Vector2 _rectDecreace = Vector2(5, 10);
	const int _rectIncreaceY = 40;
	const int _jumpRectAdjust = 5;
	float _scroll;
	bool	_jump;
	bool	_dead;
	bool	_goal;
	Vector2 _pos;
	CTexture _texture;
	CRectangle _collisionRect;
	CRectangle _jumpRect;
	const Vector2 _debugPos = Vector2(10, 70);
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetDead(const bool dead);
	void Debug();
	void SetGoal(const bool goal);
	void CollisionStage(float x, float y);
	bool IsDead() const;
	CRectangle GetCollisionRect() const { return _collisionRect; }
	CRectangle GetJumpRect() const { return  _jumpRect; }
	void SetScoll(const float scroll) { _scroll = scroll; }
private:
	void Move();
	void Jump();
	void RectUpdate();
};