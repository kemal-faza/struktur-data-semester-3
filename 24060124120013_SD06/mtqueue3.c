#include <stdio.h>
#include "tqueue3.h"

static const char *b2s(boolean b) { return b ? "true" : "false"; }

void testHeader(const char *test)
{
    printf("\n=== %s ===\n", test);
}

void printStatus(tqueue3 Q)
{
    printf("Head: %d, Tail: %d, Size: %d\n", head3(Q), tail3(Q), sizeQueue3(Q));
    printf("Empty: %s, Full: %s, OneElement: %s, TailOverHead: %s\n",
           b2s(isEmptyQueue3(Q)), b2s(isFullQueue3(Q)),
           b2s(isOneElement3(Q)), b2s(isTailOverHead(Q)));
    printf("PrintQueue: ");
    printQueue3(Q);
    printf("ViewQueue:  ");
    viewQueue3(Q);
    if (!isEmptyQueue3(Q))
    {
        printf("InfoHead: %c, InfoTail: %c\n", infoHead3(Q), infoTail3(Q));
    }
    printf("\n");
}

int main(void)
{
    tqueue3 Q;
    char x;
    int i;

    testHeader("Test createQueue3 & isEmpty");
    createQueue3(&Q);
    printStatus(Q);

    testHeader("Test enqueue - Fill queue sequentially");
    enqueue3(&Q, 'A');
    printStatus(Q);
    enqueue3(&Q, 'B');
    printStatus(Q);
    enqueue3(&Q, 'C');
    printStatus(Q);
    enqueue3(&Q, 'D');
    printStatus(Q);
    enqueue3(&Q, 'E');
    printStatus(Q);

    printf("Trying to enqueue when full:\n");
    enqueue3(&Q, 'F');
    printStatus(Q);

    testHeader("Test dequeue - Partial dequeue");
    dequeue3(&Q, &x);
    printf("Dequeued: %c\n", x);
    printStatus(Q);
    dequeue3(&Q, &x);
    printf("Dequeued: %c\n", x);
    printStatus(Q);

    testHeader("Test circular behavior - Enqueue after dequeue");
    enqueue3(&Q, 'X');
    printStatus(Q);
    enqueue3(&Q, 'Y');
    printStatus(Q);

    printf("Current queue should show tail wrapped around (tail < head):\n");
    printf("Expected: tail=%d < head=%d = %s\n", tail3(Q), head3(Q), b2s(isTailOverHead(Q)));

    testHeader("Test complete dequeue");
    while (!isEmptyQueue3(Q))
    {
        dequeue3(&Q, &x);
        printf("Dequeued: %c\n", x);
        printStatus(Q);
    }

    printf("Trying to dequeue when empty:\n");
    dequeue3(&Q, &x);
    printf("Dequeued: '%c'\n", x);
    printStatus(Q);

    testHeader("Test edge case - Single element operations");
    enqueue3(&Q, 'Z');
    printStatus(Q);
    dequeue3(&Q, &x);
    printf("Dequeued: %c\n", x);
    printStatus(Q);

    testHeader("Test complex circular scenario");
    createQueue3(&Q);

    // Fill queue
    for (i = 0; i < 5; i++)
    {
        enqueue3(&Q, '1' + i);
    }
    printf("Full queue:\n");
    printStatus(Q);

    // Dequeue 3 elements (head moves to position 4)
    for (i = 0; i < 3; i++)
    {
        dequeue3(&Q, &x);
        printf("Dequeued: %c\n", x);
    }
    printf("After 3 dequeues (head should be at pos 4):\n");
    printStatus(Q);

    // Enqueue 3 more (tail wraps around)
    enqueue3(&Q, 'X');
    printf("After enqueue X:\n");
    printStatus(Q);
    enqueue3(&Q, 'Y');
    printf("After enqueue Y:\n");
    printStatus(Q);
    enqueue3(&Q, 'Z');
    printf("After enqueue Z (should be full, tail wrapped):\n");
    printStatus(Q);

    testHeader("Final verification - Size calculation in wrapped state");
    printf("Manual count verification:\n");
    printf("Elements should be at positions: head=%d to 5, then 1 to tail=%d\n",
           head3(Q), tail3(Q));
    printf("Expected size: %d, Calculated size: %d\n",
           (5 - head3(Q) + 1) + tail3(Q), sizeQueue3(Q));

    return 0;
}