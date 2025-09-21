/* Program   : stack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 21-09-2025 */
/***********************************/

#include "stack.h"
#include <stdio.h>

/* KONSTRUKTOR */
/* procedure createStack(output S: Tstack)
    {I.S.: - }
    {F.S.: Stack S terdefinisi}
    {Proses mengisi elemen wadah kosong dengan '_', top 0} */
void createStack(Tstack *S)
{
    (*S).top = 0;
    for (int i = 1; i <= 10; i++)
    {
        (*S).wadah[i] = '_';
    }
}

/* SELEKTOR */
/* function infoTop(S: Tstack) -> character
    {mengembalikan nilai elemen puncak} */
int infoTop(Tstack S)
{
    if (S.top > 0)
    {
        return S.wadah[top(S)];
    }
    return -1; // Menandakan stack kosong
}

/* function top(S: Tstack) -> integer
    {mengembalikan posisi puncak} */
int top(Tstack S)
{
    return S.top;
}

/* PREDIKAT */
/* function isEmptyStack(S: Tstack) -> boolean
    {mengembalikan True jika matriks M kosong } */
boolean isEmptyStack(Tstack S)
{
    return (S.top == 0);
}

/* function isFullStack(S: Tstack) -> boolean
    {mengembalikan True jika matriks M penuh } */
boolean isFullStack(Tstack S)
{
    return (S.top == 10);
}

/* MUTATOR */
/* procedure push(input/output S:Tstack, input e:character)
    {I.S.: S, e terdefinisi, S mungkin kosong}
    {F.S.: S tetap, atau infoTop(S) = e}
    {Proses: mengisi elemen e ke puncak S, bila belum penuh} */
void push(Tstack *S, char e)
{
    if (!isFullStack(*S))
    {
        (*S).top++;
        (*S).wadah[(*S).top] = e;
    }
}

/* procedure push(input/output S:Tstack, output e:character)
    {I.S.: S terdefinisi, mungkin kosong}
    {F.S.: S tetap, atau e berisi infoTop(S) lama}
    {Proses: menghapus elemen e dari puncak S, bila belum kosong} */
void pop(Tstack *S, char *e)
{
    if (!isEmptyStack(*S))
    {
        *e = (*S).wadah[(*S).top];
        (*S).wadah[(*S).top] = '_';
        (*S).top--;
    }
}

/* procedure printStack(input S:Tstack)
    {I.S.: S terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen S ke layar} */
void printStack(Tstack S)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%c ", S.wadah[i]);
    }
    printf("\n");
}

/* procedure viewStack (input S:Tstack)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen S yang terisi ke layar} */
void viewStack(Tstack S)
{
    for (int i = 1; i <= S.top; i++)
    {
        printf("%c ", S.wadah[i]);
    }
    printf("\n");
}

/* OPERASI LAINNYA */
// masukkan deskripsi dan spesifikasi fungsi pada soal di sini