#include <iostream>
using namespace std;

class BankClient {
private:
	string name;
	int num;
	int balance;
public:
	BankClient() {
		cout << "예금주 : ";
		cin >> name;	//예금주 이름 입력
		cout << "계좌 번호 : ";
		cin >> num;	//계좌 번호 입력
		cout << "잔액 : ";
		cin >> balance;	//잔액 입력
	}
	~BankClient() {
		cout << "\n※ 객체가 소멸되었습니다.\n";
	}
	int deposit(int a) {	//예금 할 금액을 매개변수로 
		balance += a;	//매개변수를 잔액에 더함
		return balance;
	}
	int withdraw(int a) {	//인출 할 금액 매개변수
		balance -= a;	//매개변수 잔액에서 뺌
		return balance;
	}
	void printInfo() {		//예금주, 계좌번호, 잔액 출력 
		if (1) {	
			cout << '\n';
		}
		cout << "예금주 : " << name << '\n';
		cout << "계좌 번호 : " << num << '\n';
		cout << "잔액 : " << balance << "\n";
	}
};

int main() {
	BankClient bc;
	bc.deposit(32165);
	bc.printInfo();
	bc.withdraw(12356);
	bc.printInfo();
}