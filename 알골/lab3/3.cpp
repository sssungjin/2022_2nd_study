#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
using namespace std;

typedef int itemType;
int my_cmp = 0, my_move = 0;
int Bubble(int sorted, itemType *a, int n)
{
    int temp;
    if (*(a - 1) > *a)  //비교
    {                    
        temp = *(a - 1); //이동
        my_move++;
        *(a - 1) = *a; //이동
        my_move++;
        *a = temp; //이동
        my_move++;
        sorted = false;
        my_cmp++;
    }
    return sorted;
}

void bubbleSort(itemType a[], int n)
{
    int i, Sorted;
    Sorted = false;
    while (!Sorted)
    {
        Sorted = true;
        for (i = 1; i < n; i++)
            Sorted = Bubble(Sorted, &a[i], n);
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
     bubbleSort(a, n);
    int a_cmp = my_cmp;
    int a_move = my_move;
    my_cmp = 0, my_move = 0;
    bubbleSort(b, n);
    int b_cmp = my_cmp;
    int b_move = my_move;            tmp[j + 1][1] = temp_1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = tmp[i][1];
    }

   

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