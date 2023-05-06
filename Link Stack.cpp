#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef  struct linkstack
{
	int  data;
	struct linkstack* next;
}linkstack;

linkstack* S;

void creatstack()
{
	S = (linkstack*)malloc(sizeof(linkstack));
	S = NULL;
	printf("Create linkstack successfully!\n");
}

void pushstack(int e)
{
	linkstack* p;
	p = (linkstack*)malloc(sizeof(linkstack));
	p->data = e;
	p->next = S;
	S = p;
	printf("%d pushstack successfully!\n", e);
}

void popstack()
{
	linkstack* p;
	p = (linkstack*)malloc(sizeof(linkstack));
	if (S == NULL)
	{
		printf("Empty stack!");
		exit(1);
	}
	p = S;
	printf("%d pop stack successfully!\n", p->data);
	S = S->next;
	free(p);
}

void gettop()
{
	if (S == NULL)
	{
		printf("Empty stack!");
		exit(1);
	}
	else
		printf("Top element is %d\n", S->data);
}

void menu()
{
	printf("\n**************************************************\n");
	printf("\n********    Please enter your choice   ***********\n");
	printf("\n********    1 ---- Create linkstack    ***********\n");
	printf("\n********    2 ---- Push stack          ***********\n");
	printf("\n********    3 ---- Pop stack           ***********\n");
	printf("\n********    4 ---- Get top             ***********\n");
	printf("\n**************************************************\n");
}

int main()
{
	int choice, e;
	menu();
	while (1)
	{
		printf("\nPlease select function:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			creatstack();
			break;
		case 2:
			printf("Please enter number which you want to push stack£º");
			scanf("%d", &e);
			pushstack(e);
			break;
		case 3:
			popstack();
			break;
		case 4:
			gettop();
			break;
		}
	}
	return 0;
}

