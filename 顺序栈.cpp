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
	printf("创建顺序栈成功！\n");
}

void pushstack(sqstack& S)
{
	if (S.top - S.base == S.stacksize)
	{
		printf("栈满！");
		exit(1);
	}
	printf("请输入入栈的数：");
	int e;
	scanf("%d", &e);
	*S.top = e;	
	S.top++;
	printf("%d入栈成功！\n", e);
}

void popstack(sqstack& S)
{
	if (S.top == S.base)
	{
		printf("栈空！");
		exit(1);
	}
	int e;
	S.top--;
	e = *S.top;
	printf("%d出栈成功！\n", e);
}

void gettop(sqstack& S)
{
	if (S.top == S.base)
	{
		printf("栈空！");
		exit(1);
	}
	else
		printf("栈顶元素为：%d\n", *(S.top-1));
}

void menu()
{
	printf("****************************************************\n");
	printf("*********        请输入你的选择          ***********\n");
	printf("*********       1 ---- 创建顺序栈        ***********\n");
	printf("*********       2 ---- 入栈              ***********\n");
	printf("*********       3 ---- 出栈              ***********\n");
	printf("*********       4 ---- 取栈顶元素        ***********\n");
	printf("****************************************************\n");
}

int main()
{
	sqstack S;
	menu();
	while (1)
	{
		int choice;
		printf("请输入选择：");
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