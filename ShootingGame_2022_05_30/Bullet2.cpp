#include "ShootingGame.h"

Bullet2::Bullet2(float px, float py, float angle) : Sprite("총알2", "", true, px, py, 3)
{
	this->speed = 200;
	this->angle = angle;
	this->lifeTime = 8;
}

Bullet2::~Bullet2()
{}

void Bullet2::Start()
{
	SetSprite("Asset/총알2.bmp");
	AddBoxCollider2D(0, 0, 17, 17);
}

void Bullet2::Update()
{
	//단위벡터(크기가 1 인 벡터)
	//float nx = 1;
	//float ny = 0; 

	//회전 각도..지정하기
	//float angle = 10; //30도

	//라디안 변환하기
	float theta = angle * Mathf::PI / 180;

	//(1, 0) 단위 벡터를 theta 만큼..회전시킨 방향은
	float rx = Mathf::Cos(theta);
	float ry = Mathf::Sin(theta);

	//블릿 이동하기
	float dx = rx * speed * Time::deltaTime;
	float dy = ry * speed * Time::deltaTime;

	Translate(dx, dy);

	//라이프 타임 측정
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void Bullet2::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "플레이어" || tag == "방패")
	{
		//블릿 폭발 효과
		float px, py;

		GetPosition(px, py);
		Instantiate(new BulletExp(px - 10, py - 10));

		//블릿 객체 제거
		Destroy(this);
	}
}