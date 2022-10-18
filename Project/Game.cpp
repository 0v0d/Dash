#include "Game.h"

void Game::Initialize()
{
	_debug =false;
	_gameMenu.Initialize();
	_stage.Initialize();
	_deathCount.Initialize();
	_time.Initialize();
}

void Game::Update()
{
	Debug();

	SetCount();

	GameMenuUpdate();

	PlayerDeathUpdate();

	PlayerGoalUpdate();

	if (_gameMenu.IsPause())
		return;

	_time.Update();

	StageUpdate();
}

void Game::Debug()
{
	if (g_pInput->IsKeyPush(MOFKEY_1))
		_debug = !_debug;
}


void Game::SetCount()
{
	_count = _deathCount.GetScore();
	_bestScore = _deathCount.GetBestScore();
}

void Game::GameMenuUpdate()
{
	_gameMenu.SetGoal(_stage.IsGoal());
	if (!_stage.IsGoal())
		_gameMenu.PauseUpdate();

	SceneChange();
	_gameMenu.Update();
}

void Game::SceneChange()
{
	if (_gameMenu.IsSceneChange())
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
}

void Game::PlayerDeathUpdate()
{
	if (_stage.GetDead())
	{
		_deathCount.count(1);
		_stage.Initialize();
		_time.Initialize();
	}
}

void Game::PlayerGoalUpdate()
{
	if (_stage.IsGoal())
		_deathCount.UpdateBestScore();
}

void Game::StageUpdate()
{
	if (_time.IsStart())
		_stage.Update();
}

void  Game::Render()
{
	_stage.Render();
	CGraphicsUtilities::RenderString(_deathCountPos.x, _deathCountPos.y, MOF_COLOR_RED, "DeathCount : %d", _count);
	if (_bestScore == _deathCount.GetIniScore())
		CGraphicsUtilities::RenderString(_scorePos.x, _scorePos.y, " ");
	else
		CGraphicsUtilities::RenderString(_scorePos.x, _scorePos.y, MOF_COLOR_RED, "Best : %d", _bestScore);
	
	_time.Render();

	if(_gameMenu.IsPause())
		_gameMenu.Render();

	else if(_stage.IsGoal())
		_gameMenu.Render();

	if (_debug)
		_stage.Debug();

	CGraphicsUtilities::RenderString(_configurationPos.x, _configurationPos.y, MOF_COLOR_RED,
		"SPACE:JUMP  ESC:PAUSE 1:DEBUG");
}

void  Game::Release()
{
	_gameMenu.Release();
	_stage.Release();
}

void Game::SetStage(int stageNo)
{
	_stageNo = stageNo;
	_stage.SetStage(_stageNo);
	_deathCount.SetTextFile(_stageNo);
}