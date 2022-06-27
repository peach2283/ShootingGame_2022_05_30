#include "ShootingGame.h"

Bullet1::Bullet1(float px, float py) : Sprite("�Ѿ�1", "", true, px, py, 1)
{
	this->speed    = 200;
	this->lifeTime = 8;
}

Bullet1::~Bullet1()
{}

void Bullet1::Start()
{
	SetSprite("Asset/�Ѿ�1.bmp");
	AddBoxCollider2D(0, 0, 16, 15);
}

void Bullet1::Update()
{
	//�̵�
	Translate(0, speed * Time::deltaTime);

	//������ Ÿ�� ����
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void Bullet1::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "�÷��̾�")
	{
		//�� ���� ȿ��
		float px, py;

		GetPosition(px, py);
		Instantiate(new BulletExp(px-10, py-10));

		//�� ��ü ����
		Destroy(this);
	}
}