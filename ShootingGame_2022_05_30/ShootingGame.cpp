// ShootingGame_2022_05_30.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "ShootingGame.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
HWND                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

enum class State {keyUpRep=0, keyDown=1, keyDownRep=2, keyUp=3 };

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    //초기화
    START_DEBUG_CONSOLE();

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SHOOTINGGAME20220530, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);

    HWND hWnd = InitInstance(hInstance, nCmdShow);

    //초기화
    InitGraphic(hWnd, 0, 0, 480, 800); //그래픽 초기화
    Time::Init();                      //델타타임 초기화

    //게임오브젝트들(배경, 플레이어) 추가하기
    ObjectManager::Instantiate(new GameBG(0     ,   0));
    ObjectManager::Instantiate(new Player(240-34, 650));

    //키 입력 테스트 하기//
    
    //상태 검사 키값들//
    int   keys[6]  = {VK_LEFT        ,  VK_RIGHT      ,            VK_UP,   VK_DOWN      , VK_SPACE       , 'Z' };
    State state[6] = { State::keyUpRep, State::keyUpRep, State::keyUpRep , State::keyUpRep, State::keyUpRep, State::keyUpRep }; //초기 상태

    while (true)
    {
        ///////////배열에 있는 키들의 상태 .. 변경 스테이트 머신////////
        for (int i = 0; i < 6; i++)
        {
            switch (state[i])
            {
            case State::keyUpRep:
            {
                if (GetAsyncKeyState(keys[i]) != 0)
                {
                    state[i] = State::keyDown;
                }
                else {
                    //state = State::keyUpRep;
                }
            }
            break;

            case State::keyDown:
            {
                if (GetAsyncKeyState(keys[i]) != 0)
                {
                    state[i] = State::keyDownRep;
                }
                else {
                    state[i] = State::keyUp;
                }
            }
            break;


            case State::keyDownRep:
            {
                if (GetAsyncKeyState(keys[i]) == 0)
                {
                    state[i] = State::keyUp;
                }
                else {
                    //state = State::keyDownRep;
                }
            }
            break;

            case State::keyUp:
            {
                if (GetAsyncKeyState(keys[i]) == 0)
                {
                    state[i] = State::keyUpRep;
                }
                else {
                    state[i] = State::keyDown;
                }
            }
            break;
            }
        }
        /////////////////////////////////////////////////////////





        ///////////////////////////////////////////////////
        ///////키 상태..체크하기////////////////////////////

        if (state[4] == State::keyDown)
        {
            cout << "발사키가 눌림";
        }
        /////////////////////////////////////////////////////      
    }

    MSG msg;

    // 기본 메시지 루프입니다:
    while ( true )
    {
        //윈도우 메세지 처리 하는 코드
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) == TRUE)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if (msg.message == WM_QUIT)
            {
                break;
            }
        }
        
        //게임 동작시키는 코드
        Clear(255, 0, 0);    //화면 클리어

        Time::Update();     //델타타임 업데이트

        ObjectManager::Update();  //게임객체 업데이트
        ObjectManager::Draw();    //게임객체 그리기

        Render();  //화면 출력
    }

    //종료하기
    STOP_DEBUG_CONSOLE();

    ObjectManager::Clear();  //게임객체 전체 삭제
    ExitGraphic();           //그래픽 종료

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SHOOTINGGAME20220530));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

HWND InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //윈도우 크기 조정하기 - AdjustWindowRect
   RECT rt = {0,0, 480, 800};
   AdjustWindowRect(&rt, (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX), FALSE);

   int width  = rt.right  - rt.left;
   int height = rt.bottom - rt.top;

   HWND hWnd = CreateWindowW(szWindowClass, 
                             szTitle, 
                             (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX ),
                             CW_USEDEFAULT, 
                             0, 
                             width,    //윈도우 가로 크기
                             height,   //윈도우 세로 크기
                             nullptr, 
                             nullptr, 
                             hInstance, 
                             nullptr);

   if (hWnd==nullptr)
   {
      return nullptr;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return hWnd;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            //윈도우 화면에..다시 렌더링해서..장면 복구하기
            Render();
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}