#include <iostream>
using namespace std;

int main()
{
	cout << "정수를 얼마나 입력 받을까요? ";	
	int n; cin >> n;	//입력 받을 정수의 수 n을 입력 받음
	if (n < 0) {	//올바른 입력이 아닐 때 함수 종료
		cout << "잘못된 입력입니다.\n";
		return 0;
	}
	int* arr = new int[n];	//입력 받을 정수의 배열 동적할당

	for (int i = 0; i < n; i++) {
		cout << "정수 입력 : ";
		cin >> arr[i];	//n번 반복해 n개의 정수를 배열에 입력 받음
	}
	cout << "정수 출력 : ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";	//n번 반복문을 돌려 입력 받은 정수 모두 출력
	}
	delete[] arr;	//동적할당 해제
}