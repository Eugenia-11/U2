#include<iostream>
#include<string>
using namespace std;



Client::Client() {} // 생성자

void Client::set(string N, string T) {
	name = N;
	tel = T;
}

void Client::set(string P) {
	pnum = P;
}



int main() {
	string Name, Tel;
	string Pnum;
	Client *pInf = new Client[100];


	for (int i = 0; i < 5; i++) {
		cout << "목록보기[1], 검색[2], 삭제[3], 수정[4], 종료[5]" << ">>";
		cin >> Pnum;
		pInf[i].set(Pnum);


	}
}