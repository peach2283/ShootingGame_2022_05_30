#include "ShootingGame.h"

Laser::Laser(float px, float py) : Sprite("������","", true, px, py, 3)
{
	this->speed    = 250;
	this->lifeTime = 5;
}

Laser::~Laser()
{	
}

void Laser::Start()
{
	SetSprite("Asset/������.bmp");

	//������ �浹 �ڽ� �߰��ϱ�
	AddBoxCollider2D(0, 0, 6, 33);
}

void Laser::Update()
{
	Translate(0, -speed * Time::deltaTime);

	lifeTime = lifeTime - Time::deltaTime; //���� ���̱�

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void Laser::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "����")
	{
		//������ ���� ȿ��
		float px, py;

		GetPosition(px, py);
		Instantiate(new LaserExp(px-14, py-10));

		//������ �����ϱ�
		Destroy(this);
	}
}