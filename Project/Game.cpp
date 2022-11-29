#include "Game.h"

void Game::Initialize()
{
	_debug = false;
	_stage.Initialize();
	_deathCount.Initialize();
	_time.Initialize();
	_pause.Initialize();
	_stageClear.Initialize();
}

void Game::Update()
{
	Debug();

	SetCount();

	GameMenuUpdate();

	if (_pause.IsPause())
	{
		return;
	}

	PlayerDeathUpdate();

	PlayerGoalUpdate();

	_time.Update();

	StageUpdate();
}

void Game::Debug()
{
	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		_debug = !_debug;
	}
}


void Game::SetCount()
{
	_count = _deathCount.GetScore();
	_bestScore = _deathCount.GetBestScore();
}

void Game::GameMenuUpdate()
{
	_stageClear.SetGoal(_stage.IsGoal());

	if (_stage.IsGoal() == false)
	{
		_pause.Update();
	}

	SceneChange();
	_stageClear.Update();
}

void Game::SceneChange()
{
	/*if (_pause.IsChangeScene()||_stageClear.IsChangeScene())
	{
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}*/
}


void Game::PlayerDeathUpdate()
{
	if (_stage.IsEndMotion())
	{
		
		_stage.StageObjectInitalize();
		_time.Initialize();
	}
	if(_stage.IsDead())
	{
		_deathCount.count(1);
	}
}

void Game::PlayerGoalUpdate()
{
	if (_stage.IsGoal())
	{
		_deathCount.UpdateBestScore();
	}
}

void Game::StageUpdate()
{
	if (_time.IsStart())
	{
		_stage.Update();
	}
}

void  Game::Render()
{
	_stage.Render();
	CGraphicsUtilities::RenderString(_deathCountPos.x, _deathCountPos.y, MOF_COLOR_RED, "DeathCount : %d", _count);
	if (_bestScore == _deathCount.GetIniScore())
	{
		CGraphicsUtilities::RenderString(_scorePos.x, _scorePos.y, " ");
	}
	else
	{
		CGraphicsUtilities::RenderString(_scorePos.x, _scorePos.y, MOF_COLOR_RED, "Best : %d", _bestScore);
	}

	_time.Render();

	if (_pause.IsPause())
	{
		_pause.Render();
	}

	else if (_stage.IsGoal())
	{
		_stageClear.Render();
	}

	if (_debug)
	{
		_stage.Debug();
	}

	CGraphicsUtilities::RenderString(_configurationPos.x, _configurationPos.y, MOF_COLOR_RED,
		"SPACE:JUMP  ESC:PAUSE 1:DEBUG");
}

void  Game::Release()
{
	_stageClear.Release();
	_pause.Release();
	_stage.Release();
}

void Game::SetStage(int stageNo)
{
	_stageNo = stageNo;
	_stage.SetStage(_stageNo);
	_deathCount.SetTextFile(_stageNo);
}