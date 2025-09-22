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
    printf(isValidKurung("({[]})") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("({[})") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("((()))") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("((())") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("())") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung(")(") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("abc(def){ghi[jkl]}") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("abc(def{ghi[jkl]}") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("abc(def)ghi]jkl[") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("abc(def)ghi[jkl") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("abc)def(ghi[jkl]") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("abc(def)ghi[jkl]") ? "Valid\n" : "Tidak Valid\n");
    printf(isValidKurung("") ? "Valid\n" : "Tidak Valid\n");

    return 0;
}