/* Program   : tqueue.h */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza*/
/* Tanggal   : 02-10-2025*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"

int main()
{
    tqueue2 Q, Q1, Q2;
    char e = '-';

    createQueue2(&Q);
    printQueue2(Q);
    printf("=== Test enqueue 2 ===\n");
    enqueue2(&Q, 'A');
    printf("tail = %d\n", tail2(Q));
    enqueue2(&Q, 'B');
    printf("tail = %d\n", tail2(Q));
    enqueue2(&Q, 'C');
    printf("tail = %d\n", tail2(Q));
    printQueue2(Q);
    viewQueue2(Q);

    printf("=== Test dequeue 2 ===\n");
    dequeue2(&Q, &e);
    printf("tail = %d\n", tail2(Q));
    printf("dequeue -> %c\n", e);
    printQueue2(Q);
    viewQueue2(Q);

    printf("=== Test enqueue 2N ===\n");
    enqueue2N(&Q, 3);
    printQueue2(Q);

    printf("=== Test equal ===\n");
    createQueue2(&Q1);
    createQueue2(&Q2);
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    enqueue2(&Q2, 'A');
    enqueue2(&Q2, 'B');

    printf("Isi Q1:\n");
    printQueue2(Q1);
    printf("Isi Q2:\n");
    printQueue2(Q2);
    if (isEqualQueue2(Q1, Q2))
    {
        printf("Q1 dan Q2 sama\n");
    }
    else
    {
        printf("Q1 dan Q2 beda\n");
    }

    enqueue2(&Q2, 'C');
    printf("Isi Q1:\n");
    printQueue2(Q1);
    printf("Isi Q2:\n");
    printQueue2(Q2);
    if (isEqualQueue2(Q1, Q2))
    {
        printf("Q1 dan Q2 sama\n");
    }
    else
    {
        printf("Q1 dan Q2 beda\n");
    }

    return 0;
}