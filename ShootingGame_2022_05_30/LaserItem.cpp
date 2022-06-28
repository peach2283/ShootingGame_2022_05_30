#include "ShootingGame.h"

LaserItem::LaserItem(float px, float py) : Sprite("레이저아이템", "", true, px, py, 1)
{
	this->speed    = 150;
	this->lifeTime = 10;
}

LaserItem::~LaserItem()
{}

void LaserItem::Start()
{
	SetSprite("Asset/총알아이템.bmp");
	AddBoxCollider2D(0, 0, 22, 80);
}

void LaserItem::Update()
{
	//이동하기
	Translate(0, speed * Time::deltaTime);

	//라이프 타임 측정하기
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void LaserItem::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "플레이어")
	{
		//아이템 제거하기
		Destroy(this);
	}
}