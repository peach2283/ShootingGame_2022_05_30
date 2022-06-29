#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("폭탄아이템","", true , px, py, 1)
{
	this->visible = true;

	this->blinkTimer = 0;
	this->blinkDelay = 0.3;
}

BombItem::~BombItem()
{}

void BombItem::Start()
{
	SetSprite("Asset/폭탄아이템.bmp");
	AddBoxCollider2D(0, 0, 22, 40);
}

void BombItem::Update()
{
	if (visible == true)  //보여지고 있음
	{
		//타이머 측정
		blinkTimer = blinkTimer + Time::deltaTime;

		if (blinkTimer >= blinkDelay)
		{
			//SetActive(false);
			visible = false;

			blinkTimer = 0; //타이머 리셋
		}
	}
	else {			    //보여지지 않음

		//타이머 측정
		blinkTimer = blinkTimer + Time::deltaTime;

		if (blinkTimer >= blinkDelay)
		{
			//SetActive(true);
			visible = true;

			blinkTimer = 0; //타이머 리셋
		}
	}
}