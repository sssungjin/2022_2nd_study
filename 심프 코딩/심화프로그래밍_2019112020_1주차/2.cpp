#include <iostream>
using namespace std;

int main()
{
	int arr[10] = { 1, 56, 15, 99, 65, 33, 21, 47, 72, 5 };
	
	cout << "데이터 출력 : ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 10; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	cout << "오름차순 정렬 : ";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}