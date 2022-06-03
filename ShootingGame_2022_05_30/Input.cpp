#include "ShootingGame.h"

int   Input::keys[6]  = { VK_LEFT        ,  VK_RIGHT      ,            VK_UP,   VK_DOWN      , VK_SPACE       , 'Z' };
State Input::state[6] = { State::keyUpRep, State::keyUpRep, State::keyUpRep , State::keyUpRep, State::keyUpRep, State::keyUpRep }; //초기 상태

void Input::Update()
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
}

bool Input::GetKeyDown(KeyCode key)
{
    if (state[(int)key] == State::keyDown)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::GetKeyUp(KeyCode key)
{
    if (state[(int)key] == State::keyUp)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::GetKey(KeyCode key)
{
    if (state[(int)key] == State::keyDownRep)
    {
        return true;
    }
    else {
        return false;
    }
}
