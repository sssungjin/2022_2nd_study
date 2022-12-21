#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
using namespace std;

typedef int itemType;

int *shellSort(itemType a[], int n)
{
    int i, j, h;
    itemType v;
    h = 1;
    int *arr = new int[2];
    arr[0] = 0, arr[1] = 0;
    do
        h = 3 * h + 1;
    while (h < n);
    do
    {
        h = h / 3;
        for (i = h; i < n; i++)
        {
            v = a[i]; //이동
            arr[0]++;
            j = i;
            while (++arr[1] && (a[j - h] > v)) //비교
            {
                //arr[1]++;
                a[j] = a[j - h]; //이동
                arr[0]++;
                j -= h;
                if (j <= h - 1)
                    break;
            }
            a[j] = v; //이동
            arr[0]++;
        }
    } while (h > 1);

    return arr;
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
                tmp[j + 1][1] = temp_1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = tmp[i][1];
    }

    int *a_info = shellSort(a, n);
    int *b_info = shellSort(b, n);

    cout << "SortedData_A: ";
    for (int i = 0; i < 20; i++)
        cout << a[i] << ' ';
    cout << "\nSortedData_B: ";
    for (int i = 0; i < 20; i++)
        cout << b[i] << ' ';
    cout << '\n';
    cout << "Compare_Cnt_A " << a_info[1] << ", DataMove_Cnt_A " << a_info[0] << '\n';
    cout << "Compare_Cnt_B " << b_info[1] << ", DataMove_Cnt_B " << b_info[0] << '\n';
}