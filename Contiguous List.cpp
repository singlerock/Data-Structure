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

void createlist(sqlist& L)
{
	L.arr = (int*)malloc(10 * sizeof(int));
	int i;
	printf("Please enter the length of the list to be created£º");
	scanf("%d", &L.length);
	printf("Please enter the numbers:");
	for (i = 0; i < L.length; i++)
	{
		scanf("%d", &L.arr[i]);
	}
	printf("List created successfully!\n");
}

void insert(sqlist& L)
{
	int i;
	printf("Please enter where you want to insert:");
	scanf("%d", &i);
	if (i < 0 || i >= L.length)
	{
		printf("Insert failed because the entered position is incorrect!\n");
		exit(1);
	}
	int j;
	int e;
	printf("Please enter the number you want to insert:");
	scanf("%d", &e);
	for (j = L.length - 1; j >= i - 1; j--)
	{
		L.arr[j + 1] = L.arr[j];
	}
	L.arr[i] = e;
	L.length++;
	printf("inserted Successfully!\n");
}

void detel(sqlist& L)
{
	int i, e;
	printf("Please enter the location you want to delete:");
	scanf("%d", &i);
	int j;
	if (i < 0 || i >= L.length)
	{
		printf("Failed to delete due to incorrect entered location£¡");
		exit(1);
	}
	e = L.arr[i];
	for (j = i + 1; j <= L.length; j++)
	{
		L.arr[j - 1] = L.arr[j];
	}
	L.length--;
	printf("%dDeleted successfully!\n", e);
}

void search(sqlist& L)
{
	int e;
	int i;
	printf("Enter the number of location you want to search:");
	scanf("%d", &e);
	for (i = 0; i <= L.length; i++)
	{
		if (e == L.arr[i])
			printf("The position of %d is %d", e, i);
	}
}

void getposition(sqlist& L)
{
	int e;
	int i;
	printf("Please enter the position of the number you want to getposition:");
	scanf("%d", &e);
	if (e < 0 || e >= L.length)
	{
		printf("The entered position is incorrect. The getposition failed!");
		exit(1);
	}
	for (i = 0; i < L.length; i++)
	{
		if (e == i)
			printf("The %d position is %d", e, L.arr[i]);
	}
}

void output(sqlist& L)
{
	printf("The elements in the list are:\n");
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("%d       ", L.arr[i]);
	}
}

void exit(sqlist& L)
{
	free(L.arr);
	printf("Exit successfully!\n");
}

int main()
{
	sqlist L;
	menu();
	while (1)
	{
		int choice, i, e;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			createlist(L);
			break;
		case 2:
			insert(L);
			break;
		case 3:
			detel(L);
			break;
		case 4:
			search(L);
			break;
		case 5:
			getposition(L);
			break;
		case 6:
			output(L);
			break;
		case 0: exit(L);
			break;
		}
	}
	return 0;
}

