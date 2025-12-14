/* File : pohon3.h */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza */
/* Tanggal : 11/12/2025 */

#include "pohon3.h"

/************************ PROTOTYPE ************************/
/********** PEMBUATAN POHON BARU ***********/
/* function Tree3 (A; bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3(bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan)
{
    // kamus lokal
    bintree3 T;

    // algoritma
    T = (bintree3)malloc(sizeof(node3));
    info(T) = X;
    parent(T) = A;
    visited(T) = V;
    left(T) = kiri;
    right(T) = kanan;

    if (kiri != NIL)
        parent(kiri) = T;

    if (kanan != NIL)
        parent(kanan) = T;

    return T;
}

/* penelusuran */
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        printf("( )");
    }
    else
    {
        printf("(");

        // print terkiri dahulu
        printDFS(left(P));

        // baru print parentnya
        printf("%c", info(P));

        // lalu masuk ke yang kanan
        printDFS(right(P));

        printf(")");
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2(int a, int b)
{
    // kamus lokal

    // algoritma
    return a > b ? a : b;
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    { // tree kosong
        return -1;
    }
    else
    { // tree tidak kosong
        return 1 + Max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree3 P, int N)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P) && N >= 1)
    {
        if (N == 1)
        {
            printf("%c, ", info(P));
        }
        else
        {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS(bintree3 P)
{
    // kamus lokal
    int i;

    // algoritma
    for (i = 1; i <= Level(P); i++)
    {
        PrintLevel(P, i);
    }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree(bintree3 P)
{
    // kamus lokal

    // algoritma
    return P == NIL;
}

/* function IsDaun (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree3 P)
{
    // kamus lokal

    // algoritma
    return !IsEmptyTree(P) && IsEmptyTree(left(P)) && IsEmptyTree(right(P));
}

/* function IsBiner (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree3 P)
{
    // kamus lokal

    // algoritma
    return !IsEmptyTree(P) && !IsEmptyTree(left(P)) && !IsEmptyTree(right(P));
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree3 P)
{
    // kamus lokal

    // algoritma
    return !IsEmptyTree(P) && !IsEmptyTree(left(P)) && IsEmptyTree(right(P));
}

/* function IsUnerRight(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree3 P)
{
    // kamus lokal

    // algoritma
    return !IsEmptyTree(P) && IsEmptyTree(left(P)) && !IsEmptyTree(right(P));
}

/*PENELUSURAN*/
/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        visited(P) = false;

        resetVisited(left(P));
        resetVisited(right(P));
    }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX(bintree3 P, infotype X)
{
    // kamus lokal
    List1 path;
    bintree3 current;

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (info(P) == X)
        {
            CreateList(&path);
            current = P;

            while (current != NIL)
            {
                InsertVFirst(&path, info(current));
                current = parent(current);
            }

            PrintList(path);
        }
        else
        {
            printPathX(left(P), X);
            printPathX(right(P), X);
        }
    }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX(bintree3 P, infotype X)
{
    // kamus lokal
    List1 path;
    bintree3 current;

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (info(P) == X && IsDaun(P))
        {
            CreateList(&path);
            current = P;

            while (current != NIL)
            {
                InsertVFirst(&path, info(current));
                current = parent(current);
            }

            PrintList(path);
        }
        else
        {
            printPathDaunX(left(P), X);
            printPathDaunX(right(P), X);
        }
    }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths(bintree3 P)
{
    // kamus lokal
    List1 path;
    bintree3 current;

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (IsDaun(P))
        {
            CreateList(&path);
            current = P;

            while (current != NIL)
            {
                InsertVFirst(&path, info(current));
                current = parent(current);
            }

            PrintList(path);
        }
        else
        {
            printAllPaths(left(P));
            printAllPaths(right(P));
        }
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else
    {
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else if (IsDaun(P))
    {
        return 1;
    }
    else
    {
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level(bintree3 P)
{
    // kamus lokal

    // algoritma
    return Tinggi(P) + 1;
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree3 P, int T)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P) || T < 1)
    {
        return 0;
    }
    else if (T == 1)
    {
        return 1;
    }
    else
    {
        return CountLevelT(left(P), T - 1) + CountLevelT(right(P), T - 1);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
// printList sudah ADA di list1.h

/*procedure Pconcat( input/output Asli:List1, input Tambahan:List1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat(List1 *Asli, List1 Tambahan)
{
    // kamus lokal

    // algoritma
    ConcatList(*Asli, Tambahan, &(*Asli));
}

/*function fconcat( Asli:List1, Tambahan:List1) -> List1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat(List1 Asli, List1 Tambahan)
{
    // kamus lokal
    List1 output;

    // algoritma
    CreateList(&output);

    ConcatList(Asli, Tambahan, &output);

    return output;
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> List1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix(bintree3 P)
{
    // kamus lokal
    List1 L, Lkiri, Lkanan;

    // algoritma
    CreateList(&L);
    if (!IsEmptyTree(P))
    {
        InsertVLast(&L, info(P));
        Lkiri = LinearPrefix(left(P));
        Lkanan = LinearPrefix(right(P));

        Pconcat(&L, Fconcat(Lkiri, Lkanan));
    }

    return L;
}

/*function linearPosfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix(bintree3 P)
{
    // kamus lokal
    List1 L, Lkiri, Lkanan;

    // algoritma
    CreateList(&L);
    if (!IsEmptyTree(P))
    {
        Lkiri = LinearPosfix(left(P));
        Lkanan = LinearPosfix(right(P));

        Pconcat(&L, Fconcat(Lkiri, Lkanan));
        InsertVLast(&L, info(P));
    }

    return L;
}

/*function linearInfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix(bintree3 P)
{
    // kamus lokal
    List1 L, Lkiri, Lkanan;

    // algoritma
    CreateList(&L);
    if (!IsEmptyTree(P))
    {
        Lkiri = LinearInfix(left(P));
        Lkanan = LinearInfix(right(P));

        Pconcat(&L, Lkiri);
        InsertVLast(&L, info(P));
        Pconcat(&L, Lkanan);
    }

    return L;
}

/*function LevelTree(P:bintree3) -> List1
{menghasilkan list node dari P di level N}*/
List1 LevelTree(bintree3 P, int N)
{
    // kamus lokal
    List1 L;

    // algoritma
    CreateList(&L);
    if (!IsEmptyTree(P) && N >= 1)
    {
        if (N == 1)
        {
            InsertVLast(&L, info(P));
        }
        else
        {
            Pconcat(&L, LevelTree(left(P), N - 1));
            Pconcat(&L, LevelTree(right(P), N - 1));
        }
    }

    return L;
}

/*function linearBreadthFS(P:bintree3) -> List1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS(bintree3 P)
{
    // kamus lokal
    List1 L;
    int i;

    // algoritma
    CreateList(&L);
    if (!IsEmptyTree(P))
    {
        for (i = 1; i <= Level(P); i++)
        {
            Pconcat(&L, LevelTree(P, i));
        }
    }

    return L;
}