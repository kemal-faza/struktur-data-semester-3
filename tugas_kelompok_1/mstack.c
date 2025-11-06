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

    // algoritma
    printf(isValidKurung("({[]})", 6) ? "({[]}) is Valid\n" : "({[]}) is Not Valid\n");
    printf(isValidKurung("({[})", 5) ? "({[}) is Valid\n" : "({[}) is Not Valid\n");
    printf(isValidKurung("({[]})]", 7) ? "({[]})] is Valid\n" : "({[]})] is Not Valid\n");
    printf(isValidKurung("((()))", 6) ? "((())) is Valid\n" : "((())) is Not Valid\n");
    printf(isValidKurung("(()))", 5) ? "(())) is Valid\n" : "(())) is Not Valid\n");

    return 0;
}