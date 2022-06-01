#include "ShootingGame.h"

Player::Player(float px, float py) :Sprite("", "", true, px, py)
{
	this->speed = 200;
}

Player::~Player()
{}

void Player::Start()
{
	SetSprite("Asset/�÷��̾�.bmp");
}

void Player::Update()
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
		Translate( speed * Time::deltaTime, 0);

		float px = GetPx();

		if (px > 480-68)
		{
			SetPx(480-68);
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
		Translate(0,  speed * Time::deltaTime);

		float py = GetPy();

		if (py > 800 - 91)
		{
			SetPy(800 - 91);
		}
	}
}
