#ifndef VM_HPP
#define VM_HPP

#include <iostream>

#define STACK_SIZE 512

typedef uint8_t byte;
typedef void (*FunctionPointer)();

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
    FunctionPointer opcode[3] = {
        (FunctionPointer) &fetch,
        (FunctionPointer) &decode,
        (FunctionPointer) &execute 
    };

public:
    VM(/* args */);
    ~VM();

    void fetch();
    void decode();
    void execute();
};

#endif