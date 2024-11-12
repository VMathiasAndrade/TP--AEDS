#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RochaM.h"

void InicializaRocha(RochaMineral* rocha, int id, float peso, char* categoria, char* dataColeta, double latitude, double longitude){
    setIdentificador(rocha, id);
    setPeso(rocha, peso);
    setCategoria(rocha, categoria);
    setDataColeta(rocha, dataColeta);
    setLocalizacao(rocha, latitude, longitude);    
}

char* DefCategoria(RochaMineral* rocha){
    int i;
    int qtdMinerais = rocha->LMinerais.last - rocha->LMinerais.first;

    if(qtdMinerais == 0){
        strcpy(rocha->categoria, "Sem Minerais");
        return rocha->categoria;
    }

    int temFerrolita = 0;
    int temSolarium = 0;
    int temAquavitae = 0;
    int temTerranita = 0;
    int temCalaris = 0;

    for(i = rocha->LMinerais.first; i < rocha->LMinerais.last; i++){
       if(strcmp(rocha->LMinerais.ListaM[i].nome, "Ferrolita") == 0) {temFerrolita = 1;}
       else if(strcmp(rocha->LMinerais.ListaM[i].nome, "Solarium") == 0) {temSolarium = 1;}
       else if(strcmp(rocha->LMinerais.ListaM[i].nome, "Aquavitae") == 0) {temAquavitae = 1;}
       else if(strcmp(rocha->LMinerais.ListaM[i].nome, "Terranita") == 0) {temTerranita = 1;}
       else if(strcmp(rocha->LMinerais.ListaM[i].nome, "Calaris") == 0) {temCalaris = 1;}

       if(temFerrolita && qtdMinerais == 1) {strcpy(rocha->categoria, "Ferrom");}
       else if(temSolarium && qtdMinerais == 1) {strcpy(rocha->categoria, "Solaris");}
       else if(temFerrolita && temAquavitae && qtdMinerais == 2) {strcpy(rocha->categoria, "Aquaferro");}
       else if(temCalaris && temTerranita && qtdMinerais == 2) {strcpy(rocha->categoria, "Terrolis");}
       else if(temFerrolita && temSolarium && qtdMinerais == 2) {strcpy(rocha->categoria, "Terrasol");}
       else if(temAquavitae && temTerranita && qtdMinerais == 2) {strcpy(rocha->categoria, "Aquaterra");}
       else if(temCalaris && temAquavitae && qtdMinerais == 2) {strcpy(rocha->categoria, "Calquer");}
       else if(temSolarium && temFerrolita && qtdMinerais == 2) {strcpy(rocha->categoria, "Solarisfer");}
       else if(temTerranita && temFerrolita && qtdMinerais == 2) {strcpy(rocha->categoria, "Terralis");}
       else if(temAquavitae && temCalaris && temFerrolita && qtdMinerais == 3) {strcpy(rocha->categoria, "Aquacalis");}
    }
}

void setIdentificador(RochaMineral* rocha, int id){
    rocha->id = id;
}
void setPeso(RochaMineral* rocha, float peso){
    rocha->peso = peso;
}
void setCategoria(RochaMineral* rocha, char* categoria){
    strcpy(rocha->categoria, categoria);
}
void setDataColeta(RochaMineral* rocha, char* dataColeta){
    strcpy(rocha->dataColeta, dataColeta);
}
void setLocalizacao(RochaMineral* rocha, double latitude, double longitude){
    rocha->latitude = latitude;
    rocha->longitude = longitude;
}

int getIdentificador(RochaMineral* rocha) { return rocha->id; }
float getPeso(RochaMineral* rocha) { return rocha->peso; }
char* getCategoria(RochaMineral* rocha) { return rocha->categoria; }
char* getDataColeta(RochaMineral* rocha) { return rocha->dataColeta; }
double getLatitude(RochaMineral* rocha) { return rocha->latitude; }
double getLongitude(RochaMineral* rocha) { return rocha->longitude; }