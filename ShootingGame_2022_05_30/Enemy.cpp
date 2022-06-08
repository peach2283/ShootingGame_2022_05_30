#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 100;
	this->state = State::right;
}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	//이미지 로드하기
	SetSprite("Asset/적기.bmp", 201, 141, 190, 137);
}

void Enemy::Update()
{
	switch (state)
	{	
		case State::left:
		{
	
		}
		break;

		case State::right:
		{
	
		}
		break;
	}

	//Translate(0, speed * Time::deltaTime);
}
