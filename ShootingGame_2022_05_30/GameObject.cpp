#include "ShootingGame.h"

GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag    = tag;
	this->name   = name;
	this->active = active;

	this->px = px;
	this->py = py;
}

GameObject::~GameObject()
{
}

void GameObject::Start()
{}

void GameObject::Update()
{}

void GameObject::Draw()
{}

void GameObject::DebugDraw()
{
	//Box 충돌체..화면에 그리기//
	float x, y, width, height;

	colliders.GetBox(x, y, width, height);

	//사각형 꼭지점 계산하기
	int x0 = x;
	int y0 = y;

	int x1 = x + width;
	int y1 = y + height;

	DrawRect(x0, y0, x1, y1, 255, 0, 0);
}

//게터 함수//
string GameObject::GetTag()
{
	return tag;
}

string GameObject::GetName()
{
	return name;
}

bool GameObject::GetActive()
{
	return active;
}

float GameObject::GetPx()
{
	return px;
}

float GameObject::GetPy()
{
	return py;
}

void GameObject::GetPosition(float& px, float& py)
{
	px = this->px;
	py = this->py;
}

//세터 함수//
void GameObject::SetTag(string tag)
{
	this->tag = tag;
}

void GameObject::SetName(string name)
{
	this->name = name;
}

void GameObject::SetActive(bool active)
{
	this->active = active;
}

void GameObject::SetPx(float px)
{
	float dx = px - this->px;  //SetPx에 의해서..변경되는 x 좌표거리

	//게임오브젝트..좌표 변경
	this->px = px;

	//충돌체에..좌표 변경량..만큼..이동시키기
	colliders.Translate(dx, 0);
}

void GameObject::SetPy(float py)
{
	float dy = py - this->py;

	this->py = py;

	//충돌체에..좌표 변경량..만큼..이동시키기
	colliders.Translate(0, dy);
}

//게임오브젝트...이동 함수
void GameObject::Translate(float x, float y)
{
	//게임 오브젝트..이동하기
	px = px + x;
	py = py + y;

	//충돌체..이동하기
	colliders.Translate(x, y);
}

void GameObject::Instantiate(GameObject* obj)
{
	ObjectManager::Instantiate(obj);
}

void GameObject::Destroy(GameObject* obj)
{
	ObjectManager::Destroy(obj);
}

void GameObject::AddBoxCollider2D(float x, float y, float width, float height)
{
	this->colliders = BoxCollider2D( px + x, py + y, width, height);
}

BoxCollider2D GameObject::GetColliders()
{
	return colliders;
}

void GameObject::OnTriggerStay2D()
{}