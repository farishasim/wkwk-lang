#include "VM.hpp"

byte cat[100] = {
    PUSH, 0x00,
    POPX,
    PUSHX,
    SCAN,
    PRINT,
    JNE, 0x04,
    HALT,
};

byte helloworld[100] = {
    PUSH, 0x00,
    POPX,
    PUSHX,
    PUSH, '\n',
    PUSH, '!',
    PUSH, 'd',
    PUSH, 'l',
    PUSH, 'r',
    PUSH, 'o',
    PUSH, 'w',
    PUSH, ' ',
    PUSH, 'o',
    PUSH, 'l',
    PUSH, 'l',
    PUSH, 'e',
    PUSH, 'h',
    PRINT,
    POP,
    JNE, 28,
    HALT,
};

int main() {
    byte * program = helloworld;

    VM vm(program);

    vm.run();

    return 0;
}