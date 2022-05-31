#pragma once

#include <Windows.h>

void InitGraphic(HWND hWnd, int x, int y, int width, int height);  //�׷��� ��� �ʱ�ȭ
void ExitGraphic();                                                //�׷��� ��� ���� 

void Clear(unsigned char r, unsigned char g, unsigned char b);     //r, g, b ������..����۸� �ʱ�ȭ��

void Render(); //�������...�׷��� ����Ÿ�� ȭ��(������ ����)�� ���

void SetPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b); //x,y ��ġ�� r, g, b �������
void SetPixel(int x, int y, unsigned int color); //x, y ��ġ�� r, g, b �������(���İ� ����)

void GetPixel(int x, int y, unsigned char &r, unsigned char &g, unsigned char &b);  //x,y ��ġ����..�̹� ��µ� r, g, b���� ������
void GetPixel(int x, int y, unsigned char *r, unsigned char *g, unsigned char *b);  //x,y ��ġ����..�̹� ��µ� r, g, b���� ������

void DrawLine(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b); //(x0, y0)���� (x1, y1)�� �մ� �����׸��� - r, g, b �� ����
void DrawCircle(int cx, int cy, int radius, unsigned char r, unsigned char g, unsigned b);        //�߽���(cx, cy)�̰� �������� radius�� �� �׸��� - r, g, b �� ����
void DrawRect(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b); //���ʻ�ܲ����� (x0, y0)�� �����ʲ����� (x1, y1)����  �簢�� �׸��� - r, g, b �� ����

int GetClientWidth();      //�׷��� ��� �簢���� ���� ���̸� ��ȯ��
int GetClientHeight();     //�׷��� ��� �簢���� ���� ���̸� ��ȯ��

HWND GetConsoleHwnd();