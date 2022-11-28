#include "ListManager.h"


void ListManager::Initialize()
{
	_stageList = new StageList[_stageValue];
	_cursor = 0;
	_debug = false;
	_stageList->Load();
	for (int i = 0; i < _stageValue; i++)
	{
		_stageList[i].Initialize();
	}
}
void ListManager::Update()
{
	Select();
	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		_debug = true;
	}

	for (int i = 0; i < _stageValue; i++)
	{
		_deathCount.SetTextFile(i + _index);
		_bestScore[i] = _deathCount.GetBestScore();
	}
}
void ListManager::Render()
{
	CGraphicsUtilities::RenderString(0, 0, "StageSelect");
	_stageList->SetCursor(_cursor);
	for (int i = 0; i < _stageValue; i++)
	{
		_stageList[i].Render();
	}
	if(_debug)
	{
		CGraphicsUtilities::RenderString(_debugPos.x, _debugPos.y, "%d", _cursor);
	}
	if (_bestScore[_cursor] == _deathCount.GetIniScore())
	{
		CGraphicsUtilities::RenderString(_scorePos.x, _scorePos.y, "Best Score : Not Cleared");
	}
	else
	{
		CGraphicsUtilities::RenderString(_scorePos.x, _scorePos.y, "Best Score : %d", _bestScore[_cursor]);
	}
}

void ListManager::Release()
{
	_stageList->Release();
}

void ListManager::Select()
{
	if (g_pInput->IsKeyPush(MOFKEY_D))
	{
		_cursor+= _cursorMoveVelue;
		if (_cursor > _stageNoMax)_cursor = _stageNoMax;
	}

	if (g_pInput->IsKeyPush(MOFKEY_A))
	{
		_cursor-= _cursorMoveVelue;
		if (_cursor < _stageNoMin)_cursor = _stageNoMin;
	}
}
