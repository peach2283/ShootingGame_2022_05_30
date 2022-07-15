#include "ShootingGame.h"

Gun::Gun(float px, float py) : Sprite("∫∏Ω∫¿⁄Ωƒ", "", true, px, py, 2)
{
	this->hp = 100;
}

Gun::~Gun()
{}

void Gun::Start()
{
	SetSprite("Asset/∫∏Ω∫.bmp", 426, 315, 20, 25);
	
	AddBoxCollider2D(2, 3, 12, 12);
}

void Gun::Update()
{}

void Gun::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "∑π¿Ã¿˙")
	{
		hp = hp - 10;

		if (hp <= 10)
		{
			Explode();
		}	
	}
	else if (tag == "∆¯≈∫∆¯πﬂ")
	{
		Explode();
	}
}

void Gun::Explode()
{
	float px, py;
	GetPosition(px, py);

	Instantiate(new BossChildExp(px - 5, py - 5));
	Destroy(this);
}

void Gun::OnDestroy()
{
	GameObject* parent = GetParent();
	((Boss*)parent)->OnChildDestroy("∞«");
}