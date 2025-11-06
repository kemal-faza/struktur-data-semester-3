/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : November 2025 */
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
		next(P) = NIL;
	}
	P = NIL;
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
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List1 L)
{
	// algoritma
	return (First(L) == NIL);
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
	{
		count++;
		P = next(P);
	}
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
	address P;
	address Q;
	// algoritma
	P = Alokasi(V);
	if (P != NIL)
	{ // alokasi berhasil
		if (IsEmptyList(*L))
		{
			First(*L) = P;
		}
		else
		{
			Q = First(*L);
			while (next(Q) != NIL)
			{
				Q = next(Q);
			}
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
	{
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
	{
		if (next(First(*L)) == NIL)
		{ // hanya satu elemen
			P = First(*L);
			*V = info(P);
			First(*L) = NIL;
			Dealokasi(P);
		}
		else
		{
			Q = First(*L);
			while (next(next(Q)) != NIL)
			{
				Q = next(Q);
			}
			P = next(Q);
			*V = info(P);
			next(Q) = NIL;
			Dealokasi(P);
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
	{
		if (info(P) == X)
		{
			*A = P;
			break;
		}
		P = next(P);
	}
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
	{
		if (info(P) == X)
		{
			info(P) = Y;
		}
		P = next(P);
	}
}