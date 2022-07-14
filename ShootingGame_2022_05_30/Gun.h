#pragma once
#include "Sprite.h"

class Gun : public Sprite
{
private:
	float hp;

public:
	Gun(float px, float py);
	~Gun();

	void Start();
	void Update();

	void OnTriggerStay2D(Collider2D collision);
	void Explode();
};

