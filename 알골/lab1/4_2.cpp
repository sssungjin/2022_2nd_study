#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    set<int> a;
    set<int> b;
    set<int> uni;
    map<int,int> m;
    map<int, int> tmp;
    int N, M; 
    cin >> N >> M;

    while(a.size() != N) {
        a.insert(rand()%50);
    }
    while(b.size() != M) {
        b.insert(rand()%50);
    }

    cout << "집합 A - ";
    for(auto itr = a.begin(); itr != a.end(); itr++) {
        if(itr != a.begin())
            cout << ", ";
        cout << *itr;
        m[*itr]++;
        uni.insert(*itr);
    }
    cout << "\n집합 B - ";
    for(auto itr = b.begin(); itr != b.end(); itr++) {
        if(itr != b.begin())
            cout << ", ";
        cout << *itr;
        m[*itr]++;
        uni.insert(*itr);
    }
    cout << "\n합집합 - ";
    for(auto itr = uni.begin(); itr != uni.end(); itr++) {
        if(itr != uni.begin())
            cout << ", ";
        cout << *itr;
    }
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        if(itr->second == 2) {
            tmp[itr->first] = itr->second;
        }
    }
    cout << "\n교집합 - ";
    if(tmp.empty())
        cout << "집합이 비어있습니다.\n";
    else {
    for(auto itr = tmp.begin(); itr != tmp.end(); itr++) {
        if(itr != tmp.begin())
            cout << ", ";
        cout << itr->first;
    }
    }
    cout << '\n';
}