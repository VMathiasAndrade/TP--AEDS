#include <stdio.h>
#include <string.h>
#include "Mineral.h"

void InicializaMineral(Mineral* mineral, char *nome, char *cor, double dureza, double reativ, char*propriedades) {
    setNome(mineral, nome);
    setCor(mineral, cor);
    setPropriedades(mineral, propriedades);
    setDureza(mineral, reativ);
    setReatividade(mineral, dureza);
    setPropriedades(mineral, propriedades);
}
//RetornaMineral vai pegar o nome digitado e ja mostrar a cor, dureza e reatividade
Mineral RetornaMineral(Mineral* mineral, char* nome, char*cor, char*propriedades, double reativ, double dureza){
    int x= 1;
    while (x=1){//while foi feito para se caso o usuario digitar o nome de uma pedra inexistente, ele poder digitar novamente a pedra desejada.
        if (strcmp(nome, "Ferrolita") == 0) {
            strcpy((*mineral).cor, "Acinzentado");//ATENÇÃO: CASO DÊ ALGUM ERRO, VERIFICAR SE REALMENTE DEVE USAR (*MINERAL) AO INVES DE MINERAL.
            (*mineral).dureza = 0.5;
            (*mineral).reativ = 0.7;
            strcpy((*mineral).propriedades, "magnetismo moderado");  
            x=0;
        }
        else if (strcmp(nome, "Solarium") == 0) {
            strcpy((*mineral).cor,"Amarelo");
            (*mineral).dureza = 0.9;
            (*mineral).reativ = 0.2;
            x=0;
        }
        else if (strcmp(nome, "Aquavitae") == 0) {
            strcpy((*mineral).cor,"Azulado");
            (*mineral).reativ = 0.8;
            strcpy((*mineral).propriedades, "composto hidrofílicos");        
            (*mineral).dureza = 0.5;
            (*mineral).reativ = 0.8;
            x=0;
        }
        else if (strcmp(nome, "Terranita") == 0) {
            cor, "marrom";
            (*mineral).dureza = 0.7;
            (*mineral).reativ = 0.6;
            strcpy((*mineral).propriedades, "silicio e nutrientes");strcpy((*mineral).cor,"Marrom"); 
            (*mineral).dureza = 0.7;
            (*mineral).reativ = 0.6;
            x=0;
        }
        else if(strcmp(nome, "Calaris") == 0) {
            strcpy((*mineral).cor, "vermelho");
            (*mineral).dureza = 0.6;
            (*mineral).reativ = 0.5;
            strcpy((*mineral).propriedades, "composto regulador de pH");strcpy((*mineral).cor,"Vermelho");
            (*mineral).dureza = 0.6;
            (*mineral).reativ = 0.5;
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

void setPropriedades(Mineral* mineral, char* propriedades){
    strcpy(mineral->propriedades, propriedades); 
}
char* getNome(Mineral* mineral){
    return mineral->nome;
}
char* getCor(Mineral* mineral){
    return mineral->cor;
}
char* getPropriedades(Mineral* mineral){
    return mineral -> propriedades;
}
double getDureza(Mineral* mineral) {
    return mineral->dureza;
}
double getReatividade(Mineral* mineral) {
    return mineral->reativ;
}
