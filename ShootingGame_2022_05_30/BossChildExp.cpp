#include "ShootingGame.h"

BossChildExp::BossChildExp(float px, float py) : Animation("", "", true, px, py, 2)
{}

BossChildExp::~BossChildExp()
{}

void BossChildExp::Start()
{
	for (int i = 0; i < 12; i++)
	{
		AddSprite("Asset/Æø¹ßÈ¿°ú.bmp", 33*i, 1783, 32, 32, 0);
	}
}

void BossChildExp::Update()
{}

void BossChildExp::OnAnimationEnd()
{
	Destroy(this);
}