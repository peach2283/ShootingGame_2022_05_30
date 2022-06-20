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

	//충돌 이벤트..오버라이딩
	void OnTriggerStay2D(Collider2D collision);
};

