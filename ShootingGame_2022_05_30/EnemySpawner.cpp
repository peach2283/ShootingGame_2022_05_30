#include "ShootingGame.h"

EnemySpawner* EnemySpawner::instance = nullptr;

EnemySpawner::EnemySpawner(float px, float py) : GameObject("", "", true, px, py)
{
	this->spawnTimer = 0;
	this->spawnDelay = 1;

	this->spawnCount = 0;
	this->deadCount  = 0;

	this->state = State::enemy;
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
}

void EnemySpawner::Start()
{
	//����Ƽ������ �ڱ������� ������..�켱���� �ϱ� ���ؼ�..Awake�Լ��� ���Ե�
	instance = this;
}

void EnemySpawner::Update()
{
	//������ ����//
	switch (state)
	{
		case State::enemy:
		{
			spawnTimer += Time::deltaTime;

			if (spawnTimer >= spawnDelay)
			{
				if (spawnCount < 20)
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

						//spawnCount  ��° ����
						Enemy* obj = (Enemy*)Instantiate(new Enemy(spawnx[randomIdx], spawny[randomIdx]));  //������ �������� ����ϴ� ����							
						
						obj->SetDropLaserItem( dropLaserItem[spawnCount] );
						obj->SetDropBombItem ( dropBombItem[spawnCount]  );

						spawnCount++;  //����ī��Ʈ �����Ͻ�
					}
				}
				else {

					//���� ���� ���·�..�����ϱ�
					state = State::boss;
				}

				spawnTimer = 0;  //Ÿ�̸� ����
			}
		}
		break;

		case State::boss:
		{
			ObjectManager::Instantiate(new Boss(-6.5, 30));
			state = State::finish;  //������ ���� ����
		}
		break;

		case State::finish:
		{
		
		}
		break;
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