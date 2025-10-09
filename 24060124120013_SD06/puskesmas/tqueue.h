#ifndef tqueue_H
#define tqueue_H
#include "boolean.h"
#include "pasien.h"

/* Program   : tqueue.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza*/
/* Tanggal   : 02-10-2025*/
/***********************************/

/* type tQueue = <  wadah: array [1..5] of character ,
          head: integer ,
          tail: integer >
{cara akses: Q:tQueue, Q.head=head(Q) ...} */
typedef struct
{
  Pasien wadah[6]; // kapasitas 5 elemen, indeks 0 tidak dipakai
  int head;
  int tail;
} tqueue;

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '-', head=tail=0 }*/
void createQueue(tqueue *Q);

/*function Head(Q:tQueue)-> integer
{mengembalikan elemen terdepan antrian Q} */
// int Head(tqueue Q);
#define head(Q) (Q).head // implementasi fisik macro

/*function Tail(Q:tQueue)-> integer
{mengembalikan elemen terakhir antrian Q} */
// int Tail(tqueue Q);
#define tail(Q) (Q).tail // implementasi fisik macro

/*function infoHead(Q:tQueue)-> Pasien
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Pasien infoHead(tqueue Q);

/*function infoTail(Q:tQueue)-> Pasien
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Pasien infoTail(tqueue Q);

/*function sizeQueue(Q:tQueue)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q);

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q);

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q);

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q);

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q);

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q);

/*procedure enqueue( input/output Q:tQueue, input e: Pasien )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, Pasien e);

/*procedure deQueue( input/output Q:tQueue, output e: Pasien )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, Pasien *e);

#endif
