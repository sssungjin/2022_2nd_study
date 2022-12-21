#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int a, b;
    cout << "두 수를 입력하세요 : ";
    cin >> a >> b;
    cout << "최대공약수" << gcd(a,b) << endl;
    cout << "최소공배수" << (a*b)/gcd(a,b) << endl;
}