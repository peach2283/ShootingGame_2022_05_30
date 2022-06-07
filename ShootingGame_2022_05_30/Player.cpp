#include "ShootingGame.h"

Player::Player(float px, float py) :Sprite("", "", true, px, py)
{
	this->speed      = 200;
	this->laserCount = 1;   //아이템을 획득하면..발사갯수 증가

	this->fireTimer = 0;   
	this->fireDelay = 0.2; //발사간 지연시간
}

Player::~Player()
{}

void Player::Start()
{
	SetSprite("Asset/플레이어.bmp");
}

void Player::Update()
{	
	Move();  //이동 함수
	Fire();	 //발사 함수
}

void Player::Move()  //이동 함수
{
	/////////////플레이어 이동하기/////////////////
	if ( Input::GetKey(KeyCode::LeftArrow) == true )
	{
		Translate(-speed * Time::deltaTime, 0);

		//x 좌표 가져오기
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

void Player::Fire()  //발사 함수
{
	/////////플레이어 레이저 발사하기/////////
	if (Input::GetKey(KeyCode::Space) == true)
	{
		//발사 시간 측정하기
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px, py;

			GetPosition(px, py);

			if (laserCount == 1)
			{
				//레이저 한발 쏘기
				Instantiate(new Laser(px + 31, py - 33));
			}
			else if (laserCount == 2)
			{
				//레이저 두발 쏘기
				Instantiate(new Laser(px + 31 - 10, py - 33));
				Instantiate(new Laser(px + 31 + 10, py - 33));
			}
			else if (laserCount == 3)
			{
				//레이저 세발 쏘기
				Instantiate(new Laser(px + 31 - 10, py - 23 + 10));
				Instantiate(new Laser(px + 31, py - 23 - 10));
				Instantiate(new Laser(px + 31 + 10, py - 23 + 10));
			}

			fireTimer = 0;  //발사 타이먼..리셋
		}
	}
}