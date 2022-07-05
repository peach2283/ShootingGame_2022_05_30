#include "ShootingGame.h"

GameOver::GameOver(float px, float py) : Sprite("", "", true, px, py, 5)
{}

GameOver::~GameOver()
{}

void GameOver::Start()
{
	SetSprite("Asset/게임오버.bmp");
}

void GameOver::Update()
{
}
