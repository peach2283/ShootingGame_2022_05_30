#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:

	float spawnTimer;
	float spawnDelay;

	//���� ���� ī����..
	int spawnCount;  //������ ���� ����
	int deadCount;   //���ӿ���..���ŵ� ����

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void Start();
	void Update();

	//����� ��ο�..�������̵�
	void DebugDraw();
};

