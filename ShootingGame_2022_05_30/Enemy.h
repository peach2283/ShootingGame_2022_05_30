#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum class State { appear=0, left = 1, right = 2, fall = 3 };

private:
	float moveSpeed;  //이동 속도
	float fallSpeed;  //추락 속도

	float lifeTime;   //추락 라이프 타임

	State state;

	float hp;

	float fireTimer;
	float fireDelay;

public:
	Enemy(float px, float py);
	~Enemy();

	void Start();
	void Update();

	void OnTriggerStay2D(Collider2D collision);

	//적기 폭발 제거 함수
	void Explode();
};

