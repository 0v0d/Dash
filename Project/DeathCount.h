#pragma once
#include "Mof.h"
class DeathCount
{
private:
	int _deathCount;
	int _BestScore;
	char* _countText;
	int _stageNumber;
	const int  _iniScore = 9999;
public:
	void Initialize();
	void count(int cnt);
	void UpdateBestScore();
	int GetBestScore();
	int GetScore();
	int GetBestScoreFromFile(char* fileName);
	bool SetBestScoreToFile();
	void SetDeathCount(int stageNo);
	void SetTextFile(int stageNo);
	int GetIniScore() const { return _iniScore; }
};
