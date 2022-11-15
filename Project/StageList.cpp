#include "StageList.h"
void StageList::Load ()
{
	_texture[0].Load("1.png");
	_texture[1].Load("2.png");
}

void StageList::Initialize()
{
	_cursor = 0;
	_texturePos = Vector2(g_pGraphics->GetTargetWidth() / _eighth, g_pGraphics->GetTargetHeight() / _sixth);
}

void StageList::Render()
{
	_texture[_cursor].Render(_texturePos.x, _texturePos.y);
}

void StageList::Release()
{
	for(int i = 0; i< _stageValue; i++)
	{
		_texture[i].Release();
	}
}
