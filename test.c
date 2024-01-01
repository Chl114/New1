#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* word = (char*)malloc(36216);

	if (word == NULL)
	{
		printf("创建失败！");
		return -1;
	}

	FILE* fp = fopen("C:\\Users\\CC\\Desktop\\图书馆管理系统.docx", "rb");
	if (fp == NULL)
	{
		printf("打开文件失败！");
		return -2;
	}
	fread(word, 1, 36216, fp);
	fclose(fp);

	fp = fopen("D:\\tushu.docx", "wb");
	if (fp == NULL)
	{
		printf("打开文件失败！");
		return -4;
	}
	fwrite(word, 1, 36216, fp);
	fclose(fp);

	return 0;
}