#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cout << "원본 문자열: ";
	getline(cin, str, '\n');	//공백 구분 없이 개행문자가 올 때까지 입력받음

	int len = str.length();	//반복문 사용하기 위해 길이 구함
	cout << "역순 문자열: ";
	for(int i = len-1; i >= 0; i--) {	//길이-1부터 0까지 역순으로 문자열 출력
		cout << str[i];
	}
}