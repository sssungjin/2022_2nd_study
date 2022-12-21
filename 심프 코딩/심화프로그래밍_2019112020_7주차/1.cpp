#include <iostream>
using namespace std;

void changeKnot(float* knot)	//포인터 매개변수 knot
{
	*knot = *knot - 10000;	//인수값 knot를 주소로 접근해 10000을 -
}

int main()
{
	//1kn = 1.852km/h
	float knot = 17000;
	float speed = knot / 3000;	//speed 변수에 속도
	cout << "선박 속도(항구 진입 전): " << speed << "킬로미터(초)\n";
	changeKnot(&knot);	//주소를 매개변수에 넣어 knot의 값 변경
	speed = knot / 3000;	//변경된 knot로 speed 구해서 출력
	cout << "선박 속도(항구 진입 후): " << speed << "킬로미터(초)\n";

}