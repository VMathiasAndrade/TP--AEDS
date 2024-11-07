#include <stdio.h>
#include "MINERAL.h"

RetornaMin(char *nome) {
    
}
void InicializaMineral (char *nome, char *cor, double reatividade, double dureza) {

    setCor (Mineral, cor);
    setDureza (Mineral, dureza);
    setNome (Mineral, nome);
    setReatividade (Mineral, reatividade);
}

double getDureza (Mineral *mineral) {
    return mineral -> dureza
}

double getReatividade (Mineral *mineral) {
    return 
}