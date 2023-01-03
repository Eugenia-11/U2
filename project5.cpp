#include <stdio.h>

int arr[5][5];    // ������ �迭
int lens[60];       // �� ���庰 ������ ���� (0�������)
int xt = -1, yt = 0;   // ���� ��ġ(0,0���� �������� ��ĭ ����)
int direction = 0;  // 0:��, 1:��, 2:��, 3:��
int round = 0;      // �� �������� (0 ~ (size+size-1)��)
int num;            // ��� ���� (max ~ 1 �Ǵ� 1~ max)
int size;           // ���簢�� �迭 �Ѻ� ũ��



// ���� ���� ���⿡ �°� xp, yp �� ����
void move(int direct)
{
	switch (direct) {
	case 0: xt++;  break;
	case 1: yt++;  break;
	case 2: xt--;  break;
	case 3: yt--;  break;
	}
}

// arr �迭 ������ ���
void print_box(int size)
{
	int x, y;
	printf("\n");
	for (y = 0; y < size; y++) {
		for (x = 0; x < size; x++)
			printf("%3d ", arr[y][x]);
		printf("\n");
	}
}



int main()
{
	int i, j;
	int size = 5;
	num = size * size;  // ��¿� ����� ���� ���

	// ���庰 ���� ���� ��� (3�̸� 3, 2, 2, 1, 1, 0 )
	for (i = 0, j = size; j >= 0; i += 2, j--) {
		lens[i] = j;
		lens[i + 1] = j - 1;
	}

	// ���� ȸ����ŭ �ݺ�...
	while (round < size + size - 1) {   //1,3,5,7, (nth = size+size-1)
	  // �� ���庰 ��� ó��
		for (i = 0; i < lens[round]; i++) {
			move(direction);        // ���⿡ �°� xp, yp ��ġ ����
			arr[yt][xt] = num--;   // �� ��ġ�� ���� ����ϰ� -1
		}
		round++;                  // ���� ����
		direction = (direction + 1) % 4; //���� ����(0:��,1:��,2:��,3:��)
	}

	print_box(size);       // ���� ����� ȭ�鿡  ���
	return 0;
}