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
	//��ġ Ȯ���� ���� ȭ�� ǥ���ϱ�
	float px, py;

	GetPosition(px, py);

	//���μ� �׸���
	DrawLine(px - 50, py  , px + 50, py     , 255, 0, 0);

	//���μ� �׸���
	DrawLine(px  , py - 50, py      , py + 50, 255, 0, 0);
}