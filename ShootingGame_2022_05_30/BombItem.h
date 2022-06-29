#pragma once
#include "Sprite.h"

class BombItem : public Sprite
{
private:
	bool visible;  //true(����),  false(�Ⱥ���)

	float blinkTimer;
	float blinkDelay;

public:
	 BombItem(float px, float py);
	~BombItem();

	void Start();
	void Update();
};

