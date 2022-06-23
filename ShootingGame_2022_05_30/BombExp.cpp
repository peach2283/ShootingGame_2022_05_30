#include "ShootingGame.h"

BombExp::BombExp(float px, float py) : Animation("ÆøÅºÆø¹ß", "", true, px, py)
{}

BombExp::~BombExp()
{}

void BombExp::Start()
{
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			AddSprite("Asset/ÆøÅºÆø¹ß.bmp", x * 130, y * 130, 128, 128,    0);
		}
	}

	//Ãæµ¹Ã¼ Ãß°¡ÇÏ±â
	AddBoxCollider2D(19, 19, 90, 90);
}

void BombExp::Update()
{}

void BombExp::OnAnimationEnd()
{
	Destroy(this);
}
