#include <iostream>
#include <string>	//getline을 사용하기 위해서 포함
using namespace std;

int main()
{
	string sent; //문자열을 입력 받을 변수 선언

	cout << "문자열을 입력하세요: ";
	getline(cin, sent);	//string 헤더파일에 있는 개행을 제외한 공백 구분없이 문자열을 입력받아서 sent문자열 변수에 저장

	for (int i = sent.length() - 1; i >= 0; i--) {	//문자열을 반대로 출력해야 하므로 문자열의 길이 - 1 인덱스 부터 인덱스 0까지 출력
		cout << sent[i];
	}
}