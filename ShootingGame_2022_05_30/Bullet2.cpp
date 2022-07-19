#include "ShootingGame.h"

Bullet2::Bullet2(float px, float py) : Sprite("총알2", "", true, px, py, 1)
{
	this->speed = 200;
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
	float nx = 1;
	float ny = 0; 

	//위의 단위 벡터를 theta 만큼..회전시킨 방향은
	//x => cos(theta)
	//y => sin(theta)

	//블릿 이동하기
	float dx = nx * speed * Time::deltaTime;
	float dy = ny * speed * Time::deltaTime;

	Translate(dx, dy);
}
