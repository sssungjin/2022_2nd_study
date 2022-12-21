#include <iostream>
using namespace std;

struct square {
    int point[4][2];
};
struct mypt {
    int poin[2];
};

int main()
{
    square box;
    int maxx = -21474836;
    int maxy = -21474836;
    int minx = 21474836;
    int miny = 21474836;
    int n; cin >> n;
    mypt pt[100];
    n = 8;
    for(int i = 0; i < n; i++) {
        cin >> pt[i].poin[0] >> pt[i].poin[1];
    }
    for(int i = 0; i < n; i++) {
        if(maxx < pt[i].poin[0])
            maxx = pt[i].poin[0];
        if(minx > pt[i].poin[0])
            minx = pt[i].poin[0];
    }
    for(int i = 0; i < n; i++) {
        if(maxy < pt[i].poin[1])
            maxy = pt[i].poin[1];
        if(miny > pt[i].poin[1])
            miny = pt[i].poin[1];
    }
    box.point[0][0] = minx;
    box.point[0][1] = miny;
    box.point[1][0] = minx;
    box.point[1][1] = maxy;
    box.point[2][0] = maxx;
    box.point[2][1] = maxy;
    box.point[3][0] = maxx;
    box.point[3][1] = miny;


    for(int i = 0; i < 4; i++) {
        cout << "x : " <<  box.point[i][0] << " y : " << box.point[i][1] << endl;
    }
}