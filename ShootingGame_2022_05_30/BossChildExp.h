#pragma once
#include "Animation.h"

class BossChildExp : public Animation
{
private:
public:
	BossChildExp(float px, float py);
	~BossChildExp();

	void Start();
	void Update();

	void OnAnimationEnd();
};

