#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int list[10];
    for(int i = 0; i < 10; i++) {
        cin >> list[i];
    }   

    sort(list, list+10);
    for(int i = 0; i < 10; i++) {
        cout << list[i]  <<" " ;
    } 
}