#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaRocha.h"

void FLVazia(RLista* rLista){
    rLista->pPrimeiro = (TamCelula)malloc(sizeof(RCelula));
    rLista->pUltimo = rLista->pPrimeiro;
    rLista->pPrimeiro->pProx = NULL;
}
int LEhVazia(RLista* rLista){
    return (rLista->pPrimeiro == rLista->pUltimo);
}
int LInsere(RLista *rLista, RochaMineral* pRocha){
    rLista->pUltimo->pProx = (TamCelula)malloc(sizeof(RCelula));
    rLista->pUltimo = rLista->pUltimo->pProx;
    rLista->pUltimo->rocha = *pRocha;
    rLista->pUltimo->pProx = NULL;
}
void LImprime(RLista* rLista){
    int cont;
    TamCelula pAux;
    pAux = rLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("Rocha %d°\n", cont++);
        printf("ID: %d\n", pAux->rocha.id);
        printf("Peso: %.2f\n", pAux->rocha.peso);
        printf("Localização; %.5lf %.5lf\n", pAux->rocha.latitude, pAux->rocha.longitude);
        printf("Categoria: %s\n", pAux->rocha.categoria);
        printf("Data de Coleta: %s\n", pAux->rocha.dataColeta);
    }
    
}