#include <iostream>
#include <cstring>
using namespace std;

class Mount {
private:
	int name;
	int height;
public:
	Mount() { name = n; }
	Mount(int n, int h) { name = n;, height = h; }
	void setRadius(int n) { name = n;, height = h; }
	double getArea();
};
double Mount::getArea() {
	return name(height);
}

int main() {
	Mount mount[]= {
Mount("Hallasan", 1947),
Mount("Annapurna", 8091),
Mount("Everest", 8848),
Mount("Paektu", 2744)
	};
	for (int i = 1; i < 5; i++)  {
			cout << "[" << i << "]";
			cout << mount[].getArea() << endl;
		}


int n = 0;
int j;
char name[100];
char longName[100];

for (j = 1; j < 6; j++) {
	cin.getline(name, 100, ';');
	cout << j << " : " << name << endl;
	if (n < strlen(name)) {
		n = strlen(name);
		strcpy(longName, name);
	}
}
cout << "===== The longest mountain name ===== \n" << longName;

return 0;

}

