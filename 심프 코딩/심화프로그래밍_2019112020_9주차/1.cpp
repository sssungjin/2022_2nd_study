#include <iostream>
#define PI 3.14	//원의 면적, 원뿔, 구의 부피, 실린더 부피 구할 때 사용할 PI 정의
using namespace std;

class measure {
private:
	int sel = 0;	//어떤 계산 할 것인지 입력 받을 변수
	int rad = 0;	//반지름
	int h = 0;		//높이
	int side_a = 0;	//삼각형이나 사각형 변의 길이 a
	int side_b = 0;	//삼각형이나 사각형 변의 길이 b
public:
	measure() {	//객체 생성하면서 선택화면 출력하고 sel을 입력 받음
		cout << "면적 및 부피 계산기\n\n";

		cout << "1. 원의 면적\n";	//반지름 입력
		cout << "2. 직사각형 면적\n";		//두 변 입력
		cout << "3. 삼각형 면적\n";		//두 변 입력
		cout << "4. 정사각형 면적\n";		//한 변 입력
		cout << "5. 원뿔의 부피\n";		//반지름, 높이 입력 PI*r*r*h/3
		cout << "6. 구의 부피\n";	//반지름 입력 4/3*PI*r*r
		cout << "7. 실린더 부피\n\n";	//반지름, 높이 입력 PI*r*r*h

		cout << "입력 : ";
		cin >> sel;

		measure a(sel);	//생성자 중복 정의를 통해 sel을 매개변수로 가지는 객체 생성하면서 중복 정의된 생성자 호출
	}
	measure(int sel) {
		cout << "\n";	//sel에 따라 측정할 도형 선택
		if (sel == 1) {	
			cout << "반지름 입력 : ";
			cin >> rad;
			cout << "원의 면적은 " << rad*rad*PI << endl;
		}
		else if (sel == 2) {
			cout << "직사각형의 변의 길이 입력(a, b) : ";
			cin >> side_a >> side_b;
			cout << "직사각형의 면적은 " << side_a * side_b << endl;
		}
		else if (sel == 3) {
			cout << "삼각형의 변의 길이 입력(a, b) : ";
			cin >> side_a >> side_b;
			cout << "삼각형의 면적은 " << side_a * side_b / 2 << endl;
		}
		else if (sel == 4) {
			cout << "정사각형의 변의 길이 입력 : ";
			cin >> side_a;
			cout << "정사각형의 면적은 " << side_a * side_a << endl;
		}
		else if (sel == 5) {
			cout << "반지름 입력 : ";
			cin >> rad;
			cout << "높이 입력 : ";
			cin >> h;
			cout << "원뿔의 부피는 " << rad * rad * PI * h / 3 << endl;
		}
		else if (sel == 6) {
			cout << "반지름 입력 : ";
			cin >> rad;
			cout << "구의 부피는 " << rad * rad * PI * 4 / 3 << endl;
		}
		else if (sel == 7) {
			cout << "반지름 입력 : ";
			cin >> rad;
			cout << "높이 입력 : ";
			cin >> h;
			cout << "실린더의 부피는 " << rad * rad * PI * h << endl;
		}
	}

};
int main()
{
	measure m;
}