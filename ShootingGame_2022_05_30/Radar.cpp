#include "ShootingGame.h"

Radar::Radar(float px, float py) : Sprite("∫∏Ω∫¿⁄Ωƒ", "", true, px, py, 2)
{
	this->hp = 100;
}

Radar::~Radar()
{}

void Radar::Start()
{
	SetSprite("Asset/∫∏Ω∫.bmp", 360, 245, 11, 9);
	AddBoxCollider2D(0, 0, 11, 9);
}

void Radar::Update()
{}

void Radar::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "∑π¿Ã¿˙")
	{
		hp = hp - 10;

		if (hp <= 0)
		{
			Explode();
		}
	}
	else if (tag == "∆¯≈∫∆¯πﬂ")
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
