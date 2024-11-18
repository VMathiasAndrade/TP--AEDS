#ifndef LISTAMINERAIS_H
#define LISTAMINERAIS_H
#define MaxTam 1000
#include "Mineral.h"

typedef int Apontador;

typedef struct
{
    Mineral ListaM[MaxTam];
    Apontador first, last;
} ListaMinerais;

void FLVaziaMine(ListaMinerais *LMinerais);
int LEhVaziaMine(ListaMinerais *LMinerais);
int LInsereMine(ListaMinerais *LMinerais, Mineral x);
int LRetiraMine(ListaMinerais *LMinerais, char *nome, Mineral *pX);
void LImprimeMine(ListaMinerais *LMinerais);

#endif