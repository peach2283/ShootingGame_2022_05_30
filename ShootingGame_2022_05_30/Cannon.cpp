#include "ShootingGame.h"

Cannon::Cannon(float px, float py) : Sprite("", "", true, px, py, 2)
{}

Cannon::~Cannon()
{}

void Cannon::Start()
{
	SetSprite("Asset/����.bmp", 357, 262, 21, 22);
}

void Cannon::Update()
{}
