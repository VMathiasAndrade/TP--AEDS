#ifndef LISTASONDAS_H
#define LISTASONDAS_H
#include "Sonda.h"

typedef Sonda TipoSonda;

typedef struct Celula* Apontador;
typedef struct Celula{
    Sonda sonda;
    struct Celula* pProx;
} SCelula;

typedef struct{
    Apontador pPrimeiro;
    Apontador pUltimo;
}SLista;

void FLVaziaSonda(SLista* sLista);
void LInsereSonda(SLista* sLista, Sonda* pSonda);
void LRetiraSonda(SLista* sLista, Sonda id);
void ImprimeLSonda(SLista* sLista);
#endif