#include <stdio.h>
#include <stdlib.h>

int const MAXTAM=5;

int Frente, Tras;
int Fila[MAXTAM];

void Fila_Construtor(){
    Frente=0;
    Tras=-1;
}

bool Fila_Vazia(){
    if(Frente>Tras){
        return true;
    }else{
        return false;
    }

    //return Frente>Tras;
}

bool Fila_Cheia(){
    if(Tras==MAXTAM-1){
        return true;
        printf("Fila cheia.001");
    }else{
        return false;
    }
}

bool Fila_Enfileirar(int valor){
    if(Fila_Cheia()){
        return false;
    }else{
        Tras++;
        Fila[Tras]=valor;
        return true;
    }
}

bool Fila_Desenfileirar(int &valor){
    if(Fila_Vazia()){
        return false;
    }else{
        valor=Fila[Frente];
        Frente++;
        return true;
    }
}

bool Fila_Get(int &valor){
    if(Fila_Vazia()){
        return false;
    }else{
        valor=Fila[Frente];
        return true;
    }
}

int Fila_Tamanho(){
    return (Tras - Frente)+1;
}

typedef struct NO{
	char nomeLivro[20];
    char nomeAutor[30];
    int codigo;
    float preco;
    struct NO *prox;
 }NO;

int main(){
    int Valor;
    Fila_Construtor();


    printf("\nTamanho:%d\n",Fila_Tamanho());
    
    printf("\nValor unserido: %d\n\n",&Fila_Enfileirar[1]);


    if( Fila_Desenfileirar(Valor) ){
        printf("\nValor deletado: %d\n\n",Valor);
    }else{
    	printf("Fila vazia.\n");
	}

    system("pause");
    return 0;
}
