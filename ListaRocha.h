#ifndef LISTAROCHA_H
#define LISTAROCHA_H
#include "RochaM.h"

typedef struct Celula* TamCelula;
typedef struct Celula
{
    RochaMineral rocha;
    struct Celula* pProx;
} RCelula;

typedef struct 
{
    TamCelula pPrimeiro;
    TamCelula pUltimo;
}RLista;

void FLVazia(RLista* rLista);
int LEhVazia(RLista* rLista);
void LImprime(RLista* rLista);
void LTrocaR(RLista* rLista);
int LInsere(RLista* rLista, RochaMineral *pRocha);
int LRetira(RLista* rLista, RochaMineral *pRocha);


#endif