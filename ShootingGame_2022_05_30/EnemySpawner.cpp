#include "ShootingGame.h"

EnemySpawner* EnemySpawner::instance = nullptr;

EnemySpawner::EnemySpawner(float px, float py) : GameObject("", "", true, px, py)
{
	this->spawnTimer = 0;
	this->spawnDelay = 1;

	this->spawnCount = 0;
	this->deadCount  = 0;
}

EnemySpawner::~EnemySpawner()
{}

/************************************
void EnemySpawner::Awake()
{
	//instance = this;
}
**************************************/

EnemySpawner* EnemySpawner::Instance()
{
	return instance;
}

void EnemySpawner::IncDeadCount()
{
	deadCount++;

	cout << "���� dead Count" << deadCount <<endl;

}

void EnemySpawner::Start()
{
	//����Ƽ������ �ڱ������� ������..�켱���� �ϱ� ���ؼ�..Awake�Լ��� ���Ե�
	instance = this;
}

void EnemySpawner::Update()
{
	spawnTimer += Time::deltaTime;

	if (spawnTimer >= spawnDelay)
	{
		//���� �����(���� �����ϱ�)
		int currCount = spawnCount - deadCount;

		if (currCount < 3)  //���� ������ ���� ������ 3�� ���� �������� ������
		{
			float px, py;

			GetPosition(px, py);
			Instantiate(new Enemy(px - 95, py - 140));

			spawnCount++;  //����ī��Ʈ �����Ͻ�
		}

		spawnTimer = 0;  //Ÿ�̸� ����
	}
}

void EnemySpawner::DebugDraw()
{
	//��ġ Ȯ���� ���� ȭ�� ǥ���ϱ�
	float px, py;

	GetPosition(px, py);

	//���μ� �׸���
	DrawLine(px - 50, py  , px + 50, py     , 255, 0, 0);

	//���μ� �׸���
	DrawLine(px  , py - 50, px      , py + 50, 255, 0, 0);
}