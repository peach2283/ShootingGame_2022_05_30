#include "ShootingGame.h"

Laser::Laser(float px, float py) : Sprite("레이저","", true, px, py, 3)
{
	this->speed    = 250;
	this->lifeTime = 5;
}

Laser::~Laser()
{	
}

void Laser::Start()
{
	SetSprite("Asset/레이저.bmp");

	//레이저 충돌 박스 추가하기
	AddBoxCollider2D(0, 0, 6, 33);
}

void Laser::Update()
{
	Translate(0, -speed * Time::deltaTime);

	lifeTime = lifeTime - Time::deltaTime; //수명 줄이기

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void Laser::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "적기")
	{
		//레이저 폭발 효과
		float px, py;

		GetPosition(px, py);
		Instantiate(new LaserExp(px-14, py-10));

		//레이저 제거하기
		Destroy(this);
	}
}