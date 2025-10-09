#include <stdio.h>
#include "tqueue.h"

void testHeader(const char *test)
{
    printf("\n=== %s ===\n", test);
}

void printStatus(tqueue Q)
{
    printf("Head: %d, Tail: %d, Size: %d\n", head(Q), tail(Q), sizeQueue(Q));
    printf("Empty: %s, Full: %s, OneElement: %s\n",
           isEmptyQueue(Q) ? "true" : "false",
           isFullQueue(Q) ? "true" : "false",
           isOneElement(Q) ? "true" : "false");

    if (!isEmptyQueue(Q))
    {
        printf("InfoHead: ");
        printPasien(infoHead(Q));
        printf("InfoTail: ");
        printPasien(infoTail(Q));
    }

    printf("ViewQueue: ");
    viewQueue(Q);
    printf("\n");
}

// Fungsi untuk insert berdasarkan prioritas (priority queue)
void enqueuePriority(tqueue *Q, Pasien P)
{
    if (isFullQueue(*Q))
    {
        printf("Queue penuh! Tidak bisa menambah pasien ID %d\n", getId(P));
        return;
    }

    if (isEmptyQueue(*Q))
    {
        enqueue(Q, P);
        return;
    }

    // Simpan antrian sementara
    tqueue temp;
    createQueue(&temp);
    Pasien current;
    boolean inserted = false;

    // Cari posisi yang tepat untuk insert
    while (!isEmptyQueue(*Q))
    {
        dequeue(Q, &current);

        // Insert jika prioritas lebih tinggi (angka lebih kecil) atau sama tapi ID lebih kecil
        if (!inserted && (getPrioritas(P) < getPrioritas(current) ||
                          (getPrioritas(P) == getPrioritas(current) && getId(P) < getId(current))))
        {
            enqueue(&temp, P);
            inserted = true;
        }
        enqueue(&temp, current);
    }

    // Jika belum di-insert (prioritas paling rendah), insert di akhir
    if (!inserted)
    {
        enqueue(&temp, P);
    }

    // Kembalikan ke queue asli
    while (!isEmptyQueue(temp))
    {
        dequeue(&temp, &current);
        enqueue(Q, current);
    }
}

int main(void)
{
    tqueue antrian;
    Pasien pasien, keluar;

    testHeader("Test createQueue & isEmpty");
    createQueue(&antrian);
    printStatus(antrian);

    testHeader("Test Priority Queue - Menambah pasien berdasarkan prioritas");

    // Pasien datang tidak berurutan prioritas
    createPasien(&pasien, 101, 3); // Prioritas rendah
    printf("Menambah Pasien ID 101, Prioritas 3:\n");
    enqueuePriority(&antrian, pasien);
    printStatus(antrian);

    createPasien(&pasien, 102, 1); // Prioritas tinggi
    printf("Menambah Pasien ID 102, Prioritas 1:\n");
    enqueuePriority(&antrian, pasien);
    printStatus(antrian);

    createPasien(&pasien, 103, 2); // Prioritas sedang
    printf("Menambah Pasien ID 103, Prioritas 2:\n");
    enqueuePriority(&antrian, pasien);
    printStatus(antrian);

    createPasien(&pasien, 104, 1); // Prioritas tinggi, ID lebih besar
    printf("Menambah Pasien ID 104, Prioritas 1:\n");
    enqueuePriority(&antrian, pasien);
    printStatus(antrian);

    createPasien(&pasien, 105, 2); // Prioritas sedang, ID lebih besar
    printf("Menambah Pasien ID 105, Prioritas 2:\n");
    enqueuePriority(&antrian, pasien);
    printStatus(antrian);

    testHeader("Test Antrian Penuh");
    createPasien(&pasien, 106, 1);
    printf("Mencoba menambah pasien ke-6 (queue penuh):\n");
    enqueuePriority(&antrian, pasien);
    printStatus(antrian);

    testHeader("Test Dequeue - Melayani pasien berdasarkan urutan prioritas");

    while (!isEmptyQueue(antrian))
    {
        dequeue(&antrian, &keluar);
        printf("Melayani pasien:\n");
        printPasien(keluar);
        printf("Status antrian setelah dilayani:\n");
        printStatus(antrian);
    }

    testHeader("Test Dequeue pada antrian kosong");
    dequeue(&antrian, &keluar);
    printf("Mencoba dequeue dari antrian kosong:\n");
    printf("Hasil: ID = %d, Prioritas = %d\n", getId(keluar), getPrioritas(keluar));
    printStatus(antrian);

    testHeader("Test Skenario Realistis Puskesmas");
    printf("Simulasi kedatangan pasien dalam sehari:\n");

    // Reset antrian
    createQueue(&antrian);

    // Kedatangan pasien acak
    createPasien(&pasien, 201, 2);
    enqueuePriority(&antrian, pasien);
    printf("Pasien 201 (prioritas 2) datang\n");

    createPasien(&pasien, 202, 3);
    enqueuePriority(&antrian, pasien);
    printf("Pasien 202 (prioritas 3) datang\n");

    createPasien(&pasien, 203, 1);
    enqueuePriority(&antrian, pasien);
    printf("Pasien 203 (prioritas 1 - GAWAT DARURAT) datang\n");

    printf("\nUrutan pelayanan (prioritas tertinggi dulu):\n");
    viewQueue(antrian);

    // Layani satu pasien
    dequeue(&antrian, &keluar);
    printf("\nMelayani: ");
    printPasien(keluar);

    // Pasien darurat datang
    createPasien(&pasien, 204, 1);
    enqueuePriority(&antrian, pasien);
    printf("Pasien 204 (prioritas 1 - GAWAT DARURAT) datang saat pelayanan berlangsung\n");

    printf("Urutan antrian terbaru:\n");
    viewQueue(antrian);

    return 0;
}