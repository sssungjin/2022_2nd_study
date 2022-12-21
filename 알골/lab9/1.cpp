#include <iostream>
using namespace std;
#define Nmax 100
struct point { char c; int x, y; float tangent; };
struct line { struct point p1, p2; };
struct point polygon[Nmax]; 
typedef struct point itemType;
int my_cmp2 = 0, my_cmp = 0;

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
        itemType temp;
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
    void MakeHeap(itemType a[], int Root, int LastNode)
    {
        int Parent, LeftSon, RightSon, Son;
        itemType RootValue;
        Parent = Root;
        RootValue = a[Root];
        LeftSon = 2 * Parent + 1;
        RightSon = LeftSon + 1;
        while (LeftSon <= LastNode)
        {
            if (RightSon <= LastNode && ++my_cmp && a[LeftSon].tangent < a[RightSon].tangent)
            {
                //각 비교 횟수
                Son = RightSon;
            }
            else
                Son = LeftSon;
            if (++my_cmp && RootValue.tangent < a[Son].tangent)
            {
                a[Parent] = a[Son];
                Parent = Son;
                LeftSon = Parent * 2 + 1;
                RightSon = LeftSon + 1;
            }
            else
                break;
        }
        a[Parent] = RootValue;
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

float ComputeAngle(struct point p1, struct point p2){ 
    int dx, dy, ax, ay;
    float t;
    dx = p2.x - p1.x; ax = abs(dx);
    dy = p2.y - p1.y; ay = abs(dy);
    t = (ax+ay == 0) ? 0 : (float) dy/(ax+ay);
    //my_cmp2++;  //수평각 계산 횟수
    if (dx < 0) t = 2-t; else if (dy < 0) t = 4+t;
    my_cmp2++;
    return t*90.0;
}

int main()
{
    int n; cin >> n;
    //float *P = new float[n];
    MAKE_HEAP h(n);
    for(int i = 0; i < n; i++)
    {
        cin >> polygon[i].c >> polygon[i].x >> polygon[i].y;
    }
    int x, y, minIdx, minX = 400, minY = 400;
    for (int i = 0; i < n; i++)
    {
        x = polygon[i].x;
        y = polygon[i].y;
        if ((minY > y) || (minY == y && minX > x))
        {
            minIdx = i;
            minX = x;
            minY = y;
        }
    }
    for(int i = 0; i < n; i++) {
        polygon[i].tangent = ComputeAngle(polygon[minIdx], polygon[i]);
    }

    h.heapsort(polygon, n);
    polygon[n] = polygon[0];

    cout << "다형각이 만들어지는 순서 : ";
    for (int i = 0; i < n; i++)
    {   
        if(i == (n - 1)) {
            cout << polygon[i].c;
            break;
        }
        cout << polygon[i].c << " - ";
    }
    cout << "\n";
    cout << my_cmp2 << " (수평각 계산 횟수)\n" << my_cmp << " (각의 비교 횟수)" << endl;
}

/*
5
A 1 8
B 7 4
C 3 5
D 2 6
E 7 2
*/