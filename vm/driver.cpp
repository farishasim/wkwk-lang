#include "VM.hpp"
#include <fstream>
#include <string>

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
    JNE, 30,
    HALT,
};

int main(int argc, char ** args) {

    if (argc < 2)  {
        cout << "usage : ./driver filename\n";
        exit(0);
    }

    byte * program;

    ifstream infile;
    infile.open(args[1]);
    infile.seekg(0, ios::end);
    int length = infile.tellg();
    infile.seekg(0, ios::beg);
    program = new byte[length];
    infile.read((char*)program, length);
    infile.close();

    cout << length;

    VM vm(program);

    vm.run();

    return 0;
}