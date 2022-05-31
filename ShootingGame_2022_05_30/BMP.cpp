#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#include "BMP.h"
#include "Graphic.h"

bool BMP::ReadBMP(const char* fileName, Image* img)
{
	//��Ʈ�� ���� �б�//
	FILE* stream;

	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	stream = fopen(fileName, "rb");

	if (stream != nullptr)
	{
		//BITMAPFILEHEADER �о����//
		fread(&fileHeader, sizeof(fileHeader), 1, stream);

		/*************************
		printf("-----��Ʈ��������� ���-------\n");
		printf("bfType : 0x%x\n", fileHeader.bfType);			//���ε���Ÿ����..bmp ���� ���������� Ȯ���ϴ� �ڵ�(�����ڵ�)
		printf("bfSize : %d ����Ʈ\n", fileHeader.bfSize);      //����ũ��	
		printf("bfReserved1 : %d\n", fileHeader.bfReserved1);   //���� ����� ���ؼ�..����� ����1
		printf("bfReserved2 : %d\n", fileHeader.bfReserved2);   //���� ����� ���ؼ�..����� ����2
		printf("bfOffBits : %d\n", fileHeader.bfOffBits);		//�׸�����Ÿ(bitmap ����Ÿ)�� ����Ȱ� ������ ������ ����(Offset)
		**************************/

		//BITMAPINFOHEADER �о����//
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		/*******************************
		printf("-------��Ʈ��������� ���--------\n");
		printf("biWidth    : %d\n", infoHeader.biWidth);
		printf("biHeight   : %d\n", infoHeader.biHeight);
		printf("biBitCount : %d\n", infoHeader.biBitCount);
		*******************************/

		//��Ʈ�� �ȼ� ����Ÿ �о����//
		int width = infoHeader.biWidth;
		int height = infoHeader.biHeight;
		int length = width * height;

		unsigned int* argb = new unsigned int[length];

		fread(argb, sizeof(unsigned int), length, stream);

		//���� �ݱ�
		fclose(stream);

		//��Ʈ�� ����...����ü �迭�� �����ϱ�
		img->width = width;
		img->height = height;
		img->argb = argb;

		return true;  //�̹��� �ε� ����
	}
	else {
		printf("��Ʈ�� ������ �о�ü� �����ϴ�\n");

		return false;  //�̹��� �ε� ����
	}
}

void BMP::DrawBMP(float px, float py, Image* img)
{
	//�̹��� draw//
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
		{
			unsigned int pixel = img->argb[y * img->width + x];

			SetPixel(px + x, py + y, pixel);
		}
	}
}