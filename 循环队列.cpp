#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct sqqueue
{
	int* base;
	int frount;
	int rear;
}sqqueue;

//全局声明
sqqueue Q;

//创建队列
int createsqueue(sqqueue& Q)
{
	Q.base = (int*)malloc(sizeof(int) * 10);
	if (Q.base == NULL)
	{
		printf("分配内存失败！");
		exit(1);
	}
	Q.frount = Q.rear = 0;
	printf("创建成功！\n");
	return 0;
}

//入队列
int insqqueue(sqqueue& Q,int e)
{
	if ((Q.rear + 1) % 10 == Q.frount)
	{
		printf("队满！\n");
		exit(1);
	}
	Q.base[Q.rear] = e;
	printf("%d入队成功！\n", e);
	Q.rear = (Q.rear + 1) % 10;
	return 0;
}

//出队列
int outsqqueue(sqqueue& Q)
{
	if (Q.frount == Q.rear)
	{
		printf("队空！\n");
		exit(1);
	}
	int e = 0;
	e = Q.base[Q.frount];
	printf("%d出队成功！\n", e);
	Q.frount = (Q.frount + 1) % 10;
	return 0;
}

//取队头元素
int gethead(sqqueue& Q)
{
	if (Q.frount == Q.rear)
	{
		printf("队空！");
		exit(1);
	}
	printf("队头元素为：%d\n",Q.base[Q.frount]);
	return 0;
}

//求队长
int queuelength(sqqueue& Q)
{
	printf("此时队长为：%d\n", Q.rear - Q.frount);
	return 0;
}

//菜单
void menu(void)
{
	printf("******************************\n");
	printf("***     1---创建队列      ****\n");
	printf("***     2---入队          ****\n");
	printf("***     3---出队          ****\n");
	printf("***     4---取对头元素    ****\n");
	printf("***     5---求队长        ****\n");
	printf("******************************\n");
}

//主函数
int main(void)
{
	int choice, e, t;
	menu();
	while (1)
	{
		printf("请选择功能：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			t = createsqueue(Q);
			break;
		case 2:
			printf("请输入需要入队的数：");
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