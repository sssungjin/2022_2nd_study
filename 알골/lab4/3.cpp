#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
void my_strtok(string s, string sep) {
	char* c = strtok((char*)s.c_str(), sep.c_str());
	while (c) {
        m[c]++;
		c = strtok(NULL, sep.c_str());
	}
}

void readFile() {
    ifstream rf;
    string str;

    rf.open("C:\\Users\\dkdlw\\Desktop\\2학년 2학기 코딩\\알골\\lab4\\datafile.txt");
    if(rf.is_open()) {
        while(getline(rf, str, '\n')) {
            my_strtok(str, " ~!@#$%^&*()-_=+[]{};:\",.<>/?\n");
        }
        rf.close();
    }
    else
    {
        cout << "No such file!!\n";
    }
}

bool cmp(pair<string, int> l , pair<string, int> r) {
    if(l.second == r.second)
        if(strcmp(l.first.c_str(), r.first.c_str()) > 0)
        return false;
        else return true;
    else
    return l.second > r.second;
}

int main() 
{
    readFile();
    vector<pair<string,int>> v;
    copy(m.begin(), m.end(), back_inserter<vector<pair<string, int>>>(v));
    sort(v.begin(), v.end(), cmp);  //cmp가 true면 sort실행
    
    for(auto itr = v.begin(); itr != v.end(); itr++)
    cout << itr->first << ":" << itr->second << endl;
}