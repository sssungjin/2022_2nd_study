#include <iostream>
using namespace std;

class Pyramid {
private:
	int num;
public:
	Pyramid() {
		cout << "글자수를 입력하세요(26 이하의 숫자) : ";
		cin >> this->num;	//생성자에서 num 입력 받음
	}
	friend void printPyramid(Pyramid&);	//printPyramid 함수에 friend 함수 선언해서 Pyramid 클래스에 접근하게 함
};

void printPyramid(Pyramid& p) {
	for (int i = 1; i <= p.num; i++) {	//입력 받은 숫자만큼 반복
		for (int j = 1; j <= p.num - i; j++) {	//i 뺀 만큼 공백 출력
			cout << "  ";	
		}
		for (int j = 1; j <= i * 2 - 1; j++) {	//입력 받은 숫자 * 2 - 1 문자를 출력 (11을 받으면 11번째 문자는 하나만 출력하므로 -1)
			char c = 65 + i - 1 - (j - i > 0 ? j - i : -1 * (j - i));	//A아스키코드 65부터 i더하고 1을 빼고 j가 i보다 커지면 문자를
																		//내림차순으로 출력하기 위해 -(j-i) 값을 뺌 ex) a b c b a
			cout << c << " ";
		}
		cout << "\n";
	}
	cout << "입력한 글자수 : " << p.num;
}

int main()
{
	Pyramid p;	//p객체 생성하여 num 입력 받음
	printPyramid(p);	//friend 함수를 통해 p객체의 정보 num을 전역변수에서 받아 사용
}