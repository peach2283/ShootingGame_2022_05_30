#pragma once

#include <Windows.h>

//int   Input::keys[6] = { VK_LEFT        ,  VK_RIGHT      ,            VK_UP,   VK_DOWN      , VK_SPACE       , 'Z' };

enum class State  { keyUpRep = 0, keyDown  = 1, keyDownRep = 2, keyUp = 3 };
enum class KeyCode{ LeftArrow =0, RightArrow=1, UpArrow =2,  DownArrow=3, Space=4, Z=5};

class Input
{
private:

	static int   keys[6];
	static State state[6];

public:

	static void Update();

	static bool GetKeyDown(KeyCode key);
	static bool GetKeyUp  (KeyCode key);
	static bool GetKey    (KeyCode key);
};

