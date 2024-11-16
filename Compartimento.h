#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#include "RochaM.h"

typedef struct CelulaRocha* ApontadorRocha;
typedef struct CelulaRocha
{
    RochaMineral rocha;
    struct CelulaRocha* pProx;
} RCelula;

typedef struct 
{
    ApontadorRocha pPrimeiro;
    ApontadorRocha pUltimo;
}RCompartimento;

void FLVazia(RCompartimento* rLista);
int LTamanho(RCompartimento* rLista);
int LEhVazia(RCompartimento* rLista);
void LImprime(RCompartimento* rLista);
float LPeso(RCompartimento* rLista);
void LTrocaR(RCompartimento* rLista);
int LInsere(RCompartimento* rLista, RochaMineral *pRocha);
int LRetira(RCompartimento* rLista, RochaMineral *pRocha);
#endif