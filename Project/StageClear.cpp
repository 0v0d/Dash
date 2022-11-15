#include "StageClear.h"
void StageClear::Initialize()
{
	_input.Initialize();
	_goal =false;
	_title = "StageClear";
	_menu.Create(_title, _text, _textCount);
}

void StageClear::Update()
{
	if (IsGoal())
	{
		_input.SelectInput();
		_input.SelectInput();
		_menu.SetCoursor(_input.GetCursor());
		_menu.Show();
	}
}

void StageClear::Render()
{
	if (IsGoal())
	{
		_menu.Render();
		CGraphicsUtilities::RenderString(0, 300, "%d", _input.GetCursor());
	}
}

void StageClear::Release()
{
	_menu.Release();
}

void StageClear::SetGoal(const bool goal)
{
	_goal = goal;
}

inline bool StageClear::IsGoal()const
{
	return _goal;
}