#include "ShootingGame.h"

Bomb::Bomb(float px, float py) : Animation("", "", true, px, py, 1)
{
	this->speed = 200;
}

Bomb::~Bomb()
{}

void Bomb::Start()
{
	for (int x = 0; x < 8; x++)
	{
		AddSprite("Asset/������ź2.bmp", x * 34, 0, 32, 32, 0);
	}
}

void Bomb::Update()
{
	Translate(0, -speed * Time::deltaTime);
}

void Bomb::OnAnimationEnd()
{
	//��ź ���� ȿ��
	float px, py;

	GetPosition(px, py);
	Instantiate(new BombExp(px-50, py-50));

	//��ź �����ϱ�
	Destroy(this);
}