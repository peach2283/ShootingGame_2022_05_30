#include "ShootingGame.h"

UIManager::UIManager(float px, float py) : GameObject("","", true, px, py)
{
    this->gameMenu = nullptr;

    this->playerIcon[0] = nullptr;
    this->playerIcon[1] = nullptr;
    this->playerIcon[2] = nullptr;

    this->bombIcon[0] = nullptr;
    this->bombIcon[1] = nullptr;
    this->bombIcon[2] = nullptr;

    this->bombIcon[3] = nullptr;
    this->bombIcon[4] = nullptr;
    this->bombIcon[5] = nullptr;
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

    //��ź ���� ������ .. �߰��ϱ�
    bombIcon[0] = Instantiate(new BombIcon(10,           750));
    bombIcon[1] = Instantiate(new BombIcon(10 + 25     , 750));
    bombIcon[2] = Instantiate(new BombIcon(10 + 25 * 2 , 750));

    bombIcon[3] = Instantiate(new BombIcon(10 + 25 * 3 , 750));
    bombIcon[4] = Instantiate(new BombIcon(10 + 25 * 4 , 750));
    bombIcon[5] = Instantiate(new BombIcon(10 + 25 * 5 , 750));
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

    //��ź ī��Ʈ ... ǥ��
    int bombCount = manager->GetBombCount();

    for (int i = 0; i < 6; i++)
    {
        if (i < bombCount)
        {
            bombIcon[i]->SetActive(true);
        }
        else {
            bombIcon[i]->SetActive(false);
        }
    }

    //�÷��̾� ü�¹� .. ǥ��
    float hp = manager->GetHP();

}
