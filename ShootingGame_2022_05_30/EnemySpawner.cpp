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

	cout << "적기 dead Count" << deadCount <<endl;

}

void EnemySpawner::Start()
{
	//유니티에서는 자기포인터 저장을..우선으로 하기 위해서..Awake함수에 포함됨
	instance = this;
}

void EnemySpawner::Update()
{
	spawnTimer += Time::deltaTime;

	if (spawnTimer >= spawnDelay)
	{
		if (spawnCount < 10)
		{
			//적기 만들기(적기 스폰하기)
			int currCount = spawnCount - deadCount;

			if (currCount < 3)  //현재 게임의 적기 갯수가 3개 보다 작을때문 스폰함
			{
				float px, py;
				GetPosition(px, py);

				//적기 스폰위치 배열로 만들기
				float spawnx[3] = { px - 95 - 100 , px - 95  , px - 95 + 100 };
				float spawny[3] = { py - 140      , py - 140 , py - 140 };

				//랜덤 스폰배열 인덱스
				int randomIdx = Random::Range(0, 3); //0, 1, 2 중 랜덤값
				Instantiate(new Enemy(spawnx[randomIdx], spawny[randomIdx]));

				spawnCount++;  //스폰카운트 증가하시
			}
		}
		else {
			
			//보스 만들기(보스 스폰하기)
			cout << "보스 스폰하기" << endl;
		
		}

		spawnTimer = 0;  //타이머 리셋
	}
}

void EnemySpawner::DebugDraw()
{
	//위치 확인을 위한 화면 표시하기
	float px, py;

	GetPosition(px, py);

	//가로선 그리기
	DrawLine(px - 50, py  , px + 50, py     , 255, 0, 0);

	//세로선 그리기
	DrawLine(px  , py - 50, px      , py + 50, 255, 0, 0);
}