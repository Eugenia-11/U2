#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


class Family {
	int size; //가족 구성원 수
	char* name;     //가족 이름
public:
	Family(const char* name, int size);
	Family(const Family& family);
	void changeName(const char* name);
	void setFamily(const char* name, int size);
	void show();
	~Family();
};

Family::Family(const char* name, int size)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);

	this->size = size;
}

Family::Family(const Family& family) {
	this->size = family.size;
	int len = strlen(family.name);
	this->name = new char[len + 1];
	strcpy(this->name, family.name);

}

void Family::changeName(const char* name)
{
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

void Family::setFamily(const char * name, int size)
{
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
	this->size = size;
}


void Family::show()
{
	cout << this->name << "가족은 " << this->size << "명 입니다.\n";
	cout << endl << endl;;
}

Family::~Family()
{
	if (name) delete[] name;
}



int main() {
	Family simpson = Family("Simpson", 3); // 3명으로 구성된 Simpson 가족
	simpson.show();

	Family addams = simpson;
	addams.setFamily("Addams", 5);
	addams.show();
}
