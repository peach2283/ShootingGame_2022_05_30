#pragma once

#include "Sprite.h"

class Enemy : public Sprite
{
private:
public:
	Enemy(float px, float py);
	~Enemy();

	void Start();
	void Update();
};

