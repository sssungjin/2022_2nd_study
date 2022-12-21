#include <iostream>
using namespace std;
int num = 0;
class Box {
private:
	int volume;
	int width;
	int length;
	int height;
public:
	Box() {	//기본 생성자에서 변수의 값 0으로 초기화
		width = 0;
		length = 0;
		height = 0;
		volume = 0;
		num++;
	}
	Box(int width, int length, int height) {	//매개변수로 가로 세로 높이를 받으면 멤버 변수에 저장
		this->width = width;
		this->length = length;
		this->height = height;
		this->volume = 0;
	}
	void show() {	//부피 출력 함수
		cout << "부피 : " << volume << "cm3" << endl;
	}
	Box operator+(int a) {	//여유분으로 설정할 길이를 매개변수로 받음
		width += a;	//여유분만큼 가로 세로 높이에 더해준다.
		length += a;
		height += a;
		volume = width * length * height;
		return *this;
	}
	Box operator+(Box op) {
		Box tmp;	//Box 객체 생성
		tmp.width = this->width + op.width;		//매개변수 객체와 현재 클래스의 가로세로높이를 더한 값을 새로 생성한 객체 tmp에 저장
		tmp.length = this->length + op.length;	
		tmp.height = this->height + op.height;
		tmp.volume = (tmp.width) * (tmp.length) * (tmp.height);	//가로,세로,높이,부피를 모두 저장
		return tmp;	//객체 tmp를 반환
	}

};

int main()
{
	Box box1(4, 4, 4);
	Box box2(5, 5, 5);	//매개변수에 가로 세로 높이를 넣어 객체 생성	
	Box box3;	//기본 가로 세로 높이가 0인 객체 생성
	box1.operator+(1);	//여유분 1cm을 더해줌
	box2.operator+(1);	
	box3 = box1.operator+(box2);	//box1 객체와 box2 객체의 가로 세로 높이를 더한 값으로 부피를 구한 객체 반환

	cout << "Box1";
	box1.show();	//box1 부피 출력	
	cout << "Box2";
	box2.show();	//box2 부피 출력
	cout << "Box3";
	box3.show();	//box3 부피 출력
}