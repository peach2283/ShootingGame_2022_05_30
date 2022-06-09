#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 100;
	this->state = State::left;
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
			Translate(-speed * Time::deltaTime, 0); //왼쪽이동

			if (GetPx() <= 0) //성태전이 조건
			{
				state = State::right; //상태전이(Transition)
			}
		}
		break;

		case State::right:
		{
			Translate(speed * Time::deltaTime, 0);  //오른쪽 이동

			if (GetPx() >= 480 - 190)
			{
				state = State::left;
			}
		}
		break;
	}
}
