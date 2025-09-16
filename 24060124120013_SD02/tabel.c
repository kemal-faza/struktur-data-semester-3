#ifndef tabel_c
#define tabel_c
#include "tabel.h"
#include <string.h>
/* Deskripsi : Implementasi dari tipe data dan primitif ADT Tabel */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 11-09-2025 */

/************************KONSTRUKTOR*************************/
/* procedure createTable( output T: Tabel)
    {I.S.: -}
    {F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
    {Proses: menginisialisasi T} */
void createTable(Tabel *T)
{
    // kamus lokal
    int i;

    // algoritma
    for (i = 0; i < sizeof T; i++)
    {
        (*T).wadah[i] = ' ';
    }
    (*T).size = 0;
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
    {mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T)
{
    // kamus lokal

    // algoritma
    return T.size;
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
    {mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T)
{
    // kamus lokal

    // algoritma
    return getSize(T) == 0;
}

/* function isFullTable( T: Tabel) -> boolean
    {mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T)
{
    // kamus lokal

    // algoritma
    return getSize(T) == sizeof T.wadah;
}

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
    {I.S.: T terdefinisi, x terdefinisi }
    {F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
    {Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos)
{
    // kamus lokal
    int i;
    boolean found;

    // algoritma
    i = 1;
    found = false;
    *pos = -999;

    while (i <= getSize(T) && !found)
    {
        if (T.wadah[i] == x)
        {
            *pos = i;
            found = true;
        }
        i++;
    }
}

/* function countX (T:Tabel, x:character) -> integer
    {mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x)
{
    // kamus lokal
    int i, count;

    // algoritma
    count = 0;

    for (i = 1; i <= getSize(T); i++)
    {
        if (T.wadah[i] == x)
        {
            count++;
        }
    }

    return count;
}

/* function countVocal(T: Tabel) -> integer
    {mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
int countVocal(Tabel T)
{
    // kamus lokal
    int i, j, count;
    char vocalChar[11] = {'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};

    // algoritma
    count = 0;

    for (i = 1; i <= getSize(T); i++)
    {
        for (j = 0; j < (sizeof vocalChar) - 1; j++)
        {
            if (T.wadah[i] == vocalChar[j])
            {
                count++;
            }
        }
    }

    return count;
}

/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
    {I.S.: T terdefinisi, x terdefinisi }
    {F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
    {Proses: mengisi elemen T.wadah dengan nilai x}*/
void addXTable(Tabel *T, char x)
{
    // kamus lokal
    int sizeTabel;

    // algoritma
    sizeTabel = getSize(*T) + 1;
    if (!isFullTable(*T))
    {
        (*T).wadah[sizeTabel] = x;
        (*T).size = sizeTabel;
    }
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
    {I.S.: T terdefinisi, x terdefinisi }
    {F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
    {Proses: mengisi elemen T.wadah dengan nilai unik x}*/
void addUniqueXTable(Tabel *T, char x)
{
    // kamus lokal
    int *pos;

    // algoritma
    searchX(*T, x, &(*pos));
    if (*pos != -999)
    {
        addXTable(&(*T), x);
    }
}

/* procedure delXTable (input/output T:Tabel, input x:character)
    {I.S.: T terdefinisi, x terdefinisi}
    {F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
    {Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x)
{
    // kamus lokal
    int i, sizeTabel, pos;

    // algoritma
    sizeTabel = getSize(*T);
    searchX(*T, x, &pos);
    delTable(&(*T), pos);
}

/* procedure delTable (input/output T:Tabel, input idx:integer)
    {I.S.: T terdefinisi, idx antara 1...getSize(T)}
    {F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
    {Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx)
{
    // kamus lokal
    int i, sizeTabel;

    // algoritma
    sizeTabel = getSize(*T);

    for (i = idx; i <= sizeTabel; i++)
    {
        if (i == sizeof(*T).wadah)
        {
            (*T).wadah[i] = ' ';
        }
        else
        {
            (*T).wadah[i] = (*T).wadah[i + 1];
        }
        (*T).size = sizeTabel - 1;
    }
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
    {I.S.: T terdefinisi}
    {F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
    {Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x)
{
    // kamus lokal
    int i, sizeTabel, pos;

    // algoritma
    sizeTabel = getSize(*T) + 1;
    searchX(*T, x, &pos);

    while (pos != -999)
    {
        delTable(&(*T), pos);
    }
}

/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T)
{
    // kamus lokal
    int i, maxSizeTabel;

    // algoritma
    maxSizeTabel = sizeof T.wadah;
    for (i = 1; i < maxSizeTabel; i++)
    {
        i != maxSizeTabel - 1 ? printf("%c | ", T.wadah[i]) : printf("%c", T.wadah[i]);
    }
    printf("\n");
}

/* procedure viewTable (input T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T)
{
    // kamus lokal
    int i, sizeTabel;

    // algoritma
    sizeTabel = getSize(T);
    for (i = 1; i <= sizeTabel; i++)
    {
        i != sizeTabel ? printf("%c | ", T.wadah[i]) : printf("%c", T.wadah[i]);
    }
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
    {I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
    {F.S.: T.wadah terisi sebanyak N elemen }
    {Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
    {Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N)
{
    // kamus lokal
    int i, userInput;

    // algoritma
    i = 1;
    while (i <= N)
    {
        scanf("%c", &userInput);
        if (userInput > 0)
        {
            addXTable(&(*T), userInput);
            i++;
        }
        else
        {
            printf("input harus bilangan positif");
        }
    }

    (*T).size = N;
}

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> integer
    {mengembalikan elemen pengisi T yang paling banyak muncul } */
/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
char Modus(Tabel T)
{
    // kamus lokal
    int i, max, count;
    char maxChar;

    // algoritma
    max = 0;
    for (i = 1; i <= getSize(T); i++)
    {
        count = countX(T, T.wadah[i]);
        if (count > max)
        {
            max = count;
            maxChar = T.wadah[i];
        }
    }

    return maxChar;
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean
    {mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2)
{
    // kamus lokal
    int i;

    // algoritma
    if (getSize(T1) == getSize(T2))
    {
        for (i = 1; i <= getSize(T1); i++)
        {
            if (T1.wadah[i] != T2.wadah[i])
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}

/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel
    {mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T)
{
    // kamus lokal
    int i;
    Tabel newTabel;

    // algoritma
    createTable(&newTabel);
    for (i = getSize(T); i > 0; i--)
    {
        addXTable(&newTabel, T.wadah[i]);
    }

    return newTabel;
}

/* procedure inverseTable(input/output T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
    {Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T)
{
    *T = getInverseTable(*T);
}

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
    {Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T)
{
    // kamus lokal
    int i, pass, sizeTabel;
    char temp;

    // algoritma
    sizeTabel = getSize(*T);
    for (pass = 1; pass <= sizeTabel - 1; pass++)
    {
        for (i = sizeTabel; i >= pass + 1; i--)
        {
            if ((int)(*T).wadah[i] < (int)(*T).wadah[i - 1])
            {
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[i - 1];
                (*T).wadah[i - 1] = temp;
            }
        }
    }
}

/* procedure SortDesc ( input/output T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
    {Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T)
{
    // kamus lokal
    int i, pass, sizeTabel;
    char temp;

    // algoritma
    sizeTabel = getSize(*T);
    for (pass = 1; pass <= sizeTabel - 1; pass++)
    {
        for (i = sizeTabel; i >= pass + 1; i--)
        {
            if ((int)(*T).wadah[i] > (int)(*T).wadah[i - 1])
            {
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[i - 1];
                (*T).wadah[i - 1] = temp;
            }
        }
    }
}

#endif