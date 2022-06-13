#include "ShootingGame.h"

Player::Player(float px, float py) :Animation("", "", true, px, py)
{
	this->speed      = 200;
	this->laserCount = 3;   //아이템을 획득하면..발사갯수 증가

	this->fireTimer = 0;   
	this->fireDelay = 0.2; //발사간 지연시간
}

Player::~Player()
{}

void Player::Start()
{
	///////제자리..애니메이션    - 0  번
	AddSprite("Asset/팬텀이동2.bmp", 192, 0, 62, 80,      0);

	///////오른쪽 이동..애니메이션 - 1 번 
	AddSprite("Asset/팬텀이동2.bmp", 256 + 64 * 0 , 0, 62, 80,      1);
	AddSprite("Asset/팬텀이동2.bmp", 256 + 64 * 1 , 0, 62, 80,      1);
	AddSprite("Asset/팬텀이동2.bmp", 256 + 64 * 2 , 0, 62, 80,      1);

	///////왼쪽 이동 ...애니메이션 - 2 번
	AddSprite("Asset/팬텀이동2.bmp", 128 - 64 * 0, 0, 62, 80,       2);
	AddSprite("Asset/팬텀이동2.bmp", 128 - 64 * 1, 0, 62, 80,       2);
	AddSprite("Asset/팬텀이동2.bmp", 128 - 64 * 2, 0, 62, 80,       2);

	/////애니메이션 루프 변경////////
	SetLoop(false);

	/////애니메이션 속도 변경///////
	SetSpeed(0.5);

	//플레이어 충돌체 추가하기/////
	AddBoxCollider2D(0, 0, 62, 80);
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
		Play(2);

		//x 좌표 가져오기
		float px = GetPx();

		if (px < -9)
		{
			SetPx(-9);
		}
	}

	if ( Input::GetKey(KeyCode::RightArrow) == true )
	{
		Translate(speed * Time::deltaTime, 0); //오른쪽 이동
		Play(1);                               //오른쪽 이동 애니메이션

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

	///////왼쪽이동과 오른쪽 이동이 아닐때..제자리 애니메이션 실행하기//////
	if (Input::GetKey(KeyCode::LeftArrow) != true && Input::GetKey(KeyCode::RightArrow) != true)
	{
		Play(0);  //제자리 애니메이션 재생
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
				Instantiate(new Laser(px + 28, py - 26));
			}
			else if (laserCount == 2)
			{
				//레이저 두발 쏘기
				Instantiate(new Laser(px + 28 - 10, py - 30));
				Instantiate(new Laser(px + 28 + 10, py - 30));
			}
			else if (laserCount == 3)
			{
				//레이저 세발 쏘기
				Instantiate(new Laser(px + 28 - 10, py - 20 + 10));
				Instantiate(new Laser(px + 28     , py - 20 - 10));
				Instantiate(new Laser(px + 28 + 10, py - 20 + 10));
			}

			fireTimer = 0;  //발사 타이머..리셋
		}
	}
}