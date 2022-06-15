#pragma once

#include "Sprite.h"

class Laser : public Sprite
{
private:
	
	float speed;
	float lifeTime; //레이저 수명

public:
	Laser(float px, float py);
	~Laser();

	void Start();
	void Update();

	//충돌 이벤트 ... 오바라이딩
	void OnTriggerStay2D(Collider2D collision);
};

