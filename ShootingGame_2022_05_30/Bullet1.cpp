#include "ShootingGame.h"

Bullet1::Bullet1(float px, float py) : Sprite("�Ѿ�1", "", true, px, py)
{
	this->speed = 200;
}

Bullet1::~Bullet1()
{}

void Bullet1::Start()
{
	SetSprite("Asset/�Ѿ�1.bmp");
	AddBoxCollider2D(0, 0, 16, 15);
}

void Bullet1::Update()
{
	Translate(0, speed * Time::deltaTime);
}
