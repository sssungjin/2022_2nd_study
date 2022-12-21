#include <iostream>
using namespace std;

class Student{
private:
string name;
int num;
string atten;

public:
Student(string name, int num, string atten) {
    cout << name << " 출석체크를 시작합니다\n";
    this->name = name;
    this->num = num;
    this->atten = atten;
}
void print() {
    cout << name << endl;
    cout << num << endl;
    cout << atten << endl;
}
~Student() {
    cout << name << "출석 체크 완료\n";
}
};

int main()
{
    Student *p1 = new Student("김철수", 2020, "출석");
    Student *p2 = new Student("영희", 20201111, "출석");
    Student *p3 = new Student("민수", 202033, "결석");

    p1->print();
    p2->print();
    p3->print();

    delete p1;
    delete p2;
    delete p3;

}