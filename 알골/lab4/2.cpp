#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
using namespace std;

typedef int itemType;
int my_cmp = 0, my_move = 0;
itemType* sorted;

void merge(itemType a[], int l, int mid, int r) {
      int i,j,k,n; 
      i=l; j=mid+1; k=l; 
      while (i<=mid && j<=r) { 
            if (++my_cmp && (a[i]<=a[j])) {
                  sorted[k++] = a[i++]; 
                  my_move++; 
             } else { 
                   sorted[k++] = a[j++]; 
                   my_move++; 
            } 
       } 
       if (i>mid) 
            for (n=j; n<=r; n++){ 
                sorted[k++] = a[n]; 
                my_move++; 
            }  
       else 
            for (n=i; n<=mid; n++){
              sorted[k++] = a[n];
              my_move++;  
            }  
       for (n=l; n<=r; n++) {
        a[n] = sorted[n];
        my_move++;
       } 
}
void mergesort(itemType a[], int l, int r) { 
       int mid; 
       if (l < r) { 
             mid = ( l + r)/2; 
             mergesort(a, l, mid);
             mergesort(a, mid+1, r);
             merge(a, l, mid, r); 
       } 
}

int main()
{
    srand((unsigned int)time(NULL));

    int n;
    cin >> n;
    sorted = new itemType[n];
    int **tmp = new int *[n];
    int *a = new int[n];
    int *b = new int[n];
    int a_cmp, b_cmp, a_move, b_move;
    // a 배열 할당
    int j = n;
    for (int i = 0; i < n; i++)
    {
        a[i] = j--;
    }

    // b 배열 할당
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new int[2];
        tmp[i][0] = (1 + rand() % n);
        tmp[i][1] = i + 1;
    }
    int temp, temp_1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i) - 1; j++)
        {
            if (tmp[j][0] > tmp[j + 1][0])
            {
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
        b[i] = tmp[i][1];
    }

    mergesort(a, 0, n-1);
    a_cmp = my_cmp;
    a_move = my_move;
    my_cmp = 0, my_move = 0;
    mergesort(b, 0, n-1);
    b_cmp = my_cmp;
    b_move = my_move;

    cout << "SortedData_A: ";
    for (int i = 0; i < 20; i++)
        cout << a[i] << ' ';
    cout << "\nSortedData_B: ";
    for (int i = 0; i < 20; i++)
        cout << b[i] << ' ';
    cout << '\n';
    cout << "Compare_Cnt_A " << a_cmp << ", DataMove_Cnt_A " << a_move << '\n';
    cout << "Compare_Cnt_B " << b_cmp << ", DataMove_Cnt_B " << b_move << '\n';
}