class CPU16 {
  private:
    // The CPU16 has an ALU, a CU, and several registers.
    ALU alu;
    CU cu;
    PC pc;
    IR ir;
    AC ac;
    // The memory of the CPU16 is represented as an array of 16-bit integers.
    int memory[4096];
    // The CPU16 has a pointer to the current memory address.
    int ptr;

  public:
    // The CPU16 has a function for loading a program into memory.
    void loadProgram(int program[], int length) {
      for (int i = 0; i < length; i++) {
        memory[i] = program[i];
      }
    }

    // The CPU16 has a function for executing the next instruction in the program.
    void executeNextInstruction() {
      // Load the instruction from memory.
      ir.setAddress(memory[ptr]);
      // Extract the opcode and operand from the IR.
      int opcode = ir.getOpcode() >> 8;
      int operand = ir.getOperand() & 0xFF;
      // Select the action to take based on the opcode.
      switch (opcode) {
        case 0b0000:
          // LDA: Read the data from the address of the operand to store the value in the AC register.
          ac.setValue(memory[operand]);
          break;
        case 0b0001:
          // STA: Store the value in the AC register in the memory address.
          memory[operand] = ac.getValue();
          break;
        case 0b0010:
          // ADD: Add the value of the operand to the value in the AC register.
          alu.add(ac.getValue(), operand);
          ac.setValue(alu.getResult());
          break;
        // case 0b0110:
        //   // SUB: Sub the value of the operand to the value in the AC register.
        //   alu.sub(ac.getValue(), operand);
        //   ac.setValue(alu.getResult());
        //   break;
        case 0b0011:
          // MUL: Multiply the value in the AC register by the value of the operand.
          alu.mul(ac.getValue(), operand);
          ac.setValue(alu.getResult());
          break;
        case 0b0100:
          // DIV: Divide the value in the AC register by the value of the operand.
          alu.div(ac.getValue(), operand);
          ac.setValue(alu.getResult());
          break;
        case 0b0101:
          // MOD: Divide the value in the AC register by the value of the operand and store the remainder.
          alu.mod(ac.getValue(), operand);
          ac.setValue(alu.getResult());
          break;
        case 0b1111:
          // SEA: Store the value of the operand in the AC register.
          ac.setValue(operand);
          break;
        // ... other opcodes as needed
      }
      // Advance the PC to the next
      
    }
};

//Arithmetic Logic Unit 산술연산 레지스터
class ALU {
  // The ALU has functions for performing arithmetic and logic operations on data.
  private:
    int result;
  public:
    void add(int a, int b);
    void sub(int a, int b);
    void mul(int a, int b);
    void div(int a, int b);
    void mod(int a, int b);
    int getResult();
};

//Control Unit 데이터를 메모리로부터 ALU로 옮기라는 명령과 그 후 다시 메모리로 옮기는 명령을 내림.
class CU {
  // The CU has functions for controlling the flow of the program.
  public:
    void jump(int address);
    void branch(int address);
    void call(int address);
    void return();
};

//Program Counter
class PC {
 private:
  int address;  // The current address of the next instruction
  int wordLength;  // The length of a single instruction, in bits
 public:
  PC(int wordLength);  // Constructor to set the word length
  void nextInstruction();  // Move to the next instruction
  void jump(int address);  // Jump to a specific address
  int getAddress();  // Get the current address
};

PC::PC(int wordLength) {
  this->wordLength = wordLength;
}

//ALU 에서 연산한 결과 임시로 저장하는 레지스터
class AC {
 private:
  int value;  // The current value of the accumulator
  int wordLength;  // The length of the accumulator, in bits
 public:
  AC(int wordLength);  // Constructor to set the word length
  void setValue(int value);  // Set the value of the accumulator
  int getValue();  // Get the value of the accumulator
};

//Instruction Register, 현재 실행되고 있는 명령어 저장
class IR {
 private:
  int opcode;  // The opcode of the current instruction
  int operand;  // The operand of the current instruction
  int address;
 public:
  void setInstruction(int opcode, int operand);  // Set the current instruction
  void setAddress(int address);
  int getOpcode();  // Get the opcode of the current instruction
  int getOperand();  // Get the operand of the current instruction
};

void IR::setInstruction(int opcode, int operand) {
  this->opcode = opcode;
  this->operand = operand;
}

void IR::setAddress(int address) {
  this->address = address;
}

int IR::getOpcode() {
  return this->opcode;
}

int IR::getOperand() {
  return this->operand;
}

void ALU::add(int a, int b) {
  value = a + b;
}

void ALU::sub(int a, int b) {
  value = a - b;
}

void ALU::mul(int a, int b) {
  value = a * b;
}

void ALU::div(int a, int b) {
  value = a / b;
}

void ALU::mod(int a, int b) {
  value = a % b;
}

int ALU::getResult() {
  return result;
}
