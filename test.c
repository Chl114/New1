#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* word = (char*)malloc(36216);

	if (word == NULL)
	{
		printf("����ʧ�ܣ�");
		return -1;
	}

	FILE* fp = fopen("C:\\Users\\CC\\Desktop\\ͼ��ݹ���ϵͳ.docx", "rb");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
		return -2;
	}
	fread(word, 1, 36216, fp);
	fclose(fp);

	fp = fopen("D:\\tushu.docx", "wb");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
		return -4;
	}
	fwrite(word, 1, 36216, fp);
	fclose(fp);

	return 0;
}