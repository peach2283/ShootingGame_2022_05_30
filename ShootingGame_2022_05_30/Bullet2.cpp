#include "ShootingGame.h"

Bullet2::Bullet2(float px, float py, float angle) : Sprite("�Ѿ�2", "", true, px, py, 1)
{
	this->speed = 200;
	this->angle = angle;
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
	//float nx = 1;
	//float ny = 0; 

	//ȸ�� ����..�����ϱ�
	//float angle = 10; //30��

	//���� ��ȯ�ϱ�
	float theta = angle * Mathf::PI / 180;

	//(1, 0) ���� ���͸� theta ��ŭ..ȸ����Ų ������
	float rx = Mathf::Cos(theta);
	float ry = Mathf::Sin(theta);

	//�� �̵��ϱ�
	float dx = rx * speed * Time::deltaTime;
	float dy = ry * speed * Time::deltaTime;

	Translate(dx, dy);
}
