/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 06-09-2025*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main()
{
	// kamus main
	Titik T1, T2, T3, T4, TCenter;

	// algoritma
	printf("============================================\n");
	printf("       Driver Uji Coba Modul Titik\n");
	printf("============================================\n\n");

	printf("--- 1. PENGUJIAN KONSTRUKTOR ---\n");

	printf("Membuat T1 dengan makeTitik(5, 7)...\n");
	makeTitik(&T1, 5, 7);
	printf("   Hasil T1 = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));

	printf("Membuat T2 dengan makeTitik0()...\n");
	makeTitik0(&T2);
	printf("   Hasil T2 = (%d, %d)\n\n", getAbsis(T2), getOrdinat(T2));

	printf("--- 2. PENGUJIAN MUTATOR ---\n");

	printf("Mengubah T2 dengan setAbsis(&T2, 10)...\n");
	setAbsis(&T2, 10);
	printf("   T2 sekarang = (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

	printf("Mengubah T2 dengan setOrdinat(&T2, -8)...\n");
	setOrdinat(&T2, -8);
	printf("   T2 sekarang = (%d, %d)\n\n", getAbsis(T2), getOrdinat(T2));

	printf("--- 3. PENGUJIAN PREDIKAT ---\n");
	makeTitik0(&T3);
	makeTitik(&T4, 5, 7);

	printf("Apakah T1 (%d,%d) origin? %s\n", getAbsis(T1), getOrdinat(T1), isOrigin(T1) ? "Ya" : "Bukan");
	printf("Apakah T3 (%d,%d) origin? %s\n", getAbsis(T3), getOrdinat(T3), isOrigin(T3) ? "Ya" : "Bukan");

	setOrdinat(&T3, 0);
	setAbsis(&T3, 9);
	printf("Apakah T1 (%d,%d) di sumbu X? %s\n", getAbsis(T1), getOrdinat(T1), isOnSumbuX(T1) ? "Ya" : "Bukan");
	printf("Apakah T3 (%d,%d) di sumbu X? %s\n", getAbsis(T3), getOrdinat(T3), isOnSumbuX(T3) ? "Ya" : "Bukan");

	setAbsis(&T3, 0);
	setOrdinat(&T3, 9);
	printf("Apakah T1 (%d,%d) di sumbu Y? %s\n", getAbsis(T1), getOrdinat(T1), isOnSumbuY(T1) ? "Ya" : "Bukan");
	printf("Apakah T3 (%d,%d) di sumbu Y? %s\n", getAbsis(T3), getOrdinat(T3), isOnSumbuY(T3) ? "Ya" : "Bukan");

	printf("Apakah T1 (%d,%d) sama dengan T2 (%d,%d)? %s\n", getAbsis(T1), getOrdinat(T1), getAbsis(T2), getOrdinat(T2), isEqual(T1, T2) ? "Ya" : "Tidak");
	printf("Apakah T1 (%d,%d) sama dengan T4 (%d,%d)? %s\n\n", getAbsis(T1), getOrdinat(T1), getAbsis(T4), getOrdinat(T4), isEqual(T1, T4) ? "Ya" : "Tidak");

	printf("--- 4. PENGUJIAN SUBRUTIN LAIN ---\n");

	printf("Posisi awal T1 = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	printf("Geser T1 sejauh (3, -2)...\n");
	geser(&T1, 3, -2);
	printf("   Posisi akhir T1 = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));

	printf("Refleksi T1 terhadap sumbu X...\n");
	refleksiX(&T1);
	printf("   Posisi akhir T1 = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));

	printf("Refleksi T1 terhadap sumbu Y...\n");
	refleksiY(&T1);
	printf("   Posisi akhir T1 = (%d, %d)\n\n", getAbsis(T1), getOrdinat(T1));

	printf("Posisi awal T2 = (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
	printf("Dilatasi T2 dengan faktor skala 2.5 terhadap (0,0)...\n");
	dilatasi(&T2, 2.5);
	printf("   Posisi akhir T2 = (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

	makeTitik(&T3, 2, 3);
	makeTitik(&TCenter, 1, 1);
	printf("Posisi awal T3 = (%d, %d)\n", getAbsis(T3), getOrdinat(T3));
	printf("Dilatasi T3 dengan faktor skala 3 terhadap titik pusat (%d, %d)...\n", getAbsis(TCenter), getOrdinat(TCenter));
	dilatasiX(&T3, TCenter, 3.0);
	printf("   Posisi akhir T3 = (%d, %d)\n\n", getAbsis(T3), getOrdinat(T3));

	printf("--- 5. PENGUJIAN KUADRAN ---\n");
	makeTitik(&T1, 4, 5);
	makeTitik(&T2, -4, 5);
	makeTitik(&T3, -4, -5);
	makeTitik(&T4, 4, -5);
	printf("Titik (%d, %d) berada di kuadran: %d\n", getAbsis(T1), getOrdinat(T1), kuadran(T1));
	printf("Titik (%d, %d) berada di kuadran: %d\n", getAbsis(T2), getOrdinat(T2), kuadran(T2));
	printf("Titik (%d, %d) berada di kuadran: %d\n", getAbsis(T3), getOrdinat(T3), kuadran(T3));
	printf("Titik (%d, %d) berada di kuadran: %d\n", getAbsis(T4), getOrdinat(T4), kuadran(T4));

	printf("\n============================================\n");
	printf("          Semua fungsi telah diuji.\n");
	printf("============================================\n");

	return 0;
}
