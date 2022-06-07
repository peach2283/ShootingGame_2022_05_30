#pragma once

#include "Sprite.h"

class Player : public Sprite
{
private:
	
	float speed;
	int   laserCount;  //�߻�Ǵ� ������ ����

	float fireTimer;   //�߻� �ð� ���� ����
	float fireDelay;   //�߻簣 ��� �ð�

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();

	void Move();  //�̵� �Լ�
	void Fire();  //�߻� �Լ�
};