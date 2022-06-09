#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum class State { left = 0, right = 1 };

private:
	float speed;
	State state;

public:
	Enemy(float px, float py);
	~Enemy();

	void Start();
	void Update();
};

