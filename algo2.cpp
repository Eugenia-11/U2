#include<stdio.h>
#define MAX 5

void main()
{
	int bae[MAX][MAX] = { 0, }; // 지그재그 값 넣는 배열
	int max_num = 0; // 초기값 지정
	int count = 1; // 지그재그 값
	int temp = 0; // 배열 값 바꾸기
	int num = 0; // 각 반복에서의 최대값
	int i = 0;
	int j = 0;
	int count_max = MAX * 2; // 총 반복 횟수




	while (i < count_max)
	{

		j = max_num; // 반복의 초기값 지정

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


