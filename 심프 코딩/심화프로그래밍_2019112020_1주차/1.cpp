#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name, num, date, sent;

	cin >> name >> num >> date;
	cin.ignore(); //표준입력버퍼에 개행문자가 남아 있어서 버퍼 비워줌
	getline(cin, sent);

	for (int i = 0; i < 10; i++) {
		cout << name << num << date << sent << endl;
	}

}