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
	//기본 속성//
	string tag;
	string name;
	bool   active;
	int    layer;
	//int    orderInLayer; [유니티에서] 동일 레이어내의 객체들의 세부 순서를 정하는 옵션

	//삭제 대상인지를..표시하는 변수
	bool isDead;  //true - 삭제대상임, false - 삭제대상아님

	//트랜스폼(Position, Roatation, Scale)//
	float px;  //position x
	float py;  //position y

	//Box 충돌체 추가 - BoxCollider2D
	vector<BoxCollider2D> colliders;

	//게임오브젝트에..자식게임오브젝트 추가하기//
	vector<GameObject*> childObjects;

	//자식객체일 경우에...부모객체의 포인터 저장하는 변수
	GameObject* parent;

public:
	//생성자, 소멸자//
	GameObject(string tag, string name, bool active, float px, float py, int layer=0);
	virtual ~GameObject();

	//부모..기본 (가상)함수//
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void OnDestroy();

	//충돌체 그리기 함수//
	virtual void DebugDraw();

	//게터 함수//
	string GetTag();
	string GetName();
	bool   GetActive();

	float GetPx();
	float GetPy();

	void GetPosition(float &px, float &py);

	int GetLayer();

	//세터 함수//
	void SetTag(string tag);
	void SetName(string name);
	void SetActive(bool active);

	void SetPx(float px);
	void SetPy(float py);

	//기타..추가된 함수들//
	void Translate(float x, float y);  //이동함수

	//게임 객체 생성 / 제거 함수
	GameObject* Instantiate(GameObject* obj);
	void Destroy(GameObject* obj);

	//충돌체(Collider)추가 함수
	void AddBoxCollider2D(float x, float y, float width, float height);

	//충돌 박스 반환함수
	vector<BoxCollider2D> GetColliders();

	//충돌 이벤트 함수
	virtual void OnTriggerStay2D(Collider2D collision);

	//삭제 대상으로..표시하는/가져오는 함수//
	void SetDead();  //삭제 대상표시 
	bool GetDead();  //삭제 표시 가져오기

	//자식 게임오브젝트 추가함수
	GameObject * AddChildObject(GameObject* obj);

	//이름으로..자식객체 찾기
	GameObject* Find(string name);

	//parent 게터
	GameObject* GetParent();
};

