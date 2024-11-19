#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"
#include <math.h>

void OperacaoI(SLista *ListaSonda) {
    ApontadorSonda pAux = ListaSonda->pPrimeiro->pProx;

    while (pAux != NULL) {
        Sonda *pSonda = &pAux->sonda;
        printf("%d\n", pSonda->id);

        if (LEhVazia(&pSonda->cRocha)){
            printf("Compartimento vazio!\n");
            /* Se o compartimento estiver vazio, imprime o id da sonda e
            'compartimento vazio!' */
        } else {
            ApontadorRocha rAux = pSonda->cRocha.pPrimeiro->pProx;
            
            while (rAux != NULL) {
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
        SLista *ListaSonda;

        printf("Digite o numero de sondas: ");
        scanf("%d", &N_Sondas);
        printf("Digite os dados das sondas: (latitude, longitude, capacidade maxima, velocidade e combustivel)\n");
        for (int i = 0; i < N_Sondas; i++)
        {
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

                printf("Digite a latitude, longitude, peso, categoria e ate 3 minerais (SEPARE POR ESPACO):\n");
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
                Mineral mineral1;
                Mineral mineral2;
                Mineral mineral3;
                Mineral mineral4;

                RetornaMineral(&mineral1, "Ferrolita");
                RetornaMineral(&mineral2, "Terranita");
                RetornaMineral(&mineral3, "Calaris");
                RetornaMineral(&mineral4, "Solarium");
                
                RochaMineral rocha1;
                RochaMineral rocha2;
                RochaMineral rocha3;

                FLVaziaMine(&rocha1.LMinerais);
                FLVaziaMine(&rocha2.LMinerais);
                FLVaziaMine(&rocha3.LMinerais);

                LInsereMine(&rocha1.LMinerais, mineral1);
                LInsereMine(&rocha1.LMinerais, mineral2);
                // Ferrolita e Terranita

                LInsereMine(&rocha2.LMinerais, mineral1);
                LInsereMine(&rocha2.LMinerais, mineral4);
                // Ferrolita e Solarium

                LInsereMine(&rocha3.LMinerais, mineral3);
                LInsereMine(&rocha3.LMinerais, mineral2);
                // Calaris e Terranita

                InicializaRocha(&rocha1, 1, 18, DefCategoria(&rocha1), "12/12/2024", 55.489421, -150.457196);
                InicializaRocha(&rocha2, 2, 21, DefCategoria(&rocha2), "04/12/2024", 16.718537, -148.127484);
                InicializaRocha(&rocha3, 3, 19, DefCategoria(&rocha3), "08/09/2024", 28.452065, 84.537518);

                Sonda sonda1;
                Sonda sonda2;
                Sonda sonda3;

                InicializaSonda(&sonda1, 1, -39.341947, 142.872653, "Sim");
                InicializaSonda(&sonda2, 2, -39.341947, 142.872653, "Sim");
                InicializaSonda(&sonda3, 3, -39.341947, 142.872653, "Sim");
                
                LInsere(&sonda1.cRocha, &rocha1);
                LInsere(&sonda1.cRocha, &rocha3);

                LInsere(&sonda2.cRocha, &rocha2);
                LInsere(&sonda2.cRocha, &rocha1);
                
                FLVaziaSonda(ListaSonda);

                LInsereSonda(ListaSonda, &sonda1);
                LInsereSonda(ListaSonda, &sonda2);
                LInsereSonda(ListaSonda, &sonda3);

                OperacaoI(ListaSonda);

                break; 
            }
        }
    }
    }
    return 0;
}