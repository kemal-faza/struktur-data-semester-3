/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza*/
/* Tanggal : 20 November 2025 */

#include <stdio.h>
#include "list3.h"

int main()
{
    address P;
    infotype V;
    List3 L1, L2, L3;

    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);

    printf("=== Test InsertVFirst dan InsertVLast ===\n");
    InsertVFirst(&L1, 'A');
    InsertVFirst(&L1, 'B');
    InsertVLast(&L1, 'C');
    printf("List setelah insert: ");
    PrintList(L1);
    printf("Jumlah elemen: %d\n\n", NbElm(L1));

    // printf("=== Test DeleteVFirst ===\n");
    // DeleteVFirst(&L1, &V);
    // printf("Elemen yang dihapus: %c\n", V);
    // printf("List setelah delete: ");
    // PrintList(L1);
    // printf("Jumlah elemen: %d\n", NbElm(L1));

    // printf("=== Test DeleteVLast ===\n");
    // DeleteVLast(&L1, &V);
    // printf("Elemen yang dihapus: %c\n", V);
    // printf("List setelah delete: ");
    // PrintList(L1);
    // printf("Jumlah elemen: %d\n", NbElm(L1));

    // printf("=== Test DeleteX ===\n");
    // DeleteX(&L1, 'B');
    // printf("Elemen yang dihapus: B\n");
    // printf("List setelah delete: ");
    // PrintList(L1);
    // printf("Jumlah elemen: %d\n", NbElm(L1));

    // printf("=== Test SearchX ===\n");
    // SearchX(L1, 'A', &P);
    // printf("Elemen yang dicari: %c\n", info(P));

    // printf("=== Test UpdateX ===\n");
    // UpdateX(&L1, 'B', 'D');
    // printf("Elemen B diupdate menjadi D\n");
    // printf("List setelah update: ");
    // PrintList(L1);

    // printf("=== Test Invers ===\n");
    // Invers(&L1);
    // printf("List setelah invers: ");
    // PrintList(L1);

    // printf("=== Test InsertVAfterX ===\n");
    // InsertVAfterX(&L1, 'A', 'D');
    // printf("Menambahkan elemen D setelah A\n");
    // printf("List setelah insert: ");
    // PrintList(L1);
    // printf("Jumlah elemen: %d\n", NbElm(L1));

    // printf("=== Test InsertVBeforeX ===\n");
    // InsertVBeforeX(&L1, 'A', 'D');
    // printf("Menambahkan elemen D sebelum A\n");
    // printf("List setelah insert: ");
    // PrintList(L1);
    // printf("Jumlah elemen: %d\n", NbElm(L1));

    // printf("=== Test DeleteVAfterX ===\n");
    // DeleteVAfterX(&L1, 'C', &V);
    // printf("Hapus elemen setelah C, elemen yang dihapus: %c\n", V);
    // printf("List setelah delete: ");
    // PrintList(L1);
    // printf("Jumlah elemen: %d\n", NbElm(L1));

    // printf("=== Test DeleteVBeforeX ===\n");
    // DeleteVBeforeX(&L1, 'A', &V);
    // printf("Hapus elemen sebelum C, elemen yang dihapus: %c\n", V);
    // printf("List setelah delete: ");
    // PrintList(L1);
    // printf("Jumlah elemen: %d\n", NbElm(L1));

    // printf("=== Test CountX ===\n");
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'C');
    // InsertVLast(&L1, 'A');
    // PrintList(L1);
    // printf("Jumlah elemen A: %d\n", CountX(L1, 'A'));

    // printf("=== Test FrekuensiX ===\n");
    // InsertVLast(&L1, 'B');
    // InsertVLast(&L1, 'C');
    // InsertVLast(&L1, 'A');
    // PrintList(L1);
    // printf("Rasio elemen A: %f\n", FrekuensiX(L1, 'A'));

    // printf("=== Test MaxMember ===\n");
    // InsertVLast(&L1, 'B');
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'A');
    // PrintList(L1);
    // printf("Banyaknya kemunculan elemen terbanyak pada list: %d\n", MaxMember(L1));

    // printf("=== Test Modus ===\n");
    // InsertVLast(&L1, 'B');
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'B');
    // PrintList(L1);
    // printf("Elemen terbanyak pada list: %c\n", Modus(L1));

    // printf("=== Test CountVocal ===\n");
    // InsertVLast(&L1, 'B');
    // InsertVLast(&L1, 'E');
    // InsertVLast(&L1, 'K');
    // InsertVLast(&L1, 'U');
    // PrintList(L1);
    // printf("Banyak huruf vokal pada list: %d\n", CountVocal(L1));

    // printf("=== Test CountNG ===\n");
    // InsertVLast(&L1, 'N');
    // InsertVLast(&L1, 'G');
    // InsertVLast(&L1, 'G');
    // InsertVLast(&L1, 'N');
    // PrintList(L1);
    // printf("Banyak huruf N disertai G pada list: %d\n", CountNG(L1));

    // printf("=== Test SearchAllX ===\n");
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'B');
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'E');
    // PrintList(L1);
    // SearchAllX(L1, 'A');

    // printf("=== Test DeleteAllX ===\n");
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'B');
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'E');
    // PrintList(L1);
    // DeleteAllX(&L1, 'A');
    // PrintList(L1);

    // printf("=== Test ConcatList ===\n");
    // InsertVLast(&L2, 'A');
    // InsertVLast(&L2, 'B');
    // InsertVLast(&L2, 'A');
    // InsertVLast(&L2, 'E');
    // PrintList(L1);
    // PrintList(L2);
    // printf("Hasil concat: ");
    // ConcatList(L1, L2, &L3);
    // PrintList(L3);

    // printf("=== Test SplitList ===\n");
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'B');
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'E');
    // PrintList(L1);
    // SplitList(L1, &L2, &L3);
    // PrintList(L2);
    // PrintList(L3);

    // printf("=== Test CopyList ===\n");
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'B');
    // InsertVLast(&L1, 'A');
    // InsertVLast(&L1, 'E');
    // PrintList(L1);
    // CopyList(L1, &L2);
    // PrintList(L2);

    return 0;
}