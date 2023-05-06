#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct sqlist
{
	int* arr;
	int length;
}sqlist;

void menu()
{
	printf("\n****************************************************************\n");
	printf("\n***********            ���������ѡ��                ***********\n");
	printf("\n***********          1 ---- ����˳���               ***********\n");
	printf("\n***********          2 ---- ����                     ***********\n");
	printf("\n***********          3 ---- ɾ��                     ***********\n");
	printf("\n***********          4 ---- ȡֵ                     ***********\n");
	printf("\n***********          5 ---- ��ѯ                     ***********\n");
	printf("\n***********          6 ---- ���˳���               ***********\n");
	printf("\n***********          0 ---- �˳�                     ***********\n");
	printf("\n****************************************************************\n");
}

void listcreat(sqlist &L)
{
	L.arr = (int *)malloc(10*sizeof(int));
	int i;
	printf("�����봴����˳���ĳ���");
	scanf("%d", &L.length);
	printf("���������֣�");
	for (i = 0; i < L.length; i++)
	{
		scanf("%d", &L.arr[i]);
	}
}

void listinsert(sqlist& L,int e,int i)
{
	if (i < 0 || i>L.length + 1)
	{
		printf("����ʧ��!\n");
		exit(1);
	}
	int j;
	for (j = L.length - 1; j >= i - 1; j--)
	{
		L.arr[j + 1] = L.arr[j];
    }
	L.arr[i] = e;
	L.length++;
}

void listdetel(sqlist& L,int i)
{
	int j;
	if (i < 0 || i > L.length) 
		exit(1);
	for (j = i + 1; j <= L.length; j++)
	{
		L.arr[j - 1] = L.arr[j];
	}
	--L.length;
}

void getlist(sqlist& L)
{
	int i = 0;
	int e;
	if (i<0 || i>L.length)
		exit(1);
	printf("��������Ҫ��ѯλ�ã�");
	scanf("%d", &e);
	for (i = 0; i < L.length; i++)
	{
		if (e == L.arr[i])
			printf("%d", i+2);
	}
}

void listinput(sqlist& L)
{
	printf("˳������Ԫ���У�\n");
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("%d       ", L.arr[i]);
	}
}

void listout(sqlist& L)
{
	free(L.arr);
	printf("�˳��ɹ�!\n");
}

int main()
{
	sqlist L;
	while (1)
	{
		menu();
		int choice, i, e;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: 
			listcreat(L);
			printf("��������ɹ�!\n");
			break;
	    case 2: 
			printf("��������Ҫ�����λ��\n");
			scanf("%d", &i);
			printf("��������Ҫ�����Ԫ��\n");
			scanf("%d", &e);
			printf("����ɹ�\n");
			listinsert(L,e,i);
			break;
	    case 3: 
			printf("������Ҫɾ����λ��\n");
			scanf("%d", &i);
			printf("ɾ���ɹ�!\n");
			listdetel(L, i);
			break;
		case 4:
			getlist(L);
			break;
		case 5:
			break;
		case 6: 
			listinput(L);
			break;
	    case 0: listout(L);
			break;
		}
	}
	return 0;
}
