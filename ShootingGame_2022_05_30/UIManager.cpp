#include "ShootingGame.h"

UIManager::UIManager(float px, float py) : GameObject("","", true, px, py)
{
    this->gameMenu = nullptr;

    this->playerIcon[0] = nullptr;
    this->playerIcon[1] = nullptr;
    this->playerIcon[2] = nullptr;
}

UIManager::~UIManager()
{}

void UIManager::Start()
{
    ////////���� UI ��ü ���� �� �߰��ϱ�///////
    Instantiate(new Pause(430, 5));                //Pause ��ư �߰��ϱ�
    
    gameMenu=Instantiate(new GameMenu(122, 200));  //���� �޴� �߰��ϱ�

    //�÷��̾� ���� ������..�߰��ϱ�
    playerIcon[0] = Instantiate(new PlayerIcon(250         , 3));
    playerIcon[1] = Instantiate(new PlayerIcon(250 + 45    , 3));
    playerIcon[2] = Instantiate(new PlayerIcon(250 + 45+45 , 3));
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

    //�÷��̾� ī��Ʈ..ǥ�� 
    int playerCount = manager->GetPlayerCount();

    for (int i = 0; i < 3; i++)
    {
        if (i < playerCount) //i��° ������ ����
        {
            playerIcon[i]->SetActive(true);
        }
        else //i ��° ������ ����
        {
            playerIcon[i]->SetActive(false);
        }
    }

}
