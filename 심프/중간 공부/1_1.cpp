#include <iostream>
using namespace std;

int main() {
    int a; cin >> a;

    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= a; i++) {
        if(i%2 == 0)
            sum1 += i;
        else
            sum2 += i;
    }
    cout << endl << sum1 << endl << sum2;

}