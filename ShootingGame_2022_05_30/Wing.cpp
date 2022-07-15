#include "ShootingGame.h"

Wing::Wing(int x, int y, int width, int height, float px, float py) : Sprite("�����ڽ�", "", true, px, py, 2)
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
	//���� �̹��� �ε��ϱ�//
	SetSprite("Asset/����.bmp", x, y, width, height);

	//�浹�ڽ� �߰��ϱ�
	AddBoxCollider2D(0, 0, width, height);
}

void Wing::Update()
{}

void Wing::OnTriggerStay2D(Collider2D collision)
{
	string tag = collision.tag;

	if (tag == "������")
	{
		hp = hp - 10;

		if (hp <= 0)
		{
			Explode();
		}
	}
	else if (tag == "��ź����")
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
	//�θ� ��ü�� ������..�ڽ��� ���ߵ��� �˷���
	GameObject* parent = GetParent();

	((Boss*)parent)->OnChildDestroy("����");
}