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
	cout << "===���� ������Ʈ �Ҹ���===" << endl;
}

void GameObject::Start()
{}

void GameObject::Update()
{}

void GameObject::Draw()
{}

//���� �Լ�//
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

//���� �Լ�//
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
	this->px = px;
}

void GameObject::SetPy(float py)
{
	this->py = py;
}

//���ӿ�����Ʈ...�̵� �Լ�
void GameObject::Translate(float x, float y)
{
	px = px + x;
	py = py + y;
}

void GameObject::Instantiate(GameObject* obj)
{
	ObjectManager::Instantiate(obj);
}