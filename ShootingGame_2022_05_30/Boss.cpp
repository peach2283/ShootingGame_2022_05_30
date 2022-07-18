#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("", "", true, px, py, 1)
{
	this->speed      = 50;
	this->childCount = 0;
	this->state      = State::appear;
	this->fallTimer  = 3;

	this->fireTimer = 0;
	this->fireDelay = 1;
}

Boss::~Boss()
{}

void Boss::Start()
{
	//보스 기본 이미지 추가//
	SetSprite("Asset/보스.bmp", 0, 0, 493, 206);

	//프로펠러..자식 객체 추가하기
	AddChildObject(new Propeller( 63+16, 41+6));
	AddChildObject(new Propeller(111+16, 41+6));
	AddChildObject(new Propeller(159+16, 41+6));

	AddChildObject(new Propeller(302+16, 41+6));
	AddChildObject(new Propeller(350+16, 41+6));
	AddChildObject(new Propeller(398+16, 41+6));

	//날개 자식 추가하기
	AddChildObject(new Wing(298, 425, 30, 18,   256, 97));   //오른쪽 첫번째 
	AddChildObject(new Wing(329, 426, 32, 16,   302, 94));   //오른쪽 두번째
	AddChildObject(new Wing(364, 426, 32, 16,   350, 90));   //오른쪽 세번째
	AddChildObject(new Wing(399, 426, 32, 16,   405, 84));   //오른쪽 네번째

	AddChildObject(new Wing(404, 406, 28, 15,   206, 98));   //왼쪽 첫번째
	AddChildObject(new Wing(369, 406, 32, 16,   158, 94));   //왼쪽 두번째
	AddChildObject(new Wing(334, 406, 32, 16,   110, 90));   //왼쪽 세번째
	AddChildObject(new Wing(299, 406, 32, 16,    62, 85));   //왼쪽 네번째

	//건 자식 추가하기
	AddChildObject(new Gun(94 , 71, "건1"));
	AddChildObject(new Gun(142, 71, "건2"));
	AddChildObject(new Gun(190, 71, "건3"));

	AddChildObject(new Gun(238, 63, "건4"));

	AddChildObject(new Gun(286, 71, "건5"));
	AddChildObject(new Gun(334, 71, "건6"));
	AddChildObject(new Gun(382, 71, "건7"));

	//대포 자식 추가하기
	AddChildObject(new Cannon(270, 107));
	AddChildObject(new Cannon(201, 107));

	//레이더 자식 추가하기
	AddChildObject(new Radar(241, 105));
	AddChildObject(new Radar(241, 117));
}

void Boss::Update()
{
	switch (state)
	{
	 case State::appear:

		  Translate(0, speed * Time::deltaTime);

		  if (GetPy() >= 30)
		  {
			  state = State::attack; //attack  상태전이
		  }

		  break;

	 case State::attack:
		 {
			 //발사시간 측정하기	
			 fireTimer = fireTimer + Time::deltaTime;

			 if (fireTimer >= fireDelay)
			 {
				 //부모인 보스가..자식(건들) 객체를 찾아서..공격을 알림//
				 string gunName[7] = { "건1", "건2", "건3", "건4", "건5", "건6", "건7" };

				 for (int i = 0; i < 7; i++)
				 {
					 GameObject* gun = Find(gunName[i]);

					 if (gun != nullptr)
					 {
						 ((Gun*)gun)->Fire();  //자식객체 발사
					 }
					 else {
						 cout << "자식 객체를 찾지 못함" << endl;
					 }
				 }

				 fireTimer = 0;
			 }
		 }

		 break;
	
	 case State::fall:

		 //이동하기
		 Translate(0, speed * Time::deltaTime);

		 //추락 시간측정
		 fallTimer = fallTimer - Time::deltaTime;

		 if (fallTimer <= 0)
		 {
			//스테이지 클리어
			 cout << "스테이지 클리어" << endl;
		 }

		 break;
	}

	//보스 이동하기
	//Translate(0, speed * Time::deltaTime);
}

void Boss::OnChildDestroy(string name)
{
	cout << "보스의 자식 객체가 제거됨 : " << name << endl;

	childCount++;

	//if (childCount == 25)  //모든 자식객체가..파괴됨
	if(childCount >=1)
	{
		//보스 폭발
		float px, py;
		GetPosition(px, py);

		Instantiate(new ShipExp(px + 170, py + 20));

		Instantiate(new ShipExp(px + 170 - 130 , py + 20));
		Instantiate(new ShipExp(px + 170 + 130 , py + 20));

		//보스의..폭발이미지 변경		
		SetSprite("Asset/보스.bmp", 0, 613, 385, 182, -47, -13);

		//보스를 추락상태로..변경하기
		state = State::fall;
	}
}