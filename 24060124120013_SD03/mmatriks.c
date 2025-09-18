/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 18-09-2025 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"

// Fungsi bantuan untuk mencetak header
void printHeader(char *title)
{
	printf("\n============================================\n");
	printf("   %s\n", title);
	printf("============================================\n");
}

// Fungsi bantuan untuk mencetak matriks dengan rapi (hanya bagian terisi)
void printMatriksCustom(Matriks M, char *matrixName)
{
	printf("--- Isi Matriks %s (%dx%d) ---\n", matrixName, getNBaris(M), getNKolom(M));
	if (isEmptyMatriks(M))
	{
		printf("(Kosong)\n");
		return;
	}
	for (int i = 1; i <= getNBaris(M); i++)
	{
		for (int j = 1; j <= getNKolom(M); j++)
		{
			printf("%d\t", M.cell[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	// Panggil srand SATU KALI di awal main
	srand(time(NULL));

	/* KAMUS */
	Matriks M1, M2, M3, MHasil;
	int r, c;

	//----------------------------------------------------------------
	// 1. UJI KONSTRUKTOR, PENGISIAN, & PREDIKAT
	//----------------------------------------------------------------
	printHeader("1. UJI KONSTRUKTOR & PENGISIAN");
	initMatriks(&M1);
	printf("M1 dibuat. Apakah kosong? %s\n", isEmptyMatriks(M1) ? "Ya" : "Tidak");

	printf("\nMengisi M1 3x3 dengan isiMatriksRandom...\n");
	isiMatriksRandom(&M1, 3, 3);
	printMatriksCustom(M1, "M1");

	initMatriks(&M2);
	printf("\nMengisi M2 3x3 dengan matriks identitas...\n");
	isiMatriksIdentitas(&M2, 3);
	printMatriksCustom(M2, "M2");

	//----------------------------------------------------------------
	// 2. UJI OPERASI ARITMATIKA
	//----------------------------------------------------------------
	printHeader("2. UJI OPERASI ARITMATIKA");
	MHasil = addMatriks(M1, M2);
	printMatriksCustom(MHasil, "M1 + M2");

	MHasil = subMatriks(M1, M2);
	printMatriksCustom(MHasil, "M1 - M2");

	// Perkalian Matriks
	initMatriks(&M3);
	isiMatriksRandom(&M3, 3, 2); // Buat matriks 3x2
	printMatriksCustom(M1, "M1 (3x3)");
	printMatriksCustom(M3, "M3 (3x2)");
	MHasil = kaliMatriks(M1, M3);
	printMatriksCustom(MHasil, "M1 * M3");

	// Perkalian Skalar
	MHasil = kaliSkalarMatriks(M1, 5);
	printMatriksCustom(MHasil, "M1 * 5");

	//----------------------------------------------------------------
	// 3. UJI OPERASI LAINNYA
	//----------------------------------------------------------------
	printHeader("3. UJI OPERASI LAINNYA");
	printMatriksCustom(M3, "M3 (awal)");
	MHasil = getTransposeMatriks(M3);
	printMatriksCustom(MHasil, "Transpose dari M3");

	// Padding
	MHasil = addPadding(M3, 2);
	printMatriksCustom(MHasil, "M3 dengan padding 2");

	//----------------------------------------------------------------
	// 4. UJI PENCARIAN & HAPUS
	//----------------------------------------------------------------
	printHeader("4. UJI PENCARIAN & HAPUS");
	initMatriks(&M1);
	addX(&M1, 5, 1, 1);
	addX(&M1, 9, 1, 2);
	addX(&M1, 3, 2, 1);
	addX(&M1, 7, 2, 2);
	printMatriksCustom(M1, "M1");
	printf("Mencari angka 7...\n");
	searchX(M1, 7, &r, &c);
	printf("Hasil: baris=%d, kolom=%d\n", r, c);

	printf("\nJumlah angka 9 (countX): %d\n", countX(M1, 9));

	printf("\nMenghapus angka 7...\n");
	delX(&M1, 7);
	printMatriksCustom(M1, "M1 setelah delX(7)");

	//----------------------------------------------------------------
	// 5. UJI POOLING & KONVOLUSI
	//----------------------------------------------------------------
	printHeader("5. UJI POOLING & KONVOLUSI");
	initMatriks(&M1);
	isiMatriksRandom(&M1, 4, 4); // Matriks 4x4 untuk pooling
	printMatriksCustom(M1, "M1 (4x4)");

	MHasil = maxPooling(M1, 2);
	printMatriksCustom(MHasil, "Hasil Max Pooling (size 2)");

	MHasil = avgPooling(M1, 2);
	printMatriksCustom(MHasil, "Hasil Avg Pooling (size 2)");

	// Konvolusi
	Matriks kernel;
	initMatriks(&kernel);
	isiMatriksIdentitas(&kernel, 2); // Kernel sederhana
	printMatriksCustom(kernel, "Kernel (2x2)");
	MHasil = conv(M1, kernel);
	printMatriksCustom(MHasil, "Hasil Konvolusi M1 dengan Kernel");

	return 0;
}
