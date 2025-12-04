/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza */
/* Tanggal : 27-11-2025 */

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
     // B = Tree('T',
     //          Tree('I',
     //               Tree('N', NIL, NIL), NIL),
     //          NIL);
     // B = Tree('T',
     //          Tree('R',
     //               Tree('I',
     //                    NIL,
     //                    Tree('K',
     //                         NIL,
     //                         Tree('A', NIL, NIL))),
     //               Tree('M',
     //                    Tree('A', NIL, NIL),
     //                    Tree('T', NIL, NIL))),
     //          Tree('I',
     //               Tree('F',
     //                    Tree('O', NIL, NIL),
     //                    NIL),
     //               Tree('N', NIL, NIL)));

     // PrintPrefix(B);
     // printf("\n");

     // printf("Banyak elemen: %d\n", NbElm(B));
     // printf("Banyak elemen daun: %d\n", NbDaun(B));
     // printf("Apakah ada M di tree: %d\n", SearchX(B, 'M'));

     // UpdateX(&B, 'A', 'D');
     // PrintPrefix(B);
     // printf("\n");

     // printf("Banyak elemen T: %d\n", CountX(B, 'T'));

     // printf("Apakah tree skew left: %d\n", IsSkewLeft(B));

     PrintPrefixRingkas(B);
     printf("\n");

     // printf("Tinggi tree: %d\n", Tinggi(B));

     // printf("Level T: %d\n", LevelX(B, 'T'));

     // printf("Banyaknya node di level 3: %d\n", CountLevel(B, 3));

     // PrintLevel(B, 3);
     // printf("\n");

     // printf("Daun terkiri di tree: %c\n", GetDaunTerkiri(B));

     // printf("Rasio kemunculan A di tree: %f\n", FrekuensiX(B, 'R'));

     // printf("Banyak huruf vokal pada tree: %d\n", CountVocal(B));

     // PrintVocal(B);
     // printf("\n");

     // printf("Banyak huruf konsonan pada tree: %d\n", CountConsonant(B));

     PrintConsonant(B);
     printf("\n");

     printf("\n");
     return 0;
}
