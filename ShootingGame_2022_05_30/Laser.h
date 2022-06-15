#pragma once

#include "Sprite.h"

class Laser : public Sprite
{
private:
	
	float speed;
	float lifeTime; //������ ����

public:
	Laser(float px, float py);
	~Laser();

	void Start();
	void Update();

	//�浹 �̺�Ʈ ... ���ٶ��̵�
	void OnTriggerStay2D(Collider2D collision);
};

