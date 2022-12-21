#include <iostream>
using namespace std;

int main() 
{
    int list[10];
    cout << "입력 : ";
    for(int i = 0; i < 10; i++) {
        cin >> list[i];
    }
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < i; j++) {
            if(list[j] > list[i]) {
                int tmp;
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        cout << list[i] << " ";
    }
}