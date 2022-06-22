#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum class State { appear=0, left = 1, right = 2, fall = 3 };

private:
	float moveSpeed;  //�̵� �ӵ�
	float fallSpeed;  //�߶� �ӵ�

	float lifeTime;   //�߶� ������ Ÿ��

	State state;

	float hp;

	float fireTimer;
	float fireDelay;

	int   randomPos;  //�¿� �̵����·�..�����ϴ� ��ġ
	int   randomDir;  //�¿� �̵����� ���� ����

public:
	Enemy(float px, float py);
	~Enemy();

	void Start();
	void Update();

	void OnDestroy();
	void OnTriggerStay2D(Collider2D collision);

	//���� ���� ���� �Լ�
	void Explode();
};

