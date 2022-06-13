#include "ShootingGame.h"

Player::Player(float px, float py) :Animation("", "", true, px, py)
{
	this->speed      = 200;
	this->laserCount = 3;   //�������� ȹ���ϸ�..�߻簹�� ����

	this->fireTimer = 0;   
	this->fireDelay = 0.2; //�߻簣 �����ð�
}

Player::~Player()
{}

void Player::Start()
{
	///////���ڸ�..�ִϸ��̼�    - 0  ��
	AddSprite("Asset/�����̵�2.bmp", 192, 0, 62, 80,      0);

	///////������ �̵�..�ִϸ��̼� - 1 �� 
	AddSprite("Asset/�����̵�2.bmp", 256 + 64 * 0 , 0, 62, 80,      1);
	AddSprite("Asset/�����̵�2.bmp", 256 + 64 * 1 , 0, 62, 80,      1);
	AddSprite("Asset/�����̵�2.bmp", 256 + 64 * 2 , 0, 62, 80,      1);

	///////���� �̵� ...�ִϸ��̼� - 2 ��
	AddSprite("Asset/�����̵�2.bmp", 128 - 64 * 0, 0, 62, 80,       2);
	AddSprite("Asset/�����̵�2.bmp", 128 - 64 * 1, 0, 62, 80,       2);
	AddSprite("Asset/�����̵�2.bmp", 128 - 64 * 2, 0, 62, 80,       2);

	/////�ִϸ��̼� ���� ����////////
	SetLoop(false);

	/////�ִϸ��̼� �ӵ� ����///////
	SetSpeed(0.5);

	//�÷��̾� �浹ü �߰��ϱ�/////
	AddBoxCollider2D(0, 0, 62, 80);
}

void Player::Update()
{		
	Move();  //�̵� �Լ�
	Fire();	 //�߻� �Լ�
}

void Player::Move()  //�̵� �Լ�
{
	/////////////�÷��̾� �̵��ϱ�/////////////////
	if ( Input::GetKey(KeyCode::LeftArrow) == true )
	{
		Translate(-speed * Time::deltaTime, 0);
		Play(2);

		//x ��ǥ ��������
		float px = GetPx();

		if (px < -9)
		{
			SetPx(-9);
		}
	}

	if ( Input::GetKey(KeyCode::RightArrow) == true )
	{
		Translate(speed * Time::deltaTime, 0); //������ �̵�
		Play(1);                               //������ �̵� �ִϸ��̼�

		float px = GetPx();

		if (px > 480  - 62 + 9)
		{
			SetPx(480 - 62 + 9);
		}
	}

	if ( Input::GetKey(KeyCode::UpArrow) == true)
	{
		Translate(0, -speed * Time::deltaTime);

		float py = GetPy();

		if (py < 0)
		{
			SetPy(0);
		}
	}

	if ( Input::GetKey(KeyCode::DownArrow) == true )
	{
		Translate(0, speed * Time::deltaTime);

		float py = GetPy();

		if (py > 800 - 80 + 7)
		{
			SetPy(800 - 80 + 7);
		}
	}

	///////�����̵��� ������ �̵��� �ƴҶ�..���ڸ� �ִϸ��̼� �����ϱ�//////
	if (Input::GetKey(KeyCode::LeftArrow) != true && Input::GetKey(KeyCode::RightArrow) != true)
	{
		Play(0);  //���ڸ� �ִϸ��̼� ���
	}
}

void Player::Fire()  //�߻� �Լ�
{
	/////////�÷��̾� ������ �߻��ϱ�/////////
	if (Input::GetKey(KeyCode::Space) == true)
	{
		//�߻� �ð� �����ϱ�
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px, py;

			GetPosition(px, py);

			if (laserCount == 1)
			{
				//������ �ѹ� ���
				Instantiate(new Laser(px + 28, py - 26));
			}
			else if (laserCount == 2)
			{
				//������ �ι� ���
				Instantiate(new Laser(px + 28 - 10, py - 30));
				Instantiate(new Laser(px + 28 + 10, py - 30));
			}
			else if (laserCount == 3)
			{
				//������ ���� ���
				Instantiate(new Laser(px + 28 - 10, py - 20 + 10));
				Instantiate(new Laser(px + 28     , py - 20 - 10));
				Instantiate(new Laser(px + 28 + 10, py - 20 + 10));
			}

			fireTimer = 0;  //�߻� Ÿ�̸�..����
		}
	}
}