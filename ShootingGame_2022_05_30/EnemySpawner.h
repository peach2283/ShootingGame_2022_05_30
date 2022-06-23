#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
  //EnemySpawner 상태 Enum  만들기
  enum class State {enemy=0, boss=1, finish=2};

private:
	//싱글톤 만들기 (1) 자기 객체를 저장할 변수를 static으로 만듬
	static EnemySpawner* instance;

	float spawnTimer;
	float spawnDelay;

	//적기 스폰 카운터..
	int spawnCount;  //스폰된 적기 갯수
	int deadCount;   //게임에서..제거된 갯수

	//상태 변수
	State state;

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	//싱글톤 만들기(2) Awake함수에서..자기자신을... instance 변수에 저장함
	//void Awake();

	void Start();
	void Update();

	//싱글톤만들기 (3)instance의 게터를 static으로 만들어라!!
	static EnemySpawner* Instance();

	//디버그 드로우..오버라이딩
	void DebugDraw();

	//Enemy Dead Count 증가함수
	void IncDeadCount();
};

