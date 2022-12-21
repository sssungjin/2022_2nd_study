#include <iostream>
using namespace std;

int main()
{
	int a, b; //계산할 정수를 받을 변수
	char op; //연산자를 받을 변수

	while (1) { //종료조건이 없으므로 계속 반복
		cout << "^ ";
		cin >> a >> op >> b;	//a와 op와 b를 순서대로 입력받음
		if (op == '+') {	//op를 확인하고 +면 a, b 더한 값 출력
			cout << a << " + " << b << " = " << a + b << '\n';
		}
		else if(op == '-') {	//op를 확인하고 -면 a, b 뺀 값 출력
			cout << a << " - " << b << " = " << a - b << '\n';
		}
		else if (op == '*') {	//op를 확인하고 *면 a, b 곱한 값 출력
			cout << a << " * " << b << " = " << a * b << '\n';
		}
		else if (op == '/') {	//op를 확인하고 /면 a, b 몫 출력
			cout << a << " / " << b << " = " << a / b << '\n';
		}
		else if (op == '%') {	//op를 확인하고 %면 a, b 나머지 출력
			cout << a << " % " << b << " = " << a % b << '\n';
		}
	}
}