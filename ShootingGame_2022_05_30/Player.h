#pragma once

#include "Sprite.h"

class Player : public Sprite
{
private:
public:
	Player(string tag, string name, bool active, float px, float py);
	~Player();

	void Start();
	void Update();
};

