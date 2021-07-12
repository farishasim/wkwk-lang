# WKWK LANG - Stack-Based Esolang

Wkwk-lang adalah sebuah [bahasa pemrograman esoterik](https://en.wikipedia.org/wiki/Esoteric_programming_language) yang diimplementasikan secara stack-based. Selain memiliki stack memory dengan top 8-bit, bahasa ini juga memiliki 3 buah register 32-bit, yaitu ip (instruction pointer), sp (stack pointer), dan ac (accumulator).

## Syntax

Bahasa ini hanya terdiri dari 2 simbol yaitu 'w' dan 'k'. Pada bahasa ini, setiap 'wk-byte' terdiri dari 8 'wk-bit', dan setiap 'wk-bit' memiliki dua kemungkinan nilai yaitu 'w' atau 'k'. Aturan pada wk-byte sama seperti aturan biner, dengan mengganti 0 menjadi w dan 1 menjadi k. Contohnya, `wwwwwwww` bernilai 0, `wwwwwwwk` bernilai 1,
`wwwwwkwk` bernilai 5, dst.

Semua instruksi dan konstanta pada bahasa ini dituliskan dalam wk-byte. Misalnya untuk `wwwwwwwkwkwkwkwk`, wk-byte pertama `wwwwwwwk` adalah instruksi untuk push, dan wk-byte kedua `wkwkwkwk` adalah konstanta 85, maka ketika perintah tersebut dijalankan, yang dilakukan adalah push 85 ke stack.

Bahasa ini juga dilengkapi dengan penanganan syntax error, yaitu ketika ada karakter lain selain w dan k atau ketika panjang source code bukan merupakan kelipatan 8 (ingat bahwa semua instruksi dituliskan dalam wk-byte).

## Command
Command | Operation | Description 
:---: | :---: | --- 
`wwwwwwww`| HALT | Stop the program execution. 
`wwwwwwwk`| PUSH | Push next wk-byte to the stack.
`wwwwwwkw`| POP | Pop the stack.
`wwwwwwkk`| ADD | Add 2 top element of the stack.
`wwwwwkww`| SUB | Subtract 2nd top element of stack with top of stack.
`wwwwwkwk`| MUL | Multiply 2 top element of the stack.
`wwwwwkkw`| DIV | Divide 2nd top element of stack with top of stack.
`wwwwkwww`| JMP | Move the ip according to the next wk-byte.
`wwwwkwwk`| SWAP | Swap the last byte of ac with top of stack.
`wwwwkwkw`| PUSHX| Push the last byte of ac to the stack.
`wwwwkwkk`| POPX | Pop the stack & save the value to the last byte of ac.
`wwwwkkww`| JE | JMP if last byte of ac is equal to top of stack.
`wwwwkkwk`| JNE | JMP if last byte of ac is not equal to top of stack
`wwwwkkkw`| JLT | JMP if last byte of ac less than top of stack.
`wwwwkkkk`| JGT | JMP if last byte of ac greater than top of stack.
`wwwkwwkw`| PRINT | Print top of stack.
`wwwkwwkk`| SCAN | Read one byte input, push the value to the stack.
`wwwkwkww`| SHR | Logical shift the ac 8 bit to the right.
`wwwkwkwk`| SHL | Shift the ac 8 bit to the left.

## Build
Untuk menjalankan program dalam bahasa ini, interpreter `boi` harus di-build terlebih dahulu dengan menjalankan perintah berikut.
```
make
```

## Run
Source code program dalam bahasa ini dapat dijalankan dengan menggunakan interpreter `boi`.
```
./boi <wkwk-source-code>
```
Pada folder `example` telah disediakan beberapa program wkwk-lang, misalnya program cat sederhana yang dapat dijalankan dengan:
```
./boi example/cat.wkwk
```

## Example
Berikut ini adalah beberapa contoh program yang dituliskan pada bahasa ini.

### 1. Program Cat sederhana
```
wwwkwwkkwwwkwwkwwwwwkwwwwwwwwwww
```

### 2. Program HelloWorld "sederhana"
```
wwwwwwwkwwwwwwwwwwwwkwkkwwwwkwkwwwwwwwwkwwwwkwkwwwwwwwwkwwkwwwwkwwwwwwwkwkkwwkwwwwwwwwwkwkkwkkwwwwwwwwwkwkkkwwkwwwwwwwwkwkkwkkkkwwwwwwwkwkkkwkkkwwwwwwwkwwkwwwwwwwwwwwwkwkkwkkkkwwwwwwwkwkkwkkwwwwwwwwwkwkkwkkwwwwwwwwwkwkkwwkwkwwwwwwwkwkkwkwwwwwwkwwkwwwwwwwkwwwwwkkwkwwwkkkkwwwwwwwww
```

## test
`
wwwwwwwkwwwwwwwwwwwwkwkkwwwwkwkwwwwwwwwkwwwwkwkwwwwwwwwkwwkwwwwkwwwwwwwkwkkwwkwwwwwwwwwkwkkwkkwwwwwwwwwkwkkkwwkwwwwwwwwkwkkwkkkkwwwwwwwkwkkkwkkkwwwwwwwkwwkwwwwwwwwwwwwkwkkwkkkkwwwwwwwkwkkwkkwwwwwwwwwkwkkwkkwwwwwwwwwkwkkwwkwkwwwwwwwkwkkwkwwwwwwkwwkwwwwwwwkwwwwwkkwkwwwkkkkwwwwwwwww
`