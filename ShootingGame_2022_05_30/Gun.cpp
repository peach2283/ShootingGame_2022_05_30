#include "ShootingGame.h"

Gun::Gun(float px, float py) : Sprite("보스자식", "", true, px, py, 2)
{}

Gun::~Gun()
{}

void Gun::Start()
{
	SetSprite("Asset/보스.bmp", 426, 315, 20, 25);
	
	AddBoxCollider2D(2, 3, 12, 12);
}

void Gun::Update()
{}
