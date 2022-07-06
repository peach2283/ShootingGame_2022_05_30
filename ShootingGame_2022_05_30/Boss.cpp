#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("", "", true, px, py, 1)
{}

Boss::~Boss()
{}

void Boss::Start()
{
	//보스 기본 이미지 추가//
	SetSprite("Asset/보스.bmp", 0, 0, 493, 206);

	//보스 폭발 후 이미지 추가//
	//SetSprite("Asset/보스.bmp", 0, 613, 385, 182, -35, 0);
}

void Boss::Update()
{}
