#ifndef VM_HPP
#define VM_HPP

#include <iostream>

#define STACK_SIZE 512

typedef uint8_t byte;

class VM
{
private:
    /* data */
    byte * stack;
    byte * code;
    int ip;
    int sp;

public:
    VM(/* args */);
    ~VM();

    void fetch();
    void decode();
    void execute();
};

#endif