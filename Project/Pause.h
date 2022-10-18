#pragma once
class Pause
{
private:
	char* _title = "Pause";
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

