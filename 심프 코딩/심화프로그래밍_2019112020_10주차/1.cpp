#include <iostream>
using namespace std;


class Number {
public:
	Number() {
		cout << "656과 789 사이에서 7로 나눌 수 있는 숫자\n\n";
	}
	friend void printNum(Number&);	//전역 함수 printNum에 friend 키워드 선언
};

void printNum(Number& N)
{
	int sum = 0;
	for (int i = 656; i <= 789; i++) {	//656 부터 789 사이 모든 숫자 검사해서 
		if (i % 7 == 0) {			
			cout << "7로 나누어진 숫자는 " << i << endl;	//7로 나눈 나머지가 0이면 출력
			sum += i;		//나머지가 0이면 그 숫자를 합에 더함
		}
	}
	cout << " 7로 나눌 수 있는 모든 수의 합은 " << sum << endl;	//합 출력
}

int main()
{
	Number n;	//n객체 생성

	printNum(n);	//friend 함수 printNum 호출
}