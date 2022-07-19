#pragma once
#include "sprite.h"

class Bullet2 : public Sprite
{
private:
	float speed;

public:
	Bullet2(float px, float py);
	~Bullet2();

	void Start();
	void Update();
};

