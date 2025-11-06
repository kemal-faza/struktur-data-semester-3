#include <stdio.h>
#include "tqueue.h"

/* Program   : tqueue.h */
/* Deskripsi : file BODY modul queue karakter model kontigu head stabil */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza*/
/* Tanggal   : 02-10-2025*/
/***********************************/

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '-', head=tail=0 }*/
void createQueue(tqueue *Q)
{
    // kamus lokal
    int i;

    // algoritma
    for (i = 1; i <= 5; i++)
    {
        createPasien(&(*Q).wadah[i], 0, 0);
    }
    (*Q).head = 0;
    tail(*Q) = 0;
}

/*function infoHead(Q:tQueue)-> character
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Pasien infoHead(tqueue Q)
{
    // kamus lokal
    Pasien P;

    // algoritma
    createPasien(&P, 0, 0);
    if (isEmptyQueue(Q))
    {
        return P;
    }
    else
    {
        return Q.wadah[head(Q)];
    }
}

/*function infoTail(Q:tQueue)-> character
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Pasien infoTail(tqueue Q)
{
    // kamus lokal
    Pasien P;

    // algoritma
    if (isEmptyQueue(Q))
    {
        createPasien(&P, 0, 0);
        return P;
    }
    else
    {
        return Q.wadah[tail(Q)];
    }
}

/*function sizeQueue(Q:tQueue)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q)
{
    return tail(Q);
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q)
{
    // kamus lokal
    int i;

    // algoritma
    for (i = 1; i <= 5; i++)
    {
        i == 5 ? printf("%d\n", Q.wadah[i]) : printf("%d | ", Q.wadah[i]);
    }
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q)
{
    // kamus lokal
    int i;

    // algoritma
    for (i = head(Q); i <= tail(Q); i++)
    {
        if (i == tail(Q))
        {
            printf("%d\n", Q.wadah[i]);
        }
        else
        {
            printf("%d | ", Q.wadah[i]);
        }
    }
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q)
{
    return head(Q) == 0 && tail(Q) == 0;
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q)
{
    // kamus lokal

    // algoritma
    return tail(Q) == 5;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q)
{
    // kamus lokal

    // algoritma
    return head(Q) == 1 && tail(Q) == 1;
}

/*procedure enqueue( input/output Q:tQueue, input e: character )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, Pasien e)
{
    // kamus lokal

    // algoritma
    if (isEmptyQueue(*Q))
    {
        head(*Q) = 1;
    }

    if (!isFullQueue(*Q))
    {
        tail(*Q)++;
        (*Q).wadah[tail(*Q)] = e;
    }
}

/*procedure deQueue( input/output Q:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, Pasien *e)
{
    // kamus lokal
    int i;

    // algoritma
    *e = infoHead(*Q);
    if (!isEmptyQueue(*Q))
    {
        for (i = head(*Q); i < tail(*Q); i++)
        {
            (*Q).wadah[i] = (*Q).wadah[i + 1];
        }
        createPasien(&(*Q).wadah[tail(*Q)], 0, 0);
        tail(*Q)--;
        if (tail(*Q) == 0)
        {
            head(*Q) = 0;
        }
    }
}