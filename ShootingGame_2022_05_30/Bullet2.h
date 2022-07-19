#pragma once
#include "sprite.h"

class Bullet2 : public Sprite
{
private:
	float speed;
	float angle;

public:
	Bullet2(float px, float py, float angle);
	~Bullet2();

	void Start();
	void Update();
};

