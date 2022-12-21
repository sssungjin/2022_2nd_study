#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void readFile();
vector<string> split(string str, char sep);
string strSpace(string str);

vector<string> label;
vector<string> opcode;
vector<string> operand;

int main()
{   
    readFile();
}

void readFile() {
    ifstream rf;
    string str;
    int i = 0;
    rf.open("시소프\\sic3\\SRCFILE");
    if(rf.is_open()) {
        while(getline(rf, str, '\n')) {
           //vector<string> res = split(str, ' ');
           string ds;
           //str.erase(remove(str.begin(), str.end(), ' '), str.end());
           //cout << str << endl;
        }
        rf.close();
    }
    else
    {
        cout << "No such file!!\n";
    }
}

vector<string> split(string str, char sep) {
    istringstream iss(str);             
    string buf;                      
    vector<string> result;
 
    while (getline(iss, buf, sep)) {
        result.push_back(buf);               
    }
 
    return result;
}

string strSpace(string str) {
    int flag = 0, i = 0, j = 0;
    char temp[100];
    while(str[i]) {
        if(str[i] == ' ') {
            if(!flag) {
                temp[j++] = str[i];
                flag = 1;
            }
        }
        else {
            if(flag) flag = 0;
            temp[j++] = str[i];
        }
        i++;
    }
    temp[j] = '\0';
    return temp;
}