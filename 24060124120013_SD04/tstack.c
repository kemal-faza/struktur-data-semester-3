/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 24-09-2025 */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
/* include tstack+boolean */

/*procedure createStack( output T: Tstack)
    {I.S.: -}
    {F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
    {Proses: menginisialisasi T} */
void createStack(Tstack *T)
{
    // kamus lokal
    int i;

    // algoritma
    (*T).top = 0;
    for (i = 1; i <= 10; i++)
    {
        (*T).wadah[i] = '#';
    }
}

/*function isEmptyStack( T: Tstack) -> boolean
    {mengembalikan True jika T kosong } */
boolean isEmptyStack(Tstack T)
{
    // kamus lokal

    // algoritma
    return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
    {mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T)
{
    // kamus lokal

    // algoritma
    return T.top == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
    {I.S.: T,E terdefinisi}
    {F.S.: infotop tetap, atau berisi nilai E }
    {Proses: mengisi elemen top baru, bila belum penuh }*/
void push(Tstack *T, char E)
{
    // kamus lokal

    // algoritma
    if (!isFullStack(*T))
    {
        (*T).top++;
        (*T).wadah[(*T).top] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
    {I.S.: T terdefinisi}
    {F.S.: X= infotop stack lama, atau '#' }
    {Proses: mengambil elemen top, bila belum kosong }*/
void pop(Tstack *T, char *X)
{
    // kamus lokal

    // algoritma
    if (!isEmptyStack(*T))
    {
        *X = (*T).wadah[(*T).top];
        (*T).wadah[(*T).top] = '#';
        (*T).top--;
    }
    else
    {
        *X = '#';
    }
}

/*procedure printStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan kondisi wadah T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void printStack(Tstack T)
{
    // kamus lokal
    int i;

    // algoritma
    for (i = 1; i <= 10; i++)
    {
        if (i == 10)
        {
            printf("%c\n", T.wadah[i]);
        }
        else
        {
            printf("%c ; ", T.wadah[i]);
        }
    }
}

/*procedure viewStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen tak kosong T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void viewStack(Tstack T)
{
    // kamus lokal
    int i;
    boolean first;

    // algoritma
    first = true;
    for (i = 1; i <= 10; i++)
    {
        if (T.wadah[i] != '#')
        {
            if (first)
            {
                printf("%c", T.wadah[i]);
                first = false;
            }
            else
            {
                printf(" ; %c", T.wadah[i]);
            }
        }
    }
    printf("\n");
}

/* boolean isPalindrom(kata:String)
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 20 karakter} */
boolean isPalindrom(char kata[20])
{
    // kamus lokal
    int i, len;
    Tstack S;
    char temp;

    // algoritma
    createStack(&S);
    i = 0;
    len = strlen(kata);

    for (i = 0; i <= len / 2; i++)
    {
        push(&S, kata[i]);
    }

    i = len;
    while (isEmptyStack(S))
    {
        pop(&S, &temp);
        if (kata[i] != temp)
        {
            return false;
        }
    }

    return true;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
    {I.S.: T,N terdefinisi}
    {F.S.: infotop tetap, atau top=N }
    {Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN(Tstack *T, int N)
{
    // kamus lokal
    int i;
    char input;

    // algoritma
    i = 0;
    while (!isFullStack(*T) && i < N)
    {
        printf("Masukkan input elemen ke-%d: ", top(*T) + 1);
        scanf(" %c", &input);
        push(&(*T), input);
        i++;
    }
}