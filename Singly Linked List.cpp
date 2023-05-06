#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int data;
	struct linklist* next;
}linklist;

linklist* head;

void menu()
{
	printf("\n*************************************************************\n");
	printf("\n***********        Please enter your choice      ***********\n");
	printf("\n***********          1 ---- createlist           ***********\n");
	printf("\n***********          2 ---- insert               ***********\n");
	printf("\n***********          3 ---- detel                ***********\n");
	printf("\n***********          4 ---- sreach               ***********\n");
	printf("\n***********          5 ---- getposition          ***********\n");
	printf("\n***********          6 ---- output               ***********\n");
	printf("\n***********          0 ---- exit                 ***********\n");
	printf("\n************************************************************\n");
}

linklist* createlist(int i)
{
	linklist* p;
	linklist* r;
	linklist* head;
	head = (linklist*)malloc(sizeof(linklist));
	head->next = NULL;
	r = (linklist*)malloc(sizeof(linklist));
	head = r;
	int n;
	printf("Please enter the number:");
	for (n = 0; n < i; n++)
	{
		p = (linklist*)malloc(sizeof(linklist));
		scanf("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
	printf("List created successfully!\n");
	return head;
}

linklist* insert(linklist* head, int a, int e, int i)
{
	linklist* s = (linklist*)malloc(sizeof(linklist));
	linklist* p = head;
	s->next = NULL;
	s->data = e;
	int j = 0;
	if (a >= i || a < 0)
	{
		printf("The insertion position was entered incorrectly!\n");
		exit(1);
	}
	while (p != NULL)
	{
		if (j == a)
		{
			s->next = p->next;
			p->next = s;
		}
		p = p->next;
		j++;
	}
	i++;
	printf("%d successfully inserted in position %d!\n", e, a);
	return head;
}

linklist* detel(linklist* head, int a, int i)
{
	linklist* p = head;
	linklist* q = (linklist*)malloc(sizeof(linklist));
	int j = 0;
	if (a > i || a < 0)
	{
		printf("The deletion location was incorrectly entered!\n");
		exit(1);
	}
	while (p != NULL)
	{
		if (j == a)
		{
			q = p->next;
			p->next = q->next;
		}
		p = p->next;
		j++;
	}
	printf("%d deleted successfully \n", q->data);
	free(q);
	return head;
}

linklist* search(linklist* head, int e)
{
	linklist* p;
	p = head->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	if (p->data == e)
		printf("The address of %d is:%p", e, p);
	else
	{
		printf("The number sought was entered incorrectly!");
		exit(1);
	}
	return head;
}

linklist* getposition(int i, int a)
{
	linklist* p;
	p = head->next;
	int j = 0;
	if (a >= i || a < 0)
	{
		printf("The getlocation is incorrect!\n");
		exit(1);
	}
	while (p != NULL && a != j)
	{
		p = p->next;
		j++;
	}
	if (a == j)
		printf("Position %d is %d", a, p->data);
	return head;
}

linklist* output(linklist* head)
{
	linklist* p = head;
	p = head->next;
	printf("The elements in the list are:\n");
	while (p != NULL)
	{
		printf("%d   ", p->data);
		p = p->next;
	}
	return head;
}

linklist* exit(linklist* head)
{
	linklist* p = head;
	linklist* d;
	p = head->next;
	while (p != NULL)
	{
		linklist* d = (linklist*)malloc(sizeof(linklist));
		d = p;
		p = p->next;
		free(d);
	}
	printf("Exit successfully!");
	return head;
}

int main()
{
	int i, a, e;
	while (1)
	{
		menu();
		int choice;
		printf("Please select function:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Please enter the length of the list to be created:");
			scanf("%d", &i);
			head = createlist(i);
			break;
		case 2:
			printf("Please enter where you want to insert:");
			scanf("%d", &a);
			printf("Please enter the number you want to insert:");
			scanf("%d", &e);
			head = insert(head, a, e, i);
			break;
		case 3:
			printf("Please enter the location you want to delete:");
			scanf("%d", &a);
			head = detel(head, a, i);
			break;
		case 4:
			printf("Please enter the number of addresses you want to search:");
			scanf("%d", &e);
			head = search(head, e);
			break;
		case 5:
			printf("Please enter the position of addresses you want to get£º");
			scanf("%d", &a);
			head = getposition(i, a);
			break;
		case 6:
			head = output(head);
			break;
		case 0:
			head = exit(head);
			break;
		}
	}
	return 0;
}
