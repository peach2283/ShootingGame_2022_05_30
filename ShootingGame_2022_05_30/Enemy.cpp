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
	//�ִϸ��̼� �̹��� �ε��ϱ� - ���ؾ��� �ִϸ��̼�
	AddSprite("Asset/����.bmp", 1 + 200 * 0 , 281, 190, 137,     0);
	AddSprite("Asset/����.bmp", 1 + 200 * 1 , 281, 190, 137,     0);

	//�ִϸ��̼� �̹��� �ε��ϱ� - ����� ���ظ� ���� �ִϸ��̼�
	AddSprite("Asset/����.bmp", 1 + 200 * 0 , 141, 190, 137,      1);
	AddSprite("Asset/����.bmp", 1 + 200 * 1 , 141, 190, 137,      1);
	AddSprite("Asset/����.bmp", 1 + 200 * 2 , 141, 190, 137,      1);
	AddSprite("Asset/����.bmp", 1 + 200 * 3 , 141, 190, 137,      1);

	//�ִϸ��̼� �̹��� �ε��ϱ� - �ɰ��� ���ظ� ���� �ִϸ��̼�
	AddSprite("Asset/����.bmp", 1 + 200 * 0 , 1, 190, 137,        2);
	AddSprite("Asset/����.bmp", 1 + 200 * 1 , 1, 190, 137,        2);
	AddSprite("Asset/����.bmp", 1 + 200 * 2 , 1, 190, 137,        2);
	AddSprite("Asset/����.bmp", 1 + 200 * 3 , 1, 190, 137,        2);
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
