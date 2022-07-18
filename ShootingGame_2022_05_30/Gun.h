#pragma once
#include "Sprite.h"

class Gun : public Sprite
{
private:
	float hp;

public:
	Gun(float px, float py, string name);
	~Gun();

	void Start();
	void Update();

	void OnTriggerStay2D(Collider2D collision);
	void Explode();

	void OnDestroy();

	void Fire();
};

