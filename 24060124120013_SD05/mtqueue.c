/* Program   : tqueue.h */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza*/
/* Tanggal   : 02-10-2025*/
/***********************************/

#include <stdio.h>
#include "tqueue.h"

int main()
{
    tqueue Q, Q1, Q2;
    char e = '-';

    createQueue(&Q);
    printQueue(Q);
    printf("=== Test enqueue ===\n");
    enqueue(&Q, 'A');
    printf("tail = %d\n", tail(Q));
    enqueue(&Q, 'B');
    printf("tail = %d\n", tail(Q));
    enqueue(&Q, 'C');
    printf("tail = %d\n", tail(Q));
    printQueue(Q);

    printf("=== Test dequeue ===\n");
    dequeue(&Q, &e);
    printf("tail = %d\n", tail(Q));
    printf("dequeue -> %c\n", e);
    printQueue(Q);
    dequeue(&Q, &e);
    printf("tail = %d\n", tail(Q));
    printf("dequeue -> %c\n", e);
    printQueue(Q);

    printf("=== Test enqueue 2 ===\n");
    createQueue(&Q1);
    createQueue(&Q2);
    enqueue2(&Q1, &Q2, 'X');
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    enqueue2(&Q1, &Q2, 'Y');
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    enqueue2(&Q1, &Q2, 'Z');
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    enqueue2(&Q1, &Q2, 'W');
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);

    printf("=== Test dequeue 2 ===\n");
    dequeue2(&Q1, &Q2, &e);
    printf("dequeue2 -> %c\n", e);
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    dequeue2(&Q1, &Q2, &e);
    printf("dequeue2 -> %c\n", e);
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    dequeue2(&Q1, &Q2, &e);
    printf("dequeue2 -> %c\n", e);
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    dequeue2(&Q1, &Q2, &e);
    printf("dequeue2 -> %c\n", e);
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);

    return 0;
}