#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

class Factory {
private:
	char* name;
public:
	Factory(const char* name) {	//모니터 이름을 매개변수
		int len = strlen(name);	
		this->name = new char[len + 1];
		strcpy(this->name, name);	//클래스 변수에 매개변수 대입
	}
	Factory(const Factory& factory) {	//복사 생성자 정의
		int len = strlen(factory.name);	//매개변수 클래스의 변수 name 길이
		this->name = new char[len + 1];	//길이+1만큼 동적할당
		cout << "메모리 할당\n";
		strcpy(this->name, factory.name);	//매개변수 클래스의 name변수 값을 현재 클래스의 name에 대입
		cout << this->name << " 1대 생산!!" << endl;
	}
	~Factory() {
		delete [] name;
		cout << "메모리 소멸\n";
	}
};
int main()
{
	Factory f1("SAMSUNG");	//f1객체에 name을 SAMSUNG 으로 생성 
	Factory f2(f1);		//f2객체에 f1객체 name을 동적할당 후 복사
}