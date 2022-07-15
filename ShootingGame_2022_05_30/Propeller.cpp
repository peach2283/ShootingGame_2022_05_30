#include "ShootingGame.h"

Propeller::Propeller(float px, float py) : Animation("보스자식", "", true, px, py, 2)
{
	this->hp = 100;
}

Propeller::~Propeller()
{}

void Propeller::Start()
{
	//애니메이션..이미지들 추가하기 - 피해없는 애니메이션 (0번)
	AddSprite("Asset/프로펠러1.bmp", 5,  5, 32, 12,    0,   16, 6);
	AddSprite("Asset/프로펠러1.bmp", 39, 5, 32, 12,    0,   16, 6);
	AddSprite("Asset/프로펠러1.bmp", 72, 5, 30, 12,    0,   15, 6);
	AddSprite("Asset/프로펠러1.bmp", 104, 5, 24, 12,   0,   12, 6);

	AddSprite("Asset/프로펠러1.bmp", 131, 5, 20, 12,   0,   10, 6);
	AddSprite("Asset/프로펠러1.bmp", 153, 5, 26, 12,   0,   13, 6);
	AddSprite("Asset/프로펠러1.bmp", 182, 5, 28, 12,   0,   14, 6);
	AddSprite("Asset/프로펠러1.bmp", 213, 5, 30, 12,   0,   15, 6);

	//애니메이션..이미지들 추가하기 - 피해받은 애니메이션 (1번)
	AddSprite("Asset/프로펠러2.bmp", 7, 4, 32, 48,     1,   16, 6);
	AddSprite("Asset/프로펠러2.bmp", 42, 4, 31, 48,    1,   15, 6);
	AddSprite("Asset/프로펠러2.bmp", 76, 4, 29, 48,    1,   15, 6);
	AddSprite("Asset/프로펠러2.bmp", 108, 4, 31, 48,   1,   18, 6);

	AddSprite("Asset/프로펠러2.bmp", 142, 4, 31, 48,    1, 17, 6);
	AddSprite("Asset/프로펠러2.bmp", 176, 4, 32, 48,    1, 16, 6);
	AddSprite("Asset/프로펠러2.bmp", 210, 4, 31, 48,    1, 16, 6);
	AddSprite("Asset/프로펠러2.bmp", 244, 4, 32, 48,    1, 16, 6);

	//애니메이션 속도
	SetSpeed(4);

	//충돌체 추가하기
	AddBoxCollider2D(-9, -4, 18, 10);
}

void Propeller::Update()
{}

void Propeller::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "레이저")
	{
		//레이저 피해 적용(체력 감소)
		hp = hp - 10;
		
		if (hp < 50)
		{
			//일정 피해를 받으면..애니메이션 변경
			Play(1);
		}
		
		if (hp <= 0)
		{
			//체력이 모두 없어지면..제거 / 폭발
			Explode();			
		}
	}
	else if (tag == "폭탄폭발")
	{
		//제거/폭발
		Explode();
	}
}

void Propeller::Explode()
{
	//폭발 
	float px, py;
	GetPosition(px, py);

	Instantiate(new BossChildExp(px - 14, py - 8));

	//자식 객체 제거(버그가 발생할수 있음)
	Destroy(this);
}

void Propeller::OnDestroy()
{
	GameObject* parent = GetParent();
	((Boss*)parent)->OnChildDestroy("프로펠러");
}