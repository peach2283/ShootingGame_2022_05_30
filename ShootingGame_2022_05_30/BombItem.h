#pragma once
#include "Sprite.h"

class BombItem : public Sprite
{
private:
	bool visible;  //true(����),  false(�Ⱥ���)

	float blinkTimer;
	float blinkDelay;

	float lifeTime;

public:
	 BombItem(float px, float py);
	~BombItem();

	void Start();
	void Update();

	void OnTriggerStay2D(Collider2D collision);
};

