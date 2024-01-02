#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>

#define SIZE 10
#define LEN 20

int count = 0;

void menu(void);
int add(char name[SIZE][LEN], int score[SIZE]);
int del(char name[SIZE][LEN], int score[SIZE]);
int update(char name[SIZE][LEN], int score[SIZE]);
int find(char name[SIZE][LEN], int score[SIZE]);


int main()
{
	int menu_num;
	char stu_name[SIZE][LEN] = {0};
	int stu_score[SIZE] = {0};

	menu();

	printf("输入要进行的操作：");
	scanf("%d", &menu_num);

	while (1)
	{
		if (menu_num == 0)
		{
			printf("\n退出成功！\n");
			break;
		}

		switch (menu_num)
		{
			case 1:add(stu_name, stu_score); break;
			case 2:del(stu_name, stu_score); break;
			case 3:update(stu_name, stu_score); break;
			case 4:find(stu_name, stu_score); break;
			default:printf("输入有误！"); break;
		}

		printf("输入要进行的操作：");
		scanf("%d", &menu_num);
	}

	return 0;
}

void menu()
{
	printf("             学生管理系统             \n");
	printf("======================================\n");
	printf("1.添加  2.删除  3.修改  4.查询  0.退出\n");
	printf("======================================\n");
}

int add(char name[SIZE][LEN], int score[SIZE])
{
	int size;

	printf("要添加学生数：");
	scanf("%d", &size);

	for (int i = 0; i < size; i++)
	{
		printf("添加第%d学生的姓名：", i+1);
		scanf("%s", &name[i]);
		printf("第%d学生的数学成绩：", i+1);
		scanf("%d", &score[i]);
		count++;

	}

	printf("信息录入结束！\n");
	return 1;
}

int del(char name[SIZE][LEN], int score[SIZE])
{
	char inname[LEN] = { 0 };
	int flag = 0;
	printf("输入删除的学生姓名：");
	scanf("%s", inname);

	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(name[i], inname) == 0)
		{
			flag = 1;
			for (int j = i; j <= count - 1; j++)
			{
				strcpy(name[j] , name[j + 1]);
			}
			for (int s = i; s <= count - 1; s++)
			{
				score[s] = score[s + 1];
			}

			printf("删除成功！\n");
		}
	}
	if (flag == 0)
	{
		printf("查无此人！");
	}

	printf("删除后：\n");

	for (int i = 0; i <= count - 1; i++)
	{
		printf("%s ", name[i]);

	}
	printf("\n");

	for (int i = 0; i < count - 1; i++)
	{
		printf("%d ", score[i]);
	}
	printf("\n");

	return 1;
}

int update(char name[SIZE][LEN], int score[SIZE])
{
	char inname[LEN] = { 0 };
	printf("输入修改的学生姓名：");
	scanf("%s", inname);

	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(name[i], inname) == 0)
		{
			printf("修改成绩：");
			scanf("%d", &score[i]);
			printf("修改成功！\n");
			return 1;
		}
	}
	printf("查无此人！\n");
	return 0;
}

int find(char name[SIZE][LEN], int score[SIZE])
{
	char inname[LEN] = {0};
	printf("输入查询的学生姓名：");
	scanf("%s", inname);

	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(name[i], inname) == 0)
		{
			printf("用户名：%s\n成绩：%d\n", name[i], score[i]);
			return 1;
		}
	}
	printf("查无此人！\n");
	return 0;
}