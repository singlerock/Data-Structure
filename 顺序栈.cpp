#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct sqstack
{
	int * base;
	int* top;
	int stacksize;
}sqstack;

void createstack(sqstack& S)
{
	S.base = (int*)malloc(10 * sizeof(int));
	S.stacksize = 10;
	S.top = S.base;
	printf("����˳��ջ�ɹ���\n");
}

void pushstack(sqstack& S)
{
	if (S.top - S.base == S.stacksize)
	{
		printf("ջ����");
		exit(1);
	}
	printf("��������ջ������");
	int e;
	scanf("%d", &e);
	*S.top = e;	
	S.top++;
	printf("%d��ջ�ɹ���\n", e);
}

void popstack(sqstack& S)
{
	if (S.top == S.base)
	{
		printf("ջ�գ�");
		exit(1);
	}
	int e;
	S.top--;
	e = *S.top;
	printf("%d��ջ�ɹ���\n", e);
}

void gettop(sqstack& S)
{
	if (S.top == S.base)
	{
		printf("ջ�գ�");
		exit(1);
	}
	else
		printf("ջ��Ԫ��Ϊ��%d\n", *(S.top-1));
}

void menu()
{
	printf("****************************************************\n");
	printf("*********        ���������ѡ��          ***********\n");
	printf("*********       1 ---- ����˳��ջ        ***********\n");
	printf("*********       2 ---- ��ջ              ***********\n");
	printf("*********       3 ---- ��ջ              ***********\n");
	printf("*********       4 ---- ȡջ��Ԫ��        ***********\n");
	printf("****************************************************\n");
}

int main()
{
	sqstack S;
	menu();
	while (1)
	{
		int choice;
		printf("������ѡ��");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			createstack(S);
			break;
		case 2:
			pushstack(S);
			break;
		case 3:
			popstack(S);
			break;
		case 4:
			gettop(S);
			break;
		}
	}
	return 0;
}