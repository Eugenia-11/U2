#include <stdio.h>

int arr[5][5];    // 저장할 배열
int lens[60];       // 각 라운드별 진행할 개수 (0라운드부터)
int xt = -1, yt = 0;   // 시작 위치(0,0에서 왼쪽으로 한칸 이전)
int direction = 0;  // 0:동, 1:남, 2:서, 3:북
int round = 0;      // 몇 라운드인지 (0 ~ (size+size-1)차)
int num;            // 출력 숫자 (max ~ 1 또는 1~ max)
int size;           // 정사각형 배열 한변 크기



// 현재 진행 방향에 맞게 xp, yp 값 변경
void move(int direct)
{
	switch (direct) {
	case 0: xt++;  break;
	case 1: yt++;  break;
	case 2: xt--;  break;
	case 3: yt--;  break;
	}
}

// arr 배열 정보를 출력
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
	num = size * size;  // 출력에 사용할 숫자 계산

	// 라운드별 진행 개수 계산 (3이면 3, 2, 2, 1, 1, 0 )
	for (i = 0, j = size; j >= 0; i += 2, j--) {
		lens[i] = j;
		lens[i + 1] = j - 1;
	}

	// 라운드 회차만큼 반복...
	while (round < size + size - 1) {   //1,3,5,7, (nth = size+size-1)
	  // 각 라운드별 출력 처리
		for (i = 0; i < lens[round]; i++) {
			move(direction);        // 방향에 맞게 xp, yp 위치 변경
			arr[yt][xt] = num--;   // 새 위치에 숫자 출력하고 -1
		}
		round++;                  // 라운드 증가
		direction = (direction + 1) % 4; //다음 방향(0:동,1:남,2:서,3:북)
	}

	print_box(size);       // 최종 결과를 화면에  출력
	return 0;
}