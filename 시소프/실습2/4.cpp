#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> v;

vector<string> split(string str, char sep) {
    istringstream iss(str);             
    string buf;                      
    vector<string> result;
 
    while (getline(iss, buf, sep)) {
        result.push_back(buf);               
    }
 
    return result;
}

void readFile() {
    ifstream rf;
    string str;
    rf.open("C:\\Users\\dkdlw\\Desktop\\Optab.txt");
    if(rf.is_open()) {
        while(getline(rf, str, '\n')) {
           vector<string> res = split(str, ',');
           v.push_back(res[0]);
           v.push_back(res[1]);
        }
        rf.close();
    }
    else
    {
        cout << "No such file!!\n";
    }
}

void searching() {
    while(1) {
        string str;
        cout << "enter key : ";
        cin >> str;
        if(str == v[0]) {
            cout << v[1] << endl;
        }
        else if(str == v[2]) {
            cout << v[3] << endl;
        }
         else if(str == v[4]) {
            cout << v[5] << endl;
        }
         else if(str == v[6]) {
            cout << v[7] << endl;
        }
         else if(str == v[8]) {
            cout << v[9] << endl;
        }
        else if(str == "Q") {
            break;
        }
        else
            cout << "Error !!!\n";
    }
}
int main()
{
    readFile();
    searching();
}