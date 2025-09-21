#ifndef stack_H
#define stack_H

/* Program   : stack.h */
/* Deskripsi : file HEADER modul stack character */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 18-09-2025 */
/***********************************/

#include "boolean.h" //salin dari praktikum lalu

/* type Tstack = < wadah: array[1…10] of character,
                    top: integer > */
/* asumsi: indeks 0 tidak digunakan */
typedef struct
{
    char wadah[11];
    int top;
} Tstack;

/* KONSTRUKTOR */
/* procedure createStack(output S: Tstack)
    {I.S.: - }
    {F.S.: Stack S terdefinisi}
    {Proses mengisi elemen wadah kosong dengan '_', top 0} */
void createStack(Tstack *S);

/* SELEKTOR */
/* function infoTop(S: Tstack) -> character
    {mengembalikan nilai elemen puncak} */
int infoTop(Tstack S);

/* function top(S: Tstack) -> integer
    {mengembalikan posisi puncak} */
int top(Tstack S);

/* PREDIKAT */
/* function isEmptyStack(S: Tstack) -> boolean
    {mengembalikan True jika matriks M kosong } */
boolean isEmptyStack(Tstack S);

/* function isFullStack(S: Tstack) -> boolean
    {mengembalikan True jika matriks M penuh } */
boolean isFullStack(Tstack S);

/* MUTATOR */
/* procedure push(input/output S:Tstack, input e:character)
    {I.S.: S, e terdefinisi, S mungkin kosong}
    {F.S.: S tetap, atau infoTop(S) = e}
    {Proses: mengisi elemen e ke puncak S, bila belum penuh} */
void push(Tstack *S, char e);

/* procedure push(input/output S:Tstack, output e:character)
    {I.S.: S terdefinisi, mungkin kosong}
    {F.S.: S tetap, atau e berisi infoTop(S) lama}
    {Proses: menghapus elemen e dari puncak S, bila belum kosong} */
void push(Tstack *S, char e);

/* procedure printStack(input S:Tstack)
    {I.S.: S terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen S ke layar} */
void printStack(Tstack S);

/* procedure viewStack (input S:Tstack)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen S yang terisi ke layar} */
void viewStack(Tstack S);

/* OPERASI LAINNYA */
// masukkan deskripsi dan spesifikasi fungsi pada soal di sini

#endif