#include "ShootingGame.h"

Wing::Wing(int x, int y, int width, int height, float px, float py) : Sprite("보스자식", "", true, px, py, 2)
{
	this->x = x;
	this->y = y;
	this->width  = width;
	this->height = height;

	this->hp = 100;
}

Wing::~Wing()
{}

void Wing::Start()
{
	//날개 이미지 로드하기//
	SetSprite("Asset/보스.bmp", x, y, width, height);

	//충돌박스 추가하기
	AddBoxCollider2D(0, 0, width, height);
}

void Wing::Update()
{}

void Wing::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "레이저")
	{
		hp = hp - 10;

		if (hp <= 0)
		{
			Explode();
		}
	}
	else if (tag == "폭탄폭발")
	{
		Explode();
	}
}

void Wing::Explode()
{
	float px, py;
	GetPosition(px, py);

	Instantiate(new BossChildExp(px, py));
	Destroy(this);  	
}

void Wing::OnDestroy()
{
	//부모 객체인 보스에..자식이 폭발됨을 알려줌
	GameObject* parent = GetParent();

	((Boss*)parent)->OnChildDestroy("날개");
}