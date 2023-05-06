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
	printf("创建链栈成功！\n");
}

void pushstack(int e)
{
	linkstack* p;
	p = (linkstack*)malloc(sizeof(linkstack));
	p->data = e;
	p->next = SF;
	SF = p;
	printf("%d入栈成功！\n", e);
}

void popstack()
{
	linkstack* p;
	p = (linkstack*)malloc(sizeof(linkstack));
	if (SF == NULL)
	{
		printf("栈空！");
		exit(1);
	}
	p = SF;
	printf("%d出栈成功！\n", p->data);
	SF = SF->next;
	free(p);
}

void gettop()
{
	if (SF == NULL)
	{
		printf("栈空！");
		exit(1);
	}
	else
		printf("栈顶元素为：%d\n", SF->data);
}

void menu()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~         请输入你的选择         ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~        1 ---- 创建链栈         ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~        2 ---- 压元素入栈       ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~        3 ---- 元素出栈         ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~       4 ---- 取值栈顶元素      ~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int main()
{
	int choice, e;
	menu();
	while (1)
	{
		printf("请选择功能：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			creatstack();
			break;
		case 2:
			printf("请输入需要入栈的数：");
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
