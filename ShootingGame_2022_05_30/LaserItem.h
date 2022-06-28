#pragma once

#include "Sprite.h"

class LaserItem : public Sprite
{
private:
	float speed;
	float lifeTime;

public:
	LaserItem(float px, float py);
	~LaserItem();

	void Start();
	void Update();

	void OnTriggerStay2D(Collider2D collision);
};

