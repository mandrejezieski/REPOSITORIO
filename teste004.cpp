	#include <stdio.h>
	#include <stdlib.h>
	int topo, i ;
	int op;
	
	
	struct cadastro{
		int idade, x;
		char nome[30];
		char cpf[11];
	};
	struct cadastro FILA[10];
	
	void exibir(void){
		//cadastro FILA;
	    if (topo == 0 )
	    {
	      printf("A pilha esta vazia\n");
	    }
	    else
	    {
	    //for(int i=0; i<10; i++)
	    {
	      printf("Na posicao %d temos %s %s %s\n",i, FILA[i].nome, FILA[i].cpf, FILA[i].idade);
	     }
	     }
	     system("PAUSE");
	}
	
	
	void inserir(void){
	    if (topo == 10){
	          printf("A pilha esta cheia, OverFlow\n");
	      }
	      else {
	      	    //for(int i=0; i<10; i++){
				  
	           printf("Digite o nome: \n");
	           fflush(stdin);
	           gets(FILA[i].nome);
	           printf("Digite o cpf: \n");
	           fflush(stdin);
	           gets(FILA[i].cpf);
	           printf("Digite a idadde: \n");
	           fflush(stdin);
	           scanf("%d", &FILA[i].idade);          
	          
			   topo++;
	       }
	         exibir();
	
	       
	           
	           //void remover(struct cadastro *algumacoisa, int *i,int *x);
	       
	    }
	   
	    if (topo==0){
	           printf("A pilha esta vazia\n");     
	                }
	    else {
		printf("Elemento %s removido\n",FILA[0].nome);
	         for (int i=0;i<=10;i++){
	             FILA[i].nome = x[i+1];
	             }                 
	         }    
	    topo--;     
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
	        //case 2 : remover(FILA[i].nome);
	          //   break;
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
