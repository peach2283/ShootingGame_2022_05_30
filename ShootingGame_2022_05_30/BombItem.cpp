#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("∆¯≈∫æ∆¿Ã≈€","",true, px, py, 1)
{}

BombItem::~BombItem()
{}

void BombItem::Start()
{
	SetSprite("Asset/∆¯≈∫æ∆¿Ã≈€.bmp");
	AddBoxCollider2D(0, 0, 22, 40);
}

void BombItem::Update()
{
}