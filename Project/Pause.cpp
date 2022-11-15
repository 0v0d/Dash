#include "Pause.h"

void Pause::Initialize()
{
	
	_title = "Pause";
	_input.Initialize();
	_pause = false;
	_menu.Create(_title, _text, _textCount);
}

void Pause::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		_pause = !_pause;
	}
	if(IsPause())
	{
		_input.SelectInput();
		_input.SelectInput();
		_menu.SetCoursor(_input.GetCursor());
		_menu.Show();
	}
}

void Pause::Render()
{
	if(IsPause())
	{
		_menu.Render();
		CGraphicsUtilities::RenderString(0, 300, "%d", _input.GetCursor());
	}
	
}

void Pause::Release()
{
	_menu.Release();
}
