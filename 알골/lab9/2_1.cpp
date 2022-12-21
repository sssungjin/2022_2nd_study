#include <iostream>
#include <climits>
using namespace std;
#define Nmax 100
struct point
{
    char c;
    int x, y;
    float tangent;
};
struct line
{
    struct point p1, p2;
};
struct point polygon[Nmax]; 
struct line lines[Nmax];
typedef struct point itemType;

bool IsPointInside(int x, int y, int size){
    //count는 점q의 검사선과 다각형과의 교점의 개수
    int count = 0;
    for(int i = 0 ; i < size; i++){
        int j = (i+1)%size;
        //점 B가 선분 (p[i], p[j])의 y좌표 사이에 있음
        if((polygon[i].y > y) != (polygon[j].y > y) ){
            //atX는 점 B를 지나는 수평선과 선분 (p[i], p[j])의 교점
            double atX = (polygon[j].x- polygon[i].x) * (y-polygon[i].y)/(polygon[j].y-polygon[i].y)+polygon[i].x;
            //atX가 오른쪽 반직선과의 교점이 맞으면 교점의 개수를 증가시킨다.
            if(x < atX)
                count++;
        }
    }
    cout << "count : " << count << endl; 
    return (count % 2 == 1);
}

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
            if (RightSon <= LastNode && a[LeftSon].tangent < a[RightSon].tangent)
            {
                //각 비교 횟수
                Son = RightSon;
            }
            else
                Son = LeftSon;
            if (RootValue.tangent < a[Son].tangent)
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

float ComputeAngle(struct point p1, struct point p2)
{
    int dx, dy, ax, ay;
    float t;
    dx = p2.x - p1.x;
    ax = abs(dx);
    dy = p2.y - p1.y;
    ay = abs(dy);
    t = (ax + ay == 0) ? 0 : (float)dy / (ax + ay);
    if (dx < 0)
        t = 2 - t;
    else if (dy < 0)
        t = 4 + t;
    return t * 90.0;
}

int main()
{
    point Z;
    int n;
    cin >> n >> Z.x >> Z.y;
    float *P = new float[n];
    MAKE_HEAP h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> polygon[i].c >> polygon[i].x >> polygon[i].y;
    }
    int x, y, minIdx, minX = 100, minY = 100;
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
    for (int i = 0; i < n; i++)
    {
        polygon[i].tangent = ComputeAngle(polygon[minIdx], polygon[i]);
    }
    h.heapsort(polygon, n);
    polygon[n] = polygon[0];

    cout << "다형각이 만들어지는 순서 : ";
    for (int i = 0; i < n; i++)
    {   
        if(i == (n-1)) {
            cout << polygon[i].c;
            break;
        }
        cout << polygon[i].c << " - ";
    }
    cout << endl;
    if(IsPointInside(Z.x, Z.y, n))
    cout << "True\n";
    else
    cout << "False\n";
}

/*
8 3 5 
A 3 4
B 1 2
C 2 5
D 2 6
E 9 3
F 5 3
G 6 4
H 8 7

A 2 1
B 4 6
C 11 1
D 4 4
E 1 4
*/