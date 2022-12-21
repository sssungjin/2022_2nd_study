#include <iostream>
using namespace std;

class Time {
    int hour, minute, second;
    public:
    Time() {
        cout << "몇 시?";
        cin >> hour;
        cout << "몇 분?";
        cin >> minute;
        cout << "몇 초?";
        cin >> second;
    }
    void print()
    {
        cout << "입력한 시간 = ";
        if(hour < 10)
            cout << "0" << hour << ":";
        else
            cout << hour << ":";
        if(minute < 10)
            cout << "0" << minute << ":";
        else
            cout << minute << ":";
        if(second < 10)
            cout << "0" << second << ":";
        else
            cout << second << ":";
    }
    void change() {
        cout << "시간을 초로 변환 = " << hour*3600+minute*60 + second;
    }
};
