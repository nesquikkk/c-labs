#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#define t 100
int combination(int k, int n, int **array)
{
	if (array[n][k] != -1)
		return array[n][k];
	if (k == 0) {
		array[n][k] = 1;
		return 1;
	}
	else if (k == n) {
		array[n][k] = 1;
		return 1;
	}
	else if (k > n) {
		array[n][k] = 0;
		return 0;
	}
	else {
		array[n][k] = combination(k - 1, n - 1, array) + combination(k, n - 1, array);
		return combination(k - 1, n - 1, array) + combination(k, n - 1, array);
	}
}
int main()
{
	int **array = (int**)malloc(t * sizeof(int));
	int k, n;
	for (int i = 0; i < t; i++) {
		array[i] = (int*)malloc(t * sizeof(int));
		memset(array[i], -1, t * sizeof(int));
	}
	scanf_s("%d%d", &k, &n);
	printf("%d", combination(k, n, array));
	for (int i = 0; i < t; i++) {
		free(array[i]);
	}
	free(array);
	getchar();
	getchar();

	return 0;
}
