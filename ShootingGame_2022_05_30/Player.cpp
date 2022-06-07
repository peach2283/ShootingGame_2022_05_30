#include "ShootingGame.h"

Player::Player(float px, float py) :Sprite("", "", true, px, py)
{
	this->speed      = 200;
	this->laserCount = 1;   //�������� ȹ���ϸ�..�߻簹�� ����

	this->fireTimer = 0;   
	this->fireDelay = 0.2; //�߻簣 �����ð�
}

Player::~Player()
{}

void Player::Start()
{
	SetSprite("Asset/�÷��̾�.bmp");
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

		//x ��ǥ ��������
		float px = GetPx();

		if (px < 0)
		{
			SetPx(0);
		}
	}

	if ( Input::GetKey(KeyCode::RightArrow) == true )
	{
		Translate(speed * Time::deltaTime, 0);

		float px = GetPx();

		if (px > 480 - 68)
		{
			SetPx(480 - 68);
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

		if (py > 800 - 91)
		{
			SetPy(800 - 91);
		}
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
				Instantiate(new Laser(px + 31, py - 33));
			}
			else if (laserCount == 2)
			{
				//������ �ι� ���
				Instantiate(new Laser(px + 31 - 10, py - 33));
				Instantiate(new Laser(px + 31 + 10, py - 33));
			}
			else if (laserCount == 3)
			{
				//������ ���� ���
				Instantiate(new Laser(px + 31 - 10, py - 23 + 10));
				Instantiate(new Laser(px + 31, py - 23 - 10));
				Instantiate(new Laser(px + 31 + 10, py - 23 + 10));
			}

			fireTimer = 0;  //�߻� Ÿ�̸�..����
		}
	}
}