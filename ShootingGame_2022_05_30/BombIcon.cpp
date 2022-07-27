#include "ShootingGame.h"

BombIcon::BombIcon(float px, float py) : Sprite("", "", true, px, py, 5)
{}

BombIcon::~BombIcon()
{}

void BombIcon::Start()
{
	SetSprite("Asset/UI/Icon/BombIcon.bmp");
}

void BombIcon::Update()
{}
