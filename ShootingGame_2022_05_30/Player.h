#pragma once

#include "Sprite.h"

class Player : public Sprite
{
private:
	
	float speed;
	int   laserCount;  //발사되는 레이저 갯수

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();

	void Move();  //이동 함수
	void Fire();  //발사 함수
};