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
    ////////게임 UI 객체 생성 및 추가하기///////
    Instantiate(new Pause(430, 5));                //Pause 버튼 추가하기
    
    gameMenu=Instantiate(new GameMenu(122, 200));  //게임 메뉴 추가하기

    //플레이어 갯수 아이콘..추가하기
    playerIcon[0] = Instantiate(new PlayerIcon(250         , 3));
    playerIcon[1] = Instantiate(new PlayerIcon(250 + 45    , 3));
    playerIcon[2] = Instantiate(new PlayerIcon(250 + 45+45 , 3));
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

}
