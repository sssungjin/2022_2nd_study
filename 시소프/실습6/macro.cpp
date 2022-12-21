#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

void readFile(string fname, string mname, string m1, string m);

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        readFile("SRCFILE.txt", argv[1], argv[2], argv[3]);
    }
    else
    { //입력 없을 경우 default 값
        readFile("SRCFILE.txt", "rdbuff", "f1,", "buffer");
    }
}

void readFile(string fname, string mname, string m1, string m2)
{
    ifstream rf(fname);
    string str;
    m1 = m1.substr(0, m1.find(",")); // m1 ,제거
    if (rf.is_open())
    {
        getline(rf, str);
        istringstream st(str);
        string s[4];
        st >> s[0] >> s[1] >> s[2] >> s[3];
        s[2] = s[2].substr(0, s[2].find(",")); //, 제거
        if (s[1] == "macro")
        {
            while (getline(rf, str))
            {
                istringstream mm(str);
                string ins[2]; // instruction 라인 추출
                mm >> ins[0] >> ins[1];
                if (ins[0] != "mend")
                {
                    if (ins[1].find(s[2]) != string::npos || ins[1].find(s[3]) != string::npos)
                    {
                        if (ins[1].find(s[2]) != string::npos)
                        {
                            ins[1].replace(ins[1].find(s[2]), s[2].length(), m1);
                        }
                        else
                        {
                            ins[1].replace(ins[1].find(s[3]), s[3].length(), m2);
                        }
                    }
                    cout << ins[0] << "\t" << ins[1] << endl;
                }
            }
        }
    }
    else
    {
        cout << "No such file !!!\n";
    }
}