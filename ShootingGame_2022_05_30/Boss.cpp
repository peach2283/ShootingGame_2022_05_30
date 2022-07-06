#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("", "", true, px, py, 1)
{}

Boss::~Boss()
{}

void Boss::Start()
{
	//���� �⺻ �̹��� �߰�//
	SetSprite("Asset/����.bmp", 0, 0, 493, 206);

	//���� ���� �� �̹��� �߰�//
	//SetSprite("Asset/����.bmp", 0, 613, 385, 182, -35, 0);

	//�����緯..�ڽ� ��ü �߰��ϱ�
	AddChildObject(new Propeller( 63+16, 41+6));
	AddChildObject(new Propeller(111+16, 41+6));
	AddChildObject(new Propeller(159+16, 41+6));

	AddChildObject(new Propeller(302+16, 41+6));
	AddChildObject(new Propeller(350+16, 41+6));
	AddChildObject(new Propeller(398+16, 41+6));
}

void Boss::Update()
{}
