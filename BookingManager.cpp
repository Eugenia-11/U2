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


	for (int i = 0; i < 1; i++) {
		cout << "����� �ο���" << ">>";
		cin >> Pnum;
		pInf[i].set(Pnum);
	}

	cout << Pnum << "���� �̸��� ��ȭ��ȣ�� �Է��մϴ�.\n";

	for (int i = 0; i < 3; i++) {
		cout << "�̸��� ��ȭ��ȣ �Է�" << ":";
		cin >> Name >> Tel;
		pInf[i].set(Pnum);
		pInf[i].set(Name, Tel);

	}

	cout << "����Ǿ����ϴ�.\n";

	for (int i = 0; i < 5; i++) {
		cout << "��Ϻ���[1], �˻�[2], ����[3], ����[4], ����[5]" << ">>";
		cin >> Pnum;
		pInf[i].set(Pnum);
		if ((Pnum, "1") == 0) {
			cout << "[" << Pnum << "]" << Name << Tel; 
		};
		if ((Pnum, "2") == 0) {
			cout << "��� �˻�[6], �˻� ����[7] " << ">>";
			cin >> Pnum;
			pInf[i].set(Pnum);
			cout << "�˻��� �̸��� �Է��ϼ���.";
			cin >> Name;
			cout << Name << "�� ��ȣ��" << Tel << "�Դϴ�.";

		};
		if ((Pnum, "3") == 0) {
			cout << "[" << Pnum << "]" << Name << Tel << endl;
			cout << "��ȣ�� �����ϸ� �����˴ϴ�" << ">>";
			cin >> Pnum;

		};
		if ((Pnum, "4") == 0) {
			cout << "[" << Pnum << "]" << Name << Tel << endl;
			cout << "������ ��ȣ�� �����ϼ���." << ">>";
			cin >> Pnum;
			cout << "�̸��� ��ȭ��ȣ �Է�" << ">>";
			cin >> Name >> Tel; "\n";
			cin >> Name >> Tel;
		};
		if ((Pnum, "5") == 0) {
			cout << "���α׷��� �����մϴ�." << endl;
			break;

		};


	}
}