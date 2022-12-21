#include <iostream>
using namespace std;

class Chicken {
private:
	int price;	//치킨 한마리당 가격
	int whole_chicken;	//하루동안 튀길 수 있는 치킨의 개수
	int balance;	//구매자의 치킨을 구매하기전 잔액
	int rest_chicken;	//남은 치킨 마리수
	int profit;	//판매수익
	int chicken_fried;	//튀긴 치킨 마리수
public:
	Chicken() 
	{	
		price = 19000;	//치킨 한마리당 가격을 19000으로 설정
		whole_chicken = 60;	//하루동안 튀길 수 있는 전체 치킨의 개수를 60으로 설정
		balance = 200000;	//구매자의 치킨 구매 전 잔액을 200000으로 설정
	}
	void Seller() {
		cout << "치킨판매자 현황\n";
		cout << "남은 치킨 : ";	//출력화면에 맞게 각각 출력
		cin >> rest_chicken;	//남은 치킨을 입력 받는다.
		profit = price * (whole_chicken - rest_chicken);	//판매 수익은 치킨 가격 * 튀긴 치킨 마리수(하루동안 튀길 수 있는 치킨 마리수 - 남은 치킨)
		cout << "판매 수익 : " << profit << '\n';	//판매 수익을 출력
	}
	void Buyer() {
		cout << "\n치킨구매자 현황\n";
		cout << "현재 잔액 : " << balance - profit << '\n';	//전체 잔액 - 판매 이익을 계산하여 현재 잔액 출력
		chicken_fried = whole_chicken - rest_chicken;	//구매한 치킨 마리수는 전체 치킨 - 남은 치킨
		cout << "치킨 개수 : " << chicken_fried;	//구매한 치킨 마리수를 계산한 값을 출력
	}
};

int main() {
	Chicken chicken;	//chicken 객체 생성
	chicken.Seller();	//Seller 함수 호출 통해 치킨판매자 현황을 출력
	chicken.Buyer();	//Buyer 함수 호출 통해 치킨구매자 현황을 출력
}