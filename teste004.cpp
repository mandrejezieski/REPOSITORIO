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


int main(){
    int Valor;
    Fila_Construtor();

    Fila_Enfileirar(5);
    Fila_Enfileirar(2);
    Fila_Enfileirar(7);
    Fila_Enfileirar(5);
    Fila_Enfileirar(2);
    Fila_Enfileirar(7);

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
