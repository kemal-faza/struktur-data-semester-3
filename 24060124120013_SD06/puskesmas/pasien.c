#include "pasien.h"
#include <stdio.h>

void createPasien(Pasien *P, int id, int prioritas)
{
    (*P).id = id;
    (*P).prioritas = prioritas;
}

int getId(Pasien P)
{
    return P.id;
}

int getPrioritas(Pasien P)
{
    return P.prioritas;
}

void printPasien(Pasien P)
{
    printf("ID: %d\n", getId(P));
    printf("Prioritas: %d\n", getPrioritas(P));
}
