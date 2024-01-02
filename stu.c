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

	printf("����Ҫ���еĲ�����");
	scanf("%d", &menu_num);

	while (1)
	{
		if (menu_num == 0)
		{
			printf("\n�˳��ɹ���\n");
			break;
		}

		switch (menu_num)
		{
			case 1:add(stu_name, stu_score); break;
			case 2:del(stu_name, stu_score); break;
			case 3:update(stu_name, stu_score); break;
			case 4:find(stu_name, stu_score); break;
			default:printf("��������"); break;
		}

		printf("����Ҫ���еĲ�����");
		scanf("%d", &menu_num);
	}

	return 0;
}

void menu()
{
	printf("             ѧ������ϵͳ             \n");
	printf("======================================\n");
	printf("1.���  2.ɾ��  3.�޸�  4.��ѯ  0.�˳�\n");
	printf("======================================\n");
}

int add(char name[SIZE][LEN], int score[SIZE])
{
	int size;

	printf("Ҫ���ѧ������");
	scanf("%d", &size);

	for (int i = 0; i < size; i++)
	{
		printf("��ӵ�%dѧ����������", i+1);
		scanf("%s", &name[i]);
		printf("��%dѧ������ѧ�ɼ���", i+1);
		scanf("%d", &score[i]);
		count++;

	}

	printf("��Ϣ¼�������\n");
	return 1;
}

int del(char name[SIZE][LEN], int score[SIZE])
{
	char inname[LEN] = { 0 };
	int flag = 0;
	printf("����ɾ����ѧ��������");
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

			printf("ɾ���ɹ���\n");
		}
	}
	if (flag == 0)
	{
		printf("���޴��ˣ�");
	}

	printf("ɾ����\n");

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
	printf("�����޸ĵ�ѧ��������");
	scanf("%s", inname);

	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(name[i], inname) == 0)
		{
			printf("�޸ĳɼ���");
			scanf("%d", &score[i]);
			printf("�޸ĳɹ���\n");
			return 1;
		}
	}
	printf("���޴��ˣ�\n");
	return 0;
}

int find(char name[SIZE][LEN], int score[SIZE])
{
	char inname[LEN] = {0};
	printf("�����ѯ��ѧ��������");
	scanf("%s", inname);

	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(name[i], inname) == 0)
		{
			printf("�û�����%s\n�ɼ���%d\n", name[i], score[i]);
			return 1;
		}
	}
	printf("���޴��ˣ�\n");
	return 0;
}