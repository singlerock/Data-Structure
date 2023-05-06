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
	printf("\n***********            请输入你的选择                ***********\n");
	printf("\n***********          1 ---- 创建顺序表               ***********\n");
	printf("\n***********          2 ---- 插入                     ***********\n");
	printf("\n***********          3 ---- 删除                     ***********\n");
	printf("\n***********          4 ---- 取值                     ***********\n");
	printf("\n***********          5 ---- 查询                     ***********\n");
	printf("\n***********          6 ---- 输出顺序表               ***********\n");
	printf("\n***********          0 ---- 退出                     ***********\n");
	printf("\n****************************************************************\n");
}

void listcreat(sqlist &L)
{
	L.arr = (int *)malloc(10*sizeof(int));
	int i;
	printf("请输入创建的顺序表的长度");
	scanf("%d", &L.length);
	printf("请输入数字：");
	for (i = 0; i < L.length; i++)
	{
		scanf("%d", &L.arr[i]);
	}
}

void listinsert(sqlist& L,int e,int i)
{
	if (i < 0 || i>L.length + 1)
	{
		printf("插入失败!\n");
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
	printf("请输入需要查询位置：");
	scanf("%d", &e);
	for (i = 0; i < L.length; i++)
	{
		if (e == L.arr[i])
			printf("%d", i+2);
	}
}

void listinput(sqlist& L)
{
	printf("顺序表里的元素有：\n");
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("%d       ", L.arr[i]);
	}
}

void listout(sqlist& L)
{
	free(L.arr);
	printf("退出成功!\n");
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
			printf("创建链表成功!\n");
			break;
	    case 2: 
			printf("请输入您要插入的位置\n");
			scanf("%d", &i);
			printf("请输入您要插入的元素\n");
			scanf("%d", &e);
			printf("插入成功\n");
			listinsert(L,e,i);
			break;
	    case 3: 
			printf("请输入要删除的位置\n");
			scanf("%d", &i);
			printf("删除成功!\n");
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
