#pragma once
class StageClear
{
private:
	const int _StageSelectHeight = 40;
	const int _exitHeight = 70;
	char* _title = "StageClear";
	static const int _textCount = 2;
	char* _text[_textCount] = {
		"StageSelect",
		"Exit"
	};
public:
	char* GetTitle() { return _title; }
	int GetTextCount() { return _textCount; }
	char** GetText() { return _text; }
};

