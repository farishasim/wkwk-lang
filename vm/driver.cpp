#include "VM.hpp"

int main() {
    byte program[100] = {
        HALT
    };

    VM vm(program);

    vm.run();

    return 0;
}