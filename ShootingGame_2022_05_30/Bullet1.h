#pragma once
#include "Sprite.h"

class Bullet1 : public Sprite
{
private:
	float speed;

public:
	Bullet1(float px, float py);
	~Bullet1();

	void Start();
	void Update();
};

