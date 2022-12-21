#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
using namespace std;

typedef int itemType;
int my_cmp = 0, my_move = 0;
inline void swap(itemType a[], int i, int j)
{
    itemType t = a[i];
    my_move++;
    a[i] = a[j];
    my_move++;
    a[j] = t;
    my_move++;
}
int partition(itemType a[], int l, int r)
{
    int i, j;
    itemType v;
    if (r > l)
    {
        v = a[l];   //기준
        i = l;
        j = r + 1;
        for (;;)
        {
            while (++i <= r && ++my_cmp && (a[i] < v) )
                ;
            while (--j > l && ++my_cmp  && (a[j] > v) )
                ;
            if (i >= j)
                break;
            swap(a, i, j);
        }
        swap(a, j, l);
    }
    return j;
}

void quicksort(itemType a[], int l, int r)
{
    int j;
    if (r > l)
    {
        j = partition(a, l, r);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    int n;
    cin >> n;
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

    quicksort(a, 0, n-1);
    a_cmp = my_cmp;
    a_move = my_move;
    my_cmp = 0, my_move = 0;
    quicksort(b, 0, n-1);
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