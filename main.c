#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Compartimento.h"


int main()
{
    int N_Sondas, Escolha = 0;
    double lat_i, long_i;
    float c_i, v_i, nc_i;
    char linha[255];
    RochaMineral rocha;
    Mineral minel;
    
        printf("Nome do arquivo de entrada: ");

        char nomearq[33];

        FILE *arq;
        scanf("%32s", nomearq);
        arq = fopen(nomearq, "r");

        fscanf(arq, "%d", &N_Sondas);

        
        
        int N_op;
        fscanf(arq, "%d", &N_op);
        
        for (int i = 0; i < N_op; i++) {
            fflush(stdout);
  
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


                    break;
                
               
        }
        fclose(arq);
    
    
    printf("-----------------------------------------------------------------------------\n");
    printf("Trabalho feito por Bruno Vicentini, Pedro Paulo Paz e Vitor Mathias\n");
    printf("-----------------------------------------------------------------------------");

    return 0;
}