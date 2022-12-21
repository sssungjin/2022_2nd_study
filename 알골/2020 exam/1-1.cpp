#include <iostream>
using namespace std;

struct point {
    int x;
    int y;
};
struct rect {
    point pt[4];
};
struct circle {
    point pt;
    int rad;
};
int isInSide(rect re, circle c) {
    int flag = 1;
    for(int i = 0; i < 4; i++) {
        if((re.pt[i].x - c.pt.x)*(re.pt[i].x - c.pt.x) + (re.pt[i].y - c.pt.y) * (re.pt[i].y - c.pt.y) > c.rad*c.rad) {
            flag = 0;
        }
    }
    return flag;
}

// bool isInside(circle c, rect r) {
//    bool flag = true;
//    for (int i = 0; i < 4; i++) {
//       if ((r.pt[i].x - c.pt.x)*(r.pt[i].x - c.pt.x) + (r.pt[i].y - c.pt.y)*(r.pt[i].y - c.pt.y)
//    > c.rad*c.rad)
//          flag = false;
//    }

//    return flag;
// }
int main()
{
    rect re;
    circle c;
    
    cout << "원 x y 반지름 입력\n";
    cin >> c.pt.x >> c.pt.y >> c.rad;
    cout << "사각형의 네 점 입력\n";
    for(int i = 0; i < 4; i++) {
        cin >> re.pt[i].x >> re.pt[i].y;
    }

    cout << isInSide(re, c);

}
