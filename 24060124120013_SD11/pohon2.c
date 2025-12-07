/* File : pohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza */
/* Tanggal : 4-12-2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H)
{
    // kamus lokal
    int i;

    // algoritma
    if (!IsEmptyTree(P))
    {
        printf("%c\n", info(P));

        if (!IsEmptyTree(GetLeft(P)) || !IsEmptyTree(GetRight(P)))
        {
            for (i = 0; i < H; i++)
            {
                printf(" ");
            }
            PrintTreeInden(GetLeft(P), H + 3);

            for (i = 0; i < H; i++)
            {
                printf(" ");
            }
            PrintTreeInden(GetRight(P), H + 3);
        }
    }
    else
    {
        printf("()\n");
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (info(*P) == X)
        {
            info(*P) = Y;
        }
        else
        {
            UpdateX(&left(*P), X, Y);
            UpdateX(&right(*P), X, Y);
        }
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(*P))
    {
        info(*P) = X;
    }
    else if (IsDaun(*P) || IsUnerRight(*P))
    {
        left(*P) = AlokasiTree(X);
    }
    else
    {
        AddDaunTerkiri(&(left(*P)), X);
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (info(*P) == X && IsDaun(*P))
        {
            if (Kiri)
            {
                left(*P) = AlokasiTree(Y);
            }
            else
            {
                right(*P) = AlokasiTree(Y);
            }
        }
        else
        {
            AddDaun(&(left(*P)), X, Y, Kiri);
            AddDaun(&(right(*P)), X, Y, Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(*P))
    {
        *P = AlokasiTree(X);
    }
    else
    {
        if (!SearchX(*P, X))
        {
            AddDaunTerkiri(&(*P), X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X)
{
    // kamus lokal
    bintree T;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (IsDaun(*P))
        {
            *X = info(*P);
            DealokasiTree(P);
        }
        else if (IsDaun(GetLeft(*P)))
        {
            T = left(*P);
            *X = info(T);
            left(*P) = NIL;

            DealokasiTree(&T);
        }
        else
        {
            DelDaunTerkiri(&(left(*P)), X);
            DelDaunTerkiri(&(right(*P)), X);
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X)
{
    // kamus lokal
    bintree T;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (IsDaun(*P) && info(*P) == X)
        {
            DealokasiTree(P);
        }
        else if (IsDaun(GetLeft(*P)) && info(GetLeft(*P)) == X)
        {
            T = left(*P);
            left(*P) = NIL;

            DealokasiTree(&T);
        }
        else
        {
            DelDaun(&(left(*P)), X);
            DelDaun(&(right(*P)), X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (info(*P) == X)
        {
            DealokasiTree(P);
        }
        else
        {
            DeleteX(&(left(*P)), X);
            DeleteX(&(right(*P)), X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n)
{
    // kamus lokal
    bintree P;
    infotype X;
    int nL, nR;

    // algoritma
    if (n <= 0)
    {
        return NIL;
    }
    else
    {
        printf("Masukkan nilai node: ");
        scanf(" %c", &X);
        nL = n / 2;
        nR = n - nL - 1;
        P = Tree(X, BuildBalanceTree(nL), BuildBalanceTree(nR));
        return P;
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P)
{
    // kamus lokal
    int leftCount, rightCount;

    // algoritma
    if (IsEmptyTree(P))
    {
        return true;
    }
    else
    {
        leftCount = NbElm(GetLeft(P));
        rightCount = NbElm(GetRight(P));
        return (abs(leftCount - rightCount) <= 1) &&
               IsBalanceTree(GetLeft(P)) &&
               IsBalanceTree(GetRight(P));
    }
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P)
{
    // kamus lokal
    int maxLeft, maxRight, currentMax;

    // algoritma
    if (IsEmptyTree(P))
    {
        return '\0'; // Mengembalikan karakter null jika pohon kosong
    }
    else
    {
        currentMax = info(P);
        maxLeft = maxTree(GetLeft(P));
        maxRight = maxTree(GetRight(P));

        if (maxLeft > currentMax)
        {
            currentMax = maxLeft;
        }
        if (maxRight > currentMax)
        {
            currentMax = maxRight;
        }
        return currentMax;
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P)
{
    // kamus lokal
    int minLeft, minRight, currentMin;

    // algoritma
    if (IsEmptyTree(P))
    {
        return '\177'; // Mengembalikan karakter tertinggi jika pohon kosong
    }
    else
    {
        currentMin = info(P);
        minLeft = minTree(GetLeft(P));
        minRight = minTree(GetRight(P));

        if (minLeft < currentMin)
        {
            currentMin = minLeft;
        }
        if (minRight < currentMin)
        {
            currentMin = minRight;
        }
        return currentMin;
    }
}

/* Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan */

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return false;
    }
    else if (info(P) == X)
    {
        return true;
    }
    else if (X < info(P))
    {
        return BSearch(GetLeft(P), X);
    }
    else
    {
        return BSearch(GetRight(P), X);
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return AlokasiTree(X);
    }
    else if (X < info(P))
    {
        left(P) = InsSearch(GetLeft(P), X);
    }
    else if (X > info(P))
    {
        right(P) = InsSearch(GetRight(P), X);
    }
    return P;
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X)
{
    // kamus lokal
    bintree T;
    infotype Y;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (X < info(*P))
        {
            DelBtree(&left(*P), X);
        }
        else if (X > info(*P))
        {
            DelBtree(&right(*P), X);
        }
        else
        {
            // Node yang akan dihapus ditemukan
            if (IsDaun(*P))
            {
                DealokasiTree(P);
            }
            else if (IsUnerLeft(*P))
            {
                T = *P;
                *P = GetLeft(*P);
                DealokasiTree(&T);
            }
            else if (IsUnerRight(*P))
            {
                T = *P;
                *P = GetRight(*P);
                DealokasiTree(&T);
            }
            else
            {
                // Node dengan dua anak
                // Cari pengganti dari subtree kanan (nilai terkecil)
                bintree successor = GetRight(*P);
                while (!IsEmptyTree(GetLeft(successor)))
                {
                    successor = GetLeft(successor);
                }
                Y = info(successor);
                info(*P) = Y;            // Ganti nilai node yang dihapus dengan nilai successor
                DelBtree(&right(*P), Y); // Hapus node successor
            }
        }
    }
}