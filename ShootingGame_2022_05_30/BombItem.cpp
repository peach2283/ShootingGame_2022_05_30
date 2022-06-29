#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("��ź������","", true , px, py, 1)
{
	this->visible = true;

	this->blinkTimer = 0;
	this->blinkDelay = 0.3;
}

BombItem::~BombItem()
{}

void BombItem::Start()
{
	SetSprite("Asset/��ź������.bmp");
	AddBoxCollider2D(0, 0, 22, 40);
}

void BombItem::Update()
{
	if (visible == true)  //�������� ����
	{
		//Ÿ�̸� ����
		blinkTimer = blinkTimer + Time::deltaTime;

		if (blinkTimer >= blinkDelay)
		{
			//SetActive(false);
			visible = false;

			blinkTimer = 0; //Ÿ�̸� ����
		}
	}
	else {			    //�������� ����

		//Ÿ�̸� ����
		blinkTimer = blinkTimer + Time::deltaTime;

		if (blinkTimer >= blinkDelay)
		{
			//SetActive(true);
			visible = true;

			blinkTimer = 0; //Ÿ�̸� ����
		}
	}
}