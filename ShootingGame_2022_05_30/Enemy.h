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

	int   randomPos;  //좌우 이동상태로..전이하는 위치
	int   randomDir;  //좌우 이동상태 전이 방향

	bool hasBombTrigger;      //폭탄폭발 충돌이 있었는지를..표시하는 변수
	bool hasLaserTrigger;     //레이저와 충돌이 있었는지를 .. 표시하는 변수 
	bool hasPlayerTrigger;    //플레이어와 충돌이 있었는지를 .. 표시하는 변수
	bool hasShieldTrigger;    //플레이어의 방해와 충돌이 있었는지를..표시하는 변수

	//레이저 아이템 드랍 변수
	bool dropLaserItem;     

	//폭탄 아이템 드랍 변수
	bool dropBombItem;

public:
	Enemy(float px, float py);
	~Enemy();

	void Start();
	void Update();

	void OnDestroy();
	void OnTriggerStay2D(Collider2D collision);

	//적기 폭발 제거 함수
	void Explode();

	//레이저 아이템 드랍 변수 세터
	void SetDropLaserItem(bool drop);

	//폭탄 아이템 드랍 변수 세터
	void SetDropBombItem(bool drop);

};

