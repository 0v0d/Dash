#include	"Stage.h"

void Stage::SetStage(int stageNo)
{
	char* stageName;
	switch (stageNo)
	{
	case 1:
		stageName = "Stage1.txt";
		break;
	case 2:
		stageName = "Stage2.txt";
		break;
	}
	Load(stageName);
}

void Stage::Load(char* stageName)
{
	_file = fopen(stageName, "rt");
	if (_file == NULL)return;
	fseek(_file, 0, SEEK_END);
	_fileSize = ftell(_file);
	fseek(_file, 0, SEEK_SET);

	_buffer = new char[_fileSize + 1];
	_fileSize = fread(_buffer, 1, _fileSize, _file);
	_buffer[_fileSize] = '\0';


	if (!_backTexture.Load(strtok(_buffer, ",")))return;
	if (!_chipTexture.Load(strtok(NULL, ",")))return;
	_chipSize = atof(strtok(NULL, ","));
	_xSize = atoi(strtok(NULL, ","));
	_ySize = atoi(strtok(NULL, ","));
	_chipData = new char[_xSize * _ySize];

	for (int y = 0; y < _ySize; y++)
	{
		for (int x = 0; x < _xSize; x++)
		{
			_chipData[y * _xSize + x] = atoi(strtok(NULL, ","));
		}
	}

	fclose(_file);
	delete _buffer;
}

void Stage::Initialize()
{
	_screenWidth = g_pGraphics->GetTargetWidth();
	_screenHeight = g_pGraphics->GetTargetHeight();
	_backTextureWidth = _backTexture.GetWidth();
	_backTextureHeight = _backTexture.GetHeight();
	_stageSizeX = _chipSize * _xSize;
	_player.Initialize();
	_scrollX = 0;
	_scrollY = 0;
	_dead = false;
	_goal = false;
}

void Stage::Update()
{
	float ox = 0, oy = 0;
	if (Collision(_player.GetCollisionRect(), _player.GetJumpRect(), ox, oy))
	{
		_player.CollisionStage(ox, oy);
	}
	_player.Update();
	_player.SetGoal(IsGoal());

}

bool Stage::Collision(CRectangle playerCollision, CRectangle playerJumpRect, float& ox, float& oy)
{
	CRectangle playerJumpRect_ = playerJumpRect;
	if (playerJumpRect_.Right - _scrollX > _screenWidth - _playerScrollPos)
	{
		_scrollX += (playerJumpRect_.Right - _scrollX) - (_screenWidth - _playerScrollPos);
		if (_scrollX >= _stageSizeX - _screenWidth)
			_scrollX = _stageSizeX - _screenWidth;
	}

	_rect = false;
	_leftChipSize = playerJumpRect_.Left / _chipSize;
	_rightChipSize = playerJumpRect_.Right / _chipSize;
	_topChipSize = playerJumpRect_.Top / _chipSize;
	_bottomChipSize = playerJumpRect_.Bottom / _chipSize;

	if (_leftChipSize < 0)
	{
		_leftChipSize = 0;
	}
	if (_topChipSize < 0)
	{
		_topChipSize = 0;
	}
	if (_rightChipSize >= _xSize)
	{
		_rightChipSize = _xSize - 1;
	}
	if (_bottomChipSize >= _ySize)
	{
		_bottomChipSize = _ySize - 1;
	}

	for (int y = _topChipSize; y <= _bottomChipSize; y++)
	{
		for (int x = _leftChipSize; x <= _rightChipSize; x++)
		{
			CRectangle _chipRect(x * _chipSize, y * _chipSize, x * _chipSize + _chipSize, y * _chipSize + _chipSize);
			_chipNo = _chipData[y * _xSize + x] - 1;
			if (_chipNo < 0 || _chipNo == _notCollisonChip)
			{
				continue;
			}
			if (_chipNo == _goalchiptop || _chipNo == _goalchipbottom || _chipNo == _goalchipmiddle)
			{
				_goal = true;
			}
			if (_chipRect.CollisionRect(playerJumpRect_))
			{
				_rect = true;
				oy += _chipRect.Top - playerJumpRect_.Bottom;
				playerJumpRect_.Top += _chipRect.Top - playerJumpRect_.Bottom;
				playerJumpRect_.Bottom += _chipRect.Top - playerJumpRect_.Bottom;
			}
			else if (_chipRect.CollisionRect(playerCollision))
			{
				_rect = true;
				_dead = true;
			}
			if (_chipNo == _sankaku)
			{
				_dead = true;
			}

		}
	}
	return _rect;
}

void Stage::Render(void) {

	for (float y = ((int)-_scrollY % _backTextureHeight) - _backTextureHeight; y < _screenHeight; y += _backTextureHeight)
	{
		for (float x = ((int)-_scrollX % _backTextureWidth) - _backTextureWidth; x < _screenWidth; x += _backTextureWidth)
		{
			_backTexture.Render(x, y);
		}
	}

	_chipTextureSizeX = _chipTexture.GetWidth() / _chipSize;
	for (int y = 0; y < _ySize; y++)
	{
		for (int x = 0; x < _xSize; x++)
		{
			char _chipNo = _chipData[y * _xSize + x] - 1;
			if (_chipNo < 0)continue;
			CRectangle cr(_chipSize * (_chipNo % _chipTextureSizeX), _chipSize * (_chipNo / _chipTextureSizeX), _chipSize * (_chipNo % _chipTextureSizeX + 1), _chipSize * (_chipNo / _chipTextureSizeX + 1));
			_chipTexture.Render(-_scrollX + x * _chipSize, -_scrollY + y * _chipSize, cr);
		}
	}

	if (!IsDead())
	{
		_player.SetScoll(GetScrollX());
		_player.Render();
	}

}

void Stage::Debug()
{
	CGraphicsUtilities::RenderString(_debugPos.x, _debugPos.y, "ƒXƒNƒ[ƒ‹ X : %.0f", _scrollX);
	_player.Debug();
}

void Stage::Release()
{
	_chipTexture.Release();
	_backTexture.Release();
	_player.Release();
	if (_chipData != nullptr) 
	{
		delete[]_chipData;
	}
}

bool Stage::IsDead()
{
	return _dead;
}

bool Stage::IsGoal()
{
	return _goal;
}

float Stage::GetScrollX()
{
	return _scrollX;
}