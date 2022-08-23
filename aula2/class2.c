#include <stdio.h>
#include <malloc.h>
#define alturaMaxia 225

typedef struct{
    int peso;   //peso em quilogramas
    int altura; //altura em centimetros
} PesoAltura;

int main(){
    PesoAltura* pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));
    pessoa1->peso = 80;
    pessoa1->altura = 185;
    printf("Peso: %i, Altura: %i.\n", pessoa1->peso, pessoa1->altura);
    if (pessoa1->altura>alturaMaxia) printf("Altura acima da maxima.\n");
    else printf("Altura abaixo da maxima.\n");
    return 0;
}