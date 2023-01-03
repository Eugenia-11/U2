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
    cout << "높이는" << myMount.getHeight() << "미터" << endl;
	
	Mount seorakMount;
	seorakMount.height = 1708;
	int  getHeight = seorakMount.getHeight();
	cout << "높이는" << seorakMount.getHeight() << "미터" << endl;
}