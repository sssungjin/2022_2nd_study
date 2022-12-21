#include <iostream>
using namespace std;

class CRect
{
private:
    int left, top, right, bottom;

public:
    void print();
    void SetRect(int l, int t, int r, int b);
};

void CRect::print()
{
    cout << "(" << left << "," << top << "," << right << "," << bottom << ")" << endl;
}

void CRect::SetRect(int l, int t, int r, int b)
{
    left = l;
    right = r;
    top = t;
    bottom = b;
}

int main()
{
    CRect rc;
    rc.SetRect(0, 0, 20, 20);
    rc.print();
}