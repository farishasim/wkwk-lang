#ifndef VM_HPP
#define VM_HPP

#include <iostream>
#include "opcode.hpp"

#define STACK_SIZE 512

typedef uint8_t byte;

using namespace std;

class VM
{
private:
    /* data */
    byte * stack;
    byte * code;
    
    /* register */
    int ip;     /* instruction pointer */
    int sp;     /* stack pointer */
    int ac;     /* accumulator */

    /* instruction table */
    typedef void (VM::*FunctionPointer)();
    FunctionPointer opcode[NUMOP] = {
        &VM::halt,
        &VM::push,
        &VM::pop,
        &VM::add,
        &VM::sub,
        &VM::mul,
        &VM::div,
        &VM::mov,
        &VM::jmp,
        &VM::swap,
        &VM::pushx,
        &VM::popx,
        &VM::je,
        &VM::jne,
        &VM::jlt,
        &VM::jgt,
        &VM::setx,
        &VM::getx,
        &VM::print,
        &VM::scan,
    };

    /* status */
    bool running;

public:
    VM(byte * bytecode);
    ~VM();

    void run();
    // void fetch();
    // void decode();
    // void execute();

    void printStackTrace();

    void halt();
    void push();
    void pop();
    void add();
    void sub();
    void mul();
    void div();  // integer division
    void mov();
    void jmp();
    void swap();
    void pushx();
    void popx();
    void je();
    void jne();
    void jlt();
    void jgt();
    void setx();
    void getx();
    void print();
    void scan();
};

#endif