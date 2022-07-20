#include "ShootingGame.h"

Bullet2::Bullet2(float px, float py, float angle) : Sprite("�Ѿ�2", "", true, px, py, 3)
{
	this->speed = 200;
	this->angle = angle;
	this->lifeTime = 8;
}

Bullet2::~Bullet2()
{}

void Bullet2::Start()
{
	SetSprite("Asset/�Ѿ�2.bmp");
	AddBoxCollider2D(0, 0, 17, 17);
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

	//������ Ÿ�� ����
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void Bullet2::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "�÷��̾�" || tag == "����")
	{
		//�� ���� ȿ��
		float px, py;

		GetPosition(px, py);
		Instantiate(new BulletExp(px - 10, py - 10));

		//�� ��ü ����
		Destroy(this);
	}
}