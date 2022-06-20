#pragma once
#include "Sprite.h"

class Bullet1 : public Sprite
{
private:
	float speed;
	float lifeTime;

public:
	Bullet1(float px, float py);
	~Bullet1();

	void Start();
	void Update();

	//�浹 �̺�Ʈ..�������̵�
	void OnTriggerStay2D(Collider2D collision);
};

