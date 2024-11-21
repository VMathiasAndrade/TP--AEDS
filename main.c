#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"
#include <math.h>

void OperacaoI(SLista *ListaSonda) {
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

int main()
{
    int N_Sondas, Escolha = 0;
    double lat_i, long_i;
    float c_i, v_i, nc_i;
    char linha[255];
    SLista ListaSonda;
    RochaMineral rocha;
    Mineral minel;
    Sonda sondai;
    
    while (Escolha != 1 && Escolha != 2) {
        printf("Arquivo de entrada (1 - Terminal, 2 - Arquivo): \n");
        scanf("%d", &Escolha);
    }

    if (Escolha == 1) {

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
            switch (operacao) {
                case 'R': {
                    double lat_r, long_r;
                    float p_r;
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

                    InicializaRocha(&rocha, ++cont, p_r, DefCategoria(&rocha), "", lat_r, long_r);

                    InsereRochaS(&ListaSonda, &rocha);

                    break;
                }
                case 'I': {

                    OperacaoI(&ListaSonda);

                    break;
                }
                case 'E': {
                    
                    OperacaoE(&ListaSonda);

                    break;
                    
                }
            }
        }
    }
    else if (Escolha == 2) {

        printf("Nome do arquivo de entrada: ");

        char nomearq[33];
        int N_Sondas;

        FILE *arq;
        scanf("%32s", nomearq);
        arq = fopen(nomearq, "r");

        fscanf(arq, "%d", &N_Sondas);

        FLVaziaSonda(&ListaSonda);

        for (int i = 0; i < N_Sondas; i++) {
            fscanf(arq, "%lf %lf %f %f %f", &lat_i, &long_i, &c_i, &v_i, &nc_i);
            InicializaSonda(&sondai, (i+1), lat_i, long_i, c_i, "Sim");
            LInsereSonda(&ListaSonda, &sondai);
        }
        fflush(stdout);
        
        int N_op;
        fscanf(arq, "%d", &N_op);
        
        for (int i = 0; i < N_op; i++) {
            char opcao;
            fflush(stdout);
            fscanf(arq, " %c", &opcao);
            
            switch (opcao) {
                case 'R':{
                    int c;
                    while ((c = fgetc(arq)) != '\n' && c != EOF);

                    FLVaziaMine(&rocha.LMinerais);
                    double lat_r, long_r;
                    float p_r;
                    
                    fgets(linha, sizeof(linha), arq);
                    linha[strcspn(linha, "\n")] = '\0';

                    char *buffer = strtok(linha, " ");

                    lat_r = atof(buffer);
                    buffer = strtok(NULL, " ");
                    long_r = atof(buffer);
                    buffer = strtok(NULL, " ");
                    p_r = atof(buffer);
                    buffer = strtok(NULL, " ");

                    while (buffer != NULL) {
                        Mineral mineral;
                        buffer[strcspn(buffer, "\n")] = '\0';
                        RetornaMineral(&mineral, buffer);
                        LInsereMine(&rocha.LMinerais, mineral);
                        buffer = strtok(NULL, " ");
                    }
                    
                    int cont = 0;

                    InicializaRocha(&rocha, ++cont, p_r, DefCategoria(&rocha), "", lat_r, long_r);

                    InsereRochaS(&ListaSonda, &rocha);

                    break;
                }
                case 'I':{
                    
                    OperacaoI(&ListaSonda);
                    
                    break;
                }
                case 'E': {
                    
                    OperacaoE(&ListaSonda);

                    break;
                }
                default:
                    break;
            }
        }
        fclose(arq);
    }
    
    printf("-----------------------------------------------------------------------------\n");
    printf("Trabalho feito por Bruno Vicentini, Pedro Paulo Paz e Vitor Mathias\n");
    printf("-----------------------------------------------------------------------------");

    return 0;
}