#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"
#include <math.h>

void OperacaoI(SLista *ListaSonda)
{
    ApontadorSonda pAux = ListaSonda->pPrimeiro->pProx;

    while (pAux != NULL)
    {
        Sonda *pSonda = &pAux->sonda;
        printf("%d\n", pSonda->id);

        if (LEhVazia(&pSonda->cRocha))
        {
            printf("Compartimento vazio!\n");
            /* Se o compartimento estiver vazio, imprime o id da sonda e
            'compartimento vazio!' */
        }
        else
        {
            ApontadorRocha rAux = pSonda->cRocha.pPrimeiro->pProx;

            while (rAux != NULL)
            {
                printf("%s %.2f\n", rAux->rocha.categoria, rAux->rocha.peso);
                rAux = rAux->pProx;
            }
        }
        pAux = pAux->pProx;
    }
}

void OperacaoE(SLista *sLista, int numSondas)
{
    // Passo 1: Mover todas as sondas para (0,0) Ok
    ApontadorSonda pAtual = sLista->pPrimeiro;
    while (pAtual != NULL)
    {
        pAtual->sonda.latitude = 0.0;
        pAtual->sonda.longitude = 0.0;
        pAtual = pAtual->pProx;
    }
    // Vai ser melhor criar uma função de redistribuir as rochas
    // Talvez seja melhor jogar todas as rochas em uma lista, verificar qual é o meio dessa lista e colocar as rochas da primeira metade nas sondas (sonda 1 fica com a mais pesada, a 2 com a segunda mais pesada, etc)
    // a partir da segunda metade, a sonda que ficou com a rocha mais leve da primeira metade vai receber a mais pesada da segunda metade, e por assim vai (sonda 3 fica com a terceira mais leve, sonda 2 com a segunda mais leve e a sonda 1 com a mais leve de todas)

    printf("Operacao E concluida. Todas as sondas movidas para (0,0) e pesos redistribuidos.\n");
}

int main()
{
    int Escolha = 0;
    while (Escolha != 1 && Escolha != 2)
    {
        printf("Arquivo de entrada (1 - Terminal, 2 - Arquivo): \n");
        scanf("%d", &Escolha);
    }

    if (Escolha == 1)
    {
        int N_Sondas;
        double lat_i, long_i;
        float c_i, v_i, nc_i;
        SLista ListaSonda;
        RochaMineral rocha;
        Mineral minel;
        Sonda sondai;

        FLVaziaSonda(&ListaSonda);

        printf("Digite o numero de sondas: ");
        scanf("%d", &N_Sondas);
        printf("Digite os dados das sondas: (latitude, longitude, capacidade maxima, velocidade e combustivel)\n");
        for (int i = 0; i < N_Sondas; i++)
        {
            scanf("%lf %lf %f %f %f", &lat_i, &long_i, &c_i, &v_i, &nc_i);
            InicializaSonda(&sondai, (i + 1), lat_i, long_i, c_i, "Sim");
            LInsereSonda(&ListaSonda, &sondai);
        }

        int N_op;
        printf("Digite o numero de operacoes: ");
        scanf("%d", &N_op);
        for (int i = 0; i < N_op; i++)
        {
            char operacao;
            printf("Digite a operacao: ");
            scanf(" %c", &operacao);
            switch (operacao)
            {
            case 'R':
            {
                double lat_r, long_r;
                float p_r;
                char cat_r[20];
                char minerais_str[100];

                printf("\nDigite a latitude, longitude, peso e ate 3 minerais (SEPARE POR ESPACO):\n");
                scanf("%lf %lf %f", &lat_r, &long_r, &p_r);
                getchar();
                fgets(minerais_str, sizeof(minerais_str), stdin);
                minerais_str[strcspn(minerais_str, "\n")] = '\0';

                const char delim[2] = " ";
                char *buffer = strtok(minerais_str, delim);

                FLVaziaMine(&rocha.LMinerais);

                while (buffer != NULL)
                {
                    RetornaMineral(&minel, buffer);
                    LInsereMine(&rocha.LMinerais, minel);
                    buffer = strtok(NULL, delim);
                }

                int cont = 0;

                RochaMineral nRocha = InicializaRocha(&rocha, ++cont, p_r, DefCategoria(&rocha), "10/10/2024", lat_r, long_r);

                InsereRochaS(&ListaSonda, &nRocha);

                break;
            }
            case 'I':
            {

                OperacaoI(&ListaSonda);

                break;
            }
            case 'E':
            {
                RCompartimento ListaNova;
                printf("comeco case e");
                ListaTemp(&ListaSonda, &ListaNova);
                printf("depois de listatemp");
                RedistribuiRocha(&ListaSonda, &ListaNova);
                break;
            }
            }
        }
    }
    printf("-----------------------------------------------------------------------------\n");
    printf("Trabalho feito por Bruno Vicentini, Pedro Paulo Paz e Vitor Mathias\n");
    printf("-----------------------------------------------------------------------------");

    return 0;
}