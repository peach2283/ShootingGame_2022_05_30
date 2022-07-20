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

	////////////////////////Gun ������////////////////////////////////////
	float fireTimer; //�߻�ð� ����
	float fireDelay; //�߻簣 �����ð�

	//�ǵ��� �߻� �迭 �ε���
	int fireIndex;

	//�ǵ��� �߻� ���� �迭
	bool firePattern[20][7] = { 
									{true, true, true,     false,     false, false, false},
									{true, true, true,     false,     false, false, false},
									{true, true, true,     false,     false, false, false},
									{true, true, true,     false,     false, false, false},
									{true, true, true,     false,     false, false, false},

									{false, false, false,     false,     true, true, true},
									{false, false, false,     false,     true, true, true},
									{false, false, false,     false,     true, true, true},
									{false, false, false,     false,     true, true, true},
									{false, false, false,     false,     true, true, true},

									{false, true, false,     true,     false, true, false},
									{false, true, false,     true,     false, true, false},
									{false, true, false,     true,     false, true, false},
									{false, true, false,     true,     false, true, false},
									{false, true, false,     true,     false, true, false},

									{true, true, true,     true,     true, true, true},
									{true, true, true,     true,     true, true, true},
									{true, true, true,     true,     true, true, true},
									{true, true, true,     true,     true, true, true},

								
								};

	/////////////////ĳ�� ������///////////////////////////////
	float cannonFireTimer;
	float cannonFireDelay;

	bool  cannonFirePattern[10][2] = {  {true , true},
										{false, false},
										{true,  false},
										{false, true},
										{true,  true},

										{false, false},
										{true,  false},
										{false, true},
										{true,  false},
										{false, true},
										};
	int cannonFireIndex;

public:
	Boss(float px, float py);
	~Boss();

	void Start();
	void Update();

	//�ڽİ�ü��..�ı����� �˸��� �̺�Ʈ �Լ�//
	void OnChildDestroy(string name);

};

