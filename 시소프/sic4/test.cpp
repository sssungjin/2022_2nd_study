#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> m;

bool check_op(string toFind)
{
    string str;
    int flag = 0;
    ifstream fs("Optab.txt");
    while (getline(fs, str))
    {
        if (str.find(toFind))
        {
            return true;
        }
    }
    fs.close();
    return false;
}

int toHex(int locctr)
{
    int mul = 1, tmp = 0;
    while (locctr / 10 != 0)
    {
        tmp = tmp + (locctr % 10) * mul;
        mul *= 16;
        locctr /= 10;
    }
    tmp = (locctr % 10) * mul + tmp;
    return tmp;
}

void readFile(string fname, string fname2)
{
    ifstream rf(fname);
    ofstream of(fname2);
    ifstream is("SYMTAB.txt"); //읽을때
    ofstream fs("SYMTAB.txt"); //쓸 때
    string str;
    string label, opcode, operand;
    int locctr = 0, errorflag = 0;
    if (rf.is_open())
    {
        getline(rf, str);
        opcode = str.substr(9, 6);                      // opcode
        opcode = opcode.substr(0, opcode.find(' '));    //공백제거
        operand = str.substr(17, 18);                   // operand
        operand = operand.substr(0, operand.find(' ')); //공백제거

        if (opcode == "start")
        {
            locctr = stoi(operand);
            locctr = toHex(locctr);
            of << str;
            of << hex << locctr;
            of << endl;
        }
        else
            locctr = 0;

        while (getline(rf, str))
        {
            errorflag = 0;

            label = str.substr(0, 8);     // label
            opcode = str.substr(9, 6);    // opcode
            operand = str.substr(17, 18); // operand

            label = label.substr(0, label.find(' ')); //공백제거
            opcode = opcode.substr(0, opcode.find(' '));
            operand = operand.substr(0, operand.find(' '));

            if (opcode == "start")
                continue;

            if (opcode != "end")
            {
                if (label != ".")
                {
                    if (!label.empty())
                    {
                        m[label]++;
                        fs << str.substr(0, 8);
                        fs << hex << locctr;
                        if (m[label] >= 2)
                            fs << "     1" << endl;
                        else
                            fs << "     0" << endl;
                    }

                    of << str;
                    of << hex << locctr;
                    of << endl;

                    if (check_op(opcode))
                    {
                        if (opcode == "word")
                            locctr += 3;
                        else if (opcode == "resw")
                            locctr += 3 * stoi(operand);
                        else if (opcode == "resb")
                            locctr += stoi(operand);
                        else if (opcode == "byte")
                            locctr += operand.length();
                        else
                            locctr += 3;
                    }
                    else
                        errorflag = 1;
                }
                else if (label == ".")
                {
                    of << str << endl;
                }
            }
            else if (opcode == "end")
            {
                of << str;
                of << hex << locctr;
                of << endl;
            }
        }
        rf.close();
        of.close();
        fs.close();
        is.close();
    }
    else
    {
        cout << "No such file!!\n";
    }
}

int main(int argc, char **argv)
{
    if (argv[0] == "test")
    {
        readFile(argv[1], argv[2]);
    }
    else
    {
        readFile(argv[1], "Intfile.txt");
    }
}