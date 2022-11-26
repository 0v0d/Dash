#include "Player.h"

void Player::Initialize()
{
	_texture.Load("Player.png");
	_pos = _iniPos;
	_jump = false;
	_dead = false;
	_goal = false;
	_textureWidth = _texture.GetWidth();
	_textureHeight = _texture.GetHeight();
	RectUpdate();
}

void Player::Update()
{
	Jump();
	if (!_goal)
	{
		Move();
	}
	RectUpdate();
}

void Player::Move()
{
	_pos.x += _speed;
}

void Player::Jump()
{
	_pos.y += _playerJump.JumpValue();
	_playerJump.Jump();
}

void Player::RectUpdate()
{
	_collisionRect = CRectangle(_pos.x + _rectDecreace.x, _pos.y,
		_pos.x + _textureWidth,
		_pos.y + _textureHeight - _rectDecreace.y);

	_jumpRect = CRectangle(_pos.x + _jumpRectAdjust, _pos.y,
		_pos.x + _textureWidth - _jumpRectAdjust,
		_pos.y + _textureHeight);
}

void Player::Render()
{
	_texture.Render(_pos.x - _scroll, _pos.y);
}

void Player::CollisionStage(float x, float y)
{
	_pos.x += x;
	
	_pos.y += y;
	_playerJump.CollisionStage();
}

void Player::Release()
{
	_texture.Release();
}

void Player::Debug()
{
	CGraphicsUtilities::RenderString(_debugPos.x, _debugPos.y, "プレイヤー位置 X : %.0f , Y : %.0f ", _pos.x, _pos.y);
	CGraphicsUtilities::RenderRect(_collisionRect.Left - _scroll, _collisionRect.Top, _collisionRect.Right - _scroll, _collisionRect.Bottom, MOF_COLOR_HYELLOW);
	CGraphicsUtilities::RenderRect(_jumpRect.Left - _scroll, _jumpRect.Top , _jumpRect.Right - _scroll, _jumpRect.Bottom, MOF_COLOR_RED);
}

void Player::SetGoal(const bool goal)
{
	_goal = goal;
}


void Player::SetDead(const bool dead)
{
	_dead = dead;
}


