#include <iostream>
 using namespace std;

 int main()
 {
    int n = 10;
    int count = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 1; j<=i; j++) {
            if(j % i ==0)
            count++;
        }
    }
    cout << count;
 }