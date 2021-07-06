# WKWK LANG - Stack-Based Esolang

Wkwk-lang adalah sebuah [bahasa pemrograman esoterik](https://en.wikipedia.org/wiki/Esoteric_programming_language) yang diimplementasikan secara stack-based. Selain memiliki stack memory, bahasa ini juga memiliki 3 buah register 32-bit, yaitu ip (instruction pointer), sp (stack pointer), dan ac (accumulator).

## Syntax

Bahasa ini hanya terdiri dari 2 simbol yaitu 'w' dan 'k'. Pada bahasa ini, setiap 'wk-byte' terdiri dari 8 'wk-bit', dan setiap 'wk-bit' memiliki dua kemungkinan nilai yaitu 'w' atau 'k'. Aturan pada wk-byte sama seperti aturan biner, dengan mengganti 0 menjadi w dan 1 menjadi k. Contohnya, `wwwwwwww` bernilai 0, `wwwwwwwk` bernilai 1,
`wwwwwkwk` bernilai 5, dst.

Semua instruksi dan konstanta pada bahasa ini dituliskan dalam wk-byte. Misalnya untuk `wwwwwwwkwkwkwkwk`, wk-byte pertama `wwwwwwwk` adalah instruksi untuk push, dan wk-byte kedua `wkwkwkwk` adalah konstanta 85, maka ketika perintah tersebut dijalankan, yang dilakukan adalah push 85 ke stack.

Bahasa ini juga dilengkapi dengan penanganan syntax error, yaitu ketika ada karakter lain selain w dan k atau ketika panjang source code bukan merupakan kelipatan 8 (ingat bahwa semua instruksi dituliskan dalam wk-byte).

## Command

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