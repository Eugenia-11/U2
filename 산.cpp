#include <iostream>
using namespace std;

class Mount {
public:
	int height;
	int getHeight();
};

double Mount::getHeight() {
	return height;
}

int main() {
	Mount myMount;
	myMount.height = 1;
	int getHeight = myMount.getHeight();
    cout << "���̴�" << myMount.getHeight() << "����" << endl;
	
	Mount seorakMount;
	seorakMount.height = 1708;
	int  getHeight = seorakMount.getHeight();
	cout << "���̴�" << seorakMount.getHeight() << "����" << endl;
}