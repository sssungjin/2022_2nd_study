#include <iostream>
#include <climits>
using namespace std;

void FindMinMax (int A[ ], int n, int *Minimum, int *Maximum) {
     /* 입력 : A -n 개의 숫자가 저장되어 있는 배열 
     n -배열 A에 저장되어 있는 숫자의 개수 
     출력 : *Minimum -A에 저장된 값 중에서 최소값 *Maximum -A에 저장된 값 중에서 최대값 */
      int i ; 
    if(n%2 == 1) { 
    *Minimum=A[0]; *Maximum=A[0];
    for (i = 1; i < n-1 ; i+=2) {
        if (A[i] < A[i+1]) {
            Small= A[i]; Large= A[i+1];
        } 
        else {
            Small = A[i+1];
            Large = A[i];
        } 
        if (Small < *Minimum)
            *Minimum = Small; 
        if (Large > *Maximum)
            *Maximum = Large; 
        } 
    }
      else {
        for (i = 0; i < n-1 ; i+=2) {
            if (A[i] < A[i+1]) {
                Small= A[i]; Large= A[i+1];
            } 
            else {
                Small = A[i+1];
                Large = A[i];
            } 
            if (Small < *Minimum)
                *Minimum = Small; 
            if (Large > *Maximum)
                *Maximum = Large; 
        } 
    }
    return; 
}
