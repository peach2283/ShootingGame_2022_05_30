#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:
public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void Start();
	void Update();

	//디버그 드로우..오버라이딩
	void DebugDraw();
};

