#include "ShootingGame.h"

BulletExp::BulletExp(float px, float py) : Animation("", "", true, px, py)
{}

BulletExp::~BulletExp()
{}

void BulletExp::Start()
{
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			AddSprite("Asset/�Ѿ�����.bmp", x * 40, y * 40, 40, 40,        0);
		}
	}
}

void BulletExp::Update()
{}

void BulletExp::OnAnimationEnd()
{
	Destroy(this);
}