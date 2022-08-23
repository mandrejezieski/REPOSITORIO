#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int dado[MAX];
int topo;
int op;
typedef struct NO{
	char nomeLivro[20];
    char nomeAutor[30];
    int codigo;
    float preco;
    struct NO *prox;
 }NO;

void exibir(void){
    if (topo == 0 )
    {
      printf("A pilha esta vazia\n");
    }
    else
    {
    for(int temp=0;topo-1 >= temp ;temp++)
    {
      printf("Na posicao %d temos %d\n",temp,dado[temp]);
     }
     }
     system("PAUSE");
}

void inserir(void){
    if (topo==MAX){
          printf("A pilha esta cheia, OverFlow\n");
      }
      else {
           printf("Digite o codigo do livro: \n");
           scanf("%d",&dado[topo]);
           topo++;
           } 
     exibir();
}

void remover(int x[]){
     
    if (topo==0){
           printf("A pilha esta vazia\n");     
                }
    else {printf("Elemento %d removido\n",dado[0]);
         for (int i=0;i<=topo-1;i++){
             dado[i] = x[i+1];
             }                 
         }    
    topo--;;      
    exibir();
}

int menu(){
    printf("-= Programa Fila em C =-\n\n");
    printf("   Para inserir digite      1\n");
    printf("   Para remover digite      2\n");
    printf("   Para exibir digite       3\n\n");
    printf("   Para sair                4\n");
    scanf("%d",&op);
    switch (op){
        case 1 : inserir(); 
             break;
        case 2 : remover(dado);
             break;
        case 3 : exibir();  
             break;
           }
    return 0;
}


int main(){
    topo=0;
    while (op!=4){
          system("cls");
          menu();
          } 
    return 0;          
}
   
