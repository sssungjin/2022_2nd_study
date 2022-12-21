#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    int N, M;
    vector<int> a;
    vector<int> b;
    map<int, int> m;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        a.push_back(rand()%50);    
    }
    for(int i = 0; i < M; i++) {
        b.push_back(rand()%50);
    }
    //입력값에 중복 없다고 가정, 중복 처리 안함

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << "집합 A - ";
    for(vector<int>::iterator itr = a.begin(); itr != a.end(); itr++) {
        if(itr != a.begin())
            cout << ", ";
        cout << *itr;
    }

    cout << "\n집합 B - ";
    for(vector<int>::iterator itr = b.begin(); itr != b.end(); itr++) {
        if(itr != b.begin())
            cout << ", ";
        cout << *itr;
    }

    for(int i = 0; i < N; i++) {
            m[a[i]]++;
    }
    for(int i = 0; i < M; i++) {
            m[b[i]]++;
    }

    cout << "\n합집합 - ";
    for(map<int,int>::iterator itr = m.begin(); itr != m.end(); itr++) {
        //모든 키값 출력(value가 1,2인 키값)
        if(itr != m.begin())
            cout << ", ";
        cout << itr->first;
    }

    cout << "\n교집합 - ";

    map<int,int> tmp;
    for(map<int,int>::iterator itr = m.begin(); itr != m.end(); itr++) {
        if(itr->second >= 2) {
            tmp[itr->first] = itr->second;
        }
    }   //value가 2인 맵에 있는 값들 tmp에 복사(이상은 중복 값 나왔을 때 예외처리)

    if(tmp.empty()) {
        cout << "교집합이 없습니다.";
    }   
    else {
    for(map<int,int>::iterator itr = tmp.begin(); itr != tmp.end(); itr++) {

            if(itr != tmp.begin())
                cout << ", ";    
            cout << itr->first;
    
    }
    }

    cout << '\n';   
    //value값이 2인 키값 출력(value 2면 교집합)
    //마지막 ,만 없애면 됨

}