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
    ////////게임 UI 객체 생성 및 추가하기///////
    Instantiate(new Pause(430, 5));                //Pause 버튼 추가하기
    
    gameMenu=Instantiate(new GameMenu(122, 200));  //게임 메뉴 추가하기

    //플레이어 갯수 아이콘..추가하기
    playerIcon[0] = Instantiate(new PlayerIcon(250         , 3));
    playerIcon[1] = Instantiate(new PlayerIcon(250 + 45    , 3));
    playerIcon[2] = Instantiate(new PlayerIcon(250 + 45+45 , 3));

    //폭탄 갯수 아이콘 .. 추가하기
    bombIcon[0] = Instantiate(new BombIcon(10,           750));
    bombIcon[1] = Instantiate(new BombIcon(10 + 25     , 750));
    bombIcon[2] = Instantiate(new BombIcon(10 + 25 * 2 , 750));

    bombIcon[3] = Instantiate(new BombIcon(10 + 25 * 3 , 750));
    bombIcon[4] = Instantiate(new BombIcon(10 + 25 * 4 , 750));
    bombIcon[5] = Instantiate(new BombIcon(10 + 25 * 5 , 750));
}

void UIManager::Update()
{
    //게임매니저..인스턴스 가져오기//
    GameManager* manager = GameManager::Instance();
    
    //게임메뉴..활성화/비활성화
    if (manager->GetPause() == true) //게임 일시 정지
    {
        gameMenu->SetActive(true);  //게임메뉴 활성화
    }
    else  //게임 동작
    { 
        gameMenu->SetActive(false);  //게임메뉴 비활성화
    }

    //플레이어 카운트..표시 
    int playerCount = manager->GetPlayerCount();

    for (int i = 0; i < 3; i++)
    {
        if (i < playerCount) //i번째 아이콘 보임
        {
            playerIcon[i]->SetActive(true);
        }
        else //i 번째 아이콘 숨김
        {
            playerIcon[i]->SetActive(false);
        }
    }

    //폭탄 카은트 ... 표시
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

    //플레이어 체력바 .. 표시
    float hp = manager->GetHP();

}
