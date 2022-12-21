#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0) {	//b가 0이 되면 반복문 종료
		int r = a % b;	//a를 b로 나눈 나머지를 r에 저장

		a = b;	//a에 b를 넣어주고
		b = r;	//b에는 나머지(r)을 넣어준다
	}
	return a;
}

int main()
{
	int a, b;	//gcd함수에 넣을 변수 선언
	cout << "두 수를 입력하세요: ";
	cin >> a >> b;
	
	if (a < b) {	
		int tmp = a;
		a = b;
		b = tmp;
	} //a가 b보다 작을 경우 함수에서 나누기가 제대로 실행되지 않으므로 swap해줌
	  
	cout << "두 수의 최대공약수: " << gcd(a, b) << '\n';	//gcd의 반환값 추력
	cout << "두 수의 최소공배수: " << a * b / gcd(a, b);	//최소공배수는 두 자연수의 곱 / 최대공약수
}