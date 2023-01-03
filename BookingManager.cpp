#include<iostream>
#include<string>
using namespace std;

class Client {
	string name;
	string tel;
	string pnum;

public:
	Client();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
	string getPnum() { return pnum; }
	void set(string pnum);

};



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


	for (int i = 0; i < 1; i++) {
		cout << "등록할 인원수" << ">>";
		cin >> Pnum;
		pInf[i].set(Pnum);
	}

	cout << Pnum << "명의 이름과 전화번호를 입력합니다.\n";

	for (int i = 0; i < 3; i++) {
		cout << "이름과 전화번호 입력" << ":";
		cin >> Name >> Tel;
		pInf[i].set(Pnum);
		pInf[i].set(Name, Tel);

	}

	cout << "저장되었습니다.\n";

	for (int i = 0; i < 5; i++) {
		cout << "목록보기[1], 검색[2], 삭제[3], 수정[4], 종료[5]" << ">>";
		cin >> Pnum;
		pInf[i].set(Pnum);
		if ((Pnum, "1") == 0) {
			cout << "[" << Pnum << "]" << Name << Tel; 
		};
		if ((Pnum, "2") == 0) {
			cout << "계속 검색[6], 검색 종료[7] " << ">>";
			cin >> Pnum;
			pInf[i].set(Pnum);
			cout << "검색할 이름을 입력하세요.";
			cin >> Name;
			cout << Name << "의 번호는" << Tel << "입니다.";

		};
		if ((Pnum, "3") == 0) {
			cout << "[" << Pnum << "]" << Name << Tel << endl;
			cout << "번호를 선택하면 삭제됩니다" << ">>";
			cin >> Pnum;

		};
		if ((Pnum, "4") == 0) {
			cout << "[" << Pnum << "]" << Name << Tel << endl;
			cout << "수정할 번호를 선택하세요." << ">>";
			cin >> Pnum;
			cout << "이름과 전화번호 입력" << ">>";
			cin >> Name >> Tel; "\n";
			cin >> Name >> Tel;
		};
		if ((Pnum, "5") == 0) {
			cout << "프로그램을 종료합니다." << endl;
			break;

		};


	}
}