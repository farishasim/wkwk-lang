#include "./vm/VM.hpp"
#include <fstream>
#include <string>

using namespace std;

byte * program;

byte get8bit(char * str) {
    int i;
    byte newbyte = 0;
    for (i = 0; i<8; i++) {
        newbyte<<=1;
        if (str[i] == 'k') {
            newbyte += 1;
        } else if (str[i] == 'w') {
            
        } else {
            cout << "Unresolved Symbol: " << str[i] << "." << endl;
            exit(0);
        }
    }
    return newbyte;
}

void interpret(char * filename) {
    char * buffer;
    int len;

    // load program
    ifstream infile;
    infile.open(filename);
    infile.seekg(0, ios::end);
    len = infile.tellg();
    infile.seekg(0, ios::beg);
    // delete[] buffer;
    buffer = new char[len];
    infile.read(buffer, len);
    infile.close();

    if (len % 8 != 0) {
        cout << "Invalid code length.\n";
        exit(0);
    }

    int codelen = len / 8;
    byte * code = new byte[codelen];

    for(int i=0; i<codelen; i++) {
        code[i] = get8bit(&buffer[i*8]);
    }

    delete[] buffer;
    program = code;
}

int main(int argc, char ** args) {

    if (argc < 2)  {
        cout << "usage : ./boi filename\n";
        exit(0);
    }

    interpret(args[1]);

    // for (int i=0; i<34; i++) {
    //     if (program[i] != helloworld[i]) {
    //         cout << "disini : " << i << endl;
    //         exit(0);
    //     }
    // }

    VM vm(program);

    vm.run();

    return 0;
}