#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"
#include <math.h>

int main() {
    int Escolha = 0;
    while(Escolha != 1 || Escolha != 2){
        printf("Arquivo de entrada (1 - Terminal, 2 - Arquivo): \n");
        scanf("%d", &Escolha);
    }

    if (Escolha == 1)
    {
        int N_Sondas;
        double lat_i, long_i;
        float c_i, v_i, nc_i;
        printf("Digite o numero de sondas");
        scanf("%d", &N_Sondas);
        for(int i = 0; i <= N_Sondas; i++){
            printf("Digite os dados das sondas: (latitude, longitude, capacidade maxima, velocidade e combustivel)\n");
            scanf("%lf %lf %f %f %f", &lat_i, &long_i, &c_i, &v_i, &nc_i);
        }

        int N_op;
        printf("Digite o numero de operações: \n")
        scanf("%d", &N_op);
        for(int i = 0; i <= N_op; i++){
            char operacao;
            printf("Digite a operação: \n");
            scanf("%c", &operacao);

            switch (operacao) {
            case 'R':{

                double lat_r, long_r;
                float p_r;
                ListaMinerais minerais[3];
                char linha[255];

                fgets(linha, sizeof(linha), stdin);

                if ((fgets(linha, sizeof(linha), stdin)) != NULL)
                {
                    linha[strcspn(linha, "\n")] = '\0';

                    char *token = strtok(linha, " ");
                    sscanf(token, "%lf", &lat_r);
                    token = strtok(NULL, " ");
                    sscanf(token, "%lf", &long_r);
                    token = strtok(NULL, " ");
                    sscanf(token, "%f", &p_r);
                    token = strtok(NULL, " ");
                    
                    int i = 0;
                    while (token != NULL)
                    {
                        strcpy(minerais[i].ListaM->nome, token);
                        i++;
                        strtok(NULL, " ");
                    }
                }

                RochaMineral novaRocha;
                novaRocha.latitude = lat_r;
                novaRocha.longitude = long_r;
                novaRocha.peso = p_r;
                
                novaRocha.LMinerais = (ListaMinerais *) malloc(3 * sizeof(ListaMinerais));
                
                for(int j = 0; j < 3; j++){
                    novaRocha.LMinerais[j].ListaM = (Mineral *)malloc(sizeof(Mineral));
                    if (novaRocha.LMinerais[j].ListaM == NULL) {
                        perror("Erro ao alocar memória para ListaM");
                        exit(EXIT_FAILURE);
                    }

                    strcpy(novaRocha.LMinerais[j].ListaM->nome, minerais[j].ListaM->nome);

                }   

                printf("Categoria: %s\n", DefCategoria(&novaRocha));

            // Liberar a memória alocada para LMinerais (importante!)
                for (int j = 0; j < 3; j++) {
                    free(&novaRocha.LMinerais[j].ListaM);
                    }
                    free(&novaRocha.LMinerais);

                break;
            }
            case 'I':
            
                    

                break;
            case 'E':
                
                break;
            default:
                break;
            }
        }
    }
    
    return 0;
}

void LeituraTerminal(){
    
}