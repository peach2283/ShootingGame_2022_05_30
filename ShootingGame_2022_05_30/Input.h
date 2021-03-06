#pragma once

#include <Windows.h>

	//int   Input::keys[6] = { VK_LEFT        ,  VK_RIGHT      ,            VK_UP,   VK_DOWN      , VK_SPACE       , 'Z' };
	enum class KeyCode { LeftArrow = 3, RightArrow = 4, UpArrow = 5, DownArrow = 6, Space = 7, Z = 8 };
	enum class State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

	//마우스 좌표 저장 2차원 벡터//
	struct Vector2
	{
		short x;
		short y;
	};

	class Input
	{

	private:

		static int   keys[9];
		static State state[9];

	public:

		//마우스 좌표 저장 변수
		static Vector2 mousePosition;

		static void Update();

		//키보드 키 입력 체크 함수
		static bool GetKeyDown(KeyCode key);
		static bool GetKeyUp(KeyCode key);
		static bool GetKey(KeyCode key);

		//마우스 버튼..눌림 체크 함수
		static bool GetMouseButtonDown(int button); //0-왼쪽 버튼, 1-오른쪽 버튼, 2-가운데 버튼
		static bool GetMouseButtonUp(int button);
		static bool GetMouseButton(int button);
	};