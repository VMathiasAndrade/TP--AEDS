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
float LPeso(RLista* rLista){
    float pesoTotal = 0;
    TamCelula pAux = rLista->pPrimeiro->pProx;

    while(pAux != NULL){
        pesoTotal += pAux->rocha.peso;
        pAux = pAux->pProx;
    }

    return pesoTotal;
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
int LRetira(RLista* rLista, char* categoria){
    if(LEhVazia(rLista)) {return 0;}

    TamCelula pAnterior = rLista->pPrimeiro;
    TamCelula pAtual = rLista->pUltimo;

    while(pAtual != NULL){
        if(strcmp(pAtual->rocha.categoria, categoria) == 0){
            pAnterior->pProx = pAtual->pProx;
            if(pAtual == rLista->pUltimo){
                rLista->pUltimo = pAnterior;
            }
            free(pAtual);
            return 1;
        }
        pAnterior = pAtual;
        pAtual = pAtual->pProx;
    }
    return 0;
}

void LTrocaR(RLista* rLista) {
    if (LEhVazia(rLista)) {return;}

    TamCelula pAux = rLista->pPrimeiro->pProx;
    TamCelula maisPesada = NULL;
    float maiorPeso = 0;

    while (pAux != NULL) {
        if (pAux->rocha.peso > maiorPeso) {
            maiorPeso = pAux->rocha.peso;
            maisPesada = pAux;
        }
        pAux = pAux->pProx;
    }

    if (maisPesada == NULL) {return;}

    char categoriaMaisPesada[40];
    strcpy(categoriaMaisPesada, maisPesada->rocha.categoria);

    TamCelula maisLeve = NULL;
    float menorPeso = -1; 

    pAux = rLista->pPrimeiro->pProx;
     while (pAux != NULL) {
        if (strcmp(pAux->rocha.categoria, categoriaMaisPesada) == 0) {
            if (menorPeso == -1 || pAux->rocha.peso < menorPeso) {
                menorPeso = pAux->rocha.peso;
                maisLeve = pAux;
            }
        }
        pAux = pAux->pProx;
    }

    if(maisLeve == NULL) {return;} 

    if (maisLeve != NULL && maisLeve->rocha.peso < maisPesada->rocha.peso){
        RochaMineral temp = maisPesada->rocha;
        maisPesada->rocha = maisLeve->rocha;
        maisLeve->rocha = temp;
    }
}