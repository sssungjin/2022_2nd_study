#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef int itemType;

itemType *a, *b, *N;
int my_move = 0, my_cmp = 0;

void CountSort(itemType *a, itemType *b, itemType *N, int n, int k) {
      int i,j;
      for(i=1; i<=k; i++) 
        N[i]=0; 
      for(i=0; i<n; i++) {
        N[a[i]] = N[a[i]] + 1;
      }
      for(i=2; i<=k; i++) {
        N[i] = N[i] + N[i-1];
      } 
      for(j=n-1; j>=0; j--) {
             b[N[a[j]]] = a[j];
             my_move++; 
             N[a[j]] = N[a[j]] - 1; 
        } 
}

int main()
{
    srand((unsigned int)time(NULL));

    int n;
    cin >> n;
    int k = n;
    b = new itemType[n];  N = new itemType[k];

    itemType **tmp = new itemType *[n];
    itemType *A = new itemType[n];
    itemType *B = new itemType[n];
    itemType *C = new itemType[n];
    int j = n;
    for (int i = 0; i < n; i++)
    {
        A[i] = j--;
    }

    // b 배열 할당
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new itemType[2];
        tmp[i][0] = (1 + rand() % n);
        tmp[i][1] = i + 1;
    }
    int temp, temp_1;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i) - 1; j++) {
			if (tmp[j][0] > tmp[j + 1][0]) {
				temp = tmp[j][0];
				tmp[j][0] = tmp[j + 1][0];
				tmp[j + 1][0] = temp;

                temp_1 = tmp[j][1];
				tmp[j][1] = tmp[j + 1][1];
				tmp[j + 1][1] = temp_1;
			}
		}
	}
    for (int i = 0; i < n; i++)
    {
        B[i] = tmp[i][1];
    }

    for(int i = 0; i < n; i++) {
        C[i] = (1+rand() % n);
    }
    CountSort(A, b, N, n, k);
    int a_cmp = my_cmp;
    int a_move = my_move;
    cout << "a : ";
    for(int i = 1; i <= 20; i++) {
        cout << b[i] << " ";
    }
    my_cmp = 0, my_move = 0;
    CountSort(B, b, N, n, k);
    int b_cmp = my_cmp;
    int b_move = my_move;
        cout << endl << "b : ";
    for(int i = 1; i <= 20; i++) {
        cout << b[i] << " ";
    }
    my_cmp = 0, my_move = 0;
    CountSort(C, b, N, n, k);
    int c_cmp = my_cmp;
    int c_move = my_move;
    cout << endl << "c : ";
    for(int i = 1; i <= 20; i++) {
        cout << b[i] << " ";
    }
    my_cmp = 0, my_move = 0;
    
    

    
    cout << endl << "Compare_Cnt_A : " << a_cmp << ", DataMove_Cnt_A : " << a_move << endl;
    cout << "Compare_Cnt_B : " << b_cmp << ", DataMove_Cnt_B : " << b_move << endl;
    cout << "Compare_Cnt_C : " << c_cmp << ", DataMove_Cnt_C : " << c_move << endl;
}