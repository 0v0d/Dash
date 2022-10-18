#include "Title.h"

void Title::Initialize()
{
	_font.Load();
	_backTexture.Load("title.png");
	_message = "Press Space To Start";
	_backSize = CRectangle(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
}

void Title::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_SPACE))
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
}

void Title::Render()
{
	_backTexture.Render(_backSize);
	_font.String(_strPos.x, _strPos.y, _fontSize , _message);
}

void Title::Release()
{
	_backTexture.Release();
	_font.Release();
}
