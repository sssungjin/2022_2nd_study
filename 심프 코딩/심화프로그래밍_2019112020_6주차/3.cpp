#include <iostream>
using namespace std;
int num = 1;	//객채를 생성,소멸할 때 몇번째 구인지 출력하기 위한 전역변수

class Sphere {
private:
	int rad;	//반지름
	int number;	//몇번째 구인지 저장할 변수
public:
	float volume;	//부피, main함수에서 받아와 비교하기 위해 public부분에 선언
	Sphere() {
		rad = 0;	//반지름 초기화
		volume = 0;	//부피 초기화
		this->number = num++;	//이 객체의 number변수에 num을 넣기 위해 this 이용 
		cout << "구 객체 생성" << number << endl;	//객체가 생성되면 num++를 통해 다음 구의 번호 증가
	}
	void setRadius(int rad) {
		this->rad = rad;	//매개변수로 받은 rad를 클래스 변수 rad에 넣기 위해 this이용
	}
	void setVolume() {
		volume = (4 * 3.14 * rad * rad * rad)/3;	//volume 값 구해줌
	}
	~Sphere() {
		cout << "구 객체 소멸" << number << endl;	//소멸될 때 객체의 number변수를 통해 몇번째 구 소멸됐는지 확인
		
	}
};

int main()
{
	Sphere* s = new Sphere[5];	//5개 객체배열 동적할당
	int up = 0, down = 0;	//부피 765이상 이하 개수 구 저장하기 위한 변수
	cout << endl;

	float input;	//입력 받을 반지름 임시로 저장하기 위한 변수
	for (int i = 0; i < 5; i++) {
		cout << "구 " << i+1 << "의 반지름 >> ";
		cin >> input;
		s[i].setRadius(input);	//매개변수로 받은 input 값을 rad에 저장
		s[i].setVolume();	//저장된 클래스 변수 rad이용해 volume 저장
	}

	for (int i = 0; i < 5; i++) {
		if (s[i].volume >= 765)	//각각 객체에 저장된 volume값이 765보다 크거나 같은지
			up++;	//크다면 up++
		else
			down++;	//작다면 down++
	}

	cout << "\n구의 부피가 765cm3 이상인 큰 구는 " << up << "개 입니다\n";	//up변수를 통해 765보다 큰 객체 개수 출력
	cout << "구의 부피가 765cm3 이하인 작은 구는 " << down << "개 입니다\n\n";	//down변수를 통해 765보다 작은 객체 개수 출력

	delete[] s;	//동적할당 해제
}