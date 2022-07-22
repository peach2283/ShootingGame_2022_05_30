#include "ShootingGame.h"

/////////////////////////////////////////////////////////////////////////
////////////////게임 메뉴////////////////////////////////////////////////
GameMenu::GameMenu(float px, float py) : GameObject("", "", true, px, py, 5)
{}

GameMenu::~GameMenu()
{}

void GameMenu::Start()
{
	//헤더 자식 추가하기
	AddChildObject(new MenuHeading(0, 0));

	//배경 자식 추가하기
	AddChildObject(new MenuBG (0, 36));

	//게임으로 돌아가기 버튼 자식 추가하기
	//게임 다시 시작하기 버튼 자식 추가하기
	//타이틀로 나가기  버튼 자식 추가하기
}

void GameMenu::Update()
{

}

/////////////////////////////////////////////////////////////////////
//////////// 메뉴 배경 ///////////////////////////////////////////////
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
//////////////메뉴 헤딩///////////////////////////////////////////
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
/////////////게임으로 돌아가기서 계속하기 메뉴 아이템 버튼///////////////////
ContinueItem::ContinueItem(float px, float py) : Button("", "", true, px, py, 5)
{}

ContinueItem::~ContinueItem()
{}

void ContinueItem::Start()
{
	SetNormalImg("Asset/UI/Menu/normal.bmp");
	SetHoverImg ("Asset/UI/Menu/hover.bmp");
	SetPressImg ("Asset/UI/Menu/active.bmp");
}


////////////////////////////////////////////////////////////////////
//////////////다시시작하기 메뉴 아이템 버튼 //////////////////////////
RestartItem::RestartItem(float px, float py) : Button("", "", true, px, py, 5)
{}

RestartItem::~RestartItem()
{}

void RestartItem::Start()
{
	SetNormalImg("Asset/UI/Menu/normal.bmp");
	SetHoverImg("Asset/UI/Menu/hover.bmp");
	SetPressImg("Asset/UI/Menu/active.bmp");
}

///////////////////////////////////////////////////////////////////
//////////////윈도우로 나가기(끝내기) 메뉴 아이템 버튼/////////////////
QuitItem::QuitItem(float px, float py) : Button("", "", true, px, py, 5)
{}

QuitItem::~QuitItem()
{}

void QuitItem::Start()
{
	SetNormalImg("Asset/UI/Menu/normal.bmp");
	SetHoverImg("Asset/UI/Menu/hover.bmp");
	SetPressImg("Asset/UI/Menu/active.bmp");
}