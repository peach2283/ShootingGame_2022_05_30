#include "ShootingGame.h"

GameBG::GameBG(string tag, string name, bool active, float px, float py)
		:Sprite(tag, name, active, px, py)
{}

GameBG::~GameBG()
{}

void GameBG::Start()
{
	//스플라이이트 이미지..로드하기
	SetSprite("Asset/게임배경.bmp");
}

void GameBG::Update()
{}
