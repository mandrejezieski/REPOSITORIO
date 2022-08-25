#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tamanho 5

//CRIANDO A LIVRO
typedef struct NO{ 
	int cod;
	char nomeLivro[20];
    char nomeAutor[30];
    int codigoref;
    float preco;
    struct NO *prox;
 }NO;

//CRIANDO A FILA
typedef struct FILA{ 
    NO *ini;
    NO *fim;
    int tam;  
}FILA;

//PROTOTIPOS
struct NO;
void menu();
void inicializaFila(FILA *f);
void enfileira(char *nomeLivro, char *nomeAutor, int codigoref, int cod, float preco, FILA *f);
void desenfileira(FILA *f);
void imprimeFilaP(FILA *f);
void imprimeFila(FILA *f);
void limpaFila(FILA *f);
void somaFila(FILA *f);
float aux;


//INICIALIZANDO A FILA
void inicializaFila(FILA *f){
    
    f->ini = 0;
    f->fim = 0;
	f->tam =5;	
}


//METODO PADRÃO
int main(){
	
	setlocale(LC_ALL, "Portuguese");// PARA APARECER OS ACENTO
	float aux=0; //VARIAVEL PARA AUXILIAR, PRICIPALMENTE NA SOMA
    int sel=0; int codigoref=0; int cod =0; // VARIÁVEIS DE CONTROLA
    //INICIANDO AS VARIÁVEIS
    char nomeLivro[20];
    char nomeAutor[30];
    float preco=0;
    //ALOCANDO A FILA
    FILA *f1 = (FILA*) malloc(sizeof(FILA));
	f1->tam=5;
	f1->ini= NULL;
	f1->fim= NULL;
    if(f1 == NULL){//CONTROLE DE ERRO DE ALOCAÇÃO
        printf("\nErro de alocacao!");
        exit(-1);
    } else{    //INICIALIZANDO A FILA DE FATO
        inicializaFila(f1);
        
        while (sel != 5){// ESTRUTURA DE REPETIÇÃO PARA AS OPÇÕES
       		imprimeFilaP(f1); // IMPIRMINDO O NOME DOS LIVROS ANTES DO MENU
			
            menu();// MENU
            printf("\nOpcao: ");// EDTRUTURA PARA A ESCOLHA DA OPÇÃO
            scanf("%d", &sel);
            switch (sel){ // ESTRUTURA PARA POSSIBILITAR A EXCECUÇÃO DAS OPÇÕES
            case 1: // ENFILEIRAR
            	if(codigoref < f1->tam){ // DEFINIR QUE A FILA VAI TER 5 ESPAÇO
					 codigoref ++; // INCREMENTNDO A REFERÊNCIA
            		 cod++; // INSERIDO CÓDIGO AUTOMATICAMENTE PARA O USUÁRIO
            		 printf("\nCódigo do livro: %d",cod);
               		 printf("\nNome do livro: ");
               		 scanf("%s",nomeLivro);
               		 printf("\nNome do autor: ");
               		 scanf("%s",nomeAutor);
               		 printf("\nPreço do livro: ");
               		 scanf("%f",&preco);
               		 enfileira(nomeLivro, nomeAutor, codigoref, cod, preco, f1);
               		 break;
							
				}else{
					printf("\nFila Cheia.\n"); // IMPRIME SE A FILA ESTIVER CHEIA
					system("pause");
					system("cls");
					break;
				}
				
                break;

            case 2: //DESENFILEIRA
                desenfileira(f1);
                codigoref = codigoref-1;// DESENCREMENTANDO A REFERÊNCIA
                break;
                
            case 3: // LIMPANDO A FILA POR COMPLETA
                limpaFila(f1);
                codigoref = 0; //ZERANDO A REFERÊNCIA
                break;
                
            case 4: // IMPRIMINDO A FILA INTEIRA
                imprimeFila(f1);
                break;

			case 5:  // FINALIZANDO O PROGRAMA
				printf("\n ## ESPERO TER ME SAINDO BEM. ##)\n\n");
                printf("\nPrograma finalizado ;) \n");
                system("pause");
                exit(0);
                break;
				
				break;
				
            default: // PADRÃO 
                printf("\nOpção Inválida!");
                break;
            }
        }
    }
	
   	 return 0;
}	

// FUNÇÃO PARA O MENU
void menu(){
	printf("\n-----------------------------------\n");
	printf("\n             M.A.P.A. ");
	printf("\nAluno: Misael Andrejezieski");
	printf("\nR.A.: 2018609-5");
    printf("\n");
    printf("\n---- ---- ---- MENU ---- ---- ----");
    printf("\n\t1. Insere livro");
    printf("\n\t2. Deleta livro");
    printf("\n\t3. Esvaziar a Fila");
    printf("\n\t4. Imprime lista de livros");
    printf("\n\t5. Sair");
    printf("\n");
}


// INSTANCIANDO A FILA
void enfileira(char *nomeLivro, char *nomeAutor, int codigoref,int cod, float preco,  FILA *f){
	
    NO *ptr = (NO*) malloc (sizeof(NO));
    
	if(ptr == NULL){
        printf("\nErro de Alocação!\n");
    } else{
    	strcpy(ptr->nomeLivro, nomeLivro);
        strcpy(ptr->nomeAutor, nomeAutor);
        ptr->codigoref = codigoref;
        ptr->cod = cod;
        ptr->preco = preco;
        ptr->prox = NULL;
        
        aux = aux + preco;
           		 printf("\n soma %.2f\n",aux);
           		 
        	if(f->ini == NULL){
           		 f->ini = ptr;
        	} else{
           		 f->fim->prox = ptr; 
        	}
   			 f->fim = ptr;
    		printf("\nLivro %s", ptr->nomeLivro);
    		printf(" inserido na fila.\n");
    	}
    	system("pause");
    	system("cls");
	}

//FUNÇÃO PARA DESENFILEIRAR
void desenfileira(FILA *f){
    NO *ptr = f->ini;
    
    if(ptr != NULL){
    	printf("Livro %s", ptr->nomeLivro);
    	printf(" DELETADO.\n");// INFORMA QUE O LIVRO FOI DELETADO
    	aux = aux - ptr->preco;// SOMA OS PREÇOS
        f->ini = ptr->prox;
        ptr->prox = NULL;// LISTA QUE SEGUE
        free(ptr);
		printf("\n Diminuindo:R$ %.f",ptr->preco); //VALOR A SER DIMINUIDO DA SOMA DOS PREÇOS
        printf("\n Soma: R$ %.f\n",aux); // VALOR DA SOMA DOS PREÇOS
        	system("pause");
   			system("cls");
        if(f->ini == NULL){
           f->fim = NULL;
        
        }
    } else{//IMPRIME SE A FILA ESTIVER VAZIA
        printf("\nFila Vazia.\n");
        system("pause");
        system("cls");
    }
    
}
	
//IMPRIME A LISTA ANTES DO MENU			
void imprimeFilaP(FILA *f){
    NO *ptr = f->ini;
    printf("     ----- LIVROS -----\n");
    if(ptr != NULL){
        while(ptr != NULL){
        	printf("\nCódigo: %d", ptr->cod);
            printf(" Livro: %s", ptr->nomeLivro);
            ptr = ptr->prox;
            
        }
		printf("\nA soma de todos os livros é: R$%.2f\n",aux);
    }else{
        printf("\nFila Vazia.\n");
        
    }
   	
}


//IMPRIME LISTA 
void imprimeFila(FILA *f){
	
    NO *ptr = f->ini;
    printf("     ----- LISTA DE LIVROS -----");
    if(ptr != NULL){
        while(ptr != NULL){
            printf("\n");
            //printf("\nCódigo de referência do livro: %d", ptr->codigoref);
            printf("\nCódigo do livro: %d", ptr->cod);
            printf("\nNome do livro: %s", ptr->nomeLivro);
            printf("\nNome do autor: %s", ptr->nomeAutor);
            printf("\nPreço do livro: R$ %.2f", ptr->preco);
            printf("\n\n");
            ptr = ptr->prox;
            printf("     ----- ---- ----- -----\n");
            
        }

    }else{
        printf("\nFila Vazia.\n");
        
    }
   		system("pause");
        system("cls");
}


//LIMPA LISTA
void limpaFila(FILA *f){
    NO *ptr = f->ini;
    NO *aux;	 
    if(ptr != NULL){
        while(ptr != NULL){
            aux = ptr->prox;
            free(ptr);
            ptr = aux;
        }
        f->ini = NULL;
        f->fim = NULL;
        printf("Lista envaziada.\n");		
    } else {
        printf("\nFila Vazia!\n");    
    }	
	    system("pause");
        system("cls"); 
}

