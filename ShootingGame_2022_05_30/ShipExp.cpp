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
			AddSprite("Asset/����ȿ��.bmp", 0 + 161*x, 7482 + 161*y, 160, 160, 0);
		}
	}

	//�ִϸ��̼� �ӵ� 
	SetSpeed(1.5);
}

void ShipExp::Update()
{}

void ShipExp::OnAnimationEnd()
{
	Destroy(this);
}