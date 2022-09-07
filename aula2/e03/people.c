#include <stdio.h>
#include <malloc.h>

typedef struct aux
{
    int cpf;
    int idade;
    struct aux* conjuge;
} PESSOA;

void imprimirCPFs(PESSOA p){
    if (p.conjuge != NULL){
        printf("CPFs: %i x %i\n", p.cpf, p.conjuge->cpf);
    } else{
        printf("CPF: %i - SOLTEIRO(A)", p.cpf);
    }
}

void envelhecer1(PESSOA p){
    /* 
    Recebe apenas uma copia do objeto tipo pessoa, ou seja, 
    ao final da chamada da função a memória é apagada e não
    altera de fato a idade pessoa passada como parametro.
    */
    p.idade++;
}

void envelhecer2(PESSOA* p){
    /* 
    Recebe o endereço de memória do objeto tipo pessoa, ou seja, 
    é possivel alterar de fato o valor do campo idade, acessando 
    através do ponteiro.
    */
    p->idade++;
}

void envelhecer3(PESSOA p){
    /* 
    Recebe como variável uma cópia do valor de todos os campos
    da pessoa p, e como o campo conjuge é de uma struct é acessado 
    por p.conjuge. Em seguida o campo conjuge fornece um endereço 
    de memória, é necessário acessar por p.conjuge->idade++
    */
    p.conjuge->idade++;
}

void envelhecer4(PESSOA* p){
    /* 
    Recebe um ponteiro pra PESSOA como parametro, e acessa o campo 
    conjuge que contém o endereço de memória de outro objeto do 
    tipo PESSOA.Em seguida altera o campo idade da forma padrão para 
    ponteiros e por fim libera a memória da cópia feita pela função, 
    deixando apenas as alterações feitas na idade do conjuge da pessoa.
    */
    p->conjuge->idade++;
}

int main(){
    PESSOA pessoa1;
    PESSOA pessoa2;
    PESSOA solteira;

    pessoa1.cpf = 310000000;
    pessoa1.idade = 36;

    pessoa2.cpf = 290000000;
    pessoa1.idade = 35;

    pessoa1.conjuge = &pessoa2;
    pessoa2.conjuge = &pessoa1;

    solteira.cpf = 230000000;
    solteira.idade = 30;
    solteira.conjuge = NULL;

    imprimirCPFs(pessoa1);
    imprimirCPFs(solteira);

    envelhecer1(pessoa1);
    envelhecer2(&pessoa1);
    envelhecer3(pessoa1);
    envelhecer4(&pessoa1);
}
