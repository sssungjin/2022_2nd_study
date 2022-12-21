#include <iostream>
#include "Student.h"
using namespace std;

int main() {
	int num;
	int input_id;
	float input_score;
	string input_name;	
	//입력 받을 정보를 받을 변수
	cout << "몇 명의 학생 정보를 입력할까요?: "; 
	cin >> num;	//num만큼 학생 정보를 입력 받음

	Student* st = new Student[num];	//객체를 num크기만큼 배열을 동적할당

	for (int i = 0; i < num; i++) {
		cout << i+1 << "번째 학생 정보를 입력하세요.\n";
		cout << "이름: ";
		cin >> input_name;
		cout << "학번: ";
		cin >> input_id;
		cout << "전체 점수(0~200): ";
		cin >> input_score;
		st[i].setName(input_name);	//입력받은 이름,학번,성적을 객체 배열의 멤버에 할당
		st[i].setId(input_id);
		st[i].setScore(input_score);
	}

	if (1) {
		cout << '\n';
	}
	cout << "\n[전체 학생 정보 출력]\n";	
	for (int i = 0; i < num; i++) {	//num만큼 반복문을 실행하여 학생 정보 출력
		cout << i + 1 << "번째 학생 정보를 출력합니다.\n";
		st[i].printInfo();	//객체 배열의 i번째 인덱스의 학생 정보를 출력
	}
	delete [] st;	//st배열을 모두 사용하였으므로 동적할당을 해제
}