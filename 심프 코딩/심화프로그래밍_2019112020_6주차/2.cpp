#include <iostream>
#include <string>
using namespace std;

char changeAlpha(char c);	//매개변수의 문자를 대문자면 소문자로 
							//소문자면 대문자로 바꾸는 함수

int main()
{
	string str[3] = { "Dongguk", "iaIlIoQpAHAL", "EngLiSh" };	//문자열의 배열에 문자열 할당
	for (int i = 0; i < 3; i++) {
		cout << "원본 문자열: " << str[i] << ", 대소문자 변경-> ";
		for (int j = 0; j < str[i].length(); j++) {
			str[i][j] = changeAlpha(str[i][j]);	//문자열에 있는 알파벳의
		}										//대소문자를 모두 바꿔줌	
		cout << str[i] << endl;		//대소문자가 바뀐 문자열을 출력
	}
}

char changeAlpha(char c) {
	if ('a' <= c && c <= 'z')	//소문자면 toupper함수를 통해 대문자로 변환
		return toupper(c);
	else if ('A' <= c && c <= 'Z')	//대문자면 tolower함수를 통해 소문자로 변환
		return tolower(c);
}