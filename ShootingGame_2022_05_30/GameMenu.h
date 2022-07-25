#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Button.h"

/////////////////////////////////////////////////////////////////////////
////////////////���� �޴�////////////////////////////////////////////////
class GameMenu : public GameObject
{
private:
public:
	GameMenu(float px, float py);
	~GameMenu();

	void Start();
	void Update();
};

/////////////////////////////////////////////////////////////////////
//////////// �޴� ��� ///////////////////////////////////////////////
class MenuBG : public Sprite
{
private:
public:
	MenuBG(float px, float py);
	~MenuBG();

	void Start();
	void Update();

};

/////////////////////////////////////////////////////////////////
//////////////�޴� ���///////////////////////////////////////////
class MenuHeading : public Sprite
{
private:
public:
	MenuHeading(float px, float py);
	~MenuHeading();

	void Start();
	void Update();
};

///////////////////////////////////////////////////////////////////////
/////////////�������� ���ư��⼭ ����ϱ� �޴� ������ ��ư///////////////////
class ContinueItem : public Button
{
private:
public:
	ContinueItem(float px, float py);
	~ContinueItem();

	void Start();
	void OnClick();
};

////////////////////////////////////////////////////////////////////
//////////////�ٽý����ϱ� �޴� ������ ��ư //////////////////////////
class RestartItem : public Button
{
private:
public:
	RestartItem(float px, float py);
	~RestartItem();

	void Start();
	void OnClick();
};

///////////////////////////////////////////////////////////////////
//////////////������� ������(������) �޴� ������ ��ư/////////////////
class QuitItem : public Button
{
private:
public:
	QuitItem(float px, float py);
	~QuitItem();

	void Start();
	void OnClick();
};