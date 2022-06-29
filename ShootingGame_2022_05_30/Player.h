#pragma once

#include "Animation.h"

class Player : public Animation
{
private:
	float hp;   //�÷��̾� ü��[����...���߿� GameManager�� �̵���]

	float speed;
	int   laserCount;  //�߻�Ǵ� ������ ����
	int   bombCount;   //���� ��ź����

	float fireTimer;   //�߻� �ð� ���� ����
	float fireDelay;   //�߻簣 ��� �ð�

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();

	void Move();  //�̵� �Լ�
	void Fire();  //�߻� �Լ�

	//�浹 �̺�Ʈ �Լ�...���ٶ��̵�
	void OnTriggerStay2D(Collider2D collision);

	//�÷��̾� �������� �Լ�
	void Explode();
};