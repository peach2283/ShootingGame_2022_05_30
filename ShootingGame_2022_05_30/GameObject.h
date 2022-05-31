#pragma once
#include <iostream>
#include <string>

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

	//��Ÿ..�߰��� �Ӽ���//
public:
	//������, �Ҹ���//
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	//�θ�..�⺻ (����)�Լ�//
	virtual void Start();
	virtual void Update();
	virtual void Draw();

	//���� �Լ�//
	string GetTag();
	string GetName();
	bool   GetActive();

	float GetPx();
	float GetPy();

	//���� �Լ�//
	void SetTag(string tag);
	void SetName(string name);
	void SetActive(bool active);

	void SetPx(float px);
	void SetPy(float py);

	//��Ÿ..�߰��� �Լ���//
	void Translate(float x, float y);  //�̵��Լ�
};

