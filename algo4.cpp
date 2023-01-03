#include <stdio.h>
int arr[100][100];
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int i = 0, j = 0, a = 1;

	for (i = 0; i < N; j++) {
		for (j = 0; j < M; j++) {
			arr[i][j] = 0;
		}
	}

	i = 3;
	j = 3;
	arr[i][j] = 1;
	a = 2;

	while (a < N*M) {
		while (j + 1 < M && arr[i][j + 1] == 0) {
			j++;
			arr[i][j] = a;
			a++;
		}
		while (i + 1 < N && arr[i + 1][j] == 0) {
			i++;
			arr[i][j] = a;
			a++;
		}
		while (j - 1 >= 0 && arr[i][j - 1] == 0) {
			j--;
			arr[i][j] = a;
			a++;
		}
		while (i - 1 >= 0 && arr[i - 1][j] == 0) {
			i--;
			arr[i][j] = a;
			a++;
		}

	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

}