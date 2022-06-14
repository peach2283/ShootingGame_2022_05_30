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
	//Box �浹ü..ȭ�鿡 �׸���//
	float x, y, width, height;

	colliders.GetBox(x, y, width, height);

	//�簢�� ������ ����ϱ�
	int x0 = x;
	int y0 = y;

	int x1 = x + width;
	int y1 = y + height;

	DrawRect(x0, y0, x1, y1, 255, 0, 0);
}

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
	float dx = px - this->px;  //SetPx�� ���ؼ�..����Ǵ� x ��ǥ�Ÿ�

	//���ӿ�����Ʈ..��ǥ ����
	this->px = px;

	//�浹ü��..��ǥ ���淮..��ŭ..�̵���Ű��
	colliders.Translate(dx, 0);
}

void GameObject::SetPy(float py)
{
	float dy = py - this->py;

	this->py = py;

	//�浹ü��..��ǥ ���淮..��ŭ..�̵���Ű��
	colliders.Translate(0, dy);
}

//���ӿ�����Ʈ...�̵� �Լ�
void GameObject::Translate(float x, float y)
{
	//���� ������Ʈ..�̵��ϱ�
	px = px + x;
	py = py + y;

	//�浹ü..�̵��ϱ�
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