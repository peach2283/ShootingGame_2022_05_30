#include "ShootingGame.h"

/////////////////////////////////////////////////////////////////////////
////////////////���� �޴�////////////////////////////////////////////////
GameMenu::GameMenu(float px, float py) : GameObject("", "", true, px, py, 5)
{}

GameMenu::~GameMenu()
{}

void GameMenu::Start()
{
	//��� �ڽ� �߰��ϱ�
	AddChildObject(new MenuHeading(0, 0));

	//��� �ڽ� �߰��ϱ�
	AddChildObject(new MenuBG (0, 36));

	//�������� ���ư��� ��ư �ڽ� �߰��ϱ�
	AddChildObject(new ContinueItem(12, 48));

	//���� �ٽ� �����ϱ� ��ư �ڽ� �߰��ϱ�
	AddChildObject(new RestartItem(12,  48 + 44));

	//������� ������  ��ư �ڽ� �߰��ϱ�
	AddChildObject(new QuitItem(12,     48 + 44 + 44));
}

void GameMenu::Update()
{
}

/////////////////////////////////////////////////////////////////////
//////////// �޴� ��� ///////////////////////////////////////////////
MenuBG::MenuBG(float px, float py) : Sprite("", "", true, px, py, 5)
{
}

MenuBG::~MenuBG()
{}

void MenuBG::Start()
{
	SetSprite("Asset/UI/Menu/bg.bmp");
}

void MenuBG::Update()
{}

/////////////////////////////////////////////////////////////////
//////////////�޴� ���///////////////////////////////////////////
MenuHeading::MenuHeading(float px, float py) : Sprite("","",true, px, py, 5)
{}

MenuHeading::~MenuHeading()
{}

void MenuHeading::Start()
{
	SetSprite("Asset/UI/Menu/heading.bmp");
}

void MenuHeading::Update()
{}

///////////////////////////////////////////////////////////////////////
/////////////�������� ���ư��⼭ ����ϱ� �޴� ������ ��ư///////////////////
ContinueItem::ContinueItem(float px, float py) : Button("", "", true, px, py, 6)
{}

ContinueItem::~ContinueItem()
{}

void ContinueItem::Start()
{
	SetNormalImg("Asset/UI/Menu/normal.bmp");
	SetHoverImg ("Asset/UI/Menu/hover.bmp");
	SetPressImg ("Asset/UI/Menu/active.bmp");
}

void ContinueItem::OnClick()
{
	cout << "���� ����ϱ�" << endl;
}

////////////////////////////////////////////////////////////////////
//////////////�ٽý����ϱ� �޴� ������ ��ư //////////////////////////
RestartItem::RestartItem(float px, float py) : Button("", "", true, px, py, 6)
{}

RestartItem::~RestartItem()
{}

void RestartItem::Start()
{
	SetNormalImg("Asset/UI/Menu/normal.bmp");
	SetHoverImg("Asset/UI/Menu/hover.bmp");
	SetPressImg("Asset/UI/Menu/active.bmp");
}

void RestartItem::OnClick()
{
	cout << "���� �ٽ��ϱ�" << endl;
}

///////////////////////////////////////////////////////////////////
//////////////������� ������(������) �޴� ������ ��ư/////////////////
QuitItem::QuitItem(float px, float py) : Button("", "", true, px, py, 6)
{}

QuitItem::~QuitItem()
{}

void QuitItem::Start()
{
	SetNormalImg("Asset/UI/Menu/normal.bmp");
	SetHoverImg("Asset/UI/Menu/hover.bmp");
	SetPressImg("Asset/UI/Menu/active.bmp");
}

void QuitItem::OnClick()
{
	cout << "���� ������" << endl;
}