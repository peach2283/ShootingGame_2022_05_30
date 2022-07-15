#include "ShootingGame.h"

Radar::Radar(float px, float py) : Sprite("보스자식", "", true, px, py, 2)
{
	this->hp = 100;
}

Radar::~Radar()
{}

void Radar::Start()
{
	SetSprite("Asset/보스.bmp", 360, 245, 11, 9);
	AddBoxCollider2D(0, 0, 11, 9);
}

void Radar::Update()
{}

void Radar::OnTriggerStay2D(Collider2D collision)
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

void Radar::Explode()
{
	float px, py;
	GetPosition(px, py);

	Instantiate(new BossChildExp(px, py));
	Destroy(this);
}

void Radar::OnDestroy()
{
	GameObject* parent = GetParent();
	((Boss*)parent)->OnChildDestroy("레이더");
}