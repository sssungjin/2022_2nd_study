#pragma once
#include <iostream>
using namespace std;

class Time {
private:
	int hour;	//시간
	int minute;	//분
	int second;	//초
	int total;	//시간 분 초를 모두 초로 바꿔 더한 값
public:
	Time();
	void printTime();
	int totalSec();
};

Time::Time() {
	cout << "시간을 입력해주세요:\n";
	cout << "몇 시? ";	//시간 입력
	cin >> hour;
	cout << "몇 분? ";	//분 입력
	cin >> minute;
	cout << "몇 초? ";	//초 입력
	cin >> second;
}
void Time::printTime() {
	cout << "입력한 시간 = ";
	if (hour < 10)	//10보다 작으면 십의자리 0출력
		cout << '0' << hour << ":";
	else
		cout << hour << ":";
	if (minute < 10)	//10보다 작으면 십의자리 0출력
		cout << '0' << minute << ":";
	else
		cout << minute << ":";
	if (second < 10)	//10보다 작으면 십의자리 0출력
		cout << '0' << second << '\n';
	else
		cout << second << '\n';
	cout << "시간을 초로 변환 = " << totalSec();	//totalSec함수로 시간 분 초 합한 값을 반환 받아 출력
}
int Time::totalSec() {
	total = hour * 60 * 60 + minute * 60 + second;	//시간*60*60 + 분*60 + 초

	return total;	//더한 값 반환
}