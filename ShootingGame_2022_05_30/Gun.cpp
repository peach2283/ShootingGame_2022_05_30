#include "ShootingGame.h"

Gun::Gun(float px, float py) : Sprite("�����ڽ�", "", true, px, py, 2)
{}

Gun::~Gun()
{}

void Gun::Start()
{
	SetSprite("Asset/����.bmp", 426, 315, 20, 25);
	
	AddBoxCollider2D(2, 3, 12, 12);
}

void Gun::Update()
{}
