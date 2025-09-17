/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 18-09-2025 */
/***********************************/

#include <stdio.h>
#include "matriks.h"

int main()
{
	/*kamus*/
	Matriks M1, M2;

	/*algoritma*/
	initMatriks(&M1);
	initMatriks(&M2);
	isiMatriksRandom(&M1, 6, 6);
	isiMatriksRandom(&M2, 3, 7);
	printMatriks(M1);
	// printMatriks(addPadding(M1, 3));
	// kaliMatriks(M1, M2);
	// addPadding(M1, 2);
	// printMatriks(maxPooling(M1, 2));
	printMatriks(avgPooling(M1, 2));
	// maxPooling(M1, 2);

	return 0;
}
