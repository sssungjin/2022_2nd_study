#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    srand((unsigned int)time(NULL));

    int a = 0;
    while(1) {
        cout << "덧셈 문제를 자동으로 출제합니다.\n";
        int num1 = rand()%100;
        int num2 = rand()%100;
        cout << num1 << "+" << num2 << "=";
        cin >> a;
        if(a == num1+num2)
            cout << "맞았습니다.\n";
        else if(a != num1+num2)
        {
            cout << "틀렸습니다.\n";
        }
        else{
            cout << "종료합니다.\n";
            break;

        }
    }
}

