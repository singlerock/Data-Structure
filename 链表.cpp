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
//	printf("\n***********            ���������ѡ��                ***********\n");
//	printf("\n***********          1 ---- ����                     ***********\n");
//	printf("\n***********          2 ---- ����                     ***********\n");
//	printf("\n***********          3 ---- ɾ��                     ***********\n");
//	printf("\n***********          4 ---- ����                     ***********\n");
//	printf("\n***********          5 ---- ȡֵ                     ***********\n");
//	printf("\n***********          6 ---- �������                 ***********\n");
//	printf("\n***********          0 ---- �˳�                     ***********\n");
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
//	printf("���������֣�");
//	for (n = 0; n < i; n++)
//	{
//		p = (linklist*)malloc(sizeof(linklist));//Ϊʲô���￪��һ�Σ������������õ�pʱ�Ͳ����ٿ���
//		scanf("%d", &p->data);
//		r->next = p;//��r�Ŀ�ָ������p������������û������
//		r = p;
//	}
//	r->next = NULL;
//	printf("��������ɹ�\n");
//	return head;
//}
//
//linklist* insertlist(linklist* head, int a, int e, int i)
//{
//	linklist* s = (linklist*)malloc(sizeof(linklist));
//	linklist* p = head;
//	s->next = NULL;//���п�����
//	s->data = e;
//	int j = 0;
//	if (a >= i || a < 0)
//	{
//		printf("����λ���������\n");
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
//	printf("%d�ڵ�%d��λ����ɹ�!\n", e, a);
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
//		printf("ɾ��λ���������\n");
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
//	printf("%dɾ���ɹ�\n", q->data);
//	free(q);
//	return head;
//}
//
//linklist* searchlist(linklist* head,int e)
//{
//	linklist* p;
//	p = head->next;//��p=head����ĵ�ַ��ͬ
//	while (p != NULL && p->data != e)
//	{
//		p = p->next;
//	}
//	if (p->data == e)
//		printf("%d�ĵ�ַΪ��%p", e, p);
//	else//�������ʱ�߲�����һ��
//	{
//		printf("������ֵ�������");
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
//		printf("ȡֵλ���������\n");
//		exit(1);
//	}
//	while (p != NULL && a != j ) 
//	{
//		p = p->next;
//		j++;
//	}
//	if (a == j)
//		printf("%d��λ��%d", a, p->data);
//	return head;
//}
//
//linklist* inputlist(linklist* head)
//{
//	linklist* p = head;
//	p = head->next;
//	printf("˳������Ԫ���У�\n");
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
//	printf("�˳��ɹ���");
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
//		printf("��ѡ���ܣ�");
//		scanf("%d", &choice);
//		switch (choice)
//		{
//		case 1:
//			printf("�����봴��������ĳ��ȣ�");
//			scanf("%d", &i);
//			head = createlist(i);//���head�����������ﴫ���headһ���𣬾���Ϊ����������������ʶhead���������head�ӣ���������������Ҳû������
//			break;
//		case 2:
//			printf("��������Ҫ�����λ�ã�");
//			scanf("%d", &a);
//			printf("��������Ҫ��������֣�");
//			scanf("%d", &e);
//			insertlist(head, a, e, i);//����Ϊʲô��Ҫһ��ֵ����
//			break;
//		case 3:
//			printf("��������Ҫɾ����λ�ã�");
//			scanf("%d", &a);
//			detellist(head, a, i);
//			break;
//		case 4:
//			printf("��������Ҫ���ҵ�ַ������");
//			scanf("%d", &e);
//			searchlist(head, e);
//			break;
//		case 5:
//			printf("��������Ҫȡֵ��λ�ã�");
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
