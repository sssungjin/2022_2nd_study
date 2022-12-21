#include <iostream>
using namespace std;

int main()
{
	int m_num, c_num;
	cout << "민수의 숫자 = ";
	cin >> m_num;
	cout << "철수의 숫자 = ";
	cin >> c_num;

	int& num_m = m_num;	//m_num의 참조 변수 num_m 생성
	int& num_c = c_num;	//n_num의 참조 변수 num_n 생성

	int tmp;
	tmp = num_c;
	num_c = num_m;
	num_m = tmp;	//참조 변수 값 서로 교환

	cout << "\n숫자를 서로 교환했습니다.\n";
	
	tmp = 0;
	while (1) {
		tmp = tmp * 10 + num_m % 10;	//tmp에 num의 맨 아랫자리부터 넣고 10을 곱해 역순으로 바꿈
		num_m = num_m / 10;	//다음 자릿수를 구할 수 있도록 10을 나눠준다
		if (num_m <= 0)	//10으로 나눈 num이 0보다 작으면 반복문 종료
			break;
	}
	num_m = tmp;	//tmp에 역순으로 바뀐 num_m값을 대입

	tmp = 0;
	while (1) {
		tmp = tmp * 10 + num_c % 10;	//tmp에 num의 맨 아랫자리부터 넣고 10을 곱해 역순으로 바꿈
		num_c = num_c / 10;	//다음 자릿수를 구할 수 있도록 10을 나눠준다
		if (num_c <= 0)	//10으로 나눈 num이 0보다 작으면 반복문 종료
			break;
	}
	num_c = tmp;	//tmp에 역순으로 바뀐 num_n값을 대입

	
	cout << "숫자를 거꾸로 변경했습니다.\n\n";

	cout << "민수의 숫자 = " << m_num << endl;	//참조 변수 num_m 값과 m_num 같음
	cout << "철수의 숫자 = " << c_num << endl;	//참조 변수 num_n 값과 n_num 같음

}