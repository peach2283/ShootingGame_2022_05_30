#pragma once
#include "Animation.h"

class Propeller : public Animation
{
private:
	float hp;

public:
	Propeller(float px, float py);
	~Propeller();

	void Start();
	void Update();

	void OnTriggerStay2D(Collider2D collision);

	void Explode();  //폭발 제거 함수
};

