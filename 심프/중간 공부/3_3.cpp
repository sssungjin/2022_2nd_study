#include <iostream>
using namespace std;

class Car {
public:
int speed;
int gear;
string color;
    Car() {
        speed = 180;
        gear = 4;
        color = "Gray";
    }
    void speedUp();
    void speedDown();
    void colorTrans();
};
void Car:: speedUp() {
    speed += 15;
    cout << "speedUp호출" << speed<<endl;
}

void Car:: speedDown() {
    speed -= 15;
    cout << "speedDown호출" << speed<<endl;

}

void Car:: colorTrans() {
    color = "Black";
    cout << "colorTrans 호출" << color <<endl;

}
int main() {
    Car c;
    cout << "현재 속도는 " << c.speed << "기어는 " << c.gear << "색상은 " << c.color << endl;
    c.colorTrans();
    c.speedUp();
    c.speedUp();
    c.speedDown();
    c.colorTrans();
}