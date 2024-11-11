#include <stdio.h>
#include <string.h>
#include "Mineral.h"

void InicializaMineral(Mineral* mineral, char *nome, char *cor, double dureza, double reativ) {
    setNome(mineral, nome);
    setCor(mineral, cor);
    setDureza(mineral, reativ);
    setReatividade(mineral, dureza);
}
Mineral RetornaMineral(Mineral* mineral, char* nome){
    int x= 1;
    while (x=1){//while foi feito para se caso o usuario digitar o nome de uma pedra inexistente, ele poder digitar novamente a pedra desejada.
        if (strcmp(nome, "Ferrolita") == 0) {
            strcpy(mineral->cor, "Acinzentado");//ATENÇÃO: CASO DÊ ALGUM ERRO, VERIFICAR SE REALMENTE DEVE USAR (*MINERAL) AO INVES DE MINERAL.
            mineral->dureza = 0.5;
            mineral->reativ = 0.7;  
            x=0;
        }
        else if (strcmp(nome, "Solarium") == 0) {
            strcpy(mineral->cor,"Amarelo");
            mineral->dureza = 0.9;
            mineral->reativ = 0.2;
            x=0;
        }
        else if (strcmp(nome, "Aquavitae") == 0) {
            strcpy(mineral->cor,"Azulado");
            mineral->dureza = 0.5;
            mineral->reativ = 0.8;
            x=0;
        }
        else if (strcmp(nome, "Terranita") == 0) {
            strcpy(mineral->cor,"Marrom");
            mineral->dureza = 0.7;
            mineral->reativ = 0.6;
            x=0;
        }
        else if(strcmp(nome, "Calaris") == 0) {
            strcpy(mineral->cor, "Vermelho");
            mineral->dureza = 0.6;
            mineral->reativ = 0.5;
            x=0;
        }
        else{
            printf("Pedra inválida, digite novamente.");
            
        }
    }    
}

void setNome(Mineral* mineral, char* nome){
    strcpy(mineral->nome, nome);
}
void setCor(Mineral* mineral, char* cor){
    strcpy(mineral->cor, cor);
}
void setDureza(Mineral* mineral, double dureza){
    mineral->dureza = dureza;
}
void setReatividade(Mineral* mineral, double reativ){
    mineral->reativ = reativ;
}

char* getNome(Mineral* mineral){
    return mineral->nome;
}
char* getCor(Mineral* mineral){
    return mineral->cor;
}
double getDureza(Mineral* mineral) {
    return mineral->dureza;
}
double getReatividade(Mineral* mineral) {
    return mineral->reativ;
}