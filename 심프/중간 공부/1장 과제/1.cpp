#include <iostream>
using namespace std;

int main() 
{
    string name, msg;
    int num, date;

    cin >> name >> num >> date >> msg;

    for(int i = 0; i < 10; i++) {
        cout << name << num << date << msg << endl;
    }
}