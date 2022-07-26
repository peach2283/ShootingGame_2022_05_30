#include "ShootingGame.h"

UIManager::UIManager(float px, float py) : GameObject("","", true, px, py)
{
    this->gameMenu = nullptr;
}

UIManager::~UIManager()
{}

void UIManager::Start()
{
    ////////���� UI ��ü ���� �� �߰��ϱ�///////
    Instantiate(new Pause(430, 5));       //Pause ��ư �߰��ϱ�
    
    gameMenu=Instantiate(new GameMenu(122, 200));  //���� �޴� �߰��ϱ�
}

void UIManager::Update()
{
    //���ӸŴ���..�ν��Ͻ� ��������//
    GameManager* manager = GameManager::Instance();
    
    //���Ӹ޴�..Ȱ��ȭ/��Ȱ��ȭ
    if (manager->GetPause() == true) //���� �Ͻ� ����
    {
        gameMenu->SetActive(true);  //���Ӹ޴� Ȱ��ȭ
    }
    else  //���� ����
    { 
        gameMenu->SetActive(false);  //���Ӹ޴� ��Ȱ��ȭ
    }
}
