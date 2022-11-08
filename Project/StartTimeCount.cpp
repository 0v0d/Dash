#include "StartTimeCount.h"
void StartTimeCount::Initialize()
{
	_pos.x = CGraphicsUtilities::GetGraphics()->GetTargetWidth()/2;
	_pos.y = CGraphicsUtilities::GetGraphics()->GetTargetHeight()/2;
	_countDownTime = _countTime;
	_start = false;
}

void StartTimeCount::Update()
{
	Tick();
	if(_countDownTime < 0)
	{
		_start = true;
	}
}

void StartTimeCount::Tick()
{
	_countDownTime -= CUtilities::GetFrameSecond();
}

void StartTimeCount::Render()
{
	if (!IsStart())
	{
		CGraphicsUtilities::RenderString(_pos.x, _pos.y, "%.0f", _countDownTime);
	}
		
}