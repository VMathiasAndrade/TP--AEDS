#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#include "RochaM.h"

typedef RochaMineral TipoRocha;//OLHAR NA MONITORIA SE ESTÁ CORRETO ISSO AQUI, OU ENTAO COMO FAZER ISSO. 

typedef struct Celula* Apontador;
typedef struct Celula
{
    RochaMineral rocha;
    struct Celula* pProx;
} RCelula;

typedef struct 
{
    Apontador pPrimeiro;
    Apontador pUltimo;
}TCompartimento;

void FLVazia(TCompartimento* rLista);
int LTamanho(TCompartimento* rLista);
int LEhVazia(TCompartimento* rLista);
void LImprime(TCompartimento* rLista);
float LPeso(TCompartimento* rLista);
void LTrocaR(TCompartimento* rLista);
int LInsere(TCompartimento* rLista, RochaMineral *pRocha);
int LRetira(TCompartimento* rLista, RochaMineral* categoria);


#endif