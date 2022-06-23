#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
  //EnemySpawner ���� Enum  �����
  enum class State {enemy=0, boss=1, finish=2};

private:
	//�̱��� ����� (1) �ڱ� ��ü�� ������ ������ static���� ����
	static EnemySpawner* instance;

	float spawnTimer;
	float spawnDelay;

	//���� ���� ī����..
	int spawnCount;  //������ ���� ����
	int deadCount;   //���ӿ���..���ŵ� ����

	//���� ����
	State state;

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	//�̱��� �����(2) Awake�Լ�����..�ڱ��ڽ���... instance ������ ������
	//void Awake();

	void Start();
	void Update();

	//�̱��游��� (3)instance�� ���͸� static���� ������!!
	static EnemySpawner* Instance();

	//����� ��ο�..�������̵�
	void DebugDraw();

	//Enemy Dead Count �����Լ�
	void IncDeadCount();
};

