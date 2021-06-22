#include "VM.hpp"

int main() {
    byte program[100] = {
        PUSH, 0x04,
        PUSH, 0x03,
        ADD,
        HALT,
    };

    VM vm(program);

    vm.run();

    return 0;
}