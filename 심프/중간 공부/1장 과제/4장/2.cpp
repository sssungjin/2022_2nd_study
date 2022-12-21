#include <iostream>
using namespace std;

class BankClient{
private:
    string name;
    int num, balance;
    
public:
    BankClient() {
        cout << "예금주 : ";
        cin >> name;
        coun << "계좌 번호 : ";
        cin >> num;
        cout << "잔액 : ";
        cin >> balance;
    }
    void change() {
        char c;
        cin >> c;
        if(c == "w")
            
    }

};