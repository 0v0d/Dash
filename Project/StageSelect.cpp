#include "StageSelect.h"

void StageSelect::Initialize()
{
	_backTexture.Load("Space.png");
	_listManager.Initialize();
}

void StageSelect::Update()
{
	_listManager.Update();
	if(g_pInput->IsKeyPush(MOFKEY_SPACE))
	{
		switch (_listManager.GetCursor())
		{
		case 0:
			SceneManager::Instance().SetStage(1);
			SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
			break;
		case 1:
			SceneManager::Instance().SetStage(2);
			SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
			break;
		}
	}
}

void StageSelect::Render()
{
	_backTexture.Render(_backTexturePos.x, _backTexturePos.y);
	_listManager.Render();

	CGraphicsUtilities::RenderString(_configurationPos.x, _configurationPos.y, "A:Å©  D:Å®  SPACE:åàíË");
}

void StageSelect::Release()
{
	_backTexture.Release();
	_listManager.Release();
}