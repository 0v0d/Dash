
#pragma once
#include	"Mof.h"
#include "PlayerJump.h"
class Player
{
private:
	PlayerJump _playerJump;
	const float _speed = 7;
	const Vector2 _iniPos = Vector2(50, 526);
	float _textureWidth;
	float _textureHeight;
	const Vector2 _rectDecreace = Vector2(5, 10);
	const int _rectIncreaceY = 40;
	const int _jumpRectAdjust = 5;
	bool	_jump;
	bool	_death;
	bool	_goal;
	Vector2 _pos;
	CTexture _texture;
	CRectangle _collisionRect;
	CRectangle _jumpRect;
	const Vector2 _debugPos = Vector2(10, 70);
	void Move();
	void Jump();
	void RectUpdate();
public:
	void Initialize();
	void Update();
	void Render(float wx);
	void Release();
	void Damaged(bool collison);
	void Debug(float wx);
	void Goal(bool goal);
	void CollisionStage(float ox, float oy);
	CRectangle GetCollisionRect() { return _collisionRect; }
	CRectangle GetJumpRect() { return  _jumpRect; }
};