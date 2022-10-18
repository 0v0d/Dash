#include "GameMenu.h"

GameMenu::GameMenu() :
_text(NULL),
_count(0),
_title(NULL)
{}

void GameMenu::Initialize()
{
	_cursor = 0;
	_sceneChange = false;
	_stop = false;
	_goal = false;
}

void GameMenu::PauseInitialize()
{
	Create(_pause.GetTitle(), _pause.GetText(), _pause.GetTextCount());
}

void GameMenu::ClearInitialize()
{
	Create(_stageClear.GetTitle(), _stageClear.GetText(), _stageClear.GetTextCount());
}

void GameMenu::Create(char* title, char** text, int cnt)
{
	Release();
	_count = cnt;
	_title = (char*)malloc(strlen(title) + strIndex);
	strcpy(_title, title);
	_text = (char**)malloc(sizeof(char*) * cnt);
	for (int i = 0; i < _count; i++)
	{
		_text[i] = (char*)malloc(strlen(text[i]) + strIndex);
		strcpy(_text[i], text[i]);
	}

	CRectangle trec;
	CGraphicsUtilities::CalculateStringRect(0, 0, _title, trec);
	_rect.Right = MOF_MAX(_rect.Right, trec.Right + _heightSpace * _adjust);
	_rect.Bottom += trec.Bottom + _space * _adjust;
	_headerRect = _rect;
	for (int i = 0; i < _count; i++)
	{
		CGraphicsUtilities::CalculateStringRect(0, 0, _text[i], trec);
		_headerRect.Right = _rect.Right = MOF_MAX(_rect.Right, trec.Right + _heightSpace * _adjust);
		_rect.Bottom += trec.Bottom + _space;
	}
	_rect.Bottom += _space;
}

void GameMenu::Render()
{
	CGraphicsUtilities::RenderFillRect(_rect, MOF_ARGB(200, 0, 0, 0));
	CGraphicsUtilities::RenderFillRect(_headerRect, MOF_ARGB(200, 64, 64, 64));
	CRectangle trec;
	float py = _rect.Top + _space;
	CGraphicsUtilities::CalculateStringRect(0, 0, _title,trec);
	CGraphicsUtilities::RenderString(_screenWidth - trec.GetWidth() * _half, py, MOF_COLOR_WHITE, _title);
	py += trec.Bottom + _space;
	for (int i = 0; i < _count; i++)
	{
		CGraphicsUtilities::CalculateStringRect(0, 0, _text[i], trec);
		CGraphicsUtilities::RenderString(_screenWidth - trec.GetWidth() * _half, py + _space,
			((_cursor == i) ? MOF_XRGB(255, 255, 255) : MOF_XRGB(128, 128, 128)), _text[i]);
		py += trec.Bottom + _space;
	}
}

void GameMenu::Update()
{
	if(_stop)
	{
		SelectInput();
		PauseInitialize();
		Show();
	}
	else if(_goal)
	{
		SelectInput();
		ClearInitialize();
		Show();
	}
}


void GameMenu::Release()
{
	if (_title)
	{
		free(_title);
		_title = NULL;
	}
	if (_text)
	{
		for (int i = 0; i < _count; i++)
		{
			free(_text[i]);
		}
		free(_text);
		_text = NULL;
		_count = 0;
	}
	_rect = CRectangle(0, 0, 0, 0);
}

void GameMenu::Show()
{
	_screenWidth = g_pGraphics->GetTargetWidth() * _half;
	_screenHeight = g_pGraphics->GetTargetHeight() * _half;
	_rectWidth = _rect.GetWidth();
	_rectHeight = _rect.GetHeight();
	_rect.Top = _screenHeight - _rectHeight * _half;
	_rect.Bottom = _rect.Top + _rectHeight;
	_rect.Left = _screenWidth - _rectWidth * _half;
	_rect.Right = _rect.Left + _rectWidth;
	_headerRect.Bottom = _rect.Top + _headerRect.GetHeight();
	_headerRect.Top = _rect.Top;
	_headerRect.Right = _rect.Left + _headerRect.GetWidth();
	_headerRect.Left = _rect.Left;
}

void GameMenu::PauseUpdate()
{
	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
		_stop = !_stop;
}

void GameMenu::SelectInput()
{
	if (g_pInput->IsKeyPush(MOFKEY_W))
		Select(-1);

	if (g_pInput->IsKeyPush(MOFKEY_S))
		Select(1);

	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		switch (_cursor)
		{
		case 0:
			_sceneChange = true;
			break;
		case 1:
			PostQuitMessage(0);
			break;
		}
	}
}

void GameMenu::Select(int cursor)
{
	_cursor += cursor;

	if (_cursor > _cursorMax)
		_cursor = _cursorMax;

	if (_cursor < _cursorMin)
		_cursor = _cursorMin;
}


void GameMenu::SetGoal(bool goal)
{
	_goal = goal;
}


