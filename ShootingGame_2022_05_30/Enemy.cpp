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
	//�̹��� �ε��ϱ�
	SetSprite("Asset/����.bmp", 201, 141, 190, 137);
}

void Enemy::Update()
{
	switch (state)
	{	
		case State::left:
		{
			Translate(-speed * Time::deltaTime, 0); //�����̵�

			if (GetPx() <= 0) //�������� ����
			{
				state = State::right; //��������(Transition)
			}
		}
		break;

		case State::right:
		{
			Translate(speed * Time::deltaTime, 0);  //������ �̵�

			if (GetPx() >= 480 - 190)
			{
				state = State::left;
			}
		}
		break;
	}
}
