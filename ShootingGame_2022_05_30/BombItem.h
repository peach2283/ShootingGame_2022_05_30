#pragma once
#include "Sprite.h"

class BombItem : public Sprite
{
private:
	bool visible;  //true(보임),  false(안보임)

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

