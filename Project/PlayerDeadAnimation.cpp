#include "PlayerDeadAnimation.h"
void PlayerDeadAnimation::Initialize() 
{
	_deadAnimation.Load(_deadAnimationTexture.c_str());
	SpriteAnimationCreate _deadAnimation[] = {
		{
			"dead",
			0,0,
			120,120,
			false,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0},{3,10,0},{3,11,0},{3,12,0},{3,13,0},{3,14,0},{3,15,0}}
		},
	};
	_controller.Create(_deadAnimation, 1);
	_controller.ChangeMotion(0);
	_endMotion = false;
	_show = false;
}

void  PlayerDeadAnimation::SetStatu()
{
	_pos.x = _playerPos.x - _showRect.GetWidth() / 8;
	_pos.y = _playerPos.y - _showRect.GetHeight() / 4;
	_showRect = _controller.GetSrcRect();
}

void PlayerDeadAnimation::Update() 
{
	_controller.AddTimer(CUtilities::GetFrameSecond());
	SetStatu();
	if (_controller.IsEndMotion())
	{
		_endMotion = true;
	}
}

void PlayerDeadAnimation::Render() 
{
	_deadAnimation.Render(_pos.x - _worldPos, _pos.y, _showRect);
}

void PlayerDeadAnimation::Release() 
{
	_deadAnimation.Release();
	_controller.Release();
}
