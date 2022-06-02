#include "ShootingGame.h"

Laser::Laser(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 250;
}

Laser::~Laser()
{}

void Laser::Start()
{
	SetSprite("Asset/������.bmp");
}

void Laser::Update()
{
	Translate(0, -speed * Time::deltaTime);
}
