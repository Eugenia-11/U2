#include <iostream>
using namespace std;

int main() {
	int num;
	while (1) {
		cout << "출력할 구구단(정수)을 입력하세요 >>";
		cin >> num;

		if (num >= 0) {

			for (int i = 1; i < 10; i++)
			{
				cout << num << "x" << i << "=" << num * i << endl;

			}
		}
		else
			cout << "구구단 출력을 종료합니다." << endl;

	}
	return 0;
}
