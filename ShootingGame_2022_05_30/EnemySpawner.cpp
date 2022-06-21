#include "ShootingGame.h"

EnemySpawner::EnemySpawner(float px, float py) : GameObject("", "", true, px, py)
{}

EnemySpawner::~EnemySpawner()
{}

void EnemySpawner::Start()
{}

void EnemySpawner::Update()
{}

void EnemySpawner::DebugDraw()
{
	//위치 확인을 위한 화면 표시하기
	float px, py;

	GetPosition(px, py);

	//가로선 그리기
	DrawLine(px - 50, py  , px + 50, py     , 255, 0, 0);

	//세로선 그리기
	DrawLine(px  , py - 50, py      , py + 50, 255, 0, 0);
}