#include <iostream>
#include <stack>
using namespace std;

void Func(int k, int n) {
	if (k <= 0) { cout << "0보다 큰수만 변환 할수있음" << endl; return; }
	if (n < 2 || n>16) { cout << "2진수부터 16진수까지만 변환이 가능" << endl; return; }
	cout << "숫자" << k << "를" << n << "진수로 변환" << endl;
	cout << k << "->";
	int mok = INT_MAX;
	int namerge;
	stack<int> s;
	int ch;

	while (1) {
		if (mok == 0)break;
		if (mok == INT_MAX) {
			mok = k / n;
			namerge = k % n;
		}
		else {
			namerge = mok % n;
			mok = mok / n;
		}
		s.push(namerge);
	}
	for (int i = 0; s.size(); i++) {
		ch = s.top();
		s.pop();
		if (ch == 10) { cout << 'A'; }
		else if (ch == 11) { cout << 'B'; }
		else if (ch == 12) { cout << 'C'; }
		else if (ch == 13) { cout << 'D'; }
		else if (ch == 14) { cout << 'E'; }
		else if (ch == 15) { cout << 'F'; }
		else { cout << ch; }
	}
	cout << endl;
}

int main() {
	Func(233, 2);
	Func(233, 8);
	Func(233, 16);
}
