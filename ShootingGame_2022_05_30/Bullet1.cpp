#include "ShootingGame.h"

Bullet1::Bullet1(float px, float py) : Sprite("총알1", "", true, px, py, 1)
{
	this->speed    = 200;
	this->lifeTime = 8;
}

Bullet1::~Bullet1()
{}

void Bullet1::Start()
{
	SetSprite("Asset/총알1.bmp");
	AddBoxCollider2D(0, 0, 16, 15);
}

void Bullet1::Update()
{
	//이동
	Translate(0, speed * Time::deltaTime);

	//라이프 타임 측정
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void Bullet1::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "플레이어")
	{
		//블릿 폭발 효과
		float px, py;

		GetPosition(px, py);
		Instantiate(new BulletExp(px-10, py-10));

		//블릿 객체 제거
		Destroy(this);
	}
}