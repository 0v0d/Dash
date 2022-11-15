#include "PlayerJump.h"
void PlayerJump::Initialize()
{
	_moveY = 0;
	_jump = false;
}

void PlayerJump::Jump()
{
	_moveY += _gravity;
	if (g_pInput->IsKeyPush(MOFKEY_SPACE) && Isjump() == false)
	{
		_jump = true;
		_moveY += _jumpValue;
	}
}

void PlayerJump::CollisionStage()
{
	if (_moveY > 0)
	{
		_moveY = 0;
		if (_jump)
		{
			_jump = false;
		}
	}
}

inline bool PlayerJump::Isjump() const
{
	return _jump;
}