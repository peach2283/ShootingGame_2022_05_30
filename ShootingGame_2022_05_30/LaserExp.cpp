#include "ShootingGame.h"

LaserExp::LaserExp(float px, float py) : Animation("", "", true, px, py, 1)
{}

LaserExp::~LaserExp()
{}

void LaserExp::Start()
{
	//�ִϸ��̼� �̹��� �ε��ϱ�//
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			AddSprite("Asset/����������.bmp", x*36, y*36, 36, 36,    0);
		}
	}

	//�ִϸ��̼� �ӵ�
	SetSpeed(2);
}

void LaserExp::Update()
{}

void LaserExp::OnAnimationEnd()
{
	Destroy(this);
}