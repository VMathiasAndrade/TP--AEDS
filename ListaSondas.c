#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ListaSondas.h"

void FLVaziaSonda(SLista *slista)
{
    slista->pPrimeiro = (ApontadorSonda)malloc(sizeof(SCelula));
    slista->pUltimo = slista->pPrimeiro;
    slista->pPrimeiro->pProx = NULL;
}

int LInsereSonda(SLista *sLista, Sonda *pSonda)
{
    sLista->pUltimo->pProx = (ApontadorSonda)malloc(sizeof(SCelula));
    sLista->pUltimo = sLista->pUltimo->pProx;
    sLista->pUltimo->sonda = *pSonda;
    sLista->pUltimo->pProx = NULL;
    return 1;
}

int LRetiraSonda(SLista *sLista, Sonda *pSonda)
{
    if (sLista == NULL || sLista->pPrimeiro == NULL)
    {
        return 0; // Trata lista vazia ou nula
    }

    ApontadorSonda pAnterior = NULL;
    ApontadorSonda pAtual = sLista->pPrimeiro;

    while (pAtual != NULL)
    {
        if (pAtual->sonda.id == pSonda->id)
        {
            if (pAnterior == NULL)
            {
                sLista->pPrimeiro = pAtual->pProx; // Remove o primeiro elemento
            }
            else
            {
                pAnterior->pProx = pAtual->pProx; // Remove elementos intermediários ou o último
            }

            if (pAtual == sLista->pUltimo)
            {
                sLista->pUltimo = pAnterior; // Atualiza o último ponteiro
            }

            free(pAtual);
            return 1;
        }
        pAnterior = pAtual;
        pAtual = pAtual->pProx;
    }
    return 0;
}

void ImprimeLSonda(SLista *sLista)
{
    int cont = 0;
    ApontadorSonda pAux = pAux = sLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("ID: %d\n", pAux->sonda.id);
        printf("Rocha(s): %s\n", pAux->sonda.cRocha.pPrimeiro->rocha.categoria);
        printf("Latitude e longitude: %.6f %.6f\n", pAux->sonda.latitude, pAux->sonda.longitude);
        printf("Capacidade: %.2f\n", pAux->sonda.capacidade);
        printf("Status da sonda: %s\n\n", pAux->sonda.EstaLigada);

        pAux = pAux->pProx;
    }
}

Sonda *DistEuclidiana(SLista *ListaS, double lat_r, double long_r, RochaMineral *rocha) {
    SCelula *pAux = ListaS->pPrimeiro->pProx;
    Sonda *primeiraSonda = NULL;
    Sonda *segundaSonda = NULL;
    double menorDist = 1000000, segundaMenorDist = 1000000;
    double lat_i, long_i, distSonda;

    while (pAux != NULL)
    {
        lat_i = pAux->sonda.latitude;
        long_i = pAux->sonda.longitude;
        distSonda = sqrt(pow(lat_r - lat_i, 2) + pow(long_r - long_i, 2));

        if (distSonda < menorDist)
        {
            segundaMenorDist = menorDist;
            segundaSonda = primeiraSonda;
            menorDist = distSonda;
            primeiraSonda = &pAux->sonda;
        }
        else if (distSonda < segundaMenorDist)
        {
            segundaMenorDist = distSonda;
            segundaSonda = &pAux->sonda;
        }
        pAux = pAux->pProx;
    }

    if (primeiraSonda != NULL && LPeso(primeiraSonda) + rocha->peso <= primeiraSonda->capacidade)
    {
        return primeiraSonda;
    }
    else if (segundaSonda != NULL && LPeso(segundaSonda) + rocha->peso <= segundaSonda->capacidade)
    {
        return segundaSonda;
    }
    else
    {
        return primeiraSonda; // Retorna a primeira sonda para o caso 2 (troca de rochas)
    }
}

void InsereRochaS(SLista *ListaS, RochaMineral *rocha) {
    Sonda *sondaTemp = DistEuclidiana(ListaS, rocha->latitude, rocha->longitude, rocha);

    if (sondaTemp == NULL)
    {
        printf("Nao ha sonda perto!\n");
        return; // Sai da função se não houver sonda próxima
    }

    if (LPeso(sondaTemp) + rocha->peso > sondaTemp->capacidade)
    {
        // Caso 1: Capacidade insuficiente, tenta trocar por rocha mais pesada
        ApontadorRocha pAux = sondaTemp->cRocha.pPrimeiro->pProx;
        ApontadorRocha rochaMaisPesada = NULL;
        float maiorPeso = 0;

        while (pAux != NULL)
        {
            if (strcmp(pAux->rocha.categoria, rocha->categoria) == 0 && pAux->rocha.peso > maiorPeso)
            {
                maiorPeso = pAux->rocha.peso;
                rochaMaisPesada = pAux;
            }
            pAux = pAux->pProx;
        }

        if (rochaMaisPesada != NULL && rochaMaisPesada->rocha.peso > rocha->peso)
        {
            rochaMaisPesada->rocha = *rocha; // Substitui a rocha mais pesada
            printf("Rocha coletada pela sonda %d (troca por rocha mais pesada).\n", sondaTemp->id);
            return; // Sai da função após a troca bem-sucedida
        }
        else
        {
            printf("Impossivel coletar ou trocar rochas. Rocha descartada.\n");
            return; // Sai da função se a troca não for possível
        }
    }
    else
    {
        // Caso 2: Capacidade suficiente, insere a rocha normalmente
        sondaTemp->latitude = rocha->latitude;
        sondaTemp->longitude = rocha->longitude;
        if (LInsere(&sondaTemp->cRocha, rocha))
        {
            printf("\nRocha coletada pela sonda: %d\n", sondaTemp->id);
        }
        else
        {
            printf("\nErro ao inserir rocha na sonda %d.\n", sondaTemp->id);
        }
    }
}

void MoveOrigem(SLista *ListaS) {
    ApontadorSonda pAux = NULL;
    pAux = ListaS->pPrimeiro;
    while (pAux != NULL)
    {

        pAux->sonda.latitude = 0.0;
        pAux->sonda.longitude = 0.0;
        pAux = pAux->pProx;
    }
}

RochaMineral *copiaRocha(RochaMineral *rocha) {
    RochaMineral *copia = (RochaMineral *)malloc(sizeof(RochaMineral));
    if (copia == NULL) {
        perror("Erro ao alocar memória para cópia da rocha");
        return NULL;
    }
    *copia = *rocha; // Copia os membros da estrutura
    // Cria uma cópia da lista de minerais (cópia profunda)
    FLVaziaMine(&copia->LMinerais);
    for (int i = rocha->LMinerais.first; i < rocha->LMinerais.last; i++) {
        LInsereMine(&copia->LMinerais, rocha->LMinerais.ListaM[i]);
    }

    return copia;
}


// 2. Função para extrair todas as rochas das sondas e colocá-las em um array
RochaMineral *extraiRochas(SLista *ListaS, int *numRochas) {
    *numRochas = 0;
    ApontadorSonda pAuxSonda = ListaS->pPrimeiro->pProx;

    // Conta o número total de rochas
    while (pAuxSonda != NULL) {
        ApontadorRocha pAuxRocha = pAuxSonda->sonda.cRocha.pPrimeiro->pProx;
        while (pAuxRocha != NULL) {
            (*numRochas)++;
            pAuxRocha = pAuxRocha->pProx;
        }
        pAuxSonda = pAuxSonda->pProx;
    }

    if (*numRochas == 0) {
        return NULL; // Nenhuma rocha para extrair
    }


    RochaMineral *rochas = (RochaMineral *)malloc(*numRochas * sizeof(RochaMineral));
    if (rochas == NULL) {
        perror("Erro ao alocar memória para rochas");
        return NULL;
    }

    int indiceRocha = 0;
    pAuxSonda = ListaS->pPrimeiro->pProx;
    while (pAuxSonda != NULL) {
        ApontadorRocha pAuxRocha = pAuxSonda->sonda.cRocha.pPrimeiro->pProx;
        while (pAuxRocha != NULL) {

            rochas[indiceRocha] = *copiaRocha(&pAuxRocha->rocha); //copia a rocha para o array

            ApontadorRocha temp = pAuxRocha;
            pAuxRocha = pAuxRocha->pProx;
            free(temp);
            indiceRocha++;

        }

        FLVazia(&pAuxSonda->sonda.cRocha); //limpa a lista rocha

        pAuxSonda = pAuxSonda->pProx;
    }

    return rochas;

}

// 3. Função de comparação para qsort (ordena por peso decrescente)
int comparaRochas(const void *a, const void *b) {
    RochaMineral *rocha1 = (RochaMineral *)a;
    RochaMineral *rocha2 = (RochaMineral *)b;
    return (rocha2->peso > rocha1->peso) - (rocha2->peso < rocha1->peso); // Ordena decrescente
}

// 4. Função para distribuir as rochas entre as sondas
void distribuirRochas(SLista *ListaS, RochaMineral *rochas, int numRochas) {
    if (rochas == NULL || numRochas == 0) {
        return; // Nada para distribuir
    }

    qsort(rochas, numRochas, sizeof(RochaMineral), comparaRochas); // Ordena as rochas

    int numSondas = 0;
    ApontadorSonda pAux = ListaS->pPrimeiro->pProx;
    while (pAux != NULL) {
        numSondas++;
        pAux = pAux->pProx;
    }

    float *pesosSondas = (float *)calloc(numSondas, sizeof(float)); // Inicializa com zero
    if (pesosSondas == NULL) {
        perror("Erro ao alocar memória para pesos das sondas");
        return;
    }

    for (int i = 0; i < numRochas; i++) {
        int sondaEscolhida = -1;

        // Tenta inserir a rocha em cada sonda, da menos para a mais pesada
        for (int j = 0; j < numSondas; j++) {

            // Encontra a próxima sonda com menor peso (considerando capacidade)
            int indiceMenorPeso = -1;
            float menorPeso = -1;
            pAux = ListaS->pPrimeiro->pProx;
            for (int k = 0; k < numSondas; k++) {

                if ((indiceMenorPeso == -1 || pesosSondas[k] < menorPeso) && pAux->sonda.capacidade >= pesosSondas[k] + rochas[i].peso) {

                    indiceMenorPeso = k;
                    menorPeso = pesosSondas[k];

                }
                pAux = pAux->pProx;


            }

            if (indiceMenorPeso != -1) {

                sondaEscolhida = indiceMenorPeso;
                pAux = ListaS->pPrimeiro->pProx;
                for (int k = 0; k < sondaEscolhida; k++) {
                    pAux = pAux->pProx;
                }


                if (!LInsere(&pAux->sonda.cRocha, &rochas[i])) {
                    printf("Erro ao inserir rocha na lista\n");
                    // Trate o erro de inserção conforme necessário
                }
                pesosSondas[sondaEscolhida] += rochas[i].peso;


                break; // Sai do loop interno após inserir a rocha
            }
        }

        // Se não conseguiu inserir em nenhuma sonda, descarta a rocha
        if (sondaEscolhida == -1) {
            printf("A rocha %d foi descartada (sem capacidade nas sondas).\n", rochas[i].id);
        }

    }

    // Imprime o peso de cada sonda após a distribuição (para verificar)
    pAux = ListaS->pPrimeiro->pProx;
    while (pAux != NULL) {
        printf("Peso da sonda %d: %.2f\n", pAux->sonda.id, LPeso(&pAux->sonda));
        pAux = pAux->pProx;
    }

    free(pesosSondas);
}

void OperacaoE(SLista *ListaS) {
    int numRochas = 0;
    RochaMineral *rochas = extraiRochas(ListaS, &numRochas);

    if (rochas != NULL) {
        distribuirRochas(ListaS, rochas, numRochas);
        free(rochas); // Libera a memória alocada para as rochas
    } else {
        printf("Nenhuma rocha para redistribuir.\n");
    }

    // Move todas as sondas para a origem (0,0)
    MoveOrigem(ListaS);
}