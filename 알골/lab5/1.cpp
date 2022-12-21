#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef int itemType;
int my_move = 0, my_cmp = 0;
class MAKE_HEAP
{
private:
    itemType *a;
    int N;

public:
    MAKE_HEAP(int max)
    {
        a = new itemType[max];
        N = 0;
    }
    ~MAKE_HEAP() { delete a; }
    void swap(itemType a[], int i, int j)
    {
        int temp;
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
        my_move += 3;
    }
    void MakeHeap(itemType a[], int Root, int LastNode)
    {
        int Parent, LeftSon, RightSon, Son;
        itemType RootValue;
        Parent = Root;
        RootValue = a[Root];
        my_move++;
        LeftSon = 2 * Parent + 1;
        RightSon = LeftSon + 1;
        while (LeftSon <= LastNode)
        {
            if (RightSon <= LastNode && ++my_cmp && a[LeftSon] < a[RightSon])
            {
                Son = RightSon;
            }
            else
                Son = LeftSon;
            if (++my_cmp && RootValue < a[Son])
            {
                a[Parent] = a[Son];
                my_move++;
                Parent = Son;
                LeftSon = Parent * 2 + 1;
                RightSon = LeftSon + 1;
            }
            else
                break;
        }
        a[Parent] = RootValue;
        my_move++;
    }
    void heapsort(itemType a[], int N)
    {
        int i;
        for (i = N / 2; i >= 1; i--)
            MakeHeap(a, i - 1, N - 1);
        for (i = N - 1; i >= 1; i--)
        {
            swap(a, 0, i);
            MakeHeap(a, 0, i - 1);
        }
    }
};

int main()
{
    srand((unsigned int)time(NULL));

    int n;
    cin >> n;
    int **tmp = new int *[n];
    int *a = new int[n];
    int *b = new int[n];
    int *c = new int[n];
    MAKE_HEAP h(n);
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
        b[i] = tmp[i][1];
    }

    for(int i = 0; i < n; i++) {
        c[i] = (1+rand() % n);
    }

    h.heapsort(a, n);
    int a_cmp = my_cmp;
    int a_move = my_move;
    my_cmp = 0, my_move = 0;
    h.heapsort(b, n);
    int b_cmp = my_cmp;
    int b_move = my_move;
    my_cmp = 0, my_move = 0;
    h.heapsort(c, n);
    int c_cmp = my_cmp;
    int c_move = my_move;
    my_cmp = 0, my_move = 0;

    cout << "SortedData_A : ";
    for(int i = 0; i < 20; i++) {
        cout << a[i] << " ";
    }
    cout << endl << "SortedData_B : ";
    for(int i = 0; i < 20; i++) {
        cout << b[i] << " ";
    }
    cout << endl << "SortedData_C : ";
    for(int i = 0; i < 20; i++) {
        cout << c[i] << " ";
    }
    cout << "\nCompare_Cnt_A : " << a_cmp << ", DataMove_Cnt_A : " << a_move << endl;
    cout << "Compare_Cnt_B : " << b_cmp << ", DataMove_Cnt_B : " << b_move << endl;
    cout << "Compare_Cnt_C : " << c_cmp << ", DataMove_Cnt_C : " << c_move << endl;
}