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

        // print
        printStackTrace();

        // decode
        FunctionPointer exec = opcode[curr];

        cout << "current instruction : " << (int) ip << endl;
        cout << "address : " << (void*) this->opcode[curr] << endl;
        cout << "address : " << (void*) &VM::halt << endl;
        cout << "address : " << (void*) exec << endl;

        // execute
        (*exec)();

        cout << running << endl;
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
    cout << running << endl;
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
    stack[sp] -= stack[sp];
}

void VM::mul() {}
void VM::div() {}  // integer division
void VM::mov() {}
void VM::jmp() {}
void VM::swap() {}