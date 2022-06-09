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
   
    //적기 추가하기..테스트
    ObjectManager::Instantiate(new Enemy(240-95, 100));

    //애니메이션 .. 테스트
    //ObjectManager::Instantiate(new Animation("", "", true, 100, 0));

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
        Input::Update();    //키 입력 상태 업데이트

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
    //마우스 좌표 구하기
    case WM_RBUTTONDOWN:
    case WM_RBUTTONUP:

    case WM_MBUTTONDOWN:
    case WM_MBUTTONUP:

    case WM_LBUTTONUP:
    case WM_MOUSEMOVE:
    case WM_LBUTTONDOWN:
    {
        short mx = LOWORD(lParam);
        short my = HIWORD(lParam);

        Input::mousePosition.x = mx;
        Input::mousePosition.y = my;
    }
    break;

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