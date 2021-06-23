#ifndef OPCODE_HPP
#define OPCODE_HPP

#define HALT    0x00
#define PUSH    0x01
#define POP     0x02
#define ADD     0x03
#define SUB     0x04
#define MUL     0x05
#define DIV     0x06
#define MOV     0x07
#define JMP     0x08
#define SWAP    0x09
#define PUSHX   0x0A
#define POPX    0x0B
#define JE      0x0C
#define JNE     0x0D
#define JLT     0x0E
#define JGT     0x0F
#define SETX    0x10
#define GETX    0x11
#define PRINT   0x12
#define SCAN    0x13

#define NUMOP   SCAN+1

#endif