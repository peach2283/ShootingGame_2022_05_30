#include "ShootingGame.h"

ShipExp::ShipExp(float px, float py) : Animation("", "", true, px, py)
{}

ShipExp::~ShipExp()
{}

void ShipExp::Start()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			AddSprite("Asset/폭발효과.bmp", 0 + 161*x, 7482 + 161*y, 160, 160, 0);
		}
	}

	//애니메이션 속도 
	SetSpeed(1.5);
}

void ShipExp::Update()
{}

void ShipExp::OnAnimationEnd()
{
	Destroy(this);
}