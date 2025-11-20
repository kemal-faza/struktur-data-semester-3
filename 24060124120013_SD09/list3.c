#include "list3.h"

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) // representasi fisik fungsi
{							// kamus lokal
	address P;
	// algoritma
	P = (address)malloc(sizeof(Elm));
	if (P != NIL)
	{
		info(P) = E;
		next(P) = NIL;
		prev(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
   Proses: Melakukan pengembalian address P} */
void Dealokasi(address *P)
{
	// kamus lokal

	// algoritma
	if (*P != NIL)
	{ // P tidak kosong
		free(*P);
		*P = NIL;
	}
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList(List3 *L)
{
	// kamus lokal

	// algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List3 L)
{
	// kamus lokal

	// algoritma
	return First(L) == NIL;
}

/* function IsOneElm(L:List3) --> boolean
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm(List3 L)
{
	// kamus lokal

	// algoritma
	return !IsEmptyList(L) && next(First(L)) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L)
{
	// kamus lokal
	address P;

	// algoritma
	if (!IsEmptyList(L))
	{
		P = First(L);
		while (P != NIL)
		{
			if (next(P) == NIL)
			{
				printf("%c", info(P));
			}
			else
			{
				printf("%c | ", info(P));
			}
			P = next(P);
		}
		printf("\n");
	}
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L)
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
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V)
{
	// kamus lokal
	address P;

	// algoritma
	P = Alokasi(V);
	if (P != NIL)
	{
		if (IsEmptyList(*L))
		{
			First(*L) = P;
		}
		else
		{
			next(P) = First(*L);
			prev(First(*L)) = P;
			First(*L) = P;
		}
	}
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V)
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
		}
		else
		{
			Q = First(*L);
			while (next(Q) != NIL)
			{
				Q = next(Q);
			}

			next(Q) = P;
			prev(P) = Q;
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V)
{
	// kamus lokal
	address P;

	// algoritma
	if (IsEmptyList(*L))
	{
		*V = '#';
	}
	else
	{
		P = First(*L);
		*V = info(P);
		if (IsOneElm(*L))
		{
			First(*L) = NIL;
			Dealokasi(&P);
		}
		else
		{
			First(*L) = next(P);
			prev(First(*L)) = NIL;
			Dealokasi(&P);
		}
	}
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V)
{
	// kamus lokal
	address P, Q;

	// algoritma
	if (IsEmptyList(*L))
	{
		*V = '#';
	}
	else
	{
		P = First(*L);
		if (IsOneElm(*L))
		{
			*V = info(P);
			First(*L) = NIL;
			Dealokasi(&P);
		}
		else
		{
			while (next(P) != NIL)
			{
				P = next(P);
			}
			Q = prev(P);
			*V = info(P);
			next(Q) = NIL;
			Dealokasi(&P);
		}
	}
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X)
{
	// kamus lokal
	address P;
	infotype temp;

	// algoritma
	if (!IsEmptyList(*L))
	{
		// Jika elemen pertama yang cocok
		if (info(First(*L)) == X)
		{
			DeleteVFirst(L, &temp);
		}
		else
		{
			// Cari elemen di tengah/akhir
			P = First(*L);
			while (P != NIL)
			{
				if (info(P) == X)
				{
					// Elemen ditemukan
					if (next(P) == NIL)
					{
						// Elemen terakhir
						next(prev(P)) = NIL;
					}
					else
					{
						// Elemen di tengah
						next(prev(P)) = next(P);
						prev(next(P)) = prev(P);
					}
					Dealokasi(&P);
					break;
				}
				P = next(P);
			}
		}
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A);

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y);

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L);

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V);

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V);

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V);

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V);

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X);

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X);

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L);

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L);

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L);

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L);

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X);

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X);

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L);

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2);

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2);