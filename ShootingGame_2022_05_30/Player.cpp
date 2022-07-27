#include "ShootingGame.h"

Player::Player(float px, float py) :Animation("�÷��̾�", "", true, px, py, 2)
{
	this->speed      = 200;
	
	this->laserCount  = 1;   //�������� ȹ���ϸ�..�߻簹�� ����
	this->fireTimer   = 0;   
	this->fireDelay   = 0.2; //�߻簣 �����ð�

	this->shieldTimer = 5;            //���� ���ӽð�
	this->state       = State::appear;//�÷��̾� �ʱ����
}

Player::~Player()
{}

void Player::Start()
{
	///////���ڸ�..�ִϸ��̼�    - 0  ��
	AddSprite("Asset/�����̵�2.bmp", 192, 0, 62, 80,      0);

	///////������ �̵�..�ִϸ��̼� - 1 �� 
	AddSprite("Asset/�����̵�2.bmp", 256 + 64 * 0 , 0, 62, 80,      1);
	AddSprite("Asset/�����̵�2.bmp", 256 + 64 * 1 , 0, 62, 80,      1);
	AddSprite("Asset/�����̵�2.bmp", 256 + 64 * 2 , 0, 62, 80,      1);

	///////���� �̵� ...�ִϸ��̼� - 2 ��
	AddSprite("Asset/�����̵�2.bmp", 128 - 64 * 0, 0, 62, 80,       2);
	AddSprite("Asset/�����̵�2.bmp", 128 - 64 * 1, 0, 62, 80,       2);
	AddSprite("Asset/�����̵�2.bmp", 128 - 64 * 2, 0, 62, 80,       2);

	/////�ִϸ��̼� ���� ����////////
	SetLoop(false);

	/////�ִϸ��̼� �ӵ� ����///////
	SetSpeed(0.5);

	//�÷��̾� �浹ü �߰��ϱ�/////
	//AddBoxCollider2D(0, 0, 62, 80);

	AddBoxCollider2D(22, 5, 18, 65);  //��� ����..�浹�ڽ�
	AddBoxCollider2D(5, 40, 52, 15);  //��� ����..�浹�ڽ�

	//��ȣ���и� �ڽİ�ü��..�߰��ϱ�//
	AddChildObject(new Shield(-12, -8));
}

void Player::Update()
{	
	switch (state)
	{
		case State::appear:
		{
			Appear();
		}
		break;

		case State::control:
		{
			Move();			//�̵� �Լ�
			Fire();			//�߻� �Լ�
			ShieldTimer();  //���� �ð� �����ϱ�//
		}
		break;
	}
}

void Player::Appear()
{
	Translate(0, -speed * Time::deltaTime);

	if (GetPy() <= 650)
	{
		state = State::control;  //�÷��̾��� ��������(control)
	}
}

void Player::Move()  //�̵� �Լ�
{
	/////////////�÷��̾� �̵��ϱ�/////////////////
	if ( Input::GetKey(KeyCode::LeftArrow) == true )
	{
		Translate(-speed * Time::deltaTime, 0);
		Play(2);

		//x ��ǥ ��������
		float px = GetPx();

		if (px < -9)
		{
			SetPx(-9);
		}
	}

	if ( Input::GetKey(KeyCode::RightArrow) == true )
	{
		Translate(speed * Time::deltaTime, 0); //������ �̵�
		Play(1);                               //������ �̵� �ִϸ��̼�

		float px = GetPx();

		if (px > 480  - 62 + 9)
		{
			SetPx(480 - 62 + 9);
		}
	}

	if ( Input::GetKey(KeyCode::UpArrow) == true)
	{
		Translate(0, -speed * Time::deltaTime);

		float py = GetPy();

		if (py < 0)
		{
			SetPy(0);
		}
	}

	if ( Input::GetKey(KeyCode::DownArrow) == true )
	{
		Translate(0, speed * Time::deltaTime);

		float py = GetPy();

		if (py > 800 - 80 + 7)
		{
			SetPy(800 - 80 + 7);
		}
	}

	///////�����̵��� ������ �̵��� �ƴҶ�..���ڸ� �ִϸ��̼� �����ϱ�//////
	if (Input::GetKey(KeyCode::LeftArrow) != true && Input::GetKey(KeyCode::RightArrow) != true)
	{
		Play(0);  //���ڸ� �ִϸ��̼� ���
	}
}

void Player::Fire()  //�߻� �Լ�
{
	/////////�÷��̾� ������ �߻��ϱ�/////////
	if (Input::GetKey(KeyCode::Space) == true)
	{
		//�߻� �ð� �����ϱ�
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px, py;

			GetPosition(px, py);

			if (laserCount == 1)
			{
				//������ �ѹ� ���
				Instantiate(new Laser(px + 28, py - 26));
			}
			else if (laserCount == 2)
			{
				//������ �ι� ���
				Instantiate(new Laser(px + 28 - 10, py - 30));
				Instantiate(new Laser(px + 28 + 10, py - 30));
			}
			else if (laserCount == 3)
			{
				//������ ���� ���
				Instantiate(new Laser(px + 28 - 10, py - 20 + 10));
				Instantiate(new Laser(px + 28     , py - 20 - 10));
				Instantiate(new Laser(px + 28 + 10, py - 20 + 10));
			}

			fireTimer = 0;  //�߻� Ÿ�̸�..����
		}
	}

	///////////////��ź �߻��ϱ�/////////////
	if (Input::GetKeyDown(KeyCode::Z) == true)
	{
		GameManager* manager = GameManager::Instance();

		if ( manager->GetBombCount()  > 0)
		{
			float px, py;

			GetPosition(px, py);
			//Instantiate(new Bomb(px+15, py-20));
			Instantiate(new Bomb(px + 15, py));

			manager->DecBombCount();  //��ź ���� ����
		}
		else {
			cout << "���� ��ź�� �����ϴ�" << endl;
		}
	}
}

void Player::ShieldTimer()
{
	shieldTimer = shieldTimer - Time::deltaTime;

	if (shieldTimer <= 0)
	{
		//���� �������� �ʰ��ϱ� (���� ��Ȱ��ȭ�ϱ�)
		GameObject* shield = Find("����");

		if (shield != nullptr)
		{
			shield->SetActive(false);
		}
		else {
			cout << "���� �ڽ� ��ü�� ã�� ����" << endl;
		}
	}
}

void Player::OnTriggerStay2D(Collider2D collision)
{
	/****************************************/
	string tag = collision.tag;

	if (tag == "�Ѿ�1" || tag=="�Ѿ�2")
	{
		//���� �Ѿ�1, �Ѿ�2 �浹 ����
		/**********************/
		GameManager* manager = GameManager::Instance();

		manager->DoDamage(10);

		if ( manager->GetHP()  <= 0 )
		{
			Explode();
		}
		/***********************/

	}else if (tag == "����" || tag == "�����ڽ�")
	{
		/**************/
		Explode();
		/*************/
	}
	else if (tag == "������������")
	{
		//������ �߻� ī��Ʈ ����//
		laserCount++;

		//�ִ뷹���� �߻簹���� 3���� ������//
		if (laserCount > 3)
		{
			laserCount = 3;
		}
	}
	else if (tag == "��ź������")
	{
		//��ź ī��Ʈ(��ź����) ����//
		//GameManager* manager = GameManager::Instance();
		//manager->IncBombCount();

		GameManager::Instance()->IncBombCount();
	}
	/*****************************************/
}

void Player::Explode()
{
	//�÷��̾� ����
	float px, py;

	GetPosition(px, py);
	Instantiate(new ShipExp(px - 50, py - 50));

	//�÷��̾� ����
	Destroy(this);

	//�÷��̾�..�������ϱ�
	GameManager * manager=GameManager::Instance();
	manager->RespawnPlayer();
}