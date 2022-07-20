#pragma once
#include "Sprite.h"

class Boss : public Sprite
{
	enum class State {appear=0, attack=1, fall=2};

private:
	float speed;
	int   childCount;  //destroy된 자식객체 카운트

	State state;      //상태변수

	float fallTimer;  //추락시간 측정 타이머

	////////////////////////Gun 변수들////////////////////////////////////
	float fireTimer; //발사시간 측정
	float fireDelay; //발사간 지연시간

	//건들의 발사 배열 인덱스
	int fireIndex;

	//건들의 발사 패턴 배열
	bool firePattern[20][7] = { 
									{true, true, true,     false,     false, false, false},
									{true, true, true,     false,     false, false, false},
									{true, true, true,     false,     false, false, false},
									{true, true, true,     false,     false, false, false},
									{true, true, true,     false,     false, false, false},

									{false, false, false,     false,     true, true, true},
									{false, false, false,     false,     true, true, true},
									{false, false, false,     false,     true, true, true},
									{false, false, false,     false,     true, true, true},
									{false, false, false,     false,     true, true, true},

									{false, true, false,     true,     false, true, false},
									{false, true, false,     true,     false, true, false},
									{false, true, false,     true,     false, true, false},
									{false, true, false,     true,     false, true, false},
									{false, true, false,     true,     false, true, false},

									{true, true, true,     true,     true, true, true},
									{true, true, true,     true,     true, true, true},
									{true, true, true,     true,     true, true, true},
									{true, true, true,     true,     true, true, true},

								
								};

	/////////////////캐논 변수들///////////////////////////////
	float cannonFireTimer;
	float cannonFireDelay;

	bool  cannonFirePattern[10][2] = {  {true , true},
										{false, false},
										{true,  false},
										{false, true},
										{true,  true},

										{false, false},
										{true,  false},
										{false, true},
										{true,  false},
										{false, true},
										};
	int cannonFireIndex;

public:
	Boss(float px, float py);
	~Boss();

	void Start();
	void Update();

	//자식객체가..파괴됨을 알리는 이벤트 함수//
	void OnChildDestroy(string name);

};

