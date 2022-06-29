#pragma once

#include "Animation.h"

class Player : public Animation
{
private:
	float hp;   //플레이어 체력[참고...나중에 GameManager로 이동함]

	float speed;
	int   laserCount;  //발사되는 레이저 갯수
	int   bombCount;   //남은 폭탄갯수

	float fireTimer;   //발사 시간 측정 변수
	float fireDelay;   //발사간 대기 시간

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();

	void Move();  //이동 함수
	void Fire();  //발사 함수

	//충돌 이벤트 함수...오바라이딩
	void OnTriggerStay2D(Collider2D collision);

	//플레이어 폭발제거 함수
	void Explode();
};