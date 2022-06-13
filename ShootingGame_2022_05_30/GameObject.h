#pragma once
#include <iostream>
#include <string>
#include "BoxCollider2D.h"

using namespace std;

class GameObject
{
private:
	//�⺻ �Ӽ�//
	string tag;
	string name;
	bool   active;

	//Ʈ������(Position, Roatation, Scale)//
	float px;  //position x
	float py;  //position y

	//Box �浹ü �߰� - BoxCollider2D
	BoxCollider2D colliders;

public:
	//������, �Ҹ���//
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	//�θ�..�⺻ (����)�Լ�//
	virtual void Start();
	virtual void Update();
	virtual void Draw();

	//�浹ü �׸��� �Լ�//
	void DebugDraw();

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

};

