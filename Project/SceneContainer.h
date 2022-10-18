#pragma once
#include "IBaseScene.h"
class SceneContainer
{
public:
	IBaseScene* _gameScene = nullptr;
	IBaseScene* _titleScene = nullptr;
	IBaseScene* _stageSelectScene = nullptr;
	SceneContainer(IBaseScene* game, IBaseScene* title, IBaseScene* stageselect)
	{
		_gameScene = game;
		_titleScene = title;
		_stageSelectScene = stageselect;
	}
};