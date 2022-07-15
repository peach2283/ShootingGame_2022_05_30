#pragma once
#include "Sprite.h"

class Radar : public Sprite
{
private:
	float hp;

public:
	Radar(float px, float py);
	~Radar();

	void Start();
	void Update();

	void OnTriggerStay2D(Collider2D collision);
	void Explode();

	void OnDestroy();
};

