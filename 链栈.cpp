#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef  struct linkstack
{
	int  data;
	struct linkstack* next;
}linkstack;

linkstack* SF;

void creatstack()
{
	SF = (linkstack*)malloc(sizeof(linkstack));
	SF = NULL;
	printf("������ջ�ɹ���\n");
}

void pushstack(int e)
{
	linkstack* p;
	p = (linkstack*)malloc(sizeof(linkstack));
	p->data = e;
	p->next = SF;
	SF = p;
	printf("%d��ջ�ɹ���\n", e);
}

void popstack()
{
	linkstack* p;
	p = (linkstack*)malloc(sizeof(linkstack));
	if (SF == NULL)
	{
		printf("ջ�գ�");
		exit(1);
	}
	p = SF;
	printf("%d��ջ�ɹ���\n", p->data);
	SF = SF->next;
	free(p);
}

void gettop()
{
	if (SF == NULL)
	{
		printf("ջ�գ�");
		exit(1);
	}
	else
		printf("ջ��Ԫ��Ϊ��%d\n", SF->data);
}

void menu()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~         ���������ѡ��         ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~        1 ---- ������ջ         ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~        2 ---- ѹԪ����ջ       ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~        3 ---- Ԫ�س�ջ         ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~       4 ---- ȡֵջ��Ԫ��      ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int main()
{
	int choice, e;
	menu();
	while (1)
	{
		printf("��ѡ���ܣ�");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			creatstack();
			break;
		case 2:
			printf("��������Ҫ��ջ������");
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
