#include<iostream>
#include<string>
using namespace std;



Client::Client() {} // ������

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
		cout << "��Ϻ���[1], �˻�[2], ����[3], ����[4], ����[5]" << ">>";
		cin >> Pnum;
		pInf[i].set(Pnum);


	}
}