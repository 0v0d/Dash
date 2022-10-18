#pragma once
#include "Mof.h"
class StartTimeCount
{
private:
	float _countDownTime;
	const float _countTime = 3;
	bool _start = false;
	Vector2 _pos;
	void Tick();
	float GetNowTime() { return _countDownTime; }
public:
	void Initialize();
	void Update();
	void Render();
	bool IsStart() { return  _start; }

};

