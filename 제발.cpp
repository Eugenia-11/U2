#include <iostream>
using namespace std;

int main() {
	int num;
	while (1) {
		cout << "����� ������(����)�� �Է��ϼ��� >>";
		cin >> num;

		if (num >= 0) {

			for (int i = 1; i < 10; i++)
			{
				cout << num << "x" << i << "=" << num * i << endl;

			}
		}
		else
			cout << "������ ����� �����մϴ�." << endl;

	}
	return 0;
}
