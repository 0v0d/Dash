#include "StageClear.h"
void StageClear::Initialize()
{
	_goal = false;
	_title = "StageClear";

	_menu.Create(_title, _text, _textCount);
}

void StageClear::Update()
{
	if (IsGoal())
	{
		_menu.Show();
	}
}

void StageClear::Render()
{
	_menu.Render();
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