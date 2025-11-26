/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : */

#include "pohon1.h"

int main()
{ // kamus
     bintree B;
     // algirtma
     B = Tree('T',
              Tree('I',
                   Tree('N', NIL, NIL),
                   Tree('F',
                        Tree('O', NIL, NIL),
                        NIL)),
              Tree('R',
                   Tree('M',
                        Tree('A', NIL, NIL),
                        Tree('T', NIL, NIL)),
                   Tree('I',
                        NIL,
                        Tree('K',
                             NIL,
                             Tree('A', NIL, NIL)))));
     PrintPrefix(B);
     printf("\n");
     printf("Banyak elemen: %d\n", NbElm(B));
     printf("Banyak elemen daun: %d\n", NbDaun(B));
     printf("Apakah ada M di tree: %d\n", SearchX(B, 'M'));

     UpdateX(&B, 'A', 'D');
     PrintPrefix(B);

     printf("\n");
     return 0;
}
