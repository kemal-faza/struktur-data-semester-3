#ifndef PASIEN_H
#define PASIEN_H

#include "boolean.h"

typedef struct
{
    int id;
    int prioritas;
} Pasien;

void createPasien(Pasien *P, int id, int prioritas);
int getId(Pasien P);
int getPrioritas(Pasien P);
void printPasien(Pasien P);

#endif