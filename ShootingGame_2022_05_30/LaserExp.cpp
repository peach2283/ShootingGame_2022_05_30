#include "ShootingGame.h"

LaserExp::LaserExp(float px, float py) : Animation("", "", true, px, py, 1)
{}

LaserExp::~LaserExp()
{}

void LaserExp::Start()
{
	//애니메이션 이미지 로드하기//
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			AddSprite("Asset/레이저폭발.bmp", x*36, y*36, 36, 36,    0);
		}
	}

	//애니메이션 속도
	SetSpeed(2);
}

void LaserExp::Update()
{}

void LaserExp::OnAnimationEnd()
{
	Destroy(this);
}