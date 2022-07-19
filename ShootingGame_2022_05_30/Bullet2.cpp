#include "ShootingGame.h"

Bullet2::Bullet2(float px, float py, float angle) : Sprite("총알2", "", true, px, py, 1)
{
	this->speed = 200;
	this->angle = angle;
}

Bullet2::~Bullet2()
{}

void Bullet2::Start()
{
	SetSprite("Asset/총알2.bmp");
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
}
