//#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct linklist
//{
//	int data;
//	struct linklist* next;
//}linklist;
//
//linklist* head;
//
//void menu()
//{
//	printf("\n****************************************************************\n");
//	printf("\n***********            请输入你的选择                ***********\n");
//	printf("\n***********          1 ---- 建表                     ***********\n");
//	printf("\n***********          2 ---- 插入                     ***********\n");
//	printf("\n***********          3 ---- 删除                     ***********\n");
//	printf("\n***********          4 ---- 查找                     ***********\n");
//	printf("\n***********          5 ---- 取值                     ***********\n");
//	printf("\n***********          6 ---- 输出链表                 ***********\n");
//	printf("\n***********          0 ---- 退出                     ***********\n");
//	printf("\n****************************************************************\n");
//}
//
//linklist* createlist(int i)
//{
//	linklist* p;
//	linklist* r;
//	linklist* head;
//	head = (linklist*)malloc(sizeof(linklist));
//	head->next = NULL;
//	r = (linklist*)malloc(sizeof(linklist));
//	r = head;
//	int n;
//	printf("请输入数字：");
//	for (n = 0; n < i; n++)
//	{
//		p = (linklist*)malloc(sizeof(linklist));//为什么这里开辟一次，其他函数里用到p时就不用再开了
//		scanf("%d", &p->data);
//		r->next = p;//将r的空指针域与p的数据域相连没问题吗
//		r = p;
//	}
//	r->next = NULL;
//	printf("创建链表成功\n");
//	return head;
//}
//
//linklist* insertlist(linklist* head, int a, int e, int i)
//{
//	linklist* s = (linklist*)malloc(sizeof(linklist));
//	linklist* p = head;
//	s->next = NULL;//可有可无吗
//	s->data = e;
//	int j = 0;
//	if (a >= i || a < 0)
//	{
//		printf("插入位置输入错误！\n");
//		exit(1);
//	}
//	while (p != NULL)
//	{
//		if (j == a)
//		{
//			s->next = p->next;
//			p->next = s;
//		}
//		p = p->next;
//		j++;
//	}
//	printf("%d在第%d号位插入成功!\n", e, a);
//	return head;
//}
//
//linklist* detellist(linklist* head, int a, int i)
//{
//	linklist* p = head;
//	linklist* q = (linklist*)malloc(sizeof(linklist));
//	int j = 0;
//	if (a >= i || a < 0)
//	{
//		printf("删除位置输入错误！\n");
//		exit(1);
//	}
//	while (p != NULL)
//	{
//		if (j == a)
//		{
//			q = p->next;
//			p->next = q->next;
//		}
//		p = p->next;
//		j++;
//	}
//	printf("%d删除成功\n", q->data);
//	free(q);
//	return head;
//}
//
//linklist* searchlist(linklist* head,int e)
//{
//	linklist* p;
//	p = head->next;//与p=head输出的地址不同
//	while (p != NULL && p->data != e)
//	{
//		p = p->next;
//	}
//	if (p->data == e)
//		printf("%d的地址为：%p", e, p);
//	else//输入错误时走不到这一步
//	{
//		printf("查找数值输入错误！");
//		exit(1);
//	}
//	return head;
//}
//
//linklist* getlist(int i, int a)
//{
//	linklist* p;
//	p = head->next;
//	int j = 0;
//	if (a >= i || a < 0)
//	{
//		printf("取值位置输入错误！\n");
//		exit(1);
//	}
//	while (p != NULL && a != j ) 
//	{
//		p = p->next;
//		j++;
//	}
//	if (a == j)
//		printf("%d号位是%d", a, p->data);
//	return head;
//}
//
//linklist* inputlist(linklist* head)
//{
//	linklist* p = head;
//	p = head->next;
//	printf("顺序表里的元素有：\n");
//	while (p != NULL)
//	{
//		printf("%d   ", p->data);
//		p = p->next;
//	}
//	return head;
//}
//
//linklist* outlist(linklist* head)
//{
//	linklist* p = head;
//	linklist* d;
//	p = head->next;
//	while (p != NULL)
//	{
//		linklist* d = (linklist*)malloc(sizeof(linklist));
//		d = p;
//		p = p->next;
//		free(d);
//	}
//	printf("退出成功！");
//	return head;
//}
//
//int main()
//{
//	int i, a, e;
//	while (1)
//	{
//		menu();
//		int choice;
//		printf("请选择功能：");
//		scanf("%d", &choice);
//		switch (choice)
//		{
//		case 1:
//			printf("请输入创建的链表的长度：");
//			scanf("%d", &i);
//			head = createlist(i);//这个head和其他函数里传入的head一样吗，就是为了让其他函数里认识head，这里才用head接，还是用其他数接也没有问题
//			break;
//		case 2:
//			printf("请输入需要插入的位置：");
//			scanf("%d", &a);
//			printf("请输入需要插入的数字：");
//			scanf("%d", &e);
//			insertlist(head, a, e, i);//这里为什么不要一个值来接
//			break;
//		case 3:
//			printf("请输入需要删除的位置：");
//			scanf("%d", &a);
//			detellist(head, a, i);
//			break;
//		case 4:
//			printf("请输入需要查找地址的数：");
//			scanf("%d", &e);
//			searchlist(head, e);
//			break;
//		case 5:
//			printf("请输入需要取值的位置：");
//			scanf("%d", &a);
//			getlist(i, a);
//			break;
//		case 6:
//			inputlist(head);
//			break;
//		case 0: 
//			outlist(head);
//			break;
//		}
//	}
//	return 0;
//}
//
//
