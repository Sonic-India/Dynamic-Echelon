//This is Essential part of Matrix
//Here the Memory Allocation, Inputting of Matrix and Printing of Matrix is Done
//Core Echelon Processing is done in echelon.c
#include <stdio.h>
#include <stdlib.h>
#include"mat.h"

//Dynamic Memory Allocation
void **CreateMatrix(int rows, int cols)
{
	float **matrix = (float*) malloc(sizeof(float*) *((float) rows));
	int i;
	for (i = 0; i < rows; i++)
	{
		matrix[i] = (float*) malloc(sizeof(float) *((float) cols));
	}

	return matrix;
}

//Inputting of Matrix
void MatrixInput(float **matrix, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("\n Enter element[%d][%d] :", i, j);
			scanf("%f", &matrix[i][j]);
		}
	}
}

//Printing of Matrix
void PrintMatrix(float **matrix, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%f ", matrix[i][j]);
		}

		printf("\n");
	}
}