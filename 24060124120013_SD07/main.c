/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza*/
/* Tanggal : 9 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
int main()
{ // kamus
  address A;
  address B;
  address P;
  List1 Senarai;
  // algoritma

  // aplikasi tipe address

  A = Alokasi('G'); // Alokasi('G')
  printf("info(A)=%c\t", info(A));
  B = Alokasi('N'); // Alokasi('N')
  printf("info(B)=%c\n", info(B));
  next(B) = A;
  printf("info(next(B))=%c\n", info(next(B)));

  // aplikasi tipe List1
  CreateList(&Senarai);            // CreateList(Senarai)
  InsertVFirst(&Senarai, info(A)); // InsertVFirst(Senarai, 'D');
  InsertVFirst(&Senarai, info(B)); // InsertVFirst(Senarai, 'D');
  printf("Isi Senarai :");
  P = First(Senarai);
  while (P != NIL)
  {
    printf("\t%c", info(P));
    P = next(P);
  }
  PrintList(Senarai);

  return 0;
}
