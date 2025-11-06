#include <stdio.h>
#include "tabel.h"
/* Deskripsi : driver ADT tabel integer */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 11-09-2025 */

/* Prosedur untuk mencetak header pengujian agar output lebih terstruktur */
void printHeader(char *title)
{
	printf("\n============================================\n");
	printf("   %s\n", title);
	printf("============================================\n");
}

/* Prosedur untuk menampilkan isi dan ukuran tabel saat ini */
void printTableInfo(Tabel T, char *tableName)
{
	printf("Isi %s: [ ", tableName);
	viewTable(T);
	printf(" ] (Size: %d)\n", getSize(T));
}

/* Prosedur untuk mencetak hasil tes boolean dengan format Ya/Tidak */
void printTestResult(char *testName, boolean result)
{
	printf("%s: %s\n", testName, result ? "Ya" : "Tidak");
}

int main()
{
	/* Kamus */
	Tabel T1, T2, T3, Tinv;
	int pos;

	printHeader("1. UJI KONSTRUKTOR & PREDIKAT DASAR");
	createTable(&T1);
	printf("Tabel T1 dibuat...\n");
	printTestResult("Apakah T1 kosong?", isEmptyTable(T1));
	printTableInfo(T1, "T1");

	printHeader("2. UJI PENGISIAN (addXTable)");
	printf("Menambahkan 'K', 'A', 'M', 'I', 'S', 'A' ke T1...\n");
	addXTable(&T1, 'K');
	addXTable(&T1, 'A');
	addXTable(&T1, 'M');
	addXTable(&T1, 'I');
	addXTable(&T1, 'S');
	addXTable(&T1, 'A');
	printTableInfo(T1, "T1");
	printTestResult("Apakah T1 penuh?", isFullTable(T1));

	printHeader("3. UJI PENCARIAN & STATISTIK");
	printTableInfo(T1, "T1");
	searchX(T1, 'M', &pos);
	printf("Posisi 'M' (searchX): %d\n", pos);
	searchX(T1, 'Z', &pos);
	printf("Posisi 'Z' (searchX): %d\n", pos);
	printf("Jumlah 'A' (countX): %d\n", countX(T1, 'A'));
	printf("Jumlah vokal (countVocal): %d\n", countVocal(T1));
	printf("Modus tabel (Modus): %c\n", Modus(T1));

	printHeader("4. UJI PENGHAPUSAN");
	printTableInfo(T1, "T1 (awal)");
	printf("Menghapus elemen di indeks ke-3 ('M')...\n");
	delTable(&T1, 3);
	printTableInfo(T1, "T1 (setelah delTable)");
	printf("Menghapus elemen 'A' pertama...\n");
	delXTable(&T1, 'A');
	printTableInfo(T1, "T1 (setelah delXTable)");

	printHeader("5. UJI RELASIONAL & INVERSE");
	// Setup T2 dan T3
	createTable(&T2);
	createTable(&T3);
	addXTable(&T2, 'S');
	addXTable(&T2, 'E');
	addXTable(&T2, 'L');
	addXTable(&T3, 'S');
	addXTable(&T3, 'E');
	addXTable(&T3, 'L');
	printTableInfo(T2, "T2");
	printTableInfo(T3, "T3");
	printTestResult("Apakah T2 sama dengan T3?", isEqualTable(T2, T3));

	printf("\nMembalik T2 dengan inverseTable...\n");
	inverseTable(&T2);
	printTableInfo(T2, "T2 (setelah dibalik)");

	Tinv = getInverseTable(T2);
	printTableInfo(Tinv, "Tinv (dari getInverseTable(T2))");

	printHeader("6. UJI PENGURUTAN");
	printTableInfo(T2, "T2 (awal)");
	sortAsc(&T2);
	printTableInfo(T2, "T2 (setelah sortAsc)");
	sortDesc(&T2);
	printTableInfo(T2, "T2 (setelah sortDesc)");

	Tabel T4;
	createTable(&T4);
	populateTable(&T4, 2);
	printTableInfo(T4, "Isi Tabel T4");

	printf("\n--- PENGUJIAN SELESAI ---\n");
	return 0;
}
