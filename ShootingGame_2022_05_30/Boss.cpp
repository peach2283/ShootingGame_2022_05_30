#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("", "", true, px, py, 1)
{}

Boss::~Boss()
{}

void Boss::Start()
{
	//���� �⺻ �̹��� �߰�//
	SetSprite("Asset/����.bmp", 0, 0, 493, 206);

	//���� ���� �� �̹��� �߰�//
	//SetSprite("Asset/����.bmp", 0, 613, 385, 182, -35, 0);
}

void Boss::Update()
{}
