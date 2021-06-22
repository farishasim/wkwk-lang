#ifndef VM_HPP
#define VM_HPP

#include <iostream>
#include "opcode.hpp"

#define STACK_SIZE 512

typedef uint8_t byte;
typedef void (*FunctionPointer)();

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
    FunctionPointer opcode[10] = {
        (FunctionPointer) &VM::halt,
        (FunctionPointer) &VM::push,        
        (FunctionPointer) &VM::pop,
        (FunctionPointer) &VM::add,
        (FunctionPointer) &VM::sub,
        (FunctionPointer) &VM::mul,
        (FunctionPointer) &VM::div,
        (FunctionPointer) &VM::mov,
        (FunctionPointer) &VM::jmp,
        (FunctionPointer) &VM::swap,
    };

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
};

#endif