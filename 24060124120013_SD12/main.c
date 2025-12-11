/*Nama file:   */
/*Deskripsi:   */
/*Tanggal  :   */
/*Pembuat  :   */
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"

int main()
{
      // kamus
      bintree3 W;

      // algoritma
      // bukalah komentar ini untuk menguji (aplikasi) Tree3
      W = Tree3(NIL, 'A', false,
                Tree3(W, 'B', false,
                      NIL,
                      Tree3(left(W), 'D', false, NIL, NIL)),
                Tree3(W, 'C', false,
                      Tree3(right(W), 'E', false, NIL, NIL),
                      Tree3(right(W), 'F', false, NIL, NIL)));
      printDFS(W);
      // printPathX(W, 'B');

      return 0;
}