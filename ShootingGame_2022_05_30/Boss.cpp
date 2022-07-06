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

	//프로펠러..자식 객체 추가하기
	AddChildObject(new Propeller( 63+16, 41+6));
	AddChildObject(new Propeller(111+16, 41+6));
	AddChildObject(new Propeller(159+16, 41+6));

	AddChildObject(new Propeller(302+16, 41+6));
	AddChildObject(new Propeller(350+16, 41+6));
	AddChildObject(new Propeller(398+16, 41+6));
}

void Boss::Update()
{}
