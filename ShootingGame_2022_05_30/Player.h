#pragma once

#include "Animation.h"

class Player : public Animation
{
	enum class State {appear = 0, control = 1};

private:
	float hp;   //�÷��̾� ü��[����...���߿� GameManager�� �̵���]

	float speed;
	int   laserCount;  //�߻�Ǵ� ������ ����

	float fireTimer;   //�߻� �ð� ���� ����
	float fireDelay;   //�߻簣 ��� �ð�

	float shieldTimer;  //���� �ð����� ����

	State state;  //�÷��̾� ���� ����

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();

	void Appear();

	void Move();		//�̵� �Լ�
	void Fire();		//�߻� �Լ�
	void ShieldTimer(); //���� �Լ�

	//�浹 �̺�Ʈ �Լ�...���ٶ��̵�
	void OnTriggerStay2D(Collider2D collision);

	//�÷��̾� �������� �Լ�
	void Explode();
};