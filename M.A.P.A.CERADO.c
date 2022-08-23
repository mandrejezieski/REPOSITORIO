#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#define N 5

int aux; // variavel auxiliar.

typedef struct Pilha{ // Criando as pilhas.
	int dados[N];
	int topo;
} Pilha;

// inicializando a pilha.
void inicializa_Pilha (Pilha *p){
	int i;
	for(i=0; i< N  ; i++){
		p->dados[i] = 0;
	}
	p -> topo = 0;
}

// método para empilhar a pilha.
void empilhar(int dados, Pilha *p){
	if(p->topo == N){
		printf("Pilha cheia.\n"); // caso a pilha já esteja cheia.
	} else {
		p->dados[p->topo] = dados; // caso a pilha esteja disponível o topo receberá o dado.
		p->topo++; // o topo será incrementado.
		return;
	}
}

void empilhar02(int dados, Pilha *p){ // método que usei para colocar os dados de um vetor para o outro
	if(p->topo == N){
		printf("Pilha cheia.\n"); // caso a pilha já esteja cheia.
	} else {
		p->dados[p->topo] = aux; // caso a pilha esteja disponível o topo receberá o dado da variavel auxiliar.
		p->topo++; // o topo será incrementado.
		return;
	}
}

int desempilha(Pilha *p){ // método para desempilha a pilha.
	if(p->topo == 0){
		printf("Pilha vazia.\n"); // caso a pilha esteja vazia.
		return;
	} else {
		p->topo--;
		aux= p->dados[p->topo]; // envia o dado desempilhado para a variavel auxiliar, caso seja necessário o uso do dado.
		
	}
}

void imprimePilha(Pilha *p){  // imprime o valor da pilha.
	int i; // variavel de controle.
	for(i=0; i<p->topo; i++){
		printf("%d", p->dados[i]); // impressão do dado em uma dada posição do vetor.
	}
	printf("\n");
}


  
int main(){
	
	setlocale(LC_ALL, "Portuguese"); // sem erros de acentuação.
	
	Pilha p1; 
	Pilha p2;
	
	// Código para empilhar a pilha p1.
	inicializa_Pilha(&p1);
	printf("Iniciando a pilha p1: \n\n\n");
	system("pause");
	system("cls");
	empilhar(1, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause"); 
	system("cls");
	empilhar(2, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	empilhar(3, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	empilhar(4, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	empilhar(5, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	printf("Pilha p1: ");
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	
	//Código para desempilhar pilha p1 e empilhar pilha p2.
	printf("Desempilhando da pilha p1 e colocando na pilha p2: \n\n\n");
	system("pause");
	system("cls");
	desempilha(&p1);
	empilhar02(aux, &p2);
	imprimePilha(&p2);
	printf("\n\n");
	system("pause");
	system("cls");
	desempilha(&p1);
	empilhar02(aux, &p2);
	imprimePilha(&p2);
	printf("\n\n");
	system("pause");
	system("cls");
	desempilha(&p1);
	empilhar02(aux, &p2);
	imprimePilha(&p2);
	printf("\n\n");
	system("pause");
	system("cls");
	desempilha(&p1);
	empilhar02(aux, &p2);
	imprimePilha(&p2);
	printf("\n\n");
	system("pause");
	system("cls");
	desempilha(&p1);
	empilhar02(aux, &p2);
	imprimePilha(&p2);
	printf("\n\n");
	system("pause");
	system("cls");
	printf("Pilha p2: ");
	imprimePilha(&p2);
	printf("\n\n");
	system("pause");
	system("cls");
	
	
	//Código para provar que o código realmente funciona. Prova real.
	printf("Desempilhando da pilha p2 e recolocando na pilha p1: \n\n\n");
	system("pause");
	system("cls");
	desempilha(&p2);
	empilhar02(aux, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	desempilha(&p2);
	empilhar02(aux, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	desempilha(&p2);
	empilhar02(aux, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	desempilha(&p2);
	empilhar02(aux, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	desempilha(&p2);
	empilhar02(aux, &p1);
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	system("cls");
	printf("Pilha p1: ");
	imprimePilha(&p1);
	printf("\n\n");
	system("pause");
	
	
	printf("Exercício completo.\n");
	printf("Tenha um bom dia!!!\n\n");
	printf("MANÉ....");
	
//	system("cls");
	
}
