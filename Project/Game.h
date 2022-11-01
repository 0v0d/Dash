#pragma once
#include "IBaseScene.h"
#include "SceneManager.h"
#include "Stage.h"
#include "DeathCount.h"
#include "StartTimeCount.h"
#include  "Pause.h"
#include  "StageClear.h"
class Game : public IBaseScene
{
private:
	DeathCount _deathCount;
	Stage  _stage;
	Pause _pause;
	StageClear _stageClear;
	StartTimeCount _time; const Vector2 _deathCountPos = Vector2(0, 0);
	const Vector2 _scorePos = Vector2(0, 20);
	const Vector2 _configurationPos = Vector2(0, 40);
	bool _debug;
	int _bestScore;
	int _stageNo;
	int _count;
	void SceneChange();
	void SetCount();
	void GameMenuUpdate();
	void PlayerDeathUpdate();
	void PlayerGoalUpdate();
	void StageUpdate();
	void Debug();
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetStage(int stageNo);

};

