#include <iostream>
using namespace std;
int num = 1;
class Distance {
	int feet;
	int inch;
public:
	Distance() {	//기본 생성자에서 멤버 변수 0으로 초기화
		this->feet = 0;
		this->inch = 0;
	}
	void getInfo() {	//멤버 변수 feet, inch 의 값을 입력 받는 함수
		cout << "d" << num << ".feet: ";
		cin >> feet;
		cout << "d" << num << ".inch: ";
		num++;
		cin >> inch;
	}
	int getFeet() {	//멤버 변수feet 를 반환
		return this->feet;
	}
	int getInch() {	//멤버 변수 inch 를 반환
		return this->inch;
	}
	friend Distance operator+(Distance op1, Distance op2);	//외부함수를 프렌드 함수를 선언해서 사용하게 함
};

Distance operator+(Distance op1, Distance op2) {	//객체 두개를 매개변수로 받음
	Distance tmp;	//반환할 객체 tmp 생성
	tmp.feet = op1.feet + op2.feet;	//tmp의 feet와 inch에 op1,op2의 feet와 inch를 더한 값을 저장
	tmp.inch = op1.inch + op2.inch;
	return tmp;	//tmp 반환
}

int main()
{
	Distance d1, d2, d3, d4, tmp;
	d1.getInfo();	//d1 객체의 feet, inch 입력 받음
	d2.getInfo();	//d2 객체의 feet, inch 입력 받음
	tmp = operator+(d1, d2);	//d1, d2 객체를 매개변수로 받아 feet,inch 를 더한값이 저장된 객체를 tmp 에 반환
	cout << "두 개(d1, d2)의 거리의 합: " << tmp.getFeet() << " feet, " << tmp.getInch() << " inch" << endl;	//더한 값 출력
	d3.getInfo();	//d3 객체의 feet, inch 입력 받음
	d4.getInfo();	//d4 객체의 feet, inch 입력 받음
	tmp = operator+(d3, d4);	//d3, d4 객체를 매개변수로 받아 feet,inch 를 더한값이 저장된 객체를 tmp 에 반환
	cout << "두 개(d3, d4)의 거리의 합: " << tmp.getFeet() << " feet, " << tmp.getInch() << " inch" << endl;	//더한 값 출력

}
