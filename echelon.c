//This is were Matrix is Solved for Echelon form in Simple Elimination Technique 
//This Code is  is licensed under the MIT LICENSE
//Copyright (c) 2020 Sonic-India
#include <stdio.h>
#include <stdlib.h>
#include"addons/frac.hpp"
#include"addons/frac.cpp"
#include"mat.h"
#include"mat.c"

//Here is an example how you can use this Library
/*
void main()
{
  int m,n;
  printf("\n Enter number of Rows : ");
  scanf("%d", &m);
  printf("\n Enter number of Columns : ");
  scanf("%d", &n);
  echelon(m,n);
}*/

//echelon() takes two parameters as input Rows(m) &Columns(n)
void echelon(int m, int n)
{
	float **a;
	float **b;
	int i, j, r, k, c, d, x;
	float y, z, temp;
	a = CreateMatrix(m, n);	//Here Required Memory Allocation is Done
	b = CreateMatrix(m, n);
	MatrixInput(a, m, n);	//Matrix Input is Done after Memory Allocation is Done

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			b[i][j] = a[i][j];
		}
	}

	printf("\n******Inputed Matrix is******\n\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			x = (int) b[i][j];
			y = b[i][j];
			z = b[i][j];
			y = y - x;
			if (y == 0)
				printf("       %d", x);
			else
				frac(z);
			//printf("       %f",z);
		}

		printf("\n");
	}

	printf("\n\n");
	for (c = 0; c < (m - 1); c++)
	{
		if (b[c][c] == 0)
		{
			for (d = 0; d < (m - c - 1); d++)
			{
				if (b[c + d + 1][c] != 0)
				{
					for (j = 0; j < n; j++)
					{
						temp = b[c + d + 1][j];
						b[c + d + 1][j] = b[c][j];
						b[c][j] = temp;
					}
				}
				else
					continue;
				break;
			}
		}

		for (r = 0; r < m; r++)
		{
			for (k = 0; k < n; k++)
			{
				a[r][k] = b[r][k];
			}
		}

		for (d = 0; d < (m - c - 1); d++)
		{
			if (a[c + d + 1][c] != 0)
			{
				for (j = 0; j < n; j++)
				{
					a[c + d + 1][j] = (b[c + d + 1][j]) - ((b[c + d + 1][c] / b[c][c]) *b[c][j]);
				}
			}

			for (r = 0; r < m; r++)
			{
				for (k = 0; k < n; k++)
				{
					b[r][k] = a[r][k];
				}
			}

			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					x = (int) b[i][j];
					y = b[i][j];
					z = b[i][j];
					y = y - x;
					if (y == 0)
						printf("       %d", x);
					else
						printf("       %f", z);
				}

				printf("\n");
			}

			printf("\n\n");
		}
	}

	//Final Printing of Matrix   
	printf("*****Echelon Form*****\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			x = (int) b[i][j];
			y = b[i][j];
			z = b[i][j];
			y = y - x;
			if (y == 0)
				printf("       %d", x);
			else
				frac(z);
			//printf("       %d",z);
		}

		printf("\n");
	}
}
