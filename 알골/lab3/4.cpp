#include <iostream>
using namespace std;
typedef int itemType;

int bubble_weight = 0, insertion_weight = 0, shell_weight = 0;
int Bubble(int sorted, itemType *a, int n)
{
    int temp;
    if (*(a - 1) > *a)  
    {                    
        temp = *a; 
        bubble_weight += temp;
        *a = *(a - 1); 
        bubble_weight += *(a - 1);
        *(a - 1) = temp;
        bubble_weight += temp;
        sorted = false;
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

void insertionSort(itemType a[],  int n)
{ 
    int i, j;
    itemType v;
	for (i = 1; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (a[j] > v && j >= 0) {
			a[j + 1] = a[j];
            insertion_weight += a[j];
			j--;
		}
		a[j + 1] = v; 
        insertion_weight += 2*v;
	}
}

void shellSort(itemType a[], int n)
{
    int i, j, h;
    itemType v;
    h = 1;
    do
        h = 3 * h + 1;
    while (h < n);
    do
    {
        h = h / 3;
        for (i = h; i < n; i++)
        {
            v = a[i];
            shell_weight += a[i];
            j = i;
            while (a[j - h] > v)    
            {
                a[j] = a[j - h];    
                shell_weight += a[j - h];
                j -= h;
                if (j <= h - 1)
                    break;
            }
            a[j] = v;
            shell_weight += v;
        }
    } while (h > 1);
}

int main() {
    int n; cin >> n;
    int *bubble = new int[n];
    int *insertion = new int[n];
    int *shell = new int[n];

    int j = n;
    for (int i = 0; i < n; i++)
    {
        bubble[i] = j--;
    }
    j = n;
    for (int i = 0; i < n; i++)
    {
        insertion[i] = j--;
    }
    j = n;
    for (int i = 0; i < n; i++)
    {
        shell[i] = j--;
    }

    bubbleSort(bubble, n);
    insertionSort(insertion, n);
    shellSort(shell, n);
    cout << "Insertion Sort : " << insertion_weight << '\n';
    cout << "Bubble Sort : " << bubble_weight << '\n';
    cout << "Shell Sort : " << shell_weight << '\n';
}  