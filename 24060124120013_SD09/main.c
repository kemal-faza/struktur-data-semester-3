/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza*/
/* Tanggal : 20 November 2025 */

#include <stdio.h>
#include "list3.h"

int main()
{
    infotype V;
    List3 L1;

    CreateList(&L1);

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

    printf("=== Test DeleteX ===\n");
    DeleteX(&L1, 'A');
    printf("Elemen yang dihapus: A\n");
    printf("List setelah delete: ");
    PrintList(L1);
    printf("Jumlah elemen: %d\n", NbElm(L1));

    return 0;
}