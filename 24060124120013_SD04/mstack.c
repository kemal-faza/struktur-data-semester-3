#include <stdio.h>
#include "stack.h"

/* Program   : mstack.c */
/* Deskripsi : driver ADT stack karakter */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 21-09-2025 */
/***********************************/

int main()
{
    // kamus
    Tstack S;
    char e;

    // algoritma
    createStack(&S);
    printStack(S);
    return 0;
}