#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct NO{
	char nomeLivro[20];
    char nomeAutor[30];
    int codigoref;
    int cod;
    float preco;
    struct NO *prox;
 }NO;

typedef struct FILA{
    NO *ini;
    NO *fim;
    int tam;  
}FILA;

struct NO;
void menu();
void inicializaFila(FILA *f);
void enfileira(char *nomeLivro, char *nomeAutor, int codigoref, int cod, float preco, FILA *f);
void desenfileira(FILA *f);
void imprimeFilaP(FILA *f);
void imprimeFila(FILA *f);
void limpaFila(FILA *f);

void inicializaFila(FILA *f){
    
    f->ini = 0;
    f->fim = 0;
	f->tam =5;	
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");

    int sel=0; int codigoref=0; int cod =0;
    char nomeLivro[20];
    char nomeAutor[30];
    float preco;
    FILA *f1 = (FILA*) malloc(sizeof(FILA));
	f1->tam=5;
	f1->ini= NULL;
	f1->fim= NULL;
    if(f1 == NULL){
        printf("\nErro de alocacao!");
        exit(-1);
    } else{        
        inicializaFila(f1);
        
        while (sel != 5){
       		imprimeFilaP(f1);
			
            menu();
            printf("\nOpcao: ");
            scanf("%d", &sel);
            switch (sel){
            case 1: 
                float aux;
            	if(codigoref < f1->tam){
            		 codigoref ++;
            		 //printf("\nReferência: %d",codigoref);
            		 //printf("\nCódigo do livro: ");
            		 //scanf("%d",&cod);
            		 cod++;
            		 printf("\nCódigo do livro: %d",cod);
               		 printf("\nNome do livro: ");
               		 scanf("%s",nomeLivro);
               		 printf("\nNome do autor: ");
               		 scanf("%s",nomeAutor);
               		 printf("\nPreço do livro: ");
               		 scanf("%f",&preco);
               		 enfileira(nomeLivro, nomeAutor, codigoref, cod, preco, f1);
               		 int i;
						for(i=0;i<f1->tam;i++){
								aux = preco+i;
						}
               		 break;
				}else{
					printf("\nFila Cheia. 002\n");
					system("pause");
					system("cls");
					break;
				}
                break;

            case 2: 
                desenfileira(f1);
                //codigoref--;
                codigoref = codigoref-1;
                break;

            case 3: 
                imprimeFila(f1);
                break;
                
            case 4:
                limpaFila(f1);
                codigoref = 0;
                break;

            case 6: 
                printf("\nPrograma finalizado ;) \n");
                system("pause");
                exit(0);
                break;

			case 5:
				printf("\nA soma de todos os livros na fila é: R$ %.2f",aux);
				break;
				
            default: 
                printf("\nOpção Inválida!");
                break;
            }
        }
    }


		

   	 return 0;
}	



void menu(){
	printf("\n");
	printf("\n             M.A.P.A. ");
	printf("\nAluno: Misael Andrejezieski");
	printf("\nR.A.: 2018609-5");
    printf("\n");
    printf("\n---- ---- ---- MENU ---- ---- ----");
    printf("\n\t1. Insere livro");
    printf("\n\t2. Deleta livro");
    printf("\n\t3. Imprime lista de livros");
    printf("\n\t4. Esvaziar a Fila");
    printf("\n\t5. Soma dos livros");
    printf("\n\t6. Sair");
    printf("\n");
}



void enfileira(char *nomeLivro, char *nomeAutor, int codigoref,int cod, float preco,  FILA *f){
    NO *ptr = (NO*) malloc (sizeof(NO));
    ;
	if(ptr == NULL){
        printf("\nErro de Alocação!\n");
    } else{
    	strcpy(ptr->nomeLivro, nomeLivro);
        strcpy(ptr->nomeAutor, nomeAutor);
        ptr->codigoref = codigoref;
        ptr->cod = cod;
        ptr->preco = preco;
        ptr->prox = NULL;
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

void desenfileira(FILA *f){
    NO *ptr = f->ini;
    
    if(ptr != NULL){
    	printf("Livro %s", ptr->nomeLivro);
    	printf(" DELETADO.\n");
        f->ini = ptr->prox;
        ptr->prox = NULL;
        free(ptr);
        
        	system("pause");
   			system("cls");
        if(f->ini == NULL){
           f->fim = NULL;
        
        }
    } else{
        printf("\nFila Vazia.\n");
        system("pause");
        system("cls");
    }
    
}
				
void imprimeFilaP(FILA *f){
    NO *ptr = f->ini;
    printf("     ----- LIVROS -----\n");
    if(ptr != NULL){
        while(ptr != NULL){
        	printf("\nCódigo: %d", ptr->cod);
            printf(" Livro: %s", ptr->nomeLivro);
            ptr = ptr->prox;
             
        }

    }else{
        printf("\nFila Vazia.\n");
        
    }
   	
}



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


