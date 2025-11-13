#include "list2.h"
#include <stdio.h>
#include <stdlib.h>

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E} */
address Alokasi(infotype E)
{
    // kamus lokal
    address P;
    // algoritma
    P = (address)malloc(sizeof(Elm)); // casting
    if (P != NIL)
    {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
   Proses: Melakukan pengembalian address P} */
void Dealokasi(address P)
{
    // kamus lokal

    // algoritma
    if (P != NIL)
    { // P tidak kosong
        next(P) = NIL;
    }

    P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList(List2 *L)
{
    // kamus lokal

    // algoritma
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List2 L)
{
    // kamus lokal

    // algoritma
    return First(L) == NIL;
}

/* function IsOneElm(L:List2) --> boolean
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm(List2 L)
{
    // kamus lokal

    // algoritma
    return !IsEmptyList(L) && next(First(L)) == First(L);
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L)
{
    // kamus lokal
    address P;

    // algoritma
    if (!IsEmptyList(L))
    {
        P = First(L);
        while (next(P) != First(L))
        {
            printf("%c | ", info(P));
            P = next(P);
        };
        printf("%c\n", info(P));
        // end while - P == First(L)
    }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L)
{
    // kamus lokal
    int count;
    address P;

    // algoritma
    count = 0;

    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            count++;
            P = next(P);
        } while (P != First(L));
        // end while - P == First(L)
    }

    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V)
{
    // kamus lokal
    address P, Q;

    // algoritma
    P = Alokasi(V);
    if (P != NIL)
    {
        if (IsEmptyList(*L))
        {
            First(*L) = P;
            next(P) = P;
        }
        else
        {
            Q = First(*L);
            while (next(Q) != First(*L))
            {
                Q = next(Q);
            }
            // end while next(Q) == First(L)
            next(P) = next(First(*L));
            First(*L) = P;
            next(Q) = First(*L);
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V)
{
    // kamus lokal
    address P, Q;

    // algoritma
    P = Alokasi(V);
    if (P != NIL)
    {
        if (IsEmptyList(*L))
        {
            First(*L) = P;
            next(P) = P;
        }
        else
        {
            Q = First(*L);
            while (next(Q) != First(*L))
            {
                Q = next(Q);
            }
            // end while next(Q) == First(L)
            next(Q) = P;
            next(P) = First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V)
{
    // kamus lokal
    address P, Q;

    // algoritma
    if (IsEmptyList(*L))
    {
        *V = '#';
    }
    else if (IsOneElm(*L))
    {
        P = First(*L);
        *V = info(P);
        First(*L) = NIL;
        Dealokasi(P);
    }
    else
    {
        P = First(*L);
        *V = info(P);

        Q = First(*L);
        while (next(Q) != First(*L))
        {
            Q = next(Q);
        }
        // // end while next(Q) == First(L)
        next(Q) = next(First(*L));
        First(*L) = next(P);
        Dealokasi(P);
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V)
{
    // kamus lokal
    address P, Q;

    // algoritma
    if (IsEmptyList(*L))
    {
        *V = '#';
    }
    else if (IsOneElm(*L))
    {
        P = First(*L);
        *V = info(P);
        First(*L) = NIL;
        Dealokasi(P);
    }
    else
    {
        P = First(*L);
        while (next(next(P)) != First(*L))
        {
            P = next(P);
        }
        // end while next(next(P)) == First(L)
        Q = next(P);
        *V = info(Q);
        next(P) = First(*L);
        Dealokasi(Q);
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi.
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X)
{
    // kamus lokal
    address P, Q;
    boolean found;

    // algoritma
    if (!IsEmptyList(*L))
    {
        P = First(*L);
        while (next(next(P)) != First(*L) && !found)
        {
            if (info(next(P)) == X)
            {
                found = true;
                Q = next(P);
            }
        }
        // end while next(next(P)) == First(L)
        Q = next(P);
        next(P) = First(*L);
        Dealokasi(Q);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A);

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y);

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik,
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L);

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X);

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X);

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L);

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L);

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V);

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V);

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V);

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V);

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi.
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X);

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X);

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L);

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L);

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L);

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2);

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2);