#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> m;

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
        return NULL;
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
        return NULL;
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

// objfile 작성 시 loc읽어서 앞자리에 0몇개 출력할지 문자열로 저장
string getZero(string loc)
{
    int count = 0;
    string str = "";
    for (int i = 0; i < 6; i++)
    {
        if (loc[i] == ' ')
            count++;
    }
    loc = loc.substr(0, loc.find(' '));
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
        if('0' <= str[i] && str[i] <= '9') 
            ret = ret * 16 + str[i] - '0';
        else if('a' <= str[i] && str[i] <= 'f')
            ret = ret * 16 + str[i] - '0' - 7;
    }
    return ret;
}

string DecToHex(int dec)    //10진수 정수를 16진수 문자열로 변환
{
    int i, k = 0, m, n;
	//char c_hex[] = "0123456789ABCDEF";
    char c_hex[] =  "0123456789ABCDEF";
    string hex;
    while (1)
	{
		m = dec / 16; // 16으로 나눈 몫
		n = dec - (m * 16); // 나머지
		hex[k++] = c_hex[n];
		if (m <= 0) break;
		dec = m;
	}
    
    return hex;
}

void Pass1(string fname, string fname2)
{

    ifstream rf(fname);
    ofstream of(fname2); // intfile
    // ifstream is("SYMTAB.txt"); //읽을때
    // ofstream fs("SYMTAB.txt"); //쓸 때
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

            if (opcode == "start")
                continue;

            if (opcode != "end")
            {
                if (label != ".")
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
                    }

                    of << hex << locctr << "    ";
                    of << str;
                    of << endl;

                    // if (check_op(opcode))
                    // {
                    //     if(check_op(opcode))
                    //         locctr += 3;
                    //     else if (opcode == "word")
                    //         locctr += 3;
                    //     else if (opcode == "resw")
                    //         locctr += 3 * stoi(operand);
                    //     else if (opcode == "resb")
                    //         locctr += stoi(operand);
                    //     else if (opcode == "byte")
                    //         locctr += operand.length();
                    //     else
                    //         locctr += 3;
                    // }
                    // else
                    //     errorflag = 1;

                    if (check_op(opcode))
                    {
                        locctr += 3;
                        // cout << "check" << endl;
                    }
                    else if (opcode == "word")
                        locctr += 3;
                    else if (opcode == "resw")
                    {
                        locctr += 3 * stoi(operand);
                        // cout << "resw\n";
                    }
                    else if (opcode == "resb")
                        locctr += stoi(operand);
                    else if (opcode == "byte")
                        locctr += operand.length();
                    else
                    {
                        locctr += 3;
                        cout << "check\n";
                    }
                    // cout << "endcheck\n";
                }
                else if (label == ".")
                {
                    of << "        ";
                    of << str << endl;
                }
            }
            else if (opcode == "end")
            {
                of << hex << locctr << "    ";
                of << str;
                of << endl;
            }
        }
        rf.close();
        of.close();
        // fs.close();
        // is.close();
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

//현재 symbtab 주소, optab 넘버는 해시테이블에 10진수로 저장됨
//출력할 때 16진수로 변환해야함
void Pass2()
{
    ifstream intf("Intfile.txt");
    ofstream objf("Objfile.txt");
    string str;
    string label, opcode, operand, locctr;
    // int locctr;
    if (intf.is_open())
    {
        getline(intf, str);
        locctr = str.substr(0, 6);
        opcode = str.substr(17, 6);
        label = str.substr(8, 6);
        opcode = opcode.substr(0, opcode.find(' '));
        if (opcode == "start")
        {
            // cout << opcode;
            // listing line
            string tmp = getZero(locctr);
            objf << "H";
            objf << label;
            objf << tmp;
            string len;
            //길이 구하는 라인, end 주소 가져와서 startaddr - endaddr H레코드에 넣음
            while (getline(intf, str))
            {
                string end = str.substr(17, 3);
                if (end == "end")
                {
                    len = str.substr(0, 6); // start주소(locctr) - end주소(len)
                    // 16진수 문자열 10진수로 변환해서 계산하고 다시 16진수 문자열로
                    int startaddr = HexToDec(locctr);
                    int endaddr = HexToDec(len);
                    int total_length = endaddr - startaddr;
                    cout << total_length << endl;
                    cout << DecToHex(total_length) << endl;
                }
            }
        }
    }
    else
    {
        cout << "No Intfile !! \n";
    }
}

int main(int argc, char **argv)
{
    Pass1(argv[1], "Intfile.txt");
    Pass2();
}