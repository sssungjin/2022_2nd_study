#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char op;
    while(1) {
        cout << "^ ";
        cin >> a >> op >> b;
        if(op == '+') {
            cout << a << " + " << b << " = " << a+b;
        }
        else
            cout << a << " - " << b << " = " << a-b;

    }
}