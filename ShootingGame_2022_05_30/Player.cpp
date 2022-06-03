#include "ShootingGame.h"

Player::Player(float px, float py) :Sprite("", "", true, px, py)
{
	this->speed      = 200;
	this->laserCount = 1;   //�������� ȹ���ϸ�..�߻簹�� ����
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
	if (GetAsyncKeyState(VK_LEFT) != 0)
	{
		Translate(-speed * Time::deltaTime, 0);

		//x ��ǥ ��������
		float px = GetPx();

		if (px < 0)
		{
			SetPx(0);
		}
	}

	if (GetAsyncKeyState(VK_RIGHT) != 0)
	{
		Translate(speed * Time::deltaTime, 0);

		float px = GetPx();

		if (px > 480 - 68)
		{
			SetPx(480 - 68);
		}
	}

	if (GetAsyncKeyState(VK_UP) != 0)
	{
		Translate(0, -speed * Time::deltaTime);

		float py = GetPy();

		if (py < 0)
		{
			SetPy(0);
		}
	}

	if (GetAsyncKeyState(VK_DOWN) != 0)
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
	if (Input::GetKeyDown(KeyCode::Space) == true)
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
	}
}