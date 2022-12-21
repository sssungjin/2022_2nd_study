#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "register.h"
using namespace std;

int main() {
    CPU16 cpu;
    Memory mem;

    unordered_map<string, int> optab;
    optab.insert(make_pair("LDA", 0));
    optab.insert(make_pair("STA", 1));
    optab.insert(make_pair("ADD", 2));
    optab.insert(make_pair("MUL", 3));
    optab.insert(make_pair("DIV", 4));
    optab.insert(make_pair("MOD", 5));
    optab.insert(make_pair("SEA", 15));

    int cnt = 0;
    cout << "do you want to finish instruction? please input \"END\"" << endl;
    while (true) {
        string opcode, operand;

        cin >> opcode;
        if (opcode == "END") {
            break;
        }

        cin >> operand;

        if (optab.count(opcode) == 0) {
            cout << "OPCODE ERROR!!" << endl;
            exit(1);
            // 예외 처리
        }

        int data;
        if (opcode == "LDA" || opcode == "STA" || opcode == "SEA") {
            data = (optab[opcode] << 12) + stoi(operand, NULL, 16);
        } else {
            data = (optab[opcode] << 12) + stoi(operand);
        }

        mem.intiData(data);
        cnt++;
    }

    cout << "You want to show Max Memory Number : ";
    int memoryMax;
    cin >> memoryMax;

    cpu.runCPU(memoryMax, cnt, mem);

    return 0;
}