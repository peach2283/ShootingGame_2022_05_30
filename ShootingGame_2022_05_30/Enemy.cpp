#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("적기","", true, px, py)
{
	this->moveSpeed = 100;
	this->fallSpeed = 300;

	this->lifeTime = 5;

	this->state = State::appear;  //등장상태 부터..시작(상태 초기화)
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
	//애니메이션 이미지 로드하기 - 피해없는 애니메이션
	AddSprite("Asset/적기.bmp", 1 + 200 * 0 , 281, 190, 137,     0);
	AddSprite("Asset/적기.bmp", 1 + 200 * 1 , 281, 190, 137,     0);

	//애니메이션 이미지 로드하기 - 경미한 피해를 받은 애니메이션
	AddSprite("Asset/적기.bmp", 1 + 200 * 0 , 141, 190, 137,      1);
	AddSprite("Asset/적기.bmp", 1 + 200 * 1 , 141, 190, 137,      1);
	AddSprite("Asset/적기.bmp", 1 + 200 * 2 , 141, 190, 137,      1);
	AddSprite("Asset/적기.bmp", 1 + 200 * 3 , 141, 190, 137,      1);

	//애니메이션 이미지 로드하기 - 심각한 피해를 받은 애니메이션
	AddSprite("Asset/적기.bmp", 1 + 200 * 0 , 1, 190, 137,        2);
	AddSprite("Asset/적기.bmp", 1 + 200 * 1 , 1, 190, 137,        2);
	AddSprite("Asset/적기.bmp", 1 + 200 * 2 , 1, 190, 137,        2);
	AddSprite("Asset/적기.bmp", 1 + 200 * 3 , 1, 190, 137,        2);

	//충돌체 추가하기
	//AddBoxCollider2D(0, 0, 190, 137);
	AddBoxCollider2D(85 , 25 , 20 , 110);  //가운데..몸통 충돌 박스
	AddBoxCollider2D(0  , 85 , 190,  20);  //가운데..날개 충돌 박스
	AddBoxCollider2D(65 , 10 , 60 ,  15);  //꼬리  ..날개 충돌 박스

	//적기 랜덤 위치 / 방향 (좌우이동 상태 전이) 
	randomPos = Random::Range(50, 200);
	randomDir = Random::Range(0,   2);
}

void Enemy::Update()
{	
	//적기 이동 스테이트머신//
	switch (state)
	{	
		case State::appear:
		{
			Translate(0, moveSpeed * Time::deltaTime);  //아래로 등장

			//좌우..이동 상태전이하기
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
			Translate(-moveSpeed * Time::deltaTime, 0); //왼쪽이동

			if (GetPx() <= 0) //성태전이 조건
			{
				state = State::right; //상태전이(Transition)
			}
		}
		break;

		case State::right:
		{
			Translate(moveSpeed * Time::deltaTime, 0);  //오른쪽 이동

			if (GetPx() >= 480 - 190)
			{
				state = State::left;
			}
		}
		break;

		case State::fall:
		{
			//추락을 위한 이동
			Translate(0, fallSpeed * Time::deltaTime);

			//추락 라이프 타임
			lifeTime = lifeTime - Time::deltaTime;

			if (lifeTime <= 0)
			{
				Destroy(this);
	
			}
		}
		break;
	}	

	//블릿 발사하기//
	fireTimer = fireTimer + Time::deltaTime;

	if (fireTimer >= fireDelay)
	{
		float px, py;

		GetPosition(px, py);
		Instantiate(new Bullet1(px+87, py + 137));

		fireTimer = 0;
	}

	//충돌(트리거) 체크 변수 리셋
	hasBombTrigger   = false;
	hasLaserTrigger  = false;
	hasPlayerTrigger = false;
}

void Enemy::OnDestroy()
{
	//적기스포너의 deadCount 증가시키기
	EnemySpawner* spawner = EnemySpawner::Instance();
	spawner->IncDeadCount();
}

void Enemy::OnTriggerStay2D(Collider2D collision)
{			
		string tag = collision.tag;

		if (tag == "레이저")
		{
			if (hasLaserTrigger == false)
			{
				hasLaserTrigger = true;

				//레이저 피해 적용하기
				hp = hp - 5;

				if (80 <= hp && hp <= 100)  //피해 없음
				{

				}
				else if (50 <= hp && hp < 80)  //경미한 피해
				{
					//1 번 애니메이션 변경
					Play(1);
				}
				else if (0 < hp && hp < 50)   //심각한 피해
				{
					//2 번 애니메이션 변경
					Play(2);

					//적기 추락(fall)상태로..전이하기
					state = State::fall;

				}
				else  if (hp <= 0)           //적기 폭발
				{
					Explode();
				}
			}
		}
		else if (tag == "플레이어")
		{
			if (hasPlayerTrigger == false)
			{
				hasPlayerTrigger = true;
				Explode();
			}
		}
		else if (tag == "폭탄폭발")
		{
			if (hasBombTrigger == false)  //이전에 충돌이 없었는지를 체크
			{
				//충돌이 있었음을..표시함
				hasBombTrigger = true;
				Explode();
			}
		}	
}

void Enemy::Explode()
{
	//적기 폭발 효과
	float px, py;

	GetPosition(px, py);
	Instantiate(new ShipExp(px + 15, py));

	//적기 제거
	Destroy(this);
}