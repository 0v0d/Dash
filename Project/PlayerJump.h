#pragma once
#include	"Mof.h"

class PlayerJump
{
	const float	_gravity = 0.7;
	const float _jumpValue = -12;
	float	_moveY = 0;
	bool _jump;
public:
	void Initialize();
	void Jump();
	bool Isjump() const;
	float JumpValue() const { return _moveY; }
	void CollisionStage();
};