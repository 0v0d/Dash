#include "DeathCount.h"

void DeathCount::Initialize()
{
	_deathCount = 0;
}

void DeathCount::count(int cnt)
{
	_deathCount += cnt;
}

int DeathCount::GetScore()
{
	return _deathCount;
}

void DeathCount::UpdateBestScore()
{
	if (_deathCount < _BestScore)
	{
		_BestScore = _deathCount;
		SetBestScoreToFile();
	}
}

int DeathCount::GetBestScoreFromFile(char* fileName)
{
	_countText = fileName;
	int score = 0;
	CReadTextFile read(_countText);
	score = read.ReadU32();
	return score;
}

bool DeathCount::SetBestScoreToFile()
{
	CWriteTextFile write(_countText);
	write.WriteU32(_deathCount);
	return false;
}

void DeathCount::SetTextFile(int stageNo)
{
	switch (stageNo)
	{
	case 1:
		_countText = "DeathCount1.txt";
		break;
	case 2:
		_countText = "DeathCount2.txt";
		break;
	}
	GetBestScoreFromFile(_countText);
}

int DeathCount::GetBestScore()
{
	_BestScore = GetBestScoreFromFile(_countText);
	return _BestScore;
}