#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"
#include <math.h>

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
        printf("Digite o numero de sondas: ");
        scanf("%d", &N_Sondas);
        for (int i = 0; i < N_Sondas; i++)
        {
            printf("Digite os dados das sondas: (latitude, longitude, capacidade maxima, velocidade e combustivel)\n");
            scanf("%lf %lf %f %f %f", &lat_i, &long_i, &c_i, &v_i, &nc_i);
        }

        int N_op;
        printf("Digite o numero de operacoes: \n");
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
                double lat_i, long_i;
                float p_i;
                char cat_i[50];
                char minerais_str[255] = "";
                char linha[255];

                printf("Digite a latitude, longitude, peso, categoria e ate 3 minerais (SEPARE POR ESPACO): ");
                getchar();
                fgets(linha, sizeof(linha), stdin);
                char *buffer = strtok(linha, " ");
                if (buffer != NULL)
                    lat_i = atof(buffer);
                buffer = strtok(NULL, " ");
                if (buffer != NULL)
                    long_i = atof(buffer);
                buffer = strtok(NULL, " ");
                if (buffer != NULL)
                    p_i = atof(buffer);
                buffer = strtok(NULL, " ");
                if (buffer != NULL)
                    strcpy(cat_i, buffer);

                while ((buffer = strtok(NULL, " ")) != NULL)
                {
                    if (strlen(minerais_str) > 0)
                    {
                        strcat(minerais_str, ", ");
                    }
                    strcat(minerais_str, buffer);
                }

                printf("%.6lf %.6lf %.2f %s %s",lat_i, long_i, p_i, cat_i, minerais_str);
                break;
                
            }
            case 'I': {
                SLista *sLista;
                ImprimeLSonda(sLista);
                break; 
            }
        }
    }
    }
    return 0;
}
