#pragma once

#include  "SceneContainer.h"
#include "Game.h"
#include "Title.h"
#include "StageSelect.h"
#include "IBaseScene.h"

enum SCENE_TYPE
{
	TITLE,
	STAGESELECT,
	GAME
};

class SceneManager
{
	static SceneManager* instance;
private:
	SceneContainer* sceneContainer;
	IBaseScene* nowScene;
	SceneManager();
public:

	static SceneManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new SceneManager();
		}
		return *instance;
	};
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetStage(int stageNo);
	void ChangeScene(SCENE_TYPE type);
};