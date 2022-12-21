#include "register.h"

#include <bitset>
#include <iostream>
using namespace std;
//------------------------------------------------------------------------------//
Memory::Memory() : bits(vector<int>(4096, 0)), AccessPointer(0){};

Memory::~Memory(){};

void Memory::intiData(int data) {
    if (!isValid(AccessPointer) || !isValid(AccessPointer + 1)) {
        cout << "IntiData AccessPointer Error!!" << endl;
        exit(1);
        // 오류처리
    }
    if (AccessPointer != 0) AccessPointer++;

    bits[AccessPointer++] = (data >> 8);
    bits[AccessPointer] = data % 256;
};

int Memory::readMemory(int pointer) {
    if (!isValid(pointer)) {
        cout << "ReadMemory Pointer Error!!" << endl;
        exit(1);
        // 오류처리
    }
    AccessPointer = pointer;

    return bits[AccessPointer];
};

void Memory::writeMemory(int pointer, int temp) {
    if (!isValid(pointer)) {
        cout << "WriteMemory Pointer Error!!" << endl;
        exit(1);
        // 오류처리
    }
    AccessPointer = pointer;

    bits[AccessPointer] = temp;
}

void Memory::resetMemory(bool isFullReset, int pointer, int num) {
    if (isFullReset) {
        for (int i = 0; i < 4096; i++) {
            bits[i] = num;
        }

        AccessPointer = 0;
        return;
    }

    if (!isValid(pointer) || !isValid(pointer + 1)) {
        cout << "ResetMemory Pointer Error!!" << endl;
        exit(1);
        // 오류처리
    }

    AccessPointer = pointer + 1;
    bits[pointer] = bits[pointer + 1] = 0;
    return;
}

void Memory::showMemory(int step, int memoryMax) {
    cout << "--Step " << step + 1 << " -- Memory--\n";
    for (int i = 0; i <= memoryMax + 1; i++) {
        cout << bitset<8>(bits[i]).to_string().insert(4, " ") << "\n";
    }
    cout << "---------------------\n";
}

bool Memory::isValid(int pointer) { return 0 <= pointer && pointer < 4096; };
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
Register::Register() { bits = 0; };

Register::~Register(){};

int Register::getBits() { return bits; };

void Register::setBits(int data) { bits = data; };
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
AC::AC(){};

AC::~AC(){};
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
ALU::ALU() { carry = false; };

ALU::~ALU(){};

int ALU::addData(int tempData, int acData) {
    if (acData + tempData >= (1 << 16)) carry = true;

    return (acData + tempData) % (1 << 16);
};

int ALU::mulData(int tempData, int acData) {
    if (acData * tempData >= (1 << 16)) carry = true;

    return (acData * tempData) % (1 << 16);
};

int ALU::divData(int tempData, int acData) {
    if (tempData == 0) {
        cout << "Zero Division Pointer Error!!" << endl;
        exit(1);
        // 예외처리 해
    }

    if (acData / tempData >= (1 << 16)) carry = true;

    return (acData / tempData) % (1 << 16);
};

int ALU::modData(int tempData, int acData) {
    if (acData % tempData >= (1 << 16)) carry = true;

    return (acData % tempData) % (1 << 16);
};
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
CU::CU() {}

CU::~CU() {}

void CU::splitData() {
    opcode = bits >> 12;
    operand = bits % 4096;
}

void CU::interpretData(int data, CPU16& cpu, Memory& mem) {
    if (opcode == 0) operand = (mem.readMemory(operand) << 8) + mem.readMemory(operand + 1);

    if (opcode == 0 || opcode == 15) {
        cpu.getAC().setBits(operand);
    } else if (opcode == 1) {
        mem.writeMemory(operand, cpu.getAC().getBits() >> 8);
        mem.writeMemory(operand + 1, cpu.getAC().getBits() % 256);
    } else if (opcode == 2) {
        cpu.getAC().setBits(cpu.getALU().addData(operand, cpu.getAC().getBits()));
    } else if (opcode == 3) {
        cpu.getAC().setBits(cpu.getALU().mulData(operand, cpu.getAC().getBits()));
    } else if (opcode == 4) {
        cpu.getAC().setBits(cpu.getALU().divData(operand, cpu.getAC().getBits()));
    } else {
        cpu.getAC().setBits(cpu.getALU().modData(operand, cpu.getAC().getBits()));
    }
}
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
PC::PC(){};

PC::~PC(){};

int PC::getAddress() {
    bits += 2;
    return bits - 2;
}
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
IR::IR(){};

IR::~IR(){};

void IR::inputData(int data) {
    bits = data;
};
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
CPU16::CPU16(){};

CPU16::~CPU16(){};

void CPU16::runCPU(int memoryMax, int instructionMax, Memory& mem) {
    for (int i = 0; i < instructionMax; i++) {
        MemToIR(mem);
        IRToCU();
        cu.interpretData(ir.getBits(), *this, mem);
        mem.showMemory(i, memoryMax);
    }
}

void CPU16::MemToIR(Memory& mem) {
    int address = pc.getAddress();
    int data = (mem.readMemory(address) << 8) + mem.readMemory(address + 1);
    ir.inputData(data);
}

void CPU16::IRToCU() {
    cu.setBits(ir.getBits());
    cu.splitData();
}

CU& CPU16::getCU() {
    CU& temp = cu;
    return temp;
}

ALU& CPU16::getALU() {
    ALU& temp = alu;
    return temp;
}

PC& CPU16::getPC() {
    PC& temp = pc;
    return temp;
}

IR& CPU16::getIR() {
    IR& temp = ir;
    return temp;
}

AC& CPU16::getAC() {
    AC& temp = ac;
    return temp;
}