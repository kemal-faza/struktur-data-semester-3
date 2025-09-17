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
	Matriks M1;

	/*algoritma*/
	initMatriks(&M1);
	populateMatriks(&M1, 4, 2);
	printMatriks(M1);

	return 0;
}
