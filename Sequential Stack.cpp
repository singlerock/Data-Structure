#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct sqstack
{
	int* base;
	int* top;
	int stacksize;
}sqstack;

void createstack(sqstack& S)
{
	S.base = (int*)malloc(10 * sizeof(int));
	S.stacksize = 10;
	S.top = S.base;
	printf("Create stack successfully!\n");
}

void pushstack(sqstack& S)
{
	if (S.top - S.base == S.stacksize)
	{
		printf("Full stack!");
		exit(1);
	}
	printf("Please the number which you want to push:");
	int e;
	scanf("%d", &e);
	*S.top = e;
	S.top++;
	printf("%d push stack successfully!\n", e);
}

void popstack(sqstack& S)
{
	if (S.top == S.base)
	{
		printf("Empty stack!");
		exit(1);
	}
	int e;
	S.top--;
	e = *S.top;
	printf("%d pop stack successfully£¡\n", e);
}

void gettop(sqstack& S)
{
	if (S.top == S.base)
	{
		printf("Empty stack!");
		exit(1);
	}
	else
		printf("Stack top element is:%d\n", *(S.top - 1));
}

void menu()
{
	printf("\n****************************************************\n");
	printf("\n*********     Please enter your choice    **********\n");
	printf("\n*********       1 ---- Create stack       **********\n");
	printf("\n*********       2 ---- Push stack         **********\n");
	printf("\n*********       3 ---- Pop steack         **********\n");
	printf("\n*********       4 ---- Get stack top      **********\n");
	printf("\n****************************************************\n");
}

int main()
{
	sqstack S;
	menu();
	while (1)
	{
		int choice;
		printf("\nPlease select function:");
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
