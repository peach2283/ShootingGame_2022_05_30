#pragma once
#include "Animation.h"

class Shield : public Animation
{
private:
public:
	Shield(float px, float py);
	~Shield();

	void Start();
	void Update();
};

