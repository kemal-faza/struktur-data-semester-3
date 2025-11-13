/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza*/
/* Tanggal : 9 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.h"
int main()
{ // kamus
  address A;
  address B;
  address P;
  List2 Senarai;
  // algoritma

  // aplikasi tipe address

  A = Alokasi('G'); // Alokasi('G')
  printf("info(A)=%c\t", info(A));
  B = Alokasi('N'); // Alokasi('N')
  printf("info(B)=%c\n", info(B));
  next(B) = A;
  printf("info(next(B))=%c\n", info(next(B)));

  // aplikasi tipe List2
  CreateList(&Senarai);            // CreateList(Senarai)
  InsertVFirst(&Senarai, info(A)); // InsertVFirst(Senarai, 'G');
  InsertVFirst(&Senarai, info(B)); // InsertVFirst(Senarai, 'N');
  InsertVLast(&Senarai, 'I');
  DeleteVLast(&Senarai, &info(P));
  PrintList(Senarai);

  return 0;
}
