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
			AddSprite("Asset/ÃÑ¾ËÆø¹ß.bmp", x * 40, y * 40, 40, 40,        0);
		}
	}

	AddSprite("Asset/ÃÑ¾ËÆø¹ß.bmp", 0 * 40, 3 * 40, 40, 40, 0);
	AddSprite("Asset/ÃÑ¾ËÆø¹ß.bmp", 1 * 40, 3 * 40, 40, 40, 0);

	SetSpeed(2);
}

void BulletExp::Update()
{}

void BulletExp::OnAnimationEnd()
{
	Destroy(this);
}