#pragma once

#include "Sprite.h"

class Player : public Sprite
{
private:
	
	float speed;
	int   laserCount;  //�߻�Ǵ� ������ ����

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();

	void Move();  //�̵� �Լ�
	void Fire();  //�߻� �Լ�
};