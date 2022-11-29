#pragma once
#include	"Player.h"
#include<memory>
class Stage{
private:
	Player _player;
	bool _dead;
	bool _goal;
	char* _chipData = nullptr;
	CTexture _chipTexture;
	CTexture _backTexture;
	float _chipSize;
	float _playerScrollPos = 850.0f;
	float _scrollX;
	int	_xSize, _ySize;
	const int _goalchiptop = 9;
	const int _goalchipbottom = 10;
	const int _goalchipmiddle = 24;
	const int _sankaku = 8;
	const int _notCollisonChip = 4;
	char _chipNo;
	int _screenWidth;
	int _screenHeight;
	int _backTextureWidth;
	int _backTextureHeight;
	float _stageSizeX;
	int _leftChipSize;
	int  _rightChipSize;
	int  _topChipSize;
	int _bottomChipSize;
	bool _rect;
	char* _buffer;
	long _fileSize;
	FILE* _file;
	int _chipTextureSizeX;
	const Vector2 _debugPos = Vector2(10, 100);
	bool _endMotion;
public:
	void StageObjectInitalize();
	void SetStage(int stageNo);
	void Load(char* stageName);
	void Initialize();
	void Update();
	void Render();
	void Debug();
	void Release();
	bool Collision(CRectangle collisionRect, CRectangle playerJumpRect, float& ox, float& oy);
	bool IsDead();
	bool IsGoal();
	float GetScrollX();
	void SetEndMotion(bool endMotion) { _endMotion = endMotion; }
	bool IsEndMotion() { return _endMotion; }
};