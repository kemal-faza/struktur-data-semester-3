/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza */
/* Tanggal : 27-11-2025 */

#include "pohon1.h"
#include "pohon2.h"

int main()
{
     // kamus
     bintree P, B;
     infotype C;

     // algirtma
     // P = Tree('T',
     //          Tree('I',
     //               Tree('N', NIL, NIL),
     //               Tree('F',
     //                    Tree('O', NIL, NIL),
     //                    NIL)),
     //          Tree('R',
     //               Tree('M',
     //                    Tree('A', NIL, NIL),
     //                    Tree('T', NIL, NIL)),
     //               Tree('I',
     //                    NIL,
     //                    Tree('K',
     //                         NIL,
     //                         Tree('A', NIL, NIL)))));
     P = Tree('T',
              Tree('I',
                   Tree('N', NIL, NIL),
                   Tree('F', NIL, NIL)),
              Tree('R',
                   Tree('M', NIL, NIL),
                   Tree('I', NIL, NIL)));
     // P = Tree('T', NIL, NIL);
     // P = BuildBalanceTree(7);

     PrintTreeInden(P, 3);

     // UpdateAllX(&P, 'I', 'K');

     // AddDaunTerkiri(&P, 'X');

     // AddDaun(&P, 'T', 'O', true);

     // InsertX(&P, 'W');

     // DelDaunTerkiri(&P, &C);

     // DelDaun(&P, 'A');

     // printf("IsBalanceTree: %d\n", IsBalanceTree(P));

     // printf("maxTree: %c\n", maxTree(P));

     // printf("minTree: %c\n", minTree(P));

     // printf("Apakah O ada di binary tree: %d\n", BSearch(P, 'O'));

     // B = InsSearch(P, 'O');

     // DelBtree(&P, 'T');

     // PrintTreeInden(B, 3);
     PrintTreeInden(P, 3);

     return 0;
}
