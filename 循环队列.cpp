#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct sqqueue
{
	int* base;
	int frount;
	int rear;
}sqqueue;

//ȫ������
sqqueue Q;

//��������
int createsqueue(sqqueue& Q)
{
	Q.base = (int*)malloc(sizeof(int) * 10);
	if (Q.base == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		exit(1);
	}
	Q.frount = Q.rear = 0;
	printf("�����ɹ���\n");
	return 0;
}

//�����
int insqqueue(sqqueue& Q,int e)
{
	if ((Q.rear + 1) % 10 == Q.frount)
	{
		printf("������\n");
		exit(1);
	}
	Q.base[Q.rear] = e;
	printf("%d��ӳɹ���\n", e);
	Q.rear = (Q.rear + 1) % 10;
	return 0;
}

//������
int outsqqueue(sqqueue& Q)
{
	if (Q.frount == Q.rear)
	{
		printf("�ӿգ�\n");
		exit(1);
	}
	int e = 0;
	e = Q.base[Q.frount];
	printf("%d���ӳɹ���\n", e);
	Q.frount = (Q.frount + 1) % 10;
	return 0;
}

//ȡ��ͷԪ��
int gethead(sqqueue& Q)
{
	if (Q.frount == Q.rear)
	{
		printf("�ӿգ�");
		exit(1);
	}
	printf("��ͷԪ��Ϊ��%d\n",Q.base[Q.frount]);
	return 0;
}

//��ӳ�
int queuelength(sqqueue& Q)
{
	printf("��ʱ�ӳ�Ϊ��%d\n", Q.rear - Q.frount);
	return 0;
}

//�˵�
void menu(void)
{
	printf("******************************\n");
	printf("***     1---��������      ****\n");
	printf("***     2---���          ****\n");
	printf("***     3---����          ****\n");
	printf("***     4---ȡ��ͷԪ��    ****\n");
	printf("***     5---��ӳ�        ****\n");
	printf("******************************\n");
}

//������
int main(void)
{
	int choice, e, t;
	menu();
	while (1)
	{
		printf("��ѡ���ܣ�");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			t = createsqueue(Q);
			break;
		case 2:
			printf("��������Ҫ��ӵ�����");
			scanf("%d", &e);
			t = insqqueue(Q, e);
			break;
		case 3:
			t = outsqqueue(Q);
			break;
		case 4:
			t = gethead(Q);
			break;
		case 5:
			t = queuelength(Q);
			break;
		}
	}
	return 0;
}