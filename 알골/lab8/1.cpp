#include <iostream>
#include <string>
using namespace std;
int D[1001][1001];


int min(int a, int b, int c)
{
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else if(c <= a && c <= b) return c;
}

int EditDist(int n, string X, int m, string Y, int ins, int del, int chg) {
	// n : X의 길이, m : Y의 길이, ins : 삽입비용, del : 삭제비용, chg : 변경비용
	D[0][0] = 0;
	int c;

	for (int i = 1; i < n + 1; i++)
		D[i][0] = D[i - 1][0] + del;	//첫 열의 초기화
	for (int j = 1; j < m + 1; j++)
		D[0][j] = D[0][j - 1] + ins;	// 첫 행의 초기화

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
		     c = (X[i-1] == Y[j-1]) ? 0 : chg;
		     D[i][j] = min(D[i - 1][j] + del, D[i][j - 1] + ins, D[i - 1][j - 1] + c);
		}
	}
	return D[n][m];
}


int main()
{
	string x, y;
	cout << "초기 문자열을 입력하시오 : ";
	cin >> x;
	cout << "목표 문자열을 입력하시오 : ";
	cin >> y;
	cout << "최소 편집 비용 : " << EditDist(x.length(), x, y.length(), y, 1, 1, 2) << endl;
	cout << "\n-----------편집 거리 테이블--------------\n";
	
	for(int i = 0; i <= x.length(); i++) {
		for(int j = 0; j <= y.length(); j++) {
			cout << D[i][j] << " \t";
		}
		cout << "\n";
	}
}

