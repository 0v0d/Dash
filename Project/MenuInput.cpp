#include "MenuInput.h"

#include "SceneManager.h"

void MenuInput::Initialize()
{
	_cursor = 0;
}

void MenuInput::SelectInput()
{
	if (g_pInput->IsKeyPush(MOFKEY_W))
	{

		Select(-1);
	}

	if (g_pInput->IsKeyPush(MOFKEY_S))
	{
		Select(1);

	}

	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		switch (_cursor)
		{
		case 0:
			SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);

			break;
		case 1:
			PostQuitMessage(0);
			break;
		}
	}
}
void MenuInput::Select(int cursor)
{
	_cursor += cursor;

	if (_cursor > _cursorMax)
	{
		_cursor = _cursorMax;
	}
	if (_cursor < _cursorMin)
	{
		_cursor = _cursorMin;
	}

}