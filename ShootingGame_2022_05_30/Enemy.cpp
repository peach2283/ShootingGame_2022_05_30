#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("����","", true, px, py)
{
	this->moveSpeed = 100;
	this->fallSpeed = 300;

	this->lifeTime = 5;

	this->state = State::appear;  //������� ����..����(���� �ʱ�ȭ)
	this->hp    = 100;

	this->fireTimer = 0;
	this->fireDelay = 1;

	this->hasBombTrigger   = false;
	this->hasLaserTrigger  = false;
	this->hasPlayerTrigger = false;
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

	//���� ���� ��ġ / ���� (�¿��̵� ���� ����) 
	randomPos = Random::Range(50, 200);
	randomDir = Random::Range(0,   2);
}

void Enemy::Update()
{	
	//���� �̵� ������Ʈ�ӽ�//
	switch (state)
	{	
		case State::appear:
		{
			Translate(0, moveSpeed * Time::deltaTime);  //�Ʒ��� ����

			//�¿�..�̵� ���������ϱ�
			if (GetPy() >= randomPos)
			{
				if (randomDir == 0)
					state = State::left;
				else
					state = State::right;
			}
		}
		break;

		case State::left:
		{
			Translate(-moveSpeed * Time::deltaTime, 0); //�����̵�

			if (GetPx() <= 0) //�������� ����
			{
				state = State::right; //��������(Transition)
			}
		}
		break;

		case State::right:
		{
			Translate(moveSpeed * Time::deltaTime, 0);  //������ �̵�

			if (GetPx() >= 480 - 190)
			{
				state = State::left;
			}
		}
		break;

		case State::fall:
		{
			//�߶��� ���� �̵�
			Translate(0, fallSpeed * Time::deltaTime);

			//�߶� ������ Ÿ��
			lifeTime = lifeTime - Time::deltaTime;

			if (lifeTime <= 0)
			{
				Destroy(this);
	
			}
		}
		break;
	}	

	//�� �߻��ϱ�//
	fireTimer = fireTimer + Time::deltaTime;

	if (fireTimer >= fireDelay)
	{
		float px, py;

		GetPosition(px, py);
		Instantiate(new Bullet1(px+87, py + 137));

		fireTimer = 0;
	}

	//�浹(Ʈ����) üũ ���� ����
	hasBombTrigger   = false;
	hasLaserTrigger  = false;
	hasPlayerTrigger = false;
}

void Enemy::OnDestroy()
{
	//���⽺������ deadCount ������Ű��
	EnemySpawner* spawner = EnemySpawner::Instance();
	spawner->IncDeadCount();
}

void Enemy::OnTriggerStay2D(Collider2D collision)
{			
		string tag = collision.tag;

		if (tag == "������")
		{
			if (hasLaserTrigger == false)
			{
				hasLaserTrigger = true;

				//������ ���� �����ϱ�
				hp = hp - 5;

				if (80 <= hp && hp <= 100)  //���� ����
				{

				}
				else if (50 <= hp && hp < 80)  //����� ����
				{
					//1 �� �ִϸ��̼� ����
					Play(1);
				}
				else if (0 < hp && hp < 50)   //�ɰ��� ����
				{
					//2 �� �ִϸ��̼� ����
					Play(2);

					//���� �߶�(fall)���·�..�����ϱ�
					state = State::fall;

				}
				else  if (hp <= 0)           //���� ����
				{
					Explode();
				}
			}
		}
		else if (tag == "�÷��̾�")
		{
			if (hasPlayerTrigger == false)
			{
				hasPlayerTrigger = true;
				Explode();
			}
		}
		else if (tag == "��ź����")
		{
			if (hasBombTrigger == false)  //������ �浹�� ���������� üũ
			{
				//�浹�� �־�����..ǥ����
				hasBombTrigger = true;
				Explode();
			}
		}	
}

void Enemy::Explode()
{
	//���� ���� ȿ��
	float px, py;

	GetPosition(px, py);
	Instantiate(new ShipExp(px + 15, py));

	//���� ����
	Destroy(this);
}