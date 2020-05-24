#include <stdio.h>
#include"echelon.h"
#include"echelon.c"

void main()
{
	int m, n;
	printf("\n Enter number of Rows : ");
	scanf("%d", &m);
	printf("\n Enter number of Columns : ");
	scanf("%d", &n);
	echelon(m, n);
}