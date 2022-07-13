#include "ShootingGame.h"

GameObject::GameObject(string tag, string name, bool active, float px, float py, int layer)
{
	this->tag    = tag;
	this->name   = name;
	this->active = active;
	this->layer  = layer;

	this->px = px;
	this->py = py;

	this->isDead = false; //생성자에서는 삭제대상 아님으로 표시
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

void GameObject::OnDestroy()
{}

void GameObject::DebugDraw()
{
	//Box 충돌체..화면에 그리기//
	float x, y, width, height;

	for (int i = 0; i < colliders.size(); i++)
	{
		colliders[i].GetBox(x, y, width, height);

		//사각형 꼭지점 계산하기
		int x0 = x;
		int y0 = y;

		int x1 = x + width;
		int y1 = y + height;

		DrawRect(x0, y0, x1, y1, 255, 0, 0);
	}
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

int GameObject::GetLayer()
{
	return layer;
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
	for (int i = 0; i < colliders.size(); i++)
	{
		colliders[i].Translate(dx, 0);
	}

	//자식객체에..좌표 변경량 만큼..이동시키기
	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->Translate(dx, 0);
	}
}

void GameObject::SetPy(float py)
{
	float dy = py - this->py;

	this->py = py;

	//충돌체에..좌표 변경량..만큼..이동시키기
	for (int i = 0; i < colliders.size(); i++)
	{
		colliders[i].Translate(0, dy);
	}

	//자식객체에..좌표 변경량 만큼..이동시키기
	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->Translate(0, dy);
	}
}

//게임오브젝트...이동 함수
void GameObject::Translate(float x, float y)
{
	//게임 오브젝트..이동하기
	px = px + x;
	py = py + y;

	//충돌체..이동하기
	for (int i = 0; i < colliders.size(); i++)
	{
		colliders[i].Translate(x, y);
	}

	//자식객체..이동하기
	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->Translate(x, y);
	}
}

GameObject* GameObject::Instantiate(GameObject* obj)
{
	ObjectManager::Instantiate(obj);

	return obj;
}

void GameObject::Destroy(GameObject* obj)
{
	//ObjectManager의 목록에서 제거하기
	ObjectManager::Destroy(obj);

	//obj가 자식객체일때...부모객체에서..제거하기
	//(obj가 보스의 자식인 프로펠러일때..보스의 자식목록에서..프로펠러를 제거함)





	//obj의 자식객체 삭제하기
	for (int i = 0; i < obj->childObjects.size(); i++)
	{
		ObjectManager::Destroy(obj->childObjects[i]);
	}
}

void GameObject::AddBoxCollider2D(float x, float y, float width, float height)
{
	this->colliders.push_back( BoxCollider2D( px + x, py + y, width, height) );
}

vector<BoxCollider2D> GameObject::GetColliders()
{
	return colliders;
}

void GameObject::OnTriggerStay2D(Collider2D collision)
{}

void GameObject::SetDead()
{
	this->isDead = true;  //삭제 대상으로..표시함
}

bool GameObject::GetDead()
{
	return isDead;
}

GameObject* GameObject::AddChildObject(GameObject* obj)
{
	//자식객첵 목록에 추가하기
	childObjects.push_back(obj);

	//자식객체의 원점(0,0)을 부모객체의 px, py를 기준으로 하기
	obj->Translate(px, py);

	//게임오브젝트 목록에 추가하기
	ObjectManager::Instantiate(obj);

	//추가되는 자식 객체 포인터 반환
	return obj;
}

GameObject* GameObject::Find(string name)
{
	for (int i = 0; i < childObjects.size(); i++)
	{
		if (childObjects[i]->GetName() == name)
		{
			return childObjects[i];
		}
	}

	return nullptr;  //for 문에서..이름이 같은..자식을 찾지못할 경우
}