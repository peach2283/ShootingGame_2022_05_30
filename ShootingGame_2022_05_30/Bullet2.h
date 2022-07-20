#pragma once
#include "sprite.h"

class Bullet2 : public Sprite
{
private:
	float speed;
	float angle;
	float lifeTime;

public:
	Bullet2(float px, float py, float angle);
	~Bullet2();

	void Start();
	void Update();

	//�浹 �̺�Ʈ..�������̵�
	void OnTriggerStay2D(Collider2D collision);
};

