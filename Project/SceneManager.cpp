#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
	sceneContainer = new SceneContainer(new Game, new Title, new StageSelect);
	nowScene = sceneContainer->_titleScene;
}

void SceneManager::Initialize()
{
	sceneContainer->_gameScene->Initialize();
	sceneContainer->_titleScene->Initialize();
	sceneContainer->_stageSelectScene->Initialize();
}
void SceneManager::Update()
{
	nowScene->Update();
}
void SceneManager::Render()
{
	nowScene->Render();
}
void SceneManager::Release()
{
	sceneContainer->_titleScene->Release();
	sceneContainer->_gameScene->Release();
	sceneContainer->_stageSelectScene->Release();
}
void SceneManager::ChangeScene(SCENE_TYPE type)
{
	switch (type)
	{
	case SCENE_TYPE::TITLE:
		nowScene = sceneContainer->_titleScene;
		break;
	case SCENE_TYPE::STAGESELECT:
		nowScene = sceneContainer->_stageSelectScene;
		break;
	case SCENE_TYPE::GAME:
		nowScene = sceneContainer->_gameScene;
		sceneContainer->_gameScene->Initialize();
		break;
	}
}
void SceneManager::SetStage(int stageNo)
{
	Game* game = dynamic_cast<Game*> (sceneContainer->_gameScene);
	game->SetStage(stageNo);
}