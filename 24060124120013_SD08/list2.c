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
        free(P);
    }
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
    address P;
    infotype temp;

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
            next(P) = next(First(*L));
            next(First(*L)) = P;

            temp = info(First(*L));
            info(First(*L)) = V;
            info(P) = temp;
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
        // end while next(Q) == First(L)
        First(*L) = next(P);
        next(Q) = First(*L);
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
    infotype temp;

    // algoritma
    found = false;
    if (!IsEmptyList(*L))
    {
        P = First(*L);
        if (info(P) == X)
        {
            DeleteVFirst(L, &temp);
        }
        else
        {
            do
            {
                Q = next(P);
                if (info(Q) == X)
                {
                    next(P) = next(Q);
                    Dealokasi(Q);
                    found = true;
                }
                P = next(P);
            } while (P != First(*L) && !found);
            // end while - P == First(L)
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A)
{
    // kamus lokal
    address P;
    boolean found;

    // algoritma
    P = First(L);
    *A = NIL;
    found = false;
    if (!IsEmptyList(L))
    {
        do
        {
            if (info(P) == X)
            {
                *A = P;
                found = true;
            }
            P = next(P);
        } while (P != First(L) && !found);
        // end while - P == First(L)
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y)
{
    // kamus lokal
    address P;

    // algoritma
    P = First(*L);
    do
    {
        if (info(P) == X)
        {
            info(P) = Y;
        }
        P = next(P);
    } while (P != First(*L));
    // end while - P == First(L)
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik,
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyList(*L) && !IsOneElm(*L))
    {
        address Prev = NIL;
        address Current = First(*L);
        address Next = NIL;
        do
        {
            Next = next(Current);
            next(Current) = Prev;
            Prev = Current;
            Current = Next;
        } while (Current != First(*L));
        // end while - Current == First(L)
        next(First(*L)) = Prev;
        First(*L) = Prev;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X)
{
    // kamus lokal
    address P;
    int count;

    // algoritma
    count = 0;
    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            if (info(P) == X)
            {
                count++;
            }
            P = next(P);
        } while (P != First(L));
        // end while - P == First(L)
    }
    return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X)
{
    // kamus lokal
    int count;

    // algoritma
    count = CountX(L, X);
    if (count == 0)
    { // tidak pernah muncul
        return 0;
    }
    else
    { // muncul minimal satu kali
        return (float)count / NbElm(L);
    }
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L)
{
    // kamus lokal
    address P;
    int count;

    // algoritma
    count = 0;
    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            if (info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o' ||
                info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O')
            { // isi P sama dengan huruf vokal, baik lowercase maupun uppercase
                count++;
            }
            P = next(P);
        } while (P != First(L));
        // end while - P == First(L)
    }
    return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L)
{
    // kamus lokal
    address P;
    int count;

    // algoritma
    count = 0;
    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            if (info(P) == 'N' && info(next(P)) == 'G')
            {
                count++;
            }
            P = next(P);
        } while (P != First(L));
        // end while - P == First(L)
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V)
{
    // kamus lokal
    address P, Q;
    boolean found;

    // algoritma
    found = false;
    if (!IsEmptyList(*L))
    {
        Q = First(*L);
        do
        {
            if (info(Q) == X)
            {
                P = Alokasi(V);
                if (P != NIL)
                {
                    next(P) = next(Q);
                    next(Q) = P;
                }
                found = true; // keluar dari loop setelah menyisipkan
            }
            Q = next(Q);
        } while (Q != First(*L) && !found);
        // end while - Q == First(L) or found == true
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V)
{
    // kamus lokal
    address P, Q, R;
    boolean found;

    // algoritma
    found = false;
    if (!IsEmptyList(*L))
    {
        Q = First(*L);
        R = NIL;
        do
        {
            if (info(Q) == X)
            {
                P = Alokasi(V);
                if (P != NIL)
                {
                    if (R == NIL)
                    { // elemen sebelum Q adalah elemen pertama
                        InsertVFirst(L, V);
                    }
                    else
                    {
                        next(P) = Q;
                        next(R) = P;
                    }
                }
                found = true; // keluar dari loop setelah menyisipkan
            }
            R = Q;
            Q = next(Q);
        } while (Q != First(*L) && !found);
        // end while - Q == First(L) or found == true
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V)
{
    // kamus lokal
    address P, Q;
    boolean found;

    // algoritma
    found = false;
    if (!IsEmptyList(*L))
    {
        Q = First(*L);
        do
        {
            if (info(Q) == X)
            {
                P = next(Q);
                *V = info(P);
                next(Q) = next(P);

                // Jika elemen yang dihapus adalah First, update First
                if (P == First(*L))
                {
                    First(*L) = next(P);
                }

                Dealokasi(P);
                found = true; // keluar dari loop setelah penghapusan
            }
            Q = next(Q);
        } while (Q != First(*L) && !found);
        // end while - Q == First(L) or found == true
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V)
{
    // kamus lokal
    address P, Q, R, Prev;
    boolean found;

    // algoritma
    found = false;
    *V = '#'; // default value
    if (!IsEmptyList(*L))
    {
        // Cari elemen X dan track elemen sebelum-sebelumnya
        Q = First(*L);
        R = NIL;    // elemen tepat sebelum Q
        Prev = NIL; // elemen sebelum R

        // Cari elemen terakhir sebagai Prev awal
        if (!IsOneElm(*L))
        {
            Prev = First(*L);
            while (next(Prev) != First(*L))
            {
                Prev = next(Prev);
            }
        }

        do
        {
            if (info(Q) == X)
            {
                if (R == NIL)
                { // elemen sebelum Q adalah elemen terakhir (First)
                    // Hapus First, yang merupakan elemen sebelum X
                    DeleteVFirst(L, V);
                }
                else if (Prev == NIL)
                { // hanya ada 2 elemen, hapus yang pertama
                    DeleteVFirst(L, V);
                }
                else
                {
                    // Hapus R (elemen sebelum X)
                    P = R;
                    *V = info(P);
                    next(Prev) = Q; // ✅ Update link: Prev -> Q (skip R)
                    Dealokasi(P);
                }
                found = true; // keluar dari loop setelah penghapusan
                break;
            }
            Prev = R;
            R = Q;
            Q = next(Q);
        } while (Q != First(*L) && !found);
        // end while - Q == First(L) or found == true
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi.
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X)
{
    // kamus lokal
    address P, Q, Prev;

    // algoritma
    if (!IsEmptyList(*L))
    {
        // Hapus semua elemen X dari First sampai ada elemen non-X
        while (!IsEmptyList(*L) && info(First(*L)) == X)
        {
            infotype temp;
            DeleteVFirst(L, &temp);
        }

        // Jika list masih ada isi, hapus elemen X di tengah/akhir
        if (!IsEmptyList(*L) && !IsOneElm(*L))
        {
            Prev = First(*L);
            P = next(Prev);

            do
            {
                if (info(P) == X)
                {
                    // Hapus P
                    Q = next(P);
                    next(Prev) = Q;
                    Dealokasi(P);
                    P = Q; // Lanjut ke elemen berikutnya
                }
                else
                {
                    // Lanjut ke elemen berikutnya
                    Prev = P;
                    P = next(P);
                }
            } while (P != First(*L));
        }
    }
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X)
{
    // kamus lokal
    address P;
    int position;
    boolean found;

    // algoritma
    found = false;
    position = 1;

    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            if (info(P) == X)
            {
                if (found)
                {
                    printf(",%d", position);
                }
                else
                {
                    printf("%d", position);
                    found = true;
                }
            }
            position++;
            P = next(P);
        } while (P != First(L));
        // end while - P == First(L)
    }

    if (!found)
    {
        printf("0");
    }
    printf("\n");
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L)
{
    // kamus lokal
    address P;
    int max;
    infotype currentChar;

    // algoritma
    max = 0;

    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            currentChar = info(P);
            int count = CountX(L, currentChar);
            if (count > max)
            {
                max = count;
            }
            P = next(P);
        } while (P != First(L));
        // end while - P == First(L)
    }

    return max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L)
{
    // kamus lokal
    address P;
    int maxCount, currentCount;
    infotype modusChar, currentChar;

    // algoritma
    maxCount = 0;
    modusChar = '#';

    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            currentChar = info(P);
            currentCount = CountX(L, currentChar);
            if (currentCount > maxCount)
            {
                maxCount = currentCount;
                modusChar = currentChar;
            }
            P = next(P);
        } while (P != First(L));
        // end while - P == First(L)
    }

    return modusChar;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L)
{
    // kamus lokal
    address P;

    // algoritma
    CreateList(L);

    // Salin semua elemen dari L1
    if (!IsEmptyList(L1))
    {
        P = First(L1);
        do
        {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
        // end while - P == First(L1)
    }

    // Salin semua elemen dari L2
    if (!IsEmptyList(L2))
    {
        P = First(L2);
        do
        {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L2));
        // end while - P == First(L2)
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2)
{
    // kamus lokal
    address P;
    int count, mid, i;

    // algoritma
    CreateList(L1);
    CreateList(L2);

    if (!IsEmptyList(L))
    {
        count = NbElm(L);
        mid = (count + 1) / 2; // Pembulatan ke atas untuk list ganjil

        P = First(L);
        i = 1;

        // Masukkan elemen pertama sampai mid ke L1
        do
        {
            if (i <= mid)
            {
                InsertVLast(L1, info(P));
            }
            else
            {
                InsertVLast(L2, info(P));
            }
            i++;
            P = next(P);
        } while (P != First(L));
        // end while - P == First(L)
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2)
{
    // kamus lokal
    address P;

    // algoritma
    CreateList(L2);

    if (!IsEmptyList(L1))
    {
        P = First(L1);
        do
        {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
        // end while - P == First(L1)
    }
}