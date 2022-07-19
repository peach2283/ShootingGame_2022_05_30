#include "ShootingGame.h"

Bullet2::Bullet2(float px, float py) : Sprite("�Ѿ�2", "", true, px, py, 1)
{
	this->speed = 200;
}

Bullet2::~Bullet2()
{}

void Bullet2::Start()
{
	SetSprite("Asset/�Ѿ�2.bmp");
}

void Bullet2::Update()
{
	//��������(ũ�Ⱑ 1 �� ����)
	float nx = 1;
	float ny = 0; 

	//���� ���� ���͸� theta ��ŭ..ȸ����Ų ������
	//x => cos(theta)
	//y => sin(theta)

	//�� �̵��ϱ�
	float dx = nx * speed * Time::deltaTime;
	float dy = ny * speed * Time::deltaTime;

	Translate(dx, dy);
}
