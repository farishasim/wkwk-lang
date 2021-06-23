#include "VM.hpp"

using namespace std;

VM::VM(byte * bytecode) {
    stack = new byte[STACK_SIZE];
    code = bytecode;
    sp = -1;
    ip = 0;
    running = true;
}

VM::~VM() {
    delete[] stack;
}

void VM::run() {
    while (this->running) {
        // fetch
        byte curr = code[ip++];

        // decode
        FunctionPointer exec = opcode[curr];

        // execute
        
        (this->*exec)();
        
        // print
        
        printStackTrace();
    }
}

void VM::printStackTrace() {
    cout << ip << " stack : [ ";
    for (int i = 0; i <= sp; i++) {
        cout << (int) stack[i] << " ";
    }
    cout << "]\n\n";
}

void VM::halt() {
    this->running = false;
}

void VM::push() {
    stack[++sp] = code[ip++];
}

void VM::pop() {
    sp--;
}

void VM::add() {
    sp--;
    stack[sp] += stack[sp+1];
}

void VM::sub() {
    sp--;
    stack[sp] -= stack[sp+1];
}

void VM::mul() {
    sp--;
    stack[sp] *= stack[sp+1];
}

void VM::div() {
    sp--;
    stack[sp] /= stack[sp+1];
}  // integer division

void VM::mov() {
    int ptr =   (code[ip++]<<24) + 
                (code[ip++]<<16) + 
                (code[ip++]<<8) + 
                (code[ip++]);
    stack[ptr] = code[ip++];
}

void VM::jmp() {
    ip = code[ip];
}

void VM::swap() {
    int temp = stack[sp];
    stack[sp] = ac;
    ac = temp;
}

void VM::pushx() {
    stack[++sp] = ac;
}

void VM::popx() {
    ac = stack[sp--];
}

void VM::je() {
    if ((byte) ac == stack[sp]) {
        ip = code[ip];
    }
}

void VM::jne() {
    if ((byte) ac != stack[sp]) {
        ip = code[ip];
    }
}

void VM::jlt() {
    if ((byte) ac < stack[sp]) ip = code[ip];
}


void VM::jgt() {
    if ((byte) ac > stack[sp]) ip = code[ip];
}


void VM::setx() {
    int ptr =   (code[ip++]<<24) + 
                (code[ip++]<<16) + 
                (code[ip++]<<8) + 
                (code[ip++]);
    stack[ptr] = ac;
}

void VM::getx() {
    int ptr =   (code[ip++]<<24) + 
                (code[ip++]<<16) + 
                (code[ip++]<<8) + 
                (code[ip++]);
    ac = stack[ptr];
}
