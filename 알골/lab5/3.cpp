#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef int itemType;

typedef struct node *node_pointer;
struct node {
    itemType value;
    node_pointer next;
};

node_pointer TABLE[10], x, z, temp;
int my_move = 0, my_cmp = 0;

void radixSort(itemType *a, int n)
{
    int i, j, cnt, radix, radix_mod = 10, cipher = 0;
    i = n;
    while (i > 0)
    {
        i = i / 10;
        cipher++;
    } // cipher : 입력 데이터의 자리수 (ex. 450 -> 3)
    for (i = 0; i < cipher; i++)
    {
        for (j = 0; j < n; j++)
        {
            cnt = 0;
            radix = (a[j] % radix_mod) / (radix_mod / 10);
            /* radix_mod = 10 이면 radix는 a[j]의 일의 자리수
           radix_mod = 100 이면 radix는 a[j]의 십의 자리수 */
            temp = new node;
            temp->value = a[j];
            my_move++;
            temp->next = z;
            if (TABLE[radix] == z)
            {
                // z는 list의 끝을 확인하기 위한 노드 포인터 (NULL에 해당)
                TABLE[radix] = temp;
            }
            else
            {
                x = TABLE[radix];
                while (x->next != z)
                {
                    x = x->next;
                }
                x->next = temp;
            }
            //my_move++;
        }

        for (j = 0; j < 10; j++)
        {
            if (TABLE[j] != z)
            {
                x = TABLE[j];
                while (x != z)
                {
                    a[cnt++] = x->value;
                    my_move++;
                    temp = x; // 메모리에서 노드를 삭제하기 위해 임시 저장
                    x = x->next;
                    delete temp; // 배열에 이미 넣은 노드를 메모리에서 삭제
                }
            }
            TABLE[j] = z;
        }
        radix_mod *= 10;
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
    int *c = new int[n];
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

    radixSort(a, n);
    int a_cmp = my_cmp;
    int a_move = my_move;
    my_cmp = 0, my_move = 0;
    radixSort(b, n);
    int b_cmp = my_cmp;
    int b_move = my_move;
    my_cmp = 0, my_move = 0;
    radixSort(c, n);
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