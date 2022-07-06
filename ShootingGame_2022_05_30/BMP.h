#pragma once

struct Image
{
	int width;
	int height;
	unsigned int* argb;

	//�̹����� �Ǻ� ����//
	float pvx;   //�Ǻ� x ��ǥ
	float pvy;   //�Ǻ� y ��ǥ
};

class BMP
{
private:
public:
	static bool ReadBMP(const char* fileName, Image* img);
	static bool ReadBMP(const char* fileName, int x, int y, int width, int height, Image* img);

	static void DrawBMP(float px, float py, Image* img);
};