#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct SqQueue
{
	int* base;
	int frount;
	int rear;
}SqQueue;

void Createqueue(SqQueue& Q)
{
	Q.base = (int*)malloc(sizeof(int) * 10);
	if (Q.base == NULL)
	{
		printf("Failed to allocate memory!");
		exit(1);
	}
	Q.frount = Q.rear = 0;
	printf("Create queue successfully!\n");
}

void Enqueue(SqQueue& Q, int e)
{
	if ((Q.rear + 1) % 10 == Q.frount)
	{
		printf("Full sqqueue£¡\n");
		exit(1);
	}
	Q.base[Q.rear] = e;
	printf("%d enter queue successfully!\n", e);
	Q.rear = (Q.rear + 1) % 10;
}

void Dequeue(SqQueue& Q)
{
	if (Q.frount == Q.rear)
	{
		printf("Empty queue£¡\n");
		exit(1);
	}
	int e = 0;
	e = Q.base[Q.frount];
	printf("%d delete successfully!\n", e);
	Q.frount = (Q.frount + 1) % 10;
}

void Gethead(SqQueue& Q)
{
	if (Q.frount == Q.rear)
	{
		printf("Empty queue!");
		exit(1);
	}
	printf("Head element is %d\n", Q.base[Q.frount]);
}

void QueueSize(SqQueue& Q)
{
	printf("QueueSize is %d\n", Q.rear - Q.frount);
}

void menu(void)
{
	printf("\n*********************************\n");
	printf("\n*****    1--- Create Queue  *****\n");
	printf("\n*****    2--- Enter         *****\n");
	printf("\n*****    3--- Delete        *****\n");
	printf("\n*****    4--- Get head      *****\n");
	printf("\n*****    5--- Queue Size    *****\n");
	printf("\n*********************************\n");
}

int main(void)
{
	SqQueue Q;
	int choice, e, t;
	menu();
	while (1)
	{
		printf("\nPlease select function:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Createqueue(Q);
			break;
		case 2:
			printf("Please enter the number which you want to enter£º");
			scanf("%d", &e);
			Enqueue(Q, e);
			break;
		case 3:
			Dequeue(Q);
			break;
		case 4:
			Gethead(Q);
			break;
		case 5:
			QueueSize(Q);
			break;
		}
	}
	return 0;
}