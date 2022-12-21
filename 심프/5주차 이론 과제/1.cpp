#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Circle
{
private:
    int x, y, radius;
public:
    Circle() {
        x = 1000, y = 1000, radius = 1000; //x, y, radius의 초기값을 나올 수 없는 수로 초기화
    }
    Circle(int _x, int _y, int r) {
        x = _x; //매개변수로 받은 _x를 클래스 변수 x에 대입
        y = _y; //매개변수로 받은 _y를 클래스 변수 y에 대입
        radius = r; //매개변수로 받은 r을 클래스 변수 radius에 대입
    }
    void print() {
        cout << "반지름: " << radius << " @(" << x << ", " << y << ")\n"; 
    }   //반지름, x좌표, y좌표를 출력하는 함수
};

int main() {
    srand((unsigned int)time(NULL));    //난수 설정

    Circle circle[10];  //객체의 배열 10개를 생성

    for(int i = 0;i < 10; i++) {    //10개의 객체 배열에 할당하기 위해 10번 반복
        circle[i] = Circle(rand()%500, rand()%300, rand()%100);
    }   //매개변수가 있는 생성자에 난수를 매개변수로 넣어 각각 객체의 x,y,radius 변수에 값을 넣어준다.
    for(int i = 0; i < 10; i++) {
        circle[i].print();  //10개의 객체 배열에 있는 정보를 print()함수를 사용해 모두 출력
    }
}