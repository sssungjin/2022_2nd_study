#pragma once
#include <iostream>
using namespace std;

class Student {
private:
	string name;	//학생 이름
	int id;			//학번
	float score;	//성적
public:
	void setName(string _name);	//이름을 입력받아 설정하는 함수
	void setId(int _id);	//학번을 입력받아 설정하는 함수
	void setScore(float _score);	//성적을 입력받아 설정하는 함수
	void printInfo();	//정보를 출력하는 함수
};

void Student::setName(string _name) {
	name = _name;	//매개변수를 클래스 변수로 설정
}

void Student::setId(int _id) {
	id = _id;	//매개변수를 받아 클래스 변수로 설정
}

void Student::setScore(float _score) {
	score = _score;	//매개변수를 받아 클래스 변수로 설정
}

void Student::printInfo() {	//이름,학번,전체, 환산점수 출력하는 함수
	cout << "이름: " << name << '\n';	
	cout << "학번: " << id << '\n';
	cout << "전체: " << score << '\n';
	cout << "점수 환산(%): " << score / 2 << '\n';
}