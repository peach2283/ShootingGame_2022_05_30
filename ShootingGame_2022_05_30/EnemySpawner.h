#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:

	float spawnTimer;
	float spawnDelay;

	//적기 스폰 카운터..
	int spawnCount;  //스폰된 적기 갯수
	int deadCount;   //게임에서..제거된 갯수

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void Start();
	void Update();

	//디버그 드로우..오버라이딩
	void DebugDraw();
};

