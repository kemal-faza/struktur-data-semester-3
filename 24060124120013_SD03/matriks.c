#ifndef matriks_c
#define matriks_c

/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 18-09-2025 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
/* include matriks.h & boolean.h */
#include "matriks.h"

/* KONSTRUKTOR */
/* procedure initMatriks(output M: Matriks)
    {I.S.: - }
    {F.S.: Matriks M terdefinisi}
    {Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M)
{
    // kamus lokal
    int i, j;
    size_t sizeMatrix;

    // algoritma

    for (i = 1; i <= BMAX; i++)
    {
        for (j = 1; j <= KMAX; j++)
        {
            (*M).cell[i][j] = -999;
        }
    }

    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
    {mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M)
{
    // kamus lokal

    // algoritma
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
    {mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M)
{
    // kamus lokal

    // algoritma
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
    {mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M)
{
    // kamus lokal

    // algoritma
    return getNBaris(M) == 0 && getNKolom(M) == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
    {mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M)
{
    // kamus lokal

    // algoritma
    return getNBaris(M) == sizeof M.cell && getNKolom(M) == sizeof M.cell[1];
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
    {I.S.: M terdefinisi, X terdefinisi }
    {F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
    {Proses: mengisi elemen M.cell dengan nilai X} */
void addX(Matriks *M, int X, int row, int col)
{
    // kamus lokal

    // algoritma
    if ((*M).cell[row][col] == -999)
    {
        (*M).cell[row][col] = X;
    }

    if ((*M).nbaris < row)
    {
        (*M).nbaris = row;
    }

    if ((*M).nkolom < col)
    {
        (*M).nkolom = col;
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
    {I.S.: M terdefinisi, X terdefinisi}
    {F.S.: elemen M.cell berkurang 1}
    {Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX(Matriks *M, int X)
{
    // kamus lokal
    int row, col, i, j, countRow, countCol;

    // algoritma
    row = 0;
    col = 0;
    searchX(*M, X, &row, &col);

    if (row != 0 && col != 0)
    {
        (*M).cell[row][col] = -999;

        for (i = 1; i <= BMAX; i++)
        {
            for (j = 1; j <= KMAX; j++)
            {
                if ((*M).cell[i][j] != -999)
                {
                    countRow = i;
                    countCol = j;
                }
            }
        }

        (*M).nbaris = countRow;
        (*M).nkolom = countCol;
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
    {I.S.: M terdefinisi}
    {F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
    {proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y)
{
    // kamus lokal
    int i, j, randInt;

    // algoritma
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= y; j++)
        {
            randInt = rand() % 10 + 1;
            addX(&(*M), randInt, i, j);
        }
    }

    (*M).nbaris = x;
    (*M).nkolom = y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
    {I.S.: M terdefinisi}
    {F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
    {proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n)
{
    // kamus lokal
    int i, j;

    // algoritma
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
            {
                (*M).cell[i][j] = 1;
            }
            else
            {
                (*M).cell[i][j] = 0;
            }
        }
    }

    (*M).nbaris = n;
    (*M).nkolom = n;
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y)
{
    // kamus lokal
    int i, j, userInput;

    // algoritma
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= y; j++)
        {
            printf("Masukkan input untuk elemen baris ke-%d kolom ke-%d: ", i, j);
            scanf("%d", &userInput);
            (*M).cell[i][j] = userInput;
        }
    }

    (*M).nbaris = x;
    (*M).nkolom = y;
}

/* procedure printMatriks(input M:Matriks)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M)
{
    // kamus lokal
    int i, j, currCell;

    // algoritma
    for (i = 1; i <= BMAX; i++)
    {
        for (j = 1; j <= KMAX; j++)
        {
            currCell = M.cell[i][j];
            j == KMAX ? printf("%d\n", currCell) : printf("%d | ", currCell);
        }
    }
}

/* procedure viewMatriks (input M:Matriks)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks(Matriks M)
{
    // kamus lokal
    int i, j, currCell;

    // algoritma
    for (i = 1; i <= BMAX; i++)
    {
        for (j = 1; j <= KMAX; j++)
        {
            currCell = M.cell[i][j];
            if (currCell != -999)
            {
                printf("%d | ", currCell);
            }
        }
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2)
{
    // kamus lokal
    int i, j, tempHasil;
    Matriks MHasil;

    // algoritma
    initMatriks(&MHasil);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2))
    {
        for (i = 1; i <= getNBaris(M1); i++)
        {
            for (j = 1; j <= getNKolom(M1); j++)
            {
                tempHasil = M1.cell[i][j] + M2.cell[i][j];
                addX(&MHasil, tempHasil, i, j);
            }
        }
    }

    return MHasil;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2)
{
    // kamus lokal
    int i, j, tempHasil;
    Matriks MHasil;

    // algoritma
    initMatriks(&MHasil);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2))
    {
        for (i = 1; i <= getNBaris(M1); i++)
        {
            for (j = 1; j <= getNKolom(M1); j++)
            {
                tempHasil = M1.cell[i][j] - M2.cell[i][j];
                addX(&MHasil, tempHasil, i, j);
            }
        }
    }

    return MHasil;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2)
{
    // kamus lokal
    int i, j, k, tempHasil;
    Matriks MHasil;

    // algoritma
    initMatriks(&MHasil);
    if (getNKolom(M1) == getNBaris(M2))
    {
        for (i = 1; i <= getNBaris(M1); i++)
        {
            for (j = 1; j <= getNKolom(M2); j++)
            {
                tempHasil = 0;
                for (k = 1; k <= getNKolom(M1); k++)
                {
                    tempHasil += M1.cell[i][k] * M2.cell[k][j];
                }
                addX(&MHasil, tempHasil, i, j);
            }
        }
    }

    return MHasil;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x)
{
    // kamus lokal
    int i, j;
    Matriks MHasil;

    // algoritma
    initMatriks(&MHasil);
    for (i = 1; i <= getNBaris(M1); i++)
    {
        for (j = 1; j <= getNKolom(M1); j++)
        {
            if (M1.cell[i][j] != -999)
            {
                addX(&MHasil, M1.cell[i][j] * x, i, j);
            }
        }
    }

    return MHasil;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
    {I.S.: M terdefinisi}
    {F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
    {proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M)
{
    *M = getTransposeMatriks(*M);
}

/* function getTransposeMatriks(M: Matriks)
    {menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M)
{
    // kamus lokal
    int i, j;
    Matriks MHasil;

    // algoritma
    initMatriks(&MHasil);
    for (i = 1; i <= getNBaris(M); i++)
    {
        for (j = 1; j <= getNKolom(M); j++)
        {
            addX(&MHasil, M.cell[i][j], j, i);
        }
    }

    return MHasil;
}

/* function addPadding(M: Matriks, input n:integer)
    {menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n)
{
    // kamus lokal
    int i, j, newRow, newCol;
    Matriks Mhasil;

    // algoritma
    initMatriks(&Mhasil);
    newRow = 2 * n + getNBaris(M);
    newCol = 2 * n + getNKolom(M);
    for (i = 1; i <= newRow; i++)
    {
        for (j = 1; j <= newCol; j++)
        {
            if (i > n && i <= getNBaris(M) + n && j > n && j <= getNKolom(M) + n)
            {
                addX(&Mhasil, M.cell[i - n][j - n], i, j);
            }
            else
            {
                addX(&Mhasil, 0, i, j);
            }
        }
    }
    return Mhasil;
}

/* function maxPooling(M: Matriks, input size:integer)
    {menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size)
{
    // kamus lokal
    int i, j, k, l, max, temp, row, col;
    Matriks MHasil;

    // algoritma
    initMatriks(&MHasil);
    if (getNBaris(M) % size == 0 && getNKolom(M) % size == 0)
    {
        for (i = 1; i <= getNBaris(M); i = i + size)
        {
            for (j = 1; j <= getNKolom(M); j = j + size)
            {
                max = 0;
                for (k = i; k < i + size; k++)
                {
                    for (l = j; l < j + size; l++)
                    {
                        temp = M.cell[k][l];
                        if (temp > max)
                        {
                            max = temp;
                        }
                    }
                }
                row = (i - 1) / size + 1;
                col = (j - 1) / size + 1;
                addX(&MHasil, max, row, col);
            }
        }
    }

    return MHasil;
}

/* function avgPooling(M: Matriks, input size:integer)
    {menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size)
{
    // kamus lokal
    int i, j, k, l, avg, sum, row, col;
    Matriks MHasil;

    // algoritma
    initMatriks(&MHasil);
    if (getNBaris(M) % size == 0 && getNKolom(M) % size == 0)
    {
        for (i = 1; i <= getNBaris(M); i = i + size)
        {
            for (j = 1; j <= getNKolom(M); j = j + size)
            {
                sum = 0;
                for (k = i; k < i + size; k++)
                {
                    for (l = j; l < j + size; l++)
                    {
                        sum += M.cell[k][l];
                    }
                }
                avg = sum / (size * size);
                row = (i - 1) / size + 1;
                col = (j - 1) / size + 1;
                addX(&MHasil, avg, row, col);
            }
        }
    }

    return MHasil;
}

/* function conv(M: Matriks, K:Matriks)
    {menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K)
{
    // kamus lokal
    int i, j, k, l, m, n, rowM, colM, rowK, colK, avg, sum, row, col;
    Matriks MHasil;

    // algoritma
    initMatriks(&MHasil);
    rowM = getNBaris(M);
    colM = getNKolom(M);
    rowK = getNBaris(K);
    colK = getNKolom(K);

    if (rowM >= rowK && colM > colK)
    {
        for (i = 1; i <= rowM - rowK + 1; i++)
        {
            for (j = 1; j <= colM - colK + 1; j++)
            {
                sum = 0;
                for (k = 0; k < rowK; k++)
                {
                    for (l = 0; l < colK; l++)
                    {
                        sum += M.cell[k + i][l + j] * K.cell[k + 1][k + 1];
                    }
                }
                addX(&MHasil, sum, i, j);
            }
        }
    }

    return MHasil;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
    {I.S.: M terdefinisi, X terdefinisi }
    {F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
    {Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col)
{
    // kamus lokal
    int i, j;
    boolean found;

    // algoritma
    i = 1;
    found = false;
    while (i <= BMAX && !found)
    {
        j = 1;
        while (j <= KMAX && !found)
        {
            if (M.cell[i][j] == X)
            {
                found = true;
                *row = i;
                *col = j;
            }
            j++;
        }
        i++;
    }
}

/* function countX (M:Matriks, X: integer) -> integer
    {mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX(Matriks M, int X)
{
    // kamus lokal
    int i, j, count;

    // algoritma
    count = 0;
    for (i = 1; i <= BMAX; i++)
    {
        for (j = 1; j <= KMAX; j++)
        {
            if (M.cell[i][j] == X)
            {
                count++;
            }
        }
    }

    return count;
}

#endif