#include <cstdio>
const int MAX = 100;

int N, arr[MAX][MAX];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int main() {
	scanf("%d", &N);

	int x = N / 2, y = N / 2, d = 0;
	arr[x][y] = 1;

	for (int i = 1; i <= N - 1; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 1; j <= i; j++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				arr[nx][ny] = arr[x][y] + 1;
				x = nx, y = ny;
			}
			d = (d + 1) % 4;
		}
	}

	for (int i = N - 1; i > 0; i--) arr[N - 1][i - 1] = arr[N - 1][i] + 1;

	return 0;
}