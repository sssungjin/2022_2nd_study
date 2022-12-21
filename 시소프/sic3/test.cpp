#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void readFile(string fname, string fname2);
vector<string> split(string str, char sep);
string strSpace(string str);

vector<string> label;
vector<string> opcode;
vector<string> operand;

int main(int argc, char** argv)
{
    readFile(argv[1], argv[2]);
}

void readFile(string fname, string fname2) {
    ifstream rf(fname);
    ofstream of(fname2);
    string str;
    if(rf.is_open()) {
        while(getline(rf, str, '\n')) {
        str = strSpace(str);
        vector<string> tmp = split(str, ' ');
        of << "label\t: " << tmp[0] << endl;
        of << "opcode\t: " << tmp[1] << endl;
        of << "operand\t: " << tmp[2] << endl;
        of << '\n';
        }
        rf.close();
        of.close();
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
    int flag = 0, j = 0;
    char tmp[100];
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            if(!flag) {
                tmp[j++] = str[i];
                flag = 1;
            }
        }
        else {
            if(flag) flag = 0;
            tmp[j++] = str[i];
        }
    }
    tmp[j] = 0;

    return tmp;
}