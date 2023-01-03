#include <stdio.h>

void main()
{
	int a[5][5] = { 0 };
	int i, j, nxt = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j <= i; j++)
		{
			nxt++;
			a[i - j][j] = nxt;
		}
	}
	for (i = 1; i < 5; i++)
	{
		for (j = i; j < 5; j++)
		{
			nxt++;
			a[i - j + 5 - 1][j]= nxt;
		}
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a[i][j] == 0)
			{
				printf("   ");
			}
			else
			{
				printf("%3d", a[i][j]);
			}
		}
		printf("\n");
	}
}

