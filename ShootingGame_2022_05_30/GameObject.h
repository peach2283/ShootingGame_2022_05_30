#pragma once
#include <iostream>
#include <string>
#include "BoxCollider2D.h"

using namespace std;

class GameObject
{
private:
	//기본 속성//
	string tag;
	string name;
	bool   active;

	//트랜스폼(Position, Roatation, Scale)//
	float px;  //position x
	float py;  //position y

	//Box 충돌체 추가 - BoxCollider2D
	BoxCollider2D colliders;

public:
	//생성자, 소멸자//
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	//부모..기본 (가상)함수//
	virtual void Start();
	virtual void Update();
	virtual void Draw();

	//충돌체 그리기 함수//
	void DebugDraw();

	//게터 함수//
	string GetTag();
	string GetName();
	bool   GetActive();

	float GetPx();
	float GetPy();

	void GetPosition(float &px, float &py);

	//세터 함수//
	void SetTag(string tag);
	void SetName(string name);
	void SetActive(bool active);

	void SetPx(float px);
	void SetPy(float py);

	//기타..추가된 함수들//
	void Translate(float x, float y);  //이동함수

	//게임 객체 생성 / 제거 함수
	void Instantiate(GameObject* obj);
	void Destroy(GameObject* obj);

	//충돌체(Collider)추가 함수
	void AddBoxCollider2D(float x, float y, float width, float height);

};

