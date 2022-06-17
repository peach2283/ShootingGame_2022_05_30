#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("����","", true, px, py)
{
	this->speed = 100;
	this->state = State::left;
	this->hp    = 100;
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

	//�浹ü �߰��ϱ�
	//AddBoxCollider2D(0, 0, 190, 137);
	AddBoxCollider2D(85 , 25 , 20 , 110);  //���..���� �浹 �ڽ�
	AddBoxCollider2D(0  , 85 , 190,  20);  //���..���� �浹 �ڽ�
	AddBoxCollider2D(65 , 10 , 60 ,  15);  //����  ..���� �浹 �ڽ�
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

void Enemy::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "������")
	{
		//������ ���� �����ϱ�
		hp = hp - 10;

		cout << "���� ü�� " << hp << endl;

		//ü���� 0 �̵Ǹ�..���� ���� / ����//
		if (hp <= 0)
		{
			//���� ���� ȿ��

			//���� ����
			Destroy(this);
		}
	}
	else if (tag == "�÷��̾�")
	{
	
	}
}