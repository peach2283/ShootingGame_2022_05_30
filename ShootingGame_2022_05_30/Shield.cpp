#include "ShootingGame.h"

Shield::Shield(float px, float py) : Animation("����", "����", true, px, py, 3)
{}

Shield::~Shield()
{}

void Shield::Start()
{
	//�ִϸ��̼� �̹��� �߰��ϱ�
	AddSprite("Asset/��ȣ����1.bmp", 0);
	AddSprite("Asset/��ȣ����2.bmp", 0);
	AddSprite("Asset/��ȣ����3.bmp", 0);

	//���� �浹ü �߰��ϱ�
	AddBoxCollider2D(0, 0, 86, 90);
}

void Shield::Update()
{}
