#include "ShootingGame.h"

Laser::Laser(float px, float py) : Sprite("","", true, px, py)
{
	this->speed    = 250;
	this->lifeTime = 5;
}

Laser::~Laser()
{	
}

void Laser::Start()
{
	SetSprite("Asset/레이저.bmp");
}

void Laser::Update()
{
	Translate(0, -speed * Time::deltaTime);

	lifeTime = lifeTime - Time::deltaTime; //수명 줄이기

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}
