#include "Title.h"

void Title::Initialize()
{
	_backTexture.Load("title.png");
	_backSize = CRectangle(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
}

void Title::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_SPACE))
	{
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
}

void Title::Render()
{
	_backTexture.Render(_backSize);
}

void Title::Release()
{
	_backTexture.Release();
}
