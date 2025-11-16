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
  infotype P;
  List2 Senarai, Senarai2, Senarai3, Senarai4, Senarai5;
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
  CreateList(&Senarai2);           // CreateList(Senarai2)
  InsertVFirst(&Senarai, info(A)); // InsertVFirst(Senarai, 'G');
  InsertVFirst(&Senarai, info(B)); // InsertVFirst(Senarai, 'N');
  InsertVLast(&Senarai, 'I');
  InsertVLast(&Senarai, 'G');
  // DeleteVFirst(&Senarai, &info(P));
  // DeleteVLast(&Senarai, &info(P));
  // DeleteX(&Senarai, 'I');
  // SearchX(Senarai, 'G', &P);
  // UpdateX(&Senarai, 'G', 'I');

  printf("Isi list setelah diisi: ");
  PrintList(Senarai);

  Invers(&Senarai);

  printf("Isi list setelah dibalik: ");
  PrintList(Senarai);

  // printf("address: %p", P);
  printf("Count G: %d\n", CountX(Senarai, 'G'));
  printf("Rasio Kemunculan G: %.2f\n", FrekuensiX(Senarai, 'G'));
  printf("Count Vokal: %d\n", CountVocal(Senarai));
  printf("Count NG: %d\n", CountNG(Senarai));

  InsertVAfterX(&Senarai, 'N', 'X');
  printf("Masukkan X setelah N: ");
  PrintList(Senarai);

  InsertVBeforeX(&Senarai, 'G', 'Y');
  printf("Masukkan Y sebelum G: ");
  PrintList(Senarai);

  DeleteVAfterX(&Senarai, 'X', &P);
  printf("Hapus elemen setelah X (nilai yang dihapus: %c): ", P);
  PrintList(Senarai);

  // DeleteVBeforeX(&Senarai, 'G', &P);
  // printf("Hapus elemen sebelum G (nilai yang dihapus: %c): ", P);
  // PrintList(Senarai);

  InsertVLast(&Senarai, 'I');

  DeleteAllX(&Senarai, 'I');
  printf("Hapus semua elemen I: ");
  PrintList(Senarai);

  printf("MaxMember(Senarai): %d\n", MaxMember(Senarai));
  printf("Modus(Senarai): %c\n", Modus(Senarai));

  CopyList(Senarai, &Senarai2);
  printf("CopyList(Senarai, Senarai2): ");
  PrintList(Senarai2);

  ConcatList(Senarai, Senarai2, &Senarai3);
  printf("ConcatList(Senarai, Senarai2, Senarai3): ");
  PrintList(Senarai3);

  SplitList(Senarai3, &Senarai4, &Senarai5);
  printf("SplitList(Senarai3, Senarai4, Senarai5): \n");
  printf("Senarai4: ");
  PrintList(Senarai4);
  printf("Senarai5: ");
  PrintList(Senarai5);

  return 0;
}
