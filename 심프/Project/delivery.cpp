#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct foodInfo {
    string food_name;
    int food_quantity;
};
foodInfo infoArr[11];
class Food {
private:
    int price;
    int number;
    string name;
public:
    Food() {
        price = 0;
        number = 0;
        name = "";
    }
    void setInfo(int food_number) {
        if (food_number == 1) {
            this->price = 8000;
            this->name = "돼지김치찌개";
        }
        else if (food_number == 2) {
            this->price = 7000;
            this->name = "국밥";
        }
        else if (food_number == 3) {
            this->price = 8000;
            this->name = "불고기백반";
        }
        else if (food_number == 4) {
            this->price = 5000;
            this->name = "자장면";
        }
        else if (food_number == 5) {
            this->price = 6000;
            this->name = "짬뽕";
        }
        else if (food_number == 6) {
            this->price = 14000;
            this->name = "탕수육";
        }
        else if (food_number == 7) {
            this->price = 10000;
            this->name = "돈카츠";
        }
        else if (food_number == 8) {
            this->price = 8000;
            this->name = "라멘";
        }
        else if (food_number == 9) {
            this->price = 12000;
            this->name = "파스타";
        }
        else if (food_number == 10) {
            this->price = 18000;
            this->name = "스테이크";
        }
    }
    void setNumber(int number) {
        this->number = number;
    }
    int getPrice() {
        return price * number;
    }
    string getName() {
        return name;
    }
    int getNum() {
        return number;
    }
};

class Delivery {
private:
    string id, login_id;    //회원가입할 아이디, 로그인할 아이디
    string pw, login_pw;
    string name;
    int sel;
    unsigned int total_price;
    int total_quantity;
    int time;
    unsigned int point;
    string grade;
public:
    Delivery() {
        this->point = 0;
        this->total_price = 0;
        this->total_quantity = 0;
        cout << "-----------배달 프로그램 실행----------";
        cout << "\n\n회원가입을 진행합니다.\n";
        Register();
        Login();
    }
    void Register() {
        cout << "이름을 입력하세요 : ";
        cin >> name;
        cout << "아이디를 입력하세요 : ";
        cin >> id;
        cout << "비밀번호를 입력하세요 : ";
        cin >> pw;
    }
    void Login() {

        cout << "\n로그인\n";
        while (1) {
            cout << "ID : ";
            cin >> login_id;
            cout << "PW : ";
            cin >> login_pw;
            cout << "\n";
            if (login_id == id && login_pw == pw) {
                cout <<  "\t" << name << "님 환영합니다.\n";
                break;
            }
            else if (login_id != id) {
                cout << "존재하지 않는 ID 입니다. 다시 입력해주세요\n";
            }
            else if (login_id == id && login_pw != pw) {
                cout << "비밀번호를 틀렸습니다. 다시 입력해주세요.\n";
            }
        }
        MainMenu();
    }
    void MainMenu() {
        cout << "\n-----------메인 메뉴----------\n";
        cout << "메뉴를 선택하세요\n";
        while (1) {
            select();
            if (sel == 6)
                break;
        }
    }
    void select() {
        cout << "1 : 회원 등급 확인\n2 : 포인트 충전 및 확인\n3 : 음식 메뉴\n4 : 장바구니 담기\n5 : 주문하기\n6 : 로그아웃\n";
        cout << "선택 : ";
        cin >> sel;
        cout << "\n";
        if (sel == 1) {
            checkGrade();

        }
        else if (sel == 2) {
            pointCharge();
        }
        else if (sel == 3) {
            viewList();
        }
        else if (sel == 4) {
            putBasket();
        }
        else if (sel == 5) {
            order();
        }
        else {
            cout << "로그아웃 중....\n";
        }
    }
    void checkGrade() {
        cout << "회원 등급을 확인합니다.\n\n";
        cout << "0 ~ 100000점         : 브론즈\n100001 ~ 500000점    : 실버\n500001 ~ 1000000점   : 골드\n";
        cout << "1000001 ~ 5000000점  : 플레티넘\n5000001점 이상       : 다이아몬드\n\n";
        if (point >= 0 && point <= 100000) {
            grade = "브론즈\n";
        }
        else if (point >= 100001 && point <= 500000) {
            grade = "실버\n";
        }
        else if (point >= 500001 && point <= 1000000) {
            grade = "골드\n";
        }
        else if (point >= 1000001 && point <= 5000000) {
            grade = "플레티넘\n";
        }
        else if (point >= 5000001) {
            grade = "다이아몬드\n";
        }
        cout << "나의 등급 : " << grade << endl;
    }
    void pointCharge() {
        unsigned int plus_point;
        while (1) {
            cout << "포인트 확인 : 1    포인트 충전 : 2 (나가고 싶으시다면 다른 문자를 입력하세요)\n";
            cin >> sel;
            if (sel == 1) {
                cout << "현재 포인트는 " << point << "입니다.\n";
            }
            else if (sel == 2) {
                cout << "포인트를 충전합니다.\n";
                cout << "충전할 금액을 입력하세요 : ";
                cin >> plus_point;
                point += plus_point;
                cout << "현재 포인트는 " << point << "점 입니다.\n";
            }
            else {
                break;
            }
        }
    }
    void viewList() {
        cout << " ------------한식----------------\n";
        cout << "| 1: 돼지김치찌개   - 가격 : 8000원 |\n";
        cout << "| 2: 국밥           - 가격 : 7000원 |\n";
        cout << "| 3: 불고기백반     - 가격 : 8000원 |\n";
        cout << " --------------------------------\n";
        cout << " ------------중식----------------\n";
        cout << "| 4: 자장면         - 가격 : 5000원 |\n";
        cout << "| 5: 짬뽕           - 가격 : 6000원 |\n";
        cout << "| 6: 탕수육         - 가격 : 14000원|\n";
        cout << " --------------------------------\n";
        cout << " ------------일식----------------\n";
        cout << "| 7: 돈카츠         - 가격 : 10000원|\n";
        cout << "| 8: 라멘           - 가격 : 8000원 |\n";
        cout << " --------------------------------\n";
        cout << " ------------양식----------------\n";
        cout << "| 9:  파스타         - 가격 : 12000원|\n";
        cout << "| 10: 스테이크       - 가격 : 18000원|\n";
        cout << " --------------------------------\n";
    }
    void putBasket() {
        int i = 0;
        Food arr[11];
        string foodName[11];
        int foodQuantity[11];
        while (1) {
            int food_num;
            int num;
            char quit;
            cout << "장바구니에 담을 음식 번호를 입력하세요 : ";
            cin >> food_num;
            arr[i].setInfo(food_num);
            cout << "수량을 입력하세요 : ";
            cin >> num;
            arr[i].setNumber(num);
            total_price += arr[i].getPrice();
            infoArr[i].food_name = arr[i].getName();
            infoArr[i].food_quantity = arr[i].getNum();
            total_quantity += infoArr[i].food_quantity;
            cout << infoArr[i].food_name << "을(를) " << infoArr[i].food_quantity << "개 담았습니다.\n";
            cout << "모두 담았다면 Q(q)를 입력 더 담고싶다면 아무 문자나 입력\n";
            i++;
            cin >> quit;
            if (quit == 'Q' || quit == 'q')
                break;
        }
        cout << "-----------------장바구니-----------------\n";
        for (int j = 0; j < i; j++) {
            cout << infoArr[j].food_name << " : " << infoArr[j].food_quantity << "개\n";
        }
        cout << "총 주문 금액 : " << total_price << endl;
        cout << "-----------------------------------------\n\n";

    }
    void order() {
        if (total_quantity == 0) {
            cout << "장바구니가 비어있습니다. 장바구니에 음식을 담은 후 주문해주세요.\n\n";
        }
        else {
            int option;
            char ans;
            cout << "1 : 포장\n2 : 배달 (다른 문자 입력 시 뒤로가기)\n";
            cout << "입력 : ";
            cin >> option;
            if (option == 1) {      //포장
                cout << "현재 포인트는 " << point << "입니다.\n";
                cout << name << "님의 총 주문금액은 " << total_price << "입니다.\n";
                cout << "주문 시 포인트가 주문금액 만큼 차감됩니다.\n";
                cout << "포장 주문 하시겠습니까? (주문하시려면 Y를 입력해주세요)";
                cout << "입력 : ";
                cin >> ans;
                if (ans == 'Y') {
                    if (point >= total_price) {
                        point -= total_price;
                        cout << "주문이 완료되었습니다.\n";
                        cout << "남은 포인트는 " << point << " 입니다.\n";
                        timer();
                        cout << "예상 포장 완료 시간은 " << time << "분 ~ " << time + 15 << "분" << "입니다.\n";
                    }
                    else {
                        cout << "포인트가 부족합니다. 포인트 충전 페이지로 전환됩니다.\n";
                        pointCharge();
                    }
                }
                else {
                    cout << "주문을 취소하셨습니다. 메인 메뉴로 돌아갑니다.\n";
                }
            }
            else if (option == 2) {     //배달
                cout << "현재 포인트는 " << point << "입니다.\n";
                cout << name << "님의 총 주문금액은 " << total_price << "원, 배달비 : 2000원 으로 총 결제금액은 " << total_price + 2000 << " 입니다.\n";
                cout << "주문 시 포인트가 주문금액 만큼 차감됩니다.\n";
                cout << "배달 주문 하시겠습니까? (주문하시려면 Y를 입력해주세요)\n";
                cout << "입력 : ";
                cin >> ans;
                if (ans == 'Y') {
                    if (point >= total_price) {
                        point -= total_price;
                        cout << "주문이 완료되었습니다.\n";
                        cout << "남은 포인트는 " << point << " 입니다.\n";
                        timer();
                        cout << "예상 도착 시간은 " << time + 15 << "분 ~ " << time + 30 << "분" << "입니다.\n\n\n";
                    }
                    else {
                        cout << "포인트가 부족합니다. 포인트 충전 페이지로 전환됩니다.\n";
                        pointCharge();
                    }
                }
                else {
                    cout << "주문을 취소하셨습니다. 메인 메뉴로 돌아갑니다.\n";
                }
            }
        }
    }
    void timer() {  //음식 준비 시간 계산
        if (total_quantity <= 2) {
            time = 15;
        }
        else if (total_quantity <= 5) {
            time = 30;
        }
        else if (total_quantity <= 10) {
            time = 45;
        }
        else {
            time = 60;
        }
    }
};


int main()
{
    Delivery d;
}