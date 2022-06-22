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
		if (spawnCount < 10)
		{
			//���� �����(���� �����ϱ�)
			int currCount = spawnCount - deadCount;

			if (currCount < 3)  //���� ������ ���� ������ 3�� ���� �������� ������
			{
				float px, py;
				GetPosition(px, py);

				//���� ������ġ �迭�� �����
				float spawnx[3] = { px - 95 - 100 , px - 95  , px - 95 + 100 };
				float spawny[3] = { py - 140      , py - 140 , py - 140 };

				//���� �����迭 �ε���
				int randomIdx = Random::Range(0, 3); //0, 1, 2 �� ������
				Instantiate(new Enemy(spawnx[randomIdx], spawny[randomIdx]));

				spawnCount++;  //����ī��Ʈ �����Ͻ�
			}
		}
		else {
			
			//���� �����(���� �����ϱ�)
			cout << "���� �����ϱ�" << endl;
		
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