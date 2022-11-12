#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;
map<string, int> m;

int total_length;

struct node
{
    string symbol;
    int locctr;
    int flag;
    struct node *next;
    node(string s, int l, int f, struct node *n)
    {
        symbol = s;
        locctr = l;
        flag = f;
        next = n;
    }
};
struct node_op
{
    string opcode;
    int opnumber;
    struct node_op *next;
    node_op(string op, int num, struct node_op *ne)
    {
        opcode = op;
        opnumber = num;
        next = ne;
    }
};

class HashTable_sym
{
private:
    int m;
    struct node **ht;

public:
    HashTable_sym(int m)
    {
        this->m = m;
        ht = new node *[m]
        { NULL };
    }
    int getKey(string s)
    {
        int i;
        int r = 0;
        int a = 33;

        for (i = 0; i < s.length(); i++)
        {
            r += r * a + s[i];
        }
        return r % m;
    }
    void insertHT(string str, int loc, int flag)
    {
        int hashKey = getKey(str);
        struct node *x = new node(str, loc, flag, NULL);
        if (ht[hashKey] == NULL)
        {
            ht[hashKey] = x;
        }
        else
        {
            x->next = ht[hashKey];
            ht[hashKey] = x;
        }
    }
    struct node *searchData(string str)
    {
        int hashKey = getKey(str);

        if (ht[hashKey] != NULL)
        {
            if (ht[hashKey]->symbol == str)
            {
                return ht[hashKey];
            }
            else
            {
                struct node *curNode = ht[hashKey];
                while (curNode->next)
                {
                    if (curNode->next->symbol == str)
                    {
                        return curNode;
                    }
                    curNode = curNode->next;
                }
            }
        }
        else if (ht[hashKey] == NULL)
        {
            cout << str << endl;
            return NULL;
        }
    }
};

class HashTable_op
{
private:
    int m;
    struct node_op **ht;

public:
    HashTable_op(int m)
    {
        this->m = m;
        ht = new node_op *[m]
        { NULL };
    }
    int getKey(string s)
    {
        int i;
        int r = 0;
        int a = 33;

        for (i = 0; i < s.length(); i++)
        {
            r += r * a + s[i];
        }
        return r % m;
    }
    void insertHT(string str, int num)
    {
        int hashKey = getKey(str);
        struct node_op *x = new node_op(str, num, NULL);
        if (ht[hashKey] == NULL)
        {
            ht[hashKey] = x;
        }
        else
        {
            x->next = ht[hashKey];
            ht[hashKey] = x;
        }
    }
    struct node_op *searchData(string str)
    {
        int hashKey = getKey(str);
        if (ht[hashKey] != NULL)
        {
            if (ht[hashKey]->opcode == str)
            {
                return ht[hashKey];
            }
            else
            {
                struct node_op *curNode = ht[hashKey];
                while (curNode->next)
                {
                    if (curNode->next->opcode == str)
                    {
                        return curNode;
                    }
                    curNode = curNode->next;
                }
            }
        }
        else if (ht[hashKey] == NULL)
        {
            return NULL;
        }
    }
};

HashTable_sym symbtab(10009);
HashTable_op optab(10009);

bool check_op(string toFind)
{
    struct node_op *tmp = optab.searchData(toFind);
    //오류 코드
    if (tmp == NULL)
    {
        return false;
    }
    if (tmp->opcode == toFind)
    {
        return true;
    }
}

// 10진수 locctr을 16진수로 변환
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

// optab의 해시테이블에 넣을 때 16진수 opnum을 10진수로 변환
int toDec_op(string str)
{
    int ret = 0;
    for (int i = 0; i < 2; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'F')
        {
            ret = ret * 16 + str[i] - 55;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            ret = ret * 16 + str[i] - 48;
        }
    }
    return ret;
}

// stringstream 으로 얻은 문자열은 공백이 없으므로 6-길이 만큼 0추가
string getZero2(string loc)
{
    int count = 0;
    string str = "";
    count = 6 - loc.length();
    for (int i = 0; i < count; i++)
    {
        str += "0";
    }
    str += loc;
    return str;
}

int HexToDec(string str) // 16진수 문자열을 10진수 정수로 변환
{
    int ret = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
            ret = ret * 16 + str[i] - '0';
        else if ('a' <= str[i] && str[i] <= 'f')
            ret = ret * 16 + str[i] - '0' - 7;
    }
    return ret;
}

string DecToHex(int dec) // 10진수 정수를 16진수 문자열로 변환
{
    int i, k = 0, m, n;
    // char c_hex[] = "0123456789ABCDEF";
    char c_hex[] = "0123456789abcdef";
    char hex[6] = {0};
    int flag = 0;
    if (dec <= 15)
    {
        flag = 1;
    }
    while (1)
    {
        m = dec / 16;       // 16으로 나눈 몫
        n = dec - (m * 16); // 나머지
        hex[k++] = c_hex[n];
        if (m <= 0)
            break;
        dec = m;
    }
    char ret[6] = {0};
    int j = k - 1;
    if (flag == 1)
    {
        ret[0] = '0';
        for (int i = 1; i < k + 1; i++)
        {
            ret[i] = hex[j];
            j--;
        }
    }
    else
        for (int i = 0; i < k; i++)
        {
            ret[i] = hex[j];
            j--;
        }

    return ret;
}

void GetInstruction(string str, string *token)
{
    if (str[0] == '.')
    {
        token[0] = str.substr(0, str.find('\n'));
        token[1] = token[2] = token[3] = "";
        return;
    }

    token[0] = str.substr(0, 6);
    token[0] = token[0].substr(0, token[0].find(' '));
    token[1] = str.substr(8, 8);
    token[1] = token[1].substr(0, token[1].find(' '));
    token[2] = str.substr(17, 6);
    token[2] = token[2].substr(0, token[2].find(' '));
    token[3] = str.substr(25, 25);
    token[3] = token[3].substr(0, token[3].find(' '));
    return;
}

void Pass1(string fname, string fname2)
{

    ifstream rf(fname);
    ofstream of(fname2); // intfile

    string str;
    string label, opcode, operand;
    int locctr = 0, errorflag = 0;

    ifstream tmp("Optab.txt");
    if (tmp.is_open())
    {
        while (getline(tmp, str))
        {
            string opcode = str.substr(0, 8);
            opcode = opcode.substr(0, opcode.find(' '));
            string opnum = str.substr(8, 2);
            int num = toDec_op(opnum); // 10진수로 변환한 opnum을 넣음
            optab.insertHT(opcode, num);
            // struct node_op* t = optab.searchData(opcode);
            // cout << "optab : " << t->opcode << " " << t->opnumber << endl;
        }
        tmp.close();
    }
    else
    {
        cout << "There is No OPTAB !! \n";
    }

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
            of << hex << locctr << "    ";
            of << str;
            of << endl;
        }
        else
            locctr = 0;

        while (getline(rf, str))
        {
            errorflag = 0;
            int symbflag = 0;

            label = str.substr(0, 8);     // label
            opcode = str.substr(9, 6);    // opcode
            operand = str.substr(17, 18); // operand

            label = label.substr(0, label.find(' ')); //공백제거
            opcode = opcode.substr(0, opcode.find(' '));
            operand = operand.substr(0, operand.find(' '));

            if (opcode != "end")
            {
                if (label != ".") // comment line 처리
                {
                    if (!label.empty())
                    {
                        m[label]++;
                        if (m[label] == 1)
                        {
                            // fs << str.substr(0, 8);
                            // fs << hex << locctr;
                            // fs << "     0" << endl;
                            symbflag = 0;
                            symbtab.insertHT(label, locctr, symbflag);
                        }
                        else
                        {
                            //파일 출력하려면 error flag 1일 때 바꿔야함
                            symbflag = 1;
                            struct node *tmp = symbtab.searchData(label);
                            tmp->flag = 1;
                        }
                        struct node* temp = symbtab.searchData(label);
                        cout << "symbol : " << temp->symbol << "    locctr : " << hex << temp->locctr << "\tflag : " << temp->flag << endl;
                    }

                    of << hex << locctr << "    ";
                    of << str;
                    of << endl;

                    if (check_op(opcode))
                        locctr += 3;
                    else if (opcode == "word")
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
                else if (label == ".")
                {
                    of << "        ";
                    of << str << endl;
                }
            }
            else if (opcode == "end")
            {
                symbtab.insertHT(label, locctr, symbflag);
                of << hex << locctr << "    ";
                of << str;
                of << endl;
                total_length = locctr;  //pass2에서 total_length 사용
            }
        }
        rf.close();
        of.close();
    }
    else
    {
        cout << "No such file!!\n";
    }
}

// 0 레코드 이름
// 1~6 시작주소
// 7~8 길이
// 9~69 object 코드

void Pass2()
{
    ifstream intf("Intfile.txt");
    ofstream objf("Objfile.txt");

    string objectCode, textRecord, str, token[4];
    string address, label, opcode, operand, operand_num, opcode_num;
    int startAddr, textAddr, oper_value;
    if (intf.is_open())
    {
        getline(intf, str);
        GetInstruction(str, token);
        // cout << str << endl;
        address = token[0];
        label = token[1];
        opcode = token[2];
        operand = token[3];
        startAddr = HexToDec(address);
        textAddr = startAddr;
        total_length = total_length - startAddr;
        objf << "h";
        if (opcode == "start")
        {
            objf << label;
            for (int i = 0; i < 6 - label.length(); i++)
                objf << " ";
            getline(intf, str);
            GetInstruction(str, token);

            address = token[0];
            label = token[1];
            opcode = token[2];
            operand = token[3];
        }
        objf << setfill('0') << setw(6) << hex << textAddr;
        objf << setw(6) << hex << total_length << endl;
        while (opcode != "end")
        {
            if (label != ".")
            {
                if (check_op(opcode))
                {
                    if (operand != "")
                    {
                        if (operand.find(",x") != string::npos)
                        { //,x찾으면 인덱스부호 1
                            operand = operand.substr(0, operand.find(",x"));
                            operand_num = DecToHex((symbtab.searchData(operand)->locctr) + 32768);
                        }
                        else
                            operand_num = DecToHex(symbtab.searchData(operand)->locctr);
                    }
                    else
                    {
                        operand_num = "0000";
                    }
                    opcode_num = DecToHex(optab.searchData(opcode)->opnumber);
                    objectCode += opcode_num + operand_num;
                }

                else if (opcode == "word" || opcode == "byte")
                {
                    if (opcode == "word")
                    {
                        oper_value = stoi(operand);
                        string sss = getZero2(DecToHex(oper_value));
                        objectCode += sss;
                    }
                    else
                    {                                              // byte인 경우
                        if (operand.find("c'", 0) != string::npos) // c'aaa'인경우
                        {
                        }
                        else if (operand.find("x'", 0) != string::npos) // x'101010'경우
                        {
                            for (int i = 2; i < operand.length() - 1; i++)
                            {
                                objectCode += operand[i];
                            }
                        }
                    }
                }
            }
            if (textRecord.length() / 2 + objectCode.length() / 2 > 30 && textRecord != "")
            {
                objf << "t" << setfill('0') << setw(6) << hex << textAddr;
                objf << setfill('0') << setw(2) << hex << (textRecord.length() / 2) << textRecord << endl;
                textAddr += textRecord.length() / 2;
                textRecord = objectCode;
            }
            else if ((opcode == "resw" || opcode == "resb") && textRecord != "")
            {
                objf << "t" << setfill('0') << setw(6) << hex << textAddr;
                objf << setfill('0') << setw(2) << hex << (textRecord.length() / 2) << textRecord << endl;
                if (opcode == "resw")
                {
                    textAddr += (textRecord.length() / 2) + 3 * stoi(operand);
                }
                else
                {
                    textAddr += (textRecord.length() / 2) + stoi(operand);
                }
                textRecord = "";
            }
            else if (opcode == "resw" || opcode == "resb")
            {
                if (opcode == "resw")
                {
                    textAddr += (textRecord.length() / 2) + 3 * stoi(operand);
                }
                else if (opcode == "resb")
                {
                    textAddr += (textRecord.length() / 2) + stoi(operand);
                }
            }
            else
            {
                textRecord += objectCode;
            }
            getline(intf, str);
            GetInstruction(str, token);

            address = token[0];
            label = token[1];
            opcode = token[2];
            operand = token[3];
            objectCode = "";
            operand_num = "";
            oper_value = 0;
        }
        if (textRecord != "")
        {
            objf << "t" << setfill('0') << setw(6) << hex << textAddr;
            objf << setfill('0') << setw(2) << hex << (textRecord.length() / 2) << textRecord << endl;
        }

        objf << "e" << setfill('0') << setw(6) << hex << startAddr << endl;
    }
    else {
        cout << "No such file !!! \n";
    }
}

int main(int argc, char **argv)
{
    Pass1(argv[1], "Intfile.txt");
    Pass2();
}