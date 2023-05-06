#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkQueue
{
	int data;
	struct LinkQueue* next;
}LinkQueue;

typedef struct Node
{
	LinkQueue* frount;
	LinkQueue* rear;
}Node;

void CreatQueue(LinkQueue& Q, Node& N)
{
	LinkQueue* p;
	p = (LinkQueue*)malloc(sizeof(LinkQueue));
	p->next = NULL;
	N.frount = N.rear = p;
	printf("Create queue successfully!\n");
}

void EnQueue(LinkQueue& Q, Node& N, int e)
{
	LinkQueue* p;
	p = (LinkQueue*)malloc(sizeof(LinkQueue));
	p->data = e;
	N.rear->next = p;
	N.rear = p;
	printf("%d enter queue successfully!\n", e);
}

void DeQueue(LinkQueue& Q, Node& N)
{
	if (N.frount == N.rear)
	{
		printf("Empty queue!");
		exit(1);
	}
	LinkQueue* p;
	p = (LinkQueue*)malloc(sizeof(LinkQueue));
	p = N.frount->next;
	N.frount->next = p->next;
	if (N.rear == p)
		N.frount = N.rear;
	printf("%d delete successfully!\n", p->data);
	free(p);
}

void GetHead(LinkQueue& Q, Node& N)
{
	if (N.frount == N.rear)
	{
		printf("Empty queue!");
		exit(1);
	}
	else
		printf("Head element is %d\n", N.frount->next->data);
}

void menu(void)
{
	printf("\n**********************************************\n");
	printf("\n******     Please enter your choice    *******\n");
	printf("\n******     1 ---- Create link queue    *******\n");
	printf("\n******     2 ---- Enter                *******\n");
	printf("\n******     3 ---- Delete               *******\n");
	printf("\n******     4 ---- Gethead              *******\n");
	printf("\n**********************************************\n");
}

int main(void)
{
	int e;
	LinkQueue Q;
	Node N;
	menu();
	while (1)
	{
		int choice;
		printf("\nPlease select function:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			CreatQueue(Q, N);
			break;
		case 2:
			printf("Please enter the number which you want to enter:");
			scanf("%d", &e);
			EnQueue(Q, N, e);
			break;
		case 3:
			DeQueue(Q, N);
			break;
		case 4:
			GetHead(Q, N);
			break;
		}
	}
	return 0;
}
