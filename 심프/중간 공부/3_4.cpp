#include <iostream>
using namespace std;

class Circle {
public:
void draw() {
    cout << "asdas";
}
};

int main() {
    Circle poly;
    Circle *p;

    p = &poly;
    p->draw();
}