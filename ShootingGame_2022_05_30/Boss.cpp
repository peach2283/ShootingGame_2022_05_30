#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("", "", true, px, py, 1)
{
	this->speed = 20;
}

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

	//날개 자식 추가하기
	AddChildObject(new Wing(298, 425, 30, 18,   256, 97));   //오른쪽 첫번째 
	AddChildObject(new Wing(329, 426, 32, 16,   302, 94));   //오른쪽 두번째
	AddChildObject(new Wing(364, 426, 32, 16,   350, 90));   //오른쪽 세번째
	AddChildObject(new Wing(399, 426, 32, 16,   405, 84));   //오른쪽 네번째

	AddChildObject(new Wing(404, 406, 28, 15,   206, 98));   //왼쪽 첫번째
	AddChildObject(new Wing(369, 406, 32, 16,   158, 94));   //왼쪽 두번째
	AddChildObject(new Wing(334, 406, 32, 16,   110, 90));   //왼쪽 세번째
	AddChildObject(new Wing(299, 406, 32, 16,    62, 85));   //왼쪽 네번째


	//건 자식 추가하기
	AddChildObject(new Gun(94 , 71));
	AddChildObject(new Gun(142, 71));
	AddChildObject(new Gun(190, 71));

	AddChildObject(new Gun(238, 63));

	AddChildObject(new Gun(286, 71));
	AddChildObject(new Gun(334, 71));
	AddChildObject(new Gun(382, 71));

	//대포 자식 추가하기
	AddChildObject(new Cannon(270, 107));
	AddChildObject(new Cannon(201, 107));

	//레이더 자식 추가하기
	AddChildObject(new Radar(241, 105));
	AddChildObject(new Radar(241, 117));
}

void Boss::Update()
{
	//보스 이동하기
	Translate(0, speed * Time::deltaTime);
}
