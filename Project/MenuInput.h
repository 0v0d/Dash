#pragma once

#include "Mof.h"
class MenuInput
{
private:
	int _cursor;
	const int _cursorMin = 0;
	const int _cursorMax = 1;
public:
	void SelectInput();
	void Initialize();
	void Select(const int cursor);
	int GetCursor() const;
};

