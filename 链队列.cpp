#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct linkqueue
{
	int data;
	struct linkqueue* next;
}linkqueue;

typedef struct node
{
	linkqueue* frount;
	linkqueue* rear;
}node;

void creatqueue(linkqueue& Q,node& N)
{
	linkqueue* p;
	p = (linkqueue*)malloc(sizeof(linkqueue));
	p->next = NULL;
	N.frount = N.rear = p;
	printf("�����ɹ���\n");
}

void enqueue(linkqueue& Q, node& N, int e)
{
	linkqueue* p;
	p = (linkqueue*)malloc(sizeof(linkqueue));
	p->data = e;
	N.rear->next = p;
	N.rear = p;
	printf("%d��ӳɹ���\n", e);
}

void dequeue(linkqueue& Q, node& N)
{
	if (N.frount == N.rear)
	{
		printf("����Ϊ�գ�");
		exit(1);
	}
	linkqueue* p;
	p = (linkqueue*)malloc(sizeof(linkqueue));
	p = N.frount->next;
	N.frount->next = p->next;
	if (N.rear == p)
		N.frount = N.rear;
	printf("%d���ӳɹ���\n",p->data);
	free(p);
}

void gethead(linkqueue& Q, node& N)
{
	if (N.frount == N.rear)
	{
		printf("����Ϊ�գ�");
		exit(1);
	}
	else
		printf("��ͷԪ��Ϊ��%d\n", N.frount->next->data);
}

void menu(void)
{
	printf("*******************************************\n");
	printf("******        ���������ѡ��        *******\n");
	printf("******       1 ---- ����������      *******\n");
	printf("******       2 ---- �����          *******\n");
	printf("******       3 ---- ������          *******\n");
	printf("******       4 ---- ȡͷԪ��        *******\n");
	printf("*******************************************\n");
}

int main(void)
{
	int e;
	linkqueue Q;
	node N;
	menu();
	while (1)
	{
		int choice;
		printf("������ѡ��");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			creatqueue(Q, N);
			break;
		case 2:
			printf("����������е�����");
			scanf("%d", &e);
			enqueue(Q, N, e);
			break;
		case 3:
			dequeue(Q, N);
			break;
		case 4:
			gethead(Q, N);
			break;
		}
	}
	return 0;
}