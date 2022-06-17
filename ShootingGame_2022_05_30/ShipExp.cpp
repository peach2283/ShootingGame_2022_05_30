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
			AddSprite("Asset/Æø¹ßÈ¿°ú.bmp", 0 + 161*x, 7482 + 161*x, 160, 160, 0);
		}
	}
}

void ShipExp::Update()
{}
