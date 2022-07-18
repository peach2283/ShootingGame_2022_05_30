#pragma once
#include "Sprite.h"

class Boss : public Sprite
{
	enum class State {appear=0, attack=1, fall=2};

private:
	float speed;
	int   childCount;  //destroy�� �ڽİ�ü ī��Ʈ

	State state;      //���º���

	float fallTimer;  //�߶��ð� ���� Ÿ�̸�

	float fireTimer; //�߻�ð� ����
	float fireDelay; //�߻簣 �����ð�

public:
	Boss(float px, float py);
	~Boss();

	void Start();
	void Update();

	//�ڽİ�ü��..�ı����� �˸��� �̺�Ʈ �Լ�//
	void OnChildDestroy(string name);

};

