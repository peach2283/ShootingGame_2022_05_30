#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BoxCollider2D.h"
#include "Collider2D.h"

using namespace std;

class GameObject
{
private:
	//�⺻ �Ӽ�//
	string tag;
	string name;
	bool   active;
	int    layer;

	//���� ���������..ǥ���ϴ� ����
	bool isDead;  //true - ���������, false - �������ƴ�

	//Ʈ������(Position, Roatation, Scale)//
	float px;  //position x
	float py;  //position y

	//Box �浹ü �߰� - BoxCollider2D
	vector<BoxCollider2D> colliders;

public:
	//������, �Ҹ���//
	GameObject(string tag, string name, bool active, float px, float py, int layer=0);
	virtual ~GameObject();

	//�θ�..�⺻ (����)�Լ�//
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void OnDestroy();

	//�浹ü �׸��� �Լ�//
	virtual void DebugDraw();

	//���� �Լ�//
	string GetTag();
	string GetName();
	bool   GetActive();

	float GetPx();
	float GetPy();

	void GetPosition(float &px, float &py);

	//���� �Լ�//
	void SetTag(string tag);
	void SetName(string name);
	void SetActive(bool active);

	void SetPx(float px);
	void SetPy(float py);

	//��Ÿ..�߰��� �Լ���//
	void Translate(float x, float y);  //�̵��Լ�

	//���� ��ü ���� / ���� �Լ�
	void Instantiate(GameObject* obj);
	void Destroy(GameObject* obj);

	//�浹ü(Collider)�߰� �Լ�
	void AddBoxCollider2D(float x, float y, float width, float height);

	//�浹 �ڽ� ��ȯ�Լ�
	vector<BoxCollider2D> GetColliders();

	//�浹 �̺�Ʈ �Լ�
	virtual void OnTriggerStay2D(Collider2D collision);

	//���� �������..ǥ���ϴ�/�������� �Լ�//
	void SetDead();  //���� ���ǥ�� 
	bool GetDead();  //���� ǥ�� ��������
};

