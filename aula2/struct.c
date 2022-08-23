#include <stdio.h>
#define alturaMaxima 225

// typedef int CHAVE; => deixa mais claro qual a estrutura da variável

typedef struct{
    int peso;   // peso em quilogramas   
    int altura; // altura em centimetros
} PesoAltura;

int main(){
    PesoAltura pessoa1;
    pessoa1.peso = 80;
    pessoa1.altura = 185;

    printf("Peso: %i, Altura: %i\n", pessoa1.peso, pessoa1.altura);
    
    if (pessoa1.altura>alturaMaxima) printf("Altura acima da maxima.\n");
    else printf("Altura abaixo da maxima.\n");
    return 0;
}

