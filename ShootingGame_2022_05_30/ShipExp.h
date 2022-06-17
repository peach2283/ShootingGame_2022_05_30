#pragma once

#include "Animation.h"

class ShipExp : public Animation
{
private:
public:
	ShipExp(float px, float py);
	~ShipExp();

	void Start();
	void Update();

	void OnAnimationEnd();
};

