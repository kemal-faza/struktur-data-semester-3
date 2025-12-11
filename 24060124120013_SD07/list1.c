/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza*/
/* Tanggal : 9 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E)
{
	// kamus lokal
	address P;

	// algoritma
	P = (address)malloc(sizeof(Elm));
	if (P != NIL)
	{ // ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
	F.S. P dikembalikan ke NIL
	Proses: Melakukan pengosongan address P} */
void Dealokasi(address P)
{
	// kamus lokal

	// algoritma
	if (P != NIL)
	{
		free(P);
	}
}
/*********** OPERATORS ***********/

/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List1 L)
{
	// kamus lokal
	address P;

	// algoritma
	P = First(L);
	if (P != NIL)
	{
		printf("\nElemen = ");
		do
		{
			printf("\t%c", info(P));
			P = next(P);
		} while (P != NIL);
	}
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList(List1 *L)
{
	// kamus lokal

	// algoritma
	First(*L) = NIL; // mengisi nilai elemen List dengan Nil
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List1 L)
{
	// kamus lokal

	// algoritma
	return (First(L) == NIL); // membandingkan elemen di list dengan nilai Nil
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L)
{
	// kamus lokal
	address P;
	int count;

	// algoritma
	count = 0;
	P = First(L);
	while (P != NIL)
	{ // P tidak kosong
		count++;
		P = next(P);
	}
	// endWhile - P kosong
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V)
{
	// kamus lokal
	address P;

	// algoritma
	P = Alokasi(V);
	if (P != NIL)
	{ // alokasi berhasil
		next(P) = First(*L);
		First(*L) = P;
	}
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V)
{
	// kamus lokal
	address P, Q;

	// algoritma
	P = Alokasi(V);
	if (P != NIL)
	{ // alokasi berhasil
		if (IsEmptyList(*L))
		{ // list kosong
			First(*L) = P;
		}
		else
		{ // list tidak kosong
			Q = First(*L);
			while (next(Q) != NIL)
			{ // alamat elemen selanjutnya tidak kosong
				Q = next(Q);
			}
			// endWhile - alamat elemen selanjutnya kosong
			next(Q) = P;
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V)
{
	// kamus lokal
	address P;

	// algoritma
	if (!IsEmptyList(*L))
	{ // list tidak kosong
		P = First(*L);
		*V = info(P);
		First(*L) = next(P);
		Dealokasi(P);
	}
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V)
{
	// kamus lokal
	address P;
	address Q;

	// algoritma
	if (!IsEmptyList(*L))
	{ // list tidak kosong
		if (next(First(*L)) == NIL)
		{ // hanya satu elemen
			P = First(*L);
			*V = info(P);
			First(*L) = NIL;
			Dealokasi(P);
		}
		else
		{ // lebih dari satu elemen
			Q = First(*L);
			while (next(next(Q)) != NIL)
			{ // 2 elemen selanjutnya tidak kosong
				Q = next(Q);
			}
			// endWhile - 2 elemen selanjutnya kosong
			P = next(Q);
			*V = info(P);
			next(Q) = NIL;
			Dealokasi(P); // dealokasi memori
		}
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A)
{
	// kamus lokal
	address P;

	// algoritma
	P = First(L);
	*A = NIL;
	while (P != NIL)
	{ // P tidak kosong
		if (info(P) == X)
		{ // isi P sama dengan X
			*A = P;
			break;
		}
		P = next(P); // lanjut ke elemen selanjutnya
	}
	// endWhile - P kosong
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y)
{
	// kamus lokal
	address P;

	// algoritma
	P = First(*L);
	while (P != NIL)
	{ // P tidak kosong
		if (info(P) == X)
		{ // isi P sama dengan X
			info(P) = Y;
		}
		P = next(P); // lanjut ke elemen selanjutnya
	}
	// endWhile - P kosong
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L)
{
	// kamus lokal
	address P;
	address Prev;
	address Next;

	// algoritma
	Prev = NIL;
	P = First(*L);
	while (P != NIL)
	{ // P tidak kosong
		Next = next(P);
		next(P) = Prev;
		Prev = P;
		P = Next;
	}
	// endWhile - P kosong
	First(*L) = Prev;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountVocal(L:List1) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List1 L)
{
	// kamus lokal
	address P;
	int count;

	// algoritma
	count = 0;
	P = First(L);
	while (P != NIL)
	{ // kalau P tidak kosong
		if (info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o' ||
			info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O')
		{ // isi P sama dengan huruf vokal, baik lowercase maupun uppercase
			count++;
		}
		P = next(P); // lanjut ke elemen selanjutnya
	}
	// endWhile - P kosong
	return count;
}

/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X)
{
	// kamus lokal
	address P;
	int count;

	// algoritma
	count = 0;
	P = First(L);
	while (P != NIL)
	{ // isi P tidak kosong
		if (info(P) == X)
		{ // isi elemen P sama dengan X
			count++;
		}
		P = next(P);
	}
	// endWhile - P kosong
	return count;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X)
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

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X)
{
	// kamus lokal
	address P;
	int position;

	// algoritma
	P = First(L);
	position = 1;
	printf("Posisi kemunculan elemen %c : ", X);
	while (P != NIL)
	{ // P tidak kosong
		if (info(P) == X)
		{ // isi P sama dengan X
			printf("%d ", position);
		}
		P = next(P); // lanjut ke elemen selanjutnya
		position++;
	}
	// endWhile - P kosong
	printf("\n");
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y.
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y)
{
	// kamus lokal
	address P;

	// algoritma
	P = First(*L);
	while (P != NIL)
	{ // P tidak kosong
		if (info(P) == X)
		{ // isi P sama dengan X
			info(P) = Y;
		}
		P = next(P); // lanjut ke elemen selanjutnya
	}
	// endWhile - P kosong
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA)
{
	// kamus lokal
	address P;
	address Q;

	// algoritma
	Q = First(*L);
	while (Q != NIL)
	{ // Q tidak kosong
		if (info(Q) == V)
		{ // isi Q sama dengan V
			P = Alokasi(VA);
			if (P != NIL)
			{ // alokasi berhasil
				next(P) = next(Q);
				next(Q) = P;
			}
			break; // keluar dari loop setelah menyisipkan
		}
		Q = next(Q); // lanjut ke elemen selanjutnya
	}
	// endWhile - Q kosong
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L)
{
	// kamus lokal
	address P;
	infotype modus;
	int maxCount;
	int count;

	// algoritma
	modus = '#'; // inisialisasi dengan karakter default
	maxCount = 0;
	P = First(L);
	while (P != NIL)
	{ // P tidak kosong
		count = CountX(L, info(P));
		if (count > maxCount)
		{ // jika count sekarang lebih besar daripada count sebelumnya
			maxCount = count;
			modus = info(P);
		}
		P = next(P); // lanjut ke elemen selanjutnya
	}
	// endWhile - P kosong
	return modus;
}

/*function NbModus(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int NbModus(List1 L)
{
	// kamus lokal
	address P;
	infotype modus;
	int count;

	// algoritma
	modus = Modus(L);
	count = 0;
	P = First(L);
	while (P != NIL)
	{ // P tidak kosong
		if (info(P) == modus)
		{ // isi P sama dengan modus
			count++;
		}
		P = next(P); // lanjut ke elemen selanjutnya
	}
	// endWhile - P kosong
	return count;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L)
{
	// kamus lokal
	address P;

	// algoritma
	CreateList(L);
	P = First(L1); // inisiasi list pertama
	while (P != NIL)
	{ // P tidak kosong
		InsertVLast(L, info(P));
		P = next(P); // lanjut ke elemen selanjutnya
	}
	// endWhile - P kosong
	P = First(L2); // inisiasi list kedua
	while (P != NIL)
	{ // P tidak kosong
		InsertVLast(L, info(P));
		P = next(P);
	}
	// endWhile - P kosong
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List1 L, List1 *L1, List1 *L2)
{
	// kamus lokal
	address P;
	int i;

	// algoritma
	CreateList(L1);
	CreateList(L2);
	P = First(L);
	i = 1;
	while (P != NIL)
	{ // P tidak kosong
		if (i % 2 == 1)
		{ // urutan elemen ganjil
			InsertVLast(L1, info(P));
		}
		else
		{ // urutan elemen genap
			InsertVLast(L2, info(P));
		}
		P = next(P); // Lanjut ke elemen berikutnya
		i++;
	}
	// endWhlle - P kosong
}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2)
{
	// kamus lokal
	address P;

	// algoritma
	CreateList(L2);
	P = First(L1);
	while (P != NIL)
	{ // P tidak kosong
		InsertVLast(L2, info(P));
		P = next(P);
	}
	// endWhile - P kosong
}
