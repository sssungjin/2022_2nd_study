#include <iostream>
using namespace std;

class Lecture {
private:
	string name;	//이름
	int num;	//학번
	string atten;	//출결
public:
	Lecture() {	//생성자를 통해 변수에 값을 미리 할당
		name = "abc";
		num = 0;
		atten = "X";
	}
	Lecture(string _name, int _num, string _atten) {	//매개변수로 _name, _num, _atten을 받음
		name = _name;	//_name을 클래스 변수 name에 대입
		num = _num;		//_num을 클래스 변수 num에 대입
		atten = _atten;	//_atten을 클래스 변수 atten에 대입
		cout << name << " 출석 체크를 시작합니다.\n";	//입력 받은 이름으로 출석체크 시작
	}
	void print() {
		cout << "이름 : " << name << endl;	//name에 저장된 이름 출력
		cout << "학번 : " << num << endl;	//num에 저장된 학번 출력
		cout << "출결(출석, 지각, 결석) : " << atten << endl;	//atten에 저장된 출결 출력
	}
	~Lecture() {
		cout << name << " 출석 체크가 완료되었습니다.\n";	//객체가 소멸 될 때 출석체크 완료 메시지 출력
	}
};

int main() {
	Lecture* p1 = new Lecture("김철수", 2022654321, "출석");	//객체를 동적할당을 통해 생성하면서 매개변수에 값을 넣어 초기화
	Lecture* p2 = new Lecture("이유리", 2022987956, "지각");
	Lecture* p3 = new Lecture("이훈이", 2022456789, "결석");

	cout << "\n-------------------------\n";
	p1->print();	//p1의 멤버 함수 print()에 접근하기 위해 ->로 함수 선언
	cout << '\n';
	p2->print();	//p2의 멤버 함수 print()에 접근하기 위해 ->로 함수 선언
	cout << '\n';
	p3->print();	//p3의 멤버 함수 print()에 접근하기 위해 ->로 함수 선언
	cout << "-------------------------\n\n";
	delete p1;	//p1 객체의 동적할당 해제
	delete p2;	//p2 객체의 동적할당 해제
	delete p3;	//p3 객체의 동적할당 해제

}