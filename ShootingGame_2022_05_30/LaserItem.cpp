#include "ShootingGame.h"

LaserItem::LaserItem(float px, float py) : Sprite("������������", "", true, px, py, 1)
{
	this->speed    = 150;
	this->lifeTime = 10;
}

LaserItem::~LaserItem()
{}

void LaserItem::Start()
{
	SetSprite("Asset/�Ѿ˾�����.bmp");
	AddBoxCollider2D(0, 0, 22, 80);
}

void LaserItem::Update()
{
	//�̵��ϱ�
	Translate(0, speed * Time::deltaTime);

	//������ Ÿ�� �����ϱ�
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void LaserItem::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "�÷��̾�")
	{
		//������ �����ϱ�
		Destroy(this);
	}
}