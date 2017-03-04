#include "stdafx.h"
#include <stdlib.h>


int cmp(void const* a, void const* b)
{		
		return  *((int*)a) - *((int*)b);
}

int main()
{
	int size;
	scanf_s("%d", &size);
	int* mas = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
		mas[i] = rand();
	for (int i = 0; i < size; i++)
	{
		printf("%d ", mas[i]);
	}
	printf("\n");
	qsort(mas, size, sizeof(int), cmp);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", mas[i]);
	}
	getchar();
	getchar();
	free(mas);
	return 0;
}

