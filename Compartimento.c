    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Compartimento.h"

    void FLVazia(TCompartimento* rLista){
        rLista->pPrimeiro = (Apontador)malloc(sizeof(RCelula));
        rLista->pUltimo = rLista->pPrimeiro;
        rLista->pPrimeiro->pProx = NULL;
    }
    int LTamanho(TCompartimento* rLista){
        int cont=0;
        Apontador pAux = rLista->pPrimeiro->pProx;
        while(pAux!= NULL){
            cont+=1;
            pAux= pAux->pProx;
        }
        return cont;
    }
    float LPeso(TCompartimento* rLista){
        float pesoTotal = 0;
        Apontador pAux = rLista->pPrimeiro->pProx;

        while(pAux != NULL){
            pesoTotal += pAux->rocha.peso;
            pAux = pAux->pProx;
        }
        return pesoTotal;
    }
    int LEhVazia(TCompartimento* rLista){
        return (rLista->pPrimeiro == rLista->pUltimo);
    }
    int LInsere(TCompartimento *rLista, RochaMineral* pRocha){
        rLista->pUltimo->pProx = (Apontador)malloc(sizeof(RCelula));
        rLista->pUltimo = rLista->pUltimo->pProx;
        rLista->pUltimo->rocha = *pRocha;
        rLista->pUltimo->pProx = NULL;
        return 1;
    }

    void LImprime(TCompartimento* rLista){
        int cont;
        Apontador pAux;
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
    int LRetira(TCompartimento* rLista, RochaMineral* categoria){
        if(LEhVazia(rLista)) {return 0;}

        Apontador pAnterior = rLista->pPrimeiro;
        Apontador pAtual = rLista->pUltimo;

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

    void LTrocaR(TCompartimento* rLista) {
        if (LEhVazia(rLista)) {return;}

        Apontador pAux = rLista->pPrimeiro->pProx;
        Apontador maisPesada = NULL;
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

        Apontador maisLeve = NULL;
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