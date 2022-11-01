#include "GameMenu.h"



void GameMenu::Create(char* title, char** text, int cnt)
{
	Release();
	_count = cnt;
	_title = new char[strlen(title) + strIndex];
	strcpy(_title, title);
	_text = new char* [sizeof(char*) * cnt];
	for (int i = 0; i < _count; i++)
	{
		_text[i] = new char[strlen(text[i]) + strIndex];
		strcpy(_text[i], text[i]);
	}

	CRectangle trec;
	CGraphicsUtilities::CalculateStringRect(0, 0, _title, trec);
	_rect.Right = max(_rect.Right, trec.Right + _heightSpace * _adjust);
	_rect.Bottom += trec.Bottom + _space * _adjust;
	_headerRect = _rect;
	for (int i = 0; i < _count; i++)
	{
		CGraphicsUtilities::CalculateStringRect(0, 0, _text[i], trec);
		_headerRect.Right = _rect.Right = max(_rect.Right, trec.Right + _heightSpace * _adjust);
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
	CGraphicsUtilities::CalculateStringRect(0, 0, _title, trec);
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

void GameMenu::Release()
{
	if (_title)
	{
		delete _title;
		_title = nullptr;
	}
	if (_text)
	{
		for (int i = 0; i < _count; i++)
		{
			delete _text[i];
		}
		delete _text;
		_text = nullptr;
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
