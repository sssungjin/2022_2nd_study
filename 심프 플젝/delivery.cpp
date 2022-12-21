#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct foodInfo {           //음식 정보 저장하는 구조체
    string food_name;
    int food_quantity;
};
foodInfo infoArr[1000];
class Food {    //장바구니에 음식을 담을 때 입력한 번호를 통해 음식 정보 저장
private:
    int price;  //음식 1개당 가격
    int number; //음식 개수
    string name;    //음식 이름
public:
    Food() {
        price = 0;
        number = 0;
        name = "";
    }
    void setInfo(int food_number) { //입력받은 번호를 매개변수로 음식 정보 세팅
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
    int getPrice() {    //개수만큼 가격 반환
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
    string pw, login_pw;    //회원가입할 비밀번호, 로그인할 때 비밀번호
    string name;            //사용자 이름
    int sel;                //메뉴 선택할 때 사용
    int i;                  //음식 담은 횟수 
    int total_price;   
    int total_quantity;
    int time;
    int point;
    int tier_point;
    string grade;
public:
    Delivery() {    //변수 초기화 및 프로그램 실행
        this->tier_point = 0;
        this->point = 0;
        this->total_price = 0;
        this->total_quantity = 0;
        this->i = 0;
        this->grade = "브론즈";
        cout << "\t-----------배달 프로그램 실행----------";
        cout << "\n\n\t회원가입을 진행합니다.\n";
        Register();
        Login();
    }
    void Register() {   //회원가입
        cout << "\t이름을 입력하세요 : ";
        getline(cin, name);
        cout << "\t아이디를 입력하세요 : ";
        cin >> id;
        cout << "\t비밀번호를 입력하세요 : ";
        cin >> pw;
    }
    void Login() {  // 로그인
        cout << "\n\t로그인\n";
        while (1) {
            cout << "\tID : ";
            cin >> login_id;
            cout << "\tPW : ";
            cin >> login_pw;
            cout << "\n";
            if (login_id == id && login_pw == pw) {
                cout <<  "\t" << name << "님 환영합니다.\n";
                break;
            }
            else if (login_id != id) {
                cout << "\t존재하지 않는 ID 입니다. 다시 입력해주세요\n";
            }
            else if (login_id == id && login_pw != pw) {
                cout << "\t비밀번호를 틀렸습니다. 다시 입력해주세요.\n";
            }
        }
        MainMenu();
    }
    void MainMenu() {   //메인메뉴 출력
        cout << "\n\t-----------메인 메뉴----------\n";
        cout << "\t메뉴를 선택하세요\n";
        while (1) {
            select();
            if (!(sel >= 1 && sel <= 6))
                break;
        }
    }
    void select() { //메뉴 선택
        cout << "\t1 : 회원 등급 확인\n\t2 : 포인트 충전 및 확인\n\t3 : 음식 메뉴\n\t4 : 장바구니 담기\n\t5 : 주문하기\n\t6 : 장바구니 확인\n\t다른 숫자를 입력해 로그아웃\n";
        cout << "\t선택 : ";
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
        else if (sel == 6) {
            showBasket();
        }
        else {
            cout << "\t\t로그아웃 중....\n";
        }
    }
    void checkGrade() { //회원등급 확인
        cout << "\t회원 등급을 확인합니다.\n\n";
        cout << "\t0       ~ 100000점   : 브론즈\n\t100001  ~ 500000점   : 실버\n\t500001  ~ 1000000점  : 골드\n";
        cout << "\t1000001 ~ 5000000점  : 플레티넘\n\t5000001점 이상       : 다이아몬드\n\n";
        cout << "\t나의 등급 :  " << grade;
        cout << "\t나의 포인트 :\t" << tier_point << "\n\n";

    }
    void setGrade() {   //등급 설정
        if (tier_point >= 0 && tier_point <= 100000) {
            grade = "브론즈";
        }
        else if (tier_point >= 100001 && tier_point <= 500000) {
            grade = "실버";
        }
        else if (tier_point >= 500001 && tier_point <= 1000000) {
            grade = "골드";
        }
        else if (tier_point >= 1000001 && tier_point <= 5000000) {
            grade = "플레티넘";
        }
        else if (tier_point >= 5000001) {
            grade = "다이아몬드";
        }
    }
    void pointCharge() {    //포인트 충전 
        int plus_point;
        while (1) {
            cout << "\t포인트 확인 : 1    포인트 충전 : 2 (나가고 싶으시다면 다른 숫자를 입력하세요)\n";
            cout << "\t입력 : ";
            cin >> sel;
            if (sel == 1) {
                cout << "\t현재 포인트는 " << point << "입니다.\n\n";
            }
            else if (sel == 2) {
                cout << "\t포인트를 충전합니다.\n";
                cout << "\t충전할 금액을 입력하세요 : ";
                cin >> plus_point;
                point += plus_point;
                tier_point += plus_point;
                cout << "\t현재 포인트는 " << point << "점 입니다.\n\n";
                setGrade();
            }
            else {
                break;
            }
        }
    }
    void viewList() {   //음식 메뉴 출력
        cout << "\t●--------------한식----------------●\n";
        cout << "\t| 1: 돼지김치찌개   -  가격 : 8000원 |\n";
        cout << "\t| 2: 국밥           -  가격 : 7000원 |\n";
        cout << "\t| 3: 불고기백반     -  가격 : 8000원 |\n";
        cout << "\t●----------------------------------●\n\n";
        cout << "\t○--------------중식----------------○\n";
        cout << "\t| 4: 자장면         -  가격 : 5000원 |\n";
        cout << "\t| 5: 짬뽕           -  가격 : 6000원 |\n";
        cout << "\t| 6: 탕수육         -  가격 : 14000원|\n";
        cout << "\t○----------------------------------○\n\n";
        cout << "\t◎--------------일식----------------◎\n";
        cout << "\t| 7: 돈카츠         -  가격 : 10000원|\n";
        cout << "\t| 8: 라멘           -  가격 : 8000원 |\n";
        cout << "\t◎----------------------------------◎\n\n";
        cout << "\t⊙--------------양식-----------------⊙\n";
        cout << "\t| 9:  파스타        -  가격 : 12000원|\n";
        cout << "\t| 10: 스테이크      -  가격 : 18000원|\n";
        cout << "\t⊙-----------------------------------⊙\n\n";
    }
    void putBasket() {  //음식 번호를 통해 장바구니에 음식 담기
        Food arr[100];
        while (1) {
            int food_num;
            int num;
            char quit;
            cout << "\t장바구니에 담을 음식 번호를 입력하세요 : ";
            cin >> food_num;
            if (food_num >= 1 && food_num <= 10) {
                arr[i].setInfo(food_num);
                cout << "\t수량을 입력하세요 : ";
                cin >> num;
                arr[i].setNumber(num);
                total_price += arr[i].getPrice();
                infoArr[i].food_name = arr[i].getName();
                infoArr[i].food_quantity = arr[i].getNum();
                total_quantity += infoArr[i].food_quantity;
                cout << "\t" << infoArr[i].food_name << "을(를) " << infoArr[i].food_quantity << "개 담았습니다.\n\n";
                cout << "\t모두 담았다면 Q(q)를 입력, 더 담고싶다면 아무 문자나 입력 : ";
                i++;
                cin >> quit;
                cout << endl;
                if (quit == 'Q' || quit == 'q')
                    break;
            }
            else
                cout << "\t잘못된 메뉴 번호 입니다.\n";
        }
        showBasket();
    }
    void order() {  //주문하기
        if (total_quantity == 0) {
            cout << "\t장바구니가 비어있습니다. 장바구니에 음식을 담은 후 주문해주세요.\n\n";
        }
        else {
            int option;
            char ans;
            cout << "\t1 : 포장\n\t2 : 배달 (다른 숫자 입력 시 뒤로가기)\n";
            cout << "\t입력 : ";
            cin >> option;
            if (option == 1) {      //포장
                cout << "\t현재 포인트는 " << point << "입니다.\n";
                cout << "\t" << name << "님의 총 주문금액은 " << total_price << "입니다.\n";
                showBasket();
                cout << "\t주문 시 포인트가 주문금액 만큼 차감됩니다.\n";
                cout << "\t포장 주문 하시겠습니까? (주문하시려면 Y/y를 입력해주세요)\n";
                cout << "\t입력 : ";
                cin >> ans;
                if (ans == 'Y' || ans == 'y') {
                    if (point >= total_price) {
                        point -= total_price;
                        cout << "\t주문이 완료되었습니다.\n";
                        cout << "\t남은 포인트는 " << point << " 입니다.\n";
                        timer();
                        cout << "\t예상 포장 완료 시간은 " << time << "분 ~ " << time + 5 << "분" << "입니다.\n\n\n";
                        clearBasket();
                    }
                    else {
                        cout << "\t포인트가 부족합니다. 포인트 충전 페이지로 전환됩니다.\n";
                        pointCharge();
                    }
                }
                else {
                    cout << "\t주문을 취소하셨습니다. 메인 메뉴로 돌아갑니다.\n";
                }
            }
            else if (option == 2) {     //배달
                cout << "\t현재 포인트는 " << point << "입니다.\n";
                cout << "\t" << name << "님의 총 주문금액은 " << total_price << "원, 배달비 : 2000원 으로 총 결제금액은 " << total_price + 2000 << " 입니다.\n";
                showBasket();
                cout << "\t주문 시 포인트가 주문금액 만큼 차감됩니다.\n";
                cout << "\t배달 주문 하시겠습니까? (주문하시려면 Y를 입력해주세요)\n";
                cout << "\t입력 : ";
                cin >> ans;
                if (ans == 'Y' || ans == 'y') {
                    if (point >= total_price) {
                        point -= total_price + 2000;
                        cout << "\t주문이 완료되었습니다.\n";
                        cout << "\t남은 포인트는 " << point << " 입니다.\n";
                        timer();
                        cout << "\t예상 도착 시간은 " << time + 15 << "분 ~ " << time + 30 << "분" << "입니다.\n\n\n";
                        clearBasket();

                    }
                    else {
                        cout << "\t포인트가 부족합니다. 포인트 충전 페이지로 전환됩니다.\n";
                        pointCharge();
                    }
                }
                else {
                    cout << "\t주문을 취소하셨습니다. 메인 메뉴로 돌아갑니다.\n\n";
                }
            }
        }
        //주문 끝나면 장바구니 삭제하기
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
    void clearBasket() {    //장바구니 초기화
        //i는 장바구니에 음식 담은 횟수, i만큼 반복해서 장바구니 음식 모두 초기화
        for (int idx = 0; idx < i; idx++) {
            infoArr[idx].food_name = "";
            infoArr[idx].food_quantity = 0;
        }
        total_price = 0;
        total_quantity = 0;
        i = 0;
    }
    void showBasket() { //장바구니 출력
        if (total_quantity == 0) {
            cout << "\t장바구니가 비어있습니다. 음식을 먼저 담아주세요.\n\n";
        }
        else {
            cout << "\t-----------------장바구니-----------------\n";
            for (int j = 0; j < i; j++) {
                cout << "\t" << infoArr[j].food_name << " : " << infoArr[j].food_quantity << "개\n";
            }
            cout << "\t총 주문 금액 : " << total_price << endl;
            cout << "\t-----------------------------------------\n\n";
        }
    }
};


int main()
{
    Delivery d;
}