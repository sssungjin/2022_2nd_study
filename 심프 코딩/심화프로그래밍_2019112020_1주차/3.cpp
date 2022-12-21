#include <iostream>
#include <algorithm>
using namespace std;

class myData {
public:
	void showData() {
		cout << "데이터 출력 : ";
		for (int i = 0; i < 10; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	void showSort() {
		cout << "오름차순 정렬 : ";
		for (int i = 0; i < 10; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	void sorting() {
		sort(arr, arr + 10);
	}
private:
	int arr[10] = { 1, 56, 15, 99, 65, 33, 21, 47, 72, 5 };
};

int main()
{
	myData da;
	da.showData();
	da.sorting();
	da.showSort();
}