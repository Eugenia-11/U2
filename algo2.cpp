#include<stdio.h>
#define MAX 5

void main()
{
	int bae[MAX][MAX] = { 0, }; // ������� �� �ִ� �迭
	int max_num = 0; // �ʱⰪ ����
	int count = 1; // ������� ��
	int temp = 0; // �迭 �� �ٲٱ�
	int num = 0; // �� �ݺ������� �ִ밪
	int i = 0;
	int j = 0;
	int count_max = MAX * 2; // �� �ݺ� Ƚ��




	while (i < count_max)
	{

		j = max_num; // �ݺ��� �ʱⰪ ����

		while (j <= num)
		{
			if ((i % 2) == 0)
			{
				bae[j][num - temp] = count;
			}
			else
			{
				bae[num - temp][j] = count;
			}

			count++;
			temp++;
			j++;
		}
		i++;
		temp = 0;

		if (i >= MAX)
		{
			num = MAX - 1;
			max_num++;
		}
		else
		{
			num++;
		}
	}

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			printf("%2d  ", bae[i][j]);
		}
		printf("\n");
	}
}


