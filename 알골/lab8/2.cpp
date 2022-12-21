#include <iostream>
#include <string>
using namespace std;
int D[1001][1001];
int path[1001][1001];
char op[1001][1001];

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
    for(int j = 0; j < m + 1; j++)
        op[0][j] = 'I';
    for(int i = 0; i < n + 1; i++)
        op[i][0] = 'D';
    op[0][0] = 'O';

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
		     c = (X[i-1] == Y[j-1]) ? 0 : chg;
		     D[i][j] = min(D[i - 1][j] + del, D[i][j - 1] + ins, D[i - 1][j - 1] + c);
            
        }
	}
	return D[n][m];
}

int *stack = 0;
int top = -1;

void stack_push(int op)
{
    top++;
    stack[top] = op;
}

int stack_pop()
{
    if(top == -1)
        return 5;
    int temp = stack[top];
    top--;
    return temp;
}

void createStack(int row, int col)
{
    stack = new int[row + col - 2];
    top = -1;
}

int getPath(int r, int c)   //경로를 얻기 위해 위, 왼, 대각선 값 확인
{
    int left, up, diag;

    if(c-1 >= 0)
        left = D[r][c-1];
    else left = 10000;
    if(r-1 >= 0)
        up = D[r-1][c];
    else up = 10000;
    if(r-1 >= 0 && c-1 >= 0)
        diag = D[r-1][c-1];
    else diag = 10000;


    if(diag <= left && diag <= up) {
        if(D[r][c] == diag)
            return 0;
        else
            return 3;
    }
    else if(left <= up && left <= diag)
        return 1;
    else if(up <= left && up <= diag)
        return 2;
}

void printPath(int row, int col)    //push 후 pop 하면서 출력
{
    createStack(row, col);

    int r = row - 1;
    int c = col - 1;
    while(1) {
        if(r == 0 && c == 0)
            break;
        int res = getPath(r, c);
        switch(res) {
            case 0:
                stack_push(0);
                r--;
                c--;
                break;
            case 1:
                stack_push(1);
                c--;
                break;
            case 2:
                stack_push(2);
                r--;
                break;
            case 3:
                stack_push(3);
                r--;
                c--;
                break;
        }
    }
    while(1) {
        int tmp = stack_pop();
        if(tmp == 5) {
            break;
        }
        switch(tmp) {
            case 0:
                cout << "O ";
                break;
            case 1:
                cout << "I ";
                break;
            case 2:
                cout << "D ";
                break;
            case 3:
                cout << "C ";
                break;
        }
    }
}

//유지 0 삽입 1 삭제 2 교체 3

int main()
{
	string x, y;
	cout << "초기 문자열을 입력하시오 : ";
	cin >> x;
	cout << "목표 문자열을 입력하시오 : ";
	cin >> y;
	cout << "최소 편집 비용 : " << EditDist(x.length(), x, y.length(), y, 1, 1, 2) << endl;
	cout << "\n-----------편집 거리 테이블------\n";
	for(int i = 0; i <= x.length(); i++) {
		for(int j = 0; j <= y.length(); j++) {
			cout << D[i][j] << " \t";
		}
		cout << "\n";
	}
	cout << "--------------경로----------------\n";
    printPath(x.length()+1, y.length()+1);
    cout << "\n";
}