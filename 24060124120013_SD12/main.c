/*Nama file:   */
/*Deskripsi:   */
/*Tanggal  :   */
/*Pembuat  :   */
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"
#include "list1.h"

int main()
{
      // kamus
      bintree3 W, D, E, F, B, C;
      List1 L, tambahan;

      // algoritma
      // bukalah komentar ini untuk menguji (aplikasi) Tree3

      D = Tree3(NIL, 'D', false, NIL, NIL);
      E = Tree3(NIL, 'E', false, NIL, NIL);
      F = Tree3(NIL, 'F', false, NIL, NIL);
      B = Tree3(NIL, 'B', false, NIL, D);
      C = Tree3(NIL, 'C', false, E, F);
      W = Tree3(NIL, 'A', false, B, C);

      // B = Tree3(NIL, 'B', false, NIL, D);
      // W = Tree3(NIL, 'A', false, B, NIL);
      // parent(B) = W;

      // W = Tree3(NIL, 'A', false,
      //           NIL,
      //           NIL);

      CreateList(&L);
      InsertVLast(&L, 'A');
      InsertVLast(&L, 'B');
      InsertVLast(&L, 'C');

      CreateList(&tambahan);
      InsertVLast(&tambahan, 'D');

      printDFS(W);

      printf("Tinggi pohon: %d", Tinggi(W));

      PrintLevel(W, 3);

      PrintBFS(W);

      printPathX(W, 'E');

      printPathDaunX(W, 'E');

      printAllPaths(W);

      printf("\nBanyak elemen tree: %d", NbElmTree(W));

      printf("\nBanyak elemen daun tree: %d", NbDaun(W));

      printf("\nLevel tree: %d", Level(W));

      PrintList(L);
      Pconcat(&L, tambahan);
      PrintList(L);

      PrintList(L);
      PrintList(Fconcat(L, tambahan));

      PrintList(LinearPrefix(W));
      PrintList(LinearPosfix(W));
      PrintList(LinearInfix(W));

      PrintList(LevelTree(W, 3));
      PrintList(LinearBreadthFS(W));

      printf("\n");

      return 0;
}