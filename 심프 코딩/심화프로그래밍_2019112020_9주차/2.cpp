#include <iostream>
using namespace std;

class Car {
private:
	string name;	//차량 이름
	int number;		//차량 번호
	int display;	//표시
public:
	static int many;	//전체 생성된 객체의 수를 알기 위해 static 으로 선언
	Car()
	{
		many++;	//생성자 실행될 때마다 즉 객체 생성될 때 마다 many++ 
	}
	void getInfo(int number, string name, int display)
	{	//매개변수로 받은 값들 클래스 변수에 할당
		this->number = number;
		this->name = name;
		this->display = display;
	}
	void printInfo()	//차량의 정보 출력
	{	
		cout << "차량 번호 : " << number << endl;
		cout << "차량 이름 : " << name << endl;
		cout << "표시 : " << display << endl << endl;
	}
};

int Car::many = 0;

int main()
{
	int n; cin >> n;	//차량의 정보를 n개 객체 받기 위해
	int num, disp;	//차량 번호, 표시 입력 받을 임시 변수
	string str;		//차량 이름 입력 받을 임시 변수
	Car *c = new Car[n];	//n개만큼 객체 동적할당
	for (int i = 0; i < n; i++) {
		cout << "차량 번호 입력 : ";
		cin >> num;
		cout << "차량 이름 입력 : ";
		cin >> str;
		cout << "표시(1-10) : ";
		cin >> disp;
		cout << "\n";
		c[i].getInfo(num, str, disp);	//입력 받은 정보 할당
		c[i].printInfo();	//입력 받은 정보 출력
	}
	cout << "클래스에서 생성된 객체의 수 : " << Car::many << endl;		//클래스 이름 통해서 정적 변수에 접근해 출력
}