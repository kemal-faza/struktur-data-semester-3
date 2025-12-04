/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120013 & Muhamad Kemal Faza */
/* Tanggal : 27-11-2025 */

#include "pohon1.h"
#include "pohon2.h"

int main()
{ // kamus
     bintree P;
     // algirtma
     P = Tree('T',
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

     PrintTreeInden(P, 3);

     // UpdateAllX(&P, 'I', 'K');

     // AddDaunTerkiri(&P, 'X');

     AddDaun(&P, 'T', 'O', true);
     PrintTreeInden(P, 3);

     return 0;
}
