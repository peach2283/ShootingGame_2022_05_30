#pragma once

#include "Sprite.h"

class Laser : public Sprite
{
private:
	
	float speed;
	float lifeTime; //레이저 수명

public:
	Laser(float px, float py);
	~Laser();

	void Start();
	void Update();
};

