#include "PlayerJump.h"
void PlayerJump::Initialize()
{
	_moveY = 0;
	_jump = false;
}

void PlayerJump::Jump()
{
	_moveY += _gravity;
	if (g_pInput->IsKeyPush(MOFKEY_SPACE) && _jump == false)
	{
		_jump = true;
		_moveY += _jumpValue;
	}
	//test
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
