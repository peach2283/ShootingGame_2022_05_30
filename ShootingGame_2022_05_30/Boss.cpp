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
	//���� �⺻ �̹��� �߰�//
	SetSprite("Asset/����.bmp", 0, 0, 493, 206);

	//�����緯..�ڽ� ��ü �߰��ϱ�
	AddChildObject(new Propeller( 63+16, 41+6));
	AddChildObject(new Propeller(111+16, 41+6));
	AddChildObject(new Propeller(159+16, 41+6));

	AddChildObject(new Propeller(302+16, 41+6));
	AddChildObject(new Propeller(350+16, 41+6));
	AddChildObject(new Propeller(398+16, 41+6));

	//���� �ڽ� �߰��ϱ�
	AddChildObject(new Wing(298, 425, 30, 18,   256, 97));   //������ ù��° 
	AddChildObject(new Wing(329, 426, 32, 16,   302, 94));   //������ �ι�°
	AddChildObject(new Wing(364, 426, 32, 16,   350, 90));   //������ ����°
	AddChildObject(new Wing(399, 426, 32, 16,   405, 84));   //������ �׹�°

	AddChildObject(new Wing(404, 406, 28, 15,   206, 98));   //���� ù��°
	AddChildObject(new Wing(369, 406, 32, 16,   158, 94));   //���� �ι�°
	AddChildObject(new Wing(334, 406, 32, 16,   110, 90));   //���� ����°
	AddChildObject(new Wing(299, 406, 32, 16,    62, 85));   //���� �׹�°

	//�� �ڽ� �߰��ϱ�
	AddChildObject(new Gun(94 , 71, "��1"));
	AddChildObject(new Gun(142, 71, "��2"));
	AddChildObject(new Gun(190, 71, "��3"));

	AddChildObject(new Gun(238, 63, "��4"));

	AddChildObject(new Gun(286, 71, "��5"));
	AddChildObject(new Gun(334, 71, "��6"));
	AddChildObject(new Gun(382, 71, "��7"));

	//���� �ڽ� �߰��ϱ�
	AddChildObject(new Cannon(270, 107));
	AddChildObject(new Cannon(201, 107));

	//���̴� �ڽ� �߰��ϱ�
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
			  state = State::attack; //attack  ��������
		  }

		  break;

	 case State::attack:
		 {
			 //�߻�ð� �����ϱ�	
			 fireTimer = fireTimer + Time::deltaTime;

			 if (fireTimer >= fireDelay)
			 {
				 //�θ��� ������..�ڽ�(�ǵ�) ��ü�� ã�Ƽ�..������ �˸�//
				 string gunName[7] = { "��1", "��2", "��3", "��4", "��5", "��6", "��7" };

				 for (int i = 0; i < 7; i++)
				 {
					 GameObject* gun = Find(gunName[i]);

					 if (gun != nullptr)
					 {
						 ((Gun*)gun)->Fire();  //�ڽİ�ü �߻�
					 }
					 else {
						 cout << "�ڽ� ��ü�� ã�� ����" << endl;
					 }
				 }

				 fireTimer = 0;
			 }
		 }

		 break;
	
	 case State::fall:

		 //�̵��ϱ�
		 Translate(0, speed * Time::deltaTime);

		 //�߶� �ð�����
		 fallTimer = fallTimer - Time::deltaTime;

		 if (fallTimer <= 0)
		 {
			//�������� Ŭ����
			 cout << "�������� Ŭ����" << endl;
		 }

		 break;
	}

	//���� �̵��ϱ�
	//Translate(0, speed * Time::deltaTime);
}

void Boss::OnChildDestroy(string name)
{
	cout << "������ �ڽ� ��ü�� ���ŵ� : " << name << endl;

	childCount++;

	//if (childCount == 25)  //��� �ڽİ�ü��..�ı���
	if(childCount >=1)
	{
		//���� ����
		float px, py;
		GetPosition(px, py);

		Instantiate(new ShipExp(px + 170, py + 20));

		Instantiate(new ShipExp(px + 170 - 130 , py + 20));
		Instantiate(new ShipExp(px + 170 + 130 , py + 20));

		//������..�����̹��� ����		
		SetSprite("Asset/����.bmp", 0, 613, 385, 182, -47, -13);

		//������ �߶����·�..�����ϱ�
		state = State::fall;
	}
}