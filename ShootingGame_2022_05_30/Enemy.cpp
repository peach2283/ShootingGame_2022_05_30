#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("","", true, px, py)
{
	this->speed = 100;
	this->state = State::left;
}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	//애니메이션 이미지 로드하기 - 피해없는 애니메이션
	AddSprite("Asset/적기.bmp", 1 + 200 * 0 , 281, 190, 137,     0);
	AddSprite("Asset/적기.bmp", 1 + 200 * 1 , 281, 190, 137,     0);

	//애니메이션 이미지 로드하기 - 경미한 피해를 받은 애니메이션
	AddSprite("Asset/적기.bmp", 1 + 200 * 0 , 141, 190, 137,      1);
	AddSprite("Asset/적기.bmp", 1 + 200 * 1 , 141, 190, 137,      1);
	AddSprite("Asset/적기.bmp", 1 + 200 * 2 , 141, 190, 137,      1);
	AddSprite("Asset/적기.bmp", 1 + 200 * 3 , 141, 190, 137,      1);

	//애니메이션 이미지 로드하기 - 심각한 피해를 받은 애니메이션
	AddSprite("Asset/적기.bmp", 1 + 200 * 0 , 1, 190, 137,        2);
	AddSprite("Asset/적기.bmp", 1 + 200 * 1 , 1, 190, 137,        2);
	AddSprite("Asset/적기.bmp", 1 + 200 * 2 , 1, 190, 137,        2);
	AddSprite("Asset/적기.bmp", 1 + 200 * 3 , 1, 190, 137,        2);
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
