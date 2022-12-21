#include <iostream>
using namespace std;

class books {
private:
	string b_name;	//책 이름
	int price;		//책 가격
public:
	books() {	//생성자를 통해 변수 값 초기화
		b_name = "aa";
		price = -1;
	}
	void setName(string _name) {	//매개변수로 받은 _name을 클래스 변수 b_name에 대입
		b_name = _name;
	}
	void setPrice(int _price) {		//매개변수로 받은 _price를 클래스 변수 price에 대입
		price = _price;
	}
	void print() {	//책 제목과 가격 출력하는 함수
		cout << "제목:" << b_name << endl;
		cout << "가격:" << price << endl;
	}
};

int main() {

	string input_name;	//입력 받을 이름 저장 할 변수
	int input_price;	//입력 받을 가격 저장 할 변수
	
	books b[3];	//세개의 객체 배열 생성
	books* bp;	//객체 포인터 선언

	for (int i = 0; i < 3; i++) {
		cout << "책 " << i + 1 << "번 제목 및 가격 입력" << endl;
		cout << "제목:";
		cin >> input_name;
		cout << "가격:";
		cin >> input_price;	//객체 변수에 넣을 책 이름, 책 가격 입력 받음
		bp = &b[i];	//객체 포인터에 현재 넣을 객체 배열 주소 대입
		bp->setName(input_name);	//객체 포인터를 통해 멤버 함수 호출
		bp->setPrice(input_price);	//객체 포인터를 통해 멤버 함수 호출
	}
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		cout << "책 " << i + 1 << endl;
		bp = &b[i];	//객체 포인터에 현재 넣을 객체 배열 주소 대입
		bp->print();	//객체 포인터를 통해 멤버 함수 호출해 책 제목, 가격 출력
	}
}