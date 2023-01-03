#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char a[20];

	while (1)
	{
		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(a, 20);

		if (strcmp(a, "yes") == 0) break;
	}
	cout << "종료합니다...\n";

}

