#include "ShootingGame.h"

GameBG::GameBG(float px, float py) : Sprite("게임배경", "", true, px, py, 0)
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
