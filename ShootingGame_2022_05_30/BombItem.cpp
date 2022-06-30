#include "ShootingGame.h"

BombItem::BombItem(float px, float py) : Sprite("��ź������","", true , px, py, 1)
{
	this->visible = true;

	this->blinkTimer = 0;
	this->blinkDelay = 0.3;

	this->lifeTime = 5;
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
	//�����̱�
	if (visible == true)  //�������� ����
	{
		//Ÿ�̸� ����
		blinkTimer = blinkTimer + Time::deltaTime;

		if (blinkTimer >= blinkDelay)
		{
			//SetActive(false);
			enabled = false;  //����Ƽ�� SpriteRenderer ������Ʈ�� ���
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
			enabled = true;
			visible = true;

			blinkTimer = 0; //Ÿ�̸� ����
		}
	}

	//������Ÿ�� �����ϱ�
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		Destroy(this);
	}
}

void BombItem::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "�÷��̾�")
	{
		Destroy(this);
	}
}