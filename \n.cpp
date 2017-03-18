#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void openFiles(int argc, char * argv[], FILE **input, FILE **output);
void closeFiles(int argc, char * argv[], FILE **input, FILE **output);
void readString(char *A, FILE *input);
int strstrn(char *A, char *B);

int main(int argc, char *argv[]) {
	FILE *input, *output;
	char A[100], B[100];
	input = NULL;
	output = NULL;

	openFiles(argc, argv, &input, &output);
	readString(A, input);
	readString(B, input);
	char* temp;
	int t = 0;
	temp = strstr(A, B);

	while (temp)
	{
		temp = strstr(temp + 1, B);
		t++;
	}

	fprintf (output, "A: %s Length A: %d\nB:%s Length B: %d\n", A, strlen(A), B, strlen(B));
	fprintf (output, "%d\n", t);
	//printf("%d\n",strstrn(B,A));
	closeFiles(argc, argv, &input, &output);
	getchar();
	return 0;
}

void openFiles(int argc, char * argv[], FILE **input, FILE **output)
{
	if (argc>1)
	{
		for (int i = 1; i<argc; i++)
		{
			if (!strcmp(argv[i], "-input") && argc >= i + 2)
			{
				if (strcmp(argv[i + 1], "-output"))
				{
					*input = fopen(argv[i + 1], "r");
				}
			}
			else if (!strcmp(argv[i], "-output") && argc >= i + 2)
			{
				if (strcmp(argv[i + 1], "-input"))
				{
					*output = fopen(argv[i + 1], "w");
				}
			}
		}
	}
}

void closeFiles(int argc, char * argv[], FILE **input, FILE **output)
{
	if (*input != NULL)
	{
		fclose(*input);
	}
	if (*output != NULL)
	{
		fclose(*output);
	}
}

void readString(char *A, FILE *input)
{
	if (input == NULL)
	{
		printf("Enter string : ");
		fgets(A, 98, stdin);
	}
	else
	{
		fgets(A, 98, input);
	}
	if (A[strlen(A) - 1] == '\n')
	{
		A[strlen(A) - 1] = '\0';
	}
}

int strstrn(char *B, char *A)
{
	char *temp = strstr(B, A);
	int length = temp - B;
	printf("Length: %d\n", length);
	printf("B:%s\nTemp: %s\n", B, temp);
	if (temp == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + strstrn(strstr(B, A) + 1, A);
	}
}
